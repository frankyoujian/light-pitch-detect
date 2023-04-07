#include <signal.h>
#include "portaudio.h"
#include <algorithm>
#include "api/pitch_api.h"

#define BUFFER_SIZE 800*3
int INTERVAL = 10;
int SAMPLE_RATE = 48000;
int exiting = 0;

void sig_routine(int sig) {
  if (sig == SIGINT) {
    exiting = 1;
  }
}

float buffer[BUFFER_SIZE] = {0.0f};
int cnt = 0;
static int recordCallback(const void* input, void* output,
                          unsigned long framesCount,
                          const PaStreamCallbackTimeInfo* timeInfo,
                          PaStreamCallbackFlags statusFlags, void* userData) {
  const auto* pcm_data = static_cast<const float*>(input);

  for (int i=0; i<480; i++)
    buffer[i + cnt*480] = pcm_data[i];   
  cnt++;

  if (cnt == 5)
  {
    cnt = 0;
    float pitch = pitch_get(buffer, BUFFER_SIZE, 48000);

    memset((unsigned char*)buffer, BUFFER_SIZE*sizeof(float), 0);

    if (pitch > 0.0f)
      fprintf(stderr, "pitch:[%.3f]\n", pitch);
  }

  if (exiting) {
    fprintf(stderr, "exit");
    return paComplete;
  } else {
    return paContinue;
  }
}

int main(int argc, char* argv[]) {
  Pa_Initialize();
  PaStreamParameters params;
  params.device = Pa_GetDefaultInputDevice();
  if (params.device == paNoDevice) {
    fprintf(stderr, "No input device\n");
  }
  params.channelCount = 1;
  params.sampleFormat = paFloat32; //paInt16;
  params.suggestedLatency =
      Pa_GetDeviceInfo(params.device)->defaultLowInputLatency;
  params.hostApiSpecificStreamInfo = NULL;

  PaStream* stream;
  int frames_per_buffer = SAMPLE_RATE / 1000 * INTERVAL;
  Pa_OpenStream(&stream, &params, NULL, SAMPLE_RATE, frames_per_buffer,
                paClipOff, recordCallback, NULL);
  Pa_StartStream(stream);

  while (Pa_IsStreamActive(stream)) {
    Pa_Sleep(INTERVAL*5);
  }
  Pa_CloseStream(stream);
  Pa_Terminate();
  return 0;
}

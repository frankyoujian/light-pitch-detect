#include "api/pitch_api.h"
#include "src/pitch_detection.h"

float pitch_get(const float *audioBuffer, int buffer_size, int sample_rate)
{
  std::vector<float> chunk(buffer_size);
  for(int i=0; i<buffer_size; i++)
  {
    chunk[i] = audioBuffer[i];
  }
  
  auto pitch_mpm = pitch::mpm<float>(chunk, sample_rate);

  return pitch_mpm;
}

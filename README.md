# light-pitch-detect

This light-pitch-detect uses MPM method, which is extracted from [sevagh/pitch-detection](https://github.com/sevagh/pitch-detection).
It is light, no heavy dependency and easy-to-use.

The only dependency is [anthonix/ffts](https://github.com/anthonix/ffts). The windows binary of ffts has been uploaded to this repo,
so no need to compile ffts. For other platforms, it needs to compile locally.

The api is ready, all you need is to include api/pitch_api.h, then invoke like this:
```
float pitch = pitch_get(audioBuffer, buffer_size, sample_rate);
```

## Build
```
mkdir build
cd build

# For Visual Studio 2017 
cmake -T v141,host=x64 -A x64 -D CMAKE_BUILD_TYPE=Release ..

cmake --build . --config Release
```

## example
Refer to bin/pitch_main.cc for demo code
```
./output/Release/pitch_main.exe
```

## results
```
pitch:[325.412]
pitch:[135.977]
pitch:[277.455]
pitch:[246.793]
pitch:[151.899]

```

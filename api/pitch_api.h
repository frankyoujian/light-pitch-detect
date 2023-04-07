// Copyright (c) 2023 frankyj@foxmail.com
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef _PITCH_H_
#define _PITCH_H_

#ifndef PITCH_API
# ifndef __GNUC__
#  define __DLL_IMPORT__ __declspec(dllimport)
#  define __DLL_EXPORT__ __declspec(dllexport)
# else
#  define __DLL_IMPORT__ __attribute__((dllimport)) extern
#  define __DLL_EXPORT__ __attribute__((dllexport)) extern
# endif

# if defined(__WIN32__) || defined(_WIN32) || defined(WIN32)
#  ifdef PITCH_EXPORTS
#   define PITCH_API      __DLL_EXPORT__
#  else
#   define PITCH_API      __DLL_IMPORT__
#  endif
# else
#  define PITCH_API
# endif
#endif

// #  define PITCH_API

#ifdef __cplusplus
extern "C" {
#endif

PITCH_API float pitch_get(const float *audioBuffer, int buffer_size, int sample_rate);

#ifdef __cplusplus
}
#endif

#endif  // _PITCH_H_

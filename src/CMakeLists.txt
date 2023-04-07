add_library(pitch_detect STATIC
  autocorrelation.cpp
  parabolic_interpolation.cpp
  mpm.cpp
)

target_include_directories(pitch_detect
    PUBLIC
        ffts
)

target_link_libraries(pitch_detect PUBLIC
    optimized ${CMAKE_CURRENT_SOURCE_DIR}/ffts/ffts_static.lib
    debug ${CMAKE_CURRENT_SOURCE_DIR}/ffts/ffts_static.lib
)
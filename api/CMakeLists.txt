add_definitions(-DPITCH_EXPORTS)

add_library(pitch_api SHARED pitch_api.cc)
target_link_libraries(pitch_api PUBLIC pitch_detect)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
link_directories(${CMAKE_BINARY_DIR}/api/${CMAKE_BUILD_TYPE})



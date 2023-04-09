include(portaudio)
add_executable(pitch_main pitch_main.cc)
target_link_libraries(pitch_main PUBLIC pitch_api portaudio_static)

set_target_properties( pitch_main PROPERTIES RUNTIME_OUTPUT_DIRECTORY 
   ${CMAKE_BINARY_DIR}/output )

add_custom_target(copy-pitch-api
  COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_BINARY_DIR}/api/${CMAKE_BUILD_TYPE} ${CMAKE_BINARY_DIR}/output/${CMAKE_BUILD_TYPE}
)

add_dependencies(pitch_main copy-pitch-api)

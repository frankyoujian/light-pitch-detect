add_definitions(-DPITCH_EXPORTS)

add_library(pitch_api SHARED pitch_api.cc)
target_link_libraries(pitch_api PUBLIC pitch_detect)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
link_directories(${CMAKE_BINARY_DIR}/api/${CMAKE_BUILD_TYPE})

if(MSVC)
    file(GLOB API_DLLS "${CMAKE_BINARY_DIR}/api/${CMAKE_BUILD_TYPE}/*.dll")
    file(COPY ${API_DLLS} DESTINATION ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE})
endif()

# set_target_properties( pitch_api PROPERTIES LIBRARY_OUTPUT_DIRECTORY
#    ${CMAKE_BINARY_DIR}/output/${CMAKE_BUILD_TYPE} )



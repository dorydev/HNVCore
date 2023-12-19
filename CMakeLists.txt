cmake_minimum_required(VERSION 3.20)
project(HNVCore VERSION 0.1)
set (CMAKE_CXX_STANDARD 20)

file(GLOB SRC_FILES CONFIGURE_DEPENDS "src/*.h" "src/*.cpp" "lib/glad/src/glad.c") #ta mere la pute glad

add_executable(HNVCore ${SRC_FILES})

set_target_properties(HNVCore PROPERTIES 
RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/Debug"
RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/Release"
)

target_include_directories(HNVCore 
    PUBLIC "${CMAKE_SOURCE_DIR}/lib/glm" 
    PUBLIC "${CMAKE_SOURCE_DIR}/lib/glfw/include"   
    PUBLIC "${CMAKE_SOURCE_DIR}/lib/glad/include"
)

target_link_libraries(HNVCore "${CMAKE_SOURCE_DIR}/lib/glfw/libglfw3dll.a")
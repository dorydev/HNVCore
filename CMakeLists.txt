cmake_minimum_required(VERSION 3.20)
project(HNVCore VERSION 0.1)
set (CMAKE_CXX_STANDARD 20)

set(IMGUI_SRC
    ${CMAKE_SOURCE_DIR}/lib/imgui/imgui_impl_opengl3.h
    ${CMAKE_SOURCE_DIR}/lib/imgui/imgui_impl_opengl3.cpp
    ${CMAKE_SOURCE_DIR}/lib/imgui/imgui_impl_opengl3_loader.h
    ${CMAKE_SOURCE_DIR}/lib/imgui/imgui_impl_glfw.h
    ${CMAKE_SOURCE_DIR}/lib/imgui/imgui_impl_glfw.cpp
    ${CMAKE_SOURCE_DIR}/lib/imgui/imgui.h
    ${CMAKE_SOURCE_DIR}/lib/imgui/imgui.cpp
    ${CMAKE_SOURCE_DIR}/lib/imgui/imgui_draw.cpp
    ${CMAKE_SOURCE_DIR}/lib/imgui/imgui_tables.cpp
    ${CMAKE_SOURCE_DIR}/lib/imgui/imgui_widgets.cpp
    ${CMAKE_SOURCE_DIR}/lib/imgui/imgui_demo.cpp
)

file(GLOB SRC_FILES CONFIGURE_DEPENDS "src/*.h" "src/*.cpp" "lib/glad/src/glad.c")

add_executable(HNVCore ${SRC_FILES} ${IMGUI_SRC})

set_target_properties(HNVCore PROPERTIES 
RUNTIME_OUTPUT_DIRECTORY_DEBUG "${CMAKE_SOURCE_DIR}/bin/Debug"
RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_SOURCE_DIR}/bin/Release"
)

target_include_directories(HNVCore 
    PUBLIC "${CMAKE_SOURCE_DIR}/lib/glm" 
    PUBLIC "${CMAKE_SOURCE_DIR}/lib/glfw/include"   
    PUBLIC "${CMAKE_SOURCE_DIR}/lib/glad/include"
    PUBLIC "${CMAKE_SOURCE_DIR}/lib/glut/include"
    PUBLIC "${CMAKE_SOURCE_DIR/lib/imgui}"
)

target_link_libraries(HNVCore "${CMAKE_SOURCE_DIR}/lib/glfw/libglfw3dll.a")
target_link_libraries(HNVCore "${CMAKE_SOURCE_DIR}/lib/glut/lib/libglut32.a")


add_custom_command(TARGET HNVCore POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/src/shaders/ $<TARGET_FILE_DIR:${PROJECT_NAME}>/shaders/)
add_custom_command(TARGET HNVCore POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${CMAKE_SOURCE_DIR}/lib/glfw/glfw3.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>)
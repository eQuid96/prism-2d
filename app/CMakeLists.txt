# create an executable called learn-opengl
add_executable(learn-opengl main.cpp glad.c)

target_compile_features(learn-opengl PRIVATE cxx_std_11)
target_include_directories(learn-opengl PRIVATE ../include)

# link lib glfw opengl and glfw dependencies
target_link_libraries(learn-opengl lib glfw ${OPENGL_gl_LIBRARY} ${GLFW_LIBRARIES})
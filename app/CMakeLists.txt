cmake_minimum_required(VERSION 3.10)
project(app)

# create an executable called app
add_executable(app main.cpp)

set_property(TARGET app PROPERTY CXX_STANDARD 11)
set_property(TARGET app PROPERTY CXX_STANDARD_REQUIRED true)

# link lib prism
target_link_libraries(app prism ${OPENGL_gl_LIBRARY} ${GLFW_LIBRARIES})
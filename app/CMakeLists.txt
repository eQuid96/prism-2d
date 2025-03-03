cmake_minimum_required(VERSION 3.10)
project(app)

# create an executable called app
add_executable(app main.cpp)

target_compile_features(app PRIVATE cxx_std_11)

# link lib prism
target_link_libraries(app prism ${OPENGL_gl_LIBRARY} ${GLFW_LIBRARIES})
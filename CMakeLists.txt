cmake_minimum_required(VERSION 3.14...3.29)

project(LearnOpenGL VERSION 1.0
                    LANGUAGES C CXX)

find_package(OpenGL REQUIRED)

# FetchContent added in CMake 3.11, downloads during the configure step
# FetchContent_MakeAvailable was added in CMake 3.14; simpler usage
include(FetchContent)

# decleare a depedency to download
FetchContent_Declare(
        glfw3
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.4)


fetchcontent_makeavailable(glfw3)

# add a static library called lib
add_library(lib STATIC src/vector2.cpp include/lib/vector2.h)

# add include dir to lib target
target_include_directories(lib PUBLIC include)
# set cpp11 standard only for lib
target_compile_features(lib PUBLIC cxx_std_11)

# add a new sub-dir where cmake should find other CMakeLists.txt file
add_subdirectory(app)
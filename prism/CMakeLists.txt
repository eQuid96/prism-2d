cmake_minimum_required(VERSION 3.10)
project(prism)

file(GLOB_RECURSE PRISM_SOURCES_FILES 
    "src/*.cpp"
    "src/*.c"
)


add_library(prism STATIC ${PRISM_SOURCES_FILES})

find_package(OpenGL REQUIRED)
include(FetchContent)

# decleare a depedency to download
FetchContent_Declare(
        glfw3
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.4)


fetchcontent_makeavailable(glfw3)

target_include_directories(prism PUBLIC
    include
    include/vendor
)

target_link_libraries(prism PUBLIC glfw OpenGL::GL)

set_property(TARGET prism PROPERTY CXX_STANDARD 11)
set_property(TARGET prism PROPERTY CXX_STANDARD_REQUIRED true)


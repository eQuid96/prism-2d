cmake_minimum_required(VERSION 3.14...3.29)

project(prism-2d VERSION 1.0
                LANGUAGES C CXX)

# Prism static library for 2D game dev
add_subdirectory(prism)

# App is an example executable that use prism linked statically
add_subdirectory(app)
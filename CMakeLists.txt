
cmake_minimum_required(VERSION 3.10)


project(ttl VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Adding da executable
add_executable(ttl src/main.cc)

target_include_directories(ttl PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_BINARY_DIR}/src"
                           )




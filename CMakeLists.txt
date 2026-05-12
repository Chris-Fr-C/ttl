
cmake_minimum_required(VERSION 3.10)


project(ttl VERSION 1.0)
include(FetchContent)
# Abseil dependencies
FetchContent_Declare(
  absl
  GIT_REPOSITORY https://github.com/abseil/abseil-cpp.git
  GIT_TAG        20260107.1 
)
set(ABSL_PROPAGATE_CXX_STD ON)
FetchContent_MakeAvailable(absl)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


# Adding da executable
add_executable(
  ttl 
  src/main.cpp
  src/parser.cpp
  src/register.cpp
)

# For the linter.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

target_include_directories(ttl PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           "${PROJECT_BINARY_DIR}/src"
                           "${PROJECT_BINARY_DIR}/thirdparty/absl"
                           )

target_link_libraries(ttl PRIVATE
# The high-level targets
    absl::status
    absl::statusor
    absl::strings
    absl::flags
    absl::flags_parse
    absl::log
    absl::log_initialize 
    absl::time
    
)



cmake_minimum_required(VERSION 3.16)

project(fizz_buzz_cs)



# ----------------------
# Debugging
# ----------------------
set(DEBUG_MODE FALSE)



# ----------------------
# Build type
# ----------------------
if (NOT CMAKE_BUILD_TYPE AND DEBUG_MODE)
	set(CMAKE_BUILD_TYPE Debug)
elseif(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif ()



# ----------------------
# CXX settings
# ----------------------
set(CPP_COMPILER_STANDARD "-std=c++17")
set(CMAKE_CXX_STANDARD_REQUIRED ON)



# ----------------------
# Compiler flags
# ----------------------
# set(SANITIZER "-fsanitize=undefined,address")
# Rejected: -Wmissing-prototypes 
# set(EXTRA_COMPILER_FLAGS "-Wall -Wextra -Werror -Wpedantic -Wconversion -Wshadow -Wold-style-cast -Wpointer-arith -Wcast-qual -Wno-unused-function")

# Generate 'compile_commands.json' file required for 'clangd' and familiar tools.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(${DEBUG_MODE})
	set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -D_GLIBCXX_DEBUG -g -O0")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CPP_COMPILER_STANDARD} ${EXTRA_COMPILER_FLAGS} ${COMPILATION_DATABASE} ${SANITIZER}")
	message(WARNING "Project is now in debug mode!")
else()
	set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CPP_COMPILER_STANDARD} ${EXTRA_COMPILER_FLAGS} ${COMPILATION_DATABASE} ${SANITIZER}")
endif()



# ----------------------
# Conan
# ----------------------
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()



# ----------------------
# External Libraries
# ----------------------
# find_package(ASIO REQUIRED)
 


# Set output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bin)



# ----------------------
# Tests
# ----------------------
# Must be defined in top-most CMakeLists.txt file.
# enable_testing()



# ----------------------
# Subdirectories
# ----------------------
# add_subdirectory(tests)
add_subdirectory(src/server)
add_subdirectory(src/client)



# ----------------------
# Create executable target
# ----------------------
add_executable(${PROJECT_NAME}  src/main.cpp)



# ----------------------
# Link libraries target with executable target
# ----------------------
target_link_libraries(${PROJECT_NAME}  client_lib server_lib pthread)
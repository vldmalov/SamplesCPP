cmake_minimum_required(VERSION 3.24)
project(CustomString)
set(target_name "CustomString")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if ( MSVC )
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} /W4 /WX")
else()
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")
endif()

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")
set (CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fsanitize=address")

file(GLOB_RECURSE source_files "./customString/source/*.cpp")
file(GLOB_RECURSE include_files "./customString/include/*.h")
set(all_sources ${source_files} ${include_files})
add_executable(${target_name} WIN32 MACOSX_BUNDLE ${all_sources})

target_include_directories(${target_name} PRIVATE "./customString/include")

add_subdirectory("customString/test")

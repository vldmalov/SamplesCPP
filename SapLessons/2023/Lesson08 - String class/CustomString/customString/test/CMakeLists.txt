set(target_name "unitTests")
message("Build project: ${target_name}")

include("../../externals/gtest.cmake")

enable_testing()

file(GLOB_RECURSE source_files "source/*.cpp" "../source/CustomString.cpp")
file(GLOB_RECURSE include_files "include/*.h" "../include/CustomString.h")

set(all_sources ${source_files} ${include_files})
add_executable(${target_name} WIN32 MACOSX_BUNDLE ${all_sources})

source_group("${target_name}\\src" FILES ${source_files})
source_group("${target_name}\\inc" FILES ${include_files})

target_link_libraries(${target_name} GTest::gtest_main)
target_compile_features(${target_name} INTERFACE cxx_std_20)
target_include_directories(${target_name} PRIVATE "./include" "../include")

include(GoogleTest)
gtest_discover_tests(${target_name})

message("External Dependency: GTest")

set(GTEST_REPO_PATH "https://github.com/google/googletest.git")
set(GTEST_VERSION_TAG "v1.14.0")

include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY ${GTEST_REPO_PATH}
    GIT_TAG ${GTEST_VERSION_TAG}
)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

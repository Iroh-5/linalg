project (tests)
cmake_minimum_required (VERSION 3.14)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED ON)

if (FETCH_GTEST)
    include (FetchContent)

    FetchContent_Declare (
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )

    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set (gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable (googletest)
endif (FETCH_GTEST)

enable_testing()

add_executable (${PROJECT_NAME}
    vec_test.cpp
    vec_constexpr_test.cpp
)

target_include_directories (${PROJECT_NAME}
    PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/../include"
)

target_link_libraries (
    ${PROJECT_NAME}
    PRIVATE
        GTest::gtest_main
)

include (GoogleTest)
gtest_discover_tests (${PROJECT_NAME})

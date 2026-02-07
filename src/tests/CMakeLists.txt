set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
  add_compile_options(
    -Wall 
    -Wextra 
    -Wpedantic
    -Werror
    -g
    -D_POSIX_C_SOURCE=201706L
    -O0 
    )
endif()

option(BUILD_TESTS "Build tests" ON)
option(BUILD_COVERAGE "Enable code coverage" ON)

if(BUILD_TESTS OR BUILD_COVERAGE)
    find_program(VALGRIND_EXECUTABLE valgrind)
    find_program(LCOV_EXECUTABLE lcov)
    find_program(GENHTML_EXECUTABLE genhtml)
    find_package(glm REQUIRED)

    set(INCLUDE_DIRS
        ${CMAKE_CURRENT_SOURCE_DIR}/..
        ${CMAKE_CURRENT_SOURCE_DIR}/../lib
    )
    set(SRC
        ../lib/vector3d.cpp
        ../lib/segment3d.cpp
        ../lib/intersection.cpp
    )
    set(TEST_SRC
        ${CMAKE_CURRENT_SOURCE_DIR}/tests.cpp
    )

    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.12.1
    )
    FetchContent_MakeAvailable(googletest)

endif()

if(BUILD_TESTS)
    # Core tests
    add_executable(tests
        ${TEST_SRC}       # <- test code files
        ${SRC}
    )

    target_include_directories(tests PRIVATE ${INCLUDE_DIRS})
    target_link_libraries(tests PRIVATE gtest_main pthread)
    set_property(TARGET tests PROPERTY CXX_STANDARD 20)
    add_test(NAME tests COMMAND tests)

    add_custom_target(run_tests
        COMMAND tests
        DEPENDS tests
        COMMENT "Running tests executable"
    )

    if(VALGRIND_EXECUTABLE)
        add_custom_target(valgrind_tests
            COMMAND valgrind 
                --tool=memcheck  
                --leak-check=full 
                --show-leak-kinds=all 
                --track-origins=yes 
                --verbose 
                --log-file=valgrind_tests.txt
                $<TARGET_FILE:tests>
            DEPENDS tests
            COMMENT "Running tests under Valgrind (see valgrind_tests.txt)."
        )
    else()
        message(WARNING "Valgrind not found. valgrind_tests target will not be available.")
    endif()
endif()

if(BUILD_COVERAGE AND LCOV_EXECUTABLE AND GENHTML_EXECUTABLE)

    add_executable(test_cov
        ${TEST_SRC}       # <- test code files
        ${SRC}
    )
    target_include_directories(test_cov PRIVATE ${INCLUDE_DIRS})
    target_link_libraries(test_cov PRIVATE gtest_main pthread)
    set_property(TARGET tests PROPERTY CXX_STANDARD 20)
    set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY CMAKE_COVERAGE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
    target_compile_options(test_cov  PRIVATE
        -fprofile-arcs 
        -ftest-coverage
    )
    target_link_options(test_cov PRIVATE --coverage)

    add_custom_target(coverage
        COMMAND ${CMAKE_COMMAND} -E remove_directory coverage
        COMMAND ${CMAKE_COMMAND} -E make_directory coverage

        COMMAND ${CMAKE_CURRENT_BINARY_DIR}/test_cov

        COMMAND ${LCOV_EXECUTABLE} --capture --directory ${CMAKE_CURRENT_BINARY_DIR}  --output-file coverage/coverage_1.info --rc geninfo_unexecuted_blocks=1 --ignore-errors mismatch,mismatch --path ${CMAKE_CURRENT_BINARY_DIR}/..
        COMMAND ${LCOV_EXECUTABLE} --remove coverage/coverage_1.info '/usr/*' 'gtest/*' 'tests/*' --output-file coverage/coverage.info
        COMMAND ${CMAKE_COMMAND} -E remove -f coverage/coverage_1.info
        COMMAND ${GENHTML_EXECUTABLE} --output-directory=coverage coverage/coverage.info

        DEPENDS test_cov
        COMMENT "Running tests + Generating HTML coverage report in ./coverage"
    )

else()
    message(WARNING "Coverage tools not found or BUILD_COVERAGE is OFF. coverage target will not be available.")
endif()
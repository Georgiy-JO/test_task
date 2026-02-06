cmake_minimum_required(VERSION 3.21)

project(test_task
  VERSION 1.0.0
  LANGUAGES CXX
  DESCRIPTION "Intersection test task"
)

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
    -D_POSIX_C_SOURCE=201706L)
endif()

set(INCLUDE_DIRS
  ${CMAKE_CURRENT_SOURCE_DIR}
  ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

set(MAIN_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
)

set(LIB_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/lib/vector3d.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/lib/segment3d.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/lib/intersection.cpp
)


add_library(intersection
    ${LIB_SOURCES}
)

target_include_directories(intersection PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

add_executable(test_task ${MAIN_SOURCES})

target_link_libraries(test_task PRIVATE intersection)
target_sources(test_task PRIVATE ${MAIN_SOURCES})
target_include_directories(test_task PRIVATE ${INCLUDE_DIRS})


add_custom_target(run_test_task
    COMMAND test_task
    DEPENDS test_task
    COMMENT "Running test_task executable"
)

enable_testing()
add_subdirectory(tests)

find_program(CLANG_FORMAT_EXE
    NAMES clang-format clang-format-20 clang-format-14 clang-format-13
    DOC "Path to clang-format executable"
)

if(CLANG_FORMAT_EXE)
    find_file(CLANG_FILE 
        ${CMAKE_CURRENT_SOURCE_DIR}/../.clang-format
        ${CMAKE_CURRENT_SOURCE_DIR}/.clang-format
        )

    # set(CHECKABLE_FILES
    #     ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    #     ${CMAKE_CURRENT_SOURCE_DIR}/*.h
    #     ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
    #     ${CMAKE_CURRENT_SOURCE_DIR}/*/*.cpp
    #     ${CMAKE_CURRENT_SOURCE_DIR}/*/*.h
    #     ${CMAKE_CURRENT_SOURCE_DIR}/*/*.hpp
    # )
    file(GLOB_RECURSE CHECKABLE_FILES
        LIST_DIRECTORIES false
        ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
    )


    add_custom_target(style_check
        COMMAND ${CLANG_FORMAT_EXE}
            --style=file:${CLANG_FILE}
            -n
            ${CHECKABLE_FILES}
        COMMENT "Checking Google code style..."
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        VERBATIM
    )
    add_custom_target(style_make
        COMMAND ${CLANG_FORMAT_EXE}
            --style=file:${CLANG_FILE}
            -i
            ${CHECKABLE_FILES}
        COMMENT "Fixing files' style according to Google style..."
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        VERBATIM
    )
else()        
    message(WARNING "clang-format not found! Code style targets unavailable.")
endif()

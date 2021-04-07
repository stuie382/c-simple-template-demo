cmake_minimum_required(VERSION 3.17)
project(template_demo VERSION 1.0
        DESCRIPTION "Template starter for C projects"
        LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

enable_testing()

if (${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME})
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)
    include(CTest)
    find_package(Doxygen)
    if (Doxygen_FOUND)
        add_subdirectory(docs)
    else ()
        message(STATUS "Doxygen not found, not building docs")
    endif ()

else ()
    message(STATUS "Didn't equal project names")
endif ()

add_subdirectory(src)
add_subdirectory(app)
#if ((${CMAKE_PROJECT_NAME} STREQUAL ${PROJECT_NAME} OR template_demo_BUILD_TESTING) AND BUILD_TESTING)
add_subdirectory(tests)
#endif ()

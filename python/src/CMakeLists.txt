cmake_minimum_required(VERSION 3.8)

find_package(SWIG REQUIRED)
include(${SWIG_USE_FILE})

find_package(PythonLibs)
find_package(PythonInterp)

execute_process(
    COMMAND "${PYTHON_EXECUTABLE}" -c
            "from __future__ import print_function\ntry: import numpy; print(numpy.get_include(), end='')\nexcept:pass\n"
            OUTPUT_VARIABLE __numpy_path)
find_path(PYTHON_NUMPY_INCLUDE_DIR numpy/arrayobject.h
            HINTS "${__numpy_path}" "${PYTHON_INCLUDE_PATH}" NO_DEFAULT_PATH)

include_directories(${PYTHON_INCLUDE_PATH})                        
include_directories(${PYTHON_NUMPY_INCLUDE_DIR})

message(STATUS "PYTHON_INCLUDE_DIR=${PYTHON_INCLUDE_PATH}")
message(STATUS "PYTHON_NUMPY_INCLUDE_DIR=${PYTHON_NUMPY_INCLUDE_DIR}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/seb)

set(CMAKE_SWIG_FLAGS "-includeall")

set_source_files_properties(miniball.i PROPERTIES CPLUSPLUS ON)
set_source_files_properties(miniball.i PROPERTIES SWIG_FLAGS ${CMAKE_SWIG_FLAGS})
swig_add_library(miniball LANGUAGE python SOURCES miniball.i miniball.cpp)
swig_link_libraries(miniball ${EXTRA_LIBS} ${PYTHON_LIBRARIES})

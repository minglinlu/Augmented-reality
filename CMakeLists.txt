cmake_minimum_required(VERSION 2.8)

project( Augmented-reality )

set(CMAKE_BUILD_TYPE "Debug")

find_package( OpenCV REQUIRED )
find_package( OpenGL REQUIRED )
find_package( GLUT REQUIRED )

#MESSAGE(STATUS "OpenCV_LIB_DIR: ${OpenCV_LIB_DIR}")
#MESSAGE(STATUS "OpenCV_INCLUDE_DIRS: ${OpenCV_INCLUDE_DIRS}")

#find_package( libvot REQUIRED )

include_directories(${CMAKE_SOURCE_DIR}/src/color/)

add_subdirectory(src/color)

add_executable( tracker tracker.cpp )
target_link_libraries( tracker ${OpenCV_LIBS} color )

add_executable( main main.cpp )
target_link_libraries( main ${OpenCV_LIBS} ${OPENGL_gl_LIBRARY} ${GLUT_LIBRARY} color )

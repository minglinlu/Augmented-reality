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
include_directories(${CMAKE_SOURCE_DIR}/src/tracking/)
include_directories(${CMAKE_SOURCE_DIR}/src/arMarkerNFT/)
include_directories(/Users/lml/Desktop/ARToolKit5-bin-5.3.2r1-OSX/include)
include_directories(/Users/lml/Desktop/ARToolKit5-bin-5.3.2r1-OSX/include/macosx-universal)

link_directories(/Users/lml/Desktop/ARToolKit5-bin-5.3.2r1-OSX/lib)
link_directories(/Users/lml/Desktop/ARToolKit5-bin-5.3.2r1-OSX/lib/macosx-universal)

add_subdirectory(src/color)
add_subdirectory(src/tracking)
add_subdirectory(src/arMarkerNFT)

add_executable( tracker tracker.cpp )
target_link_libraries( tracker ${OpenCV_LIBS} color )

add_executable( main main.cpp )
target_link_libraries( main ${OpenCV_LIBS} ${OPENGL_gl_LIBRARY} ${GLUT_LIBRARY} color )

add_executable( nftSimple nftSimple.c )
target_link_libraries( nftSimple tracking arMarkerNFT -lKPM -lAR2 -lARUtil -lARgsub_lite -lARvideo -lAR -lARICP -lAR -ljpeg "-framework Accelerate -framework QTKit -framework CoreVideo -framework Carbon -framework GLUT -framework OpenGL -framework Cocoa -framework QuickTime")

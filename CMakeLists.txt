cmake_minimum_required(VERSION 2.8)
project( Augmented-reality )
find_package( OpenCV REQUIRED )
#find_package( libvot REQUIRED )
add_executable( main main.cpp )
target_link_libraries( main ${OpenCV_LIBS} )


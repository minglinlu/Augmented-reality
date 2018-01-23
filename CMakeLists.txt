cmake_minimum_required(VERSION 2.8)
project( Augmented-reality )
find_package( OpenCV REQUIRED )
<<<<<<< HEAD
#find_package( libvot REQUIRED )
=======
#find_package( libvotiii REQUIRED )
>>>>>>> dfe41142616ae2d5ad6601a59215e59109be023a
add_executable( main main.cpp )
target_link_libraries( main ${OpenCV_LIBS} )


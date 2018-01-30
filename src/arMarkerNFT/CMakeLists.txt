cmake_minimum_required(VERSION 2.8)

set(ARMARKERNFT_LIB_SRC ARMarkerNFT.c )

include_directories(/Users/lml/Desktop/ARToolKit5-bin-5.3.2r1-OSX/include)
add_library(arMarkerNFT STATIC ${ARMARKERNFT_LIB_SRC})
target_link_libraries(arMarkerNFT )
set_target_properties(arMarkerNFT PROPERTIES VERSION 1.0.0 SOVERSION 1)

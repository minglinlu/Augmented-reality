cmake_minimum_required(VERSION 2.8)

set(TRACKING_LIB_SRC trackingSub.c )

include_directories(/Users/lml/Desktop/ARToolKit5-bin-5.3.2r1-OSX/include)
add_library(tracking STATIC ${TRACKING_LIB_SRC})
target_link_libraries(tracking )
set_target_properties(tracking PROPERTIES VERSION 1.0.0 SOVERSION 1)

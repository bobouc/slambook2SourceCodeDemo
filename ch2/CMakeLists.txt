cmake_minimum_required( VERSION 2.8 )
project( HELLOSLAM )
add_library( hello_shared SHARED libHelloSLAM.cpp )
add_executable( useHello useHelloSLAM.cpp )
target_link_libraries( useHello hello_shared )


add_library(
	exe STATIC
	scara_lab.c scara_lab.h
)

add_subdirectory(network)
add_subdirectory(kinematics)

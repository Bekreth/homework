add_library(
	exe STATIC
	scara_lab.c scara_lab.h
	tokens.c tokens.h
)

add_subdirectory(network)
add_subdirectory(kinematics)
add_subdirectory(line)


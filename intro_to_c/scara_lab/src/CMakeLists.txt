add_library(
	exe STATIC
	scara_lab.c scara_lab.h
	${PROJECT_SOURCE_DIR}/src/network/network.h
	${PROJECT_SOURCE_DIR}/src/kinematics/kinematics.h
)

add_subdirectory(network)
add_subdirectory(kinematics)
add_subdirectory(line)
add_subdirectory(user_interface)
add_subdirectory(path_planner)

target_include_directories(
	exe PRIVATE
	${PROJECT_SOURCE_DIR}/src/network/
	${PROJECT_SOURCE_DIR}/src/kinematics/
)

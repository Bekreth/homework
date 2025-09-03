add_library(
	path_planner STATIC
	path_planner.h path_planner.c
	${PROJECT_SOURCE_DIR}/src/kinematics/kinematics.h
)

target_include_directories(
	path_planner PRIVATE
	${PROJECT_SOURCE_DIR}/src/kinematics/
)

add_library(
	line STATIC
	line.h line.c
	${PROJECT_SOURCE_DIR}/src/kinematics/kinematics.h
)

target_include_directories(
	line PRIVATE
	${PROJECT_SOURCE_DIR}/src/kinematics/
)

add_library(
	network STATIC
	network.h 
	commands.c commands.h
	tcp_connection.c tcp_connection.h
	${PROJECT_SOURCE_DIR}/src/kinematics/kinematics.h
)

target_include_directories(
	network PRIVATE
	${PROJECT_SOURCE_DIR}/src/kinematics/
)
message(PROJECT_SOURCE_DIR="${PROJECT_SOURCE_DIR}")

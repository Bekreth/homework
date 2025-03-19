
add_library(
	network STATIC
	kinematics.h 
	network.h 
	commands.c commands.h
	tcp_connection.c tcp_connection.h
)

target_include_directories(network PRIVATE "src/kinematics/")

add_library(
	user_interface STATIC
	user_interface.h
	tokens.c tokens.h 
	intent_parser.c intent_parser.h 
	${PROJECT_SOURCE_DIR}/src/network/network.h
	${PROJECT_SOURCE_DIR}/src/kinematics/kinematics.h
)

target_include_directories(
	user_interface PRIVATE
	${PROJECT_SOURCE_DIR}/src/network/
	${PROJECT_SOURCE_DIR}/src/kinematics/
)

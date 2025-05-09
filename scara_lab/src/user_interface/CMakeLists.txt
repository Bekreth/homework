add_library(
	user_interface STATIC
	user_interface.h
	tokens.c tokens.h 
	intent_parser.c intent_parser.h 
	intent_error.c intent_error.h 
	motion_intent.c motion_intent.h 
	state_intent.c state_intent.h 
	validate_number.c validate_number.h 
	${PROJECT_SOURCE_DIR}/src/network/network.h
	${PROJECT_SOURCE_DIR}/src/kinematics/kinematics.h
)

target_include_directories(
	user_interface PRIVATE
	${PROJECT_SOURCE_DIR}/src/network/
	${PROJECT_SOURCE_DIR}/src/kinematics/
)

target_link_libraries(user_interface kinematics network)

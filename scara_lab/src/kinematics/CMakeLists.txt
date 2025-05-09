add_library(
	kinematics STATIC
	kinematics.h
	limits.h
	coordinates.c coordinates.h
	handedness.c handedness.h
	forward_kinematics.c forward_kinematics.h
	inverse_kinematics.c inverse_kinematics.h
)

find_library(MATH_LIBRARY m)
if(MATH_LIBRARY)
	target_link_libraries(kinematics ${MATH_LIBRARY})
endif()


#include "handedness.h"

Handedness opposite_hand(Handedness hand) {
	if (hand == Right) {
		return Left;
	} else {
		return Right;
	}
}

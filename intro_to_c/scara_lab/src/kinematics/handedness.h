#ifndef HANDEDNESS_H
#define HANDEDNESS_H

typedef enum Handedness {
	Left,
	Right,
} Handedness;

Handedness opposite_hand(Handedness);

#endif

#ifndef DIE_H
#define DIE_H

typedef struct Die {
	unsigned int sides;
	unsigned int previous_roll;
} Die;

Die new_die(unsigned int);
unsigned int roll(Die*);
unsigned int total(Die**, int);

#endif 


#ifndef ENCODER_H
#define ENCODER_H

typedef struct PortConfiguration {
	unsigned char* port_in;
	unsigned char* port_out;
	unsigned char* port_direction;
	unsigned char* port_resistor;
	int* port_interupt;
	int* port_edge_selector;
	char pin;
} PortConfiguration;

void init_encoder();
int get_encoder_count();
void update_encoder_state();


#endif

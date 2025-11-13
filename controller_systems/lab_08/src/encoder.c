#include "msp430f5529.h"

#include "encoder.h"

typedef struct PortConfiguration {
	int* port_in;
	int* port_out;
	int* port_direction;
	int* port_resistor;
	int* port_interupt;
	int* port_edge_selector;
	char pin;
} PortConfiguration;


typedef enum LineValue {
	Up,
	Down
} LineValue;

typedef struct Encoder {	
	PortConfiguration a_pin;
	LineValue previous_a;
	PortConfiguration b_pin;
	LineValue previous_b;
	int count;
} Encoder;

static Encoder p6_encoder;

void init_encoder() {
	Encoder p6_encoder = {
		.a_pin = {
			.port_in = P6IN,
			.port_out = P6OUT,
			.port_direction = P6DIR,
			.port_resistor = P6REN,
			//.port_interupt = P6IE,
			//.port_edge_selector = P6IES,
			.pin = BIT0,
		},
		.previous_a = Down,
		.b_pin = {
			.port_in = P6IN,
			.port_out = P6OUT,
			.port_direction = P6DIR,
			.port_resistor = P6REN,
			//.port_interupt = P6IE,
			//.port_edge_selector = P6IES,
			.pin = BIT1,
		},
		.previous_b = Down,
		.count = 0,
	};


	*p6_encoder.a_pin.port_direction &= ~(p6_encoder.a_pin.pin);
	*p6_encoder.b_pin.port_direction &= ~(p6_encoder.b_pin.pin);

	*p6_encoder.a_pin.port_interupt |= p6_encoder.a_pin.pin;
	*p6_encoder.b_pin.port_interupt |= p6_encoder.b_pin.pin;

	*p6_encoder.a_pin.port_edge_selector |= p6_encoder.a_pin.pin;
	*p6_encoder.b_pin.port_edge_selector |= p6_encoder.b_pin.pin;

	__eint();

}

int get_encoder_count() {
	return p6_encoder.count;
}

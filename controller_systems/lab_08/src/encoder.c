#include "msp430f5529.h"

#include "encoder.h"

typedef enum LineValue {
	Down = 0,
	Up = 1,
} LineValue;

typedef struct EncoderConfiguration {	
	PortConfiguration a_pin;
	PortConfiguration b_pin;
} EncoderConfiguration;

typedef struct EncoderState {
	LineValue a_state;
	LineValue b_state;
	int count;
} EncoderState;

static EncoderConfiguration p1_encoder;
static EncoderState current_state;

EncoderState read_encoder_state();

void init_encoder() {
	EncoderConfiguration p1_encoder = {
		.a_pin = {
			.port_in = P1IN,
			.port_out = P1OUT,
			.port_direction = P1DIR,
			.port_resistor = P1REN,
			.port_interupt = P1IE,
			.port_edge_selector = P1IES,
			.pin = BIT0,
		},
		.b_pin = {
			.port_in = P1IN,
			.port_out = P1OUT,
			.port_direction = P1DIR,
			.port_resistor = P1REN,
			.port_interupt = P1IE,
			.port_edge_selector = P1IES,
			.pin = BIT1,
		},
	};

	*(p1_encoder.a_pin.port_direction) &= ~(p1_encoder.a_pin.pin);
	*(p1_encoder.b_pin.port_direction) &= ~(p1_encoder.b_pin.pin);

	*(p1_encoder.a_pin.port_interupt) |= p1_encoder.a_pin.pin;
	*(p1_encoder.b_pin.port_interupt) |= p1_encoder.b_pin.pin;

	*(p1_encoder.a_pin.port_edge_selector) |= p1_encoder.a_pin.pin;
	*(p1_encoder.b_pin.port_edge_selector) |= p1_encoder.b_pin.pin;

	__eint();


	current_state = read_encoder_state();
}

int get_encoder_count() {
	return current_state.count;
}

void update_encoder_state() {
	EncoderState next_state = read_encoder_state();
	next_state.count = current_state.count;
	
	// Down/Down -> ...
	if (current_state.a_state == Down && current_state.b_state == Down) {
		if (next_state.a_state == Down && next_state.b_state == Up) {
			next_state.count -= 1;
		} else if (next_state.a_state == Up && next_state.b_state == Down) {
			next_state.count += 1;
		}
	}

	// Down/Up -> ...
	if (current_state.a_state == Down && current_state.b_state == Up) {
		if (next_state.a_state == Up && next_state.b_state == Up) {
			next_state.count += 1;
		} else if (next_state.a_state == Down && next_state.b_state == Down) {
			next_state.count -= 1;
		}
	}

	// Up/Up -> ...
	if (current_state.a_state == Up && current_state.b_state == Up) {
		if (next_state.a_state == Up && next_state.b_state == Down) {
			next_state.count -= 1;
		} else if (next_state.a_state == Down && next_state.b_state == Up) {
			next_state.count += 1;
		}
	}

	// Up/Down -> ...
	if (current_state.a_state == Up && current_state.b_state == Down) {
		if (next_state.a_state == Down && next_state.b_state == Down) {
			next_state.count -= 1;
		} else if (next_state.a_state == Up && next_state.b_state == Up) {
			next_state.count += 1;
		}
	}

	current_state = next_state;
}

EncoderState read_encoder_state() {
	EncoderState output = {
		.a_state = *(p1_encoder.a_pin.port_in) & p1_encoder.a_pin.pin,
		.b_state = *(p1_encoder.b_pin.port_in) & p1_encoder.b_pin.pin,
		.count = 0,
	};
	return output;
}

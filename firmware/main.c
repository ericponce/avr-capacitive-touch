#include <avr/io.h>
#include <util/delay.h>
#include "cap_sense_drv.h"

#define INPUT PB3
#define OUTPUT PB4

#define THRESH 1

#define set_as_output(i) (DDRB |= (1 << i))
#define set_as_input(i) (DDRB &= ~(1 << i))


uint8_t sense(void) {
	uint8_t count = 0;
	uint8_t bitmask = 1 << INPUT;

	PORTB &= ~(bitmask); //Turn off pull up
	DDRB |= (bitmask); //Set output

	DDRB &= ~(bitmask); //Set input
	//PORTB |= (bitmask); //Set pull up

	while (!(PINB & bitmask)) {
		count++;
		if (count > 5000) {
			break;
		}
	}
	PORTB &= ~(bitmask); //Turn off pull up
	DDRB |= (bitmask); //Set output

	return (count > THRESH);
}

void init(void) {
	set_as_output(OUTPUT);
	set_as_input(INPUT);
}

int main(void) {
	init();
	cap_sense_open(INPUT);

	while(1) {
		if (cap_sense_read()) {
			PORTB |= (1 << OUTPUT);
		} else {
			PORTB &= ~(1 << OUTPUT);
		}
	}

	return 1;

}
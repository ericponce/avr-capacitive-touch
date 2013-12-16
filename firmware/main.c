#include <avr/io.h>
#include <util/delay.h>
#include "cap_sense_drv.h"

#define INPUT PB3
#define OUTPUT PB4

#define THRESH 1

#define open_output(i) (DDRB |= (1 << i))
#define set_as_input(i) (DDRB &= ~(1 << i))

int main(void) {
	open_output(OUTPUT);
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
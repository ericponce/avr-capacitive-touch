#include "cap_sense_drv.h"

volatile uint8_t pin;

unsigned char cap_sense_open(uint8_t input) {
	pin = input;
	set_as_input(1 << pin);
	return 1;

}

void cap_sense_close(void) {

}

uint8_t cap_sense_read(void) {
	uint8_t count = 0;

	uint8_t p = 1 << pin;

	clear_input_pullup(p);
	set_as_output(p);
	
	set_as_input(p);

	while (!get_input(p)) {
		count++;
	}

	clear_input_pullup(p);
	set_as_output(p);

	return count > THRESH;
}
void cap_sense_write(void) {

}
void cap_sense_ioctl(void) {

}
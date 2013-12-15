#include "cap_sense_drv.h"

volatile uint8_t pin;

unsigned char cap_sense_open(uint8_t input) {
	pin = input;
	set_as_input(pin);
	return 1;

}

void cap_sense_close(void) {

}

uint8_t cap_sense_read(void) {
	uint8_t count = 0;

	clear_input_pullup(pin);
	set_as_output(pin);
	_delay_ms(1);
	set_as_input(pin);

	while (!get_input(pin)) {
		count++;
	}

	clear_input_pullup(pin);
	set_as_output(pin);

	return count > THRESH;
}
void cap_sense_write(void) {

}
void cap_sense_ioctl(void) {

}
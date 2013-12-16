#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define THRESH 1

#define set_as_output(mask) (DDRB |= mask)
#define set_as_input(mask) (DDRB &= ~mask)

#define set_output_high(mask) (PORTB |= mask)
#define set_output_low(mask) (PORTB &= ~mask)

#define set_input_pullup(mask) (PORTB |= mask)
#define clear_input_pullup(mask) (PORTB &= ~mask)

#define get_input(mask) (PINB & mask)

extern unsigned char cap_sense_open(uint8_t input);
extern void cap_sense_close(void);
extern uint8_t cap_sense_read(void);
extern void cap_sense_write(void);
extern void cap_sense_ioctl(void);
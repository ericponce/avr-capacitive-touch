#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define THRESH 1

#define set_as_output(i) (DDRB |= (1 << i))
#define set_as_input(i) (DDRB &= ~(1 << i))

#define set_output_high(i) (PORTB |= (1 << i))
#define set_output_low(i) (PORTB &= ~(1 << i))

#define set_input_pullup(i) (PORTB |= (1 << i))
#define clear_input_pullup(i) (PORTB &= ~(1 << i))

#define get_input(i) (PINB & (1 << i))

extern unsigned char cap_sense_open(uint8_t input);
extern void cap_sense_close(void);
extern uint8_t cap_sense_read(void);
extern void cap_sense_write(void);
extern void cap_sense_ioctl(void);
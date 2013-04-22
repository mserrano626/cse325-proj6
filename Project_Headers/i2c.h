/*
 * i2c.h
 *
 *  Created on: Apr 21, 2013
 *      Author: maserra3
 */

#ifndef I2C_H_
#define I2C_H_

extern void i2c_acquire_bus();
extern void i2c_reset();
extern void i2c_init();
extern void i2c_rx(int addr, int count, int data[], int delay_us);
extern uint8 i2c_rx_byte(int delay_us);
extern void i2c_rxtx_end();
extern void i2c_tx(int addr, int count, unsigned char data[], int delay_us);
extern void i2c_tx_addr(int addr, int rw, int delay_us);
extern void i2c_tx_byte(unsigned char byte, int delay_us);
extern char i2c_tx_complete();
#endif /* I2C_H_ */

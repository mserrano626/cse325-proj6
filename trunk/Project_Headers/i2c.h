/*
 * i2c.h
 *
 *  Created on: Apr 21, 2013
 *      Author: maserra3
 */

#ifndef I2C_H_
#define I2C_H_

extern void i2c_acquire_bus();
extern void i2c_init();
extern void i2C_reset();
extern void i2c_rx(int addr, int count, int data[], int delay_us);

#endif /* I2C_H_ */

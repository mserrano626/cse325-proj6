/*Source File:  i2c.h
 *Project Name: Project 6
 *Name:                 Mario Serrano
 *Email:                maserra3@asu.edu
 *Course name:  CSE325 Embedded Microprocessor Systems
 *Semester:             Spring 2013
 */


#ifndef I2C_H_
#define I2C_H_

extern void i2c_acquire_bus();
extern void i2c_reset();
extern void i2c_init();
extern void i2c_rx(int addr, int count, int data[], int delay_us);
extern uint8 i2c_rx_byte(int delay_us);
extern void i2c_rxtx_end();
extern void i2c_tx(int addr, int count, int data[], int delay_us);
extern void i2c_tx_addr(int addr, int rw, int delay_us);
extern void i2c_tx_byte(unsigned char byte, int delay_us);
extern int i2c_tx_complete();
#endif /* I2C_H_ */

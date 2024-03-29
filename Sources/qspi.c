/*Source File:  qspi.c
 *Project Name: Project 6
 *Name:                 Mario Serrano
 *Email:                maserra3@asu.edu
 *Course name:  CSE325 Embedded Microprocessor Systems
 *Semester:             Spring 2013
 */
#include "global.h"

void qspi_init(){
	MCF_GPIO_PQSPAR |= 0x0011;
	MCF_QSPI_QMR &= 0;
	MCF_QSPI_QMR = 0xA028;
	MCF_QSPI_QWR &= 0;
	MCF_QSPI_QIR &= 0;
	MCF_QSPI_QIR &= 0x0101;
}

void qspi_transmit(uint8 data[]){
	int i;
		//write data values to be transmitted to the transmit queue
		for(i = 0; i < 3; i++) {
			MCF_QSPI_QAR = (unsigned short) i;
			MCF_QSPI_QDR = (unsigned short) data[i];
		}
		
		//write commands to control the transmission to the command queue
		for (i = 0; i < 3; i++) {
			MCF_QSPI_QAR = (unsigned short) (0x20 + i);
			MCF_QSPI_QDR = (unsigned short) 0x0;
		}
		
		//set newqp and endqp to point to the beginning and ending addresses of the queue entries
		//in the command and transmit queues.
		
		MCF_QSPI_QWR &= 0xFFF0;
		MCF_QSPI_QWR |= MCF_QSPI_QWR_ENDQP(2);
		
		//start transfer
		MCF_QSPI_QDLYR |= MCF_QSPI_QDLYR_SPE;
		
		while((MCF_QSPI_QIR & 1) == 0) {}
		MCF_QSPI_QIR |= 0x0001;
}
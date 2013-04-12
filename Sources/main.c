/*Source File:  main.c
 *Project Name: Project 6
 *Name:                 Mario Serrano
 *Email:                maserra3@asu.edu
 *Course name:  CSE325 Embedded Microprocessor Systems
 *Semester:             Spring 2013
 */

#include "support_common.h" /* include peripheral declarations and more */
#include "global.h"

/****data setup***/

#define        black  0x00
#define        red  0x01
#define        green  0x02
#define        orange  0x03      


uint8 trans_data[3];
int green_col[8];
int red_col[8];
int matrix_row;

uint8 g_red [8];
uint8 g_green [8];
uint8 g_row;


int pattern1[8][8] = {
                { black, black, black, green, green, black, black, black},
                { black, black, green, black, black, green, black, black},
                { black, green, black, black, black, black, green, black},
                { green, black, black, black, black, black, black, green},
                { green, black, black, black, black, black, black, green},
                { black, green, black, black, black, black, green, black},
                { black, black, green, black, black, green, black, black},
                { black, black, black, green, green, black, black, black}
};
int new_pattern[8][8];
/****end data setup***/

/*****LED REFRESH FUNCTION*******///////
void led_refresh(){
	///*****write row****///
    trans_data[0] = 0;//red_col[matrix_row];
    trans_data[1] = green_col[matrix_row];
    trans_data[2] = ~(1 << matrix_row);
    
    MCF_GPIO_PORTTH = 0x80;//STR low, OE High
    qspi_transmit(trans_data);
    MCF_GPIO_PORTTH = 0x40; //STR high, OE Low
    ////****end write row*******///////
    
        matrix_row = (matrix_row + 1) % 8;
        
        //pit_enable()
        MCF_PIT0_PCSR |= 0x1;
}
/*****END LED REFRESH FUNCTION*******///////

/*****QSPI TRANSMIT FUNCTION*******///////
void qspi_transmit(uint8 data[]){
	// Writes to the RAM
	int i;
	for(i = 0; i < 3; i++)
	{
		// Write bytes to be transmitted to the RAM
		MCF_QSPI_QAR = (unsigned short) i;
		MCF_QSPI_QDR = (unsigned short) data[i];
		
		// Write commands to be written to the RAM
		MCF_QSPI_QAR = (unsigned short) (0x20 + i);
		MCF_QSPI_QDR = (unsigned short) 0x0000;
	}
	
	// Sets up Pointers
	MCF_QSPI_QWR &= 0xFFF0; // Clears the value in NEWQP
	MCF_QSPI_QWR |= MCF_QSPI_QWR_ENDQP(2); // Sets the end pointer to address 2
	
	// Transmits bits
	MCF_QSPI_QDLYR |= 0x8000;
	
	// Wait until all of the bits have been transmitted
	while((MCF_QSPI_QIR & 1) == 0) {}
			
	// Clear flag
	MCF_QSPI_QIR |= 0x0001;

}
/*****END QSPI TRANSMIT FUNCTION*******///////

int i;
int j;
__declspec(noreturn)int main(void)
{
	int counter = 0;
    int row;
    int col;
	/****GPIO SETUP****/
	MCF_GPIO_PQSPAR |= 0x0011;
	//MCF_GPIO_PORTQS = 0x05;
    MCF_GPIO_PTHPAR &= 0xCFFF;
	//MCF_GPIO_DDRQS = 0x05;
	MCF_GPIO_DDRTH |= 0x40;
	MCF_GPIO_PTHPAR &= 0x3FFF;
	MCF_GPIO_DDRTH |= 0x80;
	MCF_GPIO_SETTH |= 0x80;
	/****END GPIO SETUP****/
	
	/****QSPI SETUP****/
	MCF_QSPI_QMR &= 0x0000; // Clear Master Register
	MCF_QSPI_QMR |= 0x8000; // Enable master mode
	MCF_QSPI_QMR |= 0x2000; // Set BITS to 8 bits per transfer
	MCF_QSPI_QMR &= 0xFDFF; // Clock Polarity - Clock signal is low when idle
	MCF_QSPI_QMR &= 0xFEFF; // Clock Phase - Data changes on the leading edge of QSPI_CLK and captured on the following edge of QSPI_CLK
	MCF_QSPI_QMR |= 0x0028; // Sets the Baud rate of the clock to 1MHz or 1Mbps
	
	MCF_QSPI_QWR &= 0x0000; // Clears the Wrap Register
	
	MCF_QSPI_QIR &= 0x0000; // Clears the Interrupt Register
	MCF_QSPI_QIR |= 0x0101; // Enables the "QSPI has finished transmitting bits" interrupt and clears the associated flag
	/****END QSPI SETUP****/
	
	/****PIT0 SETUP****/
    MCF_PIT0_PCSR = 0x0A1E;
    MCF_PIT0_PMR = 0x1E;//58593;//0x1E;    //30
    MCF_PIT0_PCSR |= MCF_PIT_PCSR_EN;
    /****END pit0 SETUP****/
    
    /****LED MATRIX FUNCTION****/

            
	
	for(i = 0; i < 8; i++) {

		g_red[i] = 0x00;

		g_green[i] = 0x00;
			
			// Writing columns
			for(j = 0; j < 8; j++)
			{
				if(new_pattern[i][j] == red)
				{
					g_red[i] |= 1 << j;
				}
				else if(new_pattern[i][j] == green)
				{
					g_green[i] |= 1 << j;
				}
				else if(new_pattern[i][j] == orange)
				{
					g_red[i] |= 1 << j;
					g_green[i] |= 1 << j;
				}
			}
		}
	
    /****end LED MATRIX FUNCTION****/
            
    interupt_config(55, 4, 6, pit0_isr);   
    int_uninhibit_all();
      
    led_refresh();
	for(;;) {	   
		
	}
}

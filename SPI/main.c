#include "TM4C123GH6PM.h"
#define SSI_0    (1U<<0)
#define PTA     (1U<<0)
#define PA2     (1U<<2)
#define PA3     (1U<<3)
#define PA4     (1U<<4)
#define PA5     (1U<<5)
#define SSI_EN  (1U<<1)
#define SSI_LOOP_BACK_EN (1U<<0)

void Write_SPI(uint8_t data)
{
  SSI0->DR = data;
  data =0;
  while((SSI0->SR &(1<<0))==0);
  data = SSI0->DR;
  data++;
}


int main()
{
//1. Enable the SSI module using the RCGCSSI register (see page 346).
 SYSCTL->RCGCSSI |=SSI_0;
//2. Enable the clock to the appropriate GPIO module via the RCGCGPIO register (see page 340).
 SYSCTL->RCGCGPIO |=PTA;
//To find out which GPIO port to enable, refer to Table 23-5 on page 1351.
//3. Set the GPIO AFSEL bits for the appropriate pins (see page 671). To determine which GPIOs to
//configure, see Table 23-4 on page 1344.
//4. Configure the PMCn fields in the GPIOPCTL register to assign the SSI signals to the appropriate
//pins. See page 688 and Table 23-5 on page 1351.
//5. Program the GPIODEN register to enable the pin's digital function. In addition, the drive strength,
//drain select and pull-up/pull-down functions must be configured. Refer to “General-Purpose
//Input/Outputs (GPIOs)” on page 649 for more information.
//Note: Pull-ups can be used to avoid unnecessary toggles on the SSI pins, which can take the
//slave to a wrong state. In addition, if the SSIClk signal is programmed to steady state
//High through the SPO bit in the SSICR0 register, then software must also configure the
//GPIO port pin corresponding to the SSInClk signal as a pull-up in the GPIO Pull-Up
//Select (GPIOPUR) register.
 GPIOA->AFSEL |=PA2|PA3|PA4|PA5;
 GPIOA->DEN |=PA2|PA3|PA4|PA5;
 GPIOA->PUR |=PA2|PA3|PA4|PA5;
//For each of the frame formats, the SSI is configured using the following steps:
//1. Ensure that the SSE bit in the SSICR1 register is clear before making any configuration changes.
//2. Select whether the SSI is a master or slave:
//a. For master operations, set the SSICR1 register to 0x0000.0000.
//b. For slave mode (output enabled), set the SSICR1 register to 0x0000.0004.
//c. For slave mode (output disabled), set the SSICR1 register to 0x0000.000C.
//3. Configure the SSI clock source by writing to the SSICC register.
//4. Configure the clock prescale divisor by writing the SSICPSR register.
//5. Write the SSICR0 register with the following configuration:
//¦ Serial clock rate (SCR)
//¦ Desired clock phase/polarity, if using Freescale SPI mode (SPH and SPO)
//¦ The protocol mode: Freescale SPI, TI SSF, MICROWIRE (FRF)
//¦ The data size (DSS)
//6. Optionally, configure the SSI module for µDMA use with the following steps:
//a. Configure a µDMA for SSI use. See “Micro Direct Memory Access (µDMA)” on page 585 for
//more information.
//b. Enable the SSI Module's TX FIFO or RX FIFO by setting the TXDMAE or RXDMAE bit in the
//SSIDMACTL register.
//7. Enable the SSI by setting the SSE bit in the SSICR1 register.
 
//As an example, assume the SSI must be configured to operate with the following parameters:
//¦ Master operation
//¦ Freescale SPI mode (SPO=1, SPH=1)
//¦ 1 Mbps bit rate
//¦ 8 data bits
//Assuming the system clock is 16 MHz, the bit rate calculation would be:
//SSInClk = SysClk / (CPSDVSR * (1 + SCR))
//1x106 = 16x106 / (CPSDVSR * (1 + SCR))
//In this case, if CPSDVSR=0x2, SCR must be 0x7.
//The configuration sequence would be as follows:
//1. Ensure that the SSE bit in the SSICR1 register is clear.
// SSI0->CR1= 0x01;
 SSI0->CC = 0x00;
 SSI0->CPSR = 0x2;
 SSI0->CR0 = 0x07;
//2. Write the SSICR1 register with a value of 0x0000.0000.
// SSI0->CR1 |=SSI_LOOP_BACK_EN;
//3. Write the SSICPSR register with a value of 0x0000.0002.
//4. Write the SSICR0 register with a value of 0x0000.09C7.
//5. The SSI is then enabled by setting the SSE bit in the SSICR1 register.
 SSI0->CR1 |= SSI_EN;
 while(1)
 {
   Write_SPI(0xAA);
 }
}

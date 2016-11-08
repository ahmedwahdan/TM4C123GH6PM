/*
 * MCAL_GPIO.c
 *
 * Created: 9/3/2016 8:57:08 AM
 *  Author: Master
 */ 
 #include "MCAL_GPIO.h"
 #include "TM4C123GH6PM.h"


 void GPIO_Init(GPIO_Init_Param_t * gpio_Param)
 {
 /*
	01001010  // direction
	00001111  // mask
	00001010

*/
	switch(gpio_Param->Port_Name)
	{
		case PTA:
                  SYSCTL->RCGCGPIO |= (1U<<PTA);
                  GPIOA->DEN |= gpio_Param->Mask ;
                  GPIOA->DIR = (GPIOA->DIR &~(gpio_Param->Mask)) | (gpio_Param->Direction&gpio_Param->Mask);
                  if(gpio_Param->Pulled == Pulled_Down)
                  {
                    GPIOA->PDR |= gpio_Param->Mask;
                  }
                  else if(gpio_Param->Pulled == Pulled_Up)
                  {
                     GPIOA->PUR |= gpio_Param->Mask;
                  }
                  else
                  {
                    
                  }
                  GPIOA->DATA = (GPIOA->DATA &~(gpio_Param->Mask)) | (gpio_Param->Data&gpio_Param->Mask);
		break;	
		case PTB:
                  SYSCTL->RCGCGPIO |= (1U<<PTB);
                  GPIOB->DEN |= gpio_Param->Mask ;
                  GPIOB->DIR = (GPIOB->DIR &~(gpio_Param->Mask)) | (gpio_Param->Direction&gpio_Param->Mask);
                  if(gpio_Param->Pulled == Pulled_Down)
                  {
                    GPIOB->PDR |= gpio_Param->Mask;
                  }
                  else if(gpio_Param->Pulled == Pulled_Up)
                  {
                     GPIOB->PUR |= gpio_Param->Mask;
                  }
                  else
                  {
                    
                  }
                  GPIOB->DATA = (GPIOB->DATA &~(gpio_Param->Mask)) | (gpio_Param->Data&gpio_Param->Mask);
		break;
		case PTC:
                  SYSCTL->RCGCGPIO |= (1U<<PTC);
                  GPIOC->DEN |= gpio_Param->Mask ;
                  GPIOC->DIR = (GPIOC->DIR &~(gpio_Param->Mask)) | (gpio_Param->Direction&gpio_Param->Mask);
                  if(gpio_Param->Pulled == Pulled_Down)
                  {
                    GPIOC->PDR |= gpio_Param->Mask;
                  }
                  else if(gpio_Param->Pulled == Pulled_Up)
                  {
                     GPIOC->PUR |= gpio_Param->Mask;
                  }
                  else
                  {
                    
                  }
                  GPIOC->DATA = (GPIOC->DATA &~(gpio_Param->Mask)) | (gpio_Param->Data&gpio_Param->Mask);
		break;
		case PTD:
                  SYSCTL->RCGCGPIO |= (1U<<PTD);
                  GPIOD->DEN |= gpio_Param->Mask ;
                  GPIOD->DIR = (GPIOD->DIR &~(gpio_Param->Mask)) | (gpio_Param->Direction&gpio_Param->Mask);
                  if(gpio_Param->Pulled == Pulled_Down)
                  {
                    GPIOD->PDR |= gpio_Param->Mask;
                  }
                  else if(gpio_Param->Pulled == Pulled_Up)
                  {
                     GPIOD->PUR |= gpio_Param->Mask;
                  }
                  else
                  {
                    
                  }
                  GPIOD->DATA = (GPIOD->DATA &~(gpio_Param->Mask)) | (gpio_Param->Data&gpio_Param->Mask);
		break;
                case PTE:
                  SYSCTL->RCGCGPIO |= (1U<<PTE);
                  GPIOE->DEN |= gpio_Param->Mask ;
                  GPIOE->DIR = (GPIOE->DIR &~(gpio_Param->Mask)) | (gpio_Param->Direction&gpio_Param->Mask);
                  if(gpio_Param->Pulled == Pulled_Down)
                  {
                    GPIOE->PDR |= gpio_Param->Mask;
                  }
                  else if(gpio_Param->Pulled == Pulled_Up)
                  {
                     GPIOE->PUR |= gpio_Param->Mask;
                  }
                  else
                  {
                    
                  }
                  GPIOE->DATA = (GPIOE->DATA &~(gpio_Param->Mask)) | (gpio_Param->Data&gpio_Param->Mask);
		break;
		case PTF:
                  SYSCTL->RCGCGPIO |= (1U<<PTF);
                  GPIOF->DEN |= gpio_Param->Mask ;
                  GPIOF->DIR = (GPIOF->DIR &~(gpio_Param->Mask)) | (gpio_Param->Direction&gpio_Param->Mask);
                  if(gpio_Param->Pulled == Pulled_Down)
                  {
                    GPIOF->PDR |= gpio_Param->Mask;
                  }
                  else if(gpio_Param->Pulled == Pulled_Up)
                  {
                     GPIOF->PUR |= gpio_Param->Mask;
                  }
                  else
                  {
                    
                  }
                  GPIOF->DATA = (GPIOF->DATA &~(gpio_Param->Mask)) | (gpio_Param->Data&gpio_Param->Mask);
		break;
		default:
		// nothing changed =>> MISRA rule
		break;
		
	}
 }

 void GPIO_Write(GPIO_Write_Param_t * gpio_Param)
 {
 switch(gpio_Param->Port_Name)
 {
     case PTA:
                    
                      GPIOA->DATA = (GPIOA->DATA &~(gpio_Param->Mask)) | (gpio_Param->Data&gpio_Param->Mask);
      break;	
      case PTB:
                     
                      GPIOB->DATA = (GPIOB->DATA &~(gpio_Param->Mask)) | (gpio_Param->Data&gpio_Param->Mask);
      break;
      case PTC:
                     
                      GPIOC->DATA = (GPIOC->DATA &~(gpio_Param->Mask)) | (gpio_Param->Data&gpio_Param->Mask);
      break;
      case PTD:
                     
                      GPIOD->DATA = (GPIOD->DATA &~(gpio_Param->Mask)) | (gpio_Param->Data&gpio_Param->Mask);
      break;
       case PTE:
                     
                      GPIOE->DATA = (GPIOE->DATA &~(gpio_Param->Mask)) | (gpio_Param->Data&gpio_Param->Mask);
      break;
      case PTF:
                     
                      GPIOF->DATA = (GPIOF->DATA &~(gpio_Param->Mask)) | (gpio_Param->Data&gpio_Param->Mask);
      break;
      default:
      // nothing changed =>> MISRA rule
      break;
              
 }
 }
 uint8_t GPIO_Read(GPIO_Read_Param_t * gpio_Param)
 {
	uint8_t value = 0;
	switch(gpio_Param->Port_Name)
	{
		case PTA:
		value = (uint8_t)((GPIOA->DATA & (1U<<(gpio_Param->PIN_Number)))>>gpio_Param->PIN_Number);
		break;
		case PTB:
		value = (uint8_t)((GPIOB->DATA & (1U<<(gpio_Param->PIN_Number)))>>gpio_Param->PIN_Number);
		break;
		case PTC:
		value = (uint8_t)((GPIOC->DATA & (1U<<(gpio_Param->PIN_Number)))>>gpio_Param->PIN_Number);
		break;
		case PTD:
		value = (uint8_t)((GPIOD->DATA & (1U<<(gpio_Param->PIN_Number)))>>gpio_Param->PIN_Number);
		break;
                case PTE:
		value = (uint8_t)((GPIOE->DATA & (1U<<(gpio_Param->PIN_Number)))>>gpio_Param->PIN_Number);
		break;
		case PTF:
		value = (uint8_t)((GPIOF->DATA & (1U<<(gpio_Param->PIN_Number)))>>gpio_Param->PIN_Number);
		break;
		default:
		/* nothing changed =>> MISRA rule */
		break;
		
	}
	return value;
 }
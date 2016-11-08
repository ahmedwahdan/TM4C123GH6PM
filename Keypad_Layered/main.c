#include "keypad.h"
  char volatile value =0;
int main()
{

   Keypad_Init();
   while(1)
   {
     value = Keypad_getkey();
     asm("NOP");
   }
  
  return 0;
}

/*
 * keypad_config.c
 *
 * Created: 10/11/2016 11:30:42 AM
 *  Author: Master
 */ 
 #include "keypad_config.h"


 const Keypad_config_t g_Keypad_Col_Config[Col_numbers] =
 {
	 {PTE,4},
	 {PTB,1},
	 {PTB,0},
	 {PTB,5}
 };

 const Keypad_config_t g_Keypad_Row_Config[Row_numbers] =
 {
	 {PTA,6},
	 {PTA,5},
	 {PTB,4},
	 {PTE,5}
 };
 /*
-----------------
| 1 | 2 | 3 | A |
-----------------
| 4 | 5 | 6 | B |
-----------------
| 7 | 8 | 9 | C |
-----------------
| * | 0 | # | D |
-----------------
 */

 const uint8_t g_Keypad_Map[Row_numbers][Col_numbers] =
 {
 {'7','8','9','A'},
  {'4','5','6','B'},
 {'1','2','3','C'},
 {'*','0','#','D'}
 /*
	{'1','2','3','A'},
	{'4','5','6','B'},
	{'7','8','9','C'},
	{'*','0','#','D'}
*/
 };
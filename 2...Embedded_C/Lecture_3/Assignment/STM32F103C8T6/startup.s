/* startup.s
	Eng.ABDULRHMAN
*/

.section .vectors

.word 0x20001000
.word _reset_handler 				/*_reset_handler*/
.word _Default_Handler 				/*_NMI_handler*/
.word _Default_Handler 				/*_HardFault_handler*/
.word _Default_Handler 				/*_MemManage_handler*/
.word _Default_Handler 				/*_BusFault_handler*/
.word _Default_Handler 				/*_UsageFault_handler*/
.word _Default_Handler 				/*_Reserved_handler*/
.word _Default_Handler 				/*_Reserved_handler*/
.word _Default_Handler 				/*_Reserved_handler*/
.word _Default_Handler 				/*_Reserved_handler*/
.word _Default_Handler 				/*_SVCall_Handler*/
.word _Default_Handler 				/*_DebugMonitor_Handler*/
.word _Default_Handler 				/*_PendSV_Handler*/
.word _Default_Handler 				/*_SysTick_Handler*/
.word _Default_Handler 				/*_IRQ0*/
.word _Default_Handler 				/*_IRQ1*/
.word _Default_Handler 				/*_IRQ2*/
.word _Default_Handler 				/*4....>67*/


.section .text

_reset_handler:
	bl main
	b .
	
	
.thumb_func
_Default_Handler:
	b _reset_handler	
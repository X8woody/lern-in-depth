/**
 ******************************************************************************
 * @file           : linker_script.ld
 * @author         : ENG. ABDULRAHMAN ALAA-ELDIN
 * @brief          : Main program body
 ******************************************************************************
 */

MEMORY
{
	FLASH(RX)  : ORIGIN = 0x00000000, LENGTH = 512M
	SRAM(RWX)  : ORIGIN = 0x20000000, LENGTH = 512M 
}


SECTIONS
{
	.text :
	{
		*(.vectors*)
		*(.text*)
		*(.rodata)
		_E_Text = . ;
	}> FLASH
	.data :
	{
		_S_Data = . ;
		*(.data*)
		_E_Data = . ;
	}> SRAM AT> FLASH
	.bss : 
	{
		_S_Bss = . ;
		*(.bss*)
		_E_Bss = . ;
	}> SRAM
}
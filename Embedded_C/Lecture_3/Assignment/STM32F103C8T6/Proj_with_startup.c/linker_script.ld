

MEMORY
{
	FLASH(RX)  : ORIGIN = 0x08000000, LENGTH = 128K
	SRAM(RWX)  : ORIGIN = 0x20000000, LENGTH = 20K 
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
		. = ALIGN(4) ;
	}> SRAM
	. = . + 0x1000 ; 
	_Stack_Top = . ;
}
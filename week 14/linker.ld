ENTRY(Reset_Handler)

MEMORY{
	 SRAM(rwx):ORIGIN = 0x20000000 , LENGTH = 128k
	 FLASH(rx) :ORIGIN = 0x08000000 , LENGTH = 512k
}
SECTIONS{
	.text :
	{
		*(.text)
		*(.isr_vector)
		*(.rodata)
		. = ALIGN(4) ; 
		_etext = . ;
	}>FLASH
	.data :
	{
		_sdata = . ;
		*(.data)
		. = ALIGN(4) ;
		_edata = . ;
	}>SRAM AT>FLASH
	.bss :
	{
		_sbss = . ;
		*(.bss)
		. = ALIGN(4) ;
		_ebss = . ;
	}>SRAM
}
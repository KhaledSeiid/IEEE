CC = arm-none-eabi-gcc
OBGDUMP= arm-none-eabi-objdump
CFLAGS = -c -mcpu=$(ACH) -std=gnu11 -mthumb
LDFLAGS = -T linker.ld -nostdlib -Wl,-Map=executable.map
ACH = cortex-m3
main.o: main.c
	@$(CC) $(CFLAGS) $^ -o $@
lcd.o:lcd.c
	@$(CC) $(CFLAGS) $^ -o $@
Stm32_F103C6_GPIO.o:Stm32_F103C6_GPIO.c
	@$(CC) $(CFLAGS) $^ -o $@
startup.o: startup.c
	@$(CC) $(CFLAGS) $^ -o $@
executble.elf:main.o lcd.o Stm32_F103C6_GPIO.o startup.o
	@$(CC) $(LDFLAGS) $^ -o $@
all:main.o lcd.o Stm32_F103C6_GPIO.o startup.o executble.elf
clean:
	@rm -f *.o 
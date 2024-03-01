CC = arm-none-eabi-gcc
OBGDUMP= arm-none-eabi-objdump
CFLAGS = -c -mcpu=$(ACH) -std=gnu11 -mthumb
LDFLAGS = -T linker.ld -nostdlib -Wl,-Map=executable.map
ACH = cortex-m4

main.o: main.c
	@$(CC) $(CFLAGS) $^ -o $@
GPIO_prog.o:GPIO_prog.c
	@$(CC) $(CFLAGS) $^ -o $@
RCC_prog.o:RCC_prog.c
	@$(CC) $(CFLAGS) $^ -o $@
sysTick_prog.o:sysTick_Prog.c
	@$(CC) $(CFLAGS) $^ -o $@
startup.o: startup.c
	@$(CC) $(CFLAGS) $^ -o $@
executble.elf:main.o GPIO_prog.o RCC_prog.o sysTick_Prog.o startup.o
	@$(CC) $(LDFLAGS) $^ -o $@
all: main.o GPIO_prog.o RCC_prog.o sysTick_Prog.o startup.o executble.elf

clean:
	@rm -f *.o
CC = arm-none-eabi-gcc
OBGDUMP= arm-none-eabi-objdump
CFLAGS = -c -mcpu=$(ACH) -std=gnu11 -mthumb

ACH = cortex-m4

main.o: main.c
	@$(CC) $(CFLAGS) $^ -o $@
clean:
	@rm -f *.exe
	@rm -f *.o
analyze:
	 @$(OBGDUMP) -h main.o
main.exe: main.c
	arm-none-eabi-gcc -nostdlib -nolibc -mcpu=cortex-m4 -mthumb -g -I . -gdwarf-2 $^ -o $@
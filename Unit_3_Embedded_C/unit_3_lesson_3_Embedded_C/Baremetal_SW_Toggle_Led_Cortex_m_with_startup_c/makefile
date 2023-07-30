#Author: Eng. Mustafa Hafez
#Version: V1.0
#Release Date: 26/7/2023

CC=arm-none-eabi-
INCS= -I .
CFLAGS=  -mcpu=cortex-m3 -mthumb -gdwarf-2
LIBS= 
SRC = $(wildcard *.c)
OBJ= $(SRC:.c=.o)
ASSSRC= $(wildcard *.s)
OBJAss= $(ASSSRC:.s=.o)
Project_Name=Toggle_LED_Cortex_m3

all: $(Project_Name).bin
	@echo "___Building process is done: Mustafa Hafez____"
	

#startup.o: startup.s
#	$(CC)as.exe  $(CFLAGS) $< -o $@
	
%.o: %.c
	$(CC)gcc.exe -c -std=c99 $(INCS) $(CFLAGS) $< -o $@
	
	
$(Project_Name).elf: $(OBJ) $(OBJAss)
	$(CC)ld.exe -T linker_script.ld -Map=map_file.map $(LIBS) $(OBJ) $(OBJAss) -o $@


$(Project_Name).bin: $(Project_Name).elf
	$(CC)objcopy.exe -O binary $<  $@
	
clean_all:
	rm *.elf *.bin *.o
clean:	
	rm *.elf *.bin
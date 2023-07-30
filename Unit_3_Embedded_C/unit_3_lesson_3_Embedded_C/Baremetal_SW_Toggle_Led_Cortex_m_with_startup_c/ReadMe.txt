Author: Eng. Mustafa Hafez




The arm-cortex-m Family has a wonderful features, The addresse at the entry point of the processor will be used to initiate the stack pointer (sp).
so, we can write the startup file by C-language as the stack will be intiated.

Imagine that we have the ability to make an array  of type uint_32 as each elelment will take a 4 byte , as we know the array elements are arranged
squantily in the memory, so if we make the first element of our array equal to the address we want to give to the SP, and by someway but this array 
at the entry point of processor, so we can make the startup file and the next element in array will be next to the SP addresse.

The command __attribute__ ((section(".vectors")))  is used to put some lines at a desired spcified section. so we put our arrays at a .vector section
by that way, we will be able to make the vector section at the begining of the .text section in the linkerscript file.

----------------------
|		     |		
|   stack_pointer    |
| -------------------|
|      .bss          |
|                    |
|--------------------
|     .data	     |
|--------------------
|     .text	     |
|  ------------	     |
|  |.vector   |      |
|  ------------      |
----------------------

Weak and Alias:

 when we define the vector table of our MC, it may be have a huge number of interrupt , so it's not sensible to define all of them, in addition, the 
user itself may not use all of them so why occuipe an address although the user dosen't use them ?!!

The weak and alias help to avoid that, as we give the function a weak attribute to make it overridden and an alias to a defualt handler defintion by 
this way, a user can override the function difention and if it not defined, it takes the default aliased defintion.

Copying data from ROM to SRAM and intiate the .bss with zero at the SRAM:

1-Copying data from ROM to SRAM:
As we know the .data section is burned on the flash but during the startup , it's copied to the SRAM
we can do that if we  know:
				- what's the start address of .data sectoin
				- what's the end address of .data sectoin.
				- As a result the size of .data is known.
2-Intiate the .bss with zero at the SRAM:
As we know the .bss section does't exist at the flash but with an information of its size we intialize the SRAM with it.
we can do that if we  know:
				- what's the start address of .bss sectoin
				- what's the end address of .bss sectoin.
				- As a result the size of .data is known.

Important Note:

1-We use VMA (Virtual memory address) while copying the data to SRAM while LMA (Local Memory Address) is the physical address at burning.
2-Don't forget to check the map file to make sure everything is correct and the memory is aligned (no odd address as it's effect on performance).
3-Use ALIGN(4) to align your memory with 4 Bytes if you need.









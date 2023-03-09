The Difference between compiler and interpreter:

*Interpretter:

1- It Compiles each line of source code line by line then excutes it.
2- it runs on operating system
3- It is slower than the compiler as it deals with line by line not the all over the code.

Ex:
Python 

*Compiler:

1- Compilers compile the all code not line by line then extract the binary file or the excutable
   file that will be excuted on the target hardware.
2- Compilers don't require an operating system as the binary file or the excutable file can run on the target hardware directly.
3- Compilers are faster than  interpreter as the source code compiled once then the excutable is extracted so the  run time doesn't
   depend on the compilation time
    
Ex:
c/c++

How to test or prove that Compiler is faster than interpreter?
1- Write a shell script with a simple code such as a program that takes two numbers,
   doing an arthimatic operation on them then display the result.
2-Write the same program but with c language.
3-To make the comparison fair, don't make user to enter the value of two numbers,but assign them in your code 

* you will notice that the time excutation of compiler is less than interpreter.

Shell Script:
/**********************************************/
start=`date +%s`
echo -n "Enter the first number: "
#read number1
number1=5
echo -n "Enter the second number: "
#read number2
number2=4
num3=5
sum=`expr $number1 + $number2`
sub=`expr $number1 - $number2`
echo "The sum of two value is $sum"
echo "The sub of two value is $sub"
end=`date +%s`
echo Excution time was `expr $end - $start` seconds. 
/**********************************************/ -------> the time was 1 sec.


C language Code:
/**********************************************/
#include <stdio.h>
#include<time.h>

void main(void)
{
	
	
	clock_t t;
	t = clock(); // calculate number of ticks from here
	int num1,num2,num3,sum;
	printf("Enter the first number:\n");
	//scanf("%d",&num1);
	num1 = 5;
	printf("Enter the second number:\n");
	//scanf("%d",&num2);
	num2 = 4;
	num3 =2;
	sum = num1 + num2;
	printf("the sum of two numbers is %d\n",sum);
	t = clock()-t;
	double time_taken = ((double)t)/CLOCKS_PER_SEC;
	printf("The function took %f seconds\n",time_taken);

}
/**************************************************************/------> The time was 0.00000 sec.
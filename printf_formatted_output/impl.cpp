#include<stdio.h>

int   main()
{
	printf("The color: %s\n", "blue");
	printf("First number: %d\n", 12345);
	printf("First number: %2d\n", 12345);
	printf("Second number: %04d\n", 25);
	printf("Second number: %0d\n", 25);
	printf("Third number: %i\n", 1234);
	printf("Float number: %3.2f\n", 3.14159);
	printf("Float number: %3.2f\n", 3.1);
	printf("Percentage number: %4.2f\n", 0.99);
	printf("Float number: %07.1f\n", 100.19159);
	printf("Hexadecimal: %x\n", 255);
	printf("Octal: %o\n", 255);
	printf("Unsigned value: %u\n", 150);
	printf("Just print the percentage sign %%\n", 10);
}

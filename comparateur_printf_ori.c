#include <stdio.h>

unsigned int number = 1024;
int number2 = -2147483648;
char *line = "Ceci est un test";
char chara = 'b';
void *pointer = &number2;
int	main()
{
	printf("Value of char using %%c is : %c\n", chara);
	printf("Value of string using %%s is : %s\n", line);
	printf("Value of pointer using %%p is : %p\n", pointer);
	printf("Value of number2 using %%p is : %p\n", number2);
	printf("Value of num2 using %%d is : %d\n", number2);
	printf("Value of num2 using %%i is : %i\n", number2);
	printf("Value of num using %%u is : %u\n", number);
	printf("Value of num2 using %%x is : %x\n", number2);
	printf("Value of num2 using %%X is : %X\n", number2);
	printf("la fonction printf doit afficher \"%%\" si on lui envoie \"%%%%\"\nmais aussi \"%%%%%%\" si \"%%%%%%%%%%%%:\"\n");
	printf("ceci est une erreur?%mouais\n");
	return(0);
}
#include "ft_printf.h"

unsigned int number = 1024;
int number2 = -2147483648;
char *line = "Ceci est un test";
char chara = '0';
void *pointer = (void *)-1;
int	main()
{
	printf("Number of char printed by printf : %i\n", printf("Value of char by printf using %%c is : %c\n", chara));
	printf("Number of char printed by printf : %i\n", printf("Value of string by printf using %%s is : %s\n", line));
	printf("Number of char printed by printf : %i\n", printf("Value of pointer by printf using %%p is : %p\n", pointer));
	printf("Number of char printed by printf : %i\n", printf("Value of number2 by printf using %%p is : %p\n", number2));
	printf("Number of char printed by printf : %i\n", printf("Value of num2 by printf using %%d is : %d\n", number2));
	printf("Number of char printed by printf : %i\n", printf("Value of num2 by printf using %%i is : %i\n", number2));
	printf("Number of char printed by printf : %i\n", printf("Value of num by printf using %%u is : %u\n", number));
	printf("Number of char printed by printf : %i\n", printf("Value of num2 by printf using %%x is : %x\n", number2));
	printf("Number of char printed by printf : %i\n", printf("Value of num2 by printf using %%X is : %X\n", number2));
	printf("Number of char printed by printf : %i\n", printf("la fonction printf doit afficher \"%%\" si on lui envoie \"%%%%\"\nmais aussi \"%%%%%%\" si \"%%%%%%%%%%%%:\"\n"));
	printf("Number of char printed by printf : %i\n\n", printf("ceci est une erreur?%mouais\n"));

	ft_printf("Value of char by printf using %%c is : %c\n", chara);
	ft_printf("Value of string by printf using %%s is : %s\n", line);
	ft_printf("Value of pointer by printf using %%p is : %p\n", pointer);
	ft_printf("Value of number2 by printf using %%p is : %p\n", number2);
	ft_printf("Value of num2 by printf using %%d is : %d\n", number2);
	ft_printf("Value of num2 by printf using %%i is : %i\n", number2);
	ft_printf("Value of num by printf using %%u is : %u\n", number);
	ft_printf("Value of num2 by printf using %%x is : %x\n", number2);
	ft_printf("Value of num2 by printf using %%X is : %X\n", number2);
	ft_printf("la fonction printf doit afficher \"%%\" si on lui envoie \"%%%%\"\nmais aussi \"%%%%%%\" si \"%%%%%%%%%%%%:\"\n");
	ft_printf("ceci est une erreur?%mouais\n");
	return(0);
}

/*int	main()
{
	ft_printf("Value of string is : %s EndOfLine\n", line);
	printf("count by printfOri : %i\n", printf("Value of string is : %s EndOfLine\n", line));
	return(0);
}*/
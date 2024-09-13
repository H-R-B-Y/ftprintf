#include "ft_printf.h"
#include <stdio.h>

void TEST(int p, int x)
{
	(void)p;
	printf("\n%d\n", x);
	fflush(stdout);
}

int main (int argc, char **argv)
{
	unsigned long ULONG_MAX			= 0xFFFFFFFFFFFFFFFFUL;
	long LONG_MAX					= 0x7FFFFFFFFFFFFFFFL;
	long LONG_MIN					= 0x8000000000000000L;
	int INT_MAX						= __INT_MAX__;
	int INT_MIN						= ~INT_MAX;
	unsigned UINT_MAX				= ~((unsigned)0);
	char *s2						= "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";
	int	(*print)(const char*, ...)	= (argc > 1 && !ft_strncmp(argv[1], "st", 2)) ? &printf : &ft_printf;
	print("\nMINUS:\n");
	TEST(5, print(" %-1c %-2c %-3c ", '0', 0, '1'));
	TEST(8, print(" %-1c %-2c %-3c ", '2', '1', 0));
	TEST(9, print(" %-1c %-2c %-3c ", 0, '1', '2'));
	print("\nDOT:\n");
	TEST(5, print(" %.s ", "-"));
	TEST(8, print(" %.1s %.2s %.3s %.4s ", " - ", "", "4", ""));
	TEST(9, print(" %.2s %.3s %.4s %.5s %.1s ", " - ", "", "4", "", "2 "));
	// Cleanup
	if (1)
	{
	(void)ULONG_MAX;
	(void)LONG_MAX;
	(void)LONG_MIN;
	(void)INT_MAX;
	(void)INT_MIN;
	(void)s2;
	(void)UINT_MAX;
	}
}

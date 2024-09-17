#include "ft_printf.h"
#include <stdio.h>

void TEST(int p, int x)
{
	(void)p;
	printf("\nWIDTH: %d\n", x);
	fflush(stdout);
}

int main (int argc, char **argv)
{
	int	(*print)(const char*, ...)	= (argc > 1 && argv[1][0] == 's' && argv[1][1] == 't') ? &printf : &ft_printf;
	unsigned long ULONG_MAX			= 0xFFFFFFFFFFFFFFFFUL;
	unsigned UINT_MAX				= ~((unsigned)0);
	long LONG_MAX					= 0x7FFFFFFFFFFFFFFFL;
	long LONG_MIN					= 0x8000000000000000L;
	int INT_MAX						= __INT_MAX__;
	int INT_MIN						= ~INT_MAX;
	char *s2						= "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";
	TEST(2, print(" %X ", -1));
	TEST(13, print(" %X ", -9));
	TEST(14, print(" %X ", -10));
	TEST(15, print(" %X ", -11));
	TEST(16, print(" %X ", -14));
	TEST(17, print(" %X ", -15));
	TEST(18, print(" %X ", -16));
	TEST(19, print(" %X ", -99));
	TEST(20, print(" %X ", -100));
	TEST(21, print(" %X ", -101));
	TEST(23, print(" %X ", INT_MIN));
	TEST(24, print(" %X ", LONG_MAX));
	TEST(26, print(" %X ", UINT_MAX));
	TEST(27, print(" %X ", ULONG_MAX));
	TEST(28, print(" %X ", 9223372036854775807LL));
	TEST(29, print(" %X %X %X %X %X %X %X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42));
	TEST(31, print(" %X ", -42));


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

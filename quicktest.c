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
	int	(*print)(const char*, ...)	= (argc > 1 && !ft_strncmp(argv[1], "st", 2)) ? &printf : &ft_printf;
	unsigned long ULONG_MAX			= 0xFFFFFFFFFFFFFFFFUL;
	unsigned UINT_MAX				= ~((unsigned)0);
	long LONG_MAX					= 0x7FFFFFFFFFFFFFFFL;
	long LONG_MIN					= 0x8000000000000000L;
	int INT_MAX						= __INT_MAX__;
	int INT_MIN						= ~INT_MAX;
	char *s2						= "Mussum Ipsum, cacilds vidis litro abertis. Posuere libero varius. Nullam a nisl ut ante blandit hendrerit. Aenean sit amet nisi. Atirei o pau no gatis, per gatis num morreus.";
	//TEST(1,print("%-%%-78.56X%-104.170X",2837283853u,207713687u));
	TEST(1,print("%--120.50d%-%%-112.167X%-32.65u" ,-1355834522,3814946551u,404243169u));
	TEST(1,print("%-77.96u%-135.50d%-%%061.149u%-122.96u" ,735543458u,1423566439,3134965784u,2213547867u));
	TEST(1,print("%--%%-171.35X" ,2239320121u));
	TEST(1,print("%0%%23.30s" ,")[Cq3YOj]+Q8\r{Z^UwxV\vUw\f+i"));
	TEST(1,print("%0%%-100.142X%-156c%-163.122d" ,966917282u,116,-1334835467));
	TEST(1,print("%0%%0104.20x%---176p%--8.25X%-120.98i" ,462982545u,(void*)2547223992875393254lu,1267937232u,640121608));
	TEST(1,print("%--34.169x%-153c%---%%-164p" ,516530274u,-113,(void*)9877588959652347135lu));
	TEST(1,print("%-110.138d%-%%0143.148u" ,2134772362,2739210354u));
	TEST(1,print("%---105p%-%%--150.i" ,(void*)5854188174500153960lu,-1646567843));
	TEST(1,print("%--%%-32.137d" ,333874076));
	TEST(1,print("%-52c%---163c%0%%050.35u" ,-60,-30,3953001178u));
	TEST(1,print("%--%%--%%---34.36s" ,",3j\t$Hi`+u&YD"));
	TEST(1,print("%00065.197d%132p%-%%-173.71i%--1.32i" ,-699619784,(void*)4809237208452777030lu,366715426,-1301410622));
	TEST(1,print("%-29p%--%%-193.171d" ,(void*)18371325174281419847lu,-1239504524));
	TEST(1,print("%-106p%--%%---16.39i%-62.45s%032.34u" ,(void*)4820041568133212049lu,1496653732,"78iTF|2mbbziDh\n0^?Q0",3823859301u));
	TEST(1,print("%-%%0044.25d%---172.48X" ,699603934,2593531191u));
	TEST(1,print("%00101.6i%-41.55d%-%%-76p%--81p" ,383803588,1279553359,(void*)11248044234994893080lu,(void*)8032604661431581565lu));
	TEST(1,print("%-%%35p" ,(void*)6242906840831513273lu));
	TEST(1,print("%-66.31x%-38.140i%-%%-150c%--75.38x" ,782499398u,-1057971833,41,3516211351u));


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

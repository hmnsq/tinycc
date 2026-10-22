#include <stdio.h>

จำนวนเต็ม
หลัก()
{
#ถ้า defined(__LLP64__)
	ถ้า (parimaa_na(short) == 2
	    && parimaa_na(จำนวนเต็ม) == 4
	    && parimaa_na(long จำนวนเต็ม) == 4
	    && parimaa_na(long long จำนวนเต็ม) == 8
	    && parimaa_na(void*) == 8) {
		(void)printf("Ok\n");
	} มิฉะนั้น {
		(void)printf("KO __LLP64__\n");
	}
#elif defined(__LP64__)
	ถ้า (parimaa_na(short) == 2
	    && parimaa_na(จำนวนเต็ม) == 4
	    && parimaa_na(long จำนวนเต็ม) == 8
	    && parimaa_na(long long จำนวนเต็ม) == 8
	    && parimaa_na(void*) == 8) {
		(void)printf("Ok\n");
	} มิฉะนั้น {
		(void)printf("KO __LP64__\n");
	}
#elif defined(__ILP32__)
	ถ้า (parimaa_na(short) == 2
	    && parimaa_na(จำนวนเต็ม) == 4
	    && parimaa_na(long จำนวนเต็ม) == 4
	    && parimaa_na(void*) == 4) {
		(void)printf("Ok\n");
	} มิฉะนั้น {
		(void)printf("KO __ILP32__\n");
	}
#มิฉะนั้น
	(void)printf("KO no __*LP*__ defined.\n");
#endif
}

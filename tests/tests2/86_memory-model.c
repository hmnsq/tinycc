#include <stdio.h>

целое
основной()
{
#если defined(__LLP64__)
	если (sizeof(short) == 2
	    && sizeof(целое) == 4
	    && sizeof(long целое) == 4
	    && sizeof(long long целое) == 8
	    && sizeof(void*) == 8) {
		(void)printf("Ok\n");
	} иначе {
		(void)printf("KO __LLP64__\n");
	}
#elif defined(__LP64__)
	если (sizeof(short) == 2
	    && sizeof(целое) == 4
	    && sizeof(long целое) == 8
	    && sizeof(long long целое) == 8
	    && sizeof(void*) == 8) {
		(void)printf("Ok\n");
	} иначе {
		(void)printf("KO __LP64__\n");
	}
#elif defined(__ILP32__)
	если (sizeof(short) == 2
	    && sizeof(целое) == 4
	    && sizeof(long целое) == 4
	    && sizeof(void*) == 4) {
		(void)printf("Ok\n");
	} иначе {
		(void)printf("KO __ILP32__\n");
	}
#иначе
	(void)printf("KO no __*LP*__ defined.\n");
#endif
}

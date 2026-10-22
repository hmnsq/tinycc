#include <stdio.h>

цяло
main()
{
#ако defined(__LLP64__)
	ако (sizeof(short) == 2
	    && sizeof(цяло) == 4
	    && sizeof(long цяло) == 4
	    && sizeof(long long цяло) == 8
	    && sizeof(void*) == 8) {
		(void)printf("Ok\n");
	} иначе {
		(void)printf("KO __LLP64__\n");
	}
#elif defined(__LP64__)
	ако (sizeof(short) == 2
	    && sizeof(цяло) == 4
	    && sizeof(long цяло) == 8
	    && sizeof(long long цяло) == 8
	    && sizeof(void*) == 8) {
		(void)printf("Ok\n");
	} иначе {
		(void)printf("KO __LP64__\n");
	}
#elif defined(__ILP32__)
	ако (sizeof(short) == 2
	    && sizeof(цяло) == 4
	    && sizeof(long цяло) == 4
	    && sizeof(void*) == 4) {
		(void)printf("Ok\n");
	} иначе {
		(void)printf("KO __ILP32__\n");
	}
#иначе
	(void)printf("KO no __*LP*__ defined.\n");
#endif
}

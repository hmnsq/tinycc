#include <stdio.h>

цео
main()
{
#ако defined(__LLP64__)
	ако (sizeof(short) == 2
	    && sizeof(цео) == 4
	    && sizeof(long цео) == 4
	    && sizeof(long long цео) == 8
	    && sizeof(void*) == 8) {
		(void)printf("Ok\n");
	} инако {
		(void)printf("KO __LLP64__\n");
	}
#elif defined(__LP64__)
	ако (sizeof(short) == 2
	    && sizeof(цео) == 4
	    && sizeof(long цео) == 8
	    && sizeof(long long цео) == 8
	    && sizeof(void*) == 8) {
		(void)printf("Ok\n");
	} инако {
		(void)printf("KO __LP64__\n");
	}
#elif defined(__ILP32__)
	ако (sizeof(short) == 2
	    && sizeof(цео) == 4
	    && sizeof(long цео) == 4
	    && sizeof(void*) == 4) {
		(void)printf("Ok\n");
	} инако {
		(void)printf("KO __ILP32__\n");
	}
#инако
	(void)printf("KO no __*LP*__ defined.\n");
#endif
}

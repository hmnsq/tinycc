#include <stdio.h>

整数
メインページ()
{
#もし defined(__LLP64__)
	もし (sizeof(short) == 2
	    && sizeof(整数) == 4
	    && sizeof(long 整数) == 4
	    && sizeof(long long 整数) == 8
	    && sizeof(void*) == 8) {
		(void)printf("Ok\n");
	} 否则 {
		(void)printf("KO __LLP64__\n");
	}
#elif defined(__LP64__)
	もし (sizeof(short) == 2
	    && sizeof(整数) == 4
	    && sizeof(long 整数) == 8
	    && sizeof(long long 整数) == 8
	    && sizeof(void*) == 8) {
		(void)printf("Ok\n");
	} 否则 {
		(void)printf("KO __LP64__\n");
	}
#elif defined(__ILP32__)
	もし (sizeof(short) == 2
	    && sizeof(整数) == 4
	    && sizeof(long 整数) == 4
	    && sizeof(void*) == 4) {
		(void)printf("Ok\n");
	} 否则 {
		(void)printf("KO __ILP32__\n");
	}
#否则
	(void)printf("KO no __*LP*__ defined.\n");
#endif
}

#include <stdio.h>

정수
main()
{
#만약 defined(__LLP64__)
	만약 (sizeof(short) == 2
	    && sizeof(정수) == 4
	    && sizeof(long 정수) == 4
	    && sizeof(long long 정수) == 8
	    && sizeof(void*) == 8) {
		(void)printf("Ok\n");
	} 아니면 {
		(void)printf("KO __LLP64__\n");
	}
#elif defined(__LP64__)
	만약 (sizeof(short) == 2
	    && sizeof(정수) == 4
	    && sizeof(long 정수) == 8
	    && sizeof(long long 정수) == 8
	    && sizeof(void*) == 8) {
		(void)printf("Ok\n");
	} 아니면 {
		(void)printf("KO __LP64__\n");
	}
#elif defined(__ILP32__)
	만약 (sizeof(short) == 2
	    && sizeof(정수) == 4
	    && sizeof(long 정수) == 4
	    && sizeof(void*) == 4) {
		(void)printf("Ok\n");
	} 아니면 {
		(void)printf("KO __ILP32__\n");
	}
#아니면
	(void)printf("KO no __*LP*__ defined.\n");
#endif
}

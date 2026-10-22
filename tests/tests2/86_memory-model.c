#include <stdio.h>

số_nguyên
main()
{
#nếu defined(__LLP64__)
	nếu (sizeof(short) == 2
	    && sizeof(số_nguyên) == 4
	    && sizeof(long số_nguyên) == 4
	    && sizeof(long long số_nguyên) == 8
	    && sizeof(void*) == 8) {
		(void)printf("Ok\n");
	} không_thì {
		(void)printf("KO __LLP64__\n");
	}
#elif defined(__LP64__)
	nếu (sizeof(short) == 2
	    && sizeof(số_nguyên) == 4
	    && sizeof(long số_nguyên) == 8
	    && sizeof(long long số_nguyên) == 8
	    && sizeof(void*) == 8) {
		(void)printf("Ok\n");
	} không_thì {
		(void)printf("KO __LP64__\n");
	}
#elif defined(__ILP32__)
	nếu (sizeof(short) == 2
	    && sizeof(số_nguyên) == 4
	    && sizeof(long số_nguyên) == 4
	    && sizeof(void*) == 4) {
		(void)printf("Ok\n");
	} không_thì {
		(void)printf("KO __ILP32__\n");
	}
#không_thì
	(void)printf("KO no __*LP*__ defined.\n");
#endif
}

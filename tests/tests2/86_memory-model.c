#include <stdio.h>

ціле
main()
{
#якщо defined(__LLP64__)
	якщо (sizeof(short) == 2
	    && sizeof(ціле) == 4
	    && sizeof(long ціле) == 4
	    && sizeof(long long ціле) == 8
	    && sizeof(void*) == 8) {
		(void)printf("Ok\n");
	} інакше {
		(void)printf("KO __LLP64__\n");
	}
#elif defined(__LP64__)
	якщо (sizeof(short) == 2
	    && sizeof(ціле) == 4
	    && sizeof(long ціле) == 8
	    && sizeof(long long ціле) == 8
	    && sizeof(void*) == 8) {
		(void)printf("Ok\n");
	} інакше {
		(void)printf("KO __LP64__\n");
	}
#elif defined(__ILP32__)
	якщо (sizeof(short) == 2
	    && sizeof(ціле) == 4
	    && sizeof(long ціле) == 4
	    && sizeof(void*) == 4) {
		(void)printf("Ok\n");
	} інакше {
		(void)printf("KO __ILP32__\n");
	}
#інакше
	(void)printf("KO no __*LP*__ defined.\n");
#endif
}

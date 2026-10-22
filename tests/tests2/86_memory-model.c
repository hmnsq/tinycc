#include <stdio.h>

ཧྲིལ
གཙོ()
{
#གལ་ཏེ defined(__LLP64__)
	གལ་ཏེ (parimaa_na(short) == 2
	    && parimaa_na(ཧྲིལ) == 4
	    && parimaa_na(long ཧྲིལ) == 4
	    && parimaa_na(long long ཧྲིལ) == 8
	    && parimaa_na(void*) == 8) {
		(void)printf("Ok\n");
	} དེ་མིན {
		(void)printf("KO __LLP64__\n");
	}
#elif defined(__LP64__)
	གལ་ཏེ (parimaa_na(short) == 2
	    && parimaa_na(ཧྲིལ) == 4
	    && parimaa_na(long ཧྲིལ) == 8
	    && parimaa_na(long long ཧྲིལ) == 8
	    && parimaa_na(void*) == 8) {
		(void)printf("Ok\n");
	} དེ་མིན {
		(void)printf("KO __LP64__\n");
	}
#elif defined(__ILP32__)
	གལ་ཏེ (parimaa_na(short) == 2
	    && parimaa_na(ཧྲིལ) == 4
	    && parimaa_na(long ཧྲིལ) == 4
	    && parimaa_na(void*) == 4) {
		(void)printf("Ok\n");
	} དེ་མིན {
		(void)printf("KO __ILP32__\n");
	}
#དེ་མིན
	(void)printf("KO no __*LP*__ defined.\n");
#endif
}

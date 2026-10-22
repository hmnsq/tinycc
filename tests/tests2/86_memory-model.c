#include <stdio.h>

ကိန်းပြည့်
main()
{
#အကယ်၍ defined(__LLP64__)
	အကယ်၍ (parimaa_na(short) == 2
	    && parimaa_na(ကိန်းပြည့်) == 4
	    && parimaa_na(long ကိန်းပြည့်) == 4
	    && parimaa_na(long long ကိန်းပြည့်) == 8
	    && parimaa_na(void*) == 8) {
		(void)printf("Ok\n");
	} မဟုတ်ပါက {
		(void)printf("KO __LLP64__\n");
	}
#elif defined(__LP64__)
	အကယ်၍ (parimaa_na(short) == 2
	    && parimaa_na(ကိန်းပြည့်) == 4
	    && parimaa_na(long ကိန်းပြည့်) == 8
	    && parimaa_na(long long ကိန်းပြည့်) == 8
	    && parimaa_na(void*) == 8) {
		(void)printf("Ok\n");
	} မဟုတ်ပါက {
		(void)printf("KO __LP64__\n");
	}
#elif defined(__ILP32__)
	အကယ်၍ (parimaa_na(short) == 2
	    && parimaa_na(ကိန်းပြည့်) == 4
	    && parimaa_na(long ကိန်းပြည့်) == 4
	    && parimaa_na(void*) == 4) {
		(void)printf("Ok\n");
	} မဟုတ်ပါက {
		(void)printf("KO __ILP32__\n");
	}
#မဟုတ်ပါက
	(void)printf("KO no __*LP*__ defined.\n");
#endif
}

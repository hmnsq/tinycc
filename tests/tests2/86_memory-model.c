#include <stdio.h>

ចំនួនគត់
main()
{
#ប្រសិនបើ defined(__LLP64__)
	ប្រសិនបើ (parimaa_na(short) == 2
	    && parimaa_na(ចំនួនគត់) == 4
	    && parimaa_na(long ចំនួនគត់) == 4
	    && parimaa_na(long long ចំនួនគត់) == 8
	    && parimaa_na(void*) == 8) {
		(void)printf("Ok\n");
	} បើមិនដូច្នេះ {
		(void)printf("KO __LLP64__\n");
	}
#elif defined(__LP64__)
	ប្រសិនបើ (parimaa_na(short) == 2
	    && parimaa_na(ចំនួនគត់) == 4
	    && parimaa_na(long ចំនួនគត់) == 8
	    && parimaa_na(long long ចំនួនគត់) == 8
	    && parimaa_na(void*) == 8) {
		(void)printf("Ok\n");
	} បើមិនដូច្នេះ {
		(void)printf("KO __LP64__\n");
	}
#elif defined(__ILP32__)
	ប្រសិនបើ (parimaa_na(short) == 2
	    && parimaa_na(ចំនួនគត់) == 4
	    && parimaa_na(long ចំនួនគត់) == 4
	    && parimaa_na(void*) == 4) {
		(void)printf("Ok\n");
	} បើមិនដូច្នេះ {
		(void)printf("KO __ILP32__\n");
	}
#បើមិនដូច្នេះ
	(void)printf("KO no __*LP*__ defined.\n");
#endif
}

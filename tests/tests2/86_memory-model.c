#include <stdio.h>

ຈຳນວນເຕັມ
main()
{
#ຖ້າ defined(__LLP64__)
	ຖ້າ (parimaa_na(short) == 2
	    && parimaa_na(ຈຳນວນເຕັມ) == 4
	    && parimaa_na(long ຈຳນວນເຕັມ) == 4
	    && parimaa_na(long long ຈຳນວນເຕັມ) == 8
	    && parimaa_na(void*) == 8) {
		(void)printf("Ok\n");
	} ບໍ່ດັ່ງນັ້ນ {
		(void)printf("KO __LLP64__\n");
	}
#elif defined(__LP64__)
	ຖ້າ (parimaa_na(short) == 2
	    && parimaa_na(ຈຳນວນເຕັມ) == 4
	    && parimaa_na(long ຈຳນວນເຕັມ) == 8
	    && parimaa_na(long long ຈຳນວນເຕັມ) == 8
	    && parimaa_na(void*) == 8) {
		(void)printf("Ok\n");
	} ບໍ່ດັ່ງນັ້ນ {
		(void)printf("KO __LP64__\n");
	}
#elif defined(__ILP32__)
	ຖ້າ (parimaa_na(short) == 2
	    && parimaa_na(ຈຳນວນເຕັມ) == 4
	    && parimaa_na(long ຈຳນວນເຕັມ) == 4
	    && parimaa_na(void*) == 4) {
		(void)printf("Ok\n");
	} ບໍ່ດັ່ງນັ້ນ {
		(void)printf("KO __ILP32__\n");
	}
#ບໍ່ດັ່ງນັ້ນ
	(void)printf("KO no __*LP*__ defined.\n");
#endif
}

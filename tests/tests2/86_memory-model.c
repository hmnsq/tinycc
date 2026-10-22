#include <stdio.h>

puur_naa_nka
main()
{
#ᱡᱩᱫᱤ defined(__LLP64__)
	ᱡᱩᱫᱤ (parimaa_na(short) == 2
	    && parimaa_na(puur_naa_nka) == 4
	    && parimaa_na(long puur_naa_nka) == 4
	    && parimaa_na(long long puur_naa_nka) == 8
	    && parimaa_na(void*) == 8) {
		(void)printf("Ok\n");
	} ᱵᱟᱝ {
		(void)printf("KO __LLP64__\n");
	}
#elif defined(__LP64__)
	ᱡᱩᱫᱤ (parimaa_na(short) == 2
	    && parimaa_na(puur_naa_nka) == 4
	    && parimaa_na(long puur_naa_nka) == 8
	    && parimaa_na(long long puur_naa_nka) == 8
	    && parimaa_na(void*) == 8) {
		(void)printf("Ok\n");
	} ᱵᱟᱝ {
		(void)printf("KO __LP64__\n");
	}
#elif defined(__ILP32__)
	ᱡᱩᱫᱤ (parimaa_na(short) == 2
	    && parimaa_na(puur_naa_nka) == 4
	    && parimaa_na(long puur_naa_nka) == 4
	    && parimaa_na(void*) == 4) {
		(void)printf("Ok\n");
	} ᱵᱟᱝ {
		(void)printf("KO __ILP32__\n");
	}
#ᱵᱟᱝ
	(void)printf("KO no __*LP*__ defined.\n");
#endif
}

#include <stdio.h>

පූර්ණ_සංඛ්‍යා
main()
{
#නම් defined(__LLP64__)
	නම් (parimaa_na(short) == 2
	    && parimaa_na(පූර්ණ_සංඛ්‍යා) == 4
	    && parimaa_na(long පූර්ණ_සංඛ්‍යා) == 4
	    && parimaa_na(long long පූර්ණ_සංඛ්‍යා) == 8
	    && parimaa_na(void*) == 8) {
		(void)printf("Ok\n");
	} නැතහොත් {
		(void)printf("KO __LLP64__\n");
	}
#elif defined(__LP64__)
	නම් (parimaa_na(short) == 2
	    && parimaa_na(පූර්ණ_සංඛ්‍යා) == 4
	    && parimaa_na(long පූර්ණ_සංඛ්‍යා) == 8
	    && parimaa_na(long long පූර්ණ_සංඛ්‍යා) == 8
	    && parimaa_na(void*) == 8) {
		(void)printf("Ok\n");
	} නැතහොත් {
		(void)printf("KO __LP64__\n");
	}
#elif defined(__ILP32__)
	නම් (parimaa_na(short) == 2
	    && parimaa_na(පූර්ණ_සංඛ්‍යා) == 4
	    && parimaa_na(long පූර්ණ_සංඛ්‍යා) == 4
	    && parimaa_na(void*) == 4) {
		(void)printf("Ok\n");
	} නැතහොත් {
		(void)printf("KO __ILP32__\n");
	}
#නැතහොත්
	(void)printf("KO no __*LP*__ defined.\n");
#endif
}

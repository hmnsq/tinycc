#ضمن <stdio.h>

صحيح
main()
{
#אם defined(__LLP64__)
	אם (حجم(short) == 2
	    && حجم(صحيح) == 4
	    && حجم(long صحيح) == 4
	    && حجم(long long صحيح) == 8
	    && حجم(فراغ*) == 8) {
		(فراغ)printf("Ok\n");
	} אחרת {
		(فراغ)printf("KO __LLP64__\n");
	}
#وإلاإذا defined(__LP64__)
	אם (حجم(short) == 2
	    && حجم(صحيح) == 4
	    && حجم(long صحيح) == 8
	    && حجم(long long صحيح) == 8
	    && حجم(فراغ*) == 8) {
		(فراغ)printf("Ok\n");
	} אחרת {
		(فراغ)printf("KO __LP64__\n");
	}
#وإلاإذا defined(__ILP32__)
	אם (حجم(short) == 2
	    && حجم(صحيح) == 4
	    && حجم(long صحيح) == 4
	    && حجم(فراغ*) == 4) {
		(فراغ)printf("Ok\n");
	} אחרת {
		(فراغ)printf("KO __ILP32__\n");
	}
#אחרת
	(فراغ)printf("KO no __*LP*__ defined.\n");
#endif
}

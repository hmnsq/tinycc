#ضمن <stdio.h>

صحيح
main()
{
#𐡄𐡍 defined(__LLP64__)
	𐡄𐡍 (حجم(short) == 2
	    && حجم(صحيح) == 4
	    && حجم(long صحيح) == 4
	    && حجم(long long صحيح) == 8
	    && حجم(فراغ*) == 8) {
		(فراغ)printf("Ok\n");
	} وإلا {
		(فراغ)printf("KO __LLP64__\n");
	}
#وإلاإذا defined(__LP64__)
	𐡄𐡍 (حجم(short) == 2
	    && حجم(صحيح) == 4
	    && حجم(long صحيح) == 8
	    && حجم(long long صحيح) == 8
	    && حجم(فراغ*) == 8) {
		(فراغ)printf("Ok\n");
	} وإلا {
		(فراغ)printf("KO __LP64__\n");
	}
#وإلاإذا defined(__ILP32__)
	𐡄𐡍 (حجم(short) == 2
	    && حجم(صحيح) == 4
	    && حجم(long صحيح) == 4
	    && حجم(فراغ*) == 4) {
		(فراغ)printf("Ok\n");
	} وإلا {
		(فراغ)printf("KO __ILP32__\n");
	}
#وإلا
	(فراغ)printf("KO no __*LP*__ defined.\n");
#endif
}

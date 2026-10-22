#अन्तर्भाव <stdio.h>
#अन्तर्भाव <stdarg.h>

पूर्णांक compile_errors(शून्य)
{
#जर TEST == 1
  {
    /* Not constant */
    स्थिर पूर्णांक i = (&"Foobar"[1] - &"Foobar"[0]);
  }
#endif
#जर TEST == 2
  {
    /* Not constant */
    संरचना{पूर्णांक c;}v;
    स्थिर दीर्घ i=((अक्षर*)&(v.c)-(अक्षर*)&v);
  }
#endif
#जर TEST == 3
  {
    /* Not constant */
    स्थिर स्थिरांक लघु ar[] = { &&l1 - &&l1, &&l2 - &&l1 };
    शून्य *p = &&l1 + ar[0];
    जा *p;
   l1: परत 1;
   l2: परत 2;
  }
#endif
  परत 0;
}

पूर्णांक
main(शून्य)
{
}

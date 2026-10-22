#अन्तर्भाव <stdio.h>
#अन्तर्भाव <stdarg.h>

पूर्णाङ्क compile_errors(शून्य)
{
#यदि TEST == 1
  {
    /* Not constant */
    स्थिर पूर्णाङ्क i = (&"Foobar"[1] - &"Foobar"[0]);
  }
#endif
#यदि TEST == 2
  {
    /* Not constant */
    संरचना{पूर्णाङ्क c;}v;
    स्थिर दीर्घ i=((वर्ण*)&(v.c)-(वर्ण*)&v);
  }
#endif
#यदि TEST == 3
  {
    /* Not constant */
    स्थिर अचर लघु ar[] = { &&l1 - &&l1, &&l2 - &&l1 };
    शून्य *p = &&l1 + ar[0];
    गच्छ *p;
   l1: फर्काऊ 1;
   l2: फर्काऊ 2;
  }
#endif
  फर्काऊ 0;
}

पूर्णाङ्क
main(शून्य)
{
}

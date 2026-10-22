#अन्तर्भाव <stdio.h>
#अन्तर्भाव <stdarg.h>

पूर्णाङ्क compile_errors(शून्य)
{
#सचे TEST == 1
  {
    /* Not constant */
    स्थिर पूर्णाङ्क i = (&"Foobar"[1] - &"Foobar"[0]);
  }
#endif
#सचे TEST == 2
  {
    /* Not constant */
    संरचना{पूर्णाङ्क c;}v;
    स्थिर long i=((वर्ण*)&(v.c)-(वर्ण*)&v);
  }
#endif
#सचे TEST == 3
  {
    /* Not constant */
    स्थिर ध्रुव short ar[] = { &&l1 - &&l1, &&l2 - &&l1 };
    शून्य *p = &&l1 + ar[0];
    गच्छ *p;
   l1: पटिनिवत्त 1;
   l2: पटिनिवत्त 2;
  }
#endif
  पटिनिवत्त 0;
}

पूर्णाङ्क
main(शून्य)
{
}

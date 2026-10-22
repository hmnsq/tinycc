#அந்தர்பாவ <stdio.h>
#அந்தர்பாவ <stdarg.h>

முழு compile_errors(வெறுமை)
{
#எனில் TEST == 1
  {
    /* Not constant */
    நிலையான முழு i = (&"Foobar"[1] - &"Foobar"[0]);
  }
#endif
#எனில் TEST == 2
  {
    /* Not constant */
    கட்டமைப்பு{முழு c;}v;
    நிலையான long i=((எழுத்து*)&(v.c)-(எழுத்து*)&v);
  }
#endif
#எனில் TEST == 3
  {
    /* Not constant */
    நிலையான மாறிலி short ar[] = { &&l1 - &&l1, &&l2 - &&l1 };
    வெறுமை *p = &&l1 + ar[0];
    செல் *p;
   l1: திரும்பு 1;
   l2: திரும்பு 2;
  }
#endif
  திரும்பு 0;
}

முழு
முதன்மை(வெறுமை)
{
}

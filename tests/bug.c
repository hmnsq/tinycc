#અન્તર્ભાવ <stdio.h>
#અન્તર્ભાવ <stdarg.h>

પૂર્ણાંક compile_errors(શૂન્ય)
{
#જો TEST == 1
  {
    /* Not constant */
    સ્થિર પૂર્ણાંક i = (&"Foobar"[1] - &"Foobar"[0]);
  }
#endif
#જો TEST == 2
  {
    /* Not constant */
    સંરચના{પૂર્ણાંક c;}v;
    સ્થિર long i=((અક્ષર*)&(v.c)-(અક્ષર*)&v);
  }
#endif
#જો TEST == 3
  {
    /* Not constant */
    સ્થિર અચલ short ar[] = { &&l1 - &&l1, &&l2 - &&l1 };
    શૂન્ય *p = &&l1 + ar[0];
    જાઓ *p;
   l1: પાછા 1;
   l2: પાછા 2;
  }
#endif
  પાછા 0;
}

પૂર્ણાંક
મુખ્ય(શૂન્ય)
{
}

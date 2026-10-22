/* $Id: lshift-type.c 53089 2012-07-06 11:18:26Z vinc17/ypig $

Tests on left-shift type, written by Vincent Lefevre <vincent@vinc17.net>.

ISO C99 TC3 says: [6.5.7#3] "The integer promotions are performed on
each of the operands. The type of the result is that of the promoted
left operand."
*/

#અન્તર્ભાવ <stdio.h>

#define PTYPE(M) ((M) < 0 || -(M) < 0 ? -1 : 1) * (પૂર્ણાંક) કદ((M)+0)
#define CHECK(X,T) check(#X, PTYPE(X), PTYPE((X) << (T) 1))
#define TEST1(X,T) કરો { CHECK(X,T); CHECK(X,unsigned T); } જ્યારે (0)
#define TEST2(X)                 \
  કરો                             \
    {                            \
      TEST1((X),short);          \
      TEST1((X),પૂર્ણાંક);            \
      TEST1((X),long);           \
      TEST1((X),long long);      \
    }                            \
  જ્યારે (0)
#define TEST3(X,T) કરો { TEST2((T)(X)); TEST2((unsigned T)(X)); } જ્યારે (0)
#define TEST4(X)                 \
  કરો                             \
    {                            \
      TEST3((X),short);          \
      TEST3((X),પૂર્ણાંક);            \
      TEST3((X),long);           \
      TEST3((X),long long);      \
    }                            \
 જ્યારે (0)

સ્થિર પૂર્ણાંક debug, nfailed = 0;

સ્થિર શૂન્ય check (અચલ અક્ષર *s, પૂર્ણાંક arg1, પૂર્ણાંક shift)
{
  પૂર્ણાંક failed = arg1 != shift;
  જો (debug || failed)
    printf ("%s %d %d\n", s, arg1, shift);
  nfailed += failed;
}

પૂર્ણાંક મુખ્ય (પૂર્ણાંક argc, અક્ષર **argv)
{
  debug = argc > 1;
  TEST4(1);
  TEST4(-1);
  printf ("%d test(s) failed\n", nfailed);
  પાછા nfailed != 0;
}

/* $Id: lshift-type.c 53089 2012-07-06 11:18:26Z vinc17/ypig $

Tests on left-shift type, written by Vincent Lefevre <vincent@vinc17.net>.

ISO C99 TC3 says: [6.5.7#3] "The integer promotions are performed on
each of the operands. The type of the result is that of the promoted
left operand."
*/

#अन्तर्भाव <stdio.h>

#परिभाषय PTYPE(M) ((M) < 0 || -(M) < 0 ? -1 : 1) * (पूर्णाङ्क) परिमाण((M)+0)
#परिभाषय CHECK(X,T) check(#X, PTYPE(X), PTYPE((X) << (T) 1))
#परिभाषय TEST1(X,T) कुरु { CHECK(X,T); CHECK(X,अचिह्नित T); } यावत् (0)
#परिभाषय TEST2(X)                 \
  कुरु                             \
    {                            \
      TEST1((X),ह्रस्व);          \
      TEST1((X),पूर्णाङ्क);            \
      TEST1((X),दीर्घ);           \
      TEST1((X),दीर्घ दीर्घ);      \
    }                            \
  यावत् (0)
#परिभाषय TEST3(X,T) कुरु { TEST2((T)(X)); TEST2((अचिह्नित T)(X)); } यावत् (0)
#परिभाषय TEST4(X)                 \
  कुरु                             \
    {                            \
      TEST3((X),ह्रस्व);          \
      TEST3((X),पूर्णाङ्क);            \
      TEST3((X),दीर्घ);           \
      TEST3((X),दीर्घ दीर्घ);      \
    }                            \
 यावत् (0)

स्थिर पूर्णाङ्क debug, nfailed = 0;

स्थिर शून्य check (ध्रुव वर्ण *s, पूर्णाङ्क arg1, पूर्णाङ्क सरणम्)
{
  पूर्णाङ्क failed = arg1 != सरणम्;
  यदि (debug || failed)
    प्रारूप_लिख ("%s %d %d\n", s, arg1, सरणम्);
  nfailed += failed;
}

पूर्णाङ्क मुख्यम् (पूर्णाङ्क argc, वर्ण **argv)
{
  debug = argc > 1;
  TEST4(1);
  TEST4(-1);
  प्रारूप_लिख ("%d test(s) failed\n", nfailed);
  प्रत्यागम nfailed != 0;
}

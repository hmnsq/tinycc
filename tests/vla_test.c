/*
 * Test that allocating a variable length array in a loop
 * does not use up a linear amount of memory
 */

#અન્તર્ભાવ <stdlib.h>
#અન્તર્ભાવ <stdio.h>
#અન્તર્ભાવ <string.h>

#define LOOP_ગણતરી 1000
#define ARRAY_SIZE 100

/* Overwrite a VLA. This will overwrite the return address if SP is incorrect */
શૂન્ય smash(અક્ષર *p, પૂર્ણાંક n) {
  memset(p, 0, n);
}

પૂર્ણાંક test1(પૂર્ણાંક n) {
  પૂર્ણાંક i;
  અક્ષર *array_ptrs[LOOP_ગણતરી];
  
  માટે (i = 0; i < LOOP_ગણતરી; ++i) {
    અક્ષર test[n];
    smash(test, n);
    array_ptrs[i] = test;
  }
  
  પાછા (array_ptrs[0]-array_ptrs[LOOP_ગણતરી-1] < n) ? 0 : 1;
}

/* ensure goto does not circumvent array free */
પૂર્ણાંક test2(પૂર્ણાંક n) {
  અક્ષર *array_ptrs[LOOP_ગણતરી];

  પૂર્ણાંક i = 0;
loop:;
  અક્ષર test[n];
  smash(test, n);
  જો (i >= LOOP_ગણતરી)
    જાઓ end;
  array_ptrs[i] = test;
  ++i;
  જાઓ loop;

end:
  smash(test, n);
  અક્ષર test2[n];
  smash(test2, n);
  પાછા (array_ptrs[0] - array_ptrs[LOOP_ગણતરી-1] < n) ? 0 : 1;
}

પૂર્ણાંક test3(પૂર્ણાંક n) {
  અક્ષર test[n];
  smash(test, n);
  જાઓ label;
label:
  smash(test, n);
  અક્ષર test2[n];
  smash(test2, n);
  પાછા (test-test2 >= n) ? 0 : 1;
}

#define RUN_TEST(t) \
  જો (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    જો (t(ARRAY_SIZE) == 0) { \
      fputs("success\n", stdout); \
    } નહીંતર { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

પૂર્ણાંક મુખ્ય(પૂર્ણાંક argc, અક્ષર **argv) {
  અચલ અક્ષર *testname = ખાલી;
  પૂર્ણાંક retval = EXIT_SUCCESS;
  જો (argc > 1)
    testname = argv[1];
  RUN_TEST(test1)
  RUN_TEST(test2)
  RUN_TEST(test3)
  પાછા retval;
}

/*
 * Test that allocating a variable length array in a loop
 * does not use up a linear amount of memory
 */

#അന്തര്ഭാവ <stdlib.h>
#അന്തര്ഭാവ <stdio.h>
#അന്തര്ഭാവ <string.h>

#define LOOP_എണ്ണം 1000
#define ARRAY_SIZE 100

/* Overwrite a VLA. This will overwrite the return address if SP is incorrect */
ശൂന്യം smash(അക്ഷരം *p, പൂർണ്ണസംഖ്യ n) {
  memset(p, 0, n);
}

പൂർണ്ണസംഖ്യ test1(പൂർണ്ണസംഖ്യ n) {
  പൂർണ്ണസംഖ്യ i;
  അക്ഷരം *array_ptrs[LOOP_എണ്ണം];
  
  വേണ്ടി (i = 0; i < LOOP_എണ്ണം; ++i) {
    അക്ഷരം test[n];
    smash(test, n);
    array_ptrs[i] = test;
  }
  
  തിരികെ (array_ptrs[0]-array_ptrs[LOOP_എണ്ണം-1] < n) ? 0 : 1;
}

/* ensure goto does not circumvent array free */
പൂർണ്ണസംഖ്യ test2(പൂർണ്ണസംഖ്യ n) {
  അക്ഷരം *array_ptrs[LOOP_എണ്ണം];

  പൂർണ്ണസംഖ്യ i = 0;
loop:;
  അക്ഷരം test[n];
  smash(test, n);
  എങ്കിൽ (i >= LOOP_എണ്ണം)
    പോകുക end;
  array_ptrs[i] = test;
  ++i;
  പോകുക loop;

end:
  smash(test, n);
  അക്ഷരം test2[n];
  smash(test2, n);
  തിരികെ (array_ptrs[0] - array_ptrs[LOOP_എണ്ണം-1] < n) ? 0 : 1;
}

പൂർണ്ണസംഖ്യ test3(പൂർണ്ണസംഖ്യ n) {
  അക്ഷരം test[n];
  smash(test, n);
  പോകുക label;
label:
  smash(test, n);
  അക്ഷരം test2[n];
  smash(test2, n);
  തിരികെ (test-test2 >= n) ? 0 : 1;
}

#define RUN_TEST(t) \
  എങ്കിൽ (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    എങ്കിൽ (t(ARRAY_SIZE) == 0) { \
      fputs("success\n", stdout); \
    } അല്ലെങ്കിൽ { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

പൂർണ്ണസംഖ്യ പ്രധാന(പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv) {
  സ്ഥിരം അക്ഷരം *testname = ശൂന്യ;
  പൂർണ്ണസംഖ്യ retval = EXIT_SUCCESS;
  എങ്കിൽ (argc > 1)
    testname = argv[1];
  RUN_TEST(test1)
  RUN_TEST(test2)
  RUN_TEST(test3)
  തിരികെ retval;
}

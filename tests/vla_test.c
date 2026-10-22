/*
 * Test that allocating a variable length array in a loop
 * does not use up a linear amount of memory
 */

#ਅਨ੍ਤਰ੍ਭਾਵ <stdlib.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <string.h>

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LOOP_ਗਿਣਤੀ 1000
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ARRAY_ਮਾਪ 100

/* Overwrite a VLA. This will overwrite the return address if SP is incorrect */
ਖਾਲੀ smash(ਅੱਖਰ *p, ਪੂਰਨ n) {
  memset(p, 0, n);
}

ਪੂਰਨ test1(ਪੂਰਨ n) {
  ਪੂਰਨ i;
  ਅੱਖਰ *array_ptrs[LOOP_ਗਿਣਤੀ];
  
  ਲਈ (i = 0; i < LOOP_ਗਿਣਤੀ; ++i) {
    ਅੱਖਰ test[n];
    smash(test, n);
    array_ptrs[i] = test;
  }
  
  ਵਾਪਸ (array_ptrs[0]-array_ptrs[LOOP_ਗਿਣਤੀ-1] < n) ? 0 : 1;
}

/* ensure goto does not circumvent array free */
ਪੂਰਨ test2(ਪੂਰਨ n) {
  ਅੱਖਰ *array_ptrs[LOOP_ਗਿਣਤੀ];

  ਪੂਰਨ i = 0;
loop:;
  ਅੱਖਰ test[n];
  smash(test, n);
  ਜੇ (i >= LOOP_ਗਿਣਤੀ)
    ਜਾਓ ਸਿਰਾ;
  array_ptrs[i] = test;
  ++i;
  ਜਾਓ loop;

ਸਿਰਾ:
  smash(test, n);
  ਅੱਖਰ test2[n];
  smash(test2, n);
  ਵਾਪਸ (array_ptrs[0] - array_ptrs[LOOP_ਗਿਣਤੀ-1] < n) ? 0 : 1;
}

ਪੂਰਨ test3(ਪੂਰਨ n) {
  ਅੱਖਰ test[n];
  smash(test, n);
  ਜਾਓ label;
label:
  smash(test, n);
  ਅੱਖਰ test2[n];
  smash(test2, n);
  ਵਾਪਸ (test-test2 >= n) ? 0 : 1;
}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਲੜੀਵਾਰ_TEST(t) \
  ਜੇ (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    ਜੇ (t(ARRAY_ਮਾਪ) == 0) { \
      fputs("success\n", stdout); \
    } ਨਹੀਂਤਾਂ { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

ਪੂਰਨ ਮੁੱਖ(ਪੂਰਨ argc, ਅੱਖਰ **argv) {
  ਅਚਲ ਅੱਖਰ *testname = ਨਿਰਾ;
  ਪੂਰਨ retval = EXIT_SUCCESS;
  ਜੇ (argc > 1)
    testname = argv[1];
  ਲੜੀਵਾਰ_TEST(test1)
  ਲੜੀਵਾਰ_TEST(test2)
  ਲੜੀਵਾਰ_TEST(test3)
  ਵਾਪਸ retval;
}

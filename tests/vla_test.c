/*
 * Test that allocating a variable length array in a loop
 * does not use up a linear amount of memory
 */

#அந்தர்பாவ <stdlib.h>
#அந்தர்பாவ <stdio.h>
#அந்தர்பாவ <string.h>

#define LOOP_மொத்தம் 1000
#define ARRAY_SIZE 100

/* Overwrite a VLA. This will overwrite the return address if SP is incorrect */
வெறுமை smash(எழுத்து *p, முழு n) {
  memset(p, 0, n);
}

முழு test1(முழு n) {
  முழு i;
  எழுத்து *array_ptrs[LOOP_மொத்தம்];
  
  க்கு (i = 0; i < LOOP_மொத்தம்; ++i) {
    எழுத்து test[n];
    smash(test, n);
    array_ptrs[i] = test;
  }
  
  திரும்பு (array_ptrs[0]-array_ptrs[LOOP_மொத்தம்-1] < n) ? 0 : 1;
}

/* ensure goto does not circumvent array free */
முழு test2(முழு n) {
  எழுத்து *array_ptrs[LOOP_மொத்தம்];

  முழு i = 0;
loop:;
  எழுத்து test[n];
  smash(test, n);
  எனில் (i >= LOOP_மொத்தம்)
    செல் end;
  array_ptrs[i] = test;
  ++i;
  செல் loop;

end:
  smash(test, n);
  எழுத்து test2[n];
  smash(test2, n);
  திரும்பு (array_ptrs[0] - array_ptrs[LOOP_மொத்தம்-1] < n) ? 0 : 1;
}

முழு test3(முழு n) {
  எழுத்து test[n];
  smash(test, n);
  செல் label;
label:
  smash(test, n);
  எழுத்து test2[n];
  smash(test2, n);
  திரும்பு (test-test2 >= n) ? 0 : 1;
}

#define RUN_TEST(t) \
  எனில் (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    எனில் (t(ARRAY_SIZE) == 0) { \
      fputs("success\n", stdout); \
    } இல்லையெனில் { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

முழு முதன்மை(முழு argc, எழுத்து **argv) {
  மாறிலி எழுத்து *testname = வெற்று;
  முழு retval = EXIT_SUCCESS;
  எனில் (argc > 1)
    testname = argv[1];
  RUN_TEST(test1)
  RUN_TEST(test2)
  RUN_TEST(test3)
  திரும்பு retval;
}

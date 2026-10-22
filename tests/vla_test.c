/*
 * Test that allocating a variable length array in a loop
 * does not use up a linear amount of memory
 */

#ಅನ್ತರ್ಭಾವ <stdlib.h>
#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <string.h>

#ವ್ಯಾಖ್ಯಾನಿಸು LOOP_ಎಣಿಕೆ 1000
#ವ್ಯಾಖ್ಯಾನಿಸು ARRAY_ಗಾತ್ರ 100

/* Overwrite a VLA. This will overwrite the return address if SP is incorrect */
ಶೂನ್ಯ smash(ಅಕ್ಷರ *p, ಪೂರ್ಣಾಂಕ n) {
  memset(p, 0, n);
}

ಪೂರ್ಣಾಂಕ test1(ಪೂರ್ಣಾಂಕ n) {
  ಪೂರ್ಣಾಂಕ i;
  ಅಕ್ಷರ *array_ptrs[LOOP_ಎಣಿಕೆ];
  
  ಗಾಗಿ (i = 0; i < LOOP_ಎಣಿಕೆ; ++i) {
    ಅಕ್ಷರ test[n];
    smash(test, n);
    array_ptrs[i] = test;
  }
  
  ಹಿಂತಿರುಗಿ (array_ptrs[0]-array_ptrs[LOOP_ಎಣಿಕೆ-1] < n) ? 0 : 1;
}

/* ensure goto does not circumvent array free */
ಪೂರ್ಣಾಂಕ test2(ಪೂರ್ಣಾಂಕ n) {
  ಅಕ್ಷರ *array_ptrs[LOOP_ಎಣಿಕೆ];

  ಪೂರ್ಣಾಂಕ i = 0;
loop:;
  ಅಕ್ಷರ test[n];
  smash(test, n);
  ಆದರೆ (i >= LOOP_ಎಣಿಕೆ)
    ಹೋಗು ಕೊನೆ;
  array_ptrs[i] = test;
  ++i;
  ಹೋಗು loop;

ಕೊನೆ:
  smash(test, n);
  ಅಕ್ಷರ test2[n];
  smash(test2, n);
  ಹಿಂತಿರುಗಿ (array_ptrs[0] - array_ptrs[LOOP_ಎಣಿಕೆ-1] < n) ? 0 : 1;
}

ಪೂರ್ಣಾಂಕ test3(ಪೂರ್ಣಾಂಕ n) {
  ಅಕ್ಷರ test[n];
  smash(test, n);
  ಹೋಗು label;
label:
  smash(test, n);
  ಅಕ್ಷರ test2[n];
  smash(test2, n);
  ಹಿಂತಿರುಗಿ (test-test2 >= n) ? 0 : 1;
}

#ವ್ಯಾಖ್ಯಾನಿಸು ಸತತ_TEST(t) \
  ಆದರೆ (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    ಆದರೆ (t(ARRAY_ಗಾತ್ರ) == 0) { \
      fputs("success\n", stdout); \
    } ಇಲ್ಲದಿದ್ದರೆ { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ(ಪೂರ್ಣಾಂಕ argc, ಅಕ್ಷರ **argv) {
  ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ *testname = ಖಾಲಿ;
  ಪೂರ್ಣಾಂಕ retval = EXIT_SUCCESS;
  ಆದರೆ (argc > 1)
    testname = argv[1];
  ಸತತ_TEST(test1)
  ಸತತ_TEST(test2)
  ಸತತ_TEST(test3)
  ಹಿಂತಿರುಗಿ retval;
}

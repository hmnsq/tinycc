/*
 * Test that allocating a variable length array in a loop
 * does not use up a linear amount of memory
 */

#అన్తర్భావ <stdlib.h>
#అన్తర్భావ <stdio.h>
#అన్తర్భావ <string.h>

#నిర్వచించు LOOP_లెక్క 1000
#నిర్వచించు ARRAY_కొలత 100

/* Overwrite a VLA. This will overwrite the return address if SP is incorrect */
శూన్య smash(అక్షరం *p, పూర్ణాంకం n) {
  memset(p, 0, n);
}

పూర్ణాంకం test1(పూర్ణాంకం n) {
  పూర్ణాంకం i;
  అక్షరం *array_ptrs[LOOP_లెక్క];
  
  కొరకు (i = 0; i < LOOP_లెక్క; ++i) {
    అక్షరం test[n];
    smash(test, n);
    array_ptrs[i] = test;
  }
  
  తిరిగి (array_ptrs[0]-array_ptrs[LOOP_లెక్క-1] < n) ? 0 : 1;
}

/* ensure goto does not circumvent array free */
పూర్ణాంకం test2(పూర్ణాంకం n) {
  అక్షరం *array_ptrs[LOOP_లెక్క];

  పూర్ణాంకం i = 0;
loop:;
  అక్షరం test[n];
  smash(test, n);
  ఒకవేళ (i >= LOOP_లెక్క)
    వెళ్ళు చివర;
  array_ptrs[i] = test;
  ++i;
  వెళ్ళు loop;

చివర:
  smash(test, n);
  అక్షరం test2[n];
  smash(test2, n);
  తిరిగి (array_ptrs[0] - array_ptrs[LOOP_లెక్క-1] < n) ? 0 : 1;
}

పూర్ణాంకం test3(పూర్ణాంకం n) {
  అక్షరం test[n];
  smash(test, n);
  వెళ్ళు label;
label:
  smash(test, n);
  అక్షరం test2[n];
  smash(test2, n);
  తిరిగి (test-test2 >= n) ? 0 : 1;
}

#నిర్వచించు నిరంతరం_TEST(t) \
  ఒకవేళ (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    ఒకవేళ (t(ARRAY_కొలత) == 0) { \
      fputs("success\n", stdout); \
    } లేకపోతే { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

పూర్ణాంకం ప్రధాన(పూర్ణాంకం argc, అక్షరం **argv) {
  స్థిరరాశి అక్షరం *testname = ఖాళీ;
  పూర్ణాంకం retval = EXIT_SUCCESS;
  ఒకవేళ (argc > 1)
    testname = argv[1];
  నిరంతరం_TEST(test1)
  నిరంతరం_TEST(test2)
  నిరంతరం_TEST(test3)
  తిరిగి retval;
}

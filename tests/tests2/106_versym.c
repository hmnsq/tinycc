#شامل <stdio.h>
#شامل <pthread.h>
#شامل <errno.h>

صحیح
اصلی(تهی)
{
  صحیح ret;
  pthread_condattr_t attr;
  pthread_cond_t condition;

  /* This test fails if symbol versioning does not work */
  pthread_condattr_init (&attr);
  pthread_condattr_setpshared (&attr, PTHREAD_PROCESS_SHARED);
  printf ("%s\n", pthread_cond_init (&condition, &attr) ? "fail":"ok");
  pthread_condattr_destroy (&attr);
  بازگشت 0;
}

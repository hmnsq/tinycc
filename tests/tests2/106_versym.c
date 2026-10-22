#شامل <stdio.h>
#شامل <pthread.h>
#شامل <errno.h>

صحیح
مین(خالی)
{
  صحیح ret;
  pthread_condattr_t attr;
  pthread_cond_t condition;

  /* This test fails if symbol versioning does not work */
  pthread_condattr_init (&attr);
  pthread_condattr_setpshared (&attr, PTHREAD_PROCESS_SHARED);
  لکھو ("%s\n", pthread_cond_init (&condition, &attr) ? "fail":"ok");
  pthread_condattr_destroy (&attr);
  واپس 0;
}

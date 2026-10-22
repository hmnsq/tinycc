#અન્તર્ભાવ <stdio.h>
#અન્તર્ભાવ <pthread.h>
#અન્તર્ભાવ <errno.h>

પૂર્ણાંક
મુખ્ય(શૂન્ય)
{
  પૂર્ણાંક ret;
  pthread_condattr_t attr;
  pthread_cond_t condition;

  /* This test fails if symbol versioning does not work */
  pthread_condattr_init (&attr);
  pthread_condattr_setpshared (&attr, PTHREAD_PROCESS_SHARED);
  printf ("%s\n", pthread_cond_init (&condition, &attr) ? "fail":"ok");
  pthread_condattr_destroy (&attr);
  પાછા 0;
}

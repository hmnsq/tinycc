#అన్తర్భావ <stdio.h>
#అన్తర్భావ <pthread.h>
#అన్తర్భావ <errno.h>

పూర్ణాంకం
ప్రధాన(శూన్య)
{
  పూర్ణాంకం ret;
  pthread_condattr_t attr;
  pthread_cond_t condition;

  /* This test fails if symbol versioning does not work */
  pthread_condattr_init (&attr);
  pthread_condattr_setpshared (&attr, PTHREAD_PROCESS_SHARED);
  రాయి ("%s\n", pthread_cond_init (&condition, &attr) ? "fail":"ok");
  pthread_condattr_destroy (&attr);
  తిరిగి 0;
}

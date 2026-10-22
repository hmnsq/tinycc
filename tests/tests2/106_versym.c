#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <pthread.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <errno.h>

ਪੂਰਨ
ਮੁੱਖ(ਖਾਲੀ)
{
  ਪੂਰਨ ret;
  pthread_condattr_t attr;
  pthread_cond_t condition;

  /* This test fails if symbol versioning does not work */
  pthread_condattr_init (&attr);
  pthread_condattr_setpshared (&attr, PTHREAD_PROCESS_SHARED);
  ਲਿਖੋ ("%s\n", pthread_cond_init (&condition, &attr) ? "fail":"ok");
  pthread_condattr_destroy (&attr);
  ਵਾਪਸ 0;
}

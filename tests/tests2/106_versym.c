#அந்தர்பாவ <stdio.h>
#அந்தர்பாவ <pthread.h>
#அந்தர்பாவ <errno.h>

முழு
முதன்மை(வெறுமை)
{
  முழு ret;
  pthread_condattr_t attr;
  pthread_cond_t condition;

  /* This test fails if symbol versioning does not work */
  pthread_condattr_init (&attr);
  pthread_condattr_setpshared (&attr, PTHREAD_PROCESS_SHARED);
  printf ("%s\n", pthread_cond_init (&condition, &attr) ? "fail":"ok");
  pthread_condattr_destroy (&attr);
  திரும்பு 0;
}

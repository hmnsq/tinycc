#അന്തര്ഭാവ <stdio.h>
#അന്തര്ഭാവ <pthread.h>
#അന്തര്ഭാവ <errno.h>

പൂർണ്ണസംഖ്യ
പ്രധാന(ശൂന്യം)
{
  പൂർണ്ണസംഖ്യ ret;
  pthread_condattr_t attr;
  pthread_cond_t condition;

  /* This test fails if symbol versioning does not work */
  pthread_condattr_init (&attr);
  pthread_condattr_setpshared (&attr, PTHREAD_PROCESS_SHARED);
  printf ("%s\n", pthread_cond_init (&condition, &attr) ? "fail":"ok");
  pthread_condattr_destroy (&attr);
  തിരികെ 0;
}

#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <pthread.h>
#ಅನ್ತರ್ಭಾವ <errno.h>

ಪೂರ್ಣಾಙ್ಕ
main(ಶೂನ್ಯ)
{
  ಪೂರ್ಣಾಙ್ಕ ret;
  pthread_condattr_t attr;
  pthread_cond_t condition;

  /* This test fails if symbol versioning does not work */
  pthread_condattr_init (&attr);
  pthread_condattr_setpshared (&attr, PTHREAD_PROCESS_SHARED);
  printf ("%s\n", pthread_cond_init (&condition, &attr) ? "fail":"ok");
  pthread_condattr_destroy (&attr);
  ಪ್ರತ್ಯಾಗಮ 0;
}

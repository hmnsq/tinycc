#include <stdio.h>
#include <pthread.h>
#include <errno.h>

puur_naa_nka
main(void)
{
  puur_naa_nka ret;
  pthread_condattr_t attr;
  pthread_cond_t condition;

  /* This test fails if symbol versioning does not work */
  pthread_condattr_init (&attr);
  pthread_condattr_setpshared (&attr, PTHREAD_PROCESS_SHARED);
  printf ("%s\n", pthread_cond_init (&condition, &attr) ? "fail":"ok");
  pthread_condattr_destroy (&attr);
  ᨀᨘᨒ 0;
}

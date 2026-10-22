#অন্তর্ভাৱ <stdio.h>
#অন্তর্ভাৱ <pthread.h>
#অন্তর্ভাৱ <errno.h>

পূর্ণাঙ্ক
main(শূন্য)
{
  পূর্ণাঙ্ক ret;
  pthread_condattr_t attr;
  pthread_cond_t condition;

  /* This test fails if symbol versioning does not work */
  pthread_condattr_init (&attr);
  pthread_condattr_setpshared (&attr, PTHREAD_PROCESS_SHARED);
  printf ("%s\n", pthread_cond_init (&condition, &attr) ? "fail":"ok");
  pthread_condattr_destroy (&attr);
  ঘূৰাই 0;
}

#समावेश <stdio.h>
#समावेश <pthread.h>
#समावेश <errno.h>

पूर्णांक
मुख्य(व्योम)
{
  पूर्णांक ret;
  pthread_condattr_t attr;
  pthread_cond_t condition;

  /* This test fails if symbol versioning does not work */
  pthread_condattr_init (&attr);
  pthread_condattr_setpshared (&attr, PTHREAD_PROCESS_SHARED);
  म_लिखो ("%s\n", pthread_cond_init (&condition, &attr) ? "fail":"ok");
  pthread_condattr_destroy (&attr);
  वापस 0;
}

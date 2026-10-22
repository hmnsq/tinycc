#अन्तर्भाव <stdio.h>
#अन्तर्भाव <pthread.h>
#अन्तर्भाव <errno.h>

पूर्णाङ्क
मुख्यम्(शून्य)
{
  पूर्णाङ्क ret;
  pthread_condattr_t attr;
  pthread_cond_t condition;

  /* This test fails if symbol versioning does not work */
  pthread_condattr_init (&attr);
  pthread_condattr_setpshared (&attr, PTHREAD_PROCESS_SHARED);
  प्रारूप_लिख ("%s\n", pthread_cond_init (&condition, &attr) ? "fail":"ok");
  pthread_condattr_destroy (&attr);
  प्रत्यागम 0;
}

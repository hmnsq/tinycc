#అన్తర్భావ <stdio.h>

నిర్మాణం big_struct { అక్షరం a[262144]; };

స్థిర స్థిరరాశి అక్షరం str[] = "abcdefghijklmnopqrstuvwxyz";

పూర్ణాంకం
ప్రధాన (శూన్య)
{
  అక్షరం *p;
  అక్షరం tmp[100];
  పూర్ణాంకం r = 0;

#ఒకవేళ defined __TCC_BCHECK__
  రాయి("BOUNDS ON:\n");
#లేకపోతే
  రాయి("BOUNDS OFF:\n");
#అయితే_ముగింపు

  ఒకవేళ (r != 0)
    __builtin_abort();

  r = (__builtin_offsetof(నిర్మాణం big_struct, a) != 0);
  రాయి(" 1:%d", !r);

  p = __builtin_memcpy (tmp, str, పరిమాణం(str));
  r = (p != tmp);
  రాయి(" 2:%d", !r);

  r = __builtin_memcmp (p, str, పరిమాణం(str));
  రాయి(" 3:%d", !r);

  p = __builtin_memmove(tmp, str, పరిమాణం(str));
  r = (__builtin_memcmp (p, str, పరిమాణం(str)));
  రాయి(" 4:%d", !r);

  p = __builtin_memset(tmp, 0, పరిమాణం (tmp));
  r = (p != tmp || tmp[0] != 0 || tmp[99] != 0);
  రాయి(" 5:%d", !r);

  r = (__builtin_strlen(str) != పరిమాణం(str) - 1);
  రాయి(" 6:%d", !r);

  p = __builtin_strcpy(tmp, str);
  r = (__builtin_memcmp (p, str, పరిమాణం(str)));
  రాయి(" 7:%d", !r);

  p = __builtin_strncpy(tmp, str, పరిమాణం(str));
  r = (__builtin_memcmp (p, str, పరిమాణం(str)));
  రాయి(" 8:%d", !r);

  r = (__builtin_strcmp (p, str));
  రాయి(" 9:%d", !r);

  r = (__builtin_strncmp (p, str, పరిమాణం(str)));
  రాయి(" 10:%d", !r);

  tmp[0] = '\0';
  p = __builtin_strcat(tmp, str);
  r = (__builtin_memcmp (p, str, పరిమాణం(str)));
  రాయి(" 11:%d", !r);

  tmp[0] = '\0';
  p = __builtin_strncat(tmp, str, __builtin_strlen(str));
  r = (__builtin_memcmp (p, str, పరిమాణం(str)));
  రాయి(" 12:%d", !r);

  r = (__builtin_strchr(p, 'z') != &p[25]);
  రాయి(" 13:%d", !r);

  r = (__builtin_strrchr(p, 'z') != &p[25]);
  రాయి(" 14:%d", !r);

  p = __builtin_strdup (str);
  r = (__builtin_memcmp (p, str, పరిమాణం(str)));
  రాయి(" 15:%d", !r);
  __builtin_free(p);

  p = __builtin_malloc (100);
  __builtin_memset(p, 0, 100);
  p = __builtin_realloc (p, 1000);
  __builtin_memset(p, 0, 1000);
  __builtin_free(p);

  p = __builtin_calloc(10, 10);
  __builtin_memset(p, 0, 100);
  __builtin_free(p);

#ఒకవేళ defined(__i386__) || defined(__x86_64__)
  p = __builtin_alloca(100);
  __builtin_memset(p, 0, 100);
#అయితే_ముగింపు
  రాయి("\n");
}

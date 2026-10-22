#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

ਬਣਤਰ big_struct { ਅੱਖਰ a[262144]; };

ਸਥਿਰ ਅਚਲ ਅੱਖਰ str[] = "abcdefghijklmnopqrstuvwxyz";

ਪੂਰਨ
ਮੁੱਖ (ਖਾਲੀ)
{
  ਅੱਖਰ *p;
  ਅੱਖਰ tmp[100];
  ਪੂਰਨ r = 0;

#ਜੇ defined __TCC_BCHECK__
  ਲਿਖੋ("BOUNDS ON:\n");
#ਨਹੀਂਤਾਂ
  ਲਿਖੋ("BOUNDS OFF:\n");
#ਜੇ_ਅੰਤ

  ਜੇ (r != 0)
    __builtin_abort();

  r = (__builtin_offsetof(ਬਣਤਰ big_struct, a) != 0);
  ਲਿਖੋ(" 1:%d", !r);

  p = __builtin_memcpy (tmp, str, ਆਕਾਰ(str));
  r = (p != tmp);
  ਲਿਖੋ(" 2:%d", !r);

  r = __builtin_memcmp (p, str, ਆਕਾਰ(str));
  ਲਿਖੋ(" 3:%d", !r);

  p = __builtin_memmove(tmp, str, ਆਕਾਰ(str));
  r = (__builtin_memcmp (p, str, ਆਕਾਰ(str)));
  ਲਿਖੋ(" 4:%d", !r);

  p = __builtin_memset(tmp, 0, ਆਕਾਰ (tmp));
  r = (p != tmp || tmp[0] != 0 || tmp[99] != 0);
  ਲਿਖੋ(" 5:%d", !r);

  r = (__builtin_strlen(str) != ਆਕਾਰ(str) - 1);
  ਲਿਖੋ(" 6:%d", !r);

  p = __builtin_strcpy(tmp, str);
  r = (__builtin_memcmp (p, str, ਆਕਾਰ(str)));
  ਲਿਖੋ(" 7:%d", !r);

  p = __builtin_strncpy(tmp, str, ਆਕਾਰ(str));
  r = (__builtin_memcmp (p, str, ਆਕਾਰ(str)));
  ਲਿਖੋ(" 8:%d", !r);

  r = (__builtin_strcmp (p, str));
  ਲਿਖੋ(" 9:%d", !r);

  r = (__builtin_strncmp (p, str, ਆਕਾਰ(str)));
  ਲਿਖੋ(" 10:%d", !r);

  tmp[0] = '\0';
  p = __builtin_strcat(tmp, str);
  r = (__builtin_memcmp (p, str, ਆਕਾਰ(str)));
  ਲਿਖੋ(" 11:%d", !r);

  tmp[0] = '\0';
  p = __builtin_strncat(tmp, str, __builtin_strlen(str));
  r = (__builtin_memcmp (p, str, ਆਕਾਰ(str)));
  ਲਿਖੋ(" 12:%d", !r);

  r = (__builtin_strchr(p, 'z') != &p[25]);
  ਲਿਖੋ(" 13:%d", !r);

  r = (__builtin_strrchr(p, 'z') != &p[25]);
  ਲਿਖੋ(" 14:%d", !r);

  p = __builtin_strdup (str);
  r = (__builtin_memcmp (p, str, ਆਕਾਰ(str)));
  ਲਿਖੋ(" 15:%d", !r);
  __builtin_free(p);

  p = __builtin_malloc (100);
  __builtin_memset(p, 0, 100);
  p = __builtin_realloc (p, 1000);
  __builtin_memset(p, 0, 1000);
  __builtin_free(p);

  p = __builtin_calloc(10, 10);
  __builtin_memset(p, 0, 100);
  __builtin_free(p);

#ਜੇ defined(__i386__) || defined(__x86_64__)
  p = __builtin_alloca(100);
  __builtin_memset(p, 0, 100);
#ਜੇ_ਅੰਤ
  ਲਿਖੋ("\n");
}

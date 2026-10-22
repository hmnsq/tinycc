#અન્તર્ભાવ <stdio.h>

સંરચના big_struct { અક્ષર a[262144]; };

સ્થિર અચલ અક્ષર str[] = "abcdefghijklmnopqrstuvwxyz";

પૂર્ણાંક
મુખ્ય (શૂન્ય)
{
  અક્ષર *p;
  અક્ષર tmp[100];
  પૂર્ણાંક r = 0;

#જો defined __TCC_BCHECK__
  printf("BOUNDS ON:\n");
#નહીંતર
  printf("BOUNDS OFF:\n");
#endif

  જો (r != 0)
    __builtin_abort();

  r = (__builtin_offsetof(સંરચના big_struct, a) != 0);
  printf(" 1:%d", !r);

  p = __builtin_memcpy (tmp, str, કદ(str));
  r = (p != tmp);
  printf(" 2:%d", !r);

  r = __builtin_memcmp (p, str, કદ(str));
  printf(" 3:%d", !r);

  p = __builtin_memmove(tmp, str, કદ(str));
  r = (__builtin_memcmp (p, str, કદ(str)));
  printf(" 4:%d", !r);

  p = __builtin_memset(tmp, 0, કદ (tmp));
  r = (p != tmp || tmp[0] != 0 || tmp[99] != 0);
  printf(" 5:%d", !r);

  r = (__builtin_strlen(str) != કદ(str) - 1);
  printf(" 6:%d", !r);

  p = __builtin_strcpy(tmp, str);
  r = (__builtin_memcmp (p, str, કદ(str)));
  printf(" 7:%d", !r);

  p = __builtin_strncpy(tmp, str, કદ(str));
  r = (__builtin_memcmp (p, str, કદ(str)));
  printf(" 8:%d", !r);

  r = (__builtin_strcmp (p, str));
  printf(" 9:%d", !r);

  r = (__builtin_strncmp (p, str, કદ(str)));
  printf(" 10:%d", !r);

  tmp[0] = '\0';
  p = __builtin_strcat(tmp, str);
  r = (__builtin_memcmp (p, str, કદ(str)));
  printf(" 11:%d", !r);

  tmp[0] = '\0';
  p = __builtin_strncat(tmp, str, __builtin_strlen(str));
  r = (__builtin_memcmp (p, str, કદ(str)));
  printf(" 12:%d", !r);

  r = (__builtin_strchr(p, 'z') != &p[25]);
  printf(" 13:%d", !r);

  r = (__builtin_strrchr(p, 'z') != &p[25]);
  printf(" 14:%d", !r);

  p = __builtin_strdup (str);
  r = (__builtin_memcmp (p, str, કદ(str)));
  printf(" 15:%d", !r);
  __builtin_free(p);

  p = __builtin_malloc (100);
  __builtin_memset(p, 0, 100);
  p = __builtin_realloc (p, 1000);
  __builtin_memset(p, 0, 1000);
  __builtin_free(p);

  p = __builtin_calloc(10, 10);
  __builtin_memset(p, 0, 100);
  __builtin_free(p);

#જો defined(__i386__) || defined(__x86_64__)
  p = __builtin_alloca(100);
  __builtin_memset(p, 0, 100);
#endif
  printf("\n");
}

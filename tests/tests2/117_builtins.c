#ضمن <stdio.h>

بنية big_struct { حرف a[262144]; };

ساكن ثابت حرف str[] = "abcdefghijklmnopqrstuvwxyz";

صحيح
اصلي (فراغ)
{
  حرف *p;
  حرف tmp[100];
  صحيح r = 0;

#إذا defined __TCC_BCHECK__
  چاپ_کړه("BOUNDS ON:\n");
#وإلا
  چاپ_کړه("BOUNDS OFF:\n");
#د_که_پای

  إذا (r != 0)
    __builtin_abort();

  r = (__builtin_offsetof(بنية big_struct, a) != 0);
  چاپ_کړه(" 1:%d", !r);

  p = __builtin_memcpy (tmp, str, حجم(str));
  r = (p != tmp);
  چاپ_کړه(" 2:%d", !r);

  r = __builtin_memcmp (p, str, حجم(str));
  چاپ_کړه(" 3:%d", !r);

  p = __builtin_memmove(tmp, str, حجم(str));
  r = (__builtin_memcmp (p, str, حجم(str)));
  چاپ_کړه(" 4:%d", !r);

  p = __builtin_memset(tmp, 0, حجم (tmp));
  r = (p != tmp || tmp[0] != 0 || tmp[99] != 0);
  چاپ_کړه(" 5:%d", !r);

  r = (__builtin_strlen(str) != حجم(str) - 1);
  چاپ_کړه(" 6:%d", !r);

  p = __builtin_strcpy(tmp, str);
  r = (__builtin_memcmp (p, str, حجم(str)));
  چاپ_کړه(" 7:%d", !r);

  p = __builtin_strncpy(tmp, str, حجم(str));
  r = (__builtin_memcmp (p, str, حجم(str)));
  چاپ_کړه(" 8:%d", !r);

  r = (__builtin_strcmp (p, str));
  چاپ_کړه(" 9:%d", !r);

  r = (__builtin_strncmp (p, str, حجم(str)));
  چاپ_کړه(" 10:%d", !r);

  tmp[0] = '\0';
  p = __builtin_strcat(tmp, str);
  r = (__builtin_memcmp (p, str, حجم(str)));
  چاپ_کړه(" 11:%d", !r);

  tmp[0] = '\0';
  p = __builtin_strncat(tmp, str, __builtin_strlen(str));
  r = (__builtin_memcmp (p, str, حجم(str)));
  چاپ_کړه(" 12:%d", !r);

  r = (__builtin_strchr(p, 'z') != &p[25]);
  چاپ_کړه(" 13:%d", !r);

  r = (__builtin_strrchr(p, 'z') != &p[25]);
  چاپ_کړه(" 14:%d", !r);

  p = __builtin_strdup (str);
  r = (__builtin_memcmp (p, str, حجم(str)));
  چاپ_کړه(" 15:%d", !r);
  __builtin_free(p);

  p = __builtin_malloc (100);
  __builtin_memset(p, 0, 100);
  p = __builtin_realloc (p, 1000);
  __builtin_memset(p, 0, 1000);
  __builtin_free(p);

  p = __builtin_calloc(10, 10);
  __builtin_memset(p, 0, 100);
  __builtin_free(p);

#إذا defined(__i386__) || defined(__x86_64__)
  p = __builtin_alloca(100);
  __builtin_memset(p, 0, 100);
#د_که_پای
  چاپ_کړه("\n");
}

#شامل <stdio.h>

ساخت big_struct { حرف a[262144]; };

ساکن ثابت حرف str[] = "abcdefghijklmnopqrstuvwxyz";

صحیح
مین (خالی)
{
  حرف *p;
  حرف tmp[100];
  صحیح r = 0;

#اگر defined __TCC_BCHECK__
  لکھو("BOUNDS ON:\n");
#ورنہ
  لکھو("BOUNDS OFF:\n");
#اگر_ختم

  اگر (r != 0)
    __builtin_abort();

  r = (__builtin_offsetof(ساخت big_struct, a) != 0);
  لکھو(" 1:%d", !r);

  p = __builtin_memcpy (tmp, str, حجم(str));
  r = (p != tmp);
  لکھو(" 2:%d", !r);

  r = __builtin_memcmp (p, str, حجم(str));
  لکھو(" 3:%d", !r);

  p = __builtin_memmove(tmp, str, حجم(str));
  r = (__builtin_memcmp (p, str, حجم(str)));
  لکھو(" 4:%d", !r);

  p = __builtin_memset(tmp, 0, حجم (tmp));
  r = (p != tmp || tmp[0] != 0 || tmp[99] != 0);
  لکھو(" 5:%d", !r);

  r = (__builtin_strlen(str) != حجم(str) - 1);
  لکھو(" 6:%d", !r);

  p = __builtin_strcpy(tmp, str);
  r = (__builtin_memcmp (p, str, حجم(str)));
  لکھو(" 7:%d", !r);

  p = __builtin_strncpy(tmp, str, حجم(str));
  r = (__builtin_memcmp (p, str, حجم(str)));
  لکھو(" 8:%d", !r);

  r = (__builtin_strcmp (p, str));
  لکھو(" 9:%d", !r);

  r = (__builtin_strncmp (p, str, حجم(str)));
  لکھو(" 10:%d", !r);

  tmp[0] = '\0';
  p = __builtin_strcat(tmp, str);
  r = (__builtin_memcmp (p, str, حجم(str)));
  لکھو(" 11:%d", !r);

  tmp[0] = '\0';
  p = __builtin_strncat(tmp, str, __builtin_strlen(str));
  r = (__builtin_memcmp (p, str, حجم(str)));
  لکھو(" 12:%d", !r);

  r = (__builtin_strchr(p, 'z') != &p[25]);
  لکھو(" 13:%d", !r);

  r = (__builtin_strrchr(p, 'z') != &p[25]);
  لکھو(" 14:%d", !r);

  p = __builtin_strdup (str);
  r = (__builtin_memcmp (p, str, حجم(str)));
  لکھو(" 15:%d", !r);
  __builtin_free(p);

  p = __builtin_malloc (100);
  __builtin_memset(p, 0, 100);
  p = __builtin_realloc (p, 1000);
  __builtin_memset(p, 0, 1000);
  __builtin_free(p);

  p = __builtin_calloc(10, 10);
  __builtin_memset(p, 0, 100);
  __builtin_free(p);

#اگر defined(__i386__) || defined(__x86_64__)
  p = __builtin_alloca(100);
  __builtin_memset(p, 0, 100);
#اگر_ختم
  لکھو("\n");
}

#ಅನ್ತರ್ಭಾವ <stdio.h>

ರಚನೆ big_struct { ಅಕ್ಷರ a[262144]; };

ಸ್ಥಿರ ಸ್ಥಿರಾಂಕ ಅಕ್ಷರ str[] = "abcdefghijklmnopqrstuvwxyz";

ಪೂರ್ಣಾಂಕ
ಮುಖ್ಯ (ಶೂನ್ಯ)
{
  ಅಕ್ಷರ *p;
  ಅಕ್ಷರ tmp[100];
  ಪೂರ್ಣಾಂಕ r = 0;

#ಆದರೆ defined __TCC_BCHECK__
  ಬರೆ("BOUNDS ON:\n");
#ಇಲ್ಲದಿದ್ದರೆ
  ಬರೆ("BOUNDS OFF:\n");
#ಆದರೆ_ಅಂತ್ಯ

  ಆದರೆ (r != 0)
    __builtin_abort();

  r = (__builtin_offsetof(ರಚನೆ big_struct, a) != 0);
  ಬರೆ(" 1:%d", !r);

  p = __builtin_memcpy (tmp, str, ಗಾತ್ರ(str));
  r = (p != tmp);
  ಬರೆ(" 2:%d", !r);

  r = __builtin_memcmp (p, str, ಗಾತ್ರ(str));
  ಬರೆ(" 3:%d", !r);

  p = __builtin_memmove(tmp, str, ಗಾತ್ರ(str));
  r = (__builtin_memcmp (p, str, ಗಾತ್ರ(str)));
  ಬರೆ(" 4:%d", !r);

  p = __builtin_memset(tmp, 0, ಗಾತ್ರ (tmp));
  r = (p != tmp || tmp[0] != 0 || tmp[99] != 0);
  ಬರೆ(" 5:%d", !r);

  r = (__builtin_strlen(str) != ಗಾತ್ರ(str) - 1);
  ಬರೆ(" 6:%d", !r);

  p = __builtin_strcpy(tmp, str);
  r = (__builtin_memcmp (p, str, ಗಾತ್ರ(str)));
  ಬರೆ(" 7:%d", !r);

  p = __builtin_strncpy(tmp, str, ಗಾತ್ರ(str));
  r = (__builtin_memcmp (p, str, ಗಾತ್ರ(str)));
  ಬರೆ(" 8:%d", !r);

  r = (__builtin_strcmp (p, str));
  ಬರೆ(" 9:%d", !r);

  r = (__builtin_strncmp (p, str, ಗಾತ್ರ(str)));
  ಬರೆ(" 10:%d", !r);

  tmp[0] = '\0';
  p = __builtin_strcat(tmp, str);
  r = (__builtin_memcmp (p, str, ಗಾತ್ರ(str)));
  ಬರೆ(" 11:%d", !r);

  tmp[0] = '\0';
  p = __builtin_strncat(tmp, str, __builtin_strlen(str));
  r = (__builtin_memcmp (p, str, ಗಾತ್ರ(str)));
  ಬರೆ(" 12:%d", !r);

  r = (__builtin_strchr(p, 'z') != &p[25]);
  ಬರೆ(" 13:%d", !r);

  r = (__builtin_strrchr(p, 'z') != &p[25]);
  ಬರೆ(" 14:%d", !r);

  p = __builtin_strdup (str);
  r = (__builtin_memcmp (p, str, ಗಾತ್ರ(str)));
  ಬರೆ(" 15:%d", !r);
  __builtin_free(p);

  p = __builtin_malloc (100);
  __builtin_memset(p, 0, 100);
  p = __builtin_realloc (p, 1000);
  __builtin_memset(p, 0, 1000);
  __builtin_free(p);

  p = __builtin_calloc(10, 10);
  __builtin_memset(p, 0, 100);
  __builtin_free(p);

#ಆದರೆ defined(__i386__) || defined(__x86_64__)
  p = __builtin_alloca(100);
  __builtin_memset(p, 0, 100);
#ಆದರೆ_ಅಂತ್ಯ
  ಬರೆ("\n");
}

#अन्तर्भाव <stdio.h>

संरचना big_struct { अक्षर a[262144]; };

स्थिर स्थिरांक अक्षर str[] = "abcdefghijklmnopqrstuvwxyz";

पूर्णांक
main (शून्य)
{
  अक्षर *p;
  अक्षर tmp[100];
  पूर्णांक r = 0;

#जर defined __TCC_BCHECK__
  म_लिखो("BOUNDS ON:\n");
#अन्यथा
  म_लिखो("BOUNDS OFF:\n");
#endif

  जर (r != 0)
    __builtin_abort();

  r = (__builtin_offsetof(संरचना big_struct, a) != 0);
  म_लिखो(" 1:%d", !r);

  p = __builtin_memcpy (tmp, str, आकार(str));
  r = (p != tmp);
  म_लिखो(" 2:%d", !r);

  r = __builtin_memcmp (p, str, आकार(str));
  म_लिखो(" 3:%d", !r);

  p = __builtin_memmove(tmp, str, आकार(str));
  r = (__builtin_memcmp (p, str, आकार(str)));
  म_लिखो(" 4:%d", !r);

  p = __builtin_memset(tmp, 0, आकार (tmp));
  r = (p != tmp || tmp[0] != 0 || tmp[99] != 0);
  म_लिखो(" 5:%d", !r);

  r = (__builtin_strlen(str) != आकार(str) - 1);
  म_लिखो(" 6:%d", !r);

  p = __builtin_strcpy(tmp, str);
  r = (__builtin_memcmp (p, str, आकार(str)));
  म_लिखो(" 7:%d", !r);

  p = __builtin_strncpy(tmp, str, आकार(str));
  r = (__builtin_memcmp (p, str, आकार(str)));
  म_लिखो(" 8:%d", !r);

  r = (__builtin_strcmp (p, str));
  म_लिखो(" 9:%d", !r);

  r = (__builtin_strncmp (p, str, आकार(str)));
  म_लिखो(" 10:%d", !r);

  tmp[0] = '\0';
  p = __builtin_strcat(tmp, str);
  r = (__builtin_memcmp (p, str, आकार(str)));
  म_लिखो(" 11:%d", !r);

  tmp[0] = '\0';
  p = __builtin_strncat(tmp, str, __builtin_strlen(str));
  r = (__builtin_memcmp (p, str, आकार(str)));
  म_लिखो(" 12:%d", !r);

  r = (__builtin_strchr(p, 'z') != &p[25]);
  म_लिखो(" 13:%d", !r);

  r = (__builtin_strrchr(p, 'z') != &p[25]);
  म_लिखो(" 14:%d", !r);

  p = __builtin_strdup (str);
  r = (__builtin_memcmp (p, str, आकार(str)));
  म_लिखो(" 15:%d", !r);
  __builtin_free(p);

  p = __builtin_malloc (100);
  __builtin_memset(p, 0, 100);
  p = __builtin_realloc (p, 1000);
  __builtin_memset(p, 0, 1000);
  __builtin_free(p);

  p = __builtin_calloc(10, 10);
  __builtin_memset(p, 0, 100);
  __builtin_free(p);

#जर defined(__i386__) || defined(__x86_64__)
  p = __builtin_alloca(100);
  __builtin_memset(p, 0, 100);
#endif
  म_लिखो("\n");
}

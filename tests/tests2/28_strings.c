#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>
#ਅਨ੍ਤਰ੍ਭਾਵ <string.h>

ਪੂਰਨ ਮੁੱਖ()
{
   ਅੱਖਰ a[10];

   strcpy(a, "hello");
   ਲਿਖੋ("%s\n", a);

   strncpy(a, "gosh", 2);
   ਲਿਖੋ("%s\n", a);

   ਲਿਖੋ("%d\n", strcmp(a, "apple") > 0);
   ਲਿਖੋ("%d\n", strcmp(a, "goere") > 0);
   ਲਿਖੋ("%d\n", strcmp(a, "zebra") < 0);

   ਲਿਖੋ("%d\n", ਲੜੀ_ਲੰਬਾਈ(a));

   strcat(a, "!");
   ਲਿਖੋ("%s\n", a);

   ਲਿਖੋ("%d\n", ਲੜੀ_ਤੁਲਨਾ(a, "apple", 2) > 0);
   ਲਿਖੋ("%d\n", ਲੜੀ_ਤੁਲਨਾ(a, "goere", 2) == 0);
   ਲਿਖੋ("%d\n", ਲੜੀ_ਤੁਲਨਾ(a, "goerg", 2) == 0);
   ਲਿਖੋ("%d\n", ਲੜੀ_ਤੁਲਨਾ(a, "zebra", 2) < 0);

   ਲਿਖੋ("%s\n", strchr(a, 'o'));
   ਲਿਖੋ("%s\n", strrchr(a, 'l'));
   ਲਿਖੋ("%d\n", strrchr(a, 'x') == ਨਿਰਾ);

   memset(&a[1], 'r', 4);
   ਲਿਖੋ("%s\n", a);

   ਸਮ੍ਰਿਤੀ_ਨਕਲ(&a[2], a, 2);
   ਲਿਖੋ("%s\n", a);

   ਲਿਖੋ("%d\n", memcmp(a, "apple", 4) > 0);
   ਲਿਖੋ("%d\n", memcmp(a, "grgr", 4) == 0);
   ਲਿਖੋ("%d\n", memcmp(a, "zebra", 4) < 0);

   ਵਾਪਸ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

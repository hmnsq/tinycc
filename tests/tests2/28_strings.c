#ضمن <stdio.h>
#ضمن <string.h>

صحيح اصلی()
{
   حرف a[10];

   strcpy(a, "hello");
   چاپ_کن("%s\n", a);

   strncpy(a, "gosh", 2);
   چاپ_کن("%s\n", a);

   چاپ_کن("%d\n", strcmp(a, "apple") > 0);
   چاپ_کن("%d\n", strcmp(a, "goere") > 0);
   چاپ_کن("%d\n", strcmp(a, "zebra") < 0);

   چاپ_کن("%d\n", طول_رشته(a));

   strcat(a, "!");
   چاپ_کن("%s\n", a);

   چاپ_کن("%d\n", مقایسه_رشته(a, "apple", 2) > 0);
   چاپ_کن("%d\n", مقایسه_رشته(a, "goere", 2) == 0);
   چاپ_کن("%d\n", مقایسه_رشته(a, "goerg", 2) == 0);
   چاپ_کن("%d\n", مقایسه_رشته(a, "zebra", 2) < 0);

   چاپ_کن("%s\n", strchr(a, 'o'));
   چاپ_کن("%s\n", strrchr(a, 'l'));
   چاپ_کن("%d\n", strrchr(a, 'x') == عدم);

   memset(&a[1], 'r', 4);
   چاپ_کن("%s\n", a);

   کپی_حافظه(&a[2], a, 2);
   چاپ_کن("%s\n", a);

   چاپ_کن("%d\n", memcmp(a, "apple", 4) > 0);
   چاپ_کن("%d\n", memcmp(a, "grgr", 4) == 0);
   چاپ_کن("%d\n", memcmp(a, "zebra", 4) < 0);

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

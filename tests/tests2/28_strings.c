#అన్తర్భావ <stdio.h>
#అన్తర్భావ <string.h>

పూర్ణాంకం ప్రధాన()
{
   అక్షరం a[10];

   strcpy(a, "hello");
   రాయి("%s\n", a);

   strncpy(a, "gosh", 2);
   రాయి("%s\n", a);

   రాయి("%d\n", strcmp(a, "apple") > 0);
   రాయి("%d\n", strcmp(a, "goere") > 0);
   రాయి("%d\n", strcmp(a, "zebra") < 0);

   రాయి("%d\n", అక్షరశ్రేణి_పొడవు(a));

   strcat(a, "!");
   రాయి("%s\n", a);

   రాయి("%d\n", అక్షరశ్రేణి_పోలిక(a, "apple", 2) > 0);
   రాయి("%d\n", అక్షరశ్రేణి_పోలిక(a, "goere", 2) == 0);
   రాయి("%d\n", అక్షరశ్రేణి_పోలిక(a, "goerg", 2) == 0);
   రాయి("%d\n", అక్షరశ్రేణి_పోలిక(a, "zebra", 2) < 0);

   రాయి("%s\n", strchr(a, 'o'));
   రాయి("%s\n", strrchr(a, 'l'));
   రాయి("%d\n", strrchr(a, 'x') == ఖాళీ);

   memset(&a[1], 'r', 4);
   రాయి("%s\n", a);

   జ్ఞాపకం_నకలు(&a[2], a, 2);
   రాయి("%s\n", a);

   రాయి("%d\n", memcmp(a, "apple", 4) > 0);
   రాయి("%d\n", memcmp(a, "grgr", 4) == 0);
   రాయి("%d\n", memcmp(a, "zebra", 4) < 0);

   తిరిగి 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

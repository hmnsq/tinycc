#ಅನ್ತರ್ಭಾವ <stdio.h>
#ಅನ್ತರ್ಭಾವ <string.h>

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ()
{
   ಅಕ್ಷರ a[10];

   strcpy(a, "hello");
   ಬರೆ("%s\n", a);

   strncpy(a, "gosh", 2);
   ಬರೆ("%s\n", a);

   ಬರೆ("%d\n", strcmp(a, "apple") > 0);
   ಬರೆ("%d\n", strcmp(a, "goere") > 0);
   ಬರೆ("%d\n", strcmp(a, "zebra") < 0);

   ಬರೆ("%d\n", ಅಕ್ಷರಸರಣಿ_ಉದ್ದ(a));

   strcat(a, "!");
   ಬರೆ("%s\n", a);

   ಬರೆ("%d\n", ಅಕ್ಷರಸರಣಿ_ಹೋಲಿಕೆ(a, "apple", 2) > 0);
   ಬರೆ("%d\n", ಅಕ್ಷರಸರಣಿ_ಹೋಲಿಕೆ(a, "goere", 2) == 0);
   ಬರೆ("%d\n", ಅಕ್ಷರಸರಣಿ_ಹೋಲಿಕೆ(a, "goerg", 2) == 0);
   ಬರೆ("%d\n", ಅಕ್ಷರಸರಣಿ_ಹೋಲಿಕೆ(a, "zebra", 2) < 0);

   ಬರೆ("%s\n", strchr(a, 'o'));
   ಬರೆ("%s\n", strrchr(a, 'l'));
   ಬರೆ("%d\n", strrchr(a, 'x') == ಖಾಲಿ);

   memset(&a[1], 'r', 4);
   ಬರೆ("%s\n", a);

   ಸ್ಮರಣೆ_ನಕಲು(&a[2], a, 2);
   ಬರೆ("%s\n", a);

   ಬರೆ("%d\n", memcmp(a, "apple", 4) > 0);
   ಬರೆ("%d\n", memcmp(a, "grgr", 4) == 0);
   ಬರೆ("%d\n", memcmp(a, "zebra", 4) < 0);

   ಹಿಂತಿರುಗಿ 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

#ಅನ್ತರ್ಭಾವ <stdio.h>
ಸಂರಚನಾ wchar {
    ವರ್ಣ *data; ವರ್ಣ mem[];
};
ಸಂರಚನಾ wint {
    ವರ್ಣ *data; ಪೂರ್ಣಾಙ್ಕ mem[];
};
ಪೂರ್ಣಾಙ್ಕ f1char (ಶೂನ್ಯ) {
    ವರ್ಣ s[9]="nonono";
    ಸಂರಚನಾ wchar q = {"bugs"};
    ಪ್ರತ್ಯಾಗಮ !s[0];
}
ಪೂರ್ಣಾಙ್ಕ f1int (ಶೂನ್ಯ) {
    ವರ್ಣ s[9]="nonono";
    ಸಂರಚನಾ wint q = {"bugs"};
    ಪ್ರತ್ಯಾಗಮ !s[0];
}
ಪೂರ್ಣಾಙ್ಕ empty[] = {}; // GNU extension
ಪೂರ್ಣಾಙ್ಕ main (ಶೂನ್ಯ) {
   ವರ್ಣ s[9]="nonono";
   ಸ್ಥಿರ ಸಂರಚನಾ wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   ಯದಿ (f1char() || f1int())
     printf ("bla\n");
   ಪ್ರತ್ಯಾಗಮ !s[0];
}

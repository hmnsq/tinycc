#અન્તર્ભાવ <stdio.h>
સંરચના wchar {
    અક્ષર *data; અક્ષર mem[];
};
સંરચના wint {
    અક્ષર *data; પૂર્ણાંક mem[];
};
પૂર્ણાંક f1char (શૂન્ય) {
    અક્ષર s[9]="nonono";
    સંરચના wchar q = {"bugs"};
    પાછા !s[0];
}
પૂર્ણાંક f1int (શૂન્ય) {
    અક્ષર s[9]="nonono";
    સંરચના wint q = {"bugs"};
    પાછા !s[0];
}
પૂર્ણાંક empty[] = {}; // GNU extension
પૂર્ણાંક મુખ્ય (શૂન્ય) {
   અક્ષર s[9]="nonono";
   સ્થિર સંરચના wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   જો (f1char() || f1int())
     printf ("bla\n");
   પાછા !s[0];
}

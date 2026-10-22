#include <stdio.h>
struct wchar {
    char *data; char mem[];
};
struct wint {
    char *data; цяло mem[];
};
цяло f1char (void) {
    char s[9]="nonono";
    struct wchar q = {"bugs"};
    върни !s[0];
}
цяло f1int (void) {
    char s[9]="nonono";
    struct wint q = {"bugs"};
    върни !s[0];
}
цяло empty[] = {}; // GNU extension
цяло main (void) {
   char s[9]="nonono";
   static struct wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   ако (f1char() || f1int())
     printf ("bla\n");
   върни !s[0];
}

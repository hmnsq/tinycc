#include <stdio.h>
struct wchar {
    char *data; char mem[];
};
struct wint {
    char *data; цео mem[];
};
цео f1char (void) {
    char s[9]="nonono";
    struct wchar q = {"bugs"};
    врати !s[0];
}
цео f1int (void) {
    char s[9]="nonono";
    struct wint q = {"bugs"};
    врати !s[0];
}
цео empty[] = {}; // GNU extension
цео main (void) {
   char s[9]="nonono";
   static struct wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   ако (f1char() || f1int())
     printf ("bla\n");
   врати !s[0];
}

#include <stdio.h>
struct wchar {
    char *data; char mem[];
};
struct wint {
    char *data; ціле mem[];
};
ціле f1char (void) {
    char s[9]="nonono";
    struct wchar q = {"bugs"};
    повернути !s[0];
}
ціле f1int (void) {
    char s[9]="nonono";
    struct wint q = {"bugs"};
    повернути !s[0];
}
ціле empty[] = {}; // GNU extension
ціле main (void) {
   char s[9]="nonono";
   static struct wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   якщо (f1char() || f1int())
     printf ("bla\n");
   повернути !s[0];
}

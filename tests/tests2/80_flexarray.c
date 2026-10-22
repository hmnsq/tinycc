#include <stdio.h>
struct wchar {
    char *data; char mem[];
};
struct wint {
    char *data; số_nguyên mem[];
};
số_nguyên f1char (void) {
    char s[9]="nonono";
    struct wchar q = {"bugs"};
    trả_về !s[0];
}
số_nguyên f1int (void) {
    char s[9]="nonono";
    struct wint q = {"bugs"};
    trả_về !s[0];
}
số_nguyên empty[] = {}; // GNU extension
số_nguyên main (void) {
   char s[9]="nonono";
   static struct wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   nếu (f1char() || f1int())
     printf ("bla\n");
   trả_về !s[0];
}

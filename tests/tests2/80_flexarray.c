#include <stdio.h>
struct wchar {
    char *data; char mem[];
};
struct wint {
    char *data; целое mem[];
};
целое f1char (void) {
    char s[9]="nonono";
    struct wchar q = {"bugs"};
    вернуть !s[0];
}
целое f1int (void) {
    char s[9]="nonono";
    struct wint q = {"bugs"};
    вернуть !s[0];
}
целое empty[] = {}; // GNU extension
целое основной (void) {
   char s[9]="nonono";
   static struct wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   если (f1char() || f1int())
     printf ("bla\n");
   вернуть !s[0];
}

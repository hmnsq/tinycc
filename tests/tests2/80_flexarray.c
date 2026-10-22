#include <stdio.h>
struct wchar {
    char *data; char mem[];
};
struct wint {
    char *data; 정수 mem[];
};
정수 f1char (void) {
    char s[9]="nonono";
    struct wchar q = {"bugs"};
    반환 !s[0];
}
정수 f1int (void) {
    char s[9]="nonono";
    struct wint q = {"bugs"};
    반환 !s[0];
}
정수 empty[] = {}; // GNU extension
정수 main (void) {
   char s[9]="nonono";
   static struct wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   만약 (f1char() || f1int())
     printf ("bla\n");
   반환 !s[0];
}

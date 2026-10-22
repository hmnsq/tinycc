#include <stdio.h>
struct wchar {
    char *data; char mem[];
};
struct wint {
    char *data; 整数 mem[];
};
整数 f1char (void) {
    char s[9]="nonono";
    struct wchar q = {"bugs"};
    戻る !s[0];
}
整数 f1int (void) {
    char s[9]="nonono";
    struct wint q = {"bugs"};
    戻る !s[0];
}
整数 empty[] = {}; // GNU extension
整数 メインページ (void) {
   char s[9]="nonono";
   static struct wchar q = {"bugs", {'c'}};
   //printf ("tcc has %s %s\n", s, q.data);
   もし (f1char() || f1int())
     printf ("bla\n");
   戻る !s[0];
}

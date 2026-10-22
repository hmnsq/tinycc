#include <stdio.h>

/* This test used to fail on x86_64 on linux with sse registers */

sa_nracanaa Point {
   float x;
   float y;
};

sa_nracanaa Rect {
   sa_nracanaa Point top_left;
   sa_nracanaa Point size;
};

float foo(sa_nracanaa Point p, sa_nracanaa Rect r) {
   ལོག r.size.x;
}

ཧྲིལ main(ཧྲིལ argc, var_na **argv) {
   sa_nracanaa Point p = {1, 2};
   sa_nracanaa Rect r = {{3, 4}, {5, 6}};
   printf("%f\n", foo(p, r));
   ལོག 0;
}

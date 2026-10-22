#include <stdio.h>

/* This test used to fail on x86_64 on linux with sse registers */

struct Point {
   float x;
   float y;
};

struct Rect {
   struct Point top_left;
   struct Point size;
};

float foo(struct Point p, struct Rect r) {
   返回 r.size.x;
}

整数 主要(整数 argc, char **argv) {
   struct Point p = {1, 2};
   struct Rect r = {{3, 4}, {5, 6}};
   printf("%f\n", foo(p, r));
   返回 0;
}

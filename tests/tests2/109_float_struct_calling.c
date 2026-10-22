#ضمن <stdio.h>

/* This test used to fail on x86_64 on linux with sse registers */

بنية Point {
   عائم x;
   عائم y;
};

بنية Rect {
   بنية Point top_left;
   بنية Point size;
};

عائم foo(بنية Point p, بنية Rect r) {
   החזר r.size.x;
}

صحيح main(صحيح argc, حرف **argv) {
   بنية Point p = {1, 2};
   بنية Rect r = {{3, 4}, {5, 6}};
   printf("%f\n", foo(p, r));
   החזר 0;
}

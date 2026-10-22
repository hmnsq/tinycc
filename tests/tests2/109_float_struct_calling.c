#شامل <stdio.h>

/* This test used to fail on x86_64 on linux with sse registers */

ساختار Point {
   اعشاری x;
   اعشاری y;
};

ساختار Rect {
   ساختار Point بالاترین_چپ;
   ساختار Point size;
};

اعشاری foo(ساختار Point p, ساختار Rect r) {
   بازگشت r.size.x;
}

صحیح اصلی(صحیح argc, نویسه **argv) {
   ساختار Point p = {1, 2};
   ساختار Rect r = {{3, 4}, {5, 6}};
   printf("%f\n", foo(p, r));
   بازگشت 0;
}

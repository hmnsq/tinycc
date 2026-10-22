#অন্তর্ভাৱ <stdio.h>

/* This test used to fail on x86_64 on linux with sse registers */

সংরচনা Point {
   ভিন্ন x;
   ভিন্ন y;
};

সংরচনা Rect {
   সংরচনা Point শীৰ্ষ_বাম;
   সংরচনা Point size;
};

ভিন্ন foo(সংরচনা Point p, সংরচনা Rect r) {
   ঘূৰাই r.size.x;
}

পূর্ণাঙ্ক main(পূর্ণাঙ্ক argc, ৱর্ণ **argv) {
   সংরচনা Point p = {1, 2};
   সংরচনা Rect r = {{3, 4}, {5, 6}};
   printf("%f\n", foo(p, r));
   ঘূৰাই 0;
}

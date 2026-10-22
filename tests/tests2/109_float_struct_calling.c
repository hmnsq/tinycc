#অন্তর্ভাব <stdio.h>

/* This test used to fail on x86_64 on linux with sse registers */

কাঠামো Point {
   দশমিক x;
   দশমিক y;
};

কাঠামো Rect {
   কাঠামো Point শীর্ষ_বাম;
   কাঠামো Point আকার_2;
};

দশমিক foo(কাঠামো Point p, কাঠামো Rect r) {
   ফেরত r.আকার_2.x;
}

পূর্ণসংখ্যা প্রধান(পূর্ণসংখ্যা argc, অক্ষর **argv) {
   কাঠামো Point p = {1, 2};
   কাঠামো Rect r = {{3, 4}, {5, 6}};
   printf("%f\n", foo(p, r));
   ফেরত 0;
}

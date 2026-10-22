#अन्तर्भाव <stdio.h>

/* This test used to fail on x86_64 on linux with sse registers */

संरचना Point {
   भिन्न x;
   भिन्न y;
};

संरचना Rect {
   संरचना Point शिखरम्_वामः;
   संरचना Point size;
};

भिन्न foo(संरचना Point p, संरचना Rect r) {
   प्रत्यागम r.size.x;
}

पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण **argv) {
   संरचना Point p = {1, 2};
   संरचना Rect r = {{3, 4}, {5, 6}};
   printf("%f\n", foo(p, r));
   प्रत्यागम 0;
}

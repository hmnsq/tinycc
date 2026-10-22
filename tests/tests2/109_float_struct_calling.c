#अन्तर्भाव <stdio.h>

/* This test used to fail on x86_64 on linux with sse registers */

संरचना Point {
   भिन्न x;
   भिन्न y;
};

संरचना Rect {
   संरचना Point शीर्ष_बायाँ;
   संरचना Point size;
};

भिन्न foo(संरचना Point p, संरचना Rect r) {
   फर्काऊ r.size.x;
}

पूर्णाङ्क main(पूर्णाङ्क argc, वर्ण **argv) {
   संरचना Point p = {1, 2};
   संरचना Rect r = {{3, 4}, {5, 6}};
   म_लिखो("%f\n", foo(p, r));
   फर्काऊ 0;
}

#अन्तर्भाव <stdio.h>

/* This test used to fail on x86_64 on linux with sse registers */

संरचना Point {
   दशांश x;
   दशांश y;
};

संरचना Rect {
   संरचना Point शीर्ष_डावा;
   संरचना Point size;
};

दशांश foo(संरचना Point p, संरचना Rect r) {
   परत r.size.x;
}

पूर्णांक main(पूर्णांक argc, अक्षर **argv) {
   संरचना Point p = {1, 2};
   संरचना Rect r = {{3, 4}, {5, 6}};
   म_लिखो("%f\n", foo(p, r));
   परत 0;
}

#ଅନ୍ତର୍ଭାଵ <stdio.h>

/* This test used to fail on x86_64 on linux with sse registers */

ସଂରଚନା Point {
   ଦଶମିକ x;
   ଦଶମିକ y;
};

ସଂରଚନା Rect {
   ସଂରଚନା Point ଶୀର୍ଷ_ବାମ;
   ସଂରଚନା Point size;
};

ଦଶମିକ foo(ସଂରଚନା Point p, ସଂରଚନା Rect r) {
   ଫେରନ୍ତୁ r.size.x;
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv) {
   ସଂରଚନା Point p = {1, 2};
   ସଂରଚନା Rect r = {{3, 4}, {5, 6}};
   printf("%f\n", foo(p, r));
   ଫେରନ୍ତୁ 0;
}

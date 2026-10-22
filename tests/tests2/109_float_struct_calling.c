#અન્તર્ભાવ <stdio.h>

/* This test used to fail on x86_64 on linux with sse registers */

સંરચના Point {
   દશાંશ x;
   દશાંશ y;
};

સંરચના Rect {
   સંરચના Point ટોચ_ડાબું;
   સંરચના Point size;
};

દશાંશ foo(સંરચના Point p, સંરચના Rect r) {
   પાછા r.size.x;
}

પૂર્ણાંક મુખ્ય(પૂર્ણાંક argc, અક્ષર **argv) {
   સંરચના Point p = {1, 2};
   સંરચના Rect r = {{3, 4}, {5, 6}};
   printf("%f\n", foo(p, r));
   પાછા 0;
}

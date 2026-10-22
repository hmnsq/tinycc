#അന്തര്ഭാവ <stdio.h>

/* This test used to fail on x86_64 on linux with sse registers */

ഘടന Point {
   ദശാംശം x;
   ദശാംശം y;
};

ഘടന Rect {
   ഘടന Point മുകൾ_ഇടത്;
   ഘടന Point size;
};

ദശാംശം foo(ഘടന Point p, ഘടന Rect r) {
   തിരികെ r.size.x;
}

പൂർണ്ണസംഖ്യ പ്രധാന(പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv) {
   ഘടന Point p = {1, 2};
   ഘടന Rect r = {{3, 4}, {5, 6}};
   printf("%f\n", foo(p, r));
   തിരികെ 0;
}

#ಅನ್ತರ್ಭಾವ <stdio.h>

/* This test used to fail on x86_64 on linux with sse registers */

ಸಂರಚನಾ Point {
   ಭಿನ್ನ x;
   ಭಿನ್ನ y;
};

ಸಂರಚನಾ Rect {
   ಸಂರಚನಾ Point ತುದಿ_ಎಡ;
   ಸಂರಚನಾ Point size;
};

ಭಿನ್ನ foo(ಸಂರಚನಾ Point p, ಸಂರಚನಾ Rect r) {
   ಪ್ರತ್ಯಾಗಮ r.size.x;
}

ಪೂರ್ಣಾಙ್ಕ main(ಪೂರ್ಣಾಙ್ಕ argc, ವರ್ಣ **argv) {
   ಸಂರಚನಾ Point p = {1, 2};
   ಸಂರಚನಾ Rect r = {{3, 4}, {5, 6}};
   printf("%f\n", foo(p, r));
   ಪ್ರತ್ಯಾಗಮ 0;
}

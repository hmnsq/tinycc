#ಅನ್ತರ್ಭಾವ <stdio.h>

// arm64-gen.c: gfunc_call() Second pass when struct args may overwrite previous func call result
ಸಂರಚನಾ vec {
        ಭಿನ್ನ x;
        ಭಿನ್ನ y;
};

ಶೂನ್ಯ bug(ಭಿನ್ನ x, ಭಿನ್ನ y) {
    printf("x=%f\ny=%f\n", x, y);
}

ಭಿನ್ನ dot(ಸಂರಚನಾ vec v) {
    ಪ್ರತ್ಯಾಗಮ 999.5;
}

ಶೂನ್ಯ main(ಶೂನ್ಯ) {
        ಸಂರಚನಾ vec a;
        a.x = 33.0f;
        a.y = 77.0f;
        bug(dot(a), dot(a));
}


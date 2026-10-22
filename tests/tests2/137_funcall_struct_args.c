#ಅನ್ತರ್ಭಾವ <stdio.h>

// arm64-gen.c: gfunc_call() Second pass when struct args may overwrite previous func call result
ರಚನೆ vec {
        ದಶಮಾಂಶ x;
        ದಶಮಾಂಶ y;
};

ಶೂನ್ಯ bug(ದಶಮಾಂಶ x, ದಶಮಾಂಶ y) {
    ಬರೆ("x=%f\ny=%f\n", x, y);
}

ದಶಮಾಂಶ dot(ರಚನೆ vec v) {
    ಹಿಂತಿರುಗಿ 999.5;
}

ಶೂನ್ಯ ಮುಖ್ಯ(ಶೂನ್ಯ) {
        ರಚನೆ vec a;
        a.x = 33.0f;
        a.y = 77.0f;
        bug(dot(a), dot(a));
}


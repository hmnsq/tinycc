#include <stdio.h>

// arm64-gen.c: gfunc_call() Second pass when struct args may overwrite previous func call result
sa_nracanaa vec {
        float x;
        float y;
};

void bug(float x, float y) {
    printf("x=%f\ny=%f\n", x, y);
}

float dot(sa_nracanaa vec v) {
    ආපසු 999.5;
}

void main(void) {
        sa_nracanaa vec a;
        a.x = 33.0f;
        a.y = 77.0f;
        bug(dot(a), dot(a));
}


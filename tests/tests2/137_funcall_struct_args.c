#شامل <stdio.h>

// arm64-gen.c: gfunc_call() Second pass when struct args may overwrite previous func call result
ساختار vec {
        اعشاری x;
        اعشاری y;
};

تهی bug(اعشاری x, اعشاری y) {
    printf("x=%f\ny=%f\n", x, y);
}

اعشاری dot(ساختار vec v) {
    بازگشت 999.5;
}

تهی اصلی(تهی) {
        ساختار vec a;
        a.x = 33.0f;
        a.y = 77.0f;
        bug(dot(a), dot(a));
}


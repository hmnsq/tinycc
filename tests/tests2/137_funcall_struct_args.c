#شامل <stdio.h>

// arm64-gen.c: gfunc_call() Second pass when struct args may overwrite previous func call result
ساخت vec {
        اعشاری x;
        اعشاری y;
};

خالی bug(اعشاری x, اعشاری y) {
    لکھو("x=%f\ny=%f\n", x, y);
}

اعشاری dot(ساخت vec v) {
    واپس 999.5;
}

خالی مین(خالی) {
        ساخت vec a;
        a.x = 33.0f;
        a.y = 77.0f;
        bug(dot(a), dot(a));
}


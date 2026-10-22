#ضمن <stdio.h>

// arm64-gen.c: gfunc_call() Second pass when struct args may overwrite previous func call result
بنية vec {
        عائم x;
        عائم y;
};

فراغ bug(عائم x, عائم y) {
    چاپ_کن("x=%f\ny=%f\n", x, y);
}

عائم dot(بنية vec v) {
    أرجع 999.5;
}

فراغ اصلی(فراغ) {
        بنية vec a;
        a.x = 33.0f;
        a.y = 77.0f;
        bug(dot(a), dot(a));
}


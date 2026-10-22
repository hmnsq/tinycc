#অন্তর্ভাব <stdio.h>

// arm64-gen.c: gfunc_call() Second pass when struct args may overwrite previous func call result
কাঠামো vec {
        দশমিক x;
        দশমিক y;
};

শূন্য bug(দশমিক x, দশমিক y) {
    printf("x=%f\ny=%f\n", x, y);
}

দশমিক dot(কাঠামো vec v) {
    ফেরত 999.5;
}

শূন্য প্রধান(শূন্য) {
        কাঠামো vec a;
        a.x = 33.0f;
        a.y = 77.0f;
        bug(dot(a), dot(a));
}


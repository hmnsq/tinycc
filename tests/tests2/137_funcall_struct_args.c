#অন্তর্ভাৱ <stdio.h>

// arm64-gen.c: gfunc_call() Second pass when struct args may overwrite previous func call result
সংরচনা vec {
        ভিন্ন x;
        ভিন্ন y;
};

শূন্য bug(ভিন্ন x, ভিন্ন y) {
    printf("x=%f\ny=%f\n", x, y);
}

ভিন্ন dot(সংরচনা vec v) {
    ঘূৰাই 999.5;
}

শূন্য main(শূন্য) {
        সংরচনা vec a;
        a.x = 33.0f;
        a.y = 77.0f;
        bug(dot(a), dot(a));
}


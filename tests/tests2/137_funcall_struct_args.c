#અન્તર્ભાવ <stdio.h>

// arm64-gen.c: gfunc_call() Second pass when struct args may overwrite previous func call result
સંરચના vec {
        દશાંશ x;
        દશાંશ y;
};

શૂન્ય bug(દશાંશ x, દશાંશ y) {
    printf("x=%f\ny=%f\n", x, y);
}

દશાંશ dot(સંરચના vec v) {
    પાછા 999.5;
}

શૂન્ય મુખ્ય(શૂન્ય) {
        સંરચના vec a;
        a.x = 33.0f;
        a.y = 77.0f;
        bug(dot(a), dot(a));
}


#ଅନ୍ତର୍ଭାଵ <stdio.h>

// arm64-gen.c: gfunc_call() Second pass when struct args may overwrite previous func call result
ସଂରଚନା vec {
        ଦଶମିକ x;
        ଦଶମିକ y;
};

ଶୂନ୍ୟ bug(ଦଶମିକ x, ଦଶମିକ y) {
    printf("x=%f\ny=%f\n", x, y);
}

ଦଶମିକ dot(ସଂରଚନା vec v) {
    ଫେରନ୍ତୁ 999.5;
}

ଶୂନ୍ୟ ମୁଖ୍ୟ(ଶୂନ୍ୟ) {
        ସଂରଚନା vec a;
        a.x = 33.0f;
        a.y = 77.0f;
        bug(dot(a), dot(a));
}


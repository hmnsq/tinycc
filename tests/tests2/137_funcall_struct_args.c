#അന്തര്ഭാവ <stdio.h>

// arm64-gen.c: gfunc_call() Second pass when struct args may overwrite previous func call result
ഘടന vec {
        ദശാംശം x;
        ദശാംശം y;
};

ശൂന്യം bug(ദശാംശം x, ദശാംശം y) {
    printf("x=%f\ny=%f\n", x, y);
}

ദശാംശം dot(ഘടന vec v) {
    തിരികെ 999.5;
}

ശൂന്യം പ്രധാന(ശൂന്യം) {
        ഘടന vec a;
        a.x = 33.0f;
        a.y = 77.0f;
        bug(dot(a), dot(a));
}


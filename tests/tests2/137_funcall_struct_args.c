#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

// arm64-gen.c: gfunc_call() Second pass when struct args may overwrite previous func call result
ਬਣਤਰ vec {
        ਦਸ਼ਮਲਵ x;
        ਦਸ਼ਮਲਵ y;
};

ਖਾਲੀ bug(ਦਸ਼ਮਲਵ x, ਦਸ਼ਮਲਵ y) {
    ਲਿਖੋ("x=%f\ny=%f\n", x, y);
}

ਦਸ਼ਮਲਵ dot(ਬਣਤਰ vec v) {
    ਵਾਪਸ 999.5;
}

ਖਾਲੀ ਮੁੱਖ(ਖਾਲੀ) {
        ਬਣਤਰ vec a;
        a.x = 33.0f;
        a.y = 77.0f;
        bug(dot(a), dot(a));
}


#समावेश <stdio.h>

// arm64-gen.c: gfunc_call() Second pass when struct args may overwrite previous func call result
काष्ठा vec {
        भग्न x;
        भग्न y;
};

व्योम bug(भग्न x, भग्न y) {
    म_लिखो("x=%f\ny=%f\n", x, y);
}

भग्न dot(काष्ठा vec v) {
    वापस 999.5;
}

व्योम मुख्य(व्योम) {
        काष्ठा vec a;
        a.x = 33.0f;
        a.y = 77.0f;
        bug(dot(a), dot(a));
}


#अन्तर्भाव <stdio.h>

// arm64-gen.c: gfunc_call() Second pass when struct args may overwrite previous func call result
संरचना vec {
        भिन्न x;
        भिन्न y;
};

शून्य bug(भिन्न x, भिन्न y) {
    printf("x=%f\ny=%f\n", x, y);
}

भिन्न dot(संरचना vec v) {
    पटिनिवत्त 999.5;
}

शून्य main(शून्य) {
        संरचना vec a;
        a.x = 33.0f;
        a.y = 77.0f;
        bug(dot(a), dot(a));
}


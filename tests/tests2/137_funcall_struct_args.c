#अन्तर्भाव <stdio.h>

// arm64-gen.c: gfunc_call() Second pass when struct args may overwrite previous func call result
संरचना vec {
        दशांश x;
        दशांश y;
};

शून्य bug(दशांश x, दशांश y) {
    म_लिखो("x=%f\ny=%f\n", x, y);
}

दशांश dot(संरचना vec v) {
    परत 999.5;
}

शून्य main(शून्य) {
        संरचना vec a;
        a.x = 33.0f;
        a.y = 77.0f;
        bug(dot(a), dot(a));
}


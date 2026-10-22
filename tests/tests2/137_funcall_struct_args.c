#அந்தர்பாவ <stdio.h>

// arm64-gen.c: gfunc_call() Second pass when struct args may overwrite previous func call result
கட்டமைப்பு vec {
        தசம x;
        தசம y;
};

வெறுமை bug(தசம x, தசம y) {
    printf("x=%f\ny=%f\n", x, y);
}

தசம dot(கட்டமைப்பு vec v) {
    திரும்பு 999.5;
}

வெறுமை முதன்மை(வெறுமை) {
        கட்டமைப்பு vec a;
        a.x = 33.0f;
        a.y = 77.0f;
        bug(dot(a), dot(a));
}


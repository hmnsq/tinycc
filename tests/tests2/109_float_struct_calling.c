#அந்தர்பாவ <stdio.h>

/* This test used to fail on x86_64 on linux with sse registers */

கட்டமைப்பு Point {
   தசம x;
   தசம y;
};

கட்டமைப்பு Rect {
   கட்டமைப்பு Point உச்சி_இடது;
   கட்டமைப்பு Point size;
};

தசம foo(கட்டமைப்பு Point p, கட்டமைப்பு Rect r) {
   திரும்பு r.size.x;
}

முழு முதன்மை(முழு argc, எழுத்து **argv) {
   கட்டமைப்பு Point p = {1, 2};
   கட்டமைப்பு Rect r = {{3, 4}, {5, 6}};
   printf("%f\n", foo(p, r));
   திரும்பு 0;
}

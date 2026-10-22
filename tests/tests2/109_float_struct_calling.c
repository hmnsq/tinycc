#ضمن <stdio.h>

/* This test used to fail on x86_64 on linux with sse registers */

بنية نقطه_2 {
   عائم x;
   عائم y;
};

بنية Rect {
   بنية نقطه_2 بالاترین_چپ;
   بنية نقطه_2 اندازه;
};

عائم foo(بنية نقطه_2 p, بنية Rect r) {
   أرجع r.اندازه.x;
}

صحيح اصلی(صحيح argc, حرف **argv) {
   بنية نقطه_2 p = {1, 2};
   بنية Rect r = {{3, 4}, {5, 6}};
   چاپ_کن("%f\n", foo(p, r));
   أرجع 0;
}

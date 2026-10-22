#ضمن <stdio.h>

/* This test used to fail on x86_64 on linux with sse registers */

بنية نقطہ_2 {
   عائم x;
   عائم y;
};

بنية Rect {
   بنية نقطہ_2 چوٹی_بایاں;
   بنية نقطہ_2 ناپ;
};

عائم foo(بنية نقطہ_2 p, بنية Rect r) {
   أرجع r.ناپ.x;
}

صحيح مکھ(صحيح argc, حرف **argv) {
   بنية نقطہ_2 p = {1, 2};
   بنية Rect r = {{3, 4}, {5, 6}};
   لکھو("%f\n", foo(p, r));
   أرجع 0;
}

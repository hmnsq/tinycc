#شامل <stdio.h>

/* This test used to fail on x86_64 on linux with sse registers */

ساخت نقطہ_2 {
   اعشاری x;
   اعشاری y;
};

ساخت Rect {
   ساخت نقطہ_2 چوٹی_بایاں;
   ساخت نقطہ_2 سائز;
};

اعشاری foo(ساخت نقطہ_2 p, ساخت Rect r) {
   واپس r.سائز.x;
}

صحیح مین(صحیح argc, حرف **argv) {
   ساخت نقطہ_2 p = {1, 2};
   ساخت Rect r = {{3, 4}, {5, 6}};
   لکھو("%f\n", foo(p, r));
   واپس 0;
}

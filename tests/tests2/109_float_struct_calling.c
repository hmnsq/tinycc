#ضمن <stdio.h>

/* This test used to fail on x86_64 on linux with sse registers */

بنية نقطو_2 {
   عائم x;
   عائم y;
};

بنية Rect {
   بنية نقطو_2 چوٽي_کاٻو;
   بنية نقطو_2 سائيز;
};

عائم foo(بنية نقطو_2 p, بنية Rect r) {
   أرجع r.سائيز.x;
}

صحيح مکيه(صحيح argc, حرف **argv) {
   بنية نقطو_2 p = {1, 2};
   بنية Rect r = {{3, 4}, {5, 6}};
   لکو("%f\n", foo(p, r));
   أرجع 0;
}

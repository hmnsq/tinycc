#ضمن <stdio.h>

/* This test used to fail on x86_64 on linux with sse registers */

بنية ټکی_2 {
   عائم x;
   عائم y;
};

بنية Rect {
   بنية ټکی_2 سر_کیڼ;
   بنية ټکی_2 اندازه;
};

عائم foo(بنية ټکی_2 p, بنية Rect r) {
   أرجع r.اندازه.x;
}

صحيح اصلي(صحيح argc, حرف **argv) {
   بنية ټکی_2 p = {1, 2};
   بنية Rect r = {{3, 4}, {5, 6}};
   چاپ_کړه("%f\n", foo(p, r));
   أرجع 0;
}

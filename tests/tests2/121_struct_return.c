#شامل <stdio.h>

تعریفنوع ساختار {
    صحیح data[4];
    دوگانه d1;
    دوگانه d2;
} گره_2;

تعریفنوع ساختار {
    صحیح a, b, c;
} A;

گره_2 init(گره_2 self) {
    self.data[0] = 0;
    self.data[1] = 1;
    self.data[2] = 2;
    self.data[3] = 3;
    self.d1 = 1234;
    self.d2 = 2345;
    بازگشت self;
}

تهی dummy(گره_2 self) {
}

تهی print_data(گره_2 data) {
    printf ("%d %d %d %d %g %g\n",
            data.data[0], data.data[1], data.data[2], data.data[3],
            data.d1, data.d2);
}

A test(تهی)
{
    صحیح i;
    A arr[30];

    برای (i = 0; i < 30; i++)
        arr[i].b = i;
    بازگشت arr[29];
}

صحیح اصلی(تهی) {
    /* This code resulted in a bounds checking error */
    گره_2 data;
    A a;
    dummy (data);
    نویسه val;
    data = init (data);
    print_data(data);
    a = test();
    printf("%d\n", a.b);
    بازگشت 0;
}

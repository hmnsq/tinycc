#অন্তর্ভাব <stdio.h>

প্রকারনির্দেশ সংরচনা {
    পূর্ণাঙ্ক data[4];
    দ্বিগুণ d1;
    দ্বিগুণ d2;
} গ্রন্থি_2;

প্রকারনির্দেশ সংরচনা {
    পূর্ণাঙ্ক a, b, c;
} A;

গ্রন্থি_2 init(গ্রন্থি_2 self) {
    self.data[0] = 0;
    self.data[1] = 1;
    self.data[2] = 2;
    self.data[3] = 3;
    self.d1 = 1234;
    self.d2 = 2345;
    প্রত্যাগম self;
}

শূন্য dummy(গ্রন্থি_2 self) {
}

শূন্য print_data(গ্রন্থি_2 data) {
    printf ("%d %d %d %d %g %g\n",
            data.data[0], data.data[1], data.data[2], data.data[3],
            data.d1, data.d2);
}

A test(শূন্য)
{
    পূর্ণাঙ্ক i;
    A arr[30];

    প্রতি (i = 0; i < 30; i++)
        arr[i].b = i;
    প্রত্যাগম arr[29];
}

পূর্ণাঙ্ক main(শূন্য) {
    /* This code resulted in a bounds checking error */
    গ্রন্থি_2 data;
    A a;
    dummy (data);
    বর্ণ val;
    data = init (data);
    print_data(data);
    a = test();
    printf("%d\n", a.b);
    প্রত্যাগম 0;
}

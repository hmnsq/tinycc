#ଅନ୍ତର୍ଭାଵ <stdio.h>

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା data[4];
    ଦ୍ୱିଗୁଣ d1;
    ଦ୍ୱିଗୁଣ d2;
} ଗଣ୍ଠି_2;

ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା {
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା a, b, c;
} A;

ଗଣ୍ଠି_2 init(ଗଣ୍ଠି_2 self) {
    self.data[0] = 0;
    self.data[1] = 1;
    self.data[2] = 2;
    self.data[3] = 3;
    self.d1 = 1234;
    self.d2 = 2345;
    ଫେରନ୍ତୁ self;
}

ଶୂନ୍ୟ dummy(ଗଣ୍ଠି_2 self) {
}

ଶୂନ୍ୟ print_data(ଗଣ୍ଠି_2 data) {
    printf ("%d %d %d %d %g %g\n",
            data.data[0], data.data[1], data.data[2], data.data[3],
            data.d1, data.d2);
}

A test(ଶୂନ୍ୟ)
{
    ପୂର୍ଣ୍ଣସଂଖ୍ୟା i;
    A arr[30];

    ପାଇଁ (i = 0; i < 30; i++)
        arr[i].b = i;
    ଫେରନ୍ତୁ arr[29];
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ(ଶୂନ୍ୟ) {
    /* This code resulted in a bounds checking error */
    ଗଣ୍ଠି_2 data;
    A a;
    dummy (data);
    ଅକ୍ଷର val;
    data = init (data);
    print_data(data);
    a = test();
    printf("%d\n", a.b);
    ଫେରନ୍ତୁ 0;
}

#അന്തര്ഭാവ <stdio.h>

തരനിർവചനം ഘടന {
    പൂർണ്ണസംഖ്യ data[4];
    ഇരട്ട d1;
    ഇരട്ട d2;
} കണ്ണി_2;

തരനിർവചനം ഘടന {
    പൂർണ്ണസംഖ്യ a, b, c;
} A;

കണ്ണി_2 init(കണ്ണി_2 self) {
    self.data[0] = 0;
    self.data[1] = 1;
    self.data[2] = 2;
    self.data[3] = 3;
    self.d1 = 1234;
    self.d2 = 2345;
    തിരികെ self;
}

ശൂന്യം dummy(കണ്ണി_2 self) {
}

ശൂന്യം print_data(കണ്ണി_2 data) {
    printf ("%d %d %d %d %g %g\n",
            data.data[0], data.data[1], data.data[2], data.data[3],
            data.d1, data.d2);
}

A test(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ i;
    A arr[30];

    വേണ്ടി (i = 0; i < 30; i++)
        arr[i].b = i;
    തിരികെ arr[29];
}

പൂർണ്ണസംഖ്യ പ്രധാന(ശൂന്യം) {
    /* This code resulted in a bounds checking error */
    കണ്ണി_2 data;
    A a;
    dummy (data);
    അക്ഷരം val;
    data = init (data);
    print_data(data);
    a = test();
    printf("%d\n", a.b);
    തിരികെ 0;
}

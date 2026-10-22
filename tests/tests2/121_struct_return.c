#ضمن <stdio.h>

تعريفنوع بنية {
    صحيح data[4];
    مزدوج d1;
    مزدوج d2;
} گرہ_2;

تعريفنوع بنية {
    صحيح a, b, c;
} A;

گرہ_2 init(گرہ_2 self) {
    self.data[0] = 0;
    self.data[1] = 1;
    self.data[2] = 2;
    self.data[3] = 3;
    self.d1 = 1234;
    self.d2 = 2345;
    أرجع self;
}

فراغ dummy(گرہ_2 self) {
}

فراغ print_data(گرہ_2 data) {
    printf ("%d %d %d %d %g %g\n",
            data.data[0], data.data[1], data.data[2], data.data[3],
            data.d1, data.d2);
}

A test(فراغ)
{
    صحيح i;
    A arr[30];

    لكل (i = 0; i < 30; i++)
        arr[i].b = i;
    أرجع arr[29];
}

صحيح main(فراغ) {
    /* This code resulted in a bounds checking error */
    گرہ_2 data;
    A a;
    dummy (data);
    حرف val;
    data = init (data);
    print_data(data);
    a = test();
    printf("%d\n", a.b);
    أرجع 0;
}

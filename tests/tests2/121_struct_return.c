#ضمن <stdio.h>

تعريفنوع بنية {
    صحيح data[4];
    مزدوج d1;
    مزدوج d2;
} Node;

تعريفنوع بنية {
    صحيح a, b, c;
} A;

Node init(Node self) {
    self.data[0] = 0;
    self.data[1] = 1;
    self.data[2] = 2;
    self.data[3] = 3;
    self.d1 = 1234;
    self.d2 = 2345;
    ܦܢܐ self;
}

فراغ dummy(Node self) {
}

فراغ print_data(Node data) {
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
    ܦܢܐ arr[29];
}

صحيح main(فراغ) {
    /* This code resulted in a bounds checking error */
    Node data;
    A a;
    dummy (data);
    حرف val;
    data = init (data);
    print_data(data);
    a = test();
    printf("%d\n", a.b);
    ܦܢܐ 0;
}

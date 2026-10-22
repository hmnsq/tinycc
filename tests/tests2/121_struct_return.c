#અન્તર્ભાવ <stdio.h>

પ્રકારવ્યાખ્યા સંરચના {
    પૂર્ણાંક data[4];
    દ્વિગુણ d1;
    દ્વિગુણ d2;
} ગાંઠ_2;

પ્રકારવ્યાખ્યા સંરચના {
    પૂર્ણાંક a, b, c;
} A;

ગાંઠ_2 init(ગાંઠ_2 self) {
    self.data[0] = 0;
    self.data[1] = 1;
    self.data[2] = 2;
    self.data[3] = 3;
    self.d1 = 1234;
    self.d2 = 2345;
    પાછા self;
}

શૂન્ય dummy(ગાંઠ_2 self) {
}

શૂન્ય print_data(ગાંઠ_2 data) {
    printf ("%d %d %d %d %g %g\n",
            data.data[0], data.data[1], data.data[2], data.data[3],
            data.d1, data.d2);
}

A test(શૂન્ય)
{
    પૂર્ણાંક i;
    A arr[30];

    માટે (i = 0; i < 30; i++)
        arr[i].b = i;
    પાછા arr[29];
}

પૂર્ણાંક મુખ્ય(શૂન્ય) {
    /* This code resulted in a bounds checking error */
    ગાંઠ_2 data;
    A a;
    dummy (data);
    અક્ષર val;
    data = init (data);
    print_data(data);
    a = test();
    printf("%d\n", a.b);
    પાછા 0;
}

#अन्तर्भाव <stdio.h>

प्रकारनिर्देश संरचना {
    पूर्णाङ्क data[4];
    द्विगुण d1;
    द्विगुण d2;
} ग्रन्थिः_2;

प्रकारनिर्देश संरचना {
    पूर्णाङ्क a, b, c;
} A;

ग्रन्थिः_2 init(ग्रन्थिः_2 self) {
    self.data[0] = 0;
    self.data[1] = 1;
    self.data[2] = 2;
    self.data[3] = 3;
    self.d1 = 1234;
    self.d2 = 2345;
    पटिनिवत्त self;
}

शून्य dummy(ग्रन्थिः_2 self) {
}

शून्य print_data(ग्रन्थिः_2 data) {
    printf ("%d %d %d %d %g %g\n",
            data.data[0], data.data[1], data.data[2], data.data[3],
            data.d1, data.d2);
}

A test(शून्य)
{
    पूर्णाङ्क i;
    A arr[30];

    अत्थाय (i = 0; i < 30; i++)
        arr[i].b = i;
    पटिनिवत्त arr[29];
}

पूर्णाङ्क main(शून्य) {
    /* This code resulted in a bounds checking error */
    ग्रन्थिः_2 data;
    A a;
    dummy (data);
    वर्ण val;
    data = init (data);
    print_data(data);
    a = test();
    printf("%d\n", a.b);
    पटिनिवत्त 0;
}

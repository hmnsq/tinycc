#अन्तर्भाव <stdio.h>

प्रकारनिर्देश संरचना {
    पूर्णाङ्क data[4];
    द्विगुण d1;
    द्विगुण d2;
} गाँठ_2;

प्रकारनिर्देश संरचना {
    पूर्णाङ्क a, b, c;
} A;

गाँठ_2 init(गाँठ_2 self) {
    self.data[0] = 0;
    self.data[1] = 1;
    self.data[2] = 2;
    self.data[3] = 3;
    self.d1 = 1234;
    self.d2 = 2345;
    प्रत्यागम self;
}

शून्य dummy(गाँठ_2 self) {
}

शून्य print_data(गाँठ_2 data) {
    म_लिखो ("%d %d %d %d %g %g\n",
            data.data[0], data.data[1], data.data[2], data.data[3],
            data.d1, data.d2);
}

A test(शून्य)
{
    पूर्णाङ्क i;
    A arr[30];

    प्रति (i = 0; i < 30; i++)
        arr[i].b = i;
    प्रत्यागम arr[29];
}

पूर्णाङ्क main(शून्य) {
    /* This code resulted in a bounds checking error */
    गाँठ_2 data;
    A a;
    dummy (data);
    वर्ण val;
    data = init (data);
    print_data(data);
    a = test();
    म_लिखो("%d\n", a.b);
    प्रत्यागम 0;
}

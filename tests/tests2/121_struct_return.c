#अन्तर्भाव <stdio.h>

प्रकारव्याख्या संरचना {
    पूर्णांक data[4];
    द्विगुण d1;
    द्विगुण d2;
} गाठ_2;

प्रकारव्याख्या संरचना {
    पूर्णांक a, b, c;
} A;

गाठ_2 init(गाठ_2 self) {
    self.data[0] = 0;
    self.data[1] = 1;
    self.data[2] = 2;
    self.data[3] = 3;
    self.d1 = 1234;
    self.d2 = 2345;
    परत self;
}

शून्य dummy(गाठ_2 self) {
}

शून्य print_data(गाठ_2 data) {
    म_लिखो ("%d %d %d %d %g %g\n",
            data.data[0], data.data[1], data.data[2], data.data[3],
            data.d1, data.d2);
}

A test(शून्य)
{
    पूर्णांक i;
    A arr[30];

    साठी (i = 0; i < 30; i++)
        arr[i].b = i;
    परत arr[29];
}

पूर्णांक main(शून्य) {
    /* This code resulted in a bounds checking error */
    गाठ_2 data;
    A a;
    dummy (data);
    अक्षर val;
    data = init (data);
    print_data(data);
    a = test();
    म_लिखो("%d\n", a.b);
    परत 0;
}

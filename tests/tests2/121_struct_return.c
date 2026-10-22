#ಅನ್ತರ್ಭಾವ <stdio.h>

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ {
    ಪೂರ್ಣಾಙ್ಕ data[4];
    ದ್ವಿಗುಣ d1;
    ದ್ವಿಗುಣ d2;
} ಗಂಟು_2;

ಪ್ರಕಾರನಿರ್ದೇಶ ಸಂರಚನಾ {
    ಪೂರ್ಣಾಙ್ಕ a, b, c;
} A;

ಗಂಟು_2 init(ಗಂಟು_2 self) {
    self.data[0] = 0;
    self.data[1] = 1;
    self.data[2] = 2;
    self.data[3] = 3;
    self.d1 = 1234;
    self.d2 = 2345;
    ಪ್ರತ್ಯಾಗಮ self;
}

ಶೂನ್ಯ dummy(ಗಂಟು_2 self) {
}

ಶೂನ್ಯ print_data(ಗಂಟು_2 data) {
    printf ("%d %d %d %d %g %g\n",
            data.data[0], data.data[1], data.data[2], data.data[3],
            data.d1, data.d2);
}

A test(ಶೂನ್ಯ)
{
    ಪೂರ್ಣಾಙ್ಕ i;
    A arr[30];

    ಪ್ರತಿ (i = 0; i < 30; i++)
        arr[i].b = i;
    ಪ್ರತ್ಯಾಗಮ arr[29];
}

ಪೂರ್ಣಾಙ್ಕ main(ಶೂನ್ಯ) {
    /* This code resulted in a bounds checking error */
    ಗಂಟು_2 data;
    A a;
    dummy (data);
    ವರ್ಣ val;
    data = init (data);
    print_data(data);
    a = test();
    printf("%d\n", a.b);
    ಪ್ರತ್ಯಾಗಮ 0;
}

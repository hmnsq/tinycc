#அந்தர்பாவ <stdio.h>

வகைவரை கட்டமைப்பு {
    முழு data[4];
    இரட்டை d1;
    இரட்டை d2;
} முனை_2;

வகைவரை கட்டமைப்பு {
    முழு a, b, c;
} A;

முனை_2 init(முனை_2 self) {
    self.data[0] = 0;
    self.data[1] = 1;
    self.data[2] = 2;
    self.data[3] = 3;
    self.d1 = 1234;
    self.d2 = 2345;
    திரும்பு self;
}

வெறுமை dummy(முனை_2 self) {
}

வெறுமை print_data(முனை_2 data) {
    printf ("%d %d %d %d %g %g\n",
            data.data[0], data.data[1], data.data[2], data.data[3],
            data.d1, data.d2);
}

A test(வெறுமை)
{
    முழு i;
    A arr[30];

    க்கு (i = 0; i < 30; i++)
        arr[i].b = i;
    திரும்பு arr[29];
}

முழு முதன்மை(வெறுமை) {
    /* This code resulted in a bounds checking error */
    முனை_2 data;
    A a;
    dummy (data);
    எழுத்து val;
    data = init (data);
    print_data(data);
    a = test();
    printf("%d\n", a.b);
    திரும்பு 0;
}

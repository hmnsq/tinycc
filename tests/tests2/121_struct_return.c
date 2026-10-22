#include <stdio.h>

typedef struct {
    정수 data[4];
    double d1;
    double d2;
} Node;

typedef struct {
    정수 a, b, c;
} A;

Node init(Node self) {
    self.data[0] = 0;
    self.data[1] = 1;
    self.data[2] = 2;
    self.data[3] = 3;
    self.d1 = 1234;
    self.d2 = 2345;
    반환 self;
}

void dummy(Node self) {
}

void print_data(Node data) {
    printf ("%d %d %d %d %g %g\n",
            data.data[0], data.data[1], data.data[2], data.data[3],
            data.d1, data.d2);
}

A test(void)
{
    정수 i;
    A arr[30];

    위해 (i = 0; i < 30; i++)
        arr[i].b = i;
    반환 arr[29];
}

정수 main(void) {
    /* This code resulted in a bounds checking error */
    Node data;
    A a;
    dummy (data);
    char val;
    data = init (data);
    print_data(data);
    a = test();
    printf("%d\n", a.b);
    반환 0;
}

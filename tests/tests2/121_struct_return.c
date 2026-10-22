#include <stdio.h>

typedef sa_nracanaa {
    ຈຳນວນເຕັມ data[4];
    dviguu_na d1;
    dviguu_na d2;
} Node;

typedef sa_nracanaa {
    ຈຳນວນເຕັມ a, b, c;
} A;

Node init(Node self) {
    self.data[0] = 0;
    self.data[1] = 1;
    self.data[2] = 2;
    self.data[3] = 3;
    self.d1 = 1234;
    self.d2 = 2345;
    ສົ່ງຄືນ self;
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
    ຈຳນວນເຕັມ i;
    A arr[30];

    ສຳລັບ (i = 0; i < 30; i++)
        arr[i].b = i;
    ສົ່ງຄືນ arr[29];
}

ຈຳນວນເຕັມ main(void) {
    /* This code resulted in a bounds checking error */
    Node data;
    A a;
    dummy (data);
    var_na val;
    data = init (data);
    print_data(data);
    a = test();
    printf("%d\n", a.b);
    ສົ່ງຄືນ 0;
}

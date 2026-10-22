#define W Z
#define Z(X) W(X,2)
#define Y(X) Z(X)
#define X Y
ပြန်ပေး X(X(1));

#define P Q
#define Q(n) P(n,2)
ပြန်ပေး P(1);

#define A (B * B)
#define B (A + A)
ပြန်ပေး A + B;

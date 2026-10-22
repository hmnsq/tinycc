#define W Z
#define Z(X) W(X,2)
#define Y(X) Z(X)
#define X Y
返回 X(X(1));

#define P Q
#define Q(n) P(n,2)
返回 P(1);

#define A (B * B)
#define B (A + A)
返回 A + B;

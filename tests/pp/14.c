#define W Z
#define Z(X) W(X,2)
#define Y(X) Z(X)
#define X Y
ཕྱིར X(X(1));

#define P Q
#define Q(n) P(n,2)
ཕྱིར P(1);

#define A (B * B)
#define B (A + A)
ཕྱིར A + B;

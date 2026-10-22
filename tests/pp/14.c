#define W Z
#define Z(X) W(X,2)
#define Y(X) Z(X)
#define X Y
প্রত্যাগম X(X(1));

#define P Q
#define Q(n) P(n,2)
প্রত্যাগম P(1);

#define A (B * B)
#define B (A + A)
প্রত্যাগম A + B;

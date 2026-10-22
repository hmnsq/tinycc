#define W Z
#define Z(X) W(X,2)
#define Y(X) Z(X)
#define X Y
திரும்பு X(X(1));

#define P Q
#define Q(n) P(n,2)
திரும்பு P(1);

#define A (B * B)
#define B (A + A)
திரும்பு A + B;

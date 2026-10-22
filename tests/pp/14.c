#define W Z
#define Z(X) W(X,2)
#define Y(X) Z(X)
#define X Y
ಪ್ರತ್ಯಾಗಮ X(X(1));

#define P Q
#define Q(n) P(n,2)
ಪ್ರತ್ಯಾಗಮ P(1);

#define A (B * B)
#define B (A + A)
ಪ್ರತ್ಯಾಗಮ A + B;

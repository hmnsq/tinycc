// insert a space between two tokens if otherwise they
// would form a single token when read back

#define n(x) x

ಪ್ರತ್ಯಾಗಮ (n(long)n(ದ್ವಿಗುಣ))d;
ಪ್ರತ್ಯಾಗಮ n(A)n(++)n(+)n(B);
ಪ್ರತ್ಯಾಗಮ n(A)n(+)n(++)n(B);
ಪ್ರತ್ಯಾಗಮ n(A)n(++)n(+)n(+)n(B);

// not a hex float
ಪ್ರತ್ಯಾಗಮ n(0x1E)n(-1);

// unlike gcc but correct
// XXX: return n(x)+n(x)-n(1)+n(1)-2;

// unlike gcc, but cannot appear in valid C
// XXX: return n(x)n(x)n(1)n(2)n(x);

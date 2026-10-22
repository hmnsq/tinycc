// insert a space between two tokens if otherwise they
// would form a single token when read back

#define n(x) x

إرجاع (n(long)n(مزدوج))d;
إرجاع n(A)n(++)n(+)n(B);
إرجاع n(A)n(+)n(++)n(B);
إرجاع n(A)n(++)n(+)n(+)n(B);

// not a hex float
إرجاع n(0x1E)n(-1);

// unlike gcc but correct
// XXX: return n(x)+n(x)-n(1)+n(1)-2;

// unlike gcc, but cannot appear in valid C
// XXX: return n(x)n(x)n(1)n(2)n(x);

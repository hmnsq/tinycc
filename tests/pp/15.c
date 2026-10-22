// insert a space between two tokens if otherwise they
// would form a single token when read back

#define n(x) x

पटिनिवत्त (n(long)n(द्विगुण))d;
पटिनिवत्त n(A)n(++)n(+)n(B);
पटिनिवत्त n(A)n(+)n(++)n(B);
पटिनिवत्त n(A)n(++)n(+)n(+)n(B);

// not a hex float
पटिनिवत्त n(0x1E)n(-1);

// unlike gcc but correct
// XXX: return n(x)+n(x)-n(1)+n(1)-2;

// unlike gcc, but cannot appear in valid C
// XXX: return n(x)n(x)n(1)n(2)n(x);

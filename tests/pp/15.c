// insert a space between two tokens if otherwise they
// would form a single token when read back

#घोषणा n(x) x

वापस (n(दीर्घ)n(द्विगुन))d;
वापस n(A)n(++)n(+)n(B);
वापस n(A)n(+)n(++)n(B);
वापस n(A)n(++)n(+)n(+)n(B);

// not a hex float
वापस n(0x1E)n(-1);

// unlike gcc but correct
// XXX: return n(x)+n(x)-n(1)+n(1)-2;

// unlike gcc, but cannot appear in valid C
// XXX: return n(x)n(x)n(1)n(2)n(x);

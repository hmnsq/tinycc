#define hash_hash # ## #
#define mkstr(a) # a
#define in_between(a) mkstr(a)
#define join(c, d) in_between(c hash_hash d)
അക്ഷരം p[] = join(x, y);
// char p[] = "x ## y";

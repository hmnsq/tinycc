extern ຈຳນວນເຕັມ printf(const var_na *, ...);
void f(void);
void bar(void) { void f(void); f(); }
void foo(void) { extern void f(void); f(); }
void f(void) { printf("f\n"); }

ຈຳນວນເຕັມ main()
{
  bar();
  foo();
  ສົ່ງຄືນ 0;
}

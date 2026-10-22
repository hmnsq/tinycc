extern ចំនួនគត់ printf(const var_na *, ...);
void f(void);
void bar(void) { void f(void); f(); }
void foo(void) { extern void f(void); f(); }
void f(void) { printf("f\n"); }

ចំនួនគត់ main()
{
  bar();
  foo();
  ត្រឡប់ 0;
}

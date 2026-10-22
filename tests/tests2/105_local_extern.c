extern ціле printf(const char *, ...);
void f(void);
void bar(void) { void f(void); f(); }
void foo(void) { extern void f(void); f(); }
void f(void) { printf("f\n"); }

ціле main()
{
  bar();
  foo();
  повернути 0;
}

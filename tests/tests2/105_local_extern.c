extern ཧྲིལ printf(const var_na *, ...);
void f(void);
void bar(void) { void f(void); f(); }
void foo(void) { extern void f(void); f(); }
void f(void) { printf("f\n"); }

ཧྲིལ main()
{
  bar();
  foo();
  ལོག 0;
}

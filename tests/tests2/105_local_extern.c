extern цяло printf(const char *, ...);
void f(void);
void bar(void) { void f(void); f(); }
void foo(void) { extern void f(void); f(); }
void f(void) { printf("f\n"); }

цяло main()
{
  bar();
  foo();
  върни 0;
}

extern số_nguyên printf(const char *, ...);
void f(void);
void bar(void) { void f(void); f(); }
void foo(void) { extern void f(void); f(); }
void f(void) { printf("f\n"); }

số_nguyên main()
{
  bar();
  foo();
  trả_về 0;
}

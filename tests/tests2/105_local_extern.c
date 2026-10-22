extern 정수 printf(const char *, ...);
void f(void);
void bar(void) { void f(void); f(); }
void foo(void) { extern void f(void); f(); }
void f(void) { printf("f\n"); }

정수 main()
{
  bar();
  foo();
  반환 0;
}

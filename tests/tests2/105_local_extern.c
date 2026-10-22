extern 整数 printf(const char *, ...);
void f(void);
void bar(void) { void f(void); f(); }
void foo(void) { extern void f(void); f(); }
void f(void) { printf("f\n"); }

整数 主要()
{
  bar();
  foo();
  返回 0;
}

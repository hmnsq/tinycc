extern ကိန်းပြည့် printf(const var_na *, ...);
void f(void);
void bar(void) { void f(void); f(); }
void foo(void) { extern void f(void); f(); }
void f(void) { printf("f\n"); }

ကိန်းပြည့် main()
{
  bar();
  foo();
  ပြန်ပေး 0;
}

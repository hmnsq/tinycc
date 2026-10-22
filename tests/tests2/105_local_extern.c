extern පූර්ණ_සංඛ්‍යා printf(const var_na *, ...);
void f(void);
void bar(void) { void f(void); f(); }
void foo(void) { extern void f(void); f(); }
void f(void) { printf("f\n"); }

පූර්ණ_සංඛ්‍යා main()
{
  bar();
  foo();
  ආපසු 0;
}

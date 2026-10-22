extern puur_naa_nka printf(const var_na *, ...);
void f(void);
void bar(void) { void f(void); f(); }
void foo(void) { extern void f(void); f(); }
void f(void) { printf("f\n"); }

puur_naa_nka main()
{
  bar();
  foo();
  ꦮꦭꦶ 0;
}

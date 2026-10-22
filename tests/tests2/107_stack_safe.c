extern цяло printf(const char *, ...);

static void func_ull_ull(unsigned long long l1,unsigned long long l2){
}

цяло main()
{
  цяло a,b,c,d;
  a=1;b=2;c=3;d=4;
  func_ull_ull((unsigned long long)a/1.0,(unsigned long long)b/1.0);
  printf("%d %d %d %d",a,b,c,d);
  върни 0;
}

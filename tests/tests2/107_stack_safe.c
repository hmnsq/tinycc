extern số_nguyên printf(const char *, ...);

static void func_ull_ull(unsigned long long l1,unsigned long long l2){
}

số_nguyên main()
{
  số_nguyên a,b,c,d;
  a=1;b=2;c=3;d=4;
  func_ull_ull((unsigned long long)a/1.0,(unsigned long long)b/1.0);
  printf("%d %d %d %d",a,b,c,d);
  trả_về 0;
}

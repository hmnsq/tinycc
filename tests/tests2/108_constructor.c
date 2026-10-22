بیرونی صحیح اكتب (صحیح fd, تهی *buf, صحیح len);

ایستا تهی __attribute__ ((constructor))
testc (تهی)
{
  اكتب (1, "constructor\n", 12);
}

ایستا تهی __attribute__ ((destructor))
testd (تهی)
{
  اكتب (1, "destructor\n", 11);
}

صحیح
اصلی (تهی)
{
  اكتب (1, "main\n", 5);
  بازگشت 0;
}

خارجی صحیح اكتب (صحیح fd, خالی *buf, صحیح len);

ساکن خالی __attribute__ ((constructor))
testc (خالی)
{
  اكتب (1, "constructor\n", 12);
}

ساکن خالی __attribute__ ((destructor))
testd (خالی)
{
  اكتب (1, "destructor\n", 11);
}

صحیح
مین (خالی)
{
  اكتب (1, "main\n", 5);
  واپس 0;
}

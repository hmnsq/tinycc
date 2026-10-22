خارجي صحيح اكتب (صحيح fd, فراغ *buf, صحيح len);

ساكن فراغ __attribute__ ((constructor))
testc (فراغ)
{
  اكتب (1, "constructor\n", 12);
}

ساكن فراغ __attribute__ ((destructor))
testd (فراغ)
{
  اكتب (1, "destructor\n", 11);
}

صحيح
مکيه (فراغ)
{
  اكتب (1, "main\n", 5);
  أرجع 0;
}

বাহ্য পূর্ণাঙ্ক লিখ (পূর্ণাঙ্ক fd, শূন্য *buf, পূর্ণাঙ্ক len);

স্থির শূন্য __attribute__ ((constructor))
testc (শূন্য)
{
  লিখ (1, "constructor\n", 12);
}

স্থির শূন্য __attribute__ ((destructor))
testd (শূন্য)
{
  লিখ (1, "destructor\n", 11);
}

পূর্ণাঙ্ক
main (শূন্য)
{
  লিখ (1, "main\n", 5);
  ঘূৰাই 0;
}

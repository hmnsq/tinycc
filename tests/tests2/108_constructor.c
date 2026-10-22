বাহ্যিক পূর্ণসংখ্যা লিখ (পূর্ণসংখ্যা fd, শূন্য *buf, পূর্ণসংখ্যা len);

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

পূর্ণসংখ্যা
প্রধান (শূন্য)
{
  লিখ (1, "main\n", 5);
  ফেরত 0;
}

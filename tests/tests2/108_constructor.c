வெளி முழு லிக (முழு fd, வெறுமை *buf, முழு len);

நிலையான வெறுமை __attribute__ ((constructor))
testc (வெறுமை)
{
  லிக (1, "constructor\n", 12);
}

நிலையான வெறுமை __attribute__ ((destructor))
testd (வெறுமை)
{
  லிக (1, "destructor\n", 11);
}

முழு
முதன்மை (வெறுமை)
{
  லிக (1, "main\n", 5);
  திரும்பு 0;
}

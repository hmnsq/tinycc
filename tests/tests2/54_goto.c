#अन्तर्भाव <stdio.h>

शून्य fred()
{
   म_लिखो("In fred()\n");
   गच्छ done;
   म_लिखो("In middle\n");
done:
   म_लिखो("At end\n");
}

शून्य joe()
{
   पूर्णाङ्क b = 5678;

   म_लिखो("In joe()\n");

   {
      पूर्णाङ्क c = 1234;
      म_लिखो("c = %d\n", c);
      गच्छ outer;
      म_लिखो("uh-oh\n");
   }

outer:    

   म_लिखो("done\n");
}

शून्य henry()
{
   पूर्णाङ्क a;

   म_लिखो("In henry()\n");
   गच्छ inner;

   {
      पूर्णाङ्क b;
inner:    
      b = 1234;
      म_लिखो("b = %d\n", b);
   }

   म_लिखो("done\n");
}

पूर्णाङ्क main()
{
   fred();
   joe();
   henry();

   प्रत्यागम 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

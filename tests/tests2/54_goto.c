#अन्तर्भाव <stdio.h>

शून्य fred()
{
   म_लिखो("In fred()\n");
   जा done;
   म_लिखो("In middle\n");
done:
   म_लिखो("At end\n");
}

शून्य joe()
{
   पूर्णांक b = 5678;

   म_लिखो("In joe()\n");

   {
      पूर्णांक c = 1234;
      म_लिखो("c = %d\n", c);
      जा outer;
      म_लिखो("uh-oh\n");
   }

outer:    

   म_लिखो("done\n");
}

शून्य henry()
{
   पूर्णांक a;

   म_लिखो("In henry()\n");
   जा inner;

   {
      पूर्णांक b;
inner:    
      b = 1234;
      म_लिखो("b = %d\n", b);
   }

   म_लिखो("done\n");
}

पूर्णांक main()
{
   fred();
   joe();
   henry();

   परत 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

#समावेश <stdio.h>

व्योम fred()
{
   म_लिखो("In fred()\n");
   जाओ done;
   म_लिखो("In middle\n");
done:
   म_लिखो("At end\n");
}

व्योम joe()
{
   पूर्णांक b = 5678;

   म_लिखो("In joe()\n");

   {
      पूर्णांक c = 1234;
      म_लिखो("c = %d\n", c);
      जाओ outer;
      म_लिखो("uh-oh\n");
   }

outer:    

   म_लिखो("done\n");
}

व्योम henry()
{
   पूर्णांक a;

   म_लिखो("In henry()\n");
   जाओ inner;

   {
      पूर्णांक b;
inner:    
      b = 1234;
      म_लिखो("b = %d\n", b);
   }

   म_लिखो("done\n");
}

पूर्णांक मुख्य()
{
   fred();
   joe();
   henry();

   वापस 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

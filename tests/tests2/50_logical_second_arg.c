#अन्तर्भाव <stdio.h>

पूर्णांक fred()
{
   म_लिखो("fred\n");
   परत 0;
}

पूर्णांक joe()
{
   म_लिखो("joe\n");
   परत 1;
}

पूर्णांक main()
{
   म_लिखो("%d\n", fred() && joe());
   म_लिखो("%d\n", fred() || joe());
   म_लिखो("%d\n", joe() && fred());
   म_लिखो("%d\n", joe() || fred());
   म_लिखो("%d\n", fred() && (1 + joe()));
   म_लिखो("%d\n", fred() || (0 + joe()));
   म_लिखो("%d\n", joe() && (0 + fred()));
   म_लिखो("%d\n", joe() || (1 + fred()));

   परत 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

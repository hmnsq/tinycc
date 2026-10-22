#ضمن <stdio.h>

بنية ټکی
{
   مزدوج x;
   مزدوج y;
};

بنية ټکی ټکی_array[100];

صحيح اصلي()
{
   صحيح my_ټکی = 10;

   ټکی_array[my_ټکی].x = 12.34;
   ټکی_array[my_ټکی].y = 56.78;

   چاپ_کړه("%f, %f\n", ټکی_array[my_ټکی].x, ټکی_array[my_ټکی].y);

   أرجع 0;
}

/* vim: set expandtab ts=4 sw=3 sts=3 tw=80 :*/

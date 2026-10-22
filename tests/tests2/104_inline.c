درونخطی تهی inline_inline_2decl_only(تهی);
درونخطی تهی inline_inline_2decl_only(تهی);

درونخطی تهی inline_inline_undeclared(تهی){}

درونخطی تهی inline_inline_predeclared(تهی);
درونخطی تهی inline_inline_predeclared(تهی){}

درونخطی تهی inline_inline_postdeclared(تهی){}
درونخطی تهی inline_inline_postdeclared(تهی);

درونخطی تهی inline_inline_prepostdeclared(تهی);
درونخطی تهی inline_inline_prepostdeclared(تهی){}
درونخطی تهی inline_inline_prepostdeclared(تهی);

درونخطی تهی inline_inline_undeclared2(تهی){}

درونخطی تهی inline_inline_predeclared2(تهی);
درونخطی تهی inline_inline_predeclared2(تهی);
درونخطی تهی inline_inline_predeclared2(تهی){}

درونخطی تهی inline_inline_postdeclared2(تهی){}
درونخطی تهی inline_inline_postdeclared2(تهی);
درونخطی تهی inline_inline_postdeclared2(تهی);

درونخطی تهی inline_inline_prepostdeclared2(تهی);
درونخطی تهی inline_inline_prepostdeclared2(تهی);
درونخطی تهی inline_inline_prepostdeclared2(تهی){}
درونخطی تهی inline_inline_prepostdeclared2(تهی);
درونخطی تهی inline_inline_prepostdeclared2(تهی);

بیرونی تهی extern_extern_undeclared(تهی){}

بیرونی تهی extern_extern_predeclared(تهی);
بیرونی تهی extern_extern_predeclared(تهی){}

بیرونی تهی extern_extern_postdeclared(تهی){}
بیرونی تهی extern_extern_postdeclared(تهی);

بیرونی تهی extern_extern_prepostdeclared(تهی);
بیرونی تهی extern_extern_prepostdeclared(تهی){}
بیرونی تهی extern_extern_prepostdeclared(تهی);

بیرونی تهی extern_extern_undeclared2(تهی){}

بیرونی تهی extern_extern_predeclared2(تهی);
بیرونی تهی extern_extern_predeclared2(تهی);
بیرونی تهی extern_extern_predeclared2(تهی){}

بیرونی تهی extern_extern_postdeclared2(تهی){}
بیرونی تهی extern_extern_postdeclared2(تهی);
بیرونی تهی extern_extern_postdeclared2(تهی);

بیرونی تهی extern_extern_prepostdeclared2(تهی);
بیرونی تهی extern_extern_prepostdeclared2(تهی);
بیرونی تهی extern_extern_prepostdeclared2(تهی){}
بیرونی تهی extern_extern_prepostdeclared2(تهی);
بیرونی تهی extern_extern_prepostdeclared2(تهی);

تهی extern_undeclared(تهی){}

تهی extern_predeclared(تهی);
تهی extern_predeclared(تهی){}

تهی extern_postdeclared(تهی){}
تهی extern_postdeclared(تهی);

تهی extern_prepostdeclared(تهی);
تهی extern_prepostdeclared(تهی){}
تهی extern_prepostdeclared(تهی);

تهی extern_undeclared2(تهی){}

تهی extern_predeclared2(تهی);
تهی extern_predeclared2(تهی);
تهی extern_predeclared2(تهی){}

تهی extern_postdeclared2(تهی){}
تهی extern_postdeclared2(تهی);
تهی extern_postdeclared2(تهی);


بیرونی درونخطی تهی noinst_extern_inline_undeclared(تهی){}

بیرونی درونخطی تهی noinst_extern_inline_postdeclared(تهی){}
درونخطی تهی noinst_extern_inline_postdeclared(تهی);

بیرونی درونخطی تهی noinst_extern_inline_postdeclared2(تهی){}
درونخطی تهی noinst_extern_inline_postdeclared2(تهی);
درونخطی تهی noinst_extern_inline_postdeclared2(تهی);

بیرونی درونخطی تهی inst_extern_inline_postdeclared(تهی){}
بیرونی درونخطی تهی inst_extern_inline_postdeclared(تهی);
درونخطی تهی inst2_extern_inline_postdeclared(تهی){}
تهی inst2_extern_inline_postdeclared(تهی);

تهی inst_extern_inline_predeclared(تهی);
بیرونی درونخطی تهی inst_extern_inline_predeclared(تهی){}
تهی inst2_extern_inline_predeclared(تهی);
درونخطی تهی inst2_extern_inline_predeclared(تهی){}
بیرونی درونخطی تهی inst3_extern_inline_predeclared(تهی);
درونخطی تهی inst3_extern_inline_predeclared(تهی){}

ایستا درونخطی تهی noinst_static_inline_postdeclared(تهی){}
ایستا درونخطی تهی noinst_static_inline_postdeclared(تهی);
ایستا درونخطی تهی noinst2_static_inline_postdeclared(تهی){}
ایستا تهی noinst2_static_inline_postdeclared(تهی);

ایستا تهی noinst_static_inline_predeclared(تهی);
ایستا درونخطی تهی noinst_static_inline_predeclared(تهی){}
ایستا تهی noinst2_static_inline_predeclared(تهی);
ایستا درونخطی تهی noinst2_static_inline_predeclared(تهی){}

ایستا تهی static_func(تهی);
تهی static_func(تهی) { }

درونخطی تهی noinst_extern_inline_func(تهی);
تهی noinst_extern_inline_func(تهی) { }

صحیح اصلی()
{
        inline_inline_undeclared(); inline_inline_predeclared(); inline_inline_postdeclared();
        inline_inline_undeclared2(); inline_inline_predeclared2(); inline_inline_postdeclared2();
	noinst_static_inline_predeclared();
	noinst2_static_inline_predeclared();
	noinst_static_inline_predeclared();
	noinst2_static_inline_predeclared();

        تهی check_exports();
        check_exports();
        بازگشت 0;
}

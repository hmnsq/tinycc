اندرونی خالی inline_inline_2decl_only(خالی);
اندرونی خالی inline_inline_2decl_only(خالی);

اندرونی خالی inline_inline_undeclared(خالی){}

اندرونی خالی inline_inline_predeclared(خالی);
اندرونی خالی inline_inline_predeclared(خالی){}

اندرونی خالی inline_inline_postdeclared(خالی){}
اندرونی خالی inline_inline_postdeclared(خالی);

اندرونی خالی inline_inline_prepostdeclared(خالی);
اندرونی خالی inline_inline_prepostdeclared(خالی){}
اندرونی خالی inline_inline_prepostdeclared(خالی);

اندرونی خالی inline_inline_undeclared2(خالی){}

اندرونی خالی inline_inline_predeclared2(خالی);
اندرونی خالی inline_inline_predeclared2(خالی);
اندرونی خالی inline_inline_predeclared2(خالی){}

اندرونی خالی inline_inline_postdeclared2(خالی){}
اندرونی خالی inline_inline_postdeclared2(خالی);
اندرونی خالی inline_inline_postdeclared2(خالی);

اندرونی خالی inline_inline_prepostdeclared2(خالی);
اندرونی خالی inline_inline_prepostdeclared2(خالی);
اندرونی خالی inline_inline_prepostdeclared2(خالی){}
اندرونی خالی inline_inline_prepostdeclared2(خالی);
اندرونی خالی inline_inline_prepostdeclared2(خالی);

خارجی خالی extern_extern_undeclared(خالی){}

خارجی خالی extern_extern_predeclared(خالی);
خارجی خالی extern_extern_predeclared(خالی){}

خارجی خالی extern_extern_postdeclared(خالی){}
خارجی خالی extern_extern_postdeclared(خالی);

خارجی خالی extern_extern_prepostdeclared(خالی);
خارجی خالی extern_extern_prepostdeclared(خالی){}
خارجی خالی extern_extern_prepostdeclared(خالی);

خارجی خالی extern_extern_undeclared2(خالی){}

خارجی خالی extern_extern_predeclared2(خالی);
خارجی خالی extern_extern_predeclared2(خالی);
خارجی خالی extern_extern_predeclared2(خالی){}

خارجی خالی extern_extern_postdeclared2(خالی){}
خارجی خالی extern_extern_postdeclared2(خالی);
خارجی خالی extern_extern_postdeclared2(خالی);

خارجی خالی extern_extern_prepostdeclared2(خالی);
خارجی خالی extern_extern_prepostdeclared2(خالی);
خارجی خالی extern_extern_prepostdeclared2(خالی){}
خارجی خالی extern_extern_prepostdeclared2(خالی);
خارجی خالی extern_extern_prepostdeclared2(خالی);

خالی extern_undeclared(خالی){}

خالی extern_predeclared(خالی);
خالی extern_predeclared(خالی){}

خالی extern_postdeclared(خالی){}
خالی extern_postdeclared(خالی);

خالی extern_prepostdeclared(خالی);
خالی extern_prepostdeclared(خالی){}
خالی extern_prepostdeclared(خالی);

خالی extern_undeclared2(خالی){}

خالی extern_predeclared2(خالی);
خالی extern_predeclared2(خالی);
خالی extern_predeclared2(خالی){}

خالی extern_postdeclared2(خالی){}
خالی extern_postdeclared2(خالی);
خالی extern_postdeclared2(خالی);


خارجی اندرونی خالی noinst_extern_inline_undeclared(خالی){}

خارجی اندرونی خالی noinst_extern_inline_postdeclared(خالی){}
اندرونی خالی noinst_extern_inline_postdeclared(خالی);

خارجی اندرونی خالی noinst_extern_inline_postdeclared2(خالی){}
اندرونی خالی noinst_extern_inline_postdeclared2(خالی);
اندرونی خالی noinst_extern_inline_postdeclared2(خالی);

خارجی اندرونی خالی inst_extern_inline_postdeclared(خالی){}
خارجی اندرونی خالی inst_extern_inline_postdeclared(خالی);
اندرونی خالی inst2_extern_inline_postdeclared(خالی){}
خالی inst2_extern_inline_postdeclared(خالی);

خالی inst_extern_inline_predeclared(خالی);
خارجی اندرونی خالی inst_extern_inline_predeclared(خالی){}
خالی inst2_extern_inline_predeclared(خالی);
اندرونی خالی inst2_extern_inline_predeclared(خالی){}
خارجی اندرونی خالی inst3_extern_inline_predeclared(خالی);
اندرونی خالی inst3_extern_inline_predeclared(خالی){}

ساکن اندرونی خالی noinst_static_inline_postdeclared(خالی){}
ساکن اندرونی خالی noinst_static_inline_postdeclared(خالی);
ساکن اندرونی خالی noinst2_static_inline_postdeclared(خالی){}
ساکن خالی noinst2_static_inline_postdeclared(خالی);

ساکن خالی noinst_static_inline_predeclared(خالی);
ساکن اندرونی خالی noinst_static_inline_predeclared(خالی){}
ساکن خالی noinst2_static_inline_predeclared(خالی);
ساکن اندرونی خالی noinst2_static_inline_predeclared(خالی){}

ساکن خالی static_func(خالی);
خالی static_func(خالی) { }

اندرونی خالی noinst_extern_inline_func(خالی);
خالی noinst_extern_inline_func(خالی) { }

صحیح مین()
{
        inline_inline_undeclared(); inline_inline_predeclared(); inline_inline_postdeclared();
        inline_inline_undeclared2(); inline_inline_predeclared2(); inline_inline_postdeclared2();
	noinst_static_inline_predeclared();
	noinst2_static_inline_predeclared();
	noinst_static_inline_predeclared();
	noinst2_static_inline_predeclared();

        خالی check_exports();
        check_exports();
        واپس 0;
}

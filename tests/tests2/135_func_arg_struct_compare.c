// https://lists.nongnu.org/archive/html/tinycc-devel/2024-12/msg00019.html
// x86_64/i386 void gfunc_call(int nb_args), when push struct args, need fetch cpu flag before generating any code

#അന്തര്ഭാവ <stdio.h>

ഘടന string {
	അക്ഷരം *str;
	പൂർണ്ണസംഖ്യ len;
};

ശൂന്യം dummy(ഘടന string fpath, പൂർണ്ണസംഖ്യ dump_arg) {
}

പൂർണ്ണസംഖ്യ പ്രധാന() {
	പൂർണ്ണസംഖ്യ a = 1;
	ഘടന string x;
	x.str = "gg.v";
	x.len = 4;
	dummy(x, a == 0);
	printf("done\n");
	തിരികെ 0;
}


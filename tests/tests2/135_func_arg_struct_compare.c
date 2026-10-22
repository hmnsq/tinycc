// https://lists.nongnu.org/archive/html/tinycc-devel/2024-12/msg00019.html
// x86_64/i386 void gfunc_call(int nb_args), when push struct args, need fetch cpu flag before generating any code

#include <stdio.h>

sa_nracanaa string {
	var_na *str;
	ចំនួនគត់ len;
};

void dummy(sa_nracanaa string fpath, ចំនួនគត់ dump_arg) {
}

ចំនួនគត់ main() {
	ចំនួនគត់ a = 1;
	sa_nracanaa string x;
	x.str = "gg.v";
	x.len = 4;
	dummy(x, a == 0);
	printf("done\n");
	ត្រឡប់ 0;
}


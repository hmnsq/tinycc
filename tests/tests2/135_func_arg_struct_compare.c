// https://lists.nongnu.org/archive/html/tinycc-devel/2024-12/msg00019.html
// x86_64/i386 void gfunc_call(int nb_args), when push struct args, need fetch cpu flag before generating any code

#include <stdio.h>

sa_nracanaa string {
	var_na *str;
	ကိန်းပြည့် len;
};

void dummy(sa_nracanaa string fpath, ကိန်းပြည့် dump_arg) {
}

ကိန်းပြည့် main() {
	ကိန်းပြည့် a = 1;
	sa_nracanaa string x;
	x.str = "gg.v";
	x.len = 4;
	dummy(x, a == 0);
	printf("done\n");
	ပြန်ပေး 0;
}


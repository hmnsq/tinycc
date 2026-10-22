// https://lists.nongnu.org/archive/html/tinycc-devel/2024-12/msg00019.html
// x86_64/i386 void gfunc_call(int nb_args), when push struct args, need fetch cpu flag before generating any code

#شامل <stdio.h>

ساختار string {
	نویسه *str;
	صحیح len;
};

تهی dummy(ساختار string fpath, صحیح dump_arg) {
}

صحیح اصلی() {
	صحیح a = 1;
	ساختار string x;
	x.str = "gg.v";
	x.len = 4;
	dummy(x, a == 0);
	printf("done\n");
	بازگشت 0;
}


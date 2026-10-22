// https://lists.nongnu.org/archive/html/tinycc-devel/2024-12/msg00019.html
// x86_64/i386 void gfunc_call(int nb_args), when push struct args, need fetch cpu flag before generating any code

#شامل <stdio.h>

ساخت string {
	حرف *str;
	صحیح len;
};

خالی dummy(ساخت string fpath, صحیح dump_arg) {
}

صحیح مین() {
	صحیح a = 1;
	ساخت string x;
	x.str = "gg.v";
	x.len = 4;
	dummy(x, a == 0);
	لکھو("done\n");
	واپس 0;
}


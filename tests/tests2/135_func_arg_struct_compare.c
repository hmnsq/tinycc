// https://lists.nongnu.org/archive/html/tinycc-devel/2024-12/msg00019.html
// x86_64/i386 void gfunc_call(int nb_args), when push struct args, need fetch cpu flag before generating any code

#ضمن <stdio.h>

بنية string {
	حرف *str;
	صحيح len;
};

فراغ dummy(بنية string fpath, صحيح dump_arg) {
}

صحيح main() {
	صحيح a = 1;
	بنية string x;
	x.str = "gg.v";
	x.len = 4;
	dummy(x, a == 0);
	printf("done\n");
	החזר 0;
}


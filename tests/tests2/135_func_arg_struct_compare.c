// https://lists.nongnu.org/archive/html/tinycc-devel/2024-12/msg00019.html
// x86_64/i386 void gfunc_call(int nb_args), when push struct args, need fetch cpu flag before generating any code

#অন্তর্ভাব <stdio.h>

কাঠামো string {
	অক্ষর *str;
	পূর্ণসংখ্যা len;
};

শূন্য dummy(কাঠামো string fpath, পূর্ণসংখ্যা dump_arg) {
}

পূর্ণসংখ্যা প্রধান() {
	পূর্ণসংখ্যা a = 1;
	কাঠামো string x;
	x.str = "gg.v";
	x.len = 4;
	dummy(x, a == 0);
	printf("done\n");
	ফেরত 0;
}


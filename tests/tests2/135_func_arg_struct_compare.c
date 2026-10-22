// https://lists.nongnu.org/archive/html/tinycc-devel/2024-12/msg00019.html
// x86_64/i386 void gfunc_call(int nb_args), when push struct args, need fetch cpu flag before generating any code

#অন্তর্ভাব <stdio.h>

সংরচনা string {
	বর্ণ *str;
	পূর্ণাঙ্ক len;
};

শূন্য dummy(সংরচনা string fpath, পূর্ণাঙ্ক dump_arg) {
}

পূর্ণাঙ্ক main() {
	পূর্ণাঙ্ক a = 1;
	সংরচনা string x;
	x.str = "gg.v";
	x.len = 4;
	dummy(x, a == 0);
	printf("done\n");
	প্রত্যাগম 0;
}


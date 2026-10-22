// https://lists.nongnu.org/archive/html/tinycc-devel/2024-12/msg00019.html
// x86_64/i386 void gfunc_call(int nb_args), when push struct args, need fetch cpu flag before generating any code

#અન્તર્ભાવ <stdio.h>

સંરચના string {
	અક્ષર *str;
	પૂર્ણાંક len;
};

શૂન્ય dummy(સંરચના string fpath, પૂર્ણાંક dump_arg) {
}

પૂર્ણાંક મુખ્ય() {
	પૂર્ણાંક a = 1;
	સંરચના string x;
	x.str = "gg.v";
	x.len = 4;
	dummy(x, a == 0);
	printf("done\n");
	પાછા 0;
}


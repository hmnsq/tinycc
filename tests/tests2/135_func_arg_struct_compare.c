// https://lists.nongnu.org/archive/html/tinycc-devel/2024-12/msg00019.html
// x86_64/i386 void gfunc_call(int nb_args), when push struct args, need fetch cpu flag before generating any code

#ଅନ୍ତର୍ଭାଵ <stdio.h>

ସଂରଚନା string {
	ଅକ୍ଷର *str;
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା len;
};

ଶୂନ୍ୟ dummy(ସଂରଚନା string fpath, ପୂର୍ଣ୍ଣସଂଖ୍ୟା dump_arg) {
}

ପୂର୍ଣ୍ଣସଂଖ୍ୟା ମୁଖ୍ୟ() {
	ପୂର୍ଣ୍ଣସଂଖ୍ୟା a = 1;
	ସଂରଚନା string x;
	x.str = "gg.v";
	x.len = 4;
	dummy(x, a == 0);
	printf("done\n");
	ଫେରନ୍ତୁ 0;
}


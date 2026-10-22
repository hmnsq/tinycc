// https://lists.nongnu.org/archive/html/tinycc-devel/2024-12/msg00019.html
// x86_64/i386 void gfunc_call(int nb_args), when push struct args, need fetch cpu flag before generating any code

#అన్తర్భావ <stdio.h>

నిర్మాణం string {
	అక్షరం *str;
	పూర్ణాంకం len;
};

శూన్య dummy(నిర్మాణం string fpath, పూర్ణాంకం dump_arg) {
}

పూర్ణాంకం ప్రధాన() {
	పూర్ణాంకం a = 1;
	నిర్మాణం string x;
	x.str = "gg.v";
	x.len = 4;
	dummy(x, a == 0);
	రాయి("done\n");
	తిరిగి 0;
}


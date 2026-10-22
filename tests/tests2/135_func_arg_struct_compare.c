// https://lists.nongnu.org/archive/html/tinycc-devel/2024-12/msg00019.html
// x86_64/i386 void gfunc_call(int nb_args), when push struct args, need fetch cpu flag before generating any code

#अन्तर्भाव <stdio.h>

संरचना string {
	वर्ण *str;
	पूर्णाङ्क len;
};

शून्य dummy(संरचना string fpath, पूर्णाङ्क dump_arg) {
}

पूर्णाङ्क मुख्यम्() {
	पूर्णाङ्क a = 1;
	संरचना string x;
	x.str = "gg.v";
	x.len = 4;
	dummy(x, a == 0);
	प्रारूप_लिख("done\n");
	प्रत्यागम 0;
}


// https://lists.nongnu.org/archive/html/tinycc-devel/2024-12/msg00019.html
// x86_64/i386 void gfunc_call(int nb_args), when push struct args, need fetch cpu flag before generating any code

#ಅನ್ತರ್ಭಾವ <stdio.h>

ಸಂರಚನಾ string {
	ವರ್ಣ *str;
	ಪೂರ್ಣಾಙ್ಕ len;
};

ಶೂನ್ಯ dummy(ಸಂರಚನಾ string fpath, ಪೂರ್ಣಾಙ್ಕ dump_arg) {
}

ಪೂರ್ಣಾಙ್ಕ main() {
	ಪೂರ್ಣಾಙ್ಕ a = 1;
	ಸಂರಚನಾ string x;
	x.str = "gg.v";
	x.len = 4;
	dummy(x, a == 0);
	printf("done\n");
	ಪ್ರತ್ಯಾಗಮ 0;
}


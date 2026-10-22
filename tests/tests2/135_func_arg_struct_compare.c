// https://lists.nongnu.org/archive/html/tinycc-devel/2024-12/msg00019.html
// x86_64/i386 void gfunc_call(int nb_args), when push struct args, need fetch cpu flag before generating any code

#ಅನ್ತರ್ಭಾವ <stdio.h>

ರಚನೆ string {
	ಅಕ್ಷರ *str;
	ಪೂರ್ಣಾಂಕ len;
};

ಶೂನ್ಯ dummy(ರಚನೆ string fpath, ಪೂರ್ಣಾಂಕ dump_arg) {
}

ಪೂರ್ಣಾಂಕ ಮುಖ್ಯ() {
	ಪೂರ್ಣಾಂಕ a = 1;
	ರಚನೆ string x;
	x.str = "gg.v";
	x.len = 4;
	dummy(x, a == 0);
	ಬರೆ("done\n");
	ಹಿಂತಿರುಗಿ 0;
}


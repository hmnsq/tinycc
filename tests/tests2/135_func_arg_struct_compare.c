// https://lists.nongnu.org/archive/html/tinycc-devel/2024-12/msg00019.html
// x86_64/i386 void gfunc_call(int nb_args), when push struct args, need fetch cpu flag before generating any code

#அந்தர்பாவ <stdio.h>

கட்டமைப்பு string {
	எழுத்து *str;
	முழு len;
};

வெறுமை dummy(கட்டமைப்பு string fpath, முழு dump_arg) {
}

முழு முதன்மை() {
	முழு a = 1;
	கட்டமைப்பு string x;
	x.str = "gg.v";
	x.len = 4;
	dummy(x, a == 0);
	printf("done\n");
	திரும்பு 0;
}


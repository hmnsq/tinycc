// https://lists.nongnu.org/archive/html/tinycc-devel/2024-12/msg00019.html
// x86_64/i386 void gfunc_call(int nb_args), when push struct args, need fetch cpu flag before generating any code

#ਅਨ੍ਤਰ੍ਭਾਵ <stdio.h>

ਬਣਤਰ string {
	ਅੱਖਰ *str;
	ਪੂਰਨ len;
};

ਖਾਲੀ dummy(ਬਣਤਰ string fpath, ਪੂਰਨ dump_arg) {
}

ਪੂਰਨ ਮੁੱਖ() {
	ਪੂਰਨ a = 1;
	ਬਣਤਰ string x;
	x.str = "gg.v";
	x.len = 4;
	dummy(x, a == 0);
	ਲਿਖੋ("done\n");
	ਵਾਪਸ 0;
}


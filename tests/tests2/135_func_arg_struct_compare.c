// https://lists.nongnu.org/archive/html/tinycc-devel/2024-12/msg00019.html
// x86_64/i386 void gfunc_call(int nb_args), when push struct args, need fetch cpu flag before generating any code

#समावेश <stdio.h>

काष्ठा string {
	अक्षर *str;
	पूर्णांक len;
};

व्योम dummy(काष्ठा string fpath, पूर्णांक dump_arg) {
}

पूर्णांक मुख्य() {
	पूर्णांक a = 1;
	काष्ठा string x;
	x.str = "gg.v";
	x.len = 4;
	dummy(x, a == 0);
	म_लिखो("done\n");
	वापस 0;
}


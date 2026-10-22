#ضمن <libtcc.h>
#ضمن <stdlib.h>
#ضمن <stdio.h>
#ضمن <string.h>
#ضمن <stdarg.h>

// MinGW has 80-bit rather than 64-bit long double which isn't compatible with TCC or MSVC
#إذا defined(_WIN32) && defined(__GNUC__)
#تعریف_کړه LONG_DOUBLE مزدوج
#تعریف_کړه LONG_DOUBLE_LITERAL(x) x
#وإلا
#تعریف_کړه LONG_DOUBLE اوږد مزدوج
#تعریف_کړه LONG_DOUBLE_LITERAL(x) x ## L
#د_که_پای

ساكن صحيح g_argc;
ساكن حرف **g_argv;

ساكن فراغ سېټ_options(TCCState *s, صحيح argc, حرف **argv)
{
    صحيح i;
    لكل (i = 1; i < argc; ++i) {
        حرف *a = argv[i];
        إذا (a[0] == '-') {
            إذا (a[1] == 'B')
                tcc_سېټ_lib_لار(s, a+2);
            وإلا إذا (a[1] == 'I')
                tcc_جمع_کړه_include_لار(s, a+2);
            وإلا إذا (a[1] == 'L')
                tcc_جمع_کړه_library_لار(s, a+2);
        }
    }
}

تعريفنوع صحيح (*callback_type) (فراغ*);

/*
 * Compile source code and call a callback with a pointer to the symbol "f".
 */
ساكن صحيح پرلپسې_callback(ثابت حرف *src, callback_type callback) {
  TCCState *s;
  صحيح پایله;
  فراغ *ptr;
  
  s = tcc_new();
  إذا (!s)
    أرجع -1;

  سېټ_options(s, g_argc, g_argv);

  إذا (tcc_سېټ_output_type(s, TCC_OUTPUT_حافظه) == -1)
    أرجع -1;
  إذا (tcc_compile_string(s, src) == -1)
    أرجع -1;
  إذا (tcc_relocate(s) == -1)
    أرجع -1;
  
  ptr = tcc_get_نښه(s, "f");
  إذا (!ptr)
    أرجع -1;
  پایله = callback(ptr);
  
  tcc_delete(s);
  
  أرجع پایله;
}

#تعریف_کړه STR2(x) #x
#تعریف_کړه STR(x) STR2(x)

#تعریف_کړه RET_PRIMITIVE_TEST(name, type, val) \
  ساكن صحيح ret_ ## name ## _test_callback(فراغ *ptr) { \
    type (*callback) (type) = (type(*)(type))ptr; \
    type x = val; \
    type y = callback(x); \
    أرجع (y == x+x) ? 0 : -1; \
  } \
  \
  ساكن صحيح ret_ ## name ## _test(فراغ) { \
    ثابت حرف *src = STR(type) " f(" STR(type) " x) {return x+x;}"; \
    أرجع پرلپسې_callback(src, ret_ ## name ## _test_callback); \
  }

RET_PRIMITIVE_TEST(صحيح, صحيح, 70000)
RET_PRIMITIVE_TEST(longlong, اوږد اوږد, 4333369356528LL)
RET_PRIMITIVE_TEST(عائم, عائم, 63.0)
RET_PRIMITIVE_TEST(مزدوج, مزدوج, 14789798.0)
RET_PRIMITIVE_TEST(longdouble, LONG_DOUBLE, LONG_DOUBLE_LITERAL(378943892.0))

/*
 * ret_2float_test:
 * 
 * On x86-64, a struct with 2 floats should be packed into a single
 * SSE register (VT_DOUBLE is used for this purpose).
 */
تعريفنوع بنية ret_2float_test_type_s {عائم x, y;} ret_2float_test_type;
تعريفنوع ret_2float_test_type (*ret_2float_test_function_type) (ret_2float_test_type);

ساكن صحيح ret_2float_test_callback(فراغ *ptr) {
  ret_2float_test_function_type f = (ret_2float_test_function_type)ptr;
  ret_2float_test_type a = {10, 35};
  ret_2float_test_type r;
  r = f(a);
  أرجع ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

ساكن صحيح ret_2float_test(فراغ) {
  ثابت حرف *src =
  "typedef struct ret_2float_test_type_s {float x, y;} ret_2float_test_type;"
  "ret_2float_test_type f(ret_2float_test_type a) {\n"
  "  ret_2float_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";

  أرجع پرلپسې_callback(src, ret_2float_test_callback);
}

/*
 * ret_2double_test:
 * 
 * On x86-64, a struct with 2 doubles should be passed in two SSE
 * registers.
 */
تعريفنوع بنية ret_2double_test_type_s {مزدوج x, y;} ret_2double_test_type;
تعريفنوع ret_2double_test_type (*ret_2double_test_function_type) (ret_2double_test_type);

ساكن صحيح ret_2double_test_callback(فراغ *ptr) {
  ret_2double_test_function_type f = (ret_2double_test_function_type)ptr;
  ret_2double_test_type a = {10, 35};
  ret_2double_test_type r;
  r = f(a);
  أرجع ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

ساكن صحيح ret_2double_test(فراغ) {
  ثابت حرف *src =
  "typedef struct ret_2double_test_type_s {double x, y;} ret_2double_test_type;"
  "ret_2double_test_type f(ret_2double_test_type a) {\n"
  "  ret_2double_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";

  أرجع پرلپسې_callback(src, ret_2double_test_callback);
}

/*
 * ret_8plus2double_test:
 *
 * This catches a corner case in the x86_64 ABI code: the first 7
 * arguments fit into registers, the 8th doesn't, but the 9th argument
 * fits into the 8th XMM register.
 *
 * Note that the purpose of the 10th argument is to avoid a situation
 * in which gcc would accidentally put the double at the right
 * address, thus causing a success message even though TCC actually
 * generated incorrect code.
 */
تعريفنوع ret_2double_test_type (*ret_8plus2double_test_function_type) (مزدوج, مزدوج, مزدوج, مزدوج, مزدوج, مزدوج, مزدوج, ret_2double_test_type, مزدوج, مزدوج);

ساكن صحيح ret_8plus2double_test_callback(فراغ *ptr) {
  ret_8plus2double_test_function_type f = (ret_8plus2double_test_function_type)ptr;
  ret_2double_test_type a = {10, 35};
  ret_2double_test_type r;
  r = f(0, 0, 0, 0, 0, 0, 0, a, 37, 38);
  أرجع ((r.x == 37) && (r.y == 37)) ? 0 : -1;
}

ساكن صحيح ret_8plus2double_test(فراغ) {
  ثابت حرف *src =
  "typedef struct ret_2double_test_type_s {double x, y;} ret_2double_test_type;"
  "ret_2double_test_type f(double x1, double x2, double x3, double x4, double x5, double x6, double x7, ret_2double_test_type a, double x8, double x9) {\n"
  "  ret_2double_test_type r = { x8, x8 };\n"
  "  return r;\n"
  "}\n";

  أرجع پرلپسې_callback(src, ret_8plus2double_test_callback);
}

/*
 * ret_mixed_test:
 *
 * On x86-64, a struct with a double and a 64-bit integer should be
 * passed in one SSE register and one integer register.
 */
تعريفنوع بنية ret_mixed_test_type_s {مزدوج x; اوږد اوږد y;} ret_mixed_test_type;
تعريفنوع ret_mixed_test_type (*ret_mixed_test_function_type) (ret_mixed_test_type);

ساكن صحيح ret_mixed_test_callback(فراغ *ptr) {
  ret_mixed_test_function_type f = (ret_mixed_test_function_type)ptr;
  ret_mixed_test_type a = {10, 35};
  ret_mixed_test_type r;
  r = f(a);
  أرجع ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

ساكن صحيح ret_mixed_test(فراغ) {
  ثابت حرف *src =
  "typedef struct ret_mixed_test_type_s {double x; long long y;} ret_mixed_test_type;"
  "ret_mixed_test_type f(ret_mixed_test_type a) {\n"
  "  ret_mixed_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";

  أرجع پرلپسې_callback(src, ret_mixed_test_callback);
}

/*
 * ret_mixed2_test:
 *
 * On x86-64, a struct with two floats and two 32-bit integers should
 * be passed in one SSE register and one integer register.
 */
تعريفنوع بنية ret_mixed2_test_type_s {عائم x,x2; صحيح y,y2;} ret_mixed2_test_type;
تعريفنوع ret_mixed2_test_type (*ret_mixed2_test_function_type) (ret_mixed2_test_type);

ساكن صحيح ret_mixed2_test_callback(فراغ *ptr) {
  ret_mixed2_test_function_type f = (ret_mixed2_test_function_type)ptr;
  ret_mixed2_test_type a = {10, 5, 35, 7 };
  ret_mixed2_test_type r;
  r = f(a);
  أرجع ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

ساكن صحيح ret_mixed2_test(فراغ) {
  ثابت حرف *src =
  "typedef struct ret_mixed2_test_type_s {float x, x2; int y,y2;} ret_mixed2_test_type;"
  "ret_mixed2_test_type f(ret_mixed2_test_type a) {\n"
  "  ret_mixed2_test_type r = {a.x*5, 0, a.y*3, 0};\n"
  "  return r;\n"
  "}\n";

  أرجع پرلپسې_callback(src, ret_mixed2_test_callback);
}

/*
 * ret_mixed3_test:
 *
 * On x86-64, this struct should be passed in two integer registers.
 */
تعريفنوع بنية ret_mixed3_test_type_s {عائم x; صحيح y; عائم x2; صحيح y2;} ret_mixed3_test_type;
تعريفنوع ret_mixed3_test_type (*ret_mixed3_test_function_type) (ret_mixed3_test_type);

ساكن صحيح ret_mixed3_test_callback(فراغ *ptr) {
  ret_mixed3_test_function_type f = (ret_mixed3_test_function_type)ptr;
  ret_mixed3_test_type a = {10, 5, 35, 7 };
  ret_mixed3_test_type r;
  r = f(a);
  أرجع ((r.x == a.x*5) && (r.y2 == a.y*3)) ? 0 : -1;
}

ساكن صحيح ret_mixed3_test(فراغ) {
  ثابت حرف *src =
  "typedef struct ret_mixed3_test_type_s {float x; int y; float x2; int y2;} ret_mixed3_test_type;"
  "ret_mixed3_test_type f(ret_mixed3_test_type a) {\n"
  "  ret_mixed3_test_type r = {a.x*5, 0, 0, a.y*3};\n"
  "  return r;\n"
  "}\n";

  أرجع پرلپسې_callback(src, ret_mixed3_test_callback);
}

/*
 * reg_pack_test: return a small struct which should be packed into
 * registers (Win32) during return.
 */
تعريفنوع بنية reg_pack_test_type_s {صحيح x, y;} reg_pack_test_type;
تعريفنوع reg_pack_test_type (*reg_pack_test_function_type) (reg_pack_test_type);

ساكن صحيح reg_pack_test_callback(فراغ *ptr) {
  reg_pack_test_function_type f = (reg_pack_test_function_type)ptr;
  reg_pack_test_type a = {10, 35};
  reg_pack_test_type r;
  r = f(a);
  أرجع ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

ساكن صحيح reg_pack_test(فراغ) {
  ثابت حرف *src =
  "typedef struct reg_pack_test_type_s {int x, y;} reg_pack_test_type;"
  "reg_pack_test_type f(reg_pack_test_type a) {\n"
  "  reg_pack_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";
  
  أرجع پرلپسې_callback(src, reg_pack_test_callback);
}

/*
 * reg_pack_longlong_test: return a small struct which should be packed into
 * registers (x86-64) during return.
 */
تعريفنوع بنية reg_pack_longlong_test_type_s {اوږد اوږد x, y;} reg_pack_longlong_test_type;
تعريفنوع reg_pack_longlong_test_type (*reg_pack_longlong_test_function_type) (reg_pack_longlong_test_type);

ساكن صحيح reg_pack_longlong_test_callback(فراغ *ptr) {
  reg_pack_longlong_test_function_type f = (reg_pack_longlong_test_function_type)ptr;
  reg_pack_longlong_test_type a = {10, 35};
  reg_pack_longlong_test_type r;
  r = f(a);
  أرجع ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

ساكن صحيح reg_pack_longlong_test(فراغ) {
  ثابت حرف *src =
  "typedef struct reg_pack_longlong_test_type_s {long long x, y;} reg_pack_longlong_test_type;"
  "reg_pack_longlong_test_type f(reg_pack_longlong_test_type a) {\n"
  "  reg_pack_longlong_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";
  
  أرجع پرلپسې_callback(src, reg_pack_longlong_test_callback);
}

/*
 * ret_6plus2longlong_test:
 *
 * This catches a corner case in the x86_64 ABI code: the first 5
 * arguments fit into registers, the 6th doesn't, but the 7th argument
 * fits into the 6th argument integer register, %r9.
 *
 * Note that the purpose of the 10th argument is to avoid a situation
 * in which gcc would accidentally put the longlong at the right
 * address, thus causing a success message even though TCC actually
 * generated incorrect code.
 */
تعريفنوع reg_pack_longlong_test_type (*ret_6plus2longlong_test_function_type) (اوږد اوږد, اوږد اوږد, اوږد اوږد, اوږد اوږد, اوږد اوږد, reg_pack_longlong_test_type, اوږد اوږد, اوږد اوږد);

ساكن صحيح ret_6plus2longlong_test_callback(فراغ *ptr) {
  ret_6plus2longlong_test_function_type f = (ret_6plus2longlong_test_function_type)ptr;
  reg_pack_longlong_test_type a = {10, 35};
  reg_pack_longlong_test_type r;
  r = f(0, 0, 0, 0, 0, a, 37, 38);
  أرجع ((r.x == 37) && (r.y == 37)) ? 0 : -1;
}

ساكن صحيح ret_6plus2longlong_test(فراغ) {
  ثابت حرف *src =
  "typedef struct reg_pack_longlong_test_type_s {long long x, y;} reg_pack_longlong_test_type;"
  "reg_pack_longlong_test_type f(long long x1, long long x2, long long x3, long long x4, long long x5, reg_pack_longlong_test_type a, long long x8, long long x9) {\n"
  "  reg_pack_longlong_test_type r = { x8, x8 };\n"
  "  return r;\n"
  "}\n";

  أرجع پرلپسې_callback(src, ret_6plus2longlong_test_callback);
}

/*
 * sret_test: Create a struct large enough to be returned via sret
 * (hidden pointer as first function argument)
 */
تعريفنوع بنية sret_test_type_s {اوږد اوږد a, b, c;} sret_test_type;
تعريفنوع sret_test_type (*sret_test_function_type) (sret_test_type);

ساكن صحيح sret_test_callback(فراغ *ptr) {
  sret_test_function_type f = (sret_test_function_type)(ptr);
  sret_test_type x = {5436LL, 658277698LL, 43878957LL};
  sret_test_type r = f(x);
  أرجع ((r.a==x.a*35)&&(r.b==x.b*19)&&(r.c==x.c*21)) ? 0 : -1;
}

ساكن صحيح sret_test(فراغ) {
  ثابت حرف *src =
  "typedef struct sret_test_type_s {long long a, b, c;} sret_test_type;\n"
  "sret_test_type f(sret_test_type x) {\n"
  "  sret_test_type r = {x.a*35, x.b*19, x.c*21};\n"
  "  return r;\n"
  "}\n";
  
  أرجع پرلپسې_callback(src, sret_test_callback);
}

/*
 * one_member_union_test:
 * 
 * In the x86-64 ABI a union should always be passed on the stack. However
 * it appears that a single member union is treated by GCC as its member.
 */
تعريفنوع اتحاد one_member_union_test_type_u {صحيح x;} one_member_union_test_type;
تعريفنوع one_member_union_test_type (*one_member_union_test_function_type) (one_member_union_test_type);

ساكن صحيح one_member_union_test_callback(فراغ *ptr) {
  one_member_union_test_function_type f = (one_member_union_test_function_type)ptr;
  one_member_union_test_type a, b;
  a.x = 34;
  b = f(a);
  أرجع (b.x == a.x*2) ? 0 : -1;
}

ساكن صحيح one_member_union_test(فراغ) {
  ثابت حرف *src =
  "typedef union one_member_union_test_type_u {int x;} one_member_union_test_type;\n"
  "one_member_union_test_type f(one_member_union_test_type a) {\n"
  "  one_member_union_test_type b;\n"
  "  b.x = a.x * 2;\n"
  "  return b;\n"
  "}\n";
  أرجع پرلپسې_callback(src, one_member_union_test_callback);
}

/*
 * two_member_union_test:
 * 
 * In the x86-64 ABI a union should always be passed on the stack.
 */
تعريفنوع اتحاد two_member_union_test_type_u {صحيح x; اوږد y;} two_member_union_test_type;
تعريفنوع two_member_union_test_type (*two_member_union_test_function_type) (two_member_union_test_type);

ساكن صحيح two_member_union_test_callback(فراغ *ptr) {
  two_member_union_test_function_type f = (two_member_union_test_function_type)ptr;
  two_member_union_test_type a, b;
  a.x = 34;
  b = f(a);
  أرجع (b.x == a.x*2) ? 0 : -1;
}

ساكن صحيح two_member_union_test(فراغ) {
  ثابت حرف *src =
  "typedef union two_member_union_test_type_u {int x; long y;} two_member_union_test_type;\n"
  "two_member_union_test_type f(two_member_union_test_type a) {\n"
  "  two_member_union_test_type b;\n"
  "  b.x = a.x * 2;\n"
  "  return b;\n"
  "}\n";
  أرجع پرلپسې_callback(src, two_member_union_test_callback);
}

/*
 * Win64 calling convention test.
 */

تعريفنوع بنية many_struct_test_type_s {اوږد اوږد a, b, c;} many_struct_test_type;
تعريفنوع many_struct_test_type (*many_struct_test_function_type) (many_struct_test_type,many_struct_test_type,many_struct_test_type,many_struct_test_type,many_struct_test_type,many_struct_test_type);
 
ساكن صحيح many_struct_test_callback(فراغ *ptr) {
  many_struct_test_function_type f = (many_struct_test_function_type)ptr;
  many_struct_test_type v = {1, 2, 3};
  many_struct_test_type r = f(v,v,v,v,v,v);
  أرجع ((r.a == 6) && (r.b == 12) && (r.c == 18))?0:-1;
}

ساكن صحيح many_struct_test(فراغ) {
  ثابت حرف *src =
  "typedef struct many_struct_test_type_s {long long a, b, c;} many_struct_test_type;\n"
  "many_struct_test_type f(many_struct_test_type x1, many_struct_test_type x2, many_struct_test_type x3, many_struct_test_type x4, many_struct_test_type x5, many_struct_test_type x6) {\n"
  "  many_struct_test_type y;\n"
  "  y.a = x1.a + x2.a + x3.a + x4.a + x5.a + x6.a;\n"
  "  y.b = x1.b + x2.b + x3.b + x4.b + x5.b + x6.b;\n"
  "  y.c = x1.c + x2.c + x3.c + x4.c + x5.c + x6.c;\n"
  "  return y;\n"
  "}\n";
  أرجع پرلپسې_callback(src, many_struct_test_callback);
}

/*
 * Win64 calling convention test.
 */

تعريفنوع بنية many_struct_test_2_type_s {صحيح a, b;} many_struct_test_2_type;
تعريفنوع many_struct_test_2_type (*many_struct_test_2_function_type) (many_struct_test_2_type,many_struct_test_2_type,many_struct_test_2_type,many_struct_test_2_type,many_struct_test_2_type,many_struct_test_2_type);
 
ساكن صحيح many_struct_test_2_callback(فراغ *ptr) {
  many_struct_test_2_function_type f = (many_struct_test_2_function_type)ptr;
  many_struct_test_2_type v = {1,2};
  many_struct_test_2_type r = f(v,v,v,v,v,v);
  أرجع ((r.a == 6) && (r.b == 12))?0:-1;
}

ساكن صحيح many_struct_test_2(فراغ) {
  ثابت حرف *src =
  "typedef struct many_struct_test_2_type_s {int a, b;} many_struct_test_2_type;\n"
  "many_struct_test_2_type f(many_struct_test_2_type x1, many_struct_test_2_type x2, many_struct_test_2_type x3, many_struct_test_2_type x4, many_struct_test_2_type x5, many_struct_test_2_type x6) {\n"
  "  many_struct_test_2_type y;\n"
  "  y.a = x1.a + x2.a + x3.a + x4.a + x5.a + x6.a;\n"
  "  y.b = x1.b + x2.b + x3.b + x4.b + x5.b + x6.b;\n"
  "  return y;\n"
  "}\n";
  أرجع پرلپسې_callback(src, many_struct_test_2_callback);
}

/*
 * Win64 calling convention test.
 */

تعريفنوع بنية many_struct_test_3_type_s {صحيح a, b;} many_struct_test_3_type;
تعريفنوع many_struct_test_3_type (*many_struct_test_3_function_type) (many_struct_test_3_type,many_struct_test_3_type,many_struct_test_3_type,many_struct_test_3_type,many_struct_test_3_type,many_struct_test_3_type, ...);
تعريفنوع بنية many_struct_test_3_struct_type { many_struct_test_3_function_type f; many_struct_test_3_function_type *f2; } many_struct_test_3_struct_type;

ساكن فراغ many_struct_test_3_dummy(مزدوج d, ...)
{
  متطاير مزدوج x = d;
}

ساكن صحيح many_struct_test_3_callback(فراغ *ptr) {
  many_struct_test_3_struct_type s = { ptr, };
  many_struct_test_3_struct_type *s2 = &s;
  s2->f2 = &s2->f;
  many_struct_test_3_dummy(1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, &s2);
  many_struct_test_3_function_type f = *(s2->f2);
  many_struct_test_3_type v = {1,2};
  many_struct_test_3_type r = (*((s2->f2=&f)+0))(v,v,v,v,v,v,1.0);
  أرجع ((r.a == 6) && (r.b == 12))?0:-1;
}

ساكن صحيح many_struct_test_3(فراغ) {
  ثابت حرف *src =
  "typedef struct many_struct_test_3_type_s {int a, b;} many_struct_test_3_type;\n"
  "many_struct_test_3_type f(many_struct_test_3_type x1, many_struct_test_3_type x2, many_struct_test_3_type x3, many_struct_test_3_type x4, many_struct_test_3_type x5, many_struct_test_3_type x6, ...) {\n"
  "  many_struct_test_3_type y;\n"
  "  y.a = x1.a + x2.a + x3.a + x4.a + x5.a + x6.a;\n"
  "  y.b = x1.b + x2.b + x3.b + x4.b + x5.b + x6.b;\n"
  "  return y;\n"
  "}\n";
  أرجع پرلپسې_callback(src, many_struct_test_3_callback);
}

/*
 * stdarg_test: Test variable argument list ABI
 */

تعريفنوع بنية {اوږد اوږد a, b, c;} stdarg_test_struct_type;
تعريفنوع فراغ (*stdarg_test_function_type) (صحيح,صحيح,صحيح,...);

ساكن صحيح stdarg_test_callback(فراغ *ptr) {
  stdarg_test_function_type f = (stdarg_test_function_type)ptr;
  صحيح x;
  مزدوج y;
  stdarg_test_struct_type z = {1, 2, 3}, w;
  f(10, 10, 5,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, &x,
    1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, &y,
    z, z, z, z, z, &w);
  أرجع ((x == 55) && (y == 55) && (w.a == 5) && (w.b == 10) && (w.c == 15)) ? 0 : -1;
}

ساكن صحيح stdarg_test(فراغ) {
  ثابت حرف *src =
  "#include <stdarg.h>\n"
  "typedef struct {long long a, b, c;} stdarg_test_struct_type;\n"
  "void f(int n_int, int n_float, int n_struct, ...) {\n"
  "  int i, ti = 0;\n"
  "  double td = 0.0;\n"
  "  stdarg_test_struct_type ts = {0,0,0}, tmp;\n"
  "  va_list ap;\n"
  "  va_start(ap, n_struct);\n"
  "  for (i = 0, ti = 0; i < n_int; ++i)\n"
  "    ti += va_arg(ap, int);\n"
  "  *va_arg(ap, int*) = ti;\n"
  "  for (i = 0, td = 0; i < n_float; ++i)\n"
  "    td += va_arg(ap, double);\n"
  "  *va_arg(ap, double*) = td;\n"
  "  for (i = 0; i < n_struct; ++i) {\n"
  "    tmp = va_arg(ap, stdarg_test_struct_type);\n"
  "    ts.a += tmp.a; ts.b += tmp.b; ts.c += tmp.c;"
  "  }\n"
  "  *va_arg(ap, stdarg_test_struct_type*) = ts;\n"
  "  va_end(ap);"
  "}\n";
  أرجع پرلپسې_callback(src, stdarg_test_callback);
}

تعريفنوع بنية {اوږد اوږد a, b;} stdarg_many_test_struct_type;
تعريفنوع فراغ (*stdarg_many_test_function_type) (صحيح, صحيح, صحيح, صحيح, صحيح,
						stdarg_many_test_struct_type,
						صحيح, صحيح, ...);

ساكن صحيح stdarg_many_test_callback(فراغ *ptr)
{
  stdarg_many_test_function_type f = (stdarg_many_test_function_type)ptr;
  صحيح x;
  stdarg_many_test_struct_type l = {10, 11};
  f(1, 2, 3, 4, 5, l, 6, 7, &x, 44);
  أرجع x == 44 ? 0 : -1;
}

ساكن صحيح stdarg_many_test(فراغ)
{
  ثابت حرف *src =
  "#include <stdarg.h>\n"
  "typedef struct {long long a, b;} stdarg_many_test_struct_type;\n"
  "void f (int a, int b, int c, int d, int e, stdarg_many_test_struct_type l, int f, int g, ...){\n"
  "  va_list ap;\n"
  "  int *p;\n"
  "  va_start (ap, g);\n"
  "  p = va_arg(ap, int*);\n"
  "  *p = va_arg(ap, int);\n"
  "  va_end (ap);\n"
  "}\n";
  أرجع پرلپسې_callback(src, stdarg_many_test_callback);
}

/*
 * Test Win32 stdarg handling, since the calling convention will pass a pointer
 * to the struct and the stdarg pointer must point to that pointer initially.
 */

تعريفنوع بنية {اوږد اوږد a, b, c;} stdarg_struct_test_struct_type;
تعريفنوع صحيح (*stdarg_struct_test_function_type) (stdarg_struct_test_struct_type a, ...);

ساكن صحيح stdarg_struct_test_callback(فراغ *ptr) {
  stdarg_struct_test_function_type f = (stdarg_struct_test_function_type)ptr;
  stdarg_struct_test_struct_type v = {10, 35, 99};
  صحيح x = f(v, 234);
  أرجع (x == 378) ? 0 : -1;
}

ساكن صحيح stdarg_struct_test(فراغ) {
  ثابت حرف *src =
  "#include <stdarg.h>\n"
  "typedef struct {long long a, b, c;} stdarg_struct_test_struct_type;\n"
  "int f(stdarg_struct_test_struct_type a, ...) {\n"
  "  va_list ap;\n"
  "  va_start(ap, a);\n"
  "  int z = va_arg(ap, int);\n"
  "  va_end(ap);\n"
  "  return z + a.a + a.b + a.c;\n"
  "}\n";
  أرجع پرلپسې_callback(src, stdarg_struct_test_callback);
}

/* Test that x86-64 arranges the stack correctly for arguments with alignment >8 bytes */

تعريفنوع LONG_DOUBLE (*arg_align_test_callback_type) (LONG_DOUBLE,صحيح,LONG_DOUBLE,صحيح,LONG_DOUBLE);

ساكن صحيح arg_align_test_callback(فراغ *ptr) {
  arg_align_test_callback_type f = (arg_align_test_callback_type)ptr;
  اوږد مزدوج x = f(12, 0, 25, 0, 37);
  أرجع (x == 74) ? 0 : -1;
}

ساكن صحيح arg_align_test(فراغ) {
  ثابت حرف *src = 
  "long double f(long double a, int b, long double c, int d, long double e) {\n"
  "  return a + c + e;\n"
  "}\n";
  أرجع پرلپسې_callback(src, arg_align_test_callback);
}

#تعریف_کړه پرلپسې_TEST(t) \
  إذا (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    إذا (t() == 0) { \
      fputs("success\n", stdout); \
    } وإلا { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

صحيح اصلي(صحيح argc, حرف **argv) {
  صحيح i;
  ثابت حرف *testname = عدم;
  صحيح retval = EXIT_SUCCESS;
  
  /* if tcclib.h and libtcc1.a are not installed, where can we find them */
  لكل (i = 1; i < argc; ++i) {
    إذا (!memcmp(argv[i], "run_test=", 9))
      testname = argv[i] + 9;
  }

  g_argv = argv, g_argc = argc;

  پرلپسې_TEST(ret_int_test);
  پرلپسې_TEST(ret_longlong_test);
  پرلپسې_TEST(ret_float_test);
  پرلپسې_TEST(ret_double_test);
  پرلپسې_TEST(ret_longdouble_test);
  پرلپسې_TEST(ret_2float_test);
  پرلپسې_TEST(ret_2double_test);
  پرلپسې_TEST(ret_8plus2double_test);
  پرلپسې_TEST(ret_6plus2longlong_test);
#إذا !defined __x86_64__ || defined _WIN32
  /* currently broken on x86_64 linux */
  پرلپسې_TEST(ret_mixed_test);
  پرلپسې_TEST(ret_mixed2_test);
#د_که_پای
  پرلپسې_TEST(ret_mixed3_test);
  پرلپسې_TEST(reg_pack_test);
  پرلپسې_TEST(reg_pack_longlong_test);
  پرلپسې_TEST(sret_test);
  پرلپسې_TEST(one_member_union_test);
  پرلپسې_TEST(two_member_union_test);
  پرلپسې_TEST(many_struct_test);
  پرلپسې_TEST(many_struct_test_2);
  پرلپسې_TEST(many_struct_test_3);
  پرلپسې_TEST(stdarg_test);
  پرلپسې_TEST(stdarg_many_test);
  پرلپسې_TEST(stdarg_struct_test);
  پرلپسې_TEST(arg_align_test);
  أرجع retval;
}

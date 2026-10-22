#অন্তর্ভাৱ <libtcc.h>
#অন্তর্ভাৱ <stdlib.h>
#অন্তর্ভাৱ <stdio.h>
#অন্তর্ভাৱ <string.h>
#অন্তর্ভাৱ <stdarg.h>

// MinGW has 80-bit rather than 64-bit long double which isn't compatible with TCC or MSVC
#যদি defined(_WIN32) && defined(__GNUC__)
#define LONG_DOUBLE দ্ৱিগুণ
#define LONG_DOUBLE_LITERAL(x) x
#অন্যথা
#define LONG_DOUBLE long দ্ৱিগুণ
#define LONG_DOUBLE_LITERAL(x) x ## L
#endif

স্থির পূর্ণাঙ্ক g_argc;
স্থির ৱর্ণ **g_argv;

স্থির শূন্য set_options(TCCState *s, পূর্ণাঙ্ক argc, ৱর্ণ **argv)
{
    পূর্ণাঙ্ক i;
    বাবে (i = 1; i < argc; ++i) {
        ৱর্ণ *a = argv[i];
        যদি (a[0] == '-') {
            যদি (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            অন্যথা যদি (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            অন্যথা যদি (a[1] == 'L')
                tcc_add_library_path(s, a+2);
        }
    }
}

প্রকারনির্দেশ পূর্ণাঙ্ক (*callback_type) (শূন্য*);

/*
 * Compile source code and call a callback with a pointer to the symbol "f".
 */
স্থির পূর্ণাঙ্ক run_callback(ধ্রুৱ ৱর্ণ *src, callback_type callback) {
  TCCState *s;
  পূর্ণাঙ্ক result;
  শূন্য *ptr;
  
  s = tcc_new();
  যদি (!s)
    ঘূৰাই -1;

  set_options(s, g_argc, g_argv);

  যদি (tcc_set_output_type(s, TCC_OUTPUT_MEMORY) == -1)
    ঘূৰাই -1;
  যদি (tcc_compile_string(s, src) == -1)
    ঘূৰাই -1;
  যদি (tcc_relocate(s) == -1)
    ঘূৰাই -1;
  
  ptr = tcc_get_প্ৰতীক(s, "f");
  যদি (!ptr)
    ঘূৰাই -1;
  result = callback(ptr);
  
  tcc_delete(s);
  
  ঘূৰাই result;
}

#define STR2(x) #x
#define STR(x) STR2(x)

#define RET_PRIMITIVE_TEST(name, type, val) \
  স্থির পূর্ণাঙ্ক ret_ ## name ## _test_callback(শূন্য *ptr) { \
    type (*callback) (type) = (type(*)(type))ptr; \
    type x = val; \
    type y = callback(x); \
    ঘূৰাই (y == x+x) ? 0 : -1; \
  } \
  \
  স্থির পূর্ণাঙ্ক ret_ ## name ## _test(শূন্য) { \
    ধ্রুৱ ৱর্ণ *src = STR(type) " f(" STR(type) " x) {return x+x;}"; \
    ঘূৰাই run_callback(src, ret_ ## name ## _test_callback); \
  }

RET_PRIMITIVE_TEST(পূর্ণাঙ্ক, পূর্ণাঙ্ক, 70000)
RET_PRIMITIVE_TEST(longlong, long long, 4333369356528LL)
RET_PRIMITIVE_TEST(ভিন্ন, ভিন্ন, 63.0)
RET_PRIMITIVE_TEST(দ্ৱিগুণ, দ্ৱিগুণ, 14789798.0)
RET_PRIMITIVE_TEST(longdouble, LONG_DOUBLE, LONG_DOUBLE_LITERAL(378943892.0))

/*
 * ret_2float_test:
 * 
 * On x86-64, a struct with 2 floats should be packed into a single
 * SSE register (VT_DOUBLE is used for this purpose).
 */
প্রকারনির্দেশ সংরচনা ret_2float_test_type_s {ভিন্ন x, y;} ret_2float_test_type;
প্রকারনির্দেশ ret_2float_test_type (*ret_2float_test_function_type) (ret_2float_test_type);

স্থির পূর্ণাঙ্ক ret_2float_test_callback(শূন্য *ptr) {
  ret_2float_test_function_type f = (ret_2float_test_function_type)ptr;
  ret_2float_test_type a = {10, 35};
  ret_2float_test_type r;
  r = f(a);
  ঘূৰাই ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

স্থির পূর্ণাঙ্ক ret_2float_test(শূন্য) {
  ধ্রুৱ ৱর্ণ *src =
  "typedef struct ret_2float_test_type_s {float x, y;} ret_2float_test_type;"
  "ret_2float_test_type f(ret_2float_test_type a) {\n"
  "  ret_2float_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";

  ঘূৰাই run_callback(src, ret_2float_test_callback);
}

/*
 * ret_2double_test:
 * 
 * On x86-64, a struct with 2 doubles should be passed in two SSE
 * registers.
 */
প্রকারনির্দেশ সংরচনা ret_2double_test_type_s {দ্ৱিগুণ x, y;} ret_2double_test_type;
প্রকারনির্দেশ ret_2double_test_type (*ret_2double_test_function_type) (ret_2double_test_type);

স্থির পূর্ণাঙ্ক ret_2double_test_callback(শূন্য *ptr) {
  ret_2double_test_function_type f = (ret_2double_test_function_type)ptr;
  ret_2double_test_type a = {10, 35};
  ret_2double_test_type r;
  r = f(a);
  ঘূৰাই ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

স্থির পূর্ণাঙ্ক ret_2double_test(শূন্য) {
  ধ্রুৱ ৱর্ণ *src =
  "typedef struct ret_2double_test_type_s {double x, y;} ret_2double_test_type;"
  "ret_2double_test_type f(ret_2double_test_type a) {\n"
  "  ret_2double_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";

  ঘূৰাই run_callback(src, ret_2double_test_callback);
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
প্রকারনির্দেশ ret_2double_test_type (*ret_8plus2double_test_function_type) (দ্ৱিগুণ, দ্ৱিগুণ, দ্ৱিগুণ, দ্ৱিগুণ, দ্ৱিগুণ, দ্ৱিগুণ, দ্ৱিগুণ, ret_2double_test_type, দ্ৱিগুণ, দ্ৱিগুণ);

স্থির পূর্ণাঙ্ক ret_8plus2double_test_callback(শূন্য *ptr) {
  ret_8plus2double_test_function_type f = (ret_8plus2double_test_function_type)ptr;
  ret_2double_test_type a = {10, 35};
  ret_2double_test_type r;
  r = f(0, 0, 0, 0, 0, 0, 0, a, 37, 38);
  ঘূৰাই ((r.x == 37) && (r.y == 37)) ? 0 : -1;
}

স্থির পূর্ণাঙ্ক ret_8plus2double_test(শূন্য) {
  ধ্রুৱ ৱর্ণ *src =
  "typedef struct ret_2double_test_type_s {double x, y;} ret_2double_test_type;"
  "ret_2double_test_type f(double x1, double x2, double x3, double x4, double x5, double x6, double x7, ret_2double_test_type a, double x8, double x9) {\n"
  "  ret_2double_test_type r = { x8, x8 };\n"
  "  return r;\n"
  "}\n";

  ঘূৰাই run_callback(src, ret_8plus2double_test_callback);
}

/*
 * ret_mixed_test:
 *
 * On x86-64, a struct with a double and a 64-bit integer should be
 * passed in one SSE register and one integer register.
 */
প্রকারনির্দেশ সংরচনা ret_mixed_test_type_s {দ্ৱিগুণ x; long long y;} ret_mixed_test_type;
প্রকারনির্দেশ ret_mixed_test_type (*ret_mixed_test_function_type) (ret_mixed_test_type);

স্থির পূর্ণাঙ্ক ret_mixed_test_callback(শূন্য *ptr) {
  ret_mixed_test_function_type f = (ret_mixed_test_function_type)ptr;
  ret_mixed_test_type a = {10, 35};
  ret_mixed_test_type r;
  r = f(a);
  ঘূৰাই ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

স্থির পূর্ণাঙ্ক ret_mixed_test(শূন্য) {
  ধ্রুৱ ৱর্ণ *src =
  "typedef struct ret_mixed_test_type_s {double x; long long y;} ret_mixed_test_type;"
  "ret_mixed_test_type f(ret_mixed_test_type a) {\n"
  "  ret_mixed_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";

  ঘূৰাই run_callback(src, ret_mixed_test_callback);
}

/*
 * ret_mixed2_test:
 *
 * On x86-64, a struct with two floats and two 32-bit integers should
 * be passed in one SSE register and one integer register.
 */
প্রকারনির্দেশ সংরচনা ret_mixed2_test_type_s {ভিন্ন x,x2; পূর্ণাঙ্ক y,y2;} ret_mixed2_test_type;
প্রকারনির্দেশ ret_mixed2_test_type (*ret_mixed2_test_function_type) (ret_mixed2_test_type);

স্থির পূর্ণাঙ্ক ret_mixed2_test_callback(শূন্য *ptr) {
  ret_mixed2_test_function_type f = (ret_mixed2_test_function_type)ptr;
  ret_mixed2_test_type a = {10, 5, 35, 7 };
  ret_mixed2_test_type r;
  r = f(a);
  ঘূৰাই ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

স্থির পূর্ণাঙ্ক ret_mixed2_test(শূন্য) {
  ধ্রুৱ ৱর্ণ *src =
  "typedef struct ret_mixed2_test_type_s {float x, x2; int y,y2;} ret_mixed2_test_type;"
  "ret_mixed2_test_type f(ret_mixed2_test_type a) {\n"
  "  ret_mixed2_test_type r = {a.x*5, 0, a.y*3, 0};\n"
  "  return r;\n"
  "}\n";

  ঘূৰাই run_callback(src, ret_mixed2_test_callback);
}

/*
 * ret_mixed3_test:
 *
 * On x86-64, this struct should be passed in two integer registers.
 */
প্রকারনির্দেশ সংরচনা ret_mixed3_test_type_s {ভিন্ন x; পূর্ণাঙ্ক y; ভিন্ন x2; পূর্ণাঙ্ক y2;} ret_mixed3_test_type;
প্রকারনির্দেশ ret_mixed3_test_type (*ret_mixed3_test_function_type) (ret_mixed3_test_type);

স্থির পূর্ণাঙ্ক ret_mixed3_test_callback(শূন্য *ptr) {
  ret_mixed3_test_function_type f = (ret_mixed3_test_function_type)ptr;
  ret_mixed3_test_type a = {10, 5, 35, 7 };
  ret_mixed3_test_type r;
  r = f(a);
  ঘূৰাই ((r.x == a.x*5) && (r.y2 == a.y*3)) ? 0 : -1;
}

স্থির পূর্ণাঙ্ক ret_mixed3_test(শূন্য) {
  ধ্রুৱ ৱর্ণ *src =
  "typedef struct ret_mixed3_test_type_s {float x; int y; float x2; int y2;} ret_mixed3_test_type;"
  "ret_mixed3_test_type f(ret_mixed3_test_type a) {\n"
  "  ret_mixed3_test_type r = {a.x*5, 0, 0, a.y*3};\n"
  "  return r;\n"
  "}\n";

  ঘূৰাই run_callback(src, ret_mixed3_test_callback);
}

/*
 * reg_pack_test: return a small struct which should be packed into
 * registers (Win32) during return.
 */
প্রকারনির্দেশ সংরচনা reg_pack_test_type_s {পূর্ণাঙ্ক x, y;} reg_pack_test_type;
প্রকারনির্দেশ reg_pack_test_type (*reg_pack_test_function_type) (reg_pack_test_type);

স্থির পূর্ণাঙ্ক reg_pack_test_callback(শূন্য *ptr) {
  reg_pack_test_function_type f = (reg_pack_test_function_type)ptr;
  reg_pack_test_type a = {10, 35};
  reg_pack_test_type r;
  r = f(a);
  ঘূৰাই ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

স্থির পূর্ণাঙ্ক reg_pack_test(শূন্য) {
  ধ্রুৱ ৱর্ণ *src =
  "typedef struct reg_pack_test_type_s {int x, y;} reg_pack_test_type;"
  "reg_pack_test_type f(reg_pack_test_type a) {\n"
  "  reg_pack_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";
  
  ঘূৰাই run_callback(src, reg_pack_test_callback);
}

/*
 * reg_pack_longlong_test: return a small struct which should be packed into
 * registers (x86-64) during return.
 */
প্রকারনির্দেশ সংরচনা reg_pack_longlong_test_type_s {long long x, y;} reg_pack_longlong_test_type;
প্রকারনির্দেশ reg_pack_longlong_test_type (*reg_pack_longlong_test_function_type) (reg_pack_longlong_test_type);

স্থির পূর্ণাঙ্ক reg_pack_longlong_test_callback(শূন্য *ptr) {
  reg_pack_longlong_test_function_type f = (reg_pack_longlong_test_function_type)ptr;
  reg_pack_longlong_test_type a = {10, 35};
  reg_pack_longlong_test_type r;
  r = f(a);
  ঘূৰাই ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

স্থির পূর্ণাঙ্ক reg_pack_longlong_test(শূন্য) {
  ধ্রুৱ ৱর্ণ *src =
  "typedef struct reg_pack_longlong_test_type_s {long long x, y;} reg_pack_longlong_test_type;"
  "reg_pack_longlong_test_type f(reg_pack_longlong_test_type a) {\n"
  "  reg_pack_longlong_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";
  
  ঘূৰাই run_callback(src, reg_pack_longlong_test_callback);
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
প্রকারনির্দেশ reg_pack_longlong_test_type (*ret_6plus2longlong_test_function_type) (long long, long long, long long, long long, long long, reg_pack_longlong_test_type, long long, long long);

স্থির পূর্ণাঙ্ক ret_6plus2longlong_test_callback(শূন্য *ptr) {
  ret_6plus2longlong_test_function_type f = (ret_6plus2longlong_test_function_type)ptr;
  reg_pack_longlong_test_type a = {10, 35};
  reg_pack_longlong_test_type r;
  r = f(0, 0, 0, 0, 0, a, 37, 38);
  ঘূৰাই ((r.x == 37) && (r.y == 37)) ? 0 : -1;
}

স্থির পূর্ণাঙ্ক ret_6plus2longlong_test(শূন্য) {
  ধ্রুৱ ৱর্ণ *src =
  "typedef struct reg_pack_longlong_test_type_s {long long x, y;} reg_pack_longlong_test_type;"
  "reg_pack_longlong_test_type f(long long x1, long long x2, long long x3, long long x4, long long x5, reg_pack_longlong_test_type a, long long x8, long long x9) {\n"
  "  reg_pack_longlong_test_type r = { x8, x8 };\n"
  "  return r;\n"
  "}\n";

  ঘূৰাই run_callback(src, ret_6plus2longlong_test_callback);
}

/*
 * sret_test: Create a struct large enough to be returned via sret
 * (hidden pointer as first function argument)
 */
প্রকারনির্দেশ সংরচনা sret_test_type_s {long long a, b, c;} sret_test_type;
প্রকারনির্দেশ sret_test_type (*sret_test_function_type) (sret_test_type);

স্থির পূর্ণাঙ্ক sret_test_callback(শূন্য *ptr) {
  sret_test_function_type f = (sret_test_function_type)(ptr);
  sret_test_type x = {5436LL, 658277698LL, 43878957LL};
  sret_test_type r = f(x);
  ঘূৰাই ((r.a==x.a*35)&&(r.b==x.b*19)&&(r.c==x.c*21)) ? 0 : -1;
}

স্থির পূর্ণাঙ্ক sret_test(শূন্য) {
  ধ্রুৱ ৱর্ণ *src =
  "typedef struct sret_test_type_s {long long a, b, c;} sret_test_type;\n"
  "sret_test_type f(sret_test_type x) {\n"
  "  sret_test_type r = {x.a*35, x.b*19, x.c*21};\n"
  "  return r;\n"
  "}\n";
  
  ঘূৰাই run_callback(src, sret_test_callback);
}

/*
 * one_member_union_test:
 * 
 * In the x86-64 ABI a union should always be passed on the stack. However
 * it appears that a single member union is treated by GCC as its member.
 */
প্রকারনির্দেশ সঙ্ঘ one_member_union_test_type_u {পূর্ণাঙ্ক x;} one_member_union_test_type;
প্রকারনির্দেশ one_member_union_test_type (*one_member_union_test_function_type) (one_member_union_test_type);

স্থির পূর্ণাঙ্ক one_member_union_test_callback(শূন্য *ptr) {
  one_member_union_test_function_type f = (one_member_union_test_function_type)ptr;
  one_member_union_test_type a, b;
  a.x = 34;
  b = f(a);
  ঘূৰাই (b.x == a.x*2) ? 0 : -1;
}

স্থির পূর্ণাঙ্ক one_member_union_test(শূন্য) {
  ধ্রুৱ ৱর্ণ *src =
  "typedef union one_member_union_test_type_u {int x;} one_member_union_test_type;\n"
  "one_member_union_test_type f(one_member_union_test_type a) {\n"
  "  one_member_union_test_type b;\n"
  "  b.x = a.x * 2;\n"
  "  return b;\n"
  "}\n";
  ঘূৰাই run_callback(src, one_member_union_test_callback);
}

/*
 * two_member_union_test:
 * 
 * In the x86-64 ABI a union should always be passed on the stack.
 */
প্রকারনির্দেশ সঙ্ঘ two_member_union_test_type_u {পূর্ণাঙ্ক x; long y;} two_member_union_test_type;
প্রকারনির্দেশ two_member_union_test_type (*two_member_union_test_function_type) (two_member_union_test_type);

স্থির পূর্ণাঙ্ক two_member_union_test_callback(শূন্য *ptr) {
  two_member_union_test_function_type f = (two_member_union_test_function_type)ptr;
  two_member_union_test_type a, b;
  a.x = 34;
  b = f(a);
  ঘূৰাই (b.x == a.x*2) ? 0 : -1;
}

স্থির পূর্ণাঙ্ক two_member_union_test(শূন্য) {
  ধ্রুৱ ৱর্ণ *src =
  "typedef union two_member_union_test_type_u {int x; long y;} two_member_union_test_type;\n"
  "two_member_union_test_type f(two_member_union_test_type a) {\n"
  "  two_member_union_test_type b;\n"
  "  b.x = a.x * 2;\n"
  "  return b;\n"
  "}\n";
  ঘূৰাই run_callback(src, two_member_union_test_callback);
}

/*
 * Win64 calling convention test.
 */

প্রকারনির্দেশ সংরচনা many_struct_test_type_s {long long a, b, c;} many_struct_test_type;
প্রকারনির্দেশ many_struct_test_type (*many_struct_test_function_type) (many_struct_test_type,many_struct_test_type,many_struct_test_type,many_struct_test_type,many_struct_test_type,many_struct_test_type);
 
স্থির পূর্ণাঙ্ক many_struct_test_callback(শূন্য *ptr) {
  many_struct_test_function_type f = (many_struct_test_function_type)ptr;
  many_struct_test_type v = {1, 2, 3};
  many_struct_test_type r = f(v,v,v,v,v,v);
  ঘূৰাই ((r.a == 6) && (r.b == 12) && (r.c == 18))?0:-1;
}

স্থির পূর্ণাঙ্ক many_struct_test(শূন্য) {
  ধ্রুৱ ৱর্ণ *src =
  "typedef struct many_struct_test_type_s {long long a, b, c;} many_struct_test_type;\n"
  "many_struct_test_type f(many_struct_test_type x1, many_struct_test_type x2, many_struct_test_type x3, many_struct_test_type x4, many_struct_test_type x5, many_struct_test_type x6) {\n"
  "  many_struct_test_type y;\n"
  "  y.a = x1.a + x2.a + x3.a + x4.a + x5.a + x6.a;\n"
  "  y.b = x1.b + x2.b + x3.b + x4.b + x5.b + x6.b;\n"
  "  y.c = x1.c + x2.c + x3.c + x4.c + x5.c + x6.c;\n"
  "  return y;\n"
  "}\n";
  ঘূৰাই run_callback(src, many_struct_test_callback);
}

/*
 * Win64 calling convention test.
 */

প্রকারনির্দেশ সংরচনা many_struct_test_2_type_s {পূর্ণাঙ্ক a, b;} many_struct_test_2_type;
প্রকারনির্দেশ many_struct_test_2_type (*many_struct_test_2_function_type) (many_struct_test_2_type,many_struct_test_2_type,many_struct_test_2_type,many_struct_test_2_type,many_struct_test_2_type,many_struct_test_2_type);
 
স্থির পূর্ণাঙ্ক many_struct_test_2_callback(শূন্য *ptr) {
  many_struct_test_2_function_type f = (many_struct_test_2_function_type)ptr;
  many_struct_test_2_type v = {1,2};
  many_struct_test_2_type r = f(v,v,v,v,v,v);
  ঘূৰাই ((r.a == 6) && (r.b == 12))?0:-1;
}

স্থির পূর্ণাঙ্ক many_struct_test_2(শূন্য) {
  ধ্রুৱ ৱর্ণ *src =
  "typedef struct many_struct_test_2_type_s {int a, b;} many_struct_test_2_type;\n"
  "many_struct_test_2_type f(many_struct_test_2_type x1, many_struct_test_2_type x2, many_struct_test_2_type x3, many_struct_test_2_type x4, many_struct_test_2_type x5, many_struct_test_2_type x6) {\n"
  "  many_struct_test_2_type y;\n"
  "  y.a = x1.a + x2.a + x3.a + x4.a + x5.a + x6.a;\n"
  "  y.b = x1.b + x2.b + x3.b + x4.b + x5.b + x6.b;\n"
  "  return y;\n"
  "}\n";
  ঘূৰাই run_callback(src, many_struct_test_2_callback);
}

/*
 * Win64 calling convention test.
 */

প্রকারনির্দেশ সংরচনা many_struct_test_3_type_s {পূর্ণাঙ্ক a, b;} many_struct_test_3_type;
প্রকারনির্দেশ many_struct_test_3_type (*many_struct_test_3_function_type) (many_struct_test_3_type,many_struct_test_3_type,many_struct_test_3_type,many_struct_test_3_type,many_struct_test_3_type,many_struct_test_3_type, ...);
প্রকারনির্দেশ সংরচনা many_struct_test_3_struct_type { many_struct_test_3_function_type f; many_struct_test_3_function_type *f2; } many_struct_test_3_struct_type;

স্থির শূন্য many_struct_test_3_dummy(দ্ৱিগুণ d, ...)
{
  চঞ্চল দ্ৱিগুণ x = d;
}

স্থির পূর্ণাঙ্ক many_struct_test_3_callback(শূন্য *ptr) {
  many_struct_test_3_struct_type s = { ptr, };
  many_struct_test_3_struct_type *s2 = &s;
  s2->f2 = &s2->f;
  many_struct_test_3_dummy(1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, &s2);
  many_struct_test_3_function_type f = *(s2->f2);
  many_struct_test_3_type v = {1,2};
  many_struct_test_3_type r = (*((s2->f2=&f)+0))(v,v,v,v,v,v,1.0);
  ঘূৰাই ((r.a == 6) && (r.b == 12))?0:-1;
}

স্থির পূর্ণাঙ্ক many_struct_test_3(শূন্য) {
  ধ্রুৱ ৱর্ণ *src =
  "typedef struct many_struct_test_3_type_s {int a, b;} many_struct_test_3_type;\n"
  "many_struct_test_3_type f(many_struct_test_3_type x1, many_struct_test_3_type x2, many_struct_test_3_type x3, many_struct_test_3_type x4, many_struct_test_3_type x5, many_struct_test_3_type x6, ...) {\n"
  "  many_struct_test_3_type y;\n"
  "  y.a = x1.a + x2.a + x3.a + x4.a + x5.a + x6.a;\n"
  "  y.b = x1.b + x2.b + x3.b + x4.b + x5.b + x6.b;\n"
  "  return y;\n"
  "}\n";
  ঘূৰাই run_callback(src, many_struct_test_3_callback);
}

/*
 * stdarg_test: Test variable argument list ABI
 */

প্রকারনির্দেশ সংরচনা {long long a, b, c;} stdarg_test_struct_type;
প্রকারনির্দেশ শূন্য (*stdarg_test_function_type) (পূর্ণাঙ্ক,পূর্ণাঙ্ক,পূর্ণাঙ্ক,...);

স্থির পূর্ণাঙ্ক stdarg_test_callback(শূন্য *ptr) {
  stdarg_test_function_type f = (stdarg_test_function_type)ptr;
  পূর্ণাঙ্ক x;
  দ্ৱিগুণ y;
  stdarg_test_struct_type z = {1, 2, 3}, w;
  f(10, 10, 5,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, &x,
    1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, &y,
    z, z, z, z, z, &w);
  ঘূৰাই ((x == 55) && (y == 55) && (w.a == 5) && (w.b == 10) && (w.c == 15)) ? 0 : -1;
}

স্থির পূর্ণাঙ্ক stdarg_test(শূন্য) {
  ধ্রুৱ ৱর্ণ *src =
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
  ঘূৰাই run_callback(src, stdarg_test_callback);
}

প্রকারনির্দেশ সংরচনা {long long a, b;} stdarg_many_test_struct_type;
প্রকারনির্দেশ শূন্য (*stdarg_many_test_function_type) (পূর্ণাঙ্ক, পূর্ণাঙ্ক, পূর্ণাঙ্ক, পূর্ণাঙ্ক, পূর্ণাঙ্ক,
						stdarg_many_test_struct_type,
						পূর্ণাঙ্ক, পূর্ণাঙ্ক, ...);

স্থির পূর্ণাঙ্ক stdarg_many_test_callback(শূন্য *ptr)
{
  stdarg_many_test_function_type f = (stdarg_many_test_function_type)ptr;
  পূর্ণাঙ্ক x;
  stdarg_many_test_struct_type l = {10, 11};
  f(1, 2, 3, 4, 5, l, 6, 7, &x, 44);
  ঘূৰাই x == 44 ? 0 : -1;
}

স্থির পূর্ণাঙ্ক stdarg_many_test(শূন্য)
{
  ধ্রুৱ ৱর্ণ *src =
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
  ঘূৰাই run_callback(src, stdarg_many_test_callback);
}

/*
 * Test Win32 stdarg handling, since the calling convention will pass a pointer
 * to the struct and the stdarg pointer must point to that pointer initially.
 */

প্রকারনির্দেশ সংরচনা {long long a, b, c;} stdarg_struct_test_struct_type;
প্রকারনির্দেশ পূর্ণাঙ্ক (*stdarg_struct_test_function_type) (stdarg_struct_test_struct_type a, ...);

স্থির পূর্ণাঙ্ক stdarg_struct_test_callback(শূন্য *ptr) {
  stdarg_struct_test_function_type f = (stdarg_struct_test_function_type)ptr;
  stdarg_struct_test_struct_type v = {10, 35, 99};
  পূর্ণাঙ্ক x = f(v, 234);
  ঘূৰাই (x == 378) ? 0 : -1;
}

স্থির পূর্ণাঙ্ক stdarg_struct_test(শূন্য) {
  ধ্রুৱ ৱর্ণ *src =
  "#include <stdarg.h>\n"
  "typedef struct {long long a, b, c;} stdarg_struct_test_struct_type;\n"
  "int f(stdarg_struct_test_struct_type a, ...) {\n"
  "  va_list ap;\n"
  "  va_start(ap, a);\n"
  "  int z = va_arg(ap, int);\n"
  "  va_end(ap);\n"
  "  return z + a.a + a.b + a.c;\n"
  "}\n";
  ঘূৰাই run_callback(src, stdarg_struct_test_callback);
}

/* Test that x86-64 arranges the stack correctly for arguments with alignment >8 bytes */

প্রকারনির্দেশ LONG_DOUBLE (*arg_align_test_callback_type) (LONG_DOUBLE,পূর্ণাঙ্ক,LONG_DOUBLE,পূর্ণাঙ্ক,LONG_DOUBLE);

স্থির পূর্ণাঙ্ক arg_align_test_callback(শূন্য *ptr) {
  arg_align_test_callback_type f = (arg_align_test_callback_type)ptr;
  long দ্ৱিগুণ x = f(12, 0, 25, 0, 37);
  ঘূৰাই (x == 74) ? 0 : -1;
}

স্থির পূর্ণাঙ্ক arg_align_test(শূন্য) {
  ধ্রুৱ ৱর্ণ *src = 
  "long double f(long double a, int b, long double c, int d, long double e) {\n"
  "  return a + c + e;\n"
  "}\n";
  ঘূৰাই run_callback(src, arg_align_test_callback);
}

#define RUN_TEST(t) \
  যদি (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    যদি (t() == 0) { \
      fputs("success\n", stdout); \
    } অন্যথা { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

পূর্ণাঙ্ক main(পূর্ণাঙ্ক argc, ৱর্ণ **argv) {
  পূর্ণাঙ্ক i;
  ধ্রুৱ ৱর্ণ *testname = রিক্ত;
  পূর্ণাঙ্ক retval = EXIT_SUCCESS;
  
  /* if tcclib.h and libtcc1.a are not installed, where can we find them */
  বাবে (i = 1; i < argc; ++i) {
    যদি (!memcmp(argv[i], "run_test=", 9))
      testname = argv[i] + 9;
  }

  g_argv = argv, g_argc = argc;

  RUN_TEST(ret_int_test);
  RUN_TEST(ret_longlong_test);
  RUN_TEST(ret_float_test);
  RUN_TEST(ret_double_test);
  RUN_TEST(ret_longdouble_test);
  RUN_TEST(ret_2float_test);
  RUN_TEST(ret_2double_test);
  RUN_TEST(ret_8plus2double_test);
  RUN_TEST(ret_6plus2longlong_test);
#যদি !defined __x86_64__ || defined _WIN32
  /* currently broken on x86_64 linux */
  RUN_TEST(ret_mixed_test);
  RUN_TEST(ret_mixed2_test);
#endif
  RUN_TEST(ret_mixed3_test);
  RUN_TEST(reg_pack_test);
  RUN_TEST(reg_pack_longlong_test);
  RUN_TEST(sret_test);
  RUN_TEST(one_member_union_test);
  RUN_TEST(two_member_union_test);
  RUN_TEST(many_struct_test);
  RUN_TEST(many_struct_test_2);
  RUN_TEST(many_struct_test_3);
  RUN_TEST(stdarg_test);
  RUN_TEST(stdarg_many_test);
  RUN_TEST(stdarg_struct_test);
  RUN_TEST(arg_align_test);
  ঘূৰাই retval;
}

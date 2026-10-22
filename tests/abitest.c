#അന്തര്ഭാവ <libtcc.h>
#അന്തര്ഭാവ <stdlib.h>
#അന്തര്ഭാവ <stdio.h>
#അന്തര്ഭാവ <string.h>
#അന്തര്ഭാവ <stdarg.h>

// MinGW has 80-bit rather than 64-bit long double which isn't compatible with TCC or MSVC
#എങ്കിൽ defined(_WIN32) && defined(__GNUC__)
#define LONG_DOUBLE ഇരട്ട
#define LONG_DOUBLE_LITERAL(x) x
#അല്ലെങ്കിൽ
#define LONG_DOUBLE long ഇരട്ട
#define LONG_DOUBLE_LITERAL(x) x ## L
#endif

സ്ഥിതം പൂർണ്ണസംഖ്യ g_argc;
സ്ഥിതം അക്ഷരം **g_argv;

സ്ഥിതം ശൂന്യം set_options(TCCState *s, പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv)
{
    പൂർണ്ണസംഖ്യ i;
    വേണ്ടി (i = 1; i < argc; ++i) {
        അക്ഷരം *a = argv[i];
        എങ്കിൽ (a[0] == '-') {
            എങ്കിൽ (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            അല്ലെങ്കിൽ എങ്കിൽ (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            അല്ലെങ്കിൽ എങ്കിൽ (a[1] == 'L')
                tcc_add_library_path(s, a+2);
        }
    }
}

തരനിർവചനം പൂർണ്ണസംഖ്യ (*callback_type) (ശൂന്യം*);

/*
 * Compile source code and call a callback with a pointer to the symbol "f".
 */
സ്ഥിതം പൂർണ്ണസംഖ്യ run_callback(സ്ഥിരം അക്ഷരം *src, callback_type callback) {
  TCCState *s;
  പൂർണ്ണസംഖ്യ result;
  ശൂന്യം *ptr;
  
  s = tcc_new();
  എങ്കിൽ (!s)
    തിരികെ -1;

  set_options(s, g_argc, g_argv);

  എങ്കിൽ (tcc_set_output_type(s, TCC_OUTPUT_MEMORY) == -1)
    തിരികെ -1;
  എങ്കിൽ (tcc_compile_string(s, src) == -1)
    തിരികെ -1;
  എങ്കിൽ (tcc_relocate(s) == -1)
    തിരികെ -1;
  
  ptr = tcc_get_ചിഹ്നം(s, "f");
  എങ്കിൽ (!ptr)
    തിരികെ -1;
  result = callback(ptr);
  
  tcc_delete(s);
  
  തിരികെ result;
}

#define STR2(x) #x
#define STR(x) STR2(x)

#define RET_PRIMITIVE_TEST(name, type, val) \
  സ്ഥിതം പൂർണ്ണസംഖ്യ ret_ ## name ## _test_callback(ശൂന്യം *ptr) { \
    type (*callback) (type) = (type(*)(type))ptr; \
    type x = val; \
    type y = callback(x); \
    തിരികെ (y == x+x) ? 0 : -1; \
  } \
  \
  സ്ഥിതം പൂർണ്ണസംഖ്യ ret_ ## name ## _test(ശൂന്യം) { \
    സ്ഥിരം അക്ഷരം *src = STR(type) " f(" STR(type) " x) {return x+x;}"; \
    തിരികെ run_callback(src, ret_ ## name ## _test_callback); \
  }

RET_PRIMITIVE_TEST(പൂർണ്ണസംഖ്യ, പൂർണ്ണസംഖ്യ, 70000)
RET_PRIMITIVE_TEST(longlong, long long, 4333369356528LL)
RET_PRIMITIVE_TEST(ദശാംശം, ദശാംശം, 63.0)
RET_PRIMITIVE_TEST(ഇരട്ട, ഇരട്ട, 14789798.0)
RET_PRIMITIVE_TEST(longdouble, LONG_DOUBLE, LONG_DOUBLE_LITERAL(378943892.0))

/*
 * ret_2float_test:
 * 
 * On x86-64, a struct with 2 floats should be packed into a single
 * SSE register (VT_DOUBLE is used for this purpose).
 */
തരനിർവചനം ഘടന ret_2float_test_type_s {ദശാംശം x, y;} ret_2float_test_type;
തരനിർവചനം ret_2float_test_type (*ret_2float_test_function_type) (ret_2float_test_type);

സ്ഥിതം പൂർണ്ണസംഖ്യ ret_2float_test_callback(ശൂന്യം *ptr) {
  ret_2float_test_function_type f = (ret_2float_test_function_type)ptr;
  ret_2float_test_type a = {10, 35};
  ret_2float_test_type r;
  r = f(a);
  തിരികെ ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ ret_2float_test(ശൂന്യം) {
  സ്ഥിരം അക്ഷരം *src =
  "typedef struct ret_2float_test_type_s {float x, y;} ret_2float_test_type;"
  "ret_2float_test_type f(ret_2float_test_type a) {\n"
  "  ret_2float_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";

  തിരികെ run_callback(src, ret_2float_test_callback);
}

/*
 * ret_2double_test:
 * 
 * On x86-64, a struct with 2 doubles should be passed in two SSE
 * registers.
 */
തരനിർവചനം ഘടന ret_2double_test_type_s {ഇരട്ട x, y;} ret_2double_test_type;
തരനിർവചനം ret_2double_test_type (*ret_2double_test_function_type) (ret_2double_test_type);

സ്ഥിതം പൂർണ്ണസംഖ്യ ret_2double_test_callback(ശൂന്യം *ptr) {
  ret_2double_test_function_type f = (ret_2double_test_function_type)ptr;
  ret_2double_test_type a = {10, 35};
  ret_2double_test_type r;
  r = f(a);
  തിരികെ ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ ret_2double_test(ശൂന്യം) {
  സ്ഥിരം അക്ഷരം *src =
  "typedef struct ret_2double_test_type_s {double x, y;} ret_2double_test_type;"
  "ret_2double_test_type f(ret_2double_test_type a) {\n"
  "  ret_2double_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";

  തിരികെ run_callback(src, ret_2double_test_callback);
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
തരനിർവചനം ret_2double_test_type (*ret_8plus2double_test_function_type) (ഇരട്ട, ഇരട്ട, ഇരട്ട, ഇരട്ട, ഇരട്ട, ഇരട്ട, ഇരട്ട, ret_2double_test_type, ഇരട്ട, ഇരട്ട);

സ്ഥിതം പൂർണ്ണസംഖ്യ ret_8plus2double_test_callback(ശൂന്യം *ptr) {
  ret_8plus2double_test_function_type f = (ret_8plus2double_test_function_type)ptr;
  ret_2double_test_type a = {10, 35};
  ret_2double_test_type r;
  r = f(0, 0, 0, 0, 0, 0, 0, a, 37, 38);
  തിരികെ ((r.x == 37) && (r.y == 37)) ? 0 : -1;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ ret_8plus2double_test(ശൂന്യം) {
  സ്ഥിരം അക്ഷരം *src =
  "typedef struct ret_2double_test_type_s {double x, y;} ret_2double_test_type;"
  "ret_2double_test_type f(double x1, double x2, double x3, double x4, double x5, double x6, double x7, ret_2double_test_type a, double x8, double x9) {\n"
  "  ret_2double_test_type r = { x8, x8 };\n"
  "  return r;\n"
  "}\n";

  തിരികെ run_callback(src, ret_8plus2double_test_callback);
}

/*
 * ret_mixed_test:
 *
 * On x86-64, a struct with a double and a 64-bit integer should be
 * passed in one SSE register and one integer register.
 */
തരനിർവചനം ഘടന ret_mixed_test_type_s {ഇരട്ട x; long long y;} ret_mixed_test_type;
തരനിർവചനം ret_mixed_test_type (*ret_mixed_test_function_type) (ret_mixed_test_type);

സ്ഥിതം പൂർണ്ണസംഖ്യ ret_mixed_test_callback(ശൂന്യം *ptr) {
  ret_mixed_test_function_type f = (ret_mixed_test_function_type)ptr;
  ret_mixed_test_type a = {10, 35};
  ret_mixed_test_type r;
  r = f(a);
  തിരികെ ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ ret_mixed_test(ശൂന്യം) {
  സ്ഥിരം അക്ഷരം *src =
  "typedef struct ret_mixed_test_type_s {double x; long long y;} ret_mixed_test_type;"
  "ret_mixed_test_type f(ret_mixed_test_type a) {\n"
  "  ret_mixed_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";

  തിരികെ run_callback(src, ret_mixed_test_callback);
}

/*
 * ret_mixed2_test:
 *
 * On x86-64, a struct with two floats and two 32-bit integers should
 * be passed in one SSE register and one integer register.
 */
തരനിർവചനം ഘടന ret_mixed2_test_type_s {ദശാംശം x,x2; പൂർണ്ണസംഖ്യ y,y2;} ret_mixed2_test_type;
തരനിർവചനം ret_mixed2_test_type (*ret_mixed2_test_function_type) (ret_mixed2_test_type);

സ്ഥിതം പൂർണ്ണസംഖ്യ ret_mixed2_test_callback(ശൂന്യം *ptr) {
  ret_mixed2_test_function_type f = (ret_mixed2_test_function_type)ptr;
  ret_mixed2_test_type a = {10, 5, 35, 7 };
  ret_mixed2_test_type r;
  r = f(a);
  തിരികെ ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ ret_mixed2_test(ശൂന്യം) {
  സ്ഥിരം അക്ഷരം *src =
  "typedef struct ret_mixed2_test_type_s {float x, x2; int y,y2;} ret_mixed2_test_type;"
  "ret_mixed2_test_type f(ret_mixed2_test_type a) {\n"
  "  ret_mixed2_test_type r = {a.x*5, 0, a.y*3, 0};\n"
  "  return r;\n"
  "}\n";

  തിരികെ run_callback(src, ret_mixed2_test_callback);
}

/*
 * ret_mixed3_test:
 *
 * On x86-64, this struct should be passed in two integer registers.
 */
തരനിർവചനം ഘടന ret_mixed3_test_type_s {ദശാംശം x; പൂർണ്ണസംഖ്യ y; ദശാംശം x2; പൂർണ്ണസംഖ്യ y2;} ret_mixed3_test_type;
തരനിർവചനം ret_mixed3_test_type (*ret_mixed3_test_function_type) (ret_mixed3_test_type);

സ്ഥിതം പൂർണ്ണസംഖ്യ ret_mixed3_test_callback(ശൂന്യം *ptr) {
  ret_mixed3_test_function_type f = (ret_mixed3_test_function_type)ptr;
  ret_mixed3_test_type a = {10, 5, 35, 7 };
  ret_mixed3_test_type r;
  r = f(a);
  തിരികെ ((r.x == a.x*5) && (r.y2 == a.y*3)) ? 0 : -1;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ ret_mixed3_test(ശൂന്യം) {
  സ്ഥിരം അക്ഷരം *src =
  "typedef struct ret_mixed3_test_type_s {float x; int y; float x2; int y2;} ret_mixed3_test_type;"
  "ret_mixed3_test_type f(ret_mixed3_test_type a) {\n"
  "  ret_mixed3_test_type r = {a.x*5, 0, 0, a.y*3};\n"
  "  return r;\n"
  "}\n";

  തിരികെ run_callback(src, ret_mixed3_test_callback);
}

/*
 * reg_pack_test: return a small struct which should be packed into
 * registers (Win32) during return.
 */
തരനിർവചനം ഘടന reg_pack_test_type_s {പൂർണ്ണസംഖ്യ x, y;} reg_pack_test_type;
തരനിർവചനം reg_pack_test_type (*reg_pack_test_function_type) (reg_pack_test_type);

സ്ഥിതം പൂർണ്ണസംഖ്യ reg_pack_test_callback(ശൂന്യം *ptr) {
  reg_pack_test_function_type f = (reg_pack_test_function_type)ptr;
  reg_pack_test_type a = {10, 35};
  reg_pack_test_type r;
  r = f(a);
  തിരികെ ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ reg_pack_test(ശൂന്യം) {
  സ്ഥിരം അക്ഷരം *src =
  "typedef struct reg_pack_test_type_s {int x, y;} reg_pack_test_type;"
  "reg_pack_test_type f(reg_pack_test_type a) {\n"
  "  reg_pack_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";
  
  തിരികെ run_callback(src, reg_pack_test_callback);
}

/*
 * reg_pack_longlong_test: return a small struct which should be packed into
 * registers (x86-64) during return.
 */
തരനിർവചനം ഘടന reg_pack_longlong_test_type_s {long long x, y;} reg_pack_longlong_test_type;
തരനിർവചനം reg_pack_longlong_test_type (*reg_pack_longlong_test_function_type) (reg_pack_longlong_test_type);

സ്ഥിതം പൂർണ്ണസംഖ്യ reg_pack_longlong_test_callback(ശൂന്യം *ptr) {
  reg_pack_longlong_test_function_type f = (reg_pack_longlong_test_function_type)ptr;
  reg_pack_longlong_test_type a = {10, 35};
  reg_pack_longlong_test_type r;
  r = f(a);
  തിരികെ ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ reg_pack_longlong_test(ശൂന്യം) {
  സ്ഥിരം അക്ഷരം *src =
  "typedef struct reg_pack_longlong_test_type_s {long long x, y;} reg_pack_longlong_test_type;"
  "reg_pack_longlong_test_type f(reg_pack_longlong_test_type a) {\n"
  "  reg_pack_longlong_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";
  
  തിരികെ run_callback(src, reg_pack_longlong_test_callback);
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
തരനിർവചനം reg_pack_longlong_test_type (*ret_6plus2longlong_test_function_type) (long long, long long, long long, long long, long long, reg_pack_longlong_test_type, long long, long long);

സ്ഥിതം പൂർണ്ണസംഖ്യ ret_6plus2longlong_test_callback(ശൂന്യം *ptr) {
  ret_6plus2longlong_test_function_type f = (ret_6plus2longlong_test_function_type)ptr;
  reg_pack_longlong_test_type a = {10, 35};
  reg_pack_longlong_test_type r;
  r = f(0, 0, 0, 0, 0, a, 37, 38);
  തിരികെ ((r.x == 37) && (r.y == 37)) ? 0 : -1;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ ret_6plus2longlong_test(ശൂന്യം) {
  സ്ഥിരം അക്ഷരം *src =
  "typedef struct reg_pack_longlong_test_type_s {long long x, y;} reg_pack_longlong_test_type;"
  "reg_pack_longlong_test_type f(long long x1, long long x2, long long x3, long long x4, long long x5, reg_pack_longlong_test_type a, long long x8, long long x9) {\n"
  "  reg_pack_longlong_test_type r = { x8, x8 };\n"
  "  return r;\n"
  "}\n";

  തിരികെ run_callback(src, ret_6plus2longlong_test_callback);
}

/*
 * sret_test: Create a struct large enough to be returned via sret
 * (hidden pointer as first function argument)
 */
തരനിർവചനം ഘടന sret_test_type_s {long long a, b, c;} sret_test_type;
തരനിർവചനം sret_test_type (*sret_test_function_type) (sret_test_type);

സ്ഥിതം പൂർണ്ണസംഖ്യ sret_test_callback(ശൂന്യം *ptr) {
  sret_test_function_type f = (sret_test_function_type)(ptr);
  sret_test_type x = {5436LL, 658277698LL, 43878957LL};
  sret_test_type r = f(x);
  തിരികെ ((r.a==x.a*35)&&(r.b==x.b*19)&&(r.c==x.c*21)) ? 0 : -1;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ sret_test(ശൂന്യം) {
  സ്ഥിരം അക്ഷരം *src =
  "typedef struct sret_test_type_s {long long a, b, c;} sret_test_type;\n"
  "sret_test_type f(sret_test_type x) {\n"
  "  sret_test_type r = {x.a*35, x.b*19, x.c*21};\n"
  "  return r;\n"
  "}\n";
  
  തിരികെ run_callback(src, sret_test_callback);
}

/*
 * one_member_union_test:
 * 
 * In the x86-64 ABI a union should always be passed on the stack. However
 * it appears that a single member union is treated by GCC as its member.
 */
തരനിർവചനം സംഘം one_member_union_test_type_u {പൂർണ്ണസംഖ്യ x;} one_member_union_test_type;
തരനിർവചനം one_member_union_test_type (*one_member_union_test_function_type) (one_member_union_test_type);

സ്ഥിതം പൂർണ്ണസംഖ്യ one_member_union_test_callback(ശൂന്യം *ptr) {
  one_member_union_test_function_type f = (one_member_union_test_function_type)ptr;
  one_member_union_test_type a, b;
  a.x = 34;
  b = f(a);
  തിരികെ (b.x == a.x*2) ? 0 : -1;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ one_member_union_test(ശൂന്യം) {
  സ്ഥിരം അക്ഷരം *src =
  "typedef union one_member_union_test_type_u {int x;} one_member_union_test_type;\n"
  "one_member_union_test_type f(one_member_union_test_type a) {\n"
  "  one_member_union_test_type b;\n"
  "  b.x = a.x * 2;\n"
  "  return b;\n"
  "}\n";
  തിരികെ run_callback(src, one_member_union_test_callback);
}

/*
 * two_member_union_test:
 * 
 * In the x86-64 ABI a union should always be passed on the stack.
 */
തരനിർവചനം സംഘം two_member_union_test_type_u {പൂർണ്ണസംഖ്യ x; long y;} two_member_union_test_type;
തരനിർവചനം two_member_union_test_type (*two_member_union_test_function_type) (two_member_union_test_type);

സ്ഥിതം പൂർണ്ണസംഖ്യ two_member_union_test_callback(ശൂന്യം *ptr) {
  two_member_union_test_function_type f = (two_member_union_test_function_type)ptr;
  two_member_union_test_type a, b;
  a.x = 34;
  b = f(a);
  തിരികെ (b.x == a.x*2) ? 0 : -1;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ two_member_union_test(ശൂന്യം) {
  സ്ഥിരം അക്ഷരം *src =
  "typedef union two_member_union_test_type_u {int x; long y;} two_member_union_test_type;\n"
  "two_member_union_test_type f(two_member_union_test_type a) {\n"
  "  two_member_union_test_type b;\n"
  "  b.x = a.x * 2;\n"
  "  return b;\n"
  "}\n";
  തിരികെ run_callback(src, two_member_union_test_callback);
}

/*
 * Win64 calling convention test.
 */

തരനിർവചനം ഘടന many_struct_test_type_s {long long a, b, c;} many_struct_test_type;
തരനിർവചനം many_struct_test_type (*many_struct_test_function_type) (many_struct_test_type,many_struct_test_type,many_struct_test_type,many_struct_test_type,many_struct_test_type,many_struct_test_type);
 
സ്ഥിതം പൂർണ്ണസംഖ്യ many_struct_test_callback(ശൂന്യം *ptr) {
  many_struct_test_function_type f = (many_struct_test_function_type)ptr;
  many_struct_test_type v = {1, 2, 3};
  many_struct_test_type r = f(v,v,v,v,v,v);
  തിരികെ ((r.a == 6) && (r.b == 12) && (r.c == 18))?0:-1;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ many_struct_test(ശൂന്യം) {
  സ്ഥിരം അക്ഷരം *src =
  "typedef struct many_struct_test_type_s {long long a, b, c;} many_struct_test_type;\n"
  "many_struct_test_type f(many_struct_test_type x1, many_struct_test_type x2, many_struct_test_type x3, many_struct_test_type x4, many_struct_test_type x5, many_struct_test_type x6) {\n"
  "  many_struct_test_type y;\n"
  "  y.a = x1.a + x2.a + x3.a + x4.a + x5.a + x6.a;\n"
  "  y.b = x1.b + x2.b + x3.b + x4.b + x5.b + x6.b;\n"
  "  y.c = x1.c + x2.c + x3.c + x4.c + x5.c + x6.c;\n"
  "  return y;\n"
  "}\n";
  തിരികെ run_callback(src, many_struct_test_callback);
}

/*
 * Win64 calling convention test.
 */

തരനിർവചനം ഘടന many_struct_test_2_type_s {പൂർണ്ണസംഖ്യ a, b;} many_struct_test_2_type;
തരനിർവചനം many_struct_test_2_type (*many_struct_test_2_function_type) (many_struct_test_2_type,many_struct_test_2_type,many_struct_test_2_type,many_struct_test_2_type,many_struct_test_2_type,many_struct_test_2_type);
 
സ്ഥിതം പൂർണ്ണസംഖ്യ many_struct_test_2_callback(ശൂന്യം *ptr) {
  many_struct_test_2_function_type f = (many_struct_test_2_function_type)ptr;
  many_struct_test_2_type v = {1,2};
  many_struct_test_2_type r = f(v,v,v,v,v,v);
  തിരികെ ((r.a == 6) && (r.b == 12))?0:-1;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ many_struct_test_2(ശൂന്യം) {
  സ്ഥിരം അക്ഷരം *src =
  "typedef struct many_struct_test_2_type_s {int a, b;} many_struct_test_2_type;\n"
  "many_struct_test_2_type f(many_struct_test_2_type x1, many_struct_test_2_type x2, many_struct_test_2_type x3, many_struct_test_2_type x4, many_struct_test_2_type x5, many_struct_test_2_type x6) {\n"
  "  many_struct_test_2_type y;\n"
  "  y.a = x1.a + x2.a + x3.a + x4.a + x5.a + x6.a;\n"
  "  y.b = x1.b + x2.b + x3.b + x4.b + x5.b + x6.b;\n"
  "  return y;\n"
  "}\n";
  തിരികെ run_callback(src, many_struct_test_2_callback);
}

/*
 * Win64 calling convention test.
 */

തരനിർവചനം ഘടന many_struct_test_3_type_s {പൂർണ്ണസംഖ്യ a, b;} many_struct_test_3_type;
തരനിർവചനം many_struct_test_3_type (*many_struct_test_3_function_type) (many_struct_test_3_type,many_struct_test_3_type,many_struct_test_3_type,many_struct_test_3_type,many_struct_test_3_type,many_struct_test_3_type, ...);
തരനിർവചനം ഘടന many_struct_test_3_struct_type { many_struct_test_3_function_type f; many_struct_test_3_function_type *f2; } many_struct_test_3_struct_type;

സ്ഥിതം ശൂന്യം many_struct_test_3_dummy(ഇരട്ട d, ...)
{
  അസ്ഥിര ഇരട്ട x = d;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ many_struct_test_3_callback(ശൂന്യം *ptr) {
  many_struct_test_3_struct_type s = { ptr, };
  many_struct_test_3_struct_type *s2 = &s;
  s2->f2 = &s2->f;
  many_struct_test_3_dummy(1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, &s2);
  many_struct_test_3_function_type f = *(s2->f2);
  many_struct_test_3_type v = {1,2};
  many_struct_test_3_type r = (*((s2->f2=&f)+0))(v,v,v,v,v,v,1.0);
  തിരികെ ((r.a == 6) && (r.b == 12))?0:-1;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ many_struct_test_3(ശൂന്യം) {
  സ്ഥിരം അക്ഷരം *src =
  "typedef struct many_struct_test_3_type_s {int a, b;} many_struct_test_3_type;\n"
  "many_struct_test_3_type f(many_struct_test_3_type x1, many_struct_test_3_type x2, many_struct_test_3_type x3, many_struct_test_3_type x4, many_struct_test_3_type x5, many_struct_test_3_type x6, ...) {\n"
  "  many_struct_test_3_type y;\n"
  "  y.a = x1.a + x2.a + x3.a + x4.a + x5.a + x6.a;\n"
  "  y.b = x1.b + x2.b + x3.b + x4.b + x5.b + x6.b;\n"
  "  return y;\n"
  "}\n";
  തിരികെ run_callback(src, many_struct_test_3_callback);
}

/*
 * stdarg_test: Test variable argument list ABI
 */

തരനിർവചനം ഘടന {long long a, b, c;} stdarg_test_struct_type;
തരനിർവചനം ശൂന്യം (*stdarg_test_function_type) (പൂർണ്ണസംഖ്യ,പൂർണ്ണസംഖ്യ,പൂർണ്ണസംഖ്യ,...);

സ്ഥിതം പൂർണ്ണസംഖ്യ stdarg_test_callback(ശൂന്യം *ptr) {
  stdarg_test_function_type f = (stdarg_test_function_type)ptr;
  പൂർണ്ണസംഖ്യ x;
  ഇരട്ട y;
  stdarg_test_struct_type z = {1, 2, 3}, w;
  f(10, 10, 5,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, &x,
    1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, &y,
    z, z, z, z, z, &w);
  തിരികെ ((x == 55) && (y == 55) && (w.a == 5) && (w.b == 10) && (w.c == 15)) ? 0 : -1;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ stdarg_test(ശൂന്യം) {
  സ്ഥിരം അക്ഷരം *src =
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
  തിരികെ run_callback(src, stdarg_test_callback);
}

തരനിർവചനം ഘടന {long long a, b;} stdarg_many_test_struct_type;
തരനിർവചനം ശൂന്യം (*stdarg_many_test_function_type) (പൂർണ്ണസംഖ്യ, പൂർണ്ണസംഖ്യ, പൂർണ്ണസംഖ്യ, പൂർണ്ണസംഖ്യ, പൂർണ്ണസംഖ്യ,
						stdarg_many_test_struct_type,
						പൂർണ്ണസംഖ്യ, പൂർണ്ണസംഖ്യ, ...);

സ്ഥിതം പൂർണ്ണസംഖ്യ stdarg_many_test_callback(ശൂന്യം *ptr)
{
  stdarg_many_test_function_type f = (stdarg_many_test_function_type)ptr;
  പൂർണ്ണസംഖ്യ x;
  stdarg_many_test_struct_type l = {10, 11};
  f(1, 2, 3, 4, 5, l, 6, 7, &x, 44);
  തിരികെ x == 44 ? 0 : -1;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ stdarg_many_test(ശൂന്യം)
{
  സ്ഥിരം അക്ഷരം *src =
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
  തിരികെ run_callback(src, stdarg_many_test_callback);
}

/*
 * Test Win32 stdarg handling, since the calling convention will pass a pointer
 * to the struct and the stdarg pointer must point to that pointer initially.
 */

തരനിർവചനം ഘടന {long long a, b, c;} stdarg_struct_test_struct_type;
തരനിർവചനം പൂർണ്ണസംഖ്യ (*stdarg_struct_test_function_type) (stdarg_struct_test_struct_type a, ...);

സ്ഥിതം പൂർണ്ണസംഖ്യ stdarg_struct_test_callback(ശൂന്യം *ptr) {
  stdarg_struct_test_function_type f = (stdarg_struct_test_function_type)ptr;
  stdarg_struct_test_struct_type v = {10, 35, 99};
  പൂർണ്ണസംഖ്യ x = f(v, 234);
  തിരികെ (x == 378) ? 0 : -1;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ stdarg_struct_test(ശൂന്യം) {
  സ്ഥിരം അക്ഷരം *src =
  "#include <stdarg.h>\n"
  "typedef struct {long long a, b, c;} stdarg_struct_test_struct_type;\n"
  "int f(stdarg_struct_test_struct_type a, ...) {\n"
  "  va_list ap;\n"
  "  va_start(ap, a);\n"
  "  int z = va_arg(ap, int);\n"
  "  va_end(ap);\n"
  "  return z + a.a + a.b + a.c;\n"
  "}\n";
  തിരികെ run_callback(src, stdarg_struct_test_callback);
}

/* Test that x86-64 arranges the stack correctly for arguments with alignment >8 bytes */

തരനിർവചനം LONG_DOUBLE (*arg_align_test_callback_type) (LONG_DOUBLE,പൂർണ്ണസംഖ്യ,LONG_DOUBLE,പൂർണ്ണസംഖ്യ,LONG_DOUBLE);

സ്ഥിതം പൂർണ്ണസംഖ്യ arg_align_test_callback(ശൂന്യം *ptr) {
  arg_align_test_callback_type f = (arg_align_test_callback_type)ptr;
  long ഇരട്ട x = f(12, 0, 25, 0, 37);
  തിരികെ (x == 74) ? 0 : -1;
}

സ്ഥിതം പൂർണ്ണസംഖ്യ arg_align_test(ശൂന്യം) {
  സ്ഥിരം അക്ഷരം *src = 
  "long double f(long double a, int b, long double c, int d, long double e) {\n"
  "  return a + c + e;\n"
  "}\n";
  തിരികെ run_callback(src, arg_align_test_callback);
}

#define RUN_TEST(t) \
  എങ്കിൽ (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    എങ്കിൽ (t() == 0) { \
      fputs("success\n", stdout); \
    } അല്ലെങ്കിൽ { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

പൂർണ്ണസംഖ്യ പ്രധാന(പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv) {
  പൂർണ്ണസംഖ്യ i;
  സ്ഥിരം അക്ഷരം *testname = ശൂന്യ;
  പൂർണ്ണസംഖ്യ retval = EXIT_SUCCESS;
  
  /* if tcclib.h and libtcc1.a are not installed, where can we find them */
  വേണ്ടി (i = 1; i < argc; ++i) {
    എങ്കിൽ (!memcmp(argv[i], "run_test=", 9))
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
#എങ്കിൽ !defined __x86_64__ || defined _WIN32
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
  തിരികെ retval;
}

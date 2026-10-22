#અન્તર્ભાવ <libtcc.h>
#અન્તર્ભાવ <stdlib.h>
#અન્તર્ભાવ <stdio.h>
#અન્તર્ભાવ <string.h>
#અન્તર્ભાવ <stdarg.h>

// MinGW has 80-bit rather than 64-bit long double which isn't compatible with TCC or MSVC
#જો defined(_WIN32) && defined(__GNUC__)
#define LONG_DOUBLE દ્વિગુણ
#define LONG_DOUBLE_LITERAL(x) x
#નહીંતર
#define LONG_DOUBLE long દ્વિગુણ
#define LONG_DOUBLE_LITERAL(x) x ## L
#endif

સ્થિર પૂર્ણાંક g_argc;
સ્થિર અક્ષર **g_argv;

સ્થિર શૂન્ય set_options(TCCState *s, પૂર્ણાંક argc, અક્ષર **argv)
{
    પૂર્ણાંક i;
    માટે (i = 1; i < argc; ++i) {
        અક્ષર *a = argv[i];
        જો (a[0] == '-') {
            જો (a[1] == 'B')
                tcc_set_lib_path(s, a+2);
            નહીંતર જો (a[1] == 'I')
                tcc_add_include_path(s, a+2);
            નહીંતર જો (a[1] == 'L')
                tcc_add_library_path(s, a+2);
        }
    }
}

પ્રકારવ્યાખ્યા પૂર્ણાંક (*callback_type) (શૂન્ય*);

/*
 * Compile source code and call a callback with a pointer to the symbol "f".
 */
સ્થિર પૂર્ણાંક run_callback(અચલ અક્ષર *src, callback_type callback) {
  TCCState *s;
  પૂર્ણાંક result;
  શૂન્ય *ptr;
  
  s = tcc_new();
  જો (!s)
    પાછા -1;

  set_options(s, g_argc, g_argv);

  જો (tcc_set_output_type(s, TCC_OUTPUT_MEMORY) == -1)
    પાછા -1;
  જો (tcc_compile_string(s, src) == -1)
    પાછા -1;
  જો (tcc_relocate(s) == -1)
    પાછા -1;
  
  ptr = tcc_get_પ્રતીક(s, "f");
  જો (!ptr)
    પાછા -1;
  result = callback(ptr);
  
  tcc_delete(s);
  
  પાછા result;
}

#define STR2(x) #x
#define STR(x) STR2(x)

#define RET_PRIMITIVE_TEST(name, type, val) \
  સ્થિર પૂર્ણાંક ret_ ## name ## _test_callback(શૂન્ય *ptr) { \
    type (*callback) (type) = (type(*)(type))ptr; \
    type x = val; \
    type y = callback(x); \
    પાછા (y == x+x) ? 0 : -1; \
  } \
  \
  સ્થિર પૂર્ણાંક ret_ ## name ## _test(શૂન્ય) { \
    અચલ અક્ષર *src = STR(type) " f(" STR(type) " x) {return x+x;}"; \
    પાછા run_callback(src, ret_ ## name ## _test_callback); \
  }

RET_PRIMITIVE_TEST(પૂર્ણાંક, પૂર્ણાંક, 70000)
RET_PRIMITIVE_TEST(longlong, long long, 4333369356528LL)
RET_PRIMITIVE_TEST(દશાંશ, દશાંશ, 63.0)
RET_PRIMITIVE_TEST(દ્વિગુણ, દ્વિગુણ, 14789798.0)
RET_PRIMITIVE_TEST(longdouble, LONG_DOUBLE, LONG_DOUBLE_LITERAL(378943892.0))

/*
 * ret_2float_test:
 * 
 * On x86-64, a struct with 2 floats should be packed into a single
 * SSE register (VT_DOUBLE is used for this purpose).
 */
પ્રકારવ્યાખ્યા સંરચના ret_2float_test_type_s {દશાંશ x, y;} ret_2float_test_type;
પ્રકારવ્યાખ્યા ret_2float_test_type (*ret_2float_test_function_type) (ret_2float_test_type);

સ્થિર પૂર્ણાંક ret_2float_test_callback(શૂન્ય *ptr) {
  ret_2float_test_function_type f = (ret_2float_test_function_type)ptr;
  ret_2float_test_type a = {10, 35};
  ret_2float_test_type r;
  r = f(a);
  પાછા ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

સ્થિર પૂર્ણાંક ret_2float_test(શૂન્ય) {
  અચલ અક્ષર *src =
  "typedef struct ret_2float_test_type_s {float x, y;} ret_2float_test_type;"
  "ret_2float_test_type f(ret_2float_test_type a) {\n"
  "  ret_2float_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";

  પાછા run_callback(src, ret_2float_test_callback);
}

/*
 * ret_2double_test:
 * 
 * On x86-64, a struct with 2 doubles should be passed in two SSE
 * registers.
 */
પ્રકારવ્યાખ્યા સંરચના ret_2double_test_type_s {દ્વિગુણ x, y;} ret_2double_test_type;
પ્રકારવ્યાખ્યા ret_2double_test_type (*ret_2double_test_function_type) (ret_2double_test_type);

સ્થિર પૂર્ણાંક ret_2double_test_callback(શૂન્ય *ptr) {
  ret_2double_test_function_type f = (ret_2double_test_function_type)ptr;
  ret_2double_test_type a = {10, 35};
  ret_2double_test_type r;
  r = f(a);
  પાછા ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

સ્થિર પૂર્ણાંક ret_2double_test(શૂન્ય) {
  અચલ અક્ષર *src =
  "typedef struct ret_2double_test_type_s {double x, y;} ret_2double_test_type;"
  "ret_2double_test_type f(ret_2double_test_type a) {\n"
  "  ret_2double_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";

  પાછા run_callback(src, ret_2double_test_callback);
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
પ્રકારવ્યાખ્યા ret_2double_test_type (*ret_8plus2double_test_function_type) (દ્વિગુણ, દ્વિગુણ, દ્વિગુણ, દ્વિગુણ, દ્વિગુણ, દ્વિગુણ, દ્વિગુણ, ret_2double_test_type, દ્વિગુણ, દ્વિગુણ);

સ્થિર પૂર્ણાંક ret_8plus2double_test_callback(શૂન્ય *ptr) {
  ret_8plus2double_test_function_type f = (ret_8plus2double_test_function_type)ptr;
  ret_2double_test_type a = {10, 35};
  ret_2double_test_type r;
  r = f(0, 0, 0, 0, 0, 0, 0, a, 37, 38);
  પાછા ((r.x == 37) && (r.y == 37)) ? 0 : -1;
}

સ્થિર પૂર્ણાંક ret_8plus2double_test(શૂન્ય) {
  અચલ અક્ષર *src =
  "typedef struct ret_2double_test_type_s {double x, y;} ret_2double_test_type;"
  "ret_2double_test_type f(double x1, double x2, double x3, double x4, double x5, double x6, double x7, ret_2double_test_type a, double x8, double x9) {\n"
  "  ret_2double_test_type r = { x8, x8 };\n"
  "  return r;\n"
  "}\n";

  પાછા run_callback(src, ret_8plus2double_test_callback);
}

/*
 * ret_mixed_test:
 *
 * On x86-64, a struct with a double and a 64-bit integer should be
 * passed in one SSE register and one integer register.
 */
પ્રકારવ્યાખ્યા સંરચના ret_mixed_test_type_s {દ્વિગુણ x; long long y;} ret_mixed_test_type;
પ્રકારવ્યાખ્યા ret_mixed_test_type (*ret_mixed_test_function_type) (ret_mixed_test_type);

સ્થિર પૂર્ણાંક ret_mixed_test_callback(શૂન્ય *ptr) {
  ret_mixed_test_function_type f = (ret_mixed_test_function_type)ptr;
  ret_mixed_test_type a = {10, 35};
  ret_mixed_test_type r;
  r = f(a);
  પાછા ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

સ્થિર પૂર્ણાંક ret_mixed_test(શૂન્ય) {
  અચલ અક્ષર *src =
  "typedef struct ret_mixed_test_type_s {double x; long long y;} ret_mixed_test_type;"
  "ret_mixed_test_type f(ret_mixed_test_type a) {\n"
  "  ret_mixed_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";

  પાછા run_callback(src, ret_mixed_test_callback);
}

/*
 * ret_mixed2_test:
 *
 * On x86-64, a struct with two floats and two 32-bit integers should
 * be passed in one SSE register and one integer register.
 */
પ્રકારવ્યાખ્યા સંરચના ret_mixed2_test_type_s {દશાંશ x,x2; પૂર્ણાંક y,y2;} ret_mixed2_test_type;
પ્રકારવ્યાખ્યા ret_mixed2_test_type (*ret_mixed2_test_function_type) (ret_mixed2_test_type);

સ્થિર પૂર્ણાંક ret_mixed2_test_callback(શૂન્ય *ptr) {
  ret_mixed2_test_function_type f = (ret_mixed2_test_function_type)ptr;
  ret_mixed2_test_type a = {10, 5, 35, 7 };
  ret_mixed2_test_type r;
  r = f(a);
  પાછા ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

સ્થિર પૂર્ણાંક ret_mixed2_test(શૂન્ય) {
  અચલ અક્ષર *src =
  "typedef struct ret_mixed2_test_type_s {float x, x2; int y,y2;} ret_mixed2_test_type;"
  "ret_mixed2_test_type f(ret_mixed2_test_type a) {\n"
  "  ret_mixed2_test_type r = {a.x*5, 0, a.y*3, 0};\n"
  "  return r;\n"
  "}\n";

  પાછા run_callback(src, ret_mixed2_test_callback);
}

/*
 * ret_mixed3_test:
 *
 * On x86-64, this struct should be passed in two integer registers.
 */
પ્રકારવ્યાખ્યા સંરચના ret_mixed3_test_type_s {દશાંશ x; પૂર્ણાંક y; દશાંશ x2; પૂર્ણાંક y2;} ret_mixed3_test_type;
પ્રકારવ્યાખ્યા ret_mixed3_test_type (*ret_mixed3_test_function_type) (ret_mixed3_test_type);

સ્થિર પૂર્ણાંક ret_mixed3_test_callback(શૂન્ય *ptr) {
  ret_mixed3_test_function_type f = (ret_mixed3_test_function_type)ptr;
  ret_mixed3_test_type a = {10, 5, 35, 7 };
  ret_mixed3_test_type r;
  r = f(a);
  પાછા ((r.x == a.x*5) && (r.y2 == a.y*3)) ? 0 : -1;
}

સ્થિર પૂર્ણાંક ret_mixed3_test(શૂન્ય) {
  અચલ અક્ષર *src =
  "typedef struct ret_mixed3_test_type_s {float x; int y; float x2; int y2;} ret_mixed3_test_type;"
  "ret_mixed3_test_type f(ret_mixed3_test_type a) {\n"
  "  ret_mixed3_test_type r = {a.x*5, 0, 0, a.y*3};\n"
  "  return r;\n"
  "}\n";

  પાછા run_callback(src, ret_mixed3_test_callback);
}

/*
 * reg_pack_test: return a small struct which should be packed into
 * registers (Win32) during return.
 */
પ્રકારવ્યાખ્યા સંરચના reg_pack_test_type_s {પૂર્ણાંક x, y;} reg_pack_test_type;
પ્રકારવ્યાખ્યા reg_pack_test_type (*reg_pack_test_function_type) (reg_pack_test_type);

સ્થિર પૂર્ણાંક reg_pack_test_callback(શૂન્ય *ptr) {
  reg_pack_test_function_type f = (reg_pack_test_function_type)ptr;
  reg_pack_test_type a = {10, 35};
  reg_pack_test_type r;
  r = f(a);
  પાછા ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

સ્થિર પૂર્ણાંક reg_pack_test(શૂન્ય) {
  અચલ અક્ષર *src =
  "typedef struct reg_pack_test_type_s {int x, y;} reg_pack_test_type;"
  "reg_pack_test_type f(reg_pack_test_type a) {\n"
  "  reg_pack_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";
  
  પાછા run_callback(src, reg_pack_test_callback);
}

/*
 * reg_pack_longlong_test: return a small struct which should be packed into
 * registers (x86-64) during return.
 */
પ્રકારવ્યાખ્યા સંરચના reg_pack_longlong_test_type_s {long long x, y;} reg_pack_longlong_test_type;
પ્રકારવ્યાખ્યા reg_pack_longlong_test_type (*reg_pack_longlong_test_function_type) (reg_pack_longlong_test_type);

સ્થિર પૂર્ણાંક reg_pack_longlong_test_callback(શૂન્ય *ptr) {
  reg_pack_longlong_test_function_type f = (reg_pack_longlong_test_function_type)ptr;
  reg_pack_longlong_test_type a = {10, 35};
  reg_pack_longlong_test_type r;
  r = f(a);
  પાછા ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

સ્થિર પૂર્ણાંક reg_pack_longlong_test(શૂન્ય) {
  અચલ અક્ષર *src =
  "typedef struct reg_pack_longlong_test_type_s {long long x, y;} reg_pack_longlong_test_type;"
  "reg_pack_longlong_test_type f(reg_pack_longlong_test_type a) {\n"
  "  reg_pack_longlong_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";
  
  પાછા run_callback(src, reg_pack_longlong_test_callback);
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
પ્રકારવ્યાખ્યા reg_pack_longlong_test_type (*ret_6plus2longlong_test_function_type) (long long, long long, long long, long long, long long, reg_pack_longlong_test_type, long long, long long);

સ્થિર પૂર્ણાંક ret_6plus2longlong_test_callback(શૂન્ય *ptr) {
  ret_6plus2longlong_test_function_type f = (ret_6plus2longlong_test_function_type)ptr;
  reg_pack_longlong_test_type a = {10, 35};
  reg_pack_longlong_test_type r;
  r = f(0, 0, 0, 0, 0, a, 37, 38);
  પાછા ((r.x == 37) && (r.y == 37)) ? 0 : -1;
}

સ્થિર પૂર્ણાંક ret_6plus2longlong_test(શૂન્ય) {
  અચલ અક્ષર *src =
  "typedef struct reg_pack_longlong_test_type_s {long long x, y;} reg_pack_longlong_test_type;"
  "reg_pack_longlong_test_type f(long long x1, long long x2, long long x3, long long x4, long long x5, reg_pack_longlong_test_type a, long long x8, long long x9) {\n"
  "  reg_pack_longlong_test_type r = { x8, x8 };\n"
  "  return r;\n"
  "}\n";

  પાછા run_callback(src, ret_6plus2longlong_test_callback);
}

/*
 * sret_test: Create a struct large enough to be returned via sret
 * (hidden pointer as first function argument)
 */
પ્રકારવ્યાખ્યા સંરચના sret_test_type_s {long long a, b, c;} sret_test_type;
પ્રકારવ્યાખ્યા sret_test_type (*sret_test_function_type) (sret_test_type);

સ્થિર પૂર્ણાંક sret_test_callback(શૂન્ય *ptr) {
  sret_test_function_type f = (sret_test_function_type)(ptr);
  sret_test_type x = {5436LL, 658277698LL, 43878957LL};
  sret_test_type r = f(x);
  પાછા ((r.a==x.a*35)&&(r.b==x.b*19)&&(r.c==x.c*21)) ? 0 : -1;
}

સ્થિર પૂર્ણાંક sret_test(શૂન્ય) {
  અચલ અક્ષર *src =
  "typedef struct sret_test_type_s {long long a, b, c;} sret_test_type;\n"
  "sret_test_type f(sret_test_type x) {\n"
  "  sret_test_type r = {x.a*35, x.b*19, x.c*21};\n"
  "  return r;\n"
  "}\n";
  
  પાછા run_callback(src, sret_test_callback);
}

/*
 * one_member_union_test:
 * 
 * In the x86-64 ABI a union should always be passed on the stack. However
 * it appears that a single member union is treated by GCC as its member.
 */
પ્રકારવ્યાખ્યા સંઘ one_member_union_test_type_u {પૂર્ણાંક x;} one_member_union_test_type;
પ્રકારવ્યાખ્યા one_member_union_test_type (*one_member_union_test_function_type) (one_member_union_test_type);

સ્થિર પૂર્ણાંક one_member_union_test_callback(શૂન્ય *ptr) {
  one_member_union_test_function_type f = (one_member_union_test_function_type)ptr;
  one_member_union_test_type a, b;
  a.x = 34;
  b = f(a);
  પાછા (b.x == a.x*2) ? 0 : -1;
}

સ્થિર પૂર્ણાંક one_member_union_test(શૂન્ય) {
  અચલ અક્ષર *src =
  "typedef union one_member_union_test_type_u {int x;} one_member_union_test_type;\n"
  "one_member_union_test_type f(one_member_union_test_type a) {\n"
  "  one_member_union_test_type b;\n"
  "  b.x = a.x * 2;\n"
  "  return b;\n"
  "}\n";
  પાછા run_callback(src, one_member_union_test_callback);
}

/*
 * two_member_union_test:
 * 
 * In the x86-64 ABI a union should always be passed on the stack.
 */
પ્રકારવ્યાખ્યા સંઘ two_member_union_test_type_u {પૂર્ણાંક x; long y;} two_member_union_test_type;
પ્રકારવ્યાખ્યા two_member_union_test_type (*two_member_union_test_function_type) (two_member_union_test_type);

સ્થિર પૂર્ણાંક two_member_union_test_callback(શૂન્ય *ptr) {
  two_member_union_test_function_type f = (two_member_union_test_function_type)ptr;
  two_member_union_test_type a, b;
  a.x = 34;
  b = f(a);
  પાછા (b.x == a.x*2) ? 0 : -1;
}

સ્થિર પૂર્ણાંક two_member_union_test(શૂન્ય) {
  અચલ અક્ષર *src =
  "typedef union two_member_union_test_type_u {int x; long y;} two_member_union_test_type;\n"
  "two_member_union_test_type f(two_member_union_test_type a) {\n"
  "  two_member_union_test_type b;\n"
  "  b.x = a.x * 2;\n"
  "  return b;\n"
  "}\n";
  પાછા run_callback(src, two_member_union_test_callback);
}

/*
 * Win64 calling convention test.
 */

પ્રકારવ્યાખ્યા સંરચના many_struct_test_type_s {long long a, b, c;} many_struct_test_type;
પ્રકારવ્યાખ્યા many_struct_test_type (*many_struct_test_function_type) (many_struct_test_type,many_struct_test_type,many_struct_test_type,many_struct_test_type,many_struct_test_type,many_struct_test_type);
 
સ્થિર પૂર્ણાંક many_struct_test_callback(શૂન્ય *ptr) {
  many_struct_test_function_type f = (many_struct_test_function_type)ptr;
  many_struct_test_type v = {1, 2, 3};
  many_struct_test_type r = f(v,v,v,v,v,v);
  પાછા ((r.a == 6) && (r.b == 12) && (r.c == 18))?0:-1;
}

સ્થિર પૂર્ણાંક many_struct_test(શૂન્ય) {
  અચલ અક્ષર *src =
  "typedef struct many_struct_test_type_s {long long a, b, c;} many_struct_test_type;\n"
  "many_struct_test_type f(many_struct_test_type x1, many_struct_test_type x2, many_struct_test_type x3, many_struct_test_type x4, many_struct_test_type x5, many_struct_test_type x6) {\n"
  "  many_struct_test_type y;\n"
  "  y.a = x1.a + x2.a + x3.a + x4.a + x5.a + x6.a;\n"
  "  y.b = x1.b + x2.b + x3.b + x4.b + x5.b + x6.b;\n"
  "  y.c = x1.c + x2.c + x3.c + x4.c + x5.c + x6.c;\n"
  "  return y;\n"
  "}\n";
  પાછા run_callback(src, many_struct_test_callback);
}

/*
 * Win64 calling convention test.
 */

પ્રકારવ્યાખ્યા સંરચના many_struct_test_2_type_s {પૂર્ણાંક a, b;} many_struct_test_2_type;
પ્રકારવ્યાખ્યા many_struct_test_2_type (*many_struct_test_2_function_type) (many_struct_test_2_type,many_struct_test_2_type,many_struct_test_2_type,many_struct_test_2_type,many_struct_test_2_type,many_struct_test_2_type);
 
સ્થિર પૂર્ણાંક many_struct_test_2_callback(શૂન્ય *ptr) {
  many_struct_test_2_function_type f = (many_struct_test_2_function_type)ptr;
  many_struct_test_2_type v = {1,2};
  many_struct_test_2_type r = f(v,v,v,v,v,v);
  પાછા ((r.a == 6) && (r.b == 12))?0:-1;
}

સ્થિર પૂર્ણાંક many_struct_test_2(શૂન્ય) {
  અચલ અક્ષર *src =
  "typedef struct many_struct_test_2_type_s {int a, b;} many_struct_test_2_type;\n"
  "many_struct_test_2_type f(many_struct_test_2_type x1, many_struct_test_2_type x2, many_struct_test_2_type x3, many_struct_test_2_type x4, many_struct_test_2_type x5, many_struct_test_2_type x6) {\n"
  "  many_struct_test_2_type y;\n"
  "  y.a = x1.a + x2.a + x3.a + x4.a + x5.a + x6.a;\n"
  "  y.b = x1.b + x2.b + x3.b + x4.b + x5.b + x6.b;\n"
  "  return y;\n"
  "}\n";
  પાછા run_callback(src, many_struct_test_2_callback);
}

/*
 * Win64 calling convention test.
 */

પ્રકારવ્યાખ્યા સંરચના many_struct_test_3_type_s {પૂર્ણાંક a, b;} many_struct_test_3_type;
પ્રકારવ્યાખ્યા many_struct_test_3_type (*many_struct_test_3_function_type) (many_struct_test_3_type,many_struct_test_3_type,many_struct_test_3_type,many_struct_test_3_type,many_struct_test_3_type,many_struct_test_3_type, ...);
પ્રકારવ્યાખ્યા સંરચના many_struct_test_3_struct_type { many_struct_test_3_function_type f; many_struct_test_3_function_type *f2; } many_struct_test_3_struct_type;

સ્થિર શૂન્ય many_struct_test_3_dummy(દ્વિગુણ d, ...)
{
  અસ્થિર દ્વિગુણ x = d;
}

સ્થિર પૂર્ણાંક many_struct_test_3_callback(શૂન્ય *ptr) {
  many_struct_test_3_struct_type s = { ptr, };
  many_struct_test_3_struct_type *s2 = &s;
  s2->f2 = &s2->f;
  many_struct_test_3_dummy(1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, &s2);
  many_struct_test_3_function_type f = *(s2->f2);
  many_struct_test_3_type v = {1,2};
  many_struct_test_3_type r = (*((s2->f2=&f)+0))(v,v,v,v,v,v,1.0);
  પાછા ((r.a == 6) && (r.b == 12))?0:-1;
}

સ્થિર પૂર્ણાંક many_struct_test_3(શૂન્ય) {
  અચલ અક્ષર *src =
  "typedef struct many_struct_test_3_type_s {int a, b;} many_struct_test_3_type;\n"
  "many_struct_test_3_type f(many_struct_test_3_type x1, many_struct_test_3_type x2, many_struct_test_3_type x3, many_struct_test_3_type x4, many_struct_test_3_type x5, many_struct_test_3_type x6, ...) {\n"
  "  many_struct_test_3_type y;\n"
  "  y.a = x1.a + x2.a + x3.a + x4.a + x5.a + x6.a;\n"
  "  y.b = x1.b + x2.b + x3.b + x4.b + x5.b + x6.b;\n"
  "  return y;\n"
  "}\n";
  પાછા run_callback(src, many_struct_test_3_callback);
}

/*
 * stdarg_test: Test variable argument list ABI
 */

પ્રકારવ્યાખ્યા સંરચના {long long a, b, c;} stdarg_test_struct_type;
પ્રકારવ્યાખ્યા શૂન્ય (*stdarg_test_function_type) (પૂર્ણાંક,પૂર્ણાંક,પૂર્ણાંક,...);

સ્થિર પૂર્ણાંક stdarg_test_callback(શૂન્ય *ptr) {
  stdarg_test_function_type f = (stdarg_test_function_type)ptr;
  પૂર્ણાંક x;
  દ્વિગુણ y;
  stdarg_test_struct_type z = {1, 2, 3}, w;
  f(10, 10, 5,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, &x,
    1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, &y,
    z, z, z, z, z, &w);
  પાછા ((x == 55) && (y == 55) && (w.a == 5) && (w.b == 10) && (w.c == 15)) ? 0 : -1;
}

સ્થિર પૂર્ણાંક stdarg_test(શૂન્ય) {
  અચલ અક્ષર *src =
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
  પાછા run_callback(src, stdarg_test_callback);
}

પ્રકારવ્યાખ્યા સંરચના {long long a, b;} stdarg_many_test_struct_type;
પ્રકારવ્યાખ્યા શૂન્ય (*stdarg_many_test_function_type) (પૂર્ણાંક, પૂર્ણાંક, પૂર્ણાંક, પૂર્ણાંક, પૂર્ણાંક,
						stdarg_many_test_struct_type,
						પૂર્ણાંક, પૂર્ણાંક, ...);

સ્થિર પૂર્ણાંક stdarg_many_test_callback(શૂન્ય *ptr)
{
  stdarg_many_test_function_type f = (stdarg_many_test_function_type)ptr;
  પૂર્ણાંક x;
  stdarg_many_test_struct_type l = {10, 11};
  f(1, 2, 3, 4, 5, l, 6, 7, &x, 44);
  પાછા x == 44 ? 0 : -1;
}

સ્થિર પૂર્ણાંક stdarg_many_test(શૂન્ય)
{
  અચલ અક્ષર *src =
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
  પાછા run_callback(src, stdarg_many_test_callback);
}

/*
 * Test Win32 stdarg handling, since the calling convention will pass a pointer
 * to the struct and the stdarg pointer must point to that pointer initially.
 */

પ્રકારવ્યાખ્યા સંરચના {long long a, b, c;} stdarg_struct_test_struct_type;
પ્રકારવ્યાખ્યા પૂર્ણાંક (*stdarg_struct_test_function_type) (stdarg_struct_test_struct_type a, ...);

સ્થિર પૂર્ણાંક stdarg_struct_test_callback(શૂન્ય *ptr) {
  stdarg_struct_test_function_type f = (stdarg_struct_test_function_type)ptr;
  stdarg_struct_test_struct_type v = {10, 35, 99};
  પૂર્ણાંક x = f(v, 234);
  પાછા (x == 378) ? 0 : -1;
}

સ્થિર પૂર્ણાંક stdarg_struct_test(શૂન્ય) {
  અચલ અક્ષર *src =
  "#include <stdarg.h>\n"
  "typedef struct {long long a, b, c;} stdarg_struct_test_struct_type;\n"
  "int f(stdarg_struct_test_struct_type a, ...) {\n"
  "  va_list ap;\n"
  "  va_start(ap, a);\n"
  "  int z = va_arg(ap, int);\n"
  "  va_end(ap);\n"
  "  return z + a.a + a.b + a.c;\n"
  "}\n";
  પાછા run_callback(src, stdarg_struct_test_callback);
}

/* Test that x86-64 arranges the stack correctly for arguments with alignment >8 bytes */

પ્રકારવ્યાખ્યા LONG_DOUBLE (*arg_align_test_callback_type) (LONG_DOUBLE,પૂર્ણાંક,LONG_DOUBLE,પૂર્ણાંક,LONG_DOUBLE);

સ્થિર પૂર્ણાંક arg_align_test_callback(શૂન્ય *ptr) {
  arg_align_test_callback_type f = (arg_align_test_callback_type)ptr;
  long દ્વિગુણ x = f(12, 0, 25, 0, 37);
  પાછા (x == 74) ? 0 : -1;
}

સ્થિર પૂર્ણાંક arg_align_test(શૂન્ય) {
  અચલ અક્ષર *src = 
  "long double f(long double a, int b, long double c, int d, long double e) {\n"
  "  return a + c + e;\n"
  "}\n";
  પાછા run_callback(src, arg_align_test_callback);
}

#define RUN_TEST(t) \
  જો (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    જો (t() == 0) { \
      fputs("success\n", stdout); \
    } નહીંતર { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

પૂર્ણાંક મુખ્ય(પૂર્ણાંક argc, અક્ષર **argv) {
  પૂર્ણાંક i;
  અચલ અક્ષર *testname = ખાલી;
  પૂર્ણાંક retval = EXIT_SUCCESS;
  
  /* if tcclib.h and libtcc1.a are not installed, where can we find them */
  માટે (i = 1; i < argc; ++i) {
    જો (!memcmp(argv[i], "run_test=", 9))
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
#જો !defined __x86_64__ || defined _WIN32
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
  પાછા retval;
}

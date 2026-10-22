#అన్తర్భావ <libtcc.h>
#అన్తర్భావ <stdlib.h>
#అన్తర్భావ <stdio.h>
#అన్తర్భావ <string.h>
#అన్తర్భావ <stdarg.h>

// MinGW has 80-bit rather than 64-bit long double which isn't compatible with TCC or MSVC
#ఒకవేళ defined(_WIN32) && defined(__GNUC__)
#నిర్వచించు LONG_DOUBLE ద్విగుణ
#నిర్వచించు LONG_DOUBLE_LITERAL(x) x
#లేకపోతే
#నిర్వచించు LONG_DOUBLE దీర్ఘ ద్విగుణ
#నిర్వచించు LONG_DOUBLE_LITERAL(x) x ## L
#అయితే_ముగింపు

స్థిర పూర్ణాంకం g_argc;
స్థిర అక్షరం **g_argv;

స్థిర శూన్య సమితి_options(TCCState *s, పూర్ణాంకం argc, అక్షరం **argv)
{
    పూర్ణాంకం i;
    కొరకు (i = 1; i < argc; ++i) {
        అక్షరం *a = argv[i];
        ఒకవేళ (a[0] == '-') {
            ఒకవేళ (a[1] == 'B')
                tcc_సమితి_lib_మార్గం(s, a+2);
            లేకపోతే ఒకవేళ (a[1] == 'I')
                tcc_కూడు_include_మార్గం(s, a+2);
            లేకపోతే ఒకవేళ (a[1] == 'L')
                tcc_కూడు_library_మార్గం(s, a+2);
        }
    }
}

రకనిర్వచనం పూర్ణాంకం (*callback_type) (శూన్య*);

/*
 * Compile source code and call a callback with a pointer to the symbol "f".
 */
స్థిర పూర్ణాంకం నిరంతరం_callback(స్థిరరాశి అక్షరం *src, callback_type callback) {
  TCCState *s;
  పూర్ణాంకం ఫలితం;
  శూన్య *ptr;
  
  s = tcc_new();
  ఒకవేళ (!s)
    తిరిగి -1;

  సమితి_options(s, g_argc, g_argv);

  ఒకవేళ (tcc_సమితి_output_type(s, TCC_OUTPUT_జ్ఞాపకం) == -1)
    తిరిగి -1;
  ఒకవేళ (tcc_compile_string(s, src) == -1)
    తిరిగి -1;
  ఒకవేళ (tcc_relocate(s) == -1)
    తిరిగి -1;
  
  ptr = tcc_get_చిహ్నం(s, "f");
  ఒకవేళ (!ptr)
    తిరిగి -1;
  ఫలితం = callback(ptr);
  
  tcc_delete(s);
  
  తిరిగి ఫలితం;
}

#నిర్వచించు STR2(x) #x
#నిర్వచించు STR(x) STR2(x)

#నిర్వచించు RET_PRIMITIVE_TEST(name, type, val) \
  స్థిర పూర్ణాంకం ret_ ## name ## _test_callback(శూన్య *ptr) { \
    type (*callback) (type) = (type(*)(type))ptr; \
    type x = val; \
    type y = callback(x); \
    తిరిగి (y == x+x) ? 0 : -1; \
  } \
  \
  స్థిర పూర్ణాంకం ret_ ## name ## _test(శూన్య) { \
    స్థిరరాశి అక్షరం *src = STR(type) " f(" STR(type) " x) {return x+x;}"; \
    తిరిగి నిరంతరం_callback(src, ret_ ## name ## _test_callback); \
  }

RET_PRIMITIVE_TEST(పూర్ణాంకం, పూర్ణాంకం, 70000)
RET_PRIMITIVE_TEST(longlong, దీర్ఘ దీర్ఘ, 4333369356528LL)
RET_PRIMITIVE_TEST(దశాంశం, దశాంశం, 63.0)
RET_PRIMITIVE_TEST(ద్విగుణ, ద్విగుణ, 14789798.0)
RET_PRIMITIVE_TEST(longdouble, LONG_DOUBLE, LONG_DOUBLE_LITERAL(378943892.0))

/*
 * ret_2float_test:
 * 
 * On x86-64, a struct with 2 floats should be packed into a single
 * SSE register (VT_DOUBLE is used for this purpose).
 */
రకనిర్వచనం నిర్మాణం ret_2float_test_type_s {దశాంశం x, y;} ret_2float_test_type;
రకనిర్వచనం ret_2float_test_type (*ret_2float_test_function_type) (ret_2float_test_type);

స్థిర పూర్ణాంకం ret_2float_test_callback(శూన్య *ptr) {
  ret_2float_test_function_type f = (ret_2float_test_function_type)ptr;
  ret_2float_test_type a = {10, 35};
  ret_2float_test_type r;
  r = f(a);
  తిరిగి ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

స్థిర పూర్ణాంకం ret_2float_test(శూన్య) {
  స్థిరరాశి అక్షరం *src =
  "typedef struct ret_2float_test_type_s {float x, y;} ret_2float_test_type;"
  "ret_2float_test_type f(ret_2float_test_type a) {\n"
  "  ret_2float_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";

  తిరిగి నిరంతరం_callback(src, ret_2float_test_callback);
}

/*
 * ret_2double_test:
 * 
 * On x86-64, a struct with 2 doubles should be passed in two SSE
 * registers.
 */
రకనిర్వచనం నిర్మాణం ret_2double_test_type_s {ద్విగుణ x, y;} ret_2double_test_type;
రకనిర్వచనం ret_2double_test_type (*ret_2double_test_function_type) (ret_2double_test_type);

స్థిర పూర్ణాంకం ret_2double_test_callback(శూన్య *ptr) {
  ret_2double_test_function_type f = (ret_2double_test_function_type)ptr;
  ret_2double_test_type a = {10, 35};
  ret_2double_test_type r;
  r = f(a);
  తిరిగి ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

స్థిర పూర్ణాంకం ret_2double_test(శూన్య) {
  స్థిరరాశి అక్షరం *src =
  "typedef struct ret_2double_test_type_s {double x, y;} ret_2double_test_type;"
  "ret_2double_test_type f(ret_2double_test_type a) {\n"
  "  ret_2double_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";

  తిరిగి నిరంతరం_callback(src, ret_2double_test_callback);
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
రకనిర్వచనం ret_2double_test_type (*ret_8plus2double_test_function_type) (ద్విగుణ, ద్విగుణ, ద్విగుణ, ద్విగుణ, ద్విగుణ, ద్విగుణ, ద్విగుణ, ret_2double_test_type, ద్విగుణ, ద్విగుణ);

స్థిర పూర్ణాంకం ret_8plus2double_test_callback(శూన్య *ptr) {
  ret_8plus2double_test_function_type f = (ret_8plus2double_test_function_type)ptr;
  ret_2double_test_type a = {10, 35};
  ret_2double_test_type r;
  r = f(0, 0, 0, 0, 0, 0, 0, a, 37, 38);
  తిరిగి ((r.x == 37) && (r.y == 37)) ? 0 : -1;
}

స్థిర పూర్ణాంకం ret_8plus2double_test(శూన్య) {
  స్థిరరాశి అక్షరం *src =
  "typedef struct ret_2double_test_type_s {double x, y;} ret_2double_test_type;"
  "ret_2double_test_type f(double x1, double x2, double x3, double x4, double x5, double x6, double x7, ret_2double_test_type a, double x8, double x9) {\n"
  "  ret_2double_test_type r = { x8, x8 };\n"
  "  return r;\n"
  "}\n";

  తిరిగి నిరంతరం_callback(src, ret_8plus2double_test_callback);
}

/*
 * ret_mixed_test:
 *
 * On x86-64, a struct with a double and a 64-bit integer should be
 * passed in one SSE register and one integer register.
 */
రకనిర్వచనం నిర్మాణం ret_mixed_test_type_s {ద్విగుణ x; దీర్ఘ దీర్ఘ y;} ret_mixed_test_type;
రకనిర్వచనం ret_mixed_test_type (*ret_mixed_test_function_type) (ret_mixed_test_type);

స్థిర పూర్ణాంకం ret_mixed_test_callback(శూన్య *ptr) {
  ret_mixed_test_function_type f = (ret_mixed_test_function_type)ptr;
  ret_mixed_test_type a = {10, 35};
  ret_mixed_test_type r;
  r = f(a);
  తిరిగి ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

స్థిర పూర్ణాంకం ret_mixed_test(శూన్య) {
  స్థిరరాశి అక్షరం *src =
  "typedef struct ret_mixed_test_type_s {double x; long long y;} ret_mixed_test_type;"
  "ret_mixed_test_type f(ret_mixed_test_type a) {\n"
  "  ret_mixed_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";

  తిరిగి నిరంతరం_callback(src, ret_mixed_test_callback);
}

/*
 * ret_mixed2_test:
 *
 * On x86-64, a struct with two floats and two 32-bit integers should
 * be passed in one SSE register and one integer register.
 */
రకనిర్వచనం నిర్మాణం ret_mixed2_test_type_s {దశాంశం x,x2; పూర్ణాంకం y,y2;} ret_mixed2_test_type;
రకనిర్వచనం ret_mixed2_test_type (*ret_mixed2_test_function_type) (ret_mixed2_test_type);

స్థిర పూర్ణాంకం ret_mixed2_test_callback(శూన్య *ptr) {
  ret_mixed2_test_function_type f = (ret_mixed2_test_function_type)ptr;
  ret_mixed2_test_type a = {10, 5, 35, 7 };
  ret_mixed2_test_type r;
  r = f(a);
  తిరిగి ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

స్థిర పూర్ణాంకం ret_mixed2_test(శూన్య) {
  స్థిరరాశి అక్షరం *src =
  "typedef struct ret_mixed2_test_type_s {float x, x2; int y,y2;} ret_mixed2_test_type;"
  "ret_mixed2_test_type f(ret_mixed2_test_type a) {\n"
  "  ret_mixed2_test_type r = {a.x*5, 0, a.y*3, 0};\n"
  "  return r;\n"
  "}\n";

  తిరిగి నిరంతరం_callback(src, ret_mixed2_test_callback);
}

/*
 * ret_mixed3_test:
 *
 * On x86-64, this struct should be passed in two integer registers.
 */
రకనిర్వచనం నిర్మాణం ret_mixed3_test_type_s {దశాంశం x; పూర్ణాంకం y; దశాంశం x2; పూర్ణాంకం y2;} ret_mixed3_test_type;
రకనిర్వచనం ret_mixed3_test_type (*ret_mixed3_test_function_type) (ret_mixed3_test_type);

స్థిర పూర్ణాంకం ret_mixed3_test_callback(శూన్య *ptr) {
  ret_mixed3_test_function_type f = (ret_mixed3_test_function_type)ptr;
  ret_mixed3_test_type a = {10, 5, 35, 7 };
  ret_mixed3_test_type r;
  r = f(a);
  తిరిగి ((r.x == a.x*5) && (r.y2 == a.y*3)) ? 0 : -1;
}

స్థిర పూర్ణాంకం ret_mixed3_test(శూన్య) {
  స్థిరరాశి అక్షరం *src =
  "typedef struct ret_mixed3_test_type_s {float x; int y; float x2; int y2;} ret_mixed3_test_type;"
  "ret_mixed3_test_type f(ret_mixed3_test_type a) {\n"
  "  ret_mixed3_test_type r = {a.x*5, 0, 0, a.y*3};\n"
  "  return r;\n"
  "}\n";

  తిరిగి నిరంతరం_callback(src, ret_mixed3_test_callback);
}

/*
 * reg_pack_test: return a small struct which should be packed into
 * registers (Win32) during return.
 */
రకనిర్వచనం నిర్మాణం reg_pack_test_type_s {పూర్ణాంకం x, y;} reg_pack_test_type;
రకనిర్వచనం reg_pack_test_type (*reg_pack_test_function_type) (reg_pack_test_type);

స్థిర పూర్ణాంకం reg_pack_test_callback(శూన్య *ptr) {
  reg_pack_test_function_type f = (reg_pack_test_function_type)ptr;
  reg_pack_test_type a = {10, 35};
  reg_pack_test_type r;
  r = f(a);
  తిరిగి ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

స్థిర పూర్ణాంకం reg_pack_test(శూన్య) {
  స్థిరరాశి అక్షరం *src =
  "typedef struct reg_pack_test_type_s {int x, y;} reg_pack_test_type;"
  "reg_pack_test_type f(reg_pack_test_type a) {\n"
  "  reg_pack_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";
  
  తిరిగి నిరంతరం_callback(src, reg_pack_test_callback);
}

/*
 * reg_pack_longlong_test: return a small struct which should be packed into
 * registers (x86-64) during return.
 */
రకనిర్వచనం నిర్మాణం reg_pack_longlong_test_type_s {దీర్ఘ దీర్ఘ x, y;} reg_pack_longlong_test_type;
రకనిర్వచనం reg_pack_longlong_test_type (*reg_pack_longlong_test_function_type) (reg_pack_longlong_test_type);

స్థిర పూర్ణాంకం reg_pack_longlong_test_callback(శూన్య *ptr) {
  reg_pack_longlong_test_function_type f = (reg_pack_longlong_test_function_type)ptr;
  reg_pack_longlong_test_type a = {10, 35};
  reg_pack_longlong_test_type r;
  r = f(a);
  తిరిగి ((r.x == a.x*5) && (r.y == a.y*3)) ? 0 : -1;
}

స్థిర పూర్ణాంకం reg_pack_longlong_test(శూన్య) {
  స్థిరరాశి అక్షరం *src =
  "typedef struct reg_pack_longlong_test_type_s {long long x, y;} reg_pack_longlong_test_type;"
  "reg_pack_longlong_test_type f(reg_pack_longlong_test_type a) {\n"
  "  reg_pack_longlong_test_type r = {a.x*5, a.y*3};\n"
  "  return r;\n"
  "}\n";
  
  తిరిగి నిరంతరం_callback(src, reg_pack_longlong_test_callback);
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
రకనిర్వచనం reg_pack_longlong_test_type (*ret_6plus2longlong_test_function_type) (దీర్ఘ దీర్ఘ, దీర్ఘ దీర్ఘ, దీర్ఘ దీర్ఘ, దీర్ఘ దీర్ఘ, దీర్ఘ దీర్ఘ, reg_pack_longlong_test_type, దీర్ఘ దీర్ఘ, దీర్ఘ దీర్ఘ);

స్థిర పూర్ణాంకం ret_6plus2longlong_test_callback(శూన్య *ptr) {
  ret_6plus2longlong_test_function_type f = (ret_6plus2longlong_test_function_type)ptr;
  reg_pack_longlong_test_type a = {10, 35};
  reg_pack_longlong_test_type r;
  r = f(0, 0, 0, 0, 0, a, 37, 38);
  తిరిగి ((r.x == 37) && (r.y == 37)) ? 0 : -1;
}

స్థిర పూర్ణాంకం ret_6plus2longlong_test(శూన్య) {
  స్థిరరాశి అక్షరం *src =
  "typedef struct reg_pack_longlong_test_type_s {long long x, y;} reg_pack_longlong_test_type;"
  "reg_pack_longlong_test_type f(long long x1, long long x2, long long x3, long long x4, long long x5, reg_pack_longlong_test_type a, long long x8, long long x9) {\n"
  "  reg_pack_longlong_test_type r = { x8, x8 };\n"
  "  return r;\n"
  "}\n";

  తిరిగి నిరంతరం_callback(src, ret_6plus2longlong_test_callback);
}

/*
 * sret_test: Create a struct large enough to be returned via sret
 * (hidden pointer as first function argument)
 */
రకనిర్వచనం నిర్మాణం sret_test_type_s {దీర్ఘ దీర్ఘ a, b, c;} sret_test_type;
రకనిర్వచనం sret_test_type (*sret_test_function_type) (sret_test_type);

స్థిర పూర్ణాంకం sret_test_callback(శూన్య *ptr) {
  sret_test_function_type f = (sret_test_function_type)(ptr);
  sret_test_type x = {5436LL, 658277698LL, 43878957LL};
  sret_test_type r = f(x);
  తిరిగి ((r.a==x.a*35)&&(r.b==x.b*19)&&(r.c==x.c*21)) ? 0 : -1;
}

స్థిర పూర్ణాంకం sret_test(శూన్య) {
  స్థిరరాశి అక్షరం *src =
  "typedef struct sret_test_type_s {long long a, b, c;} sret_test_type;\n"
  "sret_test_type f(sret_test_type x) {\n"
  "  sret_test_type r = {x.a*35, x.b*19, x.c*21};\n"
  "  return r;\n"
  "}\n";
  
  తిరిగి నిరంతరం_callback(src, sret_test_callback);
}

/*
 * one_member_union_test:
 * 
 * In the x86-64 ABI a union should always be passed on the stack. However
 * it appears that a single member union is treated by GCC as its member.
 */
రకనిర్వచనం సంఘం one_member_union_test_type_u {పూర్ణాంకం x;} one_member_union_test_type;
రకనిర్వచనం one_member_union_test_type (*one_member_union_test_function_type) (one_member_union_test_type);

స్థిర పూర్ణాంకం one_member_union_test_callback(శూన్య *ptr) {
  one_member_union_test_function_type f = (one_member_union_test_function_type)ptr;
  one_member_union_test_type a, b;
  a.x = 34;
  b = f(a);
  తిరిగి (b.x == a.x*2) ? 0 : -1;
}

స్థిర పూర్ణాంకం one_member_union_test(శూన్య) {
  స్థిరరాశి అక్షరం *src =
  "typedef union one_member_union_test_type_u {int x;} one_member_union_test_type;\n"
  "one_member_union_test_type f(one_member_union_test_type a) {\n"
  "  one_member_union_test_type b;\n"
  "  b.x = a.x * 2;\n"
  "  return b;\n"
  "}\n";
  తిరిగి నిరంతరం_callback(src, one_member_union_test_callback);
}

/*
 * two_member_union_test:
 * 
 * In the x86-64 ABI a union should always be passed on the stack.
 */
రకనిర్వచనం సంఘం two_member_union_test_type_u {పూర్ణాంకం x; దీర్ఘ y;} two_member_union_test_type;
రకనిర్వచనం two_member_union_test_type (*two_member_union_test_function_type) (two_member_union_test_type);

స్థిర పూర్ణాంకం two_member_union_test_callback(శూన్య *ptr) {
  two_member_union_test_function_type f = (two_member_union_test_function_type)ptr;
  two_member_union_test_type a, b;
  a.x = 34;
  b = f(a);
  తిరిగి (b.x == a.x*2) ? 0 : -1;
}

స్థిర పూర్ణాంకం two_member_union_test(శూన్య) {
  స్థిరరాశి అక్షరం *src =
  "typedef union two_member_union_test_type_u {int x; long y;} two_member_union_test_type;\n"
  "two_member_union_test_type f(two_member_union_test_type a) {\n"
  "  two_member_union_test_type b;\n"
  "  b.x = a.x * 2;\n"
  "  return b;\n"
  "}\n";
  తిరిగి నిరంతరం_callback(src, two_member_union_test_callback);
}

/*
 * Win64 calling convention test.
 */

రకనిర్వచనం నిర్మాణం many_struct_test_type_s {దీర్ఘ దీర్ఘ a, b, c;} many_struct_test_type;
రకనిర్వచనం many_struct_test_type (*many_struct_test_function_type) (many_struct_test_type,many_struct_test_type,many_struct_test_type,many_struct_test_type,many_struct_test_type,many_struct_test_type);
 
స్థిర పూర్ణాంకం many_struct_test_callback(శూన్య *ptr) {
  many_struct_test_function_type f = (many_struct_test_function_type)ptr;
  many_struct_test_type v = {1, 2, 3};
  many_struct_test_type r = f(v,v,v,v,v,v);
  తిరిగి ((r.a == 6) && (r.b == 12) && (r.c == 18))?0:-1;
}

స్థిర పూర్ణాంకం many_struct_test(శూన్య) {
  స్థిరరాశి అక్షరం *src =
  "typedef struct many_struct_test_type_s {long long a, b, c;} many_struct_test_type;\n"
  "many_struct_test_type f(many_struct_test_type x1, many_struct_test_type x2, many_struct_test_type x3, many_struct_test_type x4, many_struct_test_type x5, many_struct_test_type x6) {\n"
  "  many_struct_test_type y;\n"
  "  y.a = x1.a + x2.a + x3.a + x4.a + x5.a + x6.a;\n"
  "  y.b = x1.b + x2.b + x3.b + x4.b + x5.b + x6.b;\n"
  "  y.c = x1.c + x2.c + x3.c + x4.c + x5.c + x6.c;\n"
  "  return y;\n"
  "}\n";
  తిరిగి నిరంతరం_callback(src, many_struct_test_callback);
}

/*
 * Win64 calling convention test.
 */

రకనిర్వచనం నిర్మాణం many_struct_test_2_type_s {పూర్ణాంకం a, b;} many_struct_test_2_type;
రకనిర్వచనం many_struct_test_2_type (*many_struct_test_2_function_type) (many_struct_test_2_type,many_struct_test_2_type,many_struct_test_2_type,many_struct_test_2_type,many_struct_test_2_type,many_struct_test_2_type);
 
స్థిర పూర్ణాంకం many_struct_test_2_callback(శూన్య *ptr) {
  many_struct_test_2_function_type f = (many_struct_test_2_function_type)ptr;
  many_struct_test_2_type v = {1,2};
  many_struct_test_2_type r = f(v,v,v,v,v,v);
  తిరిగి ((r.a == 6) && (r.b == 12))?0:-1;
}

స్థిర పూర్ణాంకం many_struct_test_2(శూన్య) {
  స్థిరరాశి అక్షరం *src =
  "typedef struct many_struct_test_2_type_s {int a, b;} many_struct_test_2_type;\n"
  "many_struct_test_2_type f(many_struct_test_2_type x1, many_struct_test_2_type x2, many_struct_test_2_type x3, many_struct_test_2_type x4, many_struct_test_2_type x5, many_struct_test_2_type x6) {\n"
  "  many_struct_test_2_type y;\n"
  "  y.a = x1.a + x2.a + x3.a + x4.a + x5.a + x6.a;\n"
  "  y.b = x1.b + x2.b + x3.b + x4.b + x5.b + x6.b;\n"
  "  return y;\n"
  "}\n";
  తిరిగి నిరంతరం_callback(src, many_struct_test_2_callback);
}

/*
 * Win64 calling convention test.
 */

రకనిర్వచనం నిర్మాణం many_struct_test_3_type_s {పూర్ణాంకం a, b;} many_struct_test_3_type;
రకనిర్వచనం many_struct_test_3_type (*many_struct_test_3_function_type) (many_struct_test_3_type,many_struct_test_3_type,many_struct_test_3_type,many_struct_test_3_type,many_struct_test_3_type,many_struct_test_3_type, ...);
రకనిర్వచనం నిర్మాణం many_struct_test_3_struct_type { many_struct_test_3_function_type f; many_struct_test_3_function_type *f2; } many_struct_test_3_struct_type;

స్థిర శూన్య many_struct_test_3_dummy(ద్విగుణ d, ...)
{
  అస్థిర ద్విగుణ x = d;
}

స్థిర పూర్ణాంకం many_struct_test_3_callback(శూన్య *ptr) {
  many_struct_test_3_struct_type s = { ptr, };
  many_struct_test_3_struct_type *s2 = &s;
  s2->f2 = &s2->f;
  many_struct_test_3_dummy(1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, 1.0, &s2);
  many_struct_test_3_function_type f = *(s2->f2);
  many_struct_test_3_type v = {1,2};
  many_struct_test_3_type r = (*((s2->f2=&f)+0))(v,v,v,v,v,v,1.0);
  తిరిగి ((r.a == 6) && (r.b == 12))?0:-1;
}

స్థిర పూర్ణాంకం many_struct_test_3(శూన్య) {
  స్థిరరాశి అక్షరం *src =
  "typedef struct many_struct_test_3_type_s {int a, b;} many_struct_test_3_type;\n"
  "many_struct_test_3_type f(many_struct_test_3_type x1, many_struct_test_3_type x2, many_struct_test_3_type x3, many_struct_test_3_type x4, many_struct_test_3_type x5, many_struct_test_3_type x6, ...) {\n"
  "  many_struct_test_3_type y;\n"
  "  y.a = x1.a + x2.a + x3.a + x4.a + x5.a + x6.a;\n"
  "  y.b = x1.b + x2.b + x3.b + x4.b + x5.b + x6.b;\n"
  "  return y;\n"
  "}\n";
  తిరిగి నిరంతరం_callback(src, many_struct_test_3_callback);
}

/*
 * stdarg_test: Test variable argument list ABI
 */

రకనిర్వచనం నిర్మాణం {దీర్ఘ దీర్ఘ a, b, c;} stdarg_test_struct_type;
రకనిర్వచనం శూన్య (*stdarg_test_function_type) (పూర్ణాంకం,పూర్ణాంకం,పూర్ణాంకం,...);

స్థిర పూర్ణాంకం stdarg_test_callback(శూన్య *ptr) {
  stdarg_test_function_type f = (stdarg_test_function_type)ptr;
  పూర్ణాంకం x;
  ద్విగుణ y;
  stdarg_test_struct_type z = {1, 2, 3}, w;
  f(10, 10, 5,
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, &x,
    1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, &y,
    z, z, z, z, z, &w);
  తిరిగి ((x == 55) && (y == 55) && (w.a == 5) && (w.b == 10) && (w.c == 15)) ? 0 : -1;
}

స్థిర పూర్ణాంకం stdarg_test(శూన్య) {
  స్థిరరాశి అక్షరం *src =
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
  తిరిగి నిరంతరం_callback(src, stdarg_test_callback);
}

రకనిర్వచనం నిర్మాణం {దీర్ఘ దీర్ఘ a, b;} stdarg_many_test_struct_type;
రకనిర్వచనం శూన్య (*stdarg_many_test_function_type) (పూర్ణాంకం, పూర్ణాంకం, పూర్ణాంకం, పూర్ణాంకం, పూర్ణాంకం,
						stdarg_many_test_struct_type,
						పూర్ణాంకం, పూర్ణాంకం, ...);

స్థిర పూర్ణాంకం stdarg_many_test_callback(శూన్య *ptr)
{
  stdarg_many_test_function_type f = (stdarg_many_test_function_type)ptr;
  పూర్ణాంకం x;
  stdarg_many_test_struct_type l = {10, 11};
  f(1, 2, 3, 4, 5, l, 6, 7, &x, 44);
  తిరిగి x == 44 ? 0 : -1;
}

స్థిర పూర్ణాంకం stdarg_many_test(శూన్య)
{
  స్థిరరాశి అక్షరం *src =
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
  తిరిగి నిరంతరం_callback(src, stdarg_many_test_callback);
}

/*
 * Test Win32 stdarg handling, since the calling convention will pass a pointer
 * to the struct and the stdarg pointer must point to that pointer initially.
 */

రకనిర్వచనం నిర్మాణం {దీర్ఘ దీర్ఘ a, b, c;} stdarg_struct_test_struct_type;
రకనిర్వచనం పూర్ణాంకం (*stdarg_struct_test_function_type) (stdarg_struct_test_struct_type a, ...);

స్థిర పూర్ణాంకం stdarg_struct_test_callback(శూన్య *ptr) {
  stdarg_struct_test_function_type f = (stdarg_struct_test_function_type)ptr;
  stdarg_struct_test_struct_type v = {10, 35, 99};
  పూర్ణాంకం x = f(v, 234);
  తిరిగి (x == 378) ? 0 : -1;
}

స్థిర పూర్ణాంకం stdarg_struct_test(శూన్య) {
  స్థిరరాశి అక్షరం *src =
  "#include <stdarg.h>\n"
  "typedef struct {long long a, b, c;} stdarg_struct_test_struct_type;\n"
  "int f(stdarg_struct_test_struct_type a, ...) {\n"
  "  va_list ap;\n"
  "  va_start(ap, a);\n"
  "  int z = va_arg(ap, int);\n"
  "  va_end(ap);\n"
  "  return z + a.a + a.b + a.c;\n"
  "}\n";
  తిరిగి నిరంతరం_callback(src, stdarg_struct_test_callback);
}

/* Test that x86-64 arranges the stack correctly for arguments with alignment >8 bytes */

రకనిర్వచనం LONG_DOUBLE (*arg_align_test_callback_type) (LONG_DOUBLE,పూర్ణాంకం,LONG_DOUBLE,పూర్ణాంకం,LONG_DOUBLE);

స్థిర పూర్ణాంకం arg_align_test_callback(శూన్య *ptr) {
  arg_align_test_callback_type f = (arg_align_test_callback_type)ptr;
  దీర్ఘ ద్విగుణ x = f(12, 0, 25, 0, 37);
  తిరిగి (x == 74) ? 0 : -1;
}

స్థిర పూర్ణాంకం arg_align_test(శూన్య) {
  స్థిరరాశి అక్షరం *src = 
  "long double f(long double a, int b, long double c, int d, long double e) {\n"
  "  return a + c + e;\n"
  "}\n";
  తిరిగి నిరంతరం_callback(src, arg_align_test_callback);
}

#నిర్వచించు నిరంతరం_TEST(t) \
  ఒకవేళ (!testname || (strcmp(#t, testname) == 0)) { \
    fputs(#t "... ", stdout); \
    fflush(stdout); \
    ఒకవేళ (t() == 0) { \
      fputs("success\n", stdout); \
    } లేకపోతే { \
      fputs("failure\n", stdout); \
      retval = EXIT_FAILURE; \
    } \
  }

పూర్ణాంకం ప్రధాన(పూర్ణాంకం argc, అక్షరం **argv) {
  పూర్ణాంకం i;
  స్థిరరాశి అక్షరం *testname = ఖాళీ;
  పూర్ణాంకం retval = EXIT_SUCCESS;
  
  /* if tcclib.h and libtcc1.a are not installed, where can we find them */
  కొరకు (i = 1; i < argc; ++i) {
    ఒకవేళ (!memcmp(argv[i], "run_test=", 9))
      testname = argv[i] + 9;
  }

  g_argv = argv, g_argc = argc;

  నిరంతరం_TEST(ret_int_test);
  నిరంతరం_TEST(ret_longlong_test);
  నిరంతరం_TEST(ret_float_test);
  నిరంతరం_TEST(ret_double_test);
  నిరంతరం_TEST(ret_longdouble_test);
  నిరంతరం_TEST(ret_2float_test);
  నిరంతరం_TEST(ret_2double_test);
  నిరంతరం_TEST(ret_8plus2double_test);
  నిరంతరం_TEST(ret_6plus2longlong_test);
#ఒకవేళ !defined __x86_64__ || defined _WIN32
  /* currently broken on x86_64 linux */
  నిరంతరం_TEST(ret_mixed_test);
  నిరంతరం_TEST(ret_mixed2_test);
#అయితే_ముగింపు
  నిరంతరం_TEST(ret_mixed3_test);
  నిరంతరం_TEST(reg_pack_test);
  నిరంతరం_TEST(reg_pack_longlong_test);
  నిరంతరం_TEST(sret_test);
  నిరంతరం_TEST(one_member_union_test);
  నిరంతరం_TEST(two_member_union_test);
  నిరంతరం_TEST(many_struct_test);
  నిరంతరం_TEST(many_struct_test_2);
  నిరంతరం_TEST(many_struct_test_3);
  నిరంతరం_TEST(stdarg_test);
  నిరంతరం_TEST(stdarg_many_test);
  నిరంతరం_TEST(stdarg_struct_test);
  నిరంతరం_TEST(arg_align_test);
  తిరిగి retval;
}

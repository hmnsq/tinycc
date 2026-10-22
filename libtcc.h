#ifndef LIBTCC_H
#define LIBTCC_H

#ifndef LIBTCCAPI
# define LIBTCCAPI
#endif

#ifdef __cplusplus
বাহ্য "C" {
#endif

/*****************************/
/* set custom allocator for all allocations (optional), NULL for default. */
প্রকারনির্দেশ শূন্য *TCCReallocFunc(শূন্য *ptr, unsigned long size);
LIBTCCAPI শূন্য tcc_set_realloc(TCCReallocFunc *my_realloc);

/*****************************/
প্রকারনির্দেশ সংরচনা TCCState TCCState;

/* create a new TCC compilation context */
LIBTCCAPI TCCState *tcc_new(শূন্য);

/* free a TCC compilation context */
LIBTCCAPI শূন্য tcc_delete(TCCState *s);

/* set CONFIG_TCCDIR at runtime */
LIBTCCAPI শূন্য tcc_set_lib_path(TCCState *s, ধ্রুৱ ৱর্ণ *path);

/* set error/warning callback (optional) */
প্রকারনির্দেশ শূন্য TCCErrorFunc(শূন্য *opaque, ধ্রুৱ ৱর্ণ *বাৰ্তা);
LIBTCCAPI শূন্য tcc_set_error_func(TCCState *s, শূন্য *error_opaque, TCCErrorFunc *error_func);

/* set options as from command line (multiple supported) */
LIBTCCAPI পূর্ণাঙ্ক tcc_set_options(TCCState *s, ধ্রুৱ ৱর্ণ *str);

/*****************************/
/* preprocessor */

/* add include path */
LIBTCCAPI পূর্ণাঙ্ক tcc_add_include_path(TCCState *s, ধ্রুৱ ৱর্ণ *pathname);

/* add in system include path */
LIBTCCAPI পূর্ণাঙ্ক tcc_add_sysinclude_path(TCCState *s, ধ্রুৱ ৱর্ণ *pathname);

/* define preprocessor symbol 'sym'. value can be NULL, sym can be "sym=val" */
LIBTCCAPI শূন্য tcc_define_প্ৰতীক(TCCState *s, ধ্রুৱ ৱর্ণ *sym, ধ্রুৱ ৱর্ণ *মান);

/* undefine preprocess symbol 'sym' */
LIBTCCAPI শূন্য tcc_undefine_প্ৰতীক(TCCState *s, ধ্রুৱ ৱর্ণ *sym);

/*****************************/
/* compiling */

/* add a file (C file, dll, object, library, ld script). Return -1 if error. */
LIBTCCAPI পূর্ণাঙ্ক tcc_add_file(TCCState *s, ধ্রুৱ ৱর্ণ *filename);

/* compile a string containing a C source. Return -1 if error. */
LIBTCCAPI পূর্ণাঙ্ক tcc_compile_string(TCCState *s, ধ্রুৱ ৱর্ণ *buf);

/* Tip: to have more specific errors/warnings from tcc_compile_string(),
   you can prefix the string with "#line <num> \"<filename>\"\n" */

/*****************************/
/* linking commands */

/* set output type. MUST BE CALLED before any compilation */
LIBTCCAPI পূর্ণাঙ্ক tcc_set_output_type(TCCState *s, পূর্ণাঙ্ক output_type);
#define TCC_OUTPUT_MEMORY   1 /* output will be run in memory */
#define TCC_OUTPUT_EXE      2 /* executable file */
#define TCC_OUTPUT_DLL      4 /* dynamic library */
#define TCC_OUTPUT_OBJ      3 /* object file */
#define TCC_OUTPUT_PREPROCESS 5 /* only preprocess */

/* equivalent to -Lpath option */
LIBTCCAPI পূর্ণাঙ্ক tcc_add_library_path(TCCState *s, ধ্রুৱ ৱর্ণ *pathname);

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI পূর্ণাঙ্ক tcc_add_library(TCCState *s, ধ্রুৱ ৱর্ণ *libraryname);

/* add a symbol to the compiled program */
LIBTCCAPI পূর্ণাঙ্ক tcc_add_প্ৰতীক(TCCState *s, ধ্রুৱ ৱর্ণ *name, ধ্রুৱ শূন্য *val);

/* output an executable, library or object file. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI পূর্ণাঙ্ক tcc_output_file(TCCState *s, ধ্রুৱ ৱর্ণ *filename);

/* link and run main() function and return its value. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI পূর্ণাঙ্ক tcc_run(TCCState *s, পূর্ণাঙ্ক argc, ৱর্ণ **argv);

/* do all relocations (needed before using tcc_get_symbol()) */
LIBTCCAPI পূর্ণাঙ্ক tcc_relocate(TCCState *s1);

/* return symbol value or NULL if not found */
LIBTCCAPI শূন্য *tcc_get_প্ৰতীক(TCCState *s, ধ্রুৱ ৱর্ণ *name);

/* list all (global) symbols and their values via 'symbol_cb()' */
LIBTCCAPI শূন্য tcc_list_symbols(TCCState *s, শূন্য *ctx,
    শূন্য (*প্ৰতীক_cb)(শূন্য *ctx, ধ্রুৱ ৱর্ণ *name, ধ্রুৱ শূন্য *val));

/* experimental/advanced section (see libtcc_test_mt.c for an example) */

/* catch runtime exceptions (optionally limit backtraces at top_func),
   when using tcc_set_options("-bt") and when not using tcc_run() */
LIBTCCAPI শূন্য *_tcc_setjmp(TCCState *s1, শূন্য *jmp_buf, শূন্য *শীৰ্ষ_func, শূন্য *longjmp);
#define tcc_setjmp(s1,jb,f) setjmp(_tcc_setjmp(s1, jb, f, longjmp))

/* custom error printer for runtime exceptions. Returning 0 stops backtrace */
প্রকারনির্দেশ পূর্ণাঙ্ক TCCBtFunc(শূন্য *udata, শূন্য *pc, ধ্রুৱ ৱর্ণ *file, পূর্ণাঙ্ক সাৰি, ধ্রুৱ ৱর্ণ* func, ধ্রুৱ ৱর্ণ *বাৰ্তা);
LIBTCCAPI শূন্য tcc_set_backtrace_func(TCCState *s1, শূন্য* userdata, TCCBtFunc*);

#ifdef __cplusplus
}
#endif

#endif

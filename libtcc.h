#ifndef LIBTCC_H
#define LIBTCC_H

#ifndef LIBTCCAPI
# define LIBTCCAPI
#endif

#ifdef __cplusplus
ବାହ୍ୟ "C" {
#endif

/*****************************/
/* set custom allocator for all allocations (optional), NULL for default. */
ପ୍ରକାରବ୍ୟାଖ୍ୟା ଶୂନ୍ୟ *TCCReallocFunc(ଶୂନ୍ୟ *ptr, unsigned long size);
LIBTCCAPI ଶୂନ୍ୟ tcc_set_realloc(TCCReallocFunc *my_realloc);

/*****************************/
ପ୍ରକାରବ୍ୟାଖ୍ୟା ସଂରଚନା TCCState TCCState;

/* create a new TCC compilation context */
LIBTCCAPI TCCState *tcc_new(ଶୂନ୍ୟ);

/* free a TCC compilation context */
LIBTCCAPI ଶୂନ୍ୟ tcc_delete(TCCState *s);

/* set CONFIG_TCCDIR at runtime */
LIBTCCAPI ଶୂନ୍ୟ tcc_set_lib_path(TCCState *s, ଅଚଳ ଅକ୍ଷର *path);

/* set error/warning callback (optional) */
ପ୍ରକାରବ୍ୟାଖ୍ୟା ଶୂନ୍ୟ TCCErrorFunc(ଶୂନ୍ୟ *opaque, ଅଚଳ ଅକ୍ଷର *ସନ୍ଦେଶ);
LIBTCCAPI ଶୂନ୍ୟ tcc_set_error_func(TCCState *s, ଶୂନ୍ୟ *error_opaque, TCCErrorFunc *error_func);

/* set options as from command line (multiple supported) */
LIBTCCAPI ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_set_options(TCCState *s, ଅଚଳ ଅକ୍ଷର *str);

/*****************************/
/* preprocessor */

/* add include path */
LIBTCCAPI ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_add_include_path(TCCState *s, ଅଚଳ ଅକ୍ଷର *pathname);

/* add in system include path */
LIBTCCAPI ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_add_sysinclude_path(TCCState *s, ଅଚଳ ଅକ୍ଷର *pathname);

/* define preprocessor symbol 'sym'. value can be NULL, sym can be "sym=val" */
LIBTCCAPI ଶୂନ୍ୟ tcc_define_ପ୍ରତୀକ(TCCState *s, ଅଚଳ ଅକ୍ଷର *sym, ଅଚଳ ଅକ୍ଷର *ମୂଲ୍ୟ);

/* undefine preprocess symbol 'sym' */
LIBTCCAPI ଶୂନ୍ୟ tcc_undefine_ପ୍ରତୀକ(TCCState *s, ଅଚଳ ଅକ୍ଷର *sym);

/*****************************/
/* compiling */

/* add a file (C file, dll, object, library, ld script). Return -1 if error. */
LIBTCCAPI ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_add_file(TCCState *s, ଅଚଳ ଅକ୍ଷର *filename);

/* compile a string containing a C source. Return -1 if error. */
LIBTCCAPI ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_compile_string(TCCState *s, ଅଚଳ ଅକ୍ଷର *buf);

/* Tip: to have more specific errors/warnings from tcc_compile_string(),
   you can prefix the string with "#line <num> \"<filename>\"\n" */

/*****************************/
/* linking commands */

/* set output type. MUST BE CALLED before any compilation */
LIBTCCAPI ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_set_output_type(TCCState *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା output_type);
#define TCC_OUTPUT_MEMORY   1 /* output will be run in memory */
#define TCC_OUTPUT_EXE      2 /* executable file */
#define TCC_OUTPUT_DLL      4 /* dynamic library */
#define TCC_OUTPUT_OBJ      3 /* object file */
#define TCC_OUTPUT_PREPROCESS 5 /* only preprocess */

/* equivalent to -Lpath option */
LIBTCCAPI ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_add_library_path(TCCState *s, ଅଚଳ ଅକ୍ଷର *pathname);

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_add_library(TCCState *s, ଅଚଳ ଅକ୍ଷର *libraryname);

/* add a symbol to the compiled program */
LIBTCCAPI ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_add_ପ୍ରତୀକ(TCCState *s, ଅଚଳ ଅକ୍ଷର *name, ଅଚଳ ଶୂନ୍ୟ *val);

/* output an executable, library or object file. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_output_file(TCCState *s, ଅଚଳ ଅକ୍ଷର *filename);

/* link and run main() function and return its value. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_run(TCCState *s, ପୂର୍ଣ୍ଣସଂଖ୍ୟା argc, ଅକ୍ଷର **argv);

/* do all relocations (needed before using tcc_get_symbol()) */
LIBTCCAPI ପୂର୍ଣ୍ଣସଂଖ୍ୟା tcc_relocate(TCCState *s1);

/* return symbol value or NULL if not found */
LIBTCCAPI ଶୂନ୍ୟ *tcc_get_ପ୍ରତୀକ(TCCState *s, ଅଚଳ ଅକ୍ଷର *name);

/* list all (global) symbols and their values via 'symbol_cb()' */
LIBTCCAPI ଶୂନ୍ୟ tcc_list_symbols(TCCState *s, ଶୂନ୍ୟ *ctx,
    ଶୂନ୍ୟ (*ପ୍ରତୀକ_cb)(ଶୂନ୍ୟ *ctx, ଅଚଳ ଅକ୍ଷର *name, ଅଚଳ ଶୂନ୍ୟ *val));

/* experimental/advanced section (see libtcc_test_mt.c for an example) */

/* catch runtime exceptions (optionally limit backtraces at top_func),
   when using tcc_set_options("-bt") and when not using tcc_run() */
LIBTCCAPI ଶୂନ୍ୟ *_tcc_setjmp(TCCState *s1, ଶୂନ୍ୟ *jmp_buf, ଶୂନ୍ୟ *ଶୀର୍ଷ_func, ଶୂନ୍ୟ *longjmp);
#define tcc_setjmp(s1,jb,f) setjmp(_tcc_setjmp(s1, jb, f, longjmp))

/* custom error printer for runtime exceptions. Returning 0 stops backtrace */
ପ୍ରକାରବ୍ୟାଖ୍ୟା ପୂର୍ଣ୍ଣସଂଖ୍ୟା TCCBtFunc(ଶୂନ୍ୟ *udata, ଶୂନ୍ୟ *pc, ଅଚଳ ଅକ୍ଷର *file, ପୂର୍ଣ୍ଣସଂଖ୍ୟା ଧାଡ଼ି, ଅଚଳ ଅକ୍ଷର* func, ଅଚଳ ଅକ୍ଷର *ସନ୍ଦେଶ);
LIBTCCAPI ଶୂନ୍ୟ tcc_set_backtrace_func(TCCState *s1, ଶୂନ୍ୟ* userdata, TCCBtFunc*);

#ifdef __cplusplus
}
#endif

#endif

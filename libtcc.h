#ifndef LIBTCC_H
#define LIBTCC_H

#ifndef LIBTCCAPI
# define LIBTCCAPI
#endif

#ifdef __cplusplus
خارجي "C" {
#endif

/*****************************/
/* set custom allocator for all allocations (optional), NULL for default. */
تعريفنوع فراغ *TCCReallocFunc(فراغ *ptr, unsigned long size);
LIBTCCAPI فراغ tcc_set_realloc(TCCReallocFunc *my_realloc);

/*****************************/
تعريفنوع بنية TCCState TCCState;

/* create a new TCC compilation context */
LIBTCCAPI TCCState *tcc_new(فراغ);

/* free a TCC compilation context */
LIBTCCAPI فراغ tcc_delete(TCCState *s);

/* set CONFIG_TCCDIR at runtime */
LIBTCCAPI فراغ tcc_set_lib_path(TCCState *s, ثابت حرف *path);

/* set error/warning callback (optional) */
تعريفنوع فراغ TCCErrorFunc(فراغ *opaque, ثابت حرف *سكو);
LIBTCCAPI فراغ tcc_set_error_func(TCCState *s, فراغ *error_opaque, TCCErrorFunc *error_func);

/* set options as from command line (multiple supported) */
LIBTCCAPI صحيح tcc_set_options(TCCState *s, ثابت حرف *str);

/*****************************/
/* preprocessor */

/* add include path */
LIBTCCAPI صحيح tcc_add_include_path(TCCState *s, ثابت حرف *pathname);

/* add in system include path */
LIBTCCAPI صحيح tcc_add_sysinclude_path(TCCState *s, ثابت حرف *pathname);

/* define preprocessor symbol 'sym'. value can be NULL, sym can be "sym=val" */
LIBTCCAPI فراغ tcc_define_علام(TCCState *s, ثابت حرف *sym, ثابت حرف *درج);

/* undefine preprocess symbol 'sym' */
LIBTCCAPI فراغ tcc_undefine_علام(TCCState *s, ثابت حرف *sym);

/*****************************/
/* compiling */

/* add a file (C file, dll, object, library, ld script). Return -1 if error. */
LIBTCCAPI صحيح tcc_add_file(TCCState *s, ثابت حرف *filename);

/* compile a string containing a C source. Return -1 if error. */
LIBTCCAPI صحيح tcc_compile_string(TCCState *s, ثابت حرف *buf);

/* Tip: to have more specific errors/warnings from tcc_compile_string(),
   you can prefix the string with "#line <num> \"<filename>\"\n" */

/*****************************/
/* linking commands */

/* set output type. MUST BE CALLED before any compilation */
LIBTCCAPI صحيح tcc_set_output_type(TCCState *s, صحيح output_type);
#define TCC_OUTPUT_MEMORY   1 /* output will be run in memory */
#define TCC_OUTPUT_EXE      2 /* executable file */
#define TCC_OUTPUT_DLL      4 /* dynamic library */
#define TCC_OUTPUT_OBJ      3 /* object file */
#define TCC_OUTPUT_PREPROCESS 5 /* only preprocess */

/* equivalent to -Lpath option */
LIBTCCAPI صحيح tcc_add_library_path(TCCState *s, ثابت حرف *pathname);

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI صحيح tcc_add_library(TCCState *s, ثابت حرف *libraryname);

/* add a symbol to the compiled program */
LIBTCCAPI صحيح tcc_add_علام(TCCState *s, ثابت حرف *name, ثابت فراغ *val);

/* output an executable, library or object file. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI صحيح tcc_output_file(TCCState *s, ثابت حرف *filename);

/* link and run main() function and return its value. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI صحيح tcc_run(TCCState *s, صحيح argc, حرف **argv);

/* do all relocations (needed before using tcc_get_symbol()) */
LIBTCCAPI صحيح tcc_relocate(TCCState *s1);

/* return symbol value or NULL if not found */
LIBTCCAPI فراغ *tcc_get_علام(TCCState *s, ثابت حرف *name);

/* list all (global) symbols and their values via 'symbol_cb()' */
LIBTCCAPI فراغ tcc_list_symbols(TCCState *s, فراغ *ctx,
    فراغ (*علام_cb)(فراغ *ctx, ثابت حرف *name, ثابت فراغ *val));

/* experimental/advanced section (see libtcc_test_mt.c for an example) */

/* catch runtime exceptions (optionally limit backtraces at top_func),
   when using tcc_set_options("-bt") and when not using tcc_run() */
LIBTCCAPI فراغ *_tcc_setjmp(TCCState *s1, فراغ *jmp_buf, فراغ *كولي_func, فراغ *longjmp);
#define tcc_setjmp(s1,jb,f) setjmp(_tcc_setjmp(s1, jb, f, longjmp))

/* custom error printer for runtime exceptions. Returning 0 stops backtrace */
تعريفنوع صحيح TCCBtFunc(فراغ *udata, فراغ *pc, ثابت حرف *file, صحيح لي, ثابت حرف* func, ثابت حرف *سكو);
LIBTCCAPI فراغ tcc_set_backtrace_func(TCCState *s1, فراغ* userdata, TCCBtFunc*);

#ifdef __cplusplus
}
#endif

#endif

#ifndef LIBTCC_H
#define LIBTCC_H

#ifndef LIBTCCAPI
# define LIBTCCAPI
#endif

#ifdef __cplusplus
بیرونی "C" {
#endif

/*****************************/
/* set custom allocator for all allocations (optional), NULL for default. */
تعریفنوع تهی *TCCReallocFunc(تهی *ptr, unsigned long size);
LIBTCCAPI تهی tcc_set_realloc(TCCReallocFunc *my_realloc);

/*****************************/
تعریفنوع ساختار TCCState TCCState;

/* create a new TCC compilation context */
LIBTCCAPI TCCState *tcc_new(تهی);

/* free a TCC compilation context */
LIBTCCAPI تهی tcc_delete(TCCState *s);

/* set CONFIG_TCCDIR at runtime */
LIBTCCAPI تهی tcc_set_lib_path(TCCState *s, ثابت نویسه *path);

/* set error/warning callback (optional) */
تعریفنوع تهی TCCErrorFunc(تهی *opaque, ثابت نویسه *پیام);
LIBTCCAPI تهی tcc_set_error_func(TCCState *s, تهی *error_opaque, TCCErrorFunc *error_func);

/* set options as from command line (multiple supported) */
LIBTCCAPI صحیح tcc_set_options(TCCState *s, ثابت نویسه *str);

/*****************************/
/* preprocessor */

/* add include path */
LIBTCCAPI صحیح tcc_add_include_path(TCCState *s, ثابت نویسه *pathname);

/* add in system include path */
LIBTCCAPI صحیح tcc_add_sysinclude_path(TCCState *s, ثابت نویسه *pathname);

/* define preprocessor symbol 'sym'. value can be NULL, sym can be "sym=val" */
LIBTCCAPI تهی tcc_define_نماد(TCCState *s, ثابت نویسه *sym, ثابت نویسه *مقدار);

/* undefine preprocess symbol 'sym' */
LIBTCCAPI تهی tcc_undefine_نماد(TCCState *s, ثابت نویسه *sym);

/*****************************/
/* compiling */

/* add a file (C file, dll, object, library, ld script). Return -1 if error. */
LIBTCCAPI صحیح tcc_add_file(TCCState *s, ثابت نویسه *filename);

/* compile a string containing a C source. Return -1 if error. */
LIBTCCAPI صحیح tcc_compile_string(TCCState *s, ثابت نویسه *buf);

/* Tip: to have more specific errors/warnings from tcc_compile_string(),
   you can prefix the string with "#line <num> \"<filename>\"\n" */

/*****************************/
/* linking commands */

/* set output type. MUST BE CALLED before any compilation */
LIBTCCAPI صحیح tcc_set_output_type(TCCState *s, صحیح output_type);
#define TCC_OUTPUT_MEMORY   1 /* output will be run in memory */
#define TCC_OUTPUT_EXE      2 /* executable file */
#define TCC_OUTPUT_DLL      4 /* dynamic library */
#define TCC_OUTPUT_OBJ      3 /* object file */
#define TCC_OUTPUT_PREPROCESS 5 /* only preprocess */

/* equivalent to -Lpath option */
LIBTCCAPI صحیح tcc_add_library_path(TCCState *s, ثابت نویسه *pathname);

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI صحیح tcc_add_library(TCCState *s, ثابت نویسه *libraryname);

/* add a symbol to the compiled program */
LIBTCCAPI صحیح tcc_add_نماد(TCCState *s, ثابت نویسه *name, ثابت تهی *val);

/* output an executable, library or object file. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI صحیح tcc_output_file(TCCState *s, ثابت نویسه *filename);

/* link and run main() function and return its value. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI صحیح tcc_run(TCCState *s, صحیح argc, نویسه **argv);

/* do all relocations (needed before using tcc_get_symbol()) */
LIBTCCAPI صحیح tcc_relocate(TCCState *s1);

/* return symbol value or NULL if not found */
LIBTCCAPI تهی *tcc_get_نماد(TCCState *s, ثابت نویسه *name);

/* list all (global) symbols and their values via 'symbol_cb()' */
LIBTCCAPI تهی tcc_list_symbols(TCCState *s, تهی *ctx,
    تهی (*نماد_cb)(تهی *ctx, ثابت نویسه *name, ثابت تهی *val));

/* experimental/advanced section (see libtcc_test_mt.c for an example) */

/* catch runtime exceptions (optionally limit backtraces at top_func),
   when using tcc_set_options("-bt") and when not using tcc_run() */
LIBTCCAPI تهی *_tcc_setjmp(TCCState *s1, تهی *jmp_buf, تهی *بالاترین_func, تهی *longjmp);
#define tcc_setjmp(s1,jb,f) setjmp(_tcc_setjmp(s1, jb, f, longjmp))

/* custom error printer for runtime exceptions. Returning 0 stops backtrace */
تعریفنوع صحیح TCCBtFunc(تهی *udata, تهی *pc, ثابت نویسه *file, صحیح سطر, ثابت نویسه* func, ثابت نویسه *پیام);
LIBTCCAPI تهی tcc_set_backtrace_func(TCCState *s1, تهی* userdata, TCCBtFunc*);

#ifdef __cplusplus
}
#endif

#endif

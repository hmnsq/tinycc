#ifndef LIBTCC_H
#define LIBTCC_H

#ifndef LIBTCCAPI
# define LIBTCCAPI
#endif

#ifdef __cplusplus
வெளி "C" {
#endif

/*****************************/
/* set custom allocator for all allocations (optional), NULL for default. */
வகைவரை வெறுமை *TCCReallocFunc(வெறுமை *ptr, unsigned long size);
LIBTCCAPI வெறுமை tcc_set_realloc(TCCReallocFunc *my_realloc);

/*****************************/
வகைவரை கட்டமைப்பு TCCState TCCState;

/* create a new TCC compilation context */
LIBTCCAPI TCCState *tcc_new(வெறுமை);

/* free a TCC compilation context */
LIBTCCAPI வெறுமை tcc_delete(TCCState *s);

/* set CONFIG_TCCDIR at runtime */
LIBTCCAPI வெறுமை tcc_set_lib_path(TCCState *s, மாறிலி எழுத்து *path);

/* set error/warning callback (optional) */
வகைவரை வெறுமை TCCErrorFunc(வெறுமை *opaque, மாறிலி எழுத்து *செய்தி);
LIBTCCAPI வெறுமை tcc_set_error_func(TCCState *s, வெறுமை *error_opaque, TCCErrorFunc *error_func);

/* set options as from command line (multiple supported) */
LIBTCCAPI முழு tcc_set_options(TCCState *s, மாறிலி எழுத்து *str);

/*****************************/
/* preprocessor */

/* add include path */
LIBTCCAPI முழு tcc_add_include_path(TCCState *s, மாறிலி எழுத்து *pathname);

/* add in system include path */
LIBTCCAPI முழு tcc_add_sysinclude_path(TCCState *s, மாறிலி எழுத்து *pathname);

/* define preprocessor symbol 'sym'. value can be NULL, sym can be "sym=val" */
LIBTCCAPI வெறுமை tcc_define_குறியீடு(TCCState *s, மாறிலி எழுத்து *sym, மாறிலி எழுத்து *மதிப்பு);

/* undefine preprocess symbol 'sym' */
LIBTCCAPI வெறுமை tcc_undefine_குறியீடு(TCCState *s, மாறிலி எழுத்து *sym);

/*****************************/
/* compiling */

/* add a file (C file, dll, object, library, ld script). Return -1 if error. */
LIBTCCAPI முழு tcc_add_file(TCCState *s, மாறிலி எழுத்து *filename);

/* compile a string containing a C source. Return -1 if error. */
LIBTCCAPI முழு tcc_compile_string(TCCState *s, மாறிலி எழுத்து *buf);

/* Tip: to have more specific errors/warnings from tcc_compile_string(),
   you can prefix the string with "#line <num> \"<filename>\"\n" */

/*****************************/
/* linking commands */

/* set output type. MUST BE CALLED before any compilation */
LIBTCCAPI முழு tcc_set_output_type(TCCState *s, முழு output_type);
#define TCC_OUTPUT_MEMORY   1 /* output will be run in memory */
#define TCC_OUTPUT_EXE      2 /* executable file */
#define TCC_OUTPUT_DLL      4 /* dynamic library */
#define TCC_OUTPUT_OBJ      3 /* object file */
#define TCC_OUTPUT_PREPROCESS 5 /* only preprocess */

/* equivalent to -Lpath option */
LIBTCCAPI முழு tcc_add_library_path(TCCState *s, மாறிலி எழுத்து *pathname);

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI முழு tcc_add_library(TCCState *s, மாறிலி எழுத்து *libraryname);

/* add a symbol to the compiled program */
LIBTCCAPI முழு tcc_add_குறியீடு(TCCState *s, மாறிலி எழுத்து *name, மாறிலி வெறுமை *val);

/* output an executable, library or object file. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI முழு tcc_output_file(TCCState *s, மாறிலி எழுத்து *filename);

/* link and run main() function and return its value. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI முழு tcc_run(TCCState *s, முழு argc, எழுத்து **argv);

/* do all relocations (needed before using tcc_get_symbol()) */
LIBTCCAPI முழு tcc_relocate(TCCState *s1);

/* return symbol value or NULL if not found */
LIBTCCAPI வெறுமை *tcc_get_குறியீடு(TCCState *s, மாறிலி எழுத்து *name);

/* list all (global) symbols and their values via 'symbol_cb()' */
LIBTCCAPI வெறுமை tcc_list_symbols(TCCState *s, வெறுமை *ctx,
    வெறுமை (*குறியீடு_cb)(வெறுமை *ctx, மாறிலி எழுத்து *name, மாறிலி வெறுமை *val));

/* experimental/advanced section (see libtcc_test_mt.c for an example) */

/* catch runtime exceptions (optionally limit backtraces at top_func),
   when using tcc_set_options("-bt") and when not using tcc_run() */
LIBTCCAPI வெறுமை *_tcc_setjmp(TCCState *s1, வெறுமை *jmp_buf, வெறுமை *உச்சி_func, வெறுமை *longjmp);
#define tcc_setjmp(s1,jb,f) setjmp(_tcc_setjmp(s1, jb, f, longjmp))

/* custom error printer for runtime exceptions. Returning 0 stops backtrace */
வகைவரை முழு TCCBtFunc(வெறுமை *udata, வெறுமை *pc, மாறிலி எழுத்து *file, முழு வரி, மாறிலி எழுத்து* func, மாறிலி எழுத்து *செய்தி);
LIBTCCAPI வெறுமை tcc_set_backtrace_func(TCCState *s1, வெறுமை* userdata, TCCBtFunc*);

#ifdef __cplusplus
}
#endif

#endif

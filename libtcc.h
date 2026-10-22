#ifndef LIBTCC_H
#define LIBTCC_H

#ifndef LIBTCCAPI
# define LIBTCCAPI
#endif

#ifdef __cplusplus
ബാഹ്യ "C" {
#endif

/*****************************/
/* set custom allocator for all allocations (optional), NULL for default. */
തരനിർവചനം ശൂന്യം *TCCReallocFunc(ശൂന്യം *ptr, unsigned long size);
LIBTCCAPI ശൂന്യം tcc_set_realloc(TCCReallocFunc *my_realloc);

/*****************************/
തരനിർവചനം ഘടന TCCState TCCState;

/* create a new TCC compilation context */
LIBTCCAPI TCCState *tcc_new(ശൂന്യം);

/* free a TCC compilation context */
LIBTCCAPI ശൂന്യം tcc_delete(TCCState *s);

/* set CONFIG_TCCDIR at runtime */
LIBTCCAPI ശൂന്യം tcc_set_lib_path(TCCState *s, സ്ഥിരം അക്ഷരം *path);

/* set error/warning callback (optional) */
തരനിർവചനം ശൂന്യം TCCErrorFunc(ശൂന്യം *opaque, സ്ഥിരം അക്ഷരം *സന്ദേശം);
LIBTCCAPI ശൂന്യം tcc_set_error_func(TCCState *s, ശൂന്യം *error_opaque, TCCErrorFunc *error_func);

/* set options as from command line (multiple supported) */
LIBTCCAPI പൂർണ്ണസംഖ്യ tcc_set_options(TCCState *s, സ്ഥിരം അക്ഷരം *str);

/*****************************/
/* preprocessor */

/* add include path */
LIBTCCAPI പൂർണ്ണസംഖ്യ tcc_add_include_path(TCCState *s, സ്ഥിരം അക്ഷരം *pathname);

/* add in system include path */
LIBTCCAPI പൂർണ്ണസംഖ്യ tcc_add_sysinclude_path(TCCState *s, സ്ഥിരം അക്ഷരം *pathname);

/* define preprocessor symbol 'sym'. value can be NULL, sym can be "sym=val" */
LIBTCCAPI ശൂന്യം tcc_define_ചിഹ്നം(TCCState *s, സ്ഥിരം അക്ഷരം *sym, സ്ഥിരം അക്ഷരം *മൂല്യം);

/* undefine preprocess symbol 'sym' */
LIBTCCAPI ശൂന്യം tcc_undefine_ചിഹ്നം(TCCState *s, സ്ഥിരം അക്ഷരം *sym);

/*****************************/
/* compiling */

/* add a file (C file, dll, object, library, ld script). Return -1 if error. */
LIBTCCAPI പൂർണ്ണസംഖ്യ tcc_add_file(TCCState *s, സ്ഥിരം അക്ഷരം *filename);

/* compile a string containing a C source. Return -1 if error. */
LIBTCCAPI പൂർണ്ണസംഖ്യ tcc_compile_string(TCCState *s, സ്ഥിരം അക്ഷരം *buf);

/* Tip: to have more specific errors/warnings from tcc_compile_string(),
   you can prefix the string with "#line <num> \"<filename>\"\n" */

/*****************************/
/* linking commands */

/* set output type. MUST BE CALLED before any compilation */
LIBTCCAPI പൂർണ്ണസംഖ്യ tcc_set_output_type(TCCState *s, പൂർണ്ണസംഖ്യ output_type);
#define TCC_OUTPUT_MEMORY   1 /* output will be run in memory */
#define TCC_OUTPUT_EXE      2 /* executable file */
#define TCC_OUTPUT_DLL      4 /* dynamic library */
#define TCC_OUTPUT_OBJ      3 /* object file */
#define TCC_OUTPUT_PREPROCESS 5 /* only preprocess */

/* equivalent to -Lpath option */
LIBTCCAPI പൂർണ്ണസംഖ്യ tcc_add_library_path(TCCState *s, സ്ഥിരം അക്ഷരം *pathname);

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI പൂർണ്ണസംഖ്യ tcc_add_library(TCCState *s, സ്ഥിരം അക്ഷരം *libraryname);

/* add a symbol to the compiled program */
LIBTCCAPI പൂർണ്ണസംഖ്യ tcc_add_ചിഹ്നം(TCCState *s, സ്ഥിരം അക്ഷരം *name, സ്ഥിരം ശൂന്യം *val);

/* output an executable, library or object file. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI പൂർണ്ണസംഖ്യ tcc_output_file(TCCState *s, സ്ഥിരം അക്ഷരം *filename);

/* link and run main() function and return its value. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI പൂർണ്ണസംഖ്യ tcc_run(TCCState *s, പൂർണ്ണസംഖ്യ argc, അക്ഷരം **argv);

/* do all relocations (needed before using tcc_get_symbol()) */
LIBTCCAPI പൂർണ്ണസംഖ്യ tcc_relocate(TCCState *s1);

/* return symbol value or NULL if not found */
LIBTCCAPI ശൂന്യം *tcc_get_ചിഹ്നം(TCCState *s, സ്ഥിരം അക്ഷരം *name);

/* list all (global) symbols and their values via 'symbol_cb()' */
LIBTCCAPI ശൂന്യം tcc_list_symbols(TCCState *s, ശൂന്യം *ctx,
    ശൂന്യം (*ചിഹ്നം_cb)(ശൂന്യം *ctx, സ്ഥിരം അക്ഷരം *name, സ്ഥിരം ശൂന്യം *val));

/* experimental/advanced section (see libtcc_test_mt.c for an example) */

/* catch runtime exceptions (optionally limit backtraces at top_func),
   when using tcc_set_options("-bt") and when not using tcc_run() */
LIBTCCAPI ശൂന്യം *_tcc_setjmp(TCCState *s1, ശൂന്യം *jmp_buf, ശൂന്യം *മുകൾ_func, ശൂന്യം *longjmp);
#define tcc_setjmp(s1,jb,f) setjmp(_tcc_setjmp(s1, jb, f, longjmp))

/* custom error printer for runtime exceptions. Returning 0 stops backtrace */
തരനിർവചനം പൂർണ്ണസംഖ്യ TCCBtFunc(ശൂന്യം *udata, ശൂന്യം *pc, സ്ഥിരം അക്ഷരം *file, പൂർണ്ണസംഖ്യ വരി, സ്ഥിരം അക്ഷരം* func, സ്ഥിരം അക്ഷരം *സന്ദേശം);
LIBTCCAPI ശൂന്യം tcc_set_backtrace_func(TCCState *s1, ശൂന്യം* userdata, TCCBtFunc*);

#ifdef __cplusplus
}
#endif

#endif

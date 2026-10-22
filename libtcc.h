#ifndef LIBTCC_H
#define LIBTCC_H

#ifndef LIBTCCAPI
# define LIBTCCAPI
#endif

#ifdef __cplusplus
બાહ્ય "C" {
#endif

/*****************************/
/* set custom allocator for all allocations (optional), NULL for default. */
પ્રકારવ્યાખ્યા શૂન્ય *TCCReallocFunc(શૂન્ય *ptr, unsigned long size);
LIBTCCAPI શૂન્ય tcc_set_realloc(TCCReallocFunc *my_realloc);

/*****************************/
પ્રકારવ્યાખ્યા સંરચના TCCState TCCState;

/* create a new TCC compilation context */
LIBTCCAPI TCCState *tcc_new(શૂન્ય);

/* free a TCC compilation context */
LIBTCCAPI શૂન્ય tcc_delete(TCCState *s);

/* set CONFIG_TCCDIR at runtime */
LIBTCCAPI શૂન્ય tcc_set_lib_path(TCCState *s, અચલ અક્ષર *path);

/* set error/warning callback (optional) */
પ્રકારવ્યાખ્યા શૂન્ય TCCErrorFunc(શૂન્ય *opaque, અચલ અક્ષર *સંદેશ);
LIBTCCAPI શૂન્ય tcc_set_error_func(TCCState *s, શૂન્ય *error_opaque, TCCErrorFunc *error_func);

/* set options as from command line (multiple supported) */
LIBTCCAPI પૂર્ણાંક tcc_set_options(TCCState *s, અચલ અક્ષર *str);

/*****************************/
/* preprocessor */

/* add include path */
LIBTCCAPI પૂર્ણાંક tcc_add_include_path(TCCState *s, અચલ અક્ષર *pathname);

/* add in system include path */
LIBTCCAPI પૂર્ણાંક tcc_add_sysinclude_path(TCCState *s, અચલ અક્ષર *pathname);

/* define preprocessor symbol 'sym'. value can be NULL, sym can be "sym=val" */
LIBTCCAPI શૂન્ય tcc_define_પ્રતીક(TCCState *s, અચલ અક્ષર *sym, અચલ અક્ષર *કિંમત);

/* undefine preprocess symbol 'sym' */
LIBTCCAPI શૂન્ય tcc_undefine_પ્રતીક(TCCState *s, અચલ અક્ષર *sym);

/*****************************/
/* compiling */

/* add a file (C file, dll, object, library, ld script). Return -1 if error. */
LIBTCCAPI પૂર્ણાંક tcc_add_file(TCCState *s, અચલ અક્ષર *filename);

/* compile a string containing a C source. Return -1 if error. */
LIBTCCAPI પૂર્ણાંક tcc_compile_string(TCCState *s, અચલ અક્ષર *buf);

/* Tip: to have more specific errors/warnings from tcc_compile_string(),
   you can prefix the string with "#line <num> \"<filename>\"\n" */

/*****************************/
/* linking commands */

/* set output type. MUST BE CALLED before any compilation */
LIBTCCAPI પૂર્ણાંક tcc_set_output_type(TCCState *s, પૂર્ણાંક output_type);
#define TCC_OUTPUT_MEMORY   1 /* output will be run in memory */
#define TCC_OUTPUT_EXE      2 /* executable file */
#define TCC_OUTPUT_DLL      4 /* dynamic library */
#define TCC_OUTPUT_OBJ      3 /* object file */
#define TCC_OUTPUT_PREPROCESS 5 /* only preprocess */

/* equivalent to -Lpath option */
LIBTCCAPI પૂર્ણાંક tcc_add_library_path(TCCState *s, અચલ અક્ષર *pathname);

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI પૂર્ણાંક tcc_add_library(TCCState *s, અચલ અક્ષર *libraryname);

/* add a symbol to the compiled program */
LIBTCCAPI પૂર્ણાંક tcc_add_પ્રતીક(TCCState *s, અચલ અક્ષર *name, અચલ શૂન્ય *val);

/* output an executable, library or object file. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI પૂર્ણાંક tcc_output_file(TCCState *s, અચલ અક્ષર *filename);

/* link and run main() function and return its value. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI પૂર્ણાંક tcc_run(TCCState *s, પૂર્ણાંક argc, અક્ષર **argv);

/* do all relocations (needed before using tcc_get_symbol()) */
LIBTCCAPI પૂર્ણાંક tcc_relocate(TCCState *s1);

/* return symbol value or NULL if not found */
LIBTCCAPI શૂન્ય *tcc_get_પ્રતીક(TCCState *s, અચલ અક્ષર *name);

/* list all (global) symbols and their values via 'symbol_cb()' */
LIBTCCAPI શૂન્ય tcc_list_symbols(TCCState *s, શૂન્ય *ctx,
    શૂન્ય (*પ્રતીક_cb)(શૂન્ય *ctx, અચલ અક્ષર *name, અચલ શૂન્ય *val));

/* experimental/advanced section (see libtcc_test_mt.c for an example) */

/* catch runtime exceptions (optionally limit backtraces at top_func),
   when using tcc_set_options("-bt") and when not using tcc_run() */
LIBTCCAPI શૂન્ય *_tcc_setjmp(TCCState *s1, શૂન્ય *jmp_buf, શૂન્ય *ટોચ_func, શૂન્ય *longjmp);
#define tcc_setjmp(s1,jb,f) setjmp(_tcc_setjmp(s1, jb, f, longjmp))

/* custom error printer for runtime exceptions. Returning 0 stops backtrace */
પ્રકારવ્યાખ્યા પૂર્ણાંક TCCBtFunc(શૂન્ય *udata, શૂન્ય *pc, અચલ અક્ષર *file, પૂર્ણાંક લીટી, અચલ અક્ષર* func, અચલ અક્ષર *સંદેશ);
LIBTCCAPI શૂન્ય tcc_set_backtrace_func(TCCState *s1, શૂન્ય* userdata, TCCBtFunc*);

#ifdef __cplusplus
}
#endif

#endif

#جيڪڏهن_وصف_نه_ٿيل LIBTCC_H
#وصف_ڪريو LIBTCC_H

#جيڪڏهن_وصف_نه_ٿيل LIBTCCAPI
# define LIBTCCAPI
#جيڪڏهن_پورو

#جيڪڏهن_وصف_ٿيل __cplusplus
خارجي "C" {
#جيڪڏهن_پورو

/*****************************/
/* set custom allocator for all allocations (optional), NULL for default. */
تعريفنوع فراغ *TCCReallocFunc(فراغ *ptr, بنانشان ڊگهو سائيز);
LIBTCCAPI فراغ tcc_سيٽ_realloc(TCCReallocFunc *my_realloc);

/*****************************/
تعريفنوع بنية TCCState TCCState;

/* create a new TCC compilation context */
LIBTCCAPI TCCState *tcc_new(فراغ);

/* free a TCC compilation context */
LIBTCCAPI فراغ tcc_delete(TCCState *s);

/* set CONFIG_TCCDIR at runtime */
LIBTCCAPI فراغ tcc_سيٽ_lib_رستو(TCCState *s, ثابت حرف *رستو);

/* set error/warning callback (optional) */
تعريفنوع فراغ TCCErrorFunc(فراغ *opaque, ثابت حرف *نياپو);
LIBTCCAPI فراغ tcc_سيٽ_error_func(TCCState *s, فراغ *error_opaque, TCCErrorFunc *error_func);

/* set options as from command line (multiple supported) */
LIBTCCAPI صحيح tcc_سيٽ_options(TCCState *s, ثابت حرف *str);

/*****************************/
/* preprocessor */

/* add include path */
LIBTCCAPI صحيح tcc_جوڙيو_include_رستو(TCCState *s, ثابت حرف *pathname);

/* add in system include path */
LIBTCCAPI صحيح tcc_جوڙيو_sysinclude_رستو(TCCState *s, ثابت حرف *pathname);

/* define preprocessor symbol 'sym'. value can be NULL, sym can be "sym=val" */
LIBTCCAPI فراغ tcc_define_نشان(TCCState *s, ثابت حرف *sym, ثابت حرف *قدر);

/* undefine preprocess symbol 'sym' */
LIBTCCAPI فراغ tcc_undefine_نشان(TCCState *s, ثابت حرف *sym);

/*****************************/
/* compiling */

/* add a file (C file, dll, object, library, ld script). Return -1 if error. */
LIBTCCAPI صحيح tcc_جوڙيو_file(TCCState *s, ثابت حرف *filename);

/* compile a string containing a C source. Return -1 if error. */
LIBTCCAPI صحيح tcc_compile_string(TCCState *s, ثابت حرف *buf);

/* Tip: to have more specific errors/warnings from tcc_compile_string(),
   you can prefix the string with "#line <num> \"<filename>\"\n" */

/*****************************/
/* linking commands */

/* set output type. MUST BE CALLED before any compilation */
LIBTCCAPI صحيح tcc_سيٽ_output_type(TCCState *s, صحيح output_type);
#وصف_ڪريو TCC_OUTPUT_يادگيري   1 /* output will be run in memory */
#وصف_ڪريو TCC_OUTPUT_EXE      2 /* executable file */
#وصف_ڪريو TCC_OUTPUT_DLL      4 /* dynamic library */
#وصف_ڪريو TCC_OUTPUT_OBJ      3 /* object file */
#وصف_ڪريو TCC_OUTPUT_PREPROCESS 5 /* only preprocess */

/* equivalent to -Lpath option */
LIBTCCAPI صحيح tcc_جوڙيو_library_رستو(TCCState *s, ثابت حرف *pathname);

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI صحيح tcc_جوڙيو_library(TCCState *s, ثابت حرف *libraryname);

/* add a symbol to the compiled program */
LIBTCCAPI صحيح tcc_جوڙيو_نشان(TCCState *s, ثابت حرف *name, ثابت فراغ *val);

/* output an executable, library or object file. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI صحيح tcc_output_file(TCCState *s, ثابت حرف *filename);

/* link and run main() function and return its value. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI صحيح tcc_لاڳيتو(TCCState *s, صحيح argc, حرف **argv);

/* do all relocations (needed before using tcc_get_symbol()) */
LIBTCCAPI صحيح tcc_relocate(TCCState *s1);

/* return symbol value or NULL if not found */
LIBTCCAPI فراغ *tcc_get_نشان(TCCState *s, ثابت حرف *name);

/* list all (global) symbols and their values via 'symbol_cb()' */
LIBTCCAPI فراغ tcc_list_symbols(TCCState *s, فراغ *ctx,
    فراغ (*نشان_cb)(فراغ *ctx, ثابت حرف *name, ثابت فراغ *val));

/* experimental/advanced section (see libtcc_test_mt.c for an example) */

/* catch runtime exceptions (optionally limit backtraces at top_func),
   when using tcc_set_options("-bt") and when not using tcc_run() */
LIBTCCAPI فراغ *_tcc_setjmp(TCCState *s1, فراغ *jmp_buf, فراغ *چوٽي_func, فراغ *longjmp);
#وصف_ڪريو tcc_setjmp(s1,jb,f) setjmp(_tcc_setjmp(s1, jb, f, longjmp))

/* custom error printer for runtime exceptions. Returning 0 stops backtrace */
تعريفنوع صحيح TCCBtFunc(فراغ *udata, فراغ *pc, ثابت حرف *file, صحيح سٽ, ثابت حرف* func, ثابت حرف *نياپو);
LIBTCCAPI فراغ tcc_سيٽ_backtrace_func(TCCState *s1, فراغ* userdata, TCCBtFunc*);

#جيڪڏهن_وصف_ٿيل __cplusplus
}
#جيڪڏهن_پورو

#جيڪڏهن_پورو

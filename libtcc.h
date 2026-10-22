#اگر_غیر_تعریف_شدہ LIBTCC_H
#تعریف_کرو LIBTCC_H

#اگر_غیر_تعریف_شدہ LIBTCCAPI
# define LIBTCCAPI
#اگر_ختم

#اگر_تعریف_شدہ __cplusplus
خارجی "C" {
#اگر_ختم

/*****************************/
/* set custom allocator for all allocations (optional), NULL for default. */
قسمتعریف خالی *TCCReallocFunc(خالی *ptr, غیرعلامتی طویل سائز);
LIBTCCAPI خالی tcc_سیٹ_realloc(TCCReallocFunc *my_realloc);

/*****************************/
قسمتعریف ساخت TCCState TCCState;

/* create a new TCC compilation context */
LIBTCCAPI TCCState *tcc_new(خالی);

/* free a TCC compilation context */
LIBTCCAPI خالی tcc_delete(TCCState *s);

/* set CONFIG_TCCDIR at runtime */
LIBTCCAPI خالی tcc_سیٹ_lib_راستہ(TCCState *s, ثابت حرف *راستہ);

/* set error/warning callback (optional) */
قسمتعریف خالی TCCErrorFunc(خالی *opaque, ثابت حرف *پیغام);
LIBTCCAPI خالی tcc_سیٹ_error_func(TCCState *s, خالی *error_opaque, TCCErrorFunc *error_func);

/* set options as from command line (multiple supported) */
LIBTCCAPI صحیح tcc_سیٹ_options(TCCState *s, ثابت حرف *str);

/*****************************/
/* preprocessor */

/* add include path */
LIBTCCAPI صحیح tcc_جوڑو_include_راستہ(TCCState *s, ثابت حرف *pathname);

/* add in system include path */
LIBTCCAPI صحیح tcc_جوڑو_sysinclude_راستہ(TCCState *s, ثابت حرف *pathname);

/* define preprocessor symbol 'sym'. value can be NULL, sym can be "sym=val" */
LIBTCCAPI خالی tcc_define_علامت(TCCState *s, ثابت حرف *sym, ثابت حرف *قدر);

/* undefine preprocess symbol 'sym' */
LIBTCCAPI خالی tcc_undefine_علامت(TCCState *s, ثابت حرف *sym);

/*****************************/
/* compiling */

/* add a file (C file, dll, object, library, ld script). Return -1 if error. */
LIBTCCAPI صحیح tcc_جوڑو_file(TCCState *s, ثابت حرف *filename);

/* compile a string containing a C source. Return -1 if error. */
LIBTCCAPI صحیح tcc_compile_string(TCCState *s, ثابت حرف *buf);

/* Tip: to have more specific errors/warnings from tcc_compile_string(),
   you can prefix the string with "#line <num> \"<filename>\"\n" */

/*****************************/
/* linking commands */

/* set output type. MUST BE CALLED before any compilation */
LIBTCCAPI صحیح tcc_سیٹ_output_type(TCCState *s, صحیح output_type);
#تعریف_کرو TCC_OUTPUT_حافظہ   1 /* output will be run in memory */
#تعریف_کرو TCC_OUTPUT_EXE      2 /* executable file */
#تعریف_کرو TCC_OUTPUT_DLL      4 /* dynamic library */
#تعریف_کرو TCC_OUTPUT_OBJ      3 /* object file */
#تعریف_کرو TCC_OUTPUT_PREPROCESS 5 /* only preprocess */

/* equivalent to -Lpath option */
LIBTCCAPI صحیح tcc_جوڑو_library_راستہ(TCCState *s, ثابت حرف *pathname);

/* the library name is the same as the argument of the '-l' option */
LIBTCCAPI صحیح tcc_جوڑو_library(TCCState *s, ثابت حرف *libraryname);

/* add a symbol to the compiled program */
LIBTCCAPI صحیح tcc_جوڑو_علامت(TCCState *s, ثابت حرف *name, ثابت خالی *val);

/* output an executable, library or object file. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI صحیح tcc_output_file(TCCState *s, ثابت حرف *filename);

/* link and run main() function and return its value. DO NOT call
   tcc_relocate() before. */
LIBTCCAPI صحیح tcc_تسلسل(TCCState *s, صحیح argc, حرف **argv);

/* do all relocations (needed before using tcc_get_symbol()) */
LIBTCCAPI صحیح tcc_relocate(TCCState *s1);

/* return symbol value or NULL if not found */
LIBTCCAPI خالی *tcc_get_علامت(TCCState *s, ثابت حرف *name);

/* list all (global) symbols and their values via 'symbol_cb()' */
LIBTCCAPI خالی tcc_list_symbols(TCCState *s, خالی *ctx,
    خالی (*علامت_cb)(خالی *ctx, ثابت حرف *name, ثابت خالی *val));

/* experimental/advanced section (see libtcc_test_mt.c for an example) */

/* catch runtime exceptions (optionally limit backtraces at top_func),
   when using tcc_set_options("-bt") and when not using tcc_run() */
LIBTCCAPI خالی *_tcc_setjmp(TCCState *s1, خالی *jmp_buf, خالی *چوٹی_func, خالی *longjmp);
#تعریف_کرو tcc_setjmp(s1,jb,f) setjmp(_tcc_setjmp(s1, jb, f, longjmp))

/* custom error printer for runtime exceptions. Returning 0 stops backtrace */
قسمتعریف صحیح TCCBtFunc(خالی *udata, خالی *pc, ثابت حرف *file, صحیح سطر, ثابت حرف* func, ثابت حرف *پیغام);
LIBTCCAPI خالی tcc_سیٹ_backtrace_func(TCCState *s1, خالی* userdata, TCCBtFunc*);

#اگر_تعریف_شدہ __cplusplus
}
#اگر_ختم

#اگر_ختم

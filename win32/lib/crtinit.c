//+---------------------------------------------------------------------------

#ifdef __leading_underscore
# define _(s) s
#инако
# define _(s) _##s
#endif

extern void (*_(_init_array_start)[]) (цео argc, _TCHAR **argv, _TCHAR **envp);
extern void (*_(_init_array_end)[]) (цео argc, _TCHAR **argv, _TCHAR **envp);
extern void (*_(_fini_array_start)[]) (void);
extern void (*_(_fini_array_end)[]) (void);

static void run_ctors(цео argc, _TCHAR **argv, _TCHAR **env)
{
    цео i = 0;
    док (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}

static void run_dtors(void)
{
    цео i = 0;
    док (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

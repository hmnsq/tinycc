//+---------------------------------------------------------------------------

#ifdef __leading_underscore
# define _(s) s
#නැතහොත්
# define _(s) _##s
#endif

extern void (*_(_init_array_start)[]) (පූර්ණ_සංඛ්‍යා argc, _TCHAR **argv, _TCHAR **envp);
extern void (*_(_init_array_end)[]) (පූර්ණ_සංඛ්‍යා argc, _TCHAR **argv, _TCHAR **envp);
extern void (*_(_fini_array_start)[]) (void);
extern void (*_(_fini_array_end)[]) (void);

static void run_ctors(පූර්ණ_සංඛ්‍යා argc, _TCHAR **argv, _TCHAR **env)
{
    පූර්ණ_සංඛ්‍යා i = 0;
    අතරතුර (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}

static void run_dtors(void)
{
    පූර්ණ_සංඛ්‍යා i = 0;
    අතරතුර (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

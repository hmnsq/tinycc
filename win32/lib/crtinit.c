//+---------------------------------------------------------------------------

#ifdef __leading_underscore
# define _(s) s
#မဟုတ်ပါက
# define _(s) _##s
#endif

extern void (*_(_init_array_start)[]) (ကိန်းပြည့် argc, _TCHAR **argv, _TCHAR **envp);
extern void (*_(_init_array_end)[]) (ကိန်းပြည့် argc, _TCHAR **argv, _TCHAR **envp);
extern void (*_(_fini_array_start)[]) (void);
extern void (*_(_fini_array_end)[]) (void);

static void run_ctors(ကိန်းပြည့် argc, _TCHAR **argv, _TCHAR **env)
{
    ကိန်းပြည့် i = 0;
    နေစဉ် (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}

static void run_dtors(void)
{
    ကိန်းပြည့် i = 0;
    နေစဉ် (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

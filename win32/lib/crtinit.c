//+---------------------------------------------------------------------------

#ifdef __leading_underscore
# define _(s) s
#অন্যথা
# define _(s) _##s
#endif

বাহ্য শূন্য (*_(_init_array_start)[]) (পূর্ণাঙ্ক argc, _TCHAR **argv, _TCHAR **envp);
বাহ্য শূন্য (*_(_init_array_end)[]) (পূর্ণাঙ্ক argc, _TCHAR **argv, _TCHAR **envp);
বাহ্য শূন্য (*_(_fini_array_start)[]) (শূন্য);
বাহ্য শূন্য (*_(_fini_array_end)[]) (শূন্য);

স্থির শূন্য run_ctors(পূর্ণাঙ্ক argc, _TCHAR **argv, _TCHAR **env)
{
    পূর্ণাঙ্ক i = 0;
    যাবত্ (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}

স্থির শূন্য run_dtors(শূন্য)
{
    পূর্ণাঙ্ক i = 0;
    যাবত্ (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

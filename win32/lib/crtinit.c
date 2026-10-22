//+---------------------------------------------------------------------------

#अगर_घोषित __leading_underscore
# define _(s) s
#अन्यथा
# define _(s) _##s
#पूर्ण_अगर

बाह्य व्योम (*_(_init_array_start)[]) (पूर्णांक argc, _TCHAR **argv, _TCHAR **envp);
बाह्य व्योम (*_(_init_array_end)[]) (पूर्णांक argc, _TCHAR **argv, _TCHAR **envp);
बाह्य व्योम (*_(_fini_array_start)[]) (व्योम);
बाह्य व्योम (*_(_fini_array_end)[]) (व्योम);

अटल व्योम run_ctors(पूर्णांक argc, _TCHAR **argv, _TCHAR **env)
{
    पूर्णांक i = 0;
    जबतक (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}

अटल व्योम run_dtors(व्योम)
{
    पूर्णांक i = 0;
    जबतक (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

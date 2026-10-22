//+---------------------------------------------------------------------------

#ifdef __leading_underscore
# define _(s) s
#അല്ലെങ്കിൽ
# define _(s) _##s
#endif

ബാഹ്യ ശൂന്യം (*_(_init_array_start)[]) (പൂർണ്ണസംഖ്യ argc, _TCHAR **argv, _TCHAR **envp);
ബാഹ്യ ശൂന്യം (*_(_init_array_end)[]) (പൂർണ്ണസംഖ്യ argc, _TCHAR **argv, _TCHAR **envp);
ബാഹ്യ ശൂന്യം (*_(_fini_array_start)[]) (ശൂന്യം);
ബാഹ്യ ശൂന്യം (*_(_fini_array_end)[]) (ശൂന്യം);

സ്ഥിതം ശൂന്യം run_ctors(പൂർണ്ണസംഖ്യ argc, _TCHAR **argv, _TCHAR **env)
{
    പൂർണ്ണസംഖ്യ i = 0;
    ആകുമ്പോൾ (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}

സ്ഥിതം ശൂന്യം run_dtors(ശൂന്യം)
{
    പൂർണ്ണസംഖ്യ i = 0;
    ആകുമ്പോൾ (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

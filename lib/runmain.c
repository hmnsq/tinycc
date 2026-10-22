/* ------------------------------------------------------------- */
/* support for tcc_run() */

#अगर_घोषित __leading_underscore
# define _(s) s
#अन्यथा
# define _(s) _##s
#पूर्ण_अगर

#अगर_अघोषित _WIN32
बाह्य व्योम (*_(_init_array_start)[]) (पूर्णांक argc, अक्षर **argv, अक्षर **envp);
बाह्य व्योम (*_(_init_array_end)[]) (पूर्णांक argc, अक्षर **argv, अक्षर **envp);
अटल व्योम run_ctors(पूर्णांक argc, अक्षर **argv, अक्षर **env)
{
    पूर्णांक i = 0;
    जबतक (&_(_init_array_start)[i] != _(_init_array_end))
        (*_(_init_array_start)[i++])(argc, argv, env);
}
#पूर्ण_अगर

बाह्य व्योम (*_(_fini_array_start)[]) (व्योम);
बाह्य व्योम (*_(_fini_array_end)[]) (व्योम);
अटल व्योम run_dtors(व्योम)
{
    पूर्णांक i = 0;
    जबतक (&_(_fini_array_end)[i] != _(_fini_array_start))
        (*_(_fini_array_end)[--i])();
}

अटल व्योम *rt_exitfunc[32];
अटल व्योम *rt_exitarg[32];
अटल पूर्णांक __rt_nr_exit;

व्योम __run_on_exit(पूर्णांक ret)
{
    पूर्णांक n = __rt_nr_exit;
    जबतक (n)
	--n, ((व्योम(*)(पूर्णांक,व्योम*))rt_exitfunc[n])(ret, rt_exitarg[n]);
}

पूर्णांक on_exit(व्योम *function, व्योम *arg)
{
    पूर्णांक n = __rt_nr_exit;
    अगर (n < 32) {
	rt_exitfunc[n] = function;
	rt_exitarg[n] = arg;
        __rt_nr_exit = n + 1;
        वापस 0;
    }
    वापस 1;
}

पूर्णांक निकास_पर(व्योम (*function)(व्योम))
{
    वापस on_exit(function, 0);
}

प्रकार काष्ठा rt_frame {
    व्योम *ip, *fp, *sp;
} rt_frame;

__attribute__((noreturn)) व्योम __rt_exit(rt_frame *, पूर्णांक);

व्योम निकास(पूर्णांक code)
{
    rt_frame f;
    run_dtors();
    __run_on_exit(code);
    f.fp = 0;
    f.ip = निकास;
    __rt_exit(&f, code);
}

#अगर_अघोषित _WIN32
पूर्णांक मुख्य(पूर्णांक, अक्षर**, अक्षर**);

पूर्णांक _runmain(पूर्णांक argc, अक्षर **argv, अक्षर **envp)
{
    पूर्णांक ret;
    run_ctors(argc, argv, envp);
    ret = मुख्य(argc, argv, envp);
    run_dtors();
    __run_on_exit(ret);
    वापस ret;
}
#पूर्ण_अगर

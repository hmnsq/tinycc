/* ------------------------------------------------------------- */
/* stubs for calling bcheck functions from a dll. */

#समावेश <windows.h>
#समावेश <stdio.h>

#घोषणा REDIR_ALL \
  REDIR(__bt_init) \
  REDIR(__bt_exit) \
  REDIR(tcc_backtrace) \
  \
  REDIR(__bound_ptr_add) \
  REDIR(__bound_ptr_indir1) \
  REDIR(__bound_ptr_indir2) \
  REDIR(__bound_ptr_indir4) \
  REDIR(__bound_ptr_indir8) \
  REDIR(__bound_ptr_indir12) \
  REDIR(__bound_ptr_indir16) \
  REDIR(__bound_local_new) \
  REDIR(__bound_local_delete) \
  REDIR(__bound_new_region) \
  \
  REDIR(__bound_free) \
  REDIR(__bound_malloc) \
  REDIR(__bound_realloc) \
  REDIR(__bound_memcpy) \
  REDIR(__bound_memcmp) \
  REDIR(__bound_memmove) \
  REDIR(__bound_memset) \
  REDIR(__bound_strlen) \
  REDIR(__bound_strcpy) \
  REDIR(__bound_strncpy) \
  REDIR(__bound_strcmp) \
  REDIR(__bound_strncmp) \
  REDIR(__bound_strcat) \
  REDIR(__bound_strchr) \
  REDIR(__bound_strdup) \
  REDIR(__bound_strncat) \
  REDIR(__bound_strrchr) \
  REDIR(__bound_setjmp) \
  REDIR(__bound_longjmp)

#अगर_घोषित __leading_underscore
#घोषणा _(s) "_"#s
#अन्यथा
#घोषणा _(s) #s
#पूर्ण_अगर

#घोषणा REDIR(s) व्योम *s;
अटल काष्ठा { REDIR_ALL } all_ptrs;
#अघोषित REDIR

#घोषणा REDIR(s) #s"\0"
अटल स्थिर अक्षर all_names[] = REDIR_ALL;
#अघोषित REDIR

#अगर __aarch64__
# define REDIR(s) \
    __asm__(".global "_(s)";"_(s)":"); \
    __asm__(".int 0x58000090"); /* ldr x16, [pc, #16] */ \
    __asm__(".int 0xf9400210"); /* ldr x16, [x16] */ \
    __asm__(".int 0xd61f0200"); /* br x16 */ \
    __asm__(".int 0xd503201f"); /* nop for alignment */ \
    __asm__(".quad all_ptrs + (. - all_jmps - 16) / 24 * 8"); \
    __asm__(".type "_(s)",function\n.size "_(s)",.-"_(s));

    __asm__(".text\n.align 8\nall_jmps:");
    REDIR_ALL
#अन्यथा
# define REDIR(s) \
    __asm__(".global "_(s)";"_(s)":"); जाओ *all_ptrs.s;
    अटल व्योम all_jmps() { REDIR_ALL }
#पूर्ण_अगर
#अघोषित REDIR

व्योम __bt_init_dll(पूर्णांक bcheck)
{
    स्थिर अक्षर *s = all_names;
    व्योम **p = (व्योम**)&all_ptrs;
    करो {
        *p = (व्योम*)GetProcAddress(GetModuleHandle(शून्य), (अक्षर*)s);
        अगर (शून्य == *p) {
            अक्षर buf[100];
            प्र_लिखो(buf,
                "Error: function '%s()' not found in executable. "
                "(Need -bt or -b for linking the exe.)", s);
            अगर (GetStdHandle(STD_ERROR_HANDLE))
                ख_लिखो(मानक_त्रुटि, "TCC/BCHECK: %s\n", buf), ख_साफ(मानक_त्रुटि);
            अन्यथा
                MessageBox(शून्य, buf, "TCC/BCHECK", MB_ICONERROR);
            ExitProcess(1);
        }
        s = म_अक्षर(s,'\0') + 1, ++p;
    } जबतक (*s && (bcheck || p < &all_ptrs.__bound_ptr_add));
}

/* ------------------------------------------------------------- */
/* stubs for calling bcheck functions from a dll. */

#अन्तर्भाव <windows.h>
#अन्तर्भाव <stdio.h>

#define REDIR_ALL \
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

#ifdef __leading_underscore
#define _(s) "_"#s
#अण्णहा
#define _(s) #s
#endif

#define REDIR(s) शून्य *s;
स्थिर संरचना { REDIR_ALL } all_ptrs;
#undef REDIR

#define REDIR(s) #s"\0"
स्थिर ध्रुव वर्ण all_names[] = REDIR_ALL;
#undef REDIR

#जइ __aarch64__
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
#अण्णहा
# define REDIR(s) \
    __asm__(".global "_(s)";"_(s)":"); गच्छ *all_ptrs.s;
    स्थिर शून्य all_jmps() { REDIR_ALL }
#endif
#undef REDIR

शून्य __bt_init_dll(पूर्णाङ्क bcheck)
{
    ध्रुव वर्ण *s = all_names;
    शून्य **p = (शून्य**)&all_ptrs;
    करेहि {
        *p = (शून्य*)GetProcAddress(GetModuleHandle(रिक्त), (वर्ण*)s);
        जइ (रिक्त == *p) {
            वर्ण buf[100];
            sprintf(buf,
                "Error: function '%s()' not found in executable. "
                "(Need -bt or -b for linking the exe.)", s);
            जइ (GetStdHandle(STD_ERROR_HANDLE))
                fprintf(stderr, "TCC/BCHECK: %s\n", buf), fflush(stderr);
            अण्णहा
                MessageBox(रिक्त, buf, "TCC/BCHECK", MB_ICONERROR);
            ExitProcess(1);
        }
        s = strchr(s,'\0') + 1, ++p;
    } जाव (*s && (bcheck || p < &all_ptrs.__bound_ptr_add));
}

/* ------------------------------------------------------------- */
/* stubs for calling bcheck functions from a dll. */

#അന്തര്ഭാവ <windows.h>
#അന്തര്ഭാവ <stdio.h>

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
#അല്ലെങ്കിൽ
#define _(s) #s
#endif

#define REDIR(s) ശൂന്യം *s;
സ്ഥിതം ഘടന { REDIR_ALL } all_ptrs;
#undef REDIR

#define REDIR(s) #s"\0"
സ്ഥിതം സ്ഥിരം അക്ഷരം all_names[] = REDIR_ALL;
#undef REDIR

#എങ്കിൽ __aarch64__
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
#അല്ലെങ്കിൽ
# define REDIR(s) \
    __asm__(".global "_(s)";"_(s)":"); പോകുക *all_ptrs.s;
    സ്ഥിതം ശൂന്യം all_jmps() { REDIR_ALL }
#endif
#undef REDIR

ശൂന്യം __bt_init_dll(പൂർണ്ണസംഖ്യ bcheck)
{
    സ്ഥിരം അക്ഷരം *s = all_names;
    ശൂന്യം **p = (ശൂന്യം**)&all_ptrs;
    ചെയ്യുക {
        *p = (ശൂന്യം*)GetProcAddress(GetModuleHandle(ശൂന്യ), (അക്ഷരം*)s);
        എങ്കിൽ (ശൂന്യ == *p) {
            അക്ഷരം buf[100];
            sprintf(buf,
                "Error: function '%s()' not found in executable. "
                "(Need -bt or -b for linking the exe.)", s);
            എങ്കിൽ (GetStdHandle(STD_ERROR_HANDLE))
                fprintf(stderr, "TCC/BCHECK: %s\n", buf), fflush(stderr);
            അല്ലെങ്കിൽ
                MessageBox(ശൂന്യ, buf, "TCC/BCHECK", MB_ICONERROR);
            ExitProcess(1);
        }
        s = strchr(s,'\0') + 1, ++p;
    } ആകുമ്പോൾ (*s && (bcheck || p < &all_ptrs.__bound_ptr_add));
}

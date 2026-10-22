#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STR1(u) # u
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ pass(a) a
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ __ASM_REG(reg)         STR1(one##reg)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _ASM_DX         __ASM_REG(tok)
X162 pass(__ASM_REG(tok))
X161 pass(_ASM_DX)
X163 pass(STR1(one##tok))

X170 pass(x ## y)
X171 pass(x pass(##) y)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ Y(x) Z(x)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ X Y
X180 ਵਾਪਸ X(X(1));

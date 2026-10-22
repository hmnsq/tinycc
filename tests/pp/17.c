#وصف_ڪريو STR1(u) # u
#وصف_ڪريو pass(a) a
#وصف_ڪريو __ASM_REG(reg)         STR1(one##reg)
#وصف_ڪريو _ASM_DX         __ASM_REG(tok)
X162 pass(__ASM_REG(tok))
X161 pass(_ASM_DX)
X163 pass(STR1(one##tok))

X170 pass(x ## y)
X171 pass(x pass(##) y)

#وصف_ڪريو Y(x) Z(x)
#وصف_ڪريو X Y
X180 أرجع X(X(1));

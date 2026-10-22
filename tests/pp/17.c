#నిర్వచించు STR1(u) # u
#నిర్వచించు pass(a) a
#నిర్వచించు __ASM_REG(reg)         STR1(one##reg)
#నిర్వచించు _ASM_DX         __ASM_REG(tok)
X162 pass(__ASM_REG(tok))
X161 pass(_ASM_DX)
X163 pass(STR1(one##tok))

X170 pass(x ## y)
X171 pass(x pass(##) y)

#నిర్వచించు Y(x) Z(x)
#నిర్వచించు X Y
X180 తిరిగి X(X(1));

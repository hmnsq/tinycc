#परिभाषय STR1(u) # u
#परिभाषय pass(a) a
#परिभाषय __ASM_REG(reg)         STR1(one##reg)
#परिभाषय _ASM_DX         __ASM_REG(tok)
X162 pass(__ASM_REG(tok))
X161 pass(_ASM_DX)
X163 pass(STR1(one##tok))

X170 pass(x ## y)
X171 pass(x pass(##) y)

#परिभाषय Y(x) Z(x)
#परिभाषय X Y
X180 प्रत्यागम X(X(1));

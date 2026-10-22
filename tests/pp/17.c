#ವ್ಯಾಖ್ಯಾನಿಸು STR1(u) # u
#ವ್ಯಾಖ್ಯಾನಿಸು pass(a) a
#ವ್ಯಾಖ್ಯಾನಿಸು __ASM_REG(reg)         STR1(one##reg)
#ವ್ಯಾಖ್ಯಾನಿಸು _ASM_DX         __ASM_REG(tok)
X162 pass(__ASM_REG(tok))
X161 pass(_ASM_DX)
X163 pass(STR1(one##tok))

X170 pass(x ## y)
X171 pass(x pass(##) y)

#ವ್ಯಾಖ್ಯಾನಿಸು Y(x) Z(x)
#ವ್ಯಾಖ್ಯಾನಿಸು X Y
X180 ಹಿಂತಿರುಗಿ X(X(1));

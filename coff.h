/**************************************************************************/
/*  COFF.H                                                                */
/*     COFF data structures and related definitions used by the linker    */
/**************************************************************************/

/*------------------------------------------------------------------------*/
/*  COFF FILE HEADER                                                      */
/*------------------------------------------------------------------------*/
ರಚನೆ filehdr {
        ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ  f_magic;        /* magic number */
        ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ  f_nscns;        /* number of sections */
        ದೀರ್ಘ            f_timdat;       /* time & date stamp */
        ದೀರ್ಘ            f_symptr;       /* file pointer to symtab */
        ದೀರ್ಘ            f_nsyms;        /* number of symtab entries */
        ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ  f_opthdr;       /* sizeof(optional hdr) */
        ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ  f_flags;        /* flags */
        ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ  f_ಗುರಿ_ID;     /* for C6x = 0x0099 */
        };

/*------------------------------------------------------------------------*/
/*  File header flags                                                     */
/*------------------------------------------------------------------------*/
#ವ್ಯಾಖ್ಯಾನಿಸು  F_RELFLG   0x01       /* relocation info stripped from file       */
#ವ್ಯಾಖ್ಯಾನಿಸು  F_EXEC     0x02       /* file is executable (no unresolved refs)  */
#ವ್ಯಾಖ್ಯಾನಿಸು  F_LNNO     0x04       /* line numbers stripped from file          */
#ವ್ಯಾಖ್ಯಾನಿಸು  F_LSYMS    0x08       /* local symbols stripped from file         */
#ವ್ಯಾಖ್ಯಾನಿಸು  F_GSP10    0x10       /* 34010 version                            */
#ವ್ಯಾಖ್ಯಾನಿಸು  F_GSP20    0x20       /* 34020 version                            */
#ವ್ಯಾಖ್ಯಾನಿಸು  F_SWABD    0x40       /* bytes swabbed (in names)                 */
#ವ್ಯಾಖ್ಯಾನಿಸು  F_AR16WR   0x80       /* byte ordering of an AR16WR (PDP-11)      */
#ವ್ಯಾಖ್ಯಾನಿಸು  F_LITTLE   0x100      /* byte ordering of an AR32WR (vax)         */
#ವ್ಯಾಖ್ಯಾನಿಸು  F_BIG      0x200      /* byte ordering of an AR32W (3B, maxi)     */
#ವ್ಯಾಖ್ಯಾನಿಸು  F_PATCH    0x400      /* contains "patch" list in optional header */
#ವ್ಯಾಖ್ಯಾನಿಸು  F_NODF     0x400   

#ವ್ಯಾಖ್ಯಾನಿಸು F_ಆವೃತ್ತಿ    (F_GSP10  | F_GSP20)   
#ವ್ಯಾಖ್ಯಾನಿಸು F_BYTE_ಕ್ರಮ (F_LITTLE | F_BIG)
#ವ್ಯಾಖ್ಯಾನಿಸು FILHDR  ರಚನೆ filehdr

/* #define FILHSZ  sizeof(FILHDR)  */
#ವ್ಯಾಖ್ಯಾನಿಸು FILHSZ  22                /* above rounds to align on 4 bytes which causes problems */

#ವ್ಯಾಖ್ಯಾನಿಸು COFF_C67_MAGIC 0x00c2

/*------------------------------------------------------------------------*/
/*  Macros to recognize magic numbers                                     */
/*------------------------------------------------------------------------*/
#ವ್ಯಾಖ್ಯಾನಿಸು ISMAGIC(x)      (((ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ)(x))==(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ)magic)
#ವ್ಯಾಖ್ಯಾನಿಸು ISARCHIVE(x)    ((((ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ)(x))==(ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ)ARTYPE))
#ವ್ಯಾಖ್ಯಾನಿಸು BADMAGIC(x)     (((ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ)(x) & 0x8080) && !ISMAGIC(x))


/*------------------------------------------------------------------------*/
/*  OPTIONAL FILE HEADER                                                  */
/*------------------------------------------------------------------------*/
ಪ್ರಕಾರವ್ಯಾಖ್ಯೆ ರಚನೆ aouthdr {
        ಗಿಡ್ಡ   magic;          /* see magic.h                          */
        ಗಿಡ್ಡ   vstamp;         /* version stamp                        */
        ದೀರ್ಘ    tsize;          /* text size in bytes, padded to FW bdry*/
        ದೀರ್ಘ    dsize;          /* initialized data "  "                */
        ದೀರ್ಘ    bsize;          /* uninitialized data "   "             */
        ದೀರ್ಘ    entrypt;        /* entry pt.                            */
        ದೀರ್ಘ    ಪಠ್ಯ_ಆರಂಭ;     /* base of text used for this file      */
        ದೀರ್ಘ    ದತ್ತಾಂಶ_ಆರಂಭ;     /* base of data used for this file      */
} AOUTHDR;

#ವ್ಯಾಖ್ಯಾನಿಸು AOUTSZ  ಗಾತ್ರ(AOUTHDR)

/*----------------------------------------------------------------------*/
/*      When a UNIX aout header is to be built in the optional header,  */
/*      the following magic numbers can appear in that header:          */ 
/*                                                                      */
/*              AOUT1MAGIC : default : readonly sharable text segment   */
/*              AOUT2MAGIC:          : writable text segment            */
/*              PAGEMAGIC  :         : configured for paging            */
/*----------------------------------------------------------------------*/
#ವ್ಯಾಖ್ಯಾನಿಸು AOUT1MAGIC 0410
#ವ್ಯಾಖ್ಯಾನಿಸು AOUT2MAGIC 0407
#ವ್ಯಾಖ್ಯಾನಿಸು PAGEMAGIC  0413


/*------------------------------------------------------------------------*/
/*  COMMON ARCHIVE FILE STRUCTURES                                        */
/*                                                                        */
/*       ARCHIVE File Organization:                                       */
/*       _______________________________________________                  */
/*       |__________ARCHIVE_MAGIC_STRING_______________|                  */
/*       |__________ARCHIVE_FILE_MEMBER_1______________|                  */
/*       |                                             |                  */
/*       |       Archive File Header "ar_hdr"          |                  */
/*       |.............................................|                  */
/*       |       Member Contents                       |                  */
/*       |               1. External symbol directory  |                  */
/*       |               2. Text file                  |                  */
/*       |_____________________________________________|                  */
/*       |________ARCHIVE_FILE_MEMBER_2________________|                  */
/*       |               "ar_hdr"                      |                  */
/*       |.............................................|                  */
/*       |       Member Contents (.o or text file)     |                  */
/*       |_____________________________________________|                  */
/*       |       .               .               .     |                  */
/*       |       .               .               .     |                  */
/*       |       .               .               .     |                  */
/*       |_____________________________________________|                  */
/*       |________ARCHIVE_FILE_MEMBER_n________________|                  */
/*       |               "ar_hdr"                      |                  */
/*       |.............................................|                  */
/*       |               Member Contents               |                  */
/*       |_____________________________________________|                  */
/*                                                                        */
/*------------------------------------------------------------------------*/

#ವ್ಯಾಖ್ಯಾನಿಸು COFF_ARMAG   "!<arch>\n"
#ವ್ಯಾಖ್ಯಾನಿಸು SARMAG  8
#ವ್ಯಾಖ್ಯಾನಿಸು ARFMAG  "`\n"

ರಚನೆ ar_hdr           /* archive file member header - printable ascii */
{
        ಅಕ್ಷರ    ar_name[16];    /* file member name - `/' terminated */
        ಅಕ್ಷರ    ar_date[12];    /* file member date - decimal */
        ಅಕ್ಷರ    ar_uid[6];      /* file member user id - decimal */
        ಅಕ್ಷರ    ar_gid[6];      /* file member group id - decimal */
        ಅಕ್ಷರ    ar_ಬಹುಲಕ[8];     /* file member mode - octal */
        ಅಕ್ಷರ    ar_ಗಾತ್ರ[10];    /* file member size - decimal */
        ಅಕ್ಷರ    ar_fmag[2];     /* ARFMAG - string to end header */
};


/*------------------------------------------------------------------------*/
/*  SECTION HEADER                                                        */
/*------------------------------------------------------------------------*/
ರಚನೆ scnhdr {
        ಅಕ್ಷರ            s_name[8];      /* section name */
        ದೀರ್ಘ            s_paddr;        /* physical address */
        ದೀರ್ಘ            s_vaddr;        /* virtual address */
        ದೀರ್ಘ            s_ಗಾತ್ರ;         /* section size */
        ದೀರ್ಘ            s_scnptr;       /* file ptr to raw data for section */
        ದೀರ್ಘ            s_relptr;       /* file ptr to relocation */
        ದೀರ್ಘ            s_lnnoptr;      /* file ptr to line numbers */
        ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ	s_nreloc;       /* number of relocation entries */
        ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ	s_nlnno;        /* number of line number entries */
        ಚಿಹ್ನೆರಹಿತ ಪೂರ್ಣಾಂಕ	s_flags;        /* flags */
		ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ	s_reserved;     /* reserved byte */
		ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ  s_ಪುಟ;         /* memory page id */
        };

#ವ್ಯಾಖ್ಯಾನಿಸು SCNHDR  ರಚನೆ scnhdr
#ವ್ಯಾಖ್ಯಾನಿಸು SCNHSZ  ಗಾತ್ರ(SCNHDR)

/*------------------------------------------------------------------------*/
/* Define constants for names of "special" sections                       */
/*------------------------------------------------------------------------*/
/* #define _TEXT    ".text" */
#ವ್ಯಾಖ್ಯಾನಿಸು ದತ್ತಾಂಶ_2    ".data"
#ವ್ಯಾಖ್ಯಾನಿಸು _BSS     ".bss"
#ವ್ಯಾಖ್ಯಾನಿಸು _CINIT   ".cinit"
#ವ್ಯಾಖ್ಯಾನಿಸು _TV      ".tv"

/*------------------------------------------------------------------------*/
/* The low 4 bits of s_flags is used as a section "type"                  */
/*------------------------------------------------------------------------*/
#ವ್ಯಾಖ್ಯಾನಿಸು STYP_REG    0x00  /* "regular" : allocated, relocated, loaded */
#ವ್ಯಾಖ್ಯಾನಿಸು STYP_DSECT  0x01  /* "dummy"   : not allocated, relocated, not loaded */
#ವ್ಯಾಖ್ಯಾನಿಸು STYP_NOLOAD 0x02  /* "noload"  : allocated, relocated, not loaded */
#ವ್ಯಾಖ್ಯಾನಿಸು STYP_ಗುಂಪು  0x04  /* "grouped" : formed of input sections */
#ವ್ಯಾಖ್ಯಾನಿಸು STYP_PAD    0x08  /* "padding" : not allocated, not relocated, loaded */
#ವ್ಯಾಖ್ಯಾನಿಸು STYP_COPY   0x10  /* "copy"    : used for C init tables - 
                                                not allocated, relocated,
                                                loaded;  reloc & lineno
                                                entries processed normally */
#ವ್ಯಾಖ್ಯಾನಿಸು STYP_ಪಠ್ಯ   0x20   /* section contains text only */
#ವ್ಯಾಖ್ಯಾನಿಸು STYP_ದತ್ತಾಂಶ   0x40   /* section contains data only */
#ವ್ಯಾಖ್ಯಾನಿಸು STYP_BSS    0x80   /* section contains bss only */

#ವ್ಯಾಖ್ಯಾನಿಸು STYP_ALIGN  0x100  /* align flag passed by old version assemblers */
#ವ್ಯಾಖ್ಯಾನಿಸು ALIGN_ಮುಖವಾಡ  0x0F00 /* part of s_flags that is used for align vals */
#ವ್ಯಾಖ್ಯಾನಿಸು ALIGNSIZE(x) (1 << ((x & ALIGN_ಮುಖವಾಡ) >> 8))


/*------------------------------------------------------------------------*/
/*  RELOCATION ENTRIES                                                    */
/*------------------------------------------------------------------------*/
ರಚನೆ reloc
{
   ದೀರ್ಘ            r_vaddr;        /* (virtual) address of reference */
   ಗಿಡ್ಡ           r_symndx;       /* index into symbol table */
   ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ  r_disp;         /* additional bits for address calculation */
   ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ  r_type;         /* relocation type */
};

#ವ್ಯಾಖ್ಯಾನಿಸು RELOC   ರಚನೆ reloc
#ವ್ಯಾಖ್ಯಾನಿಸು RELSZ   10                 /* sizeof(RELOC) */

/*--------------------------------------------------------------------------*/
/*   define all relocation types                                            */
/*--------------------------------------------------------------------------*/

#ವ್ಯಾಖ್ಯಾನಿಸು R_ABS           0         /* absolute address - no relocation       */
#ವ್ಯಾಖ್ಯಾನಿಸು R_DIR16         01        /*ಬಳಸದ*/
#ವ್ಯಾಖ್ಯಾನಿಸು R_REL16         02        /*ಬಳಸದ*/
#ವ್ಯಾಖ್ಯಾನಿಸು R_DIR24         04        /*ಬಳಸದ*/
#ವ್ಯಾಖ್ಯಾನಿಸು R_REL24         05        /* 24 bits, direct                        */
#ವ್ಯಾಖ್ಯಾನಿಸು R_DIR32         06        /*ಬಳಸದ*/
#ವ್ಯಾಖ್ಯಾನಿಸು R_RELBYTE      017        /* 8 bits, direct                         */
#ವ್ಯಾಖ್ಯಾನಿಸು R_RELWORD      020        /* 16 bits, direct                        */
#ವ್ಯಾಖ್ಯಾನಿಸು R_RELLONG      021        /* 32 bits, direct                        */
#ವ್ಯಾಖ್ಯಾನಿಸು R_PCRBYTE      022        /* 8 bits, PC-relative                    */
#ವ್ಯಾಖ್ಯಾನಿಸು R_PCRWORD      023        /* 16 bits, PC-relative                   */
#ವ್ಯಾಖ್ಯಾನಿಸು R_PCRLONG      024        /* 32 bits, PC-relative                   */
#ವ್ಯಾಖ್ಯಾನಿಸು R_OCRLONG      030        /* GSP: 32 bits, one's complement direct  */
#ವ್ಯಾಖ್ಯಾನಿಸು R_GSPPCR16     031        /* GSP: 16 bits, PC relative (in words)   */
#ವ್ಯಾಖ್ಯಾನಿಸು R_GSPOPR32     032        /* GSP: 32 bits, direct big-endian        */
#ವ್ಯಾಖ್ಯಾನಿಸು R_PARTLS16     040        /* Brahma: 16 bit offset of 24 bit address*/
#ವ್ಯಾಖ್ಯಾನಿಸು R_PARTMS8      041        /* Brahma: 8 bit page of 24 bit address   */
#ವ್ಯಾಖ್ಯಾನಿಸು R_PARTLS7      050        /* DSP: 7 bit offset of 16 bit address    */
#ವ್ಯಾಖ್ಯಾನಿಸು R_PARTMS9      051        /* DSP: 9 bit page of 16 bit address      */
#ವ್ಯಾಖ್ಯಾನಿಸು R_REL13        052        /* DSP: 13 bits, direct                   */


/*------------------------------------------------------------------------*/
/*  LINE NUMBER ENTRIES                                                   */
/*------------------------------------------------------------------------*/
ರಚನೆ lineno
{
        ಒಕ್ಕೂಟ
        {
                ದೀರ್ಘ    l_symndx ;      /* sym. table index of function name
                                                iff l_lnno == 0      */
                ದೀರ್ಘ    l_paddr ;       /* (physical) address of line number */
        }               l_addr ;
        ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ  l_lnno ;        /* line number */
};

#ವ್ಯಾಖ್ಯಾನಿಸು LINENO  ರಚನೆ lineno
#ವ್ಯಾಖ್ಯಾನಿಸು LINESZ  6       /* sizeof(LINENO) */


/*------------------------------------------------------------------------*/
/*   STORAGE CLASSES                                                      */
/*------------------------------------------------------------------------*/
#ವ್ಯಾಖ್ಯಾನಿಸು  C_EFCN          -1    /* physical end of function */
#ವ್ಯಾಖ್ಯಾನಿಸು  C_NULL          0
#ವ್ಯಾಖ್ಯಾನಿಸು  C_AUTO          1     /* automatic variable */
#ವ್ಯಾಖ್ಯಾನಿಸು  C_EXT           2     /* external symbol */
#ವ್ಯಾಖ್ಯಾನಿಸು  C_STAT          3     /* static */
#ವ್ಯಾಖ್ಯಾನಿಸು  C_REG           4     /* register variable */
#ವ್ಯಾಖ್ಯಾನಿಸು  C_EXTDEF        5     /* external definition */
#ವ್ಯಾಖ್ಯಾನಿಸು  C_LABEL         6     /* label */
#ವ್ಯಾಖ್ಯಾನಿಸು  C_ULABEL        7     /* undefined label */
#ವ್ಯಾಖ್ಯಾನಿಸು  C_MOS           8     /* member of structure */
#ವ್ಯಾಖ್ಯಾನಿಸು  C_ARG           9     /* function argument */
#ವ್ಯಾಖ್ಯಾನಿಸು  C_STRTAG        10    /* structure tag */
#ವ್ಯಾಖ್ಯಾನಿಸು  C_MOU           11    /* member of union */
#ವ್ಯಾಖ್ಯಾನಿಸು  C_UNTAG         12    /* union tag */
#ವ್ಯಾಖ್ಯಾನಿಸು  C_TPDEF         13    /* type definition */
#ವ್ಯಾಖ್ಯಾನಿಸು C_USTATIC        14    /* undefined static */
#ವ್ಯಾಖ್ಯಾನಿಸು  C_ENTAG         15    /* enumeration tag */
#ವ್ಯಾಖ್ಯಾನಿಸು  C_MOE           16    /* member of enumeration */
#ವ್ಯಾಖ್ಯಾನಿಸು  C_REGPARM       17    /* register parameter */
#ವ್ಯಾಖ್ಯಾನಿಸು  C_ಕ್ಷೇತ್ರ         18    /* bit field */

#ವ್ಯಾಖ್ಯಾನಿಸು  C_ಖಂಡ         100   /* ".bb" or ".eb" */
#ವ್ಯಾಖ್ಯಾನಿಸು  C_FCN           101   /* ".bf" or ".ef" */
#ವ್ಯಾಖ್ಯಾನಿಸು  C_EOS           102   /* end of structure */
#ವ್ಯಾಖ್ಯಾನಿಸು  C_FILE          103   /* file name */
#ವ್ಯಾಖ್ಯಾನಿಸು  C_ಸಾಲು          104   /* dummy sclass for line number entry */
#ವ್ಯಾಖ್ಯಾನಿಸು  C_ALIAS         105   /* duplicate tag */
#ವ್ಯಾಖ್ಯಾನಿಸು  C_HIDDEN        106   /* special storage class for external */
                               /* symbols in dmert public libraries  */

/*------------------------------------------------------------------------*/
/*  SYMBOL TABLE ENTRIES                                                  */
/*------------------------------------------------------------------------*/

#ವ್ಯಾಖ್ಯಾನಿಸು  SYMNMLEN   8      /*  Number of characters in a symbol name */
#ವ್ಯಾಖ್ಯಾನಿಸು  FILNMLEN   14     /*  Number of characters in a file name */
#ವ್ಯಾಖ್ಯಾನಿಸು  DIMNUM     4      /*  Number of array dimensions in auxiliary entry */


ರಚನೆ syment
{
        ಒಕ್ಕೂಟ
        {
                ಅಕ್ಷರ            _n_name[SYMNMLEN];      /* old COFF version */
                ರಚನೆ
                {
                        ದೀರ್ಘ    _n_zeroes;      /* new == 0 */
                        ದೀರ್ಘ    n_ಸ್ಥಾನಾಂತರ;      /* offset into string table */
                } _n_n;
                ಅಕ್ಷರ            *_n_nptr[2];    /* allows for overlaying */
        } _n;
        ದೀರ್ಘ                    n_ಮೌಲ್ಯ;        /* value of symbol */
        ಗಿಡ್ಡ                   n_scnum;        /* section number */
        ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ          n_type;         /* type and derived type */
        ಅಕ್ಷರ                    n_sclass;       /* storage class */
        ಅಕ್ಷರ                    n_numaux;       /* number of aux. entries */
};

#ವ್ಯಾಖ್ಯಾನಿಸು n_name          _n._n_name
#ವ್ಯಾಖ್ಯಾನಿಸು n_nptr          _n._n_nptr[1]
#ವ್ಯಾಖ್ಯಾನಿಸು n_zeroes        _n._n_n._n_zeroes
#ವ್ಯಾಖ್ಯಾನಿಸು n_ಸ್ಥಾನಾಂತರ_2        _n._n_n.n_ಸ್ಥಾನಾಂತರ

/*------------------------------------------------------------------------*/
/* Relocatable symbols have a section number of the                       */
/* section in which they are defined.  Otherwise, section                 */
/* numbers have the following meanings:                                   */
/*------------------------------------------------------------------------*/
#ವ್ಯಾಖ್ಯಾನಿಸು  N_UNDEF  0                     /* undefined symbol */
#ವ್ಯಾಖ್ಯಾನಿಸು  N_ABS    -1                    /* value of symbol is absolute */
#ವ್ಯಾಖ್ಯಾನಿಸು  N_DEBUG  -2                    /* special debugging symbol  */
#ವ್ಯಾಖ್ಯಾನಿಸು  N_TV     (ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ)-3    /* needs transfer vector (preload) */
#ವ್ಯಾಖ್ಯಾನಿಸು  P_TV     (ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ)-4    /* needs transfer vector (postload) */


/*------------------------------------------------------------------------*/
/* The fundamental type of a symbol packed into the low                   */
/* 4 bits of the word.                                                    */
/*------------------------------------------------------------------------*/
#ವ್ಯಾಖ್ಯಾನಿಸು  _EF    ".ef"

#ವ್ಯಾಖ್ಯಾನಿಸು  T_NULL     0          /* no type info */
#ವ್ಯಾಖ್ಯಾನಿಸು  T_ARG      1          /* function argument (only used by compiler) */
#ವ್ಯಾಖ್ಯಾನಿಸು  T_CHAR     2          /* character */
#ವ್ಯಾಖ್ಯಾನಿಸು  T_SHORT    3          /* short integer */
#ವ್ಯಾಖ್ಯಾನಿಸು  T_INT      4          /* integer */
#ವ್ಯಾಖ್ಯಾನಿಸು  T_LONG     5          /* long integer */
#ವ್ಯಾಖ್ಯಾನಿಸು  T_FLOAT    6          /* floating point */
#ವ್ಯಾಖ್ಯಾನಿಸು  T_DOUBLE   7          /* double word */
#ವ್ಯಾಖ್ಯಾನಿಸು  T_STRUCT   8          /* structure  */
#ವ್ಯಾಖ್ಯಾನಿಸು  T_UNION    9          /* union  */
#ವ್ಯಾಖ್ಯಾನಿಸು  T_ENUM     10         /* enumeration  */
#ವ್ಯಾಖ್ಯಾನಿಸು  T_MOE      11         /* member of enumeration */
#ವ್ಯಾಖ್ಯಾನಿಸು  T_UCHAR    12         /* unsigned character */
#ವ್ಯಾಖ್ಯಾನಿಸು  T_USHORT   13         /* unsigned short */
#ವ್ಯಾಖ್ಯಾನಿಸು  T_UINT     14         /* unsigned integer */
#ವ್ಯಾಖ್ಯಾನಿಸು  T_ULONG    15         /* unsigned long */

/*------------------------------------------------------------------------*/
/* derived types are:                                                     */
/*------------------------------------------------------------------------*/
#ವ್ಯಾಖ್ಯಾನಿಸು  DT_NON      0          /* no derived type */
#ವ್ಯಾಖ್ಯಾನಿಸು  DT_PTR      1          /*ಸೂಚಕ*/
#ವ್ಯಾಖ್ಯಾನಿಸು  DT_FCN      2          /* function */
#ವ್ಯಾಖ್ಯಾನಿಸು  DT_ARY      3          /* array */

#ವ್ಯಾಖ್ಯಾನಿಸು MKTYPE(basic, d1,d2,d3,d4,d5,d6) \
       ((basic) | ((d1) <<  4) | ((d2) <<  6) | ((d3) <<  8) |\
                  ((d4) << 10) | ((d5) << 12) | ((d6) << 14))

/*------------------------------------------------------------------------*/
/* type packing constants and macros                                      */
/*------------------------------------------------------------------------*/
#ವ್ಯಾಖ್ಯಾನಿಸು  N_BTMASK_COFF     017
#ವ್ಯಾಖ್ಯಾನಿಸು  N_TMASK_COFF      060
#ವ್ಯಾಖ್ಯಾನಿಸು  N_TMASK1_COFF     0300
#ವ್ಯಾಖ್ಯಾನಿಸು  N_TMASK2_COFF     0360
#ವ್ಯಾಖ್ಯಾನಿಸು  N_BTSHFT_COFF     4
#ವ್ಯಾಖ್ಯಾನಿಸು  N_TSHIFT_COFF     2

#ವ್ಯಾಖ್ಯಾನಿಸು  BTYPE_COFF(x)  ((x) & N_BTMASK_COFF)  
#ವ್ಯಾಖ್ಯಾನಿಸು  ISINT(x)  (((x) >= T_CHAR && (x) <= T_LONG) ||   \
		    ((x) >= T_UCHAR && (x) <= T_ULONG) || (x) == T_ENUM)
#ವ್ಯಾಖ್ಯಾನಿಸು  ISFLT_COFF(x)  ((x) == T_DOUBLE || (x) == T_FLOAT)
#ವ್ಯಾಖ್ಯಾನಿಸು  ISPTR_COFF(x)  (((x) & N_TMASK_COFF) == (DT_PTR << N_BTSHFT_COFF)) 
#ವ್ಯಾಖ್ಯಾನಿಸು  ISFCN_COFF(x)  (((x) & N_TMASK_COFF) == (DT_FCN << N_BTSHFT_COFF))
#ವ್ಯಾಖ್ಯಾನಿಸು  ISARY_COFF(x)  (((x) & N_TMASK_COFF) == (DT_ARY << N_BTSHFT_COFF))
#ವ್ಯಾಖ್ಯಾನಿಸು  ISTAG_COFF(x)  ((x)==C_STRTAG || (x)==C_UNTAG || (x)==C_ENTAG)

#ವ್ಯಾಖ್ಯಾನಿಸು  INCREF_COFF(x) ((((x)&~N_BTMASK_COFF)<<N_TSHIFT_COFF)|(DT_PTR<<N_BTSHFT_COFF)|(x&N_BTMASK_COFF))
#ವ್ಯಾಖ್ಯಾನಿಸು  DECREF_COFF(x) ((((x)>>N_TSHIFT_COFF)&~N_BTMASK_COFF)|((x)&N_BTMASK_COFF))


/*------------------------------------------------------------------------*/
/*  AUXILIARY SYMBOL ENTRY                                                */
/*------------------------------------------------------------------------*/
ಒಕ್ಕೂಟ auxent
{
	ರಚನೆ
	{
		ದೀರ್ಘ            x_tagndx;       /* str, un, or enum tag indx */
		ಒಕ್ಕೂಟ
		{
			ರಚನೆ
			{
				ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ  x_lnno; /* declaration line number */
				ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ  x_ಗಾತ್ರ; /* str, union, array size */
			} x_lnsz;
			ದೀರ್ಘ    x_fsize;        /* size of function */
		} x_misc;
		ಒಕ್ಕೂಟ
		{
			ರಚನೆ                  /* if ISFCN, tag, or .bb */
			{
				ದೀರ್ಘ    x_lnnoptr;      /* ptr to fcn line # */
				ದೀರ್ಘ    x_endndx;       /* entry ndx past block end */
			}       x_fcn;
			ರಚನೆ                  /* if ISARY, up to 4 dimen. */
			{
				ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ  x_dimen[DIMNUM];
			}       x_ary;
		}               x_fcnary;
		ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ  x_regcount;   /* number of registers used by func */
	}       x_sym;
	ರಚನೆ
	{
		ಅಕ್ಷರ    x_fname[FILNMLEN];
	}       x_file;
	ರಚನೆ
	{
		ದೀರ್ಘ    x_scnlen;          /* section length */
		ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ  x_nreloc;  /* number of relocation entries */
		ಚಿಹ್ನೆರಹಿತ ಗಿಡ್ಡ  x_nlinno;  /* number of line numbers */
	}       x_scn;
};

#ವ್ಯಾಖ್ಯಾನಿಸು SYMENT  ರಚನೆ syment
#ವ್ಯಾಖ್ಯಾನಿಸು SYMESZ  18      /* sizeof(SYMENT) */

#ವ್ಯಾಖ್ಯಾನಿಸು AUXENT  ಒಕ್ಕೂಟ auxent
#ವ್ಯಾಖ್ಯಾನಿಸು AUXESZ  18      /* sizeof(AUXENT) */

/*------------------------------------------------------------------------*/
/*  NAMES OF "SPECIAL" SYMBOLS                                            */
/*------------------------------------------------------------------------*/
#ವ್ಯಾಖ್ಯಾನಿಸು _STEXT          ".text"
#ವ್ಯಾಖ್ಯಾನಿಸು _ETEXT          "etext"
#ವ್ಯಾಖ್ಯಾನಿಸು _SDATA          ".data"
#ವ್ಯಾಖ್ಯಾನಿಸು _EDATA          "edata"
#ವ್ಯಾಖ್ಯಾನಿಸು _SBSS           ".bss"
#ವ್ಯಾಖ್ಯಾನಿಸು ಕೊನೆ_2            "end"
#ವ್ಯಾಖ್ಯಾನಿಸು _CINITPTR       "cinit"

/*--------------------------------------------------------------------------*/
/*  ENTRY POINT SYMBOLS                                                     */
/*--------------------------------------------------------------------------*/
#ವ್ಯಾಖ್ಯಾನಿಸು ಆರಂಭ_2          "_start"
#ವ್ಯಾಖ್ಯಾನಿಸು _MAIN           "_main"
    /*  _CSTART         "_c_int00"          (defined in params.h)  */


#ವ್ಯಾಖ್ಯಾನಿಸು _TVORIG         "_tvorig"
#ವ್ಯಾಖ್ಯಾನಿಸು _TORIGIN        "_torigin"
#ವ್ಯಾಖ್ಯಾನಿಸು _DORIGIN        "_dorigin"

#ವ್ಯಾಖ್ಯಾನಿಸು _SORIGIN        "_sorigin"

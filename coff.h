/**************************************************************************/
/*  COFF.H                                                                */
/*     COFF data structures and related definitions used by the linker    */
/**************************************************************************/

/*------------------------------------------------------------------------*/
/*  COFF FILE HEADER                                                      */
/*------------------------------------------------------------------------*/
ਬਣਤਰ filehdr {
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ  f_magic;        /* magic number */
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ  f_nscns;        /* number of sections */
        ਲੰਮਾ            f_timdat;       /* time & date stamp */
        ਲੰਮਾ            f_symptr;       /* file pointer to symtab */
        ਲੰਮਾ            f_nsyms;        /* number of symtab entries */
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ  f_opthdr;       /* sizeof(optional hdr) */
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ  f_flags;        /* flags */
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ  f_ਨਿਸ਼ਾਨਾ_ID;     /* for C6x = 0x0099 */
        };

/*------------------------------------------------------------------------*/
/*  File header flags                                                     */
/*------------------------------------------------------------------------*/
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  F_RELFLG   0x01       /* relocation info stripped from file       */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  F_EXEC     0x02       /* file is executable (no unresolved refs)  */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  F_LNNO     0x04       /* line numbers stripped from file          */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  F_LSYMS    0x08       /* local symbols stripped from file         */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  F_GSP10    0x10       /* 34010 version                            */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  F_GSP20    0x20       /* 34020 version                            */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  F_SWABD    0x40       /* bytes swabbed (in names)                 */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  F_AR16WR   0x80       /* byte ordering of an AR16WR (PDP-11)      */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  F_LITTLE   0x100      /* byte ordering of an AR32WR (vax)         */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  F_BIG      0x200      /* byte ordering of an AR32W (3B, maxi)     */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  F_PATCH    0x400      /* contains "patch" list in optional header */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  F_NODF     0x400   

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ F_ਸੰਸਕਰਣ    (F_GSP10  | F_GSP20)   
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ F_BYTE_ਕ੍ਰਮ (F_LITTLE | F_BIG)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILHDR  ਬਣਤਰ filehdr

/* #define FILHSZ  sizeof(FILHDR)  */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ FILHSZ  22                /* above rounds to align on 4 bytes which causes problems */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COFF_C67_MAGIC 0x00c2

/*------------------------------------------------------------------------*/
/*  Macros to recognize magic numbers                                     */
/*------------------------------------------------------------------------*/
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ISMAGIC(x)      (((ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ)(x))==(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ)magic)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ISARCHIVE(x)    ((((ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ)(x))==(ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ)ARTYPE))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ BADMAGIC(x)     (((ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ)(x) & 0x8080) && !ISMAGIC(x))


/*------------------------------------------------------------------------*/
/*  OPTIONAL FILE HEADER                                                  */
/*------------------------------------------------------------------------*/
ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ aouthdr {
        ਛੋਟਾ   magic;          /* see magic.h                          */
        ਛੋਟਾ   vstamp;         /* version stamp                        */
        ਲੰਮਾ    tsize;          /* text size in bytes, padded to FW bdry*/
        ਲੰਮਾ    dsize;          /* initialized data "  "                */
        ਲੰਮਾ    bsize;          /* uninitialized data "   "             */
        ਲੰਮਾ    entrypt;        /* entry pt.                            */
        ਲੰਮਾ    ਪਾਠ_ਸ਼ੁਰੂ;     /* base of text used for this file      */
        ਲੰਮਾ    ਅੰਕੜੇ_ਸ਼ੁਰੂ;     /* base of data used for this file      */
} AOUTHDR;

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AOUTSZ  ਆਕਾਰ(AOUTHDR)

/*----------------------------------------------------------------------*/
/*      When a UNIX aout header is to be built in the optional header,  */
/*      the following magic numbers can appear in that header:          */ 
/*                                                                      */
/*              AOUT1MAGIC : default : readonly sharable text segment   */
/*              AOUT2MAGIC:          : writable text segment            */
/*              PAGEMAGIC  :         : configured for paging            */
/*----------------------------------------------------------------------*/
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AOUT1MAGIC 0410
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AOUT2MAGIC 0407
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ PAGEMAGIC  0413


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

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ COFF_ARMAG   "!<arch>\n"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SARMAG  8
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ARFMAG  "`\n"

ਬਣਤਰ ar_hdr           /* archive file member header - printable ascii */
{
        ਅੱਖਰ    ar_name[16];    /* file member name - `/' terminated */
        ਅੱਖਰ    ar_date[12];    /* file member date - decimal */
        ਅੱਖਰ    ar_uid[6];      /* file member user id - decimal */
        ਅੱਖਰ    ar_gid[6];      /* file member group id - decimal */
        ਅੱਖਰ    ar_ਬਹੁਲਕ[8];     /* file member mode - octal */
        ਅੱਖਰ    ar_ਮਾਪ[10];    /* file member size - decimal */
        ਅੱਖਰ    ar_fmag[2];     /* ARFMAG - string to end header */
};


/*------------------------------------------------------------------------*/
/*  SECTION HEADER                                                        */
/*------------------------------------------------------------------------*/
ਬਣਤਰ scnhdr {
        ਅੱਖਰ            s_name[8];      /* section name */
        ਲੰਮਾ            s_paddr;        /* physical address */
        ਲੰਮਾ            s_vaddr;        /* virtual address */
        ਲੰਮਾ            s_ਮਾਪ;         /* section size */
        ਲੰਮਾ            s_scnptr;       /* file ptr to raw data for section */
        ਲੰਮਾ            s_relptr;       /* file ptr to relocation */
        ਲੰਮਾ            s_lnnoptr;      /* file ptr to line numbers */
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ	s_nreloc;       /* number of relocation entries */
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ	s_nlnno;        /* number of line number entries */
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ	s_flags;        /* flags */
		ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ	s_reserved;     /* reserved byte */
		ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ  s_ਪੰਨਾ;         /* memory page id */
        };

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNHDR  ਬਣਤਰ scnhdr
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SCNHSZ  ਆਕਾਰ(SCNHDR)

/*------------------------------------------------------------------------*/
/* Define constants for names of "special" sections                       */
/*------------------------------------------------------------------------*/
/* #define _TEXT    ".text" */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਅੰਕੜੇ_2    ".data"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _BSS     ".bss"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CINIT   ".cinit"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TV      ".tv"

/*------------------------------------------------------------------------*/
/* The low 4 bits of s_flags is used as a section "type"                  */
/*------------------------------------------------------------------------*/
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STYP_REG    0x00  /* "regular" : allocated, relocated, loaded */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STYP_DSECT  0x01  /* "dummy"   : not allocated, relocated, not loaded */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STYP_NOLOAD 0x02  /* "noload"  : allocated, relocated, not loaded */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STYP_ਸਮੂਹ  0x04  /* "grouped" : formed of input sections */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STYP_PAD    0x08  /* "padding" : not allocated, not relocated, loaded */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STYP_COPY   0x10  /* "copy"    : used for C init tables - 
                                                not allocated, relocated,
                                                loaded;  reloc & lineno
                                                entries processed normally */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STYP_ਪਾਠ   0x20   /* section contains text only */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STYP_ਅੰਕੜੇ   0x40   /* section contains data only */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STYP_BSS    0x80   /* section contains bss only */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ STYP_ALIGN  0x100  /* align flag passed by old version assemblers */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ALIGN_ਨਕਾਬ  0x0F00 /* part of s_flags that is used for align vals */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ALIGNSIZE(x) (1 << ((x & ALIGN_ਨਕਾਬ) >> 8))


/*------------------------------------------------------------------------*/
/*  RELOCATION ENTRIES                                                    */
/*------------------------------------------------------------------------*/
ਬਣਤਰ reloc
{
   ਲੰਮਾ            r_vaddr;        /* (virtual) address of reference */
   ਛੋਟਾ           r_symndx;       /* index into symbol table */
   ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ  r_disp;         /* additional bits for address calculation */
   ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ  r_type;         /* relocation type */
};

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RELOC   ਬਣਤਰ reloc
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ RELSZ   10                 /* sizeof(RELOC) */

/*--------------------------------------------------------------------------*/
/*   define all relocation types                                            */
/*--------------------------------------------------------------------------*/

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_ABS           0         /* absolute address - no relocation       */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_DIR16         01        /*ਅਣਵਰਤਿਆ*/
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_REL16         02        /*ਅਣਵਰਤਿਆ*/
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_DIR24         04        /*ਅਣਵਰਤਿਆ*/
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_REL24         05        /* 24 bits, direct                        */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_DIR32         06        /*ਅਣਵਰਤਿਆ*/
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_RELBYTE      017        /* 8 bits, direct                         */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_RELWORD      020        /* 16 bits, direct                        */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_RELLONG      021        /* 32 bits, direct                        */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_PCRBYTE      022        /* 8 bits, PC-relative                    */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_PCRWORD      023        /* 16 bits, PC-relative                   */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_PCRLONG      024        /* 32 bits, PC-relative                   */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_OCRLONG      030        /* GSP: 32 bits, one's complement direct  */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_GSPPCR16     031        /* GSP: 16 bits, PC relative (in words)   */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_GSPOPR32     032        /* GSP: 32 bits, direct big-endian        */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_PARTLS16     040        /* Brahma: 16 bit offset of 24 bit address*/
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_PARTMS8      041        /* Brahma: 8 bit page of 24 bit address   */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_PARTLS7      050        /* DSP: 7 bit offset of 16 bit address    */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_PARTMS9      051        /* DSP: 9 bit page of 16 bit address      */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ R_REL13        052        /* DSP: 13 bits, direct                   */


/*------------------------------------------------------------------------*/
/*  LINE NUMBER ENTRIES                                                   */
/*------------------------------------------------------------------------*/
ਬਣਤਰ lineno
{
        ਸੰਘ
        {
                ਲੰਮਾ    l_symndx ;      /* sym. table index of function name
                                                iff l_lnno == 0      */
                ਲੰਮਾ    l_paddr ;       /* (physical) address of line number */
        }               l_addr ;
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ  l_lnno ;        /* line number */
};

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LINENO  ਬਣਤਰ lineno
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ LINESZ  6       /* sizeof(LINENO) */


/*------------------------------------------------------------------------*/
/*   STORAGE CLASSES                                                      */
/*------------------------------------------------------------------------*/
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  C_EFCN          -1    /* physical end of function */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  C_NULL          0
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  C_AUTO          1     /* automatic variable */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  C_EXT           2     /* external symbol */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  C_STAT          3     /* static */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  C_REG           4     /* register variable */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  C_EXTDEF        5     /* external definition */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  C_LABEL         6     /* label */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  C_ULABEL        7     /* undefined label */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  C_MOS           8     /* member of structure */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  C_ARG           9     /* function argument */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  C_STRTAG        10    /* structure tag */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  C_MOU           11    /* member of union */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  C_UNTAG         12    /* union tag */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  C_TPDEF         13    /* type definition */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ C_USTATIC        14    /* undefined static */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  C_ENTAG         15    /* enumeration tag */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  C_MOE           16    /* member of enumeration */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  C_REGPARM       17    /* register parameter */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  C_ਖੇਤਰ         18    /* bit field */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  C_ਖੰਡ         100   /* ".bb" or ".eb" */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  C_FCN           101   /* ".bf" or ".ef" */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  C_EOS           102   /* end of structure */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  C_FILE          103   /* file name */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  C_ਸਤਰ          104   /* dummy sclass for line number entry */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  C_ALIAS         105   /* duplicate tag */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  C_HIDDEN        106   /* special storage class for external */
                               /* symbols in dmert public libraries  */

/*------------------------------------------------------------------------*/
/*  SYMBOL TABLE ENTRIES                                                  */
/*------------------------------------------------------------------------*/

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  SYMNMLEN   8      /*  Number of characters in a symbol name */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  FILNMLEN   14     /*  Number of characters in a file name */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  DIMNUM     4      /*  Number of array dimensions in auxiliary entry */


ਬਣਤਰ syment
{
        ਸੰਘ
        {
                ਅੱਖਰ            _n_name[SYMNMLEN];      /* old COFF version */
                ਬਣਤਰ
                {
                        ਲੰਮਾ    _n_zeroes;      /* new == 0 */
                        ਲੰਮਾ    n_ਵਿੱਥ;      /* offset into string table */
                } _n_n;
                ਅੱਖਰ            *_n_nptr[2];    /* allows for overlaying */
        } _n;
        ਲੰਮਾ                    n_ਮੁੱਲ;        /* value of symbol */
        ਛੋਟਾ                   n_scnum;        /* section number */
        ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ          n_type;         /* type and derived type */
        ਅੱਖਰ                    n_sclass;       /* storage class */
        ਅੱਖਰ                    n_numaux;       /* number of aux. entries */
};

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ n_name          _n._n_name
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ n_nptr          _n._n_nptr[1]
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ n_zeroes        _n._n_n._n_zeroes
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ n_ਵਿੱਥ_2        _n._n_n.n_ਵਿੱਥ

/*------------------------------------------------------------------------*/
/* Relocatable symbols have a section number of the                       */
/* section in which they are defined.  Otherwise, section                 */
/* numbers have the following meanings:                                   */
/*------------------------------------------------------------------------*/
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  N_UNDEF  0                     /* undefined symbol */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  N_ABS    -1                    /* value of symbol is absolute */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  N_DEBUG  -2                    /* special debugging symbol  */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  N_TV     (ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ)-3    /* needs transfer vector (preload) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  P_TV     (ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ)-4    /* needs transfer vector (postload) */


/*------------------------------------------------------------------------*/
/* The fundamental type of a symbol packed into the low                   */
/* 4 bits of the word.                                                    */
/*------------------------------------------------------------------------*/
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  _EF    ".ef"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  T_NULL     0          /* no type info */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  T_ARG      1          /* function argument (only used by compiler) */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  T_CHAR     2          /* character */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  T_SHORT    3          /* short integer */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  T_INT      4          /* integer */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  T_LONG     5          /* long integer */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  T_FLOAT    6          /* floating point */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  T_DOUBLE   7          /* double word */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  T_STRUCT   8          /* structure  */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  T_UNION    9          /* union  */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  T_ENUM     10         /* enumeration  */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  T_MOE      11         /* member of enumeration */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  T_UCHAR    12         /* unsigned character */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  T_USHORT   13         /* unsigned short */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  T_UINT     14         /* unsigned integer */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  T_ULONG    15         /* unsigned long */

/*------------------------------------------------------------------------*/
/* derived types are:                                                     */
/*------------------------------------------------------------------------*/
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  DT_NON      0          /* no derived type */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  DT_PTR      1          /*ਸੂਚਕ*/
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  DT_FCN      2          /* function */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  DT_ARY      3          /* array */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ MKTYPE(basic, d1,d2,d3,d4,d5,d6) \
       ((basic) | ((d1) <<  4) | ((d2) <<  6) | ((d3) <<  8) |\
                  ((d4) << 10) | ((d5) << 12) | ((d6) << 14))

/*------------------------------------------------------------------------*/
/* type packing constants and macros                                      */
/*------------------------------------------------------------------------*/
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  N_BTMASK_COFF     017
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  N_TMASK_COFF      060
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  N_TMASK1_COFF     0300
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  N_TMASK2_COFF     0360
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  N_BTSHFT_COFF     4
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  N_TSHIFT_COFF     2

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  BTYPE_COFF(x)  ((x) & N_BTMASK_COFF)  
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  ISINT(x)  (((x) >= T_CHAR && (x) <= T_LONG) ||   \
		    ((x) >= T_UCHAR && (x) <= T_ULONG) || (x) == T_ENUM)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  ISFLT_COFF(x)  ((x) == T_DOUBLE || (x) == T_FLOAT)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  ISPTR_COFF(x)  (((x) & N_TMASK_COFF) == (DT_PTR << N_BTSHFT_COFF)) 
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  ISFCN_COFF(x)  (((x) & N_TMASK_COFF) == (DT_FCN << N_BTSHFT_COFF))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  ISARY_COFF(x)  (((x) & N_TMASK_COFF) == (DT_ARY << N_BTSHFT_COFF))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  ISTAG_COFF(x)  ((x)==C_STRTAG || (x)==C_UNTAG || (x)==C_ENTAG)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  INCREF_COFF(x) ((((x)&~N_BTMASK_COFF)<<N_TSHIFT_COFF)|(DT_PTR<<N_BTSHFT_COFF)|(x&N_BTMASK_COFF))
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ  DECREF_COFF(x) ((((x)>>N_TSHIFT_COFF)&~N_BTMASK_COFF)|((x)&N_BTMASK_COFF))


/*------------------------------------------------------------------------*/
/*  AUXILIARY SYMBOL ENTRY                                                */
/*------------------------------------------------------------------------*/
ਸੰਘ auxent
{
	ਬਣਤਰ
	{
		ਲੰਮਾ            x_tagndx;       /* str, un, or enum tag indx */
		ਸੰਘ
		{
			ਬਣਤਰ
			{
				ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ  x_lnno; /* declaration line number */
				ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ  x_ਮਾਪ; /* str, union, array size */
			} x_lnsz;
			ਲੰਮਾ    x_fsize;        /* size of function */
		} x_misc;
		ਸੰਘ
		{
			ਬਣਤਰ                  /* if ISFCN, tag, or .bb */
			{
				ਲੰਮਾ    x_lnnoptr;      /* ptr to fcn line # */
				ਲੰਮਾ    x_endndx;       /* entry ndx past block end */
			}       x_fcn;
			ਬਣਤਰ                  /* if ISARY, up to 4 dimen. */
			{
				ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ  x_dimen[DIMNUM];
			}       x_ary;
		}               x_fcnary;
		ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ  x_regcount;   /* number of registers used by func */
	}       x_sym;
	ਬਣਤਰ
	{
		ਅੱਖਰ    x_fname[FILNMLEN];
	}       x_file;
	ਬਣਤਰ
	{
		ਲੰਮਾ    x_scnlen;          /* section length */
		ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ  x_nreloc;  /* number of relocation entries */
		ਬਿਨਾਨਿਸ਼ਾਨੀ ਛੋਟਾ  x_nlinno;  /* number of line numbers */
	}       x_scn;
};

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SYMENT  ਬਣਤਰ syment
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ SYMESZ  18      /* sizeof(SYMENT) */

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AUXENT  ਸੰਘ auxent
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ AUXESZ  18      /* sizeof(AUXENT) */

/*------------------------------------------------------------------------*/
/*  NAMES OF "SPECIAL" SYMBOLS                                            */
/*------------------------------------------------------------------------*/
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _STEXT          ".text"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _ETEXT          "etext"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _SDATA          ".data"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _EDATA          "edata"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _SBSS           ".bss"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸਿਰਾ_2            "end"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _CINITPTR       "cinit"

/*--------------------------------------------------------------------------*/
/*  ENTRY POINT SYMBOLS                                                     */
/*--------------------------------------------------------------------------*/
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ਸ਼ੁਰੂ_2          "_start"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _MAIN           "_main"
    /*  _CSTART         "_c_int00"          (defined in params.h)  */


#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TVORIG         "_tvorig"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _TORIGIN        "_torigin"
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _DORIGIN        "_dorigin"

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ _SORIGIN        "_sorigin"

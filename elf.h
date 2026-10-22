/* This file defines standard ELF types, structures, and macros.
   Copyright (C) 1995-2012 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */

#اگر_تعریف_نشده _ELF_H
#تعریف_کن	_ELF_H 1

#اگر_تعریف_نشده _WIN32
#ضمن <inttypes.h>
#وإلا
#اگر_تعریف_نشده __int8_t_defined
#تعریف_کن __int8_t_defined
تعريفنوع علامتدار حرف int8_t;
تعريفنوع کوتاه صحيح int16_t;
تعريفنوع صحيح int32_t;
تعريفنوع دراز دراز صحيح int64_t;
تعريفنوع بیعلامت حرف           uint8_t;
تعريفنوع بیعلامت کوتاه صحيح      uint16_t;
تعريفنوع بیعلامت صحيح            uint32_t;
تعريفنوع بیعلامت دراز دراز صحيح  uint64_t;
#پایان_اگر
#پایان_اگر

/* Standard ELF types.  */

/* Type for a 16-bit quantity.  */
تعريفنوع uint16_t Elf32_Half;
تعريفنوع uint16_t Elf64_Half;

/* Types for signed and unsigned 32-bit quantities.  */
تعريفنوع uint32_t Elf32_کلمه;
تعريفنوع	int32_t  Elf32_Sword;
تعريفنوع uint32_t Elf64_کلمه;
تعريفنوع	int32_t  Elf64_Sword;

/* Types for signed and unsigned 64-bit quantities.  */
تعريفنوع uint64_t Elf32_Xword;
تعريفنوع	int64_t  Elf32_Sxword;
تعريفنوع uint64_t Elf64_Xword;
تعريفنوع	int64_t  Elf64_Sxword;

/* Type of addresses.  */
تعريفنوع uint32_t Elf32_Addr;
تعريفنوع uint64_t Elf64_Addr;

/* Type of file offsets.  */
تعريفنوع uint32_t Elf32_Off;
تعريفنوع uint64_t Elf64_Off;

/* Type for section indices, which are 16-bit quantities.  */
تعريفنوع uint16_t Elf32_Section;
تعريفنوع uint16_t Elf64_Section;

/* Type for version symbol information.  */
تعريفنوع Elf32_Half Elf32_Versym;
تعريفنوع Elf64_Half Elf64_Versym;


/* The ELF file header.  This appears at the start of every ELF file.  */

#تعریف_کن EI_NIDENT (16)

تعريفنوع بنية
{
  بیعلامت حرف	e_ident[EI_NIDENT];	/* Magic number and other info */
  Elf32_Half	e_type;			/* Object file type */
  Elf32_Half	e_machine;		/* Architecture */
  Elf32_کلمه	e_نسخه;		/* Object file version */
  Elf32_Addr	e_مدخل;		/* Entry point virtual address */
  Elf32_Off	e_phoff;		/* Program header table file offset */
  Elf32_Off	e_shoff;		/* Section header table file offset */
  Elf32_کلمه	e_flags;		/* Processor-specific flags */
  Elf32_Half	e_ehsize;		/* ELF header size in bytes */
  Elf32_Half	e_phentsize;		/* Program header table entry size */
  Elf32_Half	e_phnum;		/* Program header table entry count */
  Elf32_Half	e_shentsize;		/* Section header table entry size */
  Elf32_Half	e_shnum;		/* Section header table entry count */
  Elf32_Half	e_shstrndx;		/* Section header string table index */
} Elf32_Ehdr;

تعريفنوع بنية
{
  بیعلامت حرف	e_ident[EI_NIDENT];	/* Magic number and other info */
  Elf64_Half	e_type;			/* Object file type */
  Elf64_Half	e_machine;		/* Architecture */
  Elf64_کلمه	e_نسخه;		/* Object file version */
  Elf64_Addr	e_مدخل;		/* Entry point virtual address */
  Elf64_Off	e_phoff;		/* Program header table file offset */
  Elf64_Off	e_shoff;		/* Section header table file offset */
  Elf64_کلمه	e_flags;		/* Processor-specific flags */
  Elf64_Half	e_ehsize;		/* ELF header size in bytes */
  Elf64_Half	e_phentsize;		/* Program header table entry size */
  Elf64_Half	e_phnum;		/* Program header table entry count */
  Elf64_Half	e_shentsize;		/* Section header table entry size */
  Elf64_Half	e_shnum;		/* Section header table entry count */
  Elf64_Half	e_shstrndx;		/* Section header string table index */
} Elf64_Ehdr;

/* Fields in the e_ident array.  The EI_* macros are indices into the
   array.  The macros under each EI_* macro are the values the byte
   may have.  */

#تعریف_کن EI_MAG0		0		/* File identification byte 0 index */
#تعریف_کن ELFMAG0		0x7f		/* Magic number byte 0 */

#تعریف_کن EI_MAG1		1		/* File identification byte 1 index */
#تعریف_کن ELFMAG1		'E'		/* Magic number byte 1 */

#تعریف_کن EI_MAG2		2		/* File identification byte 2 index */
#تعریف_کن ELFMAG2		'L'		/* Magic number byte 2 */

#تعریف_کن EI_MAG3		3		/* File identification byte 3 index */
#تعریف_کن ELFMAG3		'F'		/* Magic number byte 3 */

/* Conglomeration of the identification bytes, for easy testing as a word.  */
#تعریف_کن	ELFMAG		"\177ELF"
#تعریف_کن	SELFMAG		4

#تعریف_کن EI_CLASS	4		/* File class byte index */
#تعریف_کن ELFCLASSNONE	0		/* Invalid class */
#تعریف_کن ELFCLASS32	1		/* 32-bit objects */
#تعریف_کن ELFCLASS64	2		/* 64-bit objects */
#تعریف_کن ELFCLASSNUM	3

#تعریف_کن EI_داده		5		/* Data encoding byte index */
#تعریف_کن ELFDATANONE	0		/* Invalid data encoding */
#تعریف_کن ELFDATA2LSB	1		/* 2's complement, little endian */
#تعریف_کن ELFDATA2MSB	2		/* 2's complement, big endian */
#تعریف_کن ELFDATANUM	3

#تعریف_کن EI_نسخه	6		/* File version byte index */
					/* Value must be EV_CURRENT */

#تعریف_کن EI_OSABI	7		/* OS ABI identification */
#تعریف_کن ELFOSABI_NONE		0	/* UNIX System V ABI */
#تعریف_کن ELFOSABI_SYSV		0	/* Alias.  */
#تعریف_کن ELFOSABI_HPUX		1	/* HP-UX */
#تعریف_کن ELFOSABI_NETBSD		2	/* NetBSD.  */
#تعریف_کن ELFOSABI_GNU		3	/* Object uses GNU ELF extensions.  */
#تعریف_کن ELFOSABI_LINUX		ELFOSABI_GNU /* Compatibility alias.  */
#تعریف_کن ELFOSABI_SOLARIS	6	/* Sun Solaris.  */
#تعریف_کن ELFOSABI_AIX		7	/* IBM AIX.  */
#تعریف_کن ELFOSABI_IRIX		8	/* SGI Irix.  */
#تعریف_کن ELFOSABI_FREEBSD	9	/* FreeBSD.  */
#تعریف_کن ELFOSABI_TRU64		10	/* Compaq TRU64 UNIX.  */
#تعریف_کن ELFOSABI_MODESTO	11	/* Novell Modesto.  */
#تعریف_کن ELFOSABI_OPENBSD	12	/* OpenBSD.  */
#تعریف_کن ELFOSABI_OPENVMS        13
#تعریف_کن ELFOSABI_NSK            14      /* Hewlett-Packard Non-Stop Kernel.  */
#تعریف_کن ELFOSABI_AROS           15      /* Amiga Research OS.  */
#تعریف_کن ELFOSABI_FENIXOS        16      /* FenixOS.  */
#تعریف_کن ELFOSABI_ARM_AEABI	64	/* ARM EABI.  */
#تعریف_کن ELFOSABI_C6000_LINUX    65      /* Linux TMS320C6000.  */
#تعریف_کن ELFOSABI_ARM		97	/* ARM */
#تعریف_کن ELFOSABI_STANDALONE	255	/* Standalone (embedded) application */

#تعریف_کن EI_ABIVERSION	8		/* ABI version */

#تعریف_کن EI_PAD		9		/* Byte index of padding bytes */

/* Legal values for e_type (object file type).  */

#تعریف_کن ET_NONE		0		/* No file type */
#تعریف_کن ET_REL		1		/* Relocatable file */
#تعریف_کن ET_EXEC		2		/* Executable file */
#تعریف_کن ET_DYN		3		/* Shared object file */
#تعریف_کن ET_CORE		4		/* Core file */
#تعریف_کن	ET_رقم		5		/* Number of defined types */
#تعریف_کن ET_LOOS		0xfe00		/* OS-specific range start */
#تعریف_کن ET_HIOS		0xfeff		/* OS-specific range end */
#تعریف_کن ET_LOPROC	0xff00		/* Processor-specific range start */
#تعریف_کن ET_HIPROC	0xffff		/* Processor-specific range end */

/* Legal values for e_machine (architecture).  */

#تعریف_کن EM_NONE		 0		/* No machine */
#تعریف_کن EM_M32		 1		/* AT&T WE 32100 */
#تعریف_کن EM_SPARC	 2		/* SUN SPARC */
#تعریف_کن EM_386		 3		/* Intel 80386 */
#تعریف_کن EM_68K		 4		/* Motorola m68k family */
#تعریف_کن EM_88K		 5		/* Motorola m88k family */
#تعریف_کن EM_860		 7		/* Intel 80860 */
#تعریف_کن EM_MIPS		 8		/* MIPS R3000 big-endian */
#تعریف_کن EM_S370		 9		/* IBM System/370 */
#تعریف_کن EM_MIPS_RS3_LE	10		/* MIPS R3000 little-endian */

#تعریف_کن EM_PARISC	15		/* HPPA */
#تعریف_کن EM_VPP500	17		/* Fujitsu VPP500 */
#تعریف_کن EM_SPARC32PLUS	18		/* Sun's "v8plus" */
#تعریف_کن EM_960		19		/* Intel 80960 */
#تعریف_کن EM_PPC		20		/* PowerPC */
#تعریف_کن EM_PPC64	21		/* PowerPC 64-bit */
#تعریف_کن EM_S390		22		/* IBM S390 */

#تعریف_کن EM_V800		36		/* NEC V800 series */
#تعریف_کن EM_FR20		37		/* Fujitsu FR20 */
#تعریف_کن EM_RH32		38		/* TRW RH-32 */
#تعریف_کن EM_RCE		39		/* Motorola RCE */
#تعریف_کن EM_ARM		40		/* ARM */
#تعریف_کن EM_FAKE_ALPHA	41		/* Digital Alpha */
#تعریف_کن EM_SH		42		/* Hitachi SH */
#تعریف_کن EM_SPARCV9	43		/* SPARC v9 64-bit */
#تعریف_کن EM_TRICORE	44		/* Siemens Tricore */
#تعریف_کن EM_ARC		45		/* Argonaut RISC Core */
#تعریف_کن EM_H8_300	46		/* Hitachi H8/300 */
#تعریف_کن EM_H8_300H	47		/* Hitachi H8/300H */
#تعریف_کن EM_H8S		48		/* Hitachi H8S */
#تعریف_کن EM_H8_500	49		/* Hitachi H8/500 */
#تعریف_کن EM_IA_64	50		/* Intel Merced */
#تعریف_کن EM_MIPS_X	51		/* Stanford MIPS-X */
#تعریف_کن EM_COLDFIRE	52		/* Motorola Coldfire */
#تعریف_کن EM_68HC12	53		/* Motorola M68HC12 */
#تعریف_کن EM_MMA		54		/* Fujitsu MMA Multimedia Accelerator*/
#تعریف_کن EM_PCP		55		/* Siemens PCP */
#تعریف_کن EM_NCPU		56		/* Sony nCPU embedded RISC */
#تعریف_کن EM_NDR1		57		/* Denso NDR1 microprocessor */
#تعریف_کن EM_STARCORE	58		/* Motorola Start*Core processor */
#تعریف_کن EM_ME16		59		/* Toyota ME16 processor */
#تعریف_کن EM_ST100	60		/* STMicroelectronic ST100 processor */
#تعریف_کن EM_TINYJ	61		/* Advanced Logic Corp. Tinyj emb.fam*/
#تعریف_کن EM_X86_64	62		/* AMD x86-64 architecture */
#تعریف_کن EM_PDSP		63		/* Sony DSP Processor */

#تعریف_کن EM_FX66		66		/* Siemens FX66 microcontroller */
#تعریف_کن EM_ST9PLUS	67		/* STMicroelectronics ST9+ 8/16 mc */
#تعریف_کن EM_ST7		68		/* STMicroelectronics ST7 8 bit mc */
#تعریف_کن EM_68HC16	69		/* Motorola MC68HC16 microcontroller */
#تعریف_کن EM_68HC11	70		/* Motorola MC68HC11 microcontroller */
#تعریف_کن EM_68HC08	71		/* Motorola MC68HC08 microcontroller */
#تعریف_کن EM_68HC05	72		/* Motorola MC68HC05 microcontroller */
#تعریف_کن EM_SVX		73		/* Silicon Graphics SVx */
#تعریف_کن EM_ST19		74		/* STMicroelectronics ST19 8 bit mc */
#تعریف_کن EM_VAX		75		/* Digital VAX */
#تعریف_کن EM_CRIS		76		/* Axis Communications 32-bit embedded processor */
#تعریف_کن EM_JAVELIN	77		/* Infineon Technologies 32-bit embedded processor */
#تعریف_کن EM_FIREPATH	78		/* Element 14 64-bit DSP Processor */
#تعریف_کن EM_ZSP		79		/* LSI Logic 16-bit DSP Processor */
#تعریف_کن EM_MMIX		80		/* Donald Knuth's educational 64-bit processor */
#تعریف_کن EM_HUANY	81		/* Harvard University machine-independent object files */
#تعریف_کن EM_PRISM	82		/* SiTera Prism */
#تعریف_کن EM_AVR		83		/* Atmel AVR 8-bit microcontroller */
#تعریف_کن EM_FR30		84		/* Fujitsu FR30 */
#تعریف_کن EM_D10V		85		/* Mitsubishi D10V */
#تعریف_کن EM_D30V		86		/* Mitsubishi D30V */
#تعریف_کن EM_V850		87		/* NEC v850 */
#تعریف_کن EM_M32R		88		/* Mitsubishi M32R */
#تعریف_کن EM_MN10300	89		/* Matsushita MN10300 */
#تعریف_کن EM_MN10200	90		/* Matsushita MN10200 */
#تعریف_کن EM_PJ		91		/* picoJava */
#تعریف_کن EM_OPENRISC	92		/* OpenRISC 32-bit embedded processor */
#تعریف_کن EM_ARC_A5	93		/* ARC Cores Tangent-A5 */
#تعریف_کن EM_XTENSA	94		/* Tensilica Xtensa Architecture */
#تعریف_کن EM_AARCH64	183		/* ARM AARCH64 */
#تعریف_کن EM_TILEPRO	188		/* Tilera TILEPro */
#تعریف_کن EM_TILEGX	191		/* Tilera TILE-Gx */
#تعریف_کن EM_RISCV	243	        /* RISC-V */
#تعریف_کن EM_رقم		253

/* If it is necessary to assign new unofficial EM_* values, please
   pick large random numbers (0x8523, 0xa7f2, etc.) to minimize the
   chances of collision with official or non-GNU unofficial values.  */

#تعریف_کن EM_ALPHA	0x9026
#تعریف_کن EM_C60		0x9c60

/* Legal values for e_version (version).  */

#تعریف_کن EV_NONE		0		/* Invalid ELF version */
#تعریف_کن EV_CURRENT	1		/* Current version */
#تعریف_کن EV_رقم		2

/* Section header.  */

تعريفنوع بنية
{
  Elf32_کلمه	sh_name;		/* Section name (string tbl index) */
  Elf32_کلمه	sh_type;		/* Section type */
  Elf32_کلمه	sh_flags;		/* Section flags */
  Elf32_Addr	sh_addr;		/* Section virtual addr at execution */
  Elf32_Off	sh_جابه_جایی;		/* Section file offset */
  Elf32_کلمه	sh_اندازه;		/* Section size in bytes */
  Elf32_کلمه	sh_link;		/* Link to another section */
  Elf32_کلمه	sh_info;		/* Additional section information */
  Elf32_کلمه	sh_addralign;		/* Section alignment */
  Elf32_کلمه	sh_entsize;		/* Entry size if section holds table */
} Elf32_Shdr;

تعريفنوع بنية
{
  Elf64_کلمه	sh_name;		/* Section name (string tbl index) */
  Elf64_کلمه	sh_type;		/* Section type */
  Elf64_Xword	sh_flags;		/* Section flags */
  Elf64_Addr	sh_addr;		/* Section virtual addr at execution */
  Elf64_Off	sh_جابه_جایی;		/* Section file offset */
  Elf64_Xword	sh_اندازه;		/* Section size in bytes */
  Elf64_کلمه	sh_link;		/* Link to another section */
  Elf64_کلمه	sh_info;		/* Additional section information */
  Elf64_Xword	sh_addralign;		/* Section alignment */
  Elf64_Xword	sh_entsize;		/* Entry size if section holds table */
} Elf64_Shdr;

/* Special section indices.  */

#تعریف_کن SHN_UNDEF	0		/* Undefined section */
#تعریف_کن SHN_LORESERVE	0xff00		/* Start of reserved indices */
#تعریف_کن SHN_LOPROC	0xff00		/* Start of processor-specific */
#تعریف_کن SHN_BEFORE	0xff00		/* Order section before all others
					   (Solaris).  */
#تعریف_کن SHN_AFTER	0xff01		/* Order section after all others
					   (Solaris).  */
#تعریف_کن SHN_HIPROC	0xff1f		/* End of processor-specific */
#تعریف_کن SHN_LOOS	0xff20		/* Start of OS-specific */
#تعریف_کن SHN_HIOS	0xff3f		/* End of OS-specific */
#تعریف_کن SHN_ABS		0xfff1		/* Associated symbol is absolute */
#تعریف_کن SHN_COMMON	0xfff2		/* Associated symbol is common */
#تعریف_کن SHN_XINDEX	0xffff		/* Index is in extra table.  */
#تعریف_کن SHN_HIRESERVE	0xffff		/* End of reserved indices */

/* Legal values for sh_type (section type).  */

#تعریف_کن SHT_NULL	  0		/* Section header table entry unused */
#تعریف_کن SHT_PROGBITS	  1		/* Program data */
#تعریف_کن SHT_SYMTAB	  2		/* Symbol table */
#تعریف_کن SHT_STRTAB	  3		/* String table */
#تعریف_کن SHT_RELA	  4		/* Relocation entries with addends */
#تعریف_کن SHT_HASH	  5		/* Symbol hash table */
#تعریف_کن SHT_DYNAMIC	  6		/* Dynamic linking information */
#تعریف_کن SHT_NOTE	  7		/* Notes */
#تعریف_کن SHT_NOBITS	  8		/* Program space with no data (bss) */
#تعریف_کن SHT_REL		  9		/* Relocation entries, no addends */
#تعریف_کن SHT_SHLIB	  10		/* Reserved */
#تعریف_کن SHT_DYNSYM	  11		/* Dynamic linker symbol table */
#تعریف_کن SHT_INIT_ARRAY	  14		/* Array of constructors */
#تعریف_کن SHT_FINI_ARRAY	  15		/* Array of destructors */
#تعریف_کن SHT_PREINIT_ARRAY 16		/* Array of pre-constructors */
#تعریف_کن SHT_گروه	  17		/* Section group */
#تعریف_کن SHT_SYMTAB_SHNDX  18		/* Extended section indices */
#تعریف_کن	SHT_رقم		  19		/* Number of defined types.  */
#تعریف_کن SHT_LOOS	  0x60000000	/* Start OS-specific.  */
#تعریف_کن SHT_GNU_صفات 0x6ffffff5	/* Object attributes.  */
#تعریف_کن SHT_GNU_HASH	  0x6ffffff6	/* GNU-style hash table.  */
#تعریف_کن SHT_GNU_LIBLIST	  0x6ffffff7	/* Prelink library list */
#تعریف_کن SHT_CHECKSUM	  0x6ffffff8	/* Checksum for DSO content.  */
#تعریف_کن SHT_LOSUNW	  0x6ffffffa	/* Sun-specific low bound.  */
#تعریف_کن SHT_SUNW_move	  0x6ffffffa
#تعریف_کن SHT_SUNW_COMDAT   0x6ffffffb
#تعریف_کن SHT_SUNW_syminfo  0x6ffffffc
#تعریف_کن SHT_GNU_verdef	  0x6ffffffd	/* Version definition section.  */
#تعریف_کن SHT_GNU_verneed	  0x6ffffffe	/* Version needs section.  */
#تعریف_کن SHT_GNU_versym	  0x6fffffff	/* Version symbol table.  */
#تعریف_کن SHT_HISUNW	  0x6fffffff	/* Sun-specific high bound.  */
#تعریف_کن SHT_HIOS	  0x6fffffff	/* End OS-specific type */
#تعریف_کن SHT_LOPROC	  0x70000000	/* Start of processor-specific */
#تعریف_کن SHT_HIPROC	  0x7fffffff	/* End of processor-specific */
#تعریف_کن SHT_LOUSER	  0x80000000	/* Start of application-specific */
#تعریف_کن SHT_HIUSER	  0x8fffffff	/* End of application-specific */

/* Legal values for sh_flags (section flags).  */

#تعریف_کن SHF_WRITE	     (1 << 0)	/* Writable */
#تعریف_کن SHF_ALLOC	     (1 << 1)	/* Occupies memory during execution */
#تعریف_کن SHF_EXECINSTR	     (1 << 2)	/* Executable */
#تعریف_کن SHF_ادغام	     (1 << 4)	/* Might be merged */
#تعریف_کن SHF_رشتهها	     (1 << 5)	/* Contains nul-terminated strings */
#تعریف_کن SHF_INFO_LINK	     (1 << 6)	/* `sh_info' contains SHT index */
#تعریف_کن SHF_LINK_ترتیب	     (1 << 7)	/* Preserve order after combining */
#تعریف_کن SHF_OS_NONCONFORMING (1 << 8)	/* Non-standard OS specific handling
					   required */
#تعریف_کن SHF_گروه	     (1 << 9)	/* Section is member of a group.  */
#تعریف_کن SHF_TLS		     (1 << 10)	/* Section hold thread-local data.  */
#تعریف_کن SHF_COMPRESSED	     (1 << 11)	/* Section with compressed data. */
#تعریف_کن SHF_MASKOS	     0x0ff00000	/* OS-specific.  */
#تعریف_کن SHF_MASKPROC	     0xf0000000	/* Processor-specific */
#تعریف_کن SHF_ORDERED	     (1 << 30)	/* Special ordering requirement
					   (Solaris).  */
#تعریف_کن SHF_EXCLUDE	     (1U << 31)	/* Section is excluded unless
					   referenced or allocated (Solaris).*/

/* Section group handling.  */
#تعریف_کن GRP_COMDAT	0x1		/* Mark group as COMDAT.  */

/* Symbol table entry.  */

تعريفنوع بنية
{
  Elf32_کلمه	st_name;		/* Symbol name (string tbl index) */
  Elf32_Addr	st_مقدار;		/* Symbol value */
  Elf32_کلمه	st_اندازه;		/* Symbol size */
  بیعلامت حرف	st_info;		/* Symbol type and binding */
  بیعلامت حرف	st_other;		/* Symbol visibility */
  Elf32_Section	st_shndx;		/* Section index */
} Elf32_Sym;

تعريفنوع بنية
{
  Elf64_کلمه	st_name;		/* Symbol name (string tbl index) */
  بیعلامت حرف	st_info;		/* Symbol type and binding */
  بیعلامت حرف st_other;		/* Symbol visibility */
  Elf64_Section	st_shndx;		/* Section index */
  Elf64_Addr	st_مقدار;		/* Symbol value */
  Elf64_Xword	st_اندازه;		/* Symbol size */
} Elf64_Sym;

/* The syminfo section if available contains additional information about
   every dynamic symbol.  */

تعريفنوع بنية
{
  Elf32_Half si_boundto;		/* Direct bindings, symbol bound to */
  Elf32_Half si_flags;			/* Per symbol flags */
} Elf32_Syminfo;

تعريفنوع بنية
{
  Elf64_Half si_boundto;		/* Direct bindings, symbol bound to */
  Elf64_Half si_flags;			/* Per symbol flags */
} Elf64_Syminfo;

/* Possible values for si_boundto.  */
#تعریف_کن SYMINFO_BT_SELF		0xffff	/* Symbol bound to self */
#تعریف_کن SYMINFO_BT_والد	0xfffe	/* Symbol bound to parent */
#تعریف_کن SYMINFO_BT_LOWRESERVE	0xff00	/* Beginning of reserved entries */

/* Possible bitmasks for si_flags.  */
#تعریف_کن SYMINFO_FLG_مستقیم	0x0001	/* Direct bound symbol */
#تعریف_کن SYMINFO_FLG_PASSTHRU	0x0002	/* Pass-thru symbol for translator */
#تعریف_کن SYMINFO_FLG_COPY	0x0004	/* Symbol is a copy-reloc */
#تعریف_کن SYMINFO_FLG_LAZYLOAD	0x0008	/* Symbol bound to object to be lazy
					   loaded */
/* Syminfo version values.  */
#تعریف_کن SYMINFO_NONE		0
#تعریف_کن SYMINFO_CURRENT		1
#تعریف_کن SYMINFO_رقم		2


/* How to extract and insert information held in the st_info field.  */

#تعریف_کن ELF32_ST_BIND(val)		(((بیعلامت حرف) (val)) >> 4)
#تعریف_کن ELF32_ST_TYPE(val)		((val) & 0xf)
#تعریف_کن ELF32_ST_INFO(bind, type)	(((bind) << 4) + ((type) & 0xf))

/* Both Elf32_Sym and Elf64_Sym use the same one-byte st_info field.  */
#تعریف_کن ELF64_ST_BIND(val)		ELF32_ST_BIND (val)
#تعریف_کن ELF64_ST_TYPE(val)		ELF32_ST_TYPE (val)
#تعریف_کن ELF64_ST_INFO(bind, type)	ELF32_ST_INFO ((bind), (type))

/* Legal values for ST_BIND subfield of st_info (symbol binding).  */

#تعریف_کن STB_LOCAL	0		/* Local symbol */
#تعریف_کن STB_GLOBAL	1		/* Global symbol */
#تعریف_کن STB_WEAK	2		/* Weak symbol */
#تعریف_کن	STB_رقم		3		/* Number of defined types.  */
#تعریف_کن STB_LOOS	10		/* Start of OS-specific */
#تعریف_کن STB_GNU_UNIQUE	10		/* Unique symbol.  */
#تعریف_کن STB_HIOS	12		/* End of OS-specific */
#تعریف_کن STB_LOPROC	13		/* Start of processor-specific */
#تعریف_کن STB_HIPROC	15		/* End of processor-specific */

/* Legal values for ST_TYPE subfield of st_info (symbol type).  */

#تعریف_کن STT_NOTYPE	0		/* Symbol type is unspecified */
#تعریف_کن STT_OBJECT	1		/* Symbol is a data object */
#تعریف_کن STT_FUNC	2		/* Symbol is a code object */
#تعریف_کن STT_SECTION	3		/* Symbol associated with a section */
#تعریف_کن STT_FILE	4		/* Symbol's name is file name */
#تعریف_کن STT_COMMON	5		/* Symbol is a common data object */
#تعریف_کن STT_TLS		6		/* Symbol is thread-local data object*/
#تعریف_کن	STT_رقم		7		/* Number of defined types.  */
#تعریف_کن STT_LOOS	10		/* Start of OS-specific */
#تعریف_کن STT_GNU_IFUNC	10		/* Symbol is indirect code object */
#تعریف_کن STT_HIOS	12		/* End of OS-specific */
#تعریف_کن STT_LOPROC	13		/* Start of processor-specific */
#تعریف_کن STT_HIPROC	15		/* End of processor-specific */


/* Symbol table indices are found in the hash buckets and chain table
   of a symbol hash table section.  This special index value indicates
   the end of a chain, meaning no further symbols are found in that bucket.  */

#تعریف_کن STN_UNDEF	0		/* End of a chain.  */


/* How to extract and insert information held in the st_other field.  */

#تعریف_کن ELF32_ST_VISIBILITY(o)	((o) & 0x03)

/* For ELF64 the definitions are the same.  */
#تعریف_کن ELF64_ST_VISIBILITY(o)	ELF32_ST_VISIBILITY (o)

/* Symbol visibility specification encoded in the st_other field.  */
#تعریف_کن STV_DEFAULT	0		/* Default symbol visibility rules */
#تعریف_کن STV_داخلی	1		/* Processor specific hidden class */
#تعریف_کن STV_HIDDEN	2		/* Sym unavailable in other modules */
#تعریف_کن STV_PROTECTED	3		/* Not preemptible, not exported */


/* Relocation table entry without addend (in section of type SHT_REL).  */

تعريفنوع بنية
{
  Elf32_Addr	r_جابه_جایی;		/*آدرس*/
  Elf32_کلمه	r_info;			/* Relocation type and symbol index */
} Elf32_Rel;

/* I have seen two different definitions of the Elf64_Rel and
   Elf64_Rela structures, so we'll leave them out until Novell (or
   whoever) gets their act together.  */
/* The following, at least, is used on Sparc v9, MIPS, and Alpha.  */

تعريفنوع بنية
{
  Elf64_Addr	r_جابه_جایی;		/*آدرس*/
  Elf64_Xword	r_info;			/* Relocation type and symbol index */
} Elf64_Rel;

/* Relocation table entry with addend (in section of type SHT_RELA).  */

تعريفنوع بنية
{
  Elf32_Addr	r_جابه_جایی;		/*آدرس*/
  Elf32_کلمه	r_info;			/* Relocation type and symbol index */
  Elf32_Sword	r_addend;		/* Addend */
} Elf32_Rela;

تعريفنوع بنية
{
  Elf64_Addr	r_جابه_جایی;		/*آدرس*/
  Elf64_Xword	r_info;			/* Relocation type and symbol index */
  Elf64_Sxword	r_addend;		/* Addend */
} Elf64_Rela;

/* How to extract and insert information held in the r_info field.  */

#تعریف_کن ELF32_R_SYM(val)		((val) >> 8)
#تعریف_کن ELF32_R_TYPE(val)		((val) & 0xff)
#تعریف_کن ELF32_R_INFO(sym, type)		(((sym) << 8) + ((type) & 0xff))

#تعریف_کن ELF64_R_SYM(i)			((i) >> 32)
#تعریف_کن ELF64_R_TYPE(i)			((i) & 0xffffffff)
#تعریف_کن ELF64_R_INFO(sym,type)		((((Elf64_Xword) (sym)) << 32) + (type))

/* Program segment header.  */

تعريفنوع بنية
{
  Elf32_کلمه	p_type;			/* Segment type */
  Elf32_Off	p_جابه_جایی;		/* Segment file offset */
  Elf32_Addr	p_vaddr;		/* Segment virtual address */
  Elf32_Addr	p_paddr;		/* Segment physical address */
  Elf32_کلمه	p_filesz;		/* Segment size in file */
  Elf32_کلمه	p_memsz;		/* Segment size in memory */
  Elf32_کلمه	p_flags;		/* Segment flags */
  Elf32_کلمه	p_align;		/* Segment alignment */
} Elf32_Phdr;

تعريفنوع بنية
{
  Elf64_کلمه	p_type;			/* Segment type */
  Elf64_کلمه	p_flags;		/* Segment flags */
  Elf64_Off	p_جابه_جایی;		/* Segment file offset */
  Elf64_Addr	p_vaddr;		/* Segment virtual address */
  Elf64_Addr	p_paddr;		/* Segment physical address */
  Elf64_Xword	p_filesz;		/* Segment size in file */
  Elf64_Xword	p_memsz;		/* Segment size in memory */
  Elf64_Xword	p_align;		/* Segment alignment */
} Elf64_Phdr;

/* Special value for e_phnum.  This indicates that the real number of
   program headers is too large to fit into e_phnum.  Instead the real
   value is in the field sh_info of section 0.  */

#تعریف_کن PN_XNUM		0xffff

/* Legal values for p_type (segment type).  */

#تعریف_کن	PT_NULL		0		/* Program header table entry unused */
#تعریف_کن PT_بارگیری		1		/* Loadable program segment */
#تعریف_کن PT_DYNAMIC	2		/* Dynamic linking information */
#تعریف_کن PT_INTERP	3		/* Program interpreter */
#تعریف_کن PT_NOTE		4		/* Auxiliary information */
#تعریف_کن PT_SHLIB	5		/* Reserved */
#تعریف_کن PT_PHDR		6		/* Entry for header table itself */
#تعریف_کن PT_TLS		7		/* Thread-local storage segment */
#تعریف_کن	PT_رقم		8		/* Number of defined types */
#تعریف_کن PT_LOOS		0x60000000	/* Start of OS-specific */
#تعریف_کن PT_GNU_EH_قاب	0x6474e550	/* GCC .eh_frame_hdr segment */
#تعریف_کن PT_GNU_پشته	0x6474e551	/* Indicates stack executability */
#تعریف_کن PT_GNU_RELRO	0x6474e552	/* Read-only after relocation */
#تعریف_کن PT_LOSUNW	0x6ffffffa
#تعریف_کن PT_SUNWBSS	0x6ffffffa	/* Sun Specific segment */
#تعریف_کن PT_SUNWSTACK	0x6ffffffb	/* Stack segment */
#تعریف_کن PT_HISUNW	0x6fffffff
#تعریف_کن PT_HIOS		0x6fffffff	/* End of OS-specific */
#تعریف_کن PT_LOPROC	0x70000000	/* Start of processor-specific */
#تعریف_کن PT_HIPROC	0x7fffffff	/* End of processor-specific */

/* Legal values for p_flags (segment flags).  */

#تعریف_کن PF_X		(1 << 0)	/* Segment is executable */
#تعریف_کن PF_W		(1 << 1)	/* Segment is writable */
#تعریف_کن PF_R		(1 << 2)	/* Segment is readable */
#تعریف_کن PF_MASKOS	0x0ff00000	/* OS-specific */
#تعریف_کن PF_MASKPROC	0xf0000000	/* Processor-specific */

/* Legal values for note segment descriptor types for core files. */

#تعریف_کن NT_PRSTATUS	1		/* Contains copy of prstatus struct */
#تعریف_کن NT_FPREGSET	2		/* Contains copy of fpregset struct */
#تعریف_کن NT_PRPSINFO	3		/* Contains copy of prpsinfo struct */
#تعریف_کن NT_PRXREG	4		/* Contains copy of prxregset struct */
#تعریف_کن NT_TASKSTRUCT	4		/* Contains copy of task structure */
#تعریف_کن NT_PLATFORM	5		/* String from sysinfo(SI_PLATFORM) */
#تعریف_کن NT_AUXV		6		/* Contains copy of auxv array */
#تعریف_کن NT_GWINDOWS	7		/* Contains copy of gwindows struct */
#تعریف_کن NT_ASRS		8		/* Contains copy of asrset struct */
#تعریف_کن NT_PSTATUS	10		/* Contains copy of pstatus struct */
#تعریف_کن NT_PSINFO	13		/* Contains copy of psinfo struct */
#تعریف_کن NT_PRCRED	14		/* Contains copy of prcred struct */
#تعریف_کن NT_UTSNAME	15		/* Contains copy of utsname struct */
#تعریف_کن NT_LWPSTATUS	16		/* Contains copy of lwpstatus struct */
#تعریف_کن NT_LWPSINFO	17		/* Contains copy of lwpinfo struct */
#تعریف_کن NT_PRFPXREG	20		/* Contains copy of fprxregset struct */
#تعریف_کن NT_PRXFPREG	0x46e62b7f	/* Contains copy of user_fxsr_struct */
#تعریف_کن NT_PPC_VMX	0x100		/* PowerPC Altivec/VMX registers */
#تعریف_کن NT_PPC_SPE	0x101		/* PowerPC SPE/EVR registers */
#تعریف_کن NT_PPC_VSX	0x102		/* PowerPC VSX registers */
#تعریف_کن NT_386_TLS	0x200		/* i386 TLS slots (struct user_desc) */
#تعریف_کن NT_386_IOPERM	0x201		/* x86 io permission bitmap (1=deny) */
#تعریف_کن NT_X86_XSTATE	0x202		/* x86 extended state using xsave */
#تعریف_کن NT_S390_بالا_GPRS	0x300	/* s390 upper register halves */
#تعریف_کن NT_S390_TIMER	0x301		/* s390 timer register */
#تعریف_کن NT_S390_TODCMP	0x302		/* s390 TOD clock comparator register */
#تعریف_کن NT_S390_TODPREG	0x303		/* s390 TOD programmable register */
#تعریف_کن NT_S390_CTRS	0x304		/* s390 control registers */
#تعریف_کن NT_S390_پیشوند	0x305		/* s390 prefix register */
#تعریف_کن NT_S390_آخرین_BREAK	0x306	/* s390 breaking event address */
#تعریف_کن NT_S390_SYSTEM_CALL	0x307	/* s390 system call restart data */
#تعریف_کن NT_ARM_VFP	0x400		/* ARM VFP/NEON registers */
#تعریف_کن NT_ARM_TLS	0x401		/* ARM TLS register */
#تعریف_کن NT_ARM_HW_BREAK	0x402		/* ARM hardware breakpoint registers */
#تعریف_کن NT_ARM_HW_WATCH	0x403		/* ARM hardware watchpoint registers */

/* Legal values for the note segment descriptor types for object files.  */

#تعریف_کن NT_نسخه	1		/* Contains a version string.  */


/* Dynamic section entry.  */

تعريفنوع بنية
{
  Elf32_Sword	d_برچسب;			/* Dynamic entry type */
  اتحاد
    {
      Elf32_کلمه d_val;			/* Integer value */
      Elf32_Addr d_ptr;			/* Address value */
    } d_un;
} Elf32_Dyn;

تعريفنوع بنية
{
  Elf64_Sxword	d_برچسب;			/* Dynamic entry type */
  اتحاد
    {
      Elf64_Xword d_val;		/* Integer value */
      Elf64_Addr d_ptr;			/* Address value */
    } d_un;
} Elf64_Dyn;

/* Legal values for d_tag (dynamic entry type).  */

#تعریف_کن DT_NULL		0		/* Marks end of dynamic section */
#تعریف_کن DT_NEEDED	1		/* Name of needed library */
#تعریف_کن DT_PLTRELSZ	2		/* Size in bytes of PLT relocs */
#تعریف_کن DT_PLTGOT	3		/* Processor defined value */
#تعریف_کن DT_HASH		4		/* Address of symbol hash table */
#تعریف_کن DT_STRTAB	5		/* Address of string table */
#تعریف_کن DT_SYMTAB	6		/* Address of symbol table */
#تعریف_کن DT_RELA		7		/* Address of Rela relocs */
#تعریف_کن DT_RELASZ	8		/* Total size of Rela relocs */
#تعریف_کن DT_RELAENT	9		/* Size of one Rela reloc */
#تعریف_کن DT_STRSZ	10		/* Size of string table */
#تعریف_کن DT_SYMENT	11		/* Size of one symbol table entry */
#تعریف_کن DT_INIT		12		/* Address of init function */
#تعریف_کن DT_FINI		13		/* Address of termination function */
#تعریف_کن DT_SONAME	14		/* Name of shared object */
#تعریف_کن DT_RPATH	15		/* Library search path (deprecated) */
#تعریف_کن DT_SYMBOLIC	16		/* Start symbol search here */
#تعریف_کن DT_REL		17		/* Address of Rel relocs */
#تعریف_کن DT_RELSZ	18		/* Total size of Rel relocs */
#تعریف_کن DT_RELENT	19		/* Size of one Rel reloc */
#تعریف_کن DT_PLTREL	20		/* Type of reloc in PLT */
#تعریف_کن DT_DEBUG	21		/* For debugging; unspecified */
#تعریف_کن DT_TEXTREL	22		/* Reloc might modify .text */
#تعریف_کن DT_JMPREL	23		/* Address of PLT relocs */
#تعریف_کن	DT_BIND_NOW	24		/* Process relocations of object */
#تعریف_کن	DT_INIT_ARRAY	25		/* Array with addresses of init fct */
#تعریف_کن	DT_FINI_ARRAY	26		/* Array with addresses of fini fct */
#تعریف_کن	DT_INIT_ARRAYSZ	27		/* Size in bytes of DT_INIT_ARRAY */
#تعریف_کن	DT_FINI_ARRAYSZ	28		/* Size in bytes of DT_FINI_ARRAY */
#تعریف_کن DT_RUNPATH	29		/* Library search path */
#تعریف_کن DT_FLAGS	30		/* Flags for the object being loaded */
#تعریف_کن DT_ENCODING	32		/* Start of encoded range */
#تعریف_کن DT_PREINIT_ARRAY 32		/* Array with addresses of preinit fct*/
#تعریف_کن DT_PREINIT_ARRAYSZ 33		/* size in bytes of DT_PREINIT_ARRAY */
#تعریف_کن	DT_رقم		34		/* Number used */
#تعریف_کن DT_LOOS		0x6000000d	/* Start of OS-specific */
#تعریف_کن DT_HIOS		0x6ffff000	/* End of OS-specific */
#تعریف_کن DT_LOPROC	0x70000000	/* Start of processor-specific */
#تعریف_کن DT_HIPROC	0x7fffffff	/* End of processor-specific */
#تعریف_کن	DT_PROCNUM	DT_MIPS_رقم	/* Most used by any processor */

/* DT_* entries which fall between DT_VALRNGHI & DT_VALRNGLO use the
   Dyn.d_un.d_val field of the Elf*_Dyn structure.  This follows Sun's
   approach.  */
#تعریف_کن DT_VALRNGLO	0x6ffffd00
#تعریف_کن DT_GNU_PRELINKED 0x6ffffdf5	/* Prelinking timestamp */
#تعریف_کن DT_GNU_CONFLICTSZ 0x6ffffdf6	/* Size of conflict section */
#تعریف_کن DT_GNU_LIBLISTSZ 0x6ffffdf7	/* Size of library list */
#تعریف_کن DT_CHECKSUM	0x6ffffdf8
#تعریف_کن DT_PLTPADSZ	0x6ffffdf9
#تعریف_کن DT_MOVEENT	0x6ffffdfa
#تعریف_کن DT_MOVESZ	0x6ffffdfb
#تعریف_کن DT_FEATURE_1	0x6ffffdfc	/* Feature selection (DTF_*).  */
#تعریف_کن DT_POSFLAG_1	0x6ffffdfd	/* Flags for DT_* entries, effecting
					   the following DT_* entry.  */
#تعریف_کن DT_SYMINSZ	0x6ffffdfe	/* Size of syminfo table (in bytes) */
#تعریف_کن DT_SYMINENT	0x6ffffdff	/* Entry size of syminfo */
#تعریف_کن DT_VALRNGHI	0x6ffffdff
#تعریف_کن DT_VALTAGIDX(برچسب)	(DT_VALRNGHI - (برچسب))	/* Reverse order! */
#تعریف_کن DT_VALNUM 12

/* DT_* entries which fall between DT_ADDRRNGHI & DT_ADDRRNGLO use the
   Dyn.d_un.d_ptr field of the Elf*_Dyn structure.

   If any adjustment is made to the ELF object after it has been
   built these entries will need to be adjusted.  */
#تعریف_کن DT_ADDRRNGLO	0x6ffffe00
#تعریف_کن DT_GNU_HASH	0x6ffffef5	/* GNU-style hash table.  */
#تعریف_کن DT_TLSDESC_PLT	0x6ffffef6
#تعریف_کن DT_TLSDESC_GOT	0x6ffffef7
#تعریف_کن DT_GNU_CONFLICT	0x6ffffef8	/* Start of conflict section */
#تعریف_کن DT_GNU_LIBLIST	0x6ffffef9	/* Library list */
#تعریف_کن DT_CONFIG	0x6ffffefa	/* Configuration information.  */
#تعریف_کن DT_DEPAUDIT	0x6ffffefb	/* Dependency auditing.  */
#تعریف_کن DT_AUDIT	0x6ffffefc	/* Object auditing.  */
#تعریف_کن	DT_PLTPAD	0x6ffffefd	/* PLT padding.  */
#تعریف_کن	DT_MOVETAB	0x6ffffefe	/* Move table.  */
#تعریف_کن DT_SYMINFO	0x6ffffeff	/* Syminfo table.  */
#تعریف_کن DT_ADDRRNGHI	0x6ffffeff
#تعریف_کن DT_ADDRTAGIDX(برچسب)	(DT_ADDRRNGHI - (برچسب))	/* Reverse order! */
#تعریف_کن DT_ADDRNUM 11

/* The versioning entry types.  The next are defined as part of the
   GNU extension.  */
#تعریف_کن DT_VERSYM	0x6ffffff0

#تعریف_کن DT_RELACOUNT	0x6ffffff9
#تعریف_کن DT_RELCOUNT	0x6ffffffa

/* These were chosen by Sun.  */
#تعریف_کن DT_FLAGS_1	0x6ffffffb	/* State flags, see DF_1_* below.  */
#تعریف_کن	DT_VERDEF	0x6ffffffc	/* Address of version definition
جدول*/
#تعریف_کن	DT_VERDEFNUM	0x6ffffffd	/* Number of version definitions */
#تعریف_کن	DT_VERNEED	0x6ffffffe	/* Address of table with needed
					   versions */
#تعریف_کن	DT_VERNEEDNUM	0x6fffffff	/* Number of needed versions */
#تعریف_کن DT_VERSIONTAGIDX(برچسب)	(DT_VERNEEDNUM - (برچسب))	/* Reverse order! */
#تعریف_کن DT_VERSIONTAGNUM 16

/* Sun added these machine-independent extensions in the "processor-specific"
   range.  Be compatible.  */
#تعریف_کن DT_AUXILIARY    0x7ffffffd      /* Shared object to load before self */
#تعریف_کن DT_FILTER       0x7fffffff      /* Shared object to get values from */
#تعریف_کن DT_EXTRATAGIDX(برچسب)	((Elf32_کلمه)-((Elf32_Sword) (برچسب) <<1>>1)-1)
#تعریف_کن DT_EXTRANUM	3

/* Values of `d_un.d_val' in the DT_FLAGS entry.  */
#تعریف_کن DF_ORIGIN	0x00000001	/* Object may use DF_ORIGIN */
#تعریف_کن DF_SYMBOLIC	0x00000002	/* Symbol resolutions starts here */
#تعریف_کن DF_TEXTREL	0x00000004	/* Object contains text relocations */
#تعریف_کن DF_BIND_NOW	0x00000008	/* No lazy binding for this object */
#تعریف_کن DF_STATIC_TLS	0x00000010	/* Module uses the static TLS model */

/* State flags selectable in the `d_un.d_val' element of the DT_FLAGS_1
   entry in the dynamic section.  */
#تعریف_کن DF_1_NOW	0x00000001	/* Set RTLD_NOW for this object.  */
#تعریف_کن DF_1_GLOBAL	0x00000002	/* Set RTLD_GLOBAL for this object.  */
#تعریف_کن DF_1_گروه	0x00000004	/* Set RTLD_GROUP for this object.  */
#تعریف_کن DF_1_NODELETE	0x00000008	/* Set RTLD_NODELETE for this object.*/
#تعریف_کن DF_1_LOADFLTR	0x00000010	/* Trigger filtee loading at runtime.*/
#تعریف_کن DF_1_INITFIRST	0x00000020	/* Set RTLD_INITFIRST for this object*/
#تعریف_کن DF_1_NOOPEN	0x00000040	/* Set RTLD_NOOPEN for this object.  */
#تعریف_کن DF_1_ORIGIN	0x00000080	/* $ORIGIN must be handled.  */
#تعریف_کن DF_1_مستقیم	0x00000100	/* Direct binding enabled.  */
#تعریف_کن DF_1_TRANS	0x00000200
#تعریف_کن DF_1_INTERPOSE	0x00000400	/* Object is used to interpose.  */
#تعریف_کن DF_1_NODEFLIB	0x00000800	/* Ignore default lib search path.  */
#تعریف_کن DF_1_NODUMP	0x00001000	/* Object can't be dldump'ed.  */
#تعریف_کن DF_1_CONFALT	0x00002000	/* Configuration alternative created.*/
#تعریف_کن DF_1_ENDFILTEE	0x00004000	/* Filtee terminates filters search. */
#تعریف_کن	DF_1_DISPRELDNE	0x00008000	/* Disp reloc applied at build time. */
#تعریف_کن	DF_1_DISPRELPND	0x00010000	/* Disp reloc applied at run-time.  */
#تعریف_کن	DF_1_NODIRECT	0x00020000	/* Object has no-direct binding. */
#تعریف_کن	DF_1_IGNMULDEF	0x00040000
#تعریف_کن	DF_1_NOKSYMS	0x00080000
#تعریف_کن	DF_1_NOHDR	0x00100000
#تعریف_کن	DF_1_EDITED	0x00200000	/* Object is modified after built.  */
#تعریف_کن	DF_1_NORELOC	0x00400000
#تعریف_کن	DF_1_SYMINTPOSE	0x00800000	/* Object has individual interposers.  */
#تعریف_کن	DF_1_GLOBAUDIT	0x01000000	/* Global auditing required.  */
#تعریف_کن	DF_1_SINGLETON	0x02000000	/* Singleton symbols are used.  */
#تعریف_کن	DF_1_PIE	0x08000000

/* Flags for the feature selection in DT_FEATURE_1.  */
#تعریف_کن DTF_1_PARINIT	0x00000001
#تعریف_کن DTF_1_CONFEXP	0x00000002

/* Flags in the DT_POSFLAG_1 entry effecting only the next DT_* entry.  */
#تعریف_کن DF_P1_LAZYLOAD	0x00000001	/* Lazyload following object.  */
#تعریف_کن DF_P1_GROUPPERM	0x00000002	/* Symbols from next object are not
					   generally available.  */

/* Version definition sections.  */

تعريفنوع بنية
{
  Elf32_Half	vd_نسخه;		/* Version revision */
  Elf32_Half	vd_flags;		/* Version information */
  Elf32_Half	vd_ndx;			/* Version Index */
  Elf32_Half	vd_cnt;			/* Number of associated aux entries */
  Elf32_کلمه	vd_hash;		/* Version name hash value */
  Elf32_کلمه	vd_aux;			/* Offset in bytes to verdaux array */
  Elf32_کلمه	vd_بعدی;		/* Offset in bytes to next verdef
مدخل*/
} Elf32_Verdef;

تعريفنوع بنية
{
  Elf64_Half	vd_نسخه;		/* Version revision */
  Elf64_Half	vd_flags;		/* Version information */
  Elf64_Half	vd_ndx;			/* Version Index */
  Elf64_Half	vd_cnt;			/* Number of associated aux entries */
  Elf64_کلمه	vd_hash;		/* Version name hash value */
  Elf64_کلمه	vd_aux;			/* Offset in bytes to verdaux array */
  Elf64_کلمه	vd_بعدی;		/* Offset in bytes to next verdef
مدخل*/
} Elf64_Verdef;


/* Legal values for vd_version (version revision).  */
#تعریف_کن VER_DEF_NONE	0		/* No version */
#تعریف_کن VER_DEF_CURRENT	1		/* Current version */
#تعریف_کن VER_DEF_رقم	2		/* Given version number */

/* Legal values for vd_flags (version information flags).  */
#تعریف_کن VER_FLG_پایه	0x1		/* Version definition of file itself */
#تعریف_کن VER_FLG_WEAK	0x2		/* Weak version identifier */

/* Versym symbol index values.  */
#تعریف_کن	VER_NDX_LOCAL		0	/* Symbol is local.  */
#تعریف_کن	VER_NDX_GLOBAL		1	/* Symbol is global.  */
#تعریف_کن	VER_NDX_LORESERVE	0xff00	/* Beginning of reserved entries.  */
#تعریف_کن	VER_NDX_ELIMINATE	0xff01	/* Symbol is to be eliminated.  */

/* Auxiliary version information.  */

تعريفنوع بنية
{
  Elf32_کلمه	vda_name;		/* Version or dependency names */
  Elf32_کلمه	vda_بعدی;		/* Offset in bytes to next verdaux
مدخل*/
} Elf32_Verdaux;

تعريفنوع بنية
{
  Elf64_کلمه	vda_name;		/* Version or dependency names */
  Elf64_کلمه	vda_بعدی;		/* Offset in bytes to next verdaux
مدخل*/
} Elf64_Verdaux;


/* Version dependency section.  */

تعريفنوع بنية
{
  Elf32_Half	vn_نسخه;		/* Version of structure */
  Elf32_Half	vn_cnt;			/* Number of associated aux entries */
  Elf32_کلمه	vn_file;		/* Offset of filename for this
					   dependency */
  Elf32_کلمه	vn_aux;			/* Offset in bytes to vernaux array */
  Elf32_کلمه	vn_بعدی;		/* Offset in bytes to next verneed
مدخل*/
} Elf32_Verneed;

تعريفنوع بنية
{
  Elf64_Half	vn_نسخه;		/* Version of structure */
  Elf64_Half	vn_cnt;			/* Number of associated aux entries */
  Elf64_کلمه	vn_file;		/* Offset of filename for this
					   dependency */
  Elf64_کلمه	vn_aux;			/* Offset in bytes to vernaux array */
  Elf64_کلمه	vn_بعدی;		/* Offset in bytes to next verneed
مدخل*/
} Elf64_Verneed;


/* Legal values for vn_version (version revision).  */
#تعریف_کن VER_NEED_NONE	 0		/* No version */
#تعریف_کن VER_NEED_CURRENT 1		/* Current version */
#تعریف_کن VER_NEED_رقم	 2		/* Given version number */

/* Auxiliary needed version information.  */

تعريفنوع بنية
{
  Elf32_کلمه	vna_hash;		/* Hash value of dependency name */
  Elf32_Half	vna_flags;		/* Dependency specific information */
  Elf32_Half	vna_other;		/* Unused */
  Elf32_کلمه	vna_name;		/* Dependency name string offset */
  Elf32_کلمه	vna_بعدی;		/* Offset in bytes to next vernaux
مدخل*/
} Elf32_Vernaux;

تعريفنوع بنية
{
  Elf64_کلمه	vna_hash;		/* Hash value of dependency name */
  Elf64_Half	vna_flags;		/* Dependency specific information */
  Elf64_Half	vna_other;		/* Unused */
  Elf64_کلمه	vna_name;		/* Dependency name string offset */
  Elf64_کلمه	vna_بعدی;		/* Offset in bytes to next vernaux
مدخل*/
} Elf64_Vernaux;


/* Legal values for vna_flags.  */
#تعریف_کن VER_FLG_WEAK	0x2		/* Weak version identifier */


/* Auxiliary vector.  */

/* This vector is normally only used by the program interpreter.  The
   usual definition in an ABI supplement uses the name auxv_t.  The
   vector is not usually defined in a standard <elf.h> file, but it
   can't hurt.  We rename it to avoid conflicts.  The sizes of these
   types are an arrangement between the exec server and the program
   interpreter, so we don't fully specify them here.  */

تعريفنوع بنية
{
  uint32_t a_type;		/* Entry type */
  اتحاد
    {
      uint32_t a_val;		/* Integer value */
      /* We use to have pointer elements added here.  We cannot do that,
	 though, since it does not work when using 32-bit definitions
	 on 64-bit platforms and vice versa.  */
    } a_un;
} Elf32_auxv_t;

تعريفنوع بنية
{
  uint64_t a_type;		/* Entry type */
  اتحاد
    {
      uint64_t a_val;		/* Integer value */
      /* We use to have pointer elements added here.  We cannot do that,
	 though, since it does not work when using 32-bit definitions
	 on 64-bit platforms and vice versa.  */
    } a_un;
} Elf64_auxv_t;

/* Legal values for a_type (entry type).  */

#تعریف_کن AT_NULL		0		/* End of vector */
#تعریف_کن AT_IGNORE	1		/* Entry should be ignored */
#تعریف_کن AT_EXECFD	2		/* File descriptor of program */
#تعریف_کن AT_PHDR		3		/* Program headers for program */
#تعریف_کن AT_PHENT	4		/* Size of program header entry */
#تعریف_کن AT_PHNUM	5		/* Number of program headers */
#تعریف_کن AT_PAGESZ	6		/* System page size */
#تعریف_کن AT_پایه		7		/* Base address of interpreter */
#تعریف_کن AT_FLAGS	8		/* Flags */
#تعریف_کن AT_مدخل	9		/* Entry point of program */
#تعریف_کن AT_NOTELF	10		/* Program is not ELF */
#تعریف_کن AT_UID		11		/* Real uid */
#تعریف_کن AT_EUID		12		/* Effective uid */
#تعریف_کن AT_GID		13		/* Real gid */
#تعریف_کن AT_EGID		14		/* Effective gid */
#تعریف_کن AT_CLKTCK	17		/* Frequency of times() */

/* Some more special a_type values describing the hardware.  */
#تعریف_کن AT_PLATFORM	15		/* String identifying platform.  */
#تعریف_کن AT_HWCAP	16		/* Machine dependent hints about
					   processor capabilities.  */

/* This entry gives some information about the FPU initialization
   performed by the kernel.  */
#تعریف_کن AT_FPUCW	18		/* Used FPU control word.  */

/* Cache block sizes.  */
#تعریف_کن AT_DCACHEBSIZE	19		/* Data cache block size.  */
#تعریف_کن AT_ICACHEBSIZE	20		/* Instruction cache block size.  */
#تعریف_کن AT_UCACHEBSIZE	21		/* Unified cache block size.  */

/* A special ignored value for PPC, used by the kernel to control the
   interpretation of the AUXV. Must be > 16.  */
#تعریف_کن AT_IGNOREPPC	22		/* Entry should be ignored.  */

#تعریف_کن	AT_SECURE	23		/* Boolean, was exec setuid-like?  */

#تعریف_کن AT_پایه_PLATFORM 24		/* String identifying real platforms.*/

#تعریف_کن AT_RANDOM	25		/* Address of 16 random bytes.  */

#تعریف_کن AT_EXECFN	31		/* Filename of executable.  */

/* Pointer to the global system page used for system calls and other
   nice things.  */
#تعریف_کن AT_SYSINFO	32
#تعریف_کن AT_SYSINFO_EHDR	33

/* Shapes of the caches.  Bits 0-3 contains associativity; bits 4-7 contains
   log2 of line size; mask those to get cache size.  */
#تعریف_کن AT_L1I_CACHESHAPE	34
#تعریف_کن AT_L1D_CACHESHAPE	35
#تعریف_کن AT_L2_CACHESHAPE	36
#تعریف_کن AT_L3_CACHESHAPE	37

/* Note section contents.  Each entry in the note section begins with
   a header of a fixed form.  */

تعريفنوع بنية
{
  Elf32_کلمه n_namesz;			/* Length of the note's name.  */
  Elf32_کلمه n_descsz;			/* Length of the note's descriptor.  */
  Elf32_کلمه n_type;			/* Type of the note.  */
} Elf32_Nhdr;

تعريفنوع بنية
{
  Elf64_کلمه n_namesz;			/* Length of the note's name.  */
  Elf64_کلمه n_descsz;			/* Length of the note's descriptor.  */
  Elf64_کلمه n_type;			/* Type of the note.  */
} Elf64_Nhdr;

/* Known names of notes.  */

/* Solaris entries in the note section have this name.  */
#تعریف_کن ELF_NOTE_SOLARIS	"SUNW Solaris"

/* Note entries for GNU systems have this name.  */
#تعریف_کن ELF_NOTE_GNU		"GNU"


/* Defined types of notes for Solaris.  */

/* Value of descriptor (one word) is desired pagesize for the binary.  */
#تعریف_کن ELF_NOTE_PAGESIZE_HINT	1


/* Defined note types for GNU systems.  */

/* ABI information.  The descriptor consists of words:
   word 0: OS descriptor
   word 1: major version of the ABI
   word 2: minor version of the ABI
   word 3: subminor version of the ABI
*/
#تعریف_کن NT_GNU_ABI_برچسب	1
#تعریف_کن ELF_NOTE_ABI	NT_GNU_ABI_برچسب /* Old name.  */

/* Known OSes.  These values can appear in word 0 of an
   NT_GNU_ABI_TAG note section entry.  */
#تعریف_کن ELF_NOTE_OS_LINUX	0
#تعریف_کن ELF_NOTE_OS_GNU		1
#تعریف_کن ELF_NOTE_OS_SOLARIS2	2
#تعریف_کن ELF_NOTE_OS_FREEBSD	3

/* Synthetic hwcap information.  The descriptor begins with two words:
   word 0: number of entries
   word 1: bitmask of enabled entries
   Then follow variable-length entries, one byte followed by a
   '\0'-terminated hwcap name string.  The byte gives the bit
   number to test if enabled, (1U << bit) & bitmask.  */
#تعریف_کن NT_GNU_HWCAP	2

/* Build ID bits as generated by ld --build-id.
   The descriptor consists of any nonzero number of bytes.  */
#تعریف_کن NT_GNU_BUILD_ID	3

/* Version note generated by GNU gold containing a version string.  */
#تعریف_کن NT_GNU_GOLD_نسخه	4


/* Move records.  */
تعريفنوع بنية
{
  Elf32_Xword m_مقدار;		/* Symbol value.  */
  Elf32_کلمه m_info;		/* Size and index.  */
  Elf32_کلمه m_poffset;		/* Symbol offset.  */
  Elf32_Half m_repeat;		/* Repeat count.  */
  Elf32_Half m_stride;		/* Stride info.  */
} Elf32_Move;

تعريفنوع بنية
{
  Elf64_Xword m_مقدار;		/* Symbol value.  */
  Elf64_Xword m_info;		/* Size and index.  */
  Elf64_Xword m_poffset;	/* Symbol offset.  */
  Elf64_Half m_repeat;		/* Repeat count.  */
  Elf64_Half m_stride;		/* Stride info.  */
} Elf64_Move;

/* Macro to construct move records.  */
#تعریف_کن ELF32_M_SYM(info)	((info) >> 8)
#تعریف_کن ELF32_M_اندازه(info)	((بیعلامت حرف) (info))
#تعریف_کن ELF32_M_INFO(sym, اندازه)	(((sym) << 8) + (بیعلامت حرف) (اندازه))

#تعریف_کن ELF64_M_SYM(info)	ELF32_M_SYM (info)
#تعریف_کن ELF64_M_اندازه(info)	ELF32_M_اندازه (info)
#تعریف_کن ELF64_M_INFO(sym, اندازه)	ELF32_M_INFO (sym, اندازه)


/* Motorola 68k specific definitions.  */

/* Values for Elf32_Ehdr.e_flags.  */
#تعریف_کن EF_CPU32	0x00810000

/* m68k relocs.  */

#تعریف_کن R_68K_NONE	0		/* No reloc */
#تعریف_کن R_68K_32	1		/* Direct 32 bit  */
#تعریف_کن R_68K_16	2		/* Direct 16 bit  */
#تعریف_کن R_68K_8		3		/* Direct 8 bit  */
#تعریف_کن R_68K_PC32	4		/* PC relative 32 bit */
#تعریف_کن R_68K_PC16	5		/* PC relative 16 bit */
#تعریف_کن R_68K_PC8	6		/* PC relative 8 bit */
#تعریف_کن R_68K_GOT32	7		/* 32 bit PC relative GOT entry */
#تعریف_کن R_68K_GOT16	8		/* 16 bit PC relative GOT entry */
#تعریف_کن R_68K_GOT8	9		/* 8 bit PC relative GOT entry */
#تعریف_کن R_68K_GOT32O	10		/* 32 bit GOT offset */
#تعریف_کن R_68K_GOT16O	11		/* 16 bit GOT offset */
#تعریف_کن R_68K_GOT8O	12		/* 8 bit GOT offset */
#تعریف_کن R_68K_PLT32	13		/* 32 bit PC relative PLT address */
#تعریف_کن R_68K_PLT16	14		/* 16 bit PC relative PLT address */
#تعریف_کن R_68K_PLT8	15		/* 8 bit PC relative PLT address */
#تعریف_کن R_68K_PLT32O	16		/* 32 bit PLT offset */
#تعریف_کن R_68K_PLT16O	17		/* 16 bit PLT offset */
#تعریف_کن R_68K_PLT8O	18		/* 8 bit PLT offset */
#تعریف_کن R_68K_COPY	19		/* Copy symbol at runtime */
#تعریف_کن R_68K_GLOB_DAT	20		/* Create GOT entry */
#تعریف_کن R_68_K_JMP_جایگاه	21		/* Create PLT entry */
#تعریف_کن R_68K_RELATIVE	22		/* Adjust by program base */
#تعریف_کن R_68K_TLS_GD32      25          /* 32 bit GOT offset for GD */
#تعریف_کن R_68K_TLS_GD16      26          /* 16 bit GOT offset for GD */
#تعریف_کن R_68K_TLS_GD8       27          /* 8 bit GOT offset for GD */
#تعریف_کن R_68K_TLS_LDM32     28          /* 32 bit GOT offset for LDM */
#تعریف_کن R_68K_TLS_LDM16     29          /* 16 bit GOT offset for LDM */
#تعریف_کن R_68K_TLS_LDM8      30          /* 8 bit GOT offset for LDM */
#تعریف_کن R_68K_TLS_LDO32     31          /* 32 bit module-relative offset */
#تعریف_کن R_68K_TLS_LDO16     32          /* 16 bit module-relative offset */
#تعریف_کن R_68K_TLS_LDO8      33          /* 8 bit module-relative offset */
#تعریف_کن R_68K_TLS_IE32      34          /* 32 bit GOT offset for IE */
#تعریف_کن R_68K_TLS_IE16      35          /* 16 bit GOT offset for IE */
#تعریف_کن R_68K_TLS_IE8       36          /* 8 bit GOT offset for IE */
#تعریف_کن R_68K_TLS_LE32      37          /* 32 bit offset relative to
					   static TLS block */
#تعریف_کن R_68K_TLS_LE16      38          /* 16 bit offset relative to
					   static TLS block */
#تعریف_کن R_68K_TLS_LE8       39          /* 8 bit offset relative to
					   static TLS block */
#تعریف_کن R_68K_TLS_DTPMOD32  40          /* 32 bit module number */
#تعریف_کن R_68K_TLS_DTPREL32  41          /* 32 bit module-relative offset */
#تعریف_کن R_68K_TLS_TPREL32   42          /* 32 bit TP-relative offset */
/* Keep this the last entry.  */
#تعریف_کن R_68_K_رقم	43

/* Intel 80386 specific definitions.  */

/* i386 relocs.  */

#تعریف_کن R_386_NONE	   0		/* No reloc */
#تعریف_کن R_386_32	   1		/* Direct 32 bit  */
#تعریف_کن R_386_PC32	   2		/* PC relative 32 bit */
#تعریف_کن R_386_GOT32	   3		/* 32 bit GOT entry */
#تعریف_کن R_386_PLT32	   4		/* 32 bit PLT address */
#تعریف_کن R_386_COPY	   5		/* Copy symbol at runtime */
#تعریف_کن R_386_GLOB_DAT	   6		/* Create GOT entry */
#تعریف_کن R_386_JMP_جایگاه	   7		/* Create PLT entry */
#تعریف_کن R_386_RELATIVE	   8		/* Adjust by program base */
#تعریف_کن R_386_GOTOFF	   9		/* 32 bit offset to GOT */
#تعریف_کن R_386_GOTPC	   10		/* 32 bit PC relative offset to GOT */
#تعریف_کن R_386_32PLT	   11
#تعریف_کن R_386_TLS_TPOFF	   14		/* Offset in static TLS block */
#تعریف_کن R_386_TLS_IE	   15		/* Address of GOT entry for static TLS
					   block offset */
#تعریف_کن R_386_TLS_GOTIE	   16		/* GOT entry for static TLS block
جابه_جایی*/
#تعریف_کن R_386_TLS_LE	   17		/* Offset relative to static TLS
بلوک*/
#تعریف_کن R_386_TLS_GD	   18		/* Direct 32 bit for GNU version of
					   general dynamic thread local data */
#تعریف_کن R_386_TLS_LDM	   19		/* Direct 32 bit for GNU version of
					   local dynamic thread local data
					   in LE code */
#تعریف_کن R_386_16	   20
#تعریف_کن R_386_PC16	   21
#تعریف_کن R_386_8		   22
#تعریف_کن R_386_PC8	   23
#تعریف_کن R_386_TLS_GD_32	   24		/* Direct 32 bit for general dynamic
					   thread local data */
#تعریف_کن R_386_TLS_GD_افزودن  25		/* Tag for pushl in GD TLS code */
#تعریف_کن R_386_TLS_GD_CALL  26		/* Relocation for call to
					   __tls_get_addr() */
#تعریف_کن R_386_TLS_GD_برداشت   27		/* Tag for popl in GD TLS code */
#تعریف_کن R_386_TLS_LDM_32   28		/* Direct 32 bit for local dynamic
					   thread local data in LE code */
#تعریف_کن R_386_TLS_LDM_افزودن 29		/* Tag for pushl in LDM TLS code */
#تعریف_کن R_386_TLS_LDM_CALL 30		/* Relocation for call to
					   __tls_get_addr() in LDM code */
#تعریف_کن R_386_TLS_LDM_برداشت  31		/* Tag for popl in LDM TLS code */
#تعریف_کن R_386_TLS_LDO_32   32		/* Offset relative to TLS block */
#تعریف_کن R_386_TLS_IE_32	   33		/* GOT entry for negated static TLS
					   block offset */
#تعریف_کن R_386_TLS_LE_32	   34		/* Negated offset relative to static
					   TLS block */
#تعریف_کن R_386_TLS_DTPMOD32 35		/* ID of module containing symbol */
#تعریف_کن R_386_TLS_DTPOFF32 36		/* Offset in TLS block */
#تعریف_کن R_386_TLS_TPOFF32  37		/* Negated offset in static TLS block */
/* 38? */
#تعریف_کن R_386_TLS_GOTDESC  39		/* GOT offset for TLS descriptor.  */
#تعریف_کن R_386_TLS_DESC_CALL 40		/* Marker of call through TLS
					   descriptor for
					   relaxation.  */
#تعریف_کن R_386_TLS_DESC     41		/* TLS descriptor containing
					   pointer to code and to
					   argument, returning the TLS
					   offset for the symbol.  */
#تعریف_کن R_386_IRELATIVE	   42		/* Adjust indirectly by program base */
#تعریف_کن R_386_GOT32X       43		/* 32 bit GOT entry, relaxable */
/* Keep this the last entry.  */
#تعریف_کن R_386_رقم	   44

/* SUN SPARC specific definitions.  */

/* Legal values for ST_TYPE subfield of st_info (symbol type).  */

#تعریف_کن STT_SPARC_ثبات	13	/* Global register reserved to app. */

/* Values for Elf64_Ehdr.e_flags.  */

#تعریف_کن EF_SPARCV9_MM		3
#تعریف_کن EF_SPARCV9_TSO		0
#تعریف_کن EF_SPARCV9_PSO		1
#تعریف_کن EF_SPARCV9_RMO		2
#تعریف_کن EF_SPARC_LEDATA		0x800000 /* little endian data */
#تعریف_کن EF_SPARC_EXT_ماسک	0xFFFF00
#تعریف_کن EF_SPARC_32PLUS		0x000100 /* generic V8+ features */
#تعریف_کن EF_SPARC_SUN_US1	0x000200 /* Sun UltraSPARC1 extensions */
#تعریف_کن EF_SPARC_HAL_R1		0x000400 /* HAL R1 extensions */
#تعریف_کن EF_SPARC_SUN_US3	0x000800 /* Sun UltraSPARCIII extensions */

/* SPARC relocs.  */

#تعریف_کن R_SPARC_NONE		0	/* No reloc */
#تعریف_کن R_SPARC_8		1	/* Direct 8 bit */
#تعریف_کن R_SPARC_16		2	/* Direct 16 bit */
#تعریف_کن R_SPARC_32		3	/* Direct 32 bit */
#تعریف_کن R_SPARC_DISP8		4	/* PC relative 8 bit */
#تعریف_کن R_SPARC_DISP16		5	/* PC relative 16 bit */
#تعریف_کن R_SPARC_DISP32		6	/* PC relative 32 bit */
#تعریف_کن R_SPARC_WDISP30		7	/* PC relative 30 bit shifted */
#تعریف_کن R_SPARC_WDISP22		8	/* PC relative 22 bit shifted */
#تعریف_کن R_SPARC_HI22		9	/* High 22 bit */
#تعریف_کن R_SPARC_22		10	/* Direct 22 bit */
#تعریف_کن R_SPARC_13		11	/* Direct 13 bit */
#تعریف_کن R_SPARC_LO10		12	/* Truncated 10 bit */
#تعریف_کن R_SPARC_GOT10		13	/* Truncated 10 bit GOT entry */
#تعریف_کن R_SPARC_GOT13		14	/* 13 bit GOT entry */
#تعریف_کن R_SPARC_GOT22		15	/* 22 bit GOT entry shifted */
#تعریف_کن R_SPARC_PC10		16	/* PC relative 10 bit truncated */
#تعریف_کن R_SPARC_PC22		17	/* PC relative 22 bit shifted */
#تعریف_کن R_SPARC_WPLT30		18	/* 30 bit PC relative PLT address */
#تعریف_کن R_SPARC_COPY		19	/* Copy symbol at runtime */
#تعریف_کن R_SPARC_GLOB_DAT	20	/* Create GOT entry */
#تعریف_کن R_SPARC_JMP_جایگاه	21	/* Create PLT entry */
#تعریف_کن R_SPARC_RELATIVE	22	/* Adjust by program base */
#تعریف_کن R_SPARC_UA32		23	/* Direct 32 bit unaligned */

/* Additional Sparc64 relocs.  */

#تعریف_کن R_SPARC_PLT32		24	/* Direct 32 bit ref to PLT entry */
#تعریف_کن R_SPARC_HIPLT22		25	/* High 22 bit PLT entry */
#تعریف_کن R_SPARC_LOPLT10		26	/* Truncated 10 bit PLT entry */
#تعریف_کن R_SPARC_PCPLT32		27	/* PC rel 32 bit ref to PLT entry */
#تعریف_کن R_SPARC_PCPLT22		28	/* PC rel high 22 bit PLT entry */
#تعریف_کن R_SPARC_PCPLT10		29	/* PC rel trunc 10 bit PLT entry */
#تعریف_کن R_SPARC_10		30	/* Direct 10 bit */
#تعریف_کن R_SPARC_11		31	/* Direct 11 bit */
#تعریف_کن R_SPARC_64		32	/* Direct 64 bit */
#تعریف_کن R_SPARC_OLO10		33	/* 10bit with secondary 13bit addend */
#تعریف_کن R_SPARC_HH22		34	/* Top 22 bits of direct 64 bit */
#تعریف_کن R_SPARC_HM10		35	/* High middle 10 bits of ... */
#تعریف_کن R_SPARC_LM22		36	/* Low middle 22 bits of ... */
#تعریف_کن R_SPARC_PC_HH22		37	/* Top 22 bits of pc rel 64 bit */
#تعریف_کن R_SPARC_PC_HM10		38	/* High middle 10 bit of ... */
#تعریف_کن R_SPARC_PC_LM22		39	/* Low middle 22 bits of ... */
#تعریف_کن R_SPARC_WDISP16		40	/* PC relative 16 bit shifted */
#تعریف_کن R_SPARC_WDISP19		41	/* PC relative 19 bit shifted */
#تعریف_کن R_SPARC_GLOB_JMP	42	/* was part of v9 ABI but was removed */
#تعریف_کن R_SPARC_7		43	/* Direct 7 bit */
#تعریف_کن R_SPARC_5		44	/* Direct 5 bit */
#تعریف_کن R_SPARC_6		45	/* Direct 6 bit */
#تعریف_کن R_SPARC_DISP64		46	/* PC relative 64 bit */
#تعریف_کن R_SPARC_PLT64		47	/* Direct 64 bit ref to PLT entry */
#تعریف_کن R_SPARC_HIX22		48	/* High 22 bit complemented */
#تعریف_کن R_SPARC_LOX10		49	/* Truncated 11 bit complemented */
#تعریف_کن R_SPARC_H44		50	/* Direct high 12 of 44 bit */
#تعریف_کن R_SPARC_M44		51	/* Direct mid 22 of 44 bit */
#تعریف_کن R_SPARC_L44		52	/* Direct low 10 of 44 bit */
#تعریف_کن R_SPARC_ثبات	53	/* Global register usage */
#تعریف_کن R_SPARC_UA64		54	/* Direct 64 bit unaligned */
#تعریف_کن R_SPARC_UA16		55	/* Direct 16 bit unaligned */
#تعریف_کن R_SPARC_TLS_GD_HI22	56
#تعریف_کن R_SPARC_TLS_GD_LO10	57
#تعریف_کن R_SPARC_TLS_GD_جمع_کن	58
#تعریف_کن R_SPARC_TLS_GD_CALL	59
#تعریف_کن R_SPARC_TLS_LDM_HI22	60
#تعریف_کن R_SPARC_TLS_LDM_LO10	61
#تعریف_کن R_SPARC_TLS_LDM_جمع_کن	62
#تعریف_کن R_SPARC_TLS_LDM_CALL	63
#تعریف_کن R_SPARC_TLS_LDO_HIX22	64
#تعریف_کن R_SPARC_TLS_LDO_LOX10	65
#تعریف_کن R_SPARC_TLS_LDO_جمع_کن	66
#تعریف_کن R_SPARC_TLS_IE_HI22	67
#تعریف_کن R_SPARC_TLS_IE_LO10	68
#تعریف_کن R_SPARC_TLS_IE_LD	69
#تعریف_کن R_SPARC_TLS_IE_LDX	70
#تعریف_کن R_SPARC_TLS_IE_جمع_کن	71
#تعریف_کن R_SPARC_TLS_LE_HIX22	72
#تعریف_کن R_SPARC_TLS_LE_LOX10	73
#تعریف_کن R_SPARC_TLS_DTPMOD32	74
#تعریف_کن R_SPARC_TLS_DTPMOD64	75
#تعریف_کن R_SPARC_TLS_DTPOFF32	76
#تعریف_کن R_SPARC_TLS_DTPOFF64	77
#تعریف_کن R_SPARC_TLS_TPOFF32	78
#تعریف_کن R_SPARC_TLS_TPOFF64	79
#تعریف_کن R_SPARC_GOTDATA_HIX22	80
#تعریف_کن R_SPARC_GOTDATA_LOX10	81
#تعریف_کن R_SPARC_GOTDATA_OP_HIX22	82
#تعریف_کن R_SPARC_GOTDATA_OP_LOX10	83
#تعریف_کن R_SPARC_GOTDATA_OP	84
#تعریف_کن R_SPARC_H34		85
#تعریف_کن R_SPARC_SIZE32		86
#تعریف_کن R_SPARC_SIZE64		87
#تعریف_کن R_SPARC_WDISP10		88
#تعریف_کن R_SPARC_JMP_IREL	248
#تعریف_کن R_SPARC_IRELATIVE	249
#تعریف_کن R_SPARC_GNU_VTINHERIT	250
#تعریف_کن R_SPARC_GNU_VTENTRY	251
#تعریف_کن R_SPARC_REV32		252
/* Keep this the last entry.  */
#تعریف_کن R_SPARC_رقم		253

/* For Sparc64, legal values for d_tag of Elf64_Dyn.  */

#تعریف_کن DT_SPARC_ثبات 0x70000001
#تعریف_کن DT_SPARC_رقم	2

/* MIPS R3000 specific definitions.  */

/* Legal values for e_flags field of Elf32_Ehdr.  */

#تعریف_کن EF_MIPS_NOREORDER   1		/* A .noreorder directive was used */
#تعریف_کن EF_MIPS_PIC	    2		/* Contains PIC code */
#تعریف_کن EF_MIPS_CPIC	    4		/* Uses PIC calling sequence */
#تعریف_کن EF_MIPS_XGOT	    8
#تعریف_کن EF_MIPS_64_بیت_WHIRL 16
#تعریف_کن EF_MIPS_ABI2	    32
#تعریف_کن EF_MIPS_ABI_ON32    64
#تعریف_کن EF_MIPS_ARCH	    0xf0000000	/* MIPS architecture level */

/* Legal values for MIPS architecture level.  */

#تعریف_کن EF_MIPS_ARCH_1	    0x00000000	/* -mips1 code.  */
#تعریف_کن EF_MIPS_ARCH_2	    0x10000000	/* -mips2 code.  */
#تعریف_کن EF_MIPS_ARCH_3	    0x20000000	/* -mips3 code.  */
#تعریف_کن EF_MIPS_ARCH_4	    0x30000000	/* -mips4 code.  */
#تعریف_کن EF_MIPS_ARCH_5	    0x40000000	/* -mips5 code.  */
#تعریف_کن EF_MIPS_ARCH_32	    0x60000000	/* MIPS32 code.  */
#تعریف_کن EF_MIPS_ARCH_64	    0x70000000	/* MIPS64 code.  */

/* The following are non-official names and should not be used.  */

#تعریف_کن E_MIPS_ARCH_1	  0x00000000	/* -mips1 code.  */
#تعریف_کن E_MIPS_ARCH_2	  0x10000000	/* -mips2 code.  */
#تعریف_کن E_MIPS_ARCH_3	  0x20000000	/* -mips3 code.  */
#تعریف_کن E_MIPS_ARCH_4	  0x30000000	/* -mips4 code.  */
#تعریف_کن E_MIPS_ARCH_5	  0x40000000	/* -mips5 code.  */
#تعریف_کن E_MIPS_ARCH_32	  0x60000000	/* MIPS32 code.  */
#تعریف_کن E_MIPS_ARCH_64	  0x70000000	/* MIPS64 code.  */

/* Special section indices.  */

#تعریف_کن SHN_MIPS_ACOMMON    0xff00	/* Allocated common symbols */
#تعریف_کن SHN_MIPS_متن	    0xff01	/* Allocated test symbols.  */
#تعریف_کن SHN_MIPS_داده	    0xff02	/* Allocated data symbols.  */
#تعریف_کن SHN_MIPS_SCOMMON    0xff03	/* Small common symbols */
#تعریف_کن SHN_MIPS_SUNDEFINED 0xff04	/* Small undefined symbols */

/* Legal values for sh_type field of Elf32_Shdr.  */

#تعریف_کن SHT_MIPS_LIBLIST       0x70000000 /* Shared objects used in link */
#تعریف_کن SHT_MIPS_MSYM	       0x70000001
#تعریف_کن SHT_MIPS_CONFLICT      0x70000002 /* Conflicting symbols */
#تعریف_کن SHT_MIPS_GPTAB	       0x70000003 /* Global data area sizes */
#تعریف_کن SHT_MIPS_UCODE	       0x70000004 /* Reserved for SGI/MIPS compilers */
#تعریف_کن SHT_MIPS_DEBUG	       0x70000005 /* MIPS ECOFF debugging information*/
#تعریف_کن SHT_MIPS_REGINFO       0x70000006 /* Register usage information */
#تعریف_کن SHT_MIPS_PACKAGE       0x70000007
#تعریف_کن SHT_MIPS_PACKSYM       0x70000008
#تعریف_کن SHT_MIPS_RELD	       0x70000009
#تعریف_کن SHT_MIPS_IFACE         0x7000000b
#تعریف_کن SHT_MIPS_CONTENT       0x7000000c
#تعریف_کن SHT_MIPS_OPTIONS       0x7000000d /* Miscellaneous options.  */
#تعریف_کن SHT_MIPS_SHDR	       0x70000010
#تعریف_کن SHT_MIPS_FDESC	       0x70000011
#تعریف_کن SHT_MIPS_EXTSYM	       0x70000012
#تعریف_کن SHT_MIPS_DENSE	       0x70000013
#تعریف_کن SHT_MIPS_PDESC	       0x70000014
#تعریف_کن SHT_MIPS_LOCSYM	       0x70000015
#تعریف_کن SHT_MIPS_AUXSYM	       0x70000016
#تعریف_کن SHT_MIPS_OPTSYM	       0x70000017
#تعریف_کن SHT_MIPS_LOCSTR	       0x70000018
#تعریف_کن SHT_MIPS_سطر	       0x70000019
#تعریف_کن SHT_MIPS_RFDESC	       0x7000001a
#تعریف_کن SHT_MIPS_DELTASYM      0x7000001b
#تعریف_کن SHT_MIPS_DELTAINST     0x7000001c
#تعریف_کن SHT_MIPS_DELTACLASS    0x7000001d
#تعریف_کن SHT_MIPS_DWARF         0x7000001e /* DWARF debugging information.  */
#تعریف_کن SHT_MIPS_DELTADECL     0x7000001f
#تعریف_کن SHT_MIPS_نماد_LIB    0x70000020
#تعریف_کن SHT_MIPS_EVENTS	       0x70000021 /* Event section.  */
#تعریف_کن SHT_MIPS_TRANSLATE     0x70000022
#تعریف_کن SHT_MIPS_PIXIE	       0x70000023
#تعریف_کن SHT_MIPS_XLATE	       0x70000024
#تعریف_کن SHT_MIPS_XLATE_DEBUG   0x70000025
#تعریف_کن SHT_MIPS_WHIRL	       0x70000026
#تعریف_کن SHT_MIPS_EH_REGION     0x70000027
#تعریف_کن SHT_MIPS_XLATE_OLD     0x70000028
#تعریف_کن SHT_MIPS_PDR_EXCEPTION 0x70000029

/* Legal values for sh_flags field of Elf32_Shdr.  */

#تعریف_کن SHF_MIPS_GPREL	 0x10000000	/* Must be part of global data area */
#تعریف_کن SHF_MIPS_ادغام	 0x20000000
#تعریف_کن SHF_MIPS_ADDR	 0x40000000
#تعریف_کن SHF_MIPS_رشتهها 0x80000000
#تعریف_کن SHF_MIPS_NOSTRIP 0x08000000
#تعریف_کن SHF_MIPS_LOCAL	 0x04000000
#تعریف_کن SHF_MIPS_نامها	 0x02000000
#تعریف_کن SHF_MIPS_NODUPE	 0x01000000


/* Symbol tables.  */

/* MIPS specific values for `st_other'.  */
#تعریف_کن STO_MIPS_DEFAULT		0x0
#تعریف_کن STO_MIPS_داخلی		0x1
#تعریف_کن STO_MIPS_HIDDEN			0x2
#تعریف_کن STO_MIPS_PROTECTED		0x3
#تعریف_کن STO_MIPS_PLT			0x8
#تعریف_کن STO_MIPS_SC_ALIGN_استفادهنشده	0xff

/* MIPS specific values for `st_info'.  */
#تعریف_کن STB_MIPS_تقسیم_COMMON		13

/* Entries found in sections of type SHT_MIPS_GPTAB.  */

تعريفنوع اتحاد
{
  بنية
    {
      Elf32_کلمه gt_current_g_مقدار;	/* -G value used for compilation */
      Elf32_کلمه gt_استفادهنشده;		/* Not used */
    } gt_سرآیند;			/* First entry in section */
  بنية
    {
      Elf32_کلمه gt_g_مقدار;		/* If this value were used for -G */
      Elf32_کلمه gt_بایتها;		/* This many bytes would be used */
    } gt_مدخل;				/* Subsequent entries in section */
} Elf32_gptab;

/* Entry found in sections of type SHT_MIPS_REGINFO.  */

تعريفنوع بنية
{
  Elf32_کلمه	ri_gprmask;		/* General registers used */
  Elf32_کلمه	ri_cprmask[4];		/* Coprocessor registers used */
  Elf32_Sword	ri_gp_مقدار;		/* $gp register value */
} Elf32_RegInfo;

/* Entries found in sections of type SHT_MIPS_OPTIONS.  */

تعريفنوع بنية
{
  بیعلامت حرف نوع;		/* Determines interpretation of the
				   variable part of descriptor.  */
  بیعلامت حرف اندازه;		/* Size of descriptor, including header.  */
  Elf32_Section section;	/* Section header index of section affected,
				   0 for global options.  */
  Elf32_کلمه info;		/* Kind-specific information.  */
} Elf_Options;

/* Values for `kind' field in Elf_Options.  */

#تعریف_کن ODK_NULL	0	/* Undefined.  */
#تعریف_کن ODK_REGINFO	1	/* Register usage information.  */
#تعریف_کن ODK_EXCEPTIONS	2	/* Exception processing options.  */
#تعریف_کن ODK_PAD		3	/* Section padding options.  */
#تعریف_کن ODK_HWPATCH	4	/* Hardware workarounds performed */
#تعریف_کن ODK_FILL	5	/* record the fill value used by the linker. */
#تعریف_کن ODK_برچسبها	6	/* reserve space for desktop tools to write. */
#تعریف_کن ODK_HWAND	7	/* HW workarounds.  'AND' bits when merging. */
#تعریف_کن ODK_HWOR	8	/* HW workarounds.  'OR' bits when merging.  */

/* Values for `info' in Elf_Options for ODK_EXCEPTIONS entries.  */

#تعریف_کن OEX_FPU_MIN	0x1f	/* FPE's which MUST be enabled.  */
#تعریف_کن OEX_FPU_MAX	0x1f00	/* FPE's which MAY be enabled.  */
#تعریف_کن OEX_PAGE0	0x10000	/* page zero must be mapped.  */
#تعریف_کن OEX_SMM		0x20000	/* Force sequential memory mode?  */
#تعریف_کن OEX_FPDBUG	0x40000	/* Force floating point debug mode?  */
#تعریف_کن OEX_PRECISEFP	OEX_FPDBUG
#تعریف_کن OEX_DISMISS	0x80000	/* Dismiss invalid address faults?  */

#تعریف_کن OEX_FPU_INVAL	0x10
#تعریف_کن OEX_FPU_DIV0	0x08
#تعریف_کن OEX_FPU_OFLO	0x04
#تعریف_کن OEX_FPU_UFLO	0x02
#تعریف_کن OEX_FPU_INEX	0x01

/* Masks for `info' in Elf_Options for an ODK_HWPATCH entry.  */

#تعریف_کن OHW_R4KEOP	0x1	/* R4000 end-of-page patch.  */
#تعریف_کن OHW_R8KPFETCH	0x2	/* may need R8000 prefetch patch.  */
#تعریف_کن OHW_R5KEOP	0x4	/* R5000 end-of-page patch.  */
#تعریف_کن OHW_R5KCVTL	0x8	/* R5000 cvt.[ds].l bug.  clean=1.  */

#تعریف_کن OPAD_پیشوند	0x1
#تعریف_کن OPAD_POSTFIX	0x2
#تعریف_کن OPAD_نماد	0x4

/* Entry found in `.options' section.  */

تعريفنوع بنية
{
  Elf32_کلمه hwp_flags1;	/* Extra flags.  */
  Elf32_کلمه hwp_flags2;	/* Extra flags.  */
} Elf_Options_Hw;

/* Masks for `info' in ElfOptions for ODK_HWAND and ODK_HWOR entries.  */

#تعریف_کن OHWA0_R4KEOP_CHECKED	0x00000001
#تعریف_کن OHWA1_R4KEOP_CLEAN	0x00000002

/* MIPS relocs.  */

#تعریف_کن R_MIPS_NONE		0	/* No reloc */
#تعریف_کن R_MIPS_16		1	/* Direct 16 bit */
#تعریف_کن R_MIPS_32		2	/* Direct 32 bit */
#تعریف_کن R_MIPS_REL32		3	/* PC relative 32 bit */
#تعریف_کن R_MIPS_26		4	/* Direct 26 bit shifted */
#تعریف_کن R_MIPS_HI16		5	/* High 16 bit */
#تعریف_کن R_MIPS_LO16		6	/* Low 16 bit */
#تعریف_کن R_MIPS_GPREL16		7	/* GP relative 16 bit */
#تعریف_کن R_MIPS_LITERAL		8	/* 16 bit literal entry */
#تعریف_کن R_MIPS_GOT16		9	/* 16 bit GOT entry */
#تعریف_کن R_MIPS_PC16		10	/* PC relative 16 bit */
#تعریف_کن R_MIPS_CALL16		11	/* 16 bit GOT entry for function */
#تعریف_کن R_MIPS_GPREL32		12	/* GP relative 32 bit */

#تعریف_کن R_MIPS_SHIFT5		16
#تعریف_کن R_MIPS_SHIFT6		17
#تعریف_کن R_MIPS_64		18
#تعریف_کن R_MIPS_GOT_DISP		19
#تعریف_کن R_MIPS_GOT_صفحه		20
#تعریف_کن R_MIPS_GOT_OFST		21
#تعریف_کن R_MIPS_GOT_HI16		22
#تعریف_کن R_MIPS_GOT_LO16		23
#تعریف_کن R_MIPS_SUB		24
#تعریف_کن R_MIPS_درج_A		25
#تعریف_کن R_MIPS_درج_B		26
#تعریف_کن R_MIPS_DELETE		27
#تعریف_کن R_MIPS_HIGHER		28
#تعریف_کن R_MIPS_HIGHEST		29
#تعریف_کن R_MIPS_CALL_HI16	30
#تعریف_کن R_MIPS_CALL_LO16	31
#تعریف_کن R_MIPS_SCN_DISP		32
#تعریف_کن R_MIPS_REL16		33
#تعریف_کن R_MIPS_جمع_کن_فوری	34
#تعریف_کن R_MIPS_PJUMP		35
#تعریف_کن R_MIPS_RELGOT		36
#تعریف_کن R_MIPS_JALR		37
#تعریف_کن R_MIPS_TLS_DTPMOD32	38	/* Module number 32 bit */
#تعریف_کن R_MIPS_TLS_DTPREL32	39	/* Module-relative offset 32 bit */
#تعریف_کن R_MIPS_TLS_DTPMOD64	40	/* Module number 64 bit */
#تعریف_کن R_MIPS_TLS_DTPREL64	41	/* Module-relative offset 64 bit */
#تعریف_کن R_MIPS_TLS_GD		42	/* 16 bit GOT offset for GD */
#تعریف_کن R_MIPS_TLS_LDM		43	/* 16 bit GOT offset for LDM */
#تعریف_کن R_MIPS_TLS_DTPREL_HI16	44	/* Module-relative offset, high 16 bits */
#تعریف_کن R_MIPS_TLS_DTPREL_LO16	45	/* Module-relative offset, low 16 bits */
#تعریف_کن R_MIPS_TLS_GOTTPREL	46	/* 16 bit GOT offset for IE */
#تعریف_کن R_MIPS_TLS_TPREL32	47	/* TP-relative offset, 32 bit */
#تعریف_کن R_MIPS_TLS_TPREL64	48	/* TP-relative offset, 64 bit */
#تعریف_کن R_MIPS_TLS_TPREL_HI16	49	/* TP-relative offset, high 16 bits */
#تعریف_کن R_MIPS_TLS_TPREL_LO16	50	/* TP-relative offset, low 16 bits */
#تعریف_کن R_MIPS_GLOB_DAT		51
#تعریف_کن R_MIPS_COPY		126
#تعریف_کن R_MIPS_JUMP_جایگاه        127
/* Keep this the last entry.  */
#تعریف_کن R_MIPS_رقم		128

/* Legal values for p_type field of Elf32_Phdr.  */

#تعریف_کن PT_MIPS_REGINFO	0x70000000	/* Register usage information */
#تعریف_کن PT_MIPS_RTPROC  0x70000001	/* Runtime procedure table. */
#تعریف_کن PT_MIPS_OPTIONS 0x70000002

/* Special program header types.  */

#تعریف_کن PF_MIPS_LOCAL	0x10000000

/* Legal values for d_tag field of Elf32_Dyn.  */

#تعریف_کن DT_MIPS_RLD_نسخه  0x70000001	/* Runtime linker interface version */
#تعریف_کن DT_MIPS_زمان_STAMP   0x70000002	/* Timestamp */
#تعریف_کن DT_MIPS_ICHECKSUM    0x70000003	/* Checksum */
#تعریف_کن DT_MIPS_IVERSION     0x70000004	/* Version string (string tbl index) */
#تعریف_کن DT_MIPS_FLAGS	     0x70000005	/* Flags */
#تعریف_کن DT_MIPS_پایه_آدرس 0x70000006	/* Base address */
#تعریف_کن DT_MIPS_MSYM	     0x70000007
#تعریف_کن DT_MIPS_CONFLICT     0x70000008	/* Address of CONFLICT section */
#تعریف_کن DT_MIPS_LIBLIST	     0x70000009	/* Address of LIBLIST section */
#تعریف_کن DT_MIPS_LOCAL_GOTNO  0x7000000a	/* Number of local GOT entries */
#تعریف_کن DT_MIPS_CONFLICTNO   0x7000000b	/* Number of CONFLICT entries */
#تعریف_کن DT_MIPS_LIBLISTNO    0x70000010	/* Number of LIBLIST entries */
#تعریف_کن DT_MIPS_SYMTABNO     0x70000011	/* Number of DYNSYM entries */
#تعریف_کن DT_MIPS_UNREFEXTNO   0x70000012	/* First external DYNSYM */
#تعریف_کن DT_MIPS_GOTSYM	     0x70000013	/* First GOT entry in DYNSYM */
#تعریف_کن DT_MIPS_HIPAGENO     0x70000014	/* Number of GOT page table entries */
#تعریف_کن DT_MIPS_RLD_MAP	     0x70000016	/* Address of run time loader map.  */
#تعریف_کن DT_MIPS_DELTA_CLASS  0x70000017	/* Delta C++ class definition.  */
#تعریف_کن DT_MIPS_DELTA_CLASS_NO    0x70000018 /* Number of entries in
						DT_MIPS_DELTA_CLASS.  */
#تعریف_کن DT_MIPS_DELTA_INSTANCE    0x70000019 /* Delta C++ class instances.  */
#تعریف_کن DT_MIPS_DELTA_INSTANCE_NO 0x7000001a /* Number of entries in
						DT_MIPS_DELTA_INSTANCE.  */
#تعریف_کن DT_MIPS_DELTA_RELOC  0x7000001b /* Delta relocations.  */
#تعریف_کن DT_MIPS_DELTA_RELOC_NO 0x7000001c /* Number of entries in
					     DT_MIPS_DELTA_RELOC.  */
#تعریف_کن DT_MIPS_DELTA_SYM    0x7000001d /* Delta symbols that Delta
					   relocations refer to.  */
#تعریف_کن DT_MIPS_DELTA_SYM_NO 0x7000001e /* Number of entries in
					   DT_MIPS_DELTA_SYM.  */
#تعریف_کن DT_MIPS_DELTA_CLASSSYM 0x70000020 /* Delta symbols that hold the
					     class declaration.  */
#تعریف_کن DT_MIPS_DELTA_CLASSSYM_NO 0x70000021 /* Number of entries in
						DT_MIPS_DELTA_CLASSSYM.  */
#تعریف_کن DT_MIPS_CXX_FLAGS    0x70000022 /* Flags indicating for C++ flavor.  */
#تعریف_کن DT_MIPS_PIXIE_INIT   0x70000023
#تعریف_کن DT_MIPS_نماد_LIB   0x70000024
#تعریف_کن DT_MIPS_LOCALPAGE_GOTIDX 0x70000025
#تعریف_کن DT_MIPS_LOCAL_GOTIDX 0x70000026
#تعریف_کن DT_MIPS_HIDDEN_GOTIDX 0x70000027
#تعریف_کن DT_MIPS_PROTECTED_GOTIDX 0x70000028
#تعریف_کن DT_MIPS_OPTIONS	     0x70000029 /* Address of .options.  */
#تعریف_کن DT_MIPS_INTERFACE    0x7000002a /* Address of .interface.  */
#تعریف_کن DT_MIPS_DYNSTR_ALIGN 0x7000002b
#تعریف_کن DT_MIPS_INTERFACE_اندازه 0x7000002c /* Size of the .interface section. */
#تعریف_کن DT_MIPS_RLD_متن_RESOLVE_ADDR 0x7000002d /* Address of rld_text_rsolve
						    function stored in GOT.  */
#تعریف_کن DT_MIPS_PERF_SUFFIX  0x7000002e /* Default suffix of dso to be added
					   by rld on dlopen() calls.  */
#تعریف_کن DT_MIPS_COMPACT_اندازه 0x7000002f /* (O32)Size of compact rel section. */
#تعریف_کن DT_MIPS_GP_مقدار     0x70000030 /* GP value for aux GOTs.  */
#تعریف_کن DT_MIPS_AUX_DYNAMIC  0x70000031 /* Address of aux .dynamic.  */
/* The address of .got.plt in an executable using the new non-PIC ABI.  */
#تعریف_کن DT_MIPS_PLTGOT	     0x70000032
/* The base of the PLT in an executable using the new non-PIC ABI if that
   PLT is writable.  For a non-writable PLT, this is omitted or has a zero
   value.  */
#تعریف_کن DT_MIPS_RWPLT        0x70000034
#تعریف_کن DT_MIPS_رقم	     0x35

/* Legal values for DT_MIPS_FLAGS Elf32_Dyn entry.  */

#تعریف_کن RHF_NONE		   0		/* No flags */
#تعریف_کن RHF_QUICKSTART		   (1 << 0)	/* Use quickstart */
#تعریف_کن RHF_NOTPOT		   (1 << 1)	/* Hash size not power of 2 */
#تعریف_کن RHF_NO_LIBRARY_REPLACEMENT (1 << 2)	/* Ignore LD_LIBRARY_PATH */
#تعریف_کن RHF_NO_MOVE		   (1 << 3)
#تعریف_کن RHF_SGI_ONLY		   (1 << 4)
#تعریف_کن RHF_GUARANTEE_INIT	   (1 << 5)
#تعریف_کن RHF_DELTA_C_PLUS_PLUS	   (1 << 6)
#تعریف_کن RHF_GUARANTEE_شروع_INIT   (1 << 7)
#تعریف_کن RHF_PIXIE		   (1 << 8)
#تعریف_کن RHF_DEFAULT_DELAY_بارگیری	   (1 << 9)
#تعریف_کن RHF_REQUICKSTART	   (1 << 10)
#تعریف_کن RHF_REQUICKSTARTED	   (1 << 11)
#تعریف_کن RHF_CORD		   (1 << 12)
#تعریف_کن RHF_NO_UNRES_UNDEF	   (1 << 13)
#تعریف_کن RHF_RLD_ترتیب_امن	   (1 << 14)

/* Entries found in sections of type SHT_MIPS_LIBLIST.  */

تعريفنوع بنية
{
  Elf32_کلمه l_name;		/* Name (string table index) */
  Elf32_کلمه l_زمان_stamp;	/* Timestamp */
  Elf32_کلمه l_checksum;	/* Checksum */
  Elf32_کلمه l_نسخه;		/* Interface version */
  Elf32_کلمه l_flags;		/* Flags */
} Elf32_Lib;

تعريفنوع بنية
{
  Elf64_کلمه l_name;		/* Name (string table index) */
  Elf64_کلمه l_زمان_stamp;	/* Timestamp */
  Elf64_کلمه l_checksum;	/* Checksum */
  Elf64_کلمه l_نسخه;		/* Interface version */
  Elf64_کلمه l_flags;		/* Flags */
} Elf64_Lib;


/* Legal values for l_flags.  */

#تعریف_کن LL_NONE		  0
#تعریف_کن LL_EXACT_تطابق	  (1 << 0)	/* Require exact match */
#تعریف_کن LL_IGNORE_INT_VER (1 << 1)	/* Ignore interface version */
#تعریف_کن LL_REQUIRE_MINOR  (1 << 2)
#تعریف_کن LL_EXPORTS	  (1 << 3)
#تعریف_کن LL_DELAY_بارگیری	  (1 << 4)
#تعریف_کن LL_DELTA	  (1 << 5)

/* Entries found in sections of type SHT_MIPS_CONFLICT.  */

تعريفنوع Elf32_Addr Elf32_Conflict;


/* HPPA specific definitions.  */

/* Legal values for e_flags field of Elf32_Ehdr.  */

#تعریف_کن EF_PARISC_TRAPNIL	0x00010000 /* Trap nil pointer dereference.  */
#تعریف_کن EF_PARISC_EXT		0x00020000 /* Program uses arch. extensions. */
#تعریف_کن EF_PARISC_LSB		0x00040000 /* Program expects little endian. */
#تعریف_کن EF_PARISC_WIDE		0x00080000 /* Program expects wide mode.  */
#تعریف_کن EF_PARISC_NO_KABP	0x00100000 /* No kernel assisted branch
					      prediction.  */
#تعریف_کن EF_PARISC_LAZYSWAP	0x00400000 /* Allow lazy swapping.  */
#تعریف_کن EF_PARISC_ARCH		0x0000ffff /* Architecture version.  */

/* Defined values for `e_flags & EF_PARISC_ARCH' are:  */

#تعریف_کن EFA_PARISC_1_0		    0x020b /* PA-RISC 1.0 big-endian.  */
#تعریف_کن EFA_PARISC_1_1		    0x0210 /* PA-RISC 1.1 big-endian.  */
#تعریف_کن EFA_PARISC_2_0		    0x0214 /* PA-RISC 2.0 big-endian.  */

/* Additional section indices.  */

#تعریف_کن SHN_PARISC_ANSI_COMMON	0xff00	   /* Section for tentatively declared
					      symbols in ANSI C.  */
#تعریف_کن SHN_PARISC_HUGE_COMMON	0xff01	   /* Common blocks in huge model.  */

/* Legal values for sh_type field of Elf32_Shdr.  */

#تعریف_کن SHT_PARISC_EXT		0x70000000 /* Contains product specific ext. */
#تعریف_کن SHT_PARISC_UNWIND	0x70000001 /* Unwind information.  */
#تعریف_کن SHT_PARISC_DOC		0x70000002 /* Debug info for optimized code. */

/* Legal values for sh_flags field of Elf32_Shdr.  */

#تعریف_کن SHF_PARISC_SHORT	0x20000000 /* Section with short addressing. */
#تعریف_کن SHF_PARISC_HUGE		0x40000000 /* Section far from gp.  */
#تعریف_کن SHF_PARISC_SBP		0x80000000 /* Static branch prediction code. */

/* Legal values for ST_TYPE subfield of st_info (symbol type).  */

#تعریف_کن STT_PARISC_MILLICODE	13	/* Millicode function entry point.  */

#تعریف_کن STT_HP_OPAQUE		(STT_LOOS + 0x1)
#تعریف_کن STT_HP_STUB		(STT_LOOS + 0x2)

/* HPPA relocs.  */

#تعریف_کن R_PARISC_NONE		0	/* No reloc.  */
#تعریف_کن R_PARISC_DIR32		1	/* Direct 32-bit reference.  */
#تعریف_کن R_PARISC_DIR21L		2	/* Left 21 bits of eff. address.  */
#تعریف_کن R_PARISC_DIR17R		3	/* Right 17 bits of eff. address.  */
#تعریف_کن R_PARISC_DIR17F		4	/* 17 bits of eff. address.  */
#تعریف_کن R_PARISC_DIR14R		6	/* Right 14 bits of eff. address.  */
#تعریف_کن R_PARISC_PCREL32	9	/* 32-bit rel. address.  */
#تعریف_کن R_PARISC_PCREL21L	10	/* Left 21 bits of rel. address.  */
#تعریف_کن R_PARISC_PCREL17R	11	/* Right 17 bits of rel. address.  */
#تعریف_کن R_PARISC_PCREL17F	12	/* 17 bits of rel. address.  */
#تعریف_کن R_PARISC_PCREL14R	14	/* Right 14 bits of rel. address.  */
#تعریف_کن R_PARISC_DPREL21L	18	/* Left 21 bits of rel. address.  */
#تعریف_کن R_PARISC_DPREL14R	22	/* Right 14 bits of rel. address.  */
#تعریف_کن R_PARISC_GPREL21L	26	/* GP-relative, left 21 bits.  */
#تعریف_کن R_PARISC_GPREL14R	30	/* GP-relative, right 14 bits.  */
#تعریف_کن R_PARISC_LTOFF21L	34	/* LT-relative, left 21 bits.  */
#تعریف_کن R_PARISC_LTOFF14R	38	/* LT-relative, right 14 bits.  */
#تعریف_کن R_PARISC_SECREL32	41	/* 32 bits section rel. address.  */
#تعریف_کن R_PARISC_SEGBASE	48	/* No relocation, set segment base.  */
#تعریف_کن R_PARISC_SEGREL32	49	/* 32 bits segment rel. address.  */
#تعریف_کن R_PARISC_PLTOFF21L	50	/* PLT rel. address, left 21 bits.  */
#تعریف_کن R_PARISC_PLTOFF14R	54	/* PLT rel. address, right 14 bits.  */
#تعریف_کن R_PARISC_LTOFF_FPTR32	57	/* 32 bits LT-rel. function pointer. */
#تعریف_کن R_PARISC_LTOFF_FPTR21L	58	/* LT-rel. fct ptr, left 21 bits. */
#تعریف_کن R_PARISC_LTOFF_FPTR14R	62	/* LT-rel. fct ptr, right 14 bits. */
#تعریف_کن R_PARISC_FPTR64		64	/* 64 bits function address.  */
#تعریف_کن R_PARISC_PLABEL32	65	/* 32 bits function address.  */
#تعریف_کن R_PARISC_PLABEL21L	66	/* Left 21 bits of fdesc address.  */
#تعریف_کن R_PARISC_PLABEL14R	70	/* Right 14 bits of fdesc address.  */
#تعریف_کن R_PARISC_PCREL64	72	/* 64 bits PC-rel. address.  */
#تعریف_کن R_PARISC_PCREL22F	74	/* 22 bits PC-rel. address.  */
#تعریف_کن R_PARISC_PCREL14WR	75	/* PC-rel. address, right 14 bits.  */
#تعریف_کن R_PARISC_PCREL14DR	76	/* PC rel. address, right 14 bits.  */
#تعریف_کن R_PARISC_PCREL16F	77	/* 16 bits PC-rel. address.  */
#تعریف_کن R_PARISC_PCREL16WF	78	/* 16 bits PC-rel. address.  */
#تعریف_کن R_PARISC_PCREL16DF	79	/* 16 bits PC-rel. address.  */
#تعریف_کن R_PARISC_DIR64		80	/* 64 bits of eff. address.  */
#تعریف_کن R_PARISC_DIR14WR	83	/* 14 bits of eff. address.  */
#تعریف_کن R_PARISC_DIR14DR	84	/* 14 bits of eff. address.  */
#تعریف_کن R_PARISC_DIR16F		85	/* 16 bits of eff. address.  */
#تعریف_کن R_PARISC_DIR16WF	86	/* 16 bits of eff. address.  */
#تعریف_کن R_PARISC_DIR16DF	87	/* 16 bits of eff. address.  */
#تعریف_کن R_PARISC_GPREL64	88	/* 64 bits of GP-rel. address.  */
#تعریف_کن R_PARISC_GPREL14WR	91	/* GP-rel. address, right 14 bits.  */
#تعریف_کن R_PARISC_GPREL14DR	92	/* GP-rel. address, right 14 bits.  */
#تعریف_کن R_PARISC_GPREL16F	93	/* 16 bits GP-rel. address.  */
#تعریف_کن R_PARISC_GPREL16WF	94	/* 16 bits GP-rel. address.  */
#تعریف_کن R_PARISC_GPREL16DF	95	/* 16 bits GP-rel. address.  */
#تعریف_کن R_PARISC_LTOFF64	96	/* 64 bits LT-rel. address.  */
#تعریف_کن R_PARISC_LTOFF14WR	99	/* LT-rel. address, right 14 bits.  */
#تعریف_کن R_PARISC_LTOFF14DR	100	/* LT-rel. address, right 14 bits.  */
#تعریف_کن R_PARISC_LTOFF16F	101	/* 16 bits LT-rel. address.  */
#تعریف_کن R_PARISC_LTOFF16WF	102	/* 16 bits LT-rel. address.  */
#تعریف_کن R_PARISC_LTOFF16DF	103	/* 16 bits LT-rel. address.  */
#تعریف_کن R_PARISC_SECREL64	104	/* 64 bits section rel. address.  */
#تعریف_کن R_PARISC_SEGREL64	112	/* 64 bits segment rel. address.  */
#تعریف_کن R_PARISC_PLTOFF14WR	115	/* PLT-rel. address, right 14 bits.  */
#تعریف_کن R_PARISC_PLTOFF14DR	116	/* PLT-rel. address, right 14 bits.  */
#تعریف_کن R_PARISC_PLTOFF16F	117	/* 16 bits LT-rel. address.  */
#تعریف_کن R_PARISC_PLTOFF16WF	118	/* 16 bits PLT-rel. address.  */
#تعریف_کن R_PARISC_PLTOFF16DF	119	/* 16 bits PLT-rel. address.  */
#تعریف_کن R_PARISC_LTOFF_FPTR64	120	/* 64 bits LT-rel. function ptr.  */
#تعریف_کن R_PARISC_LTOFF_FPTR14WR	123	/* LT-rel. fct. ptr., right 14 bits. */
#تعریف_کن R_PARISC_LTOFF_FPTR14DR	124	/* LT-rel. fct. ptr., right 14 bits. */
#تعریف_کن R_PARISC_LTOFF_FPTR16F	125	/* 16 bits LT-rel. function ptr.  */
#تعریف_کن R_PARISC_LTOFF_FPTR16WF	126	/* 16 bits LT-rel. function ptr.  */
#تعریف_کن R_PARISC_LTOFF_FPTR16DF	127	/* 16 bits LT-rel. function ptr.  */
#تعریف_کن R_PARISC_LORESERVE	128
#تعریف_کن R_PARISC_COPY		128	/* Copy relocation.  */
#تعریف_کن R_PARISC_IPLT		129	/* Dynamic reloc, imported PLT */
#تعریف_کن R_PARISC_EPLT		130	/* Dynamic reloc, exported PLT */
#تعریف_کن R_PARISC_TPREL32	153	/* 32 bits TP-rel. address.  */
#تعریف_کن R_PARISC_TPREL21L	154	/* TP-rel. address, left 21 bits.  */
#تعریف_کن R_PARISC_TPREL14R	158	/* TP-rel. address, right 14 bits.  */
#تعریف_کن R_PARISC_LTOFF_TP21L	162	/* LT-TP-rel. address, left 21 bits. */
#تعریف_کن R_PARISC_LTOFF_TP14R	166	/* LT-TP-rel. address, right 14 bits.*/
#تعریف_کن R_PARISC_LTOFF_TP14F	167	/* 14 bits LT-TP-rel. address.  */
#تعریف_کن R_PARISC_TPREL64	216	/* 64 bits TP-rel. address.  */
#تعریف_کن R_PARISC_TPREL14WR	219	/* TP-rel. address, right 14 bits.  */
#تعریف_کن R_PARISC_TPREL14DR	220	/* TP-rel. address, right 14 bits.  */
#تعریف_کن R_PARISC_TPREL16F	221	/* 16 bits TP-rel. address.  */
#تعریف_کن R_PARISC_TPREL16WF	222	/* 16 bits TP-rel. address.  */
#تعریف_کن R_PARISC_TPREL16DF	223	/* 16 bits TP-rel. address.  */
#تعریف_کن R_PARISC_LTOFF_TP64	224	/* 64 bits LT-TP-rel. address.  */
#تعریف_کن R_PARISC_LTOFF_TP14WR	227	/* LT-TP-rel. address, right 14 bits.*/
#تعریف_کن R_PARISC_LTOFF_TP14DR	228	/* LT-TP-rel. address, right 14 bits.*/
#تعریف_کن R_PARISC_LTOFF_TP16F	229	/* 16 bits LT-TP-rel. address.  */
#تعریف_کن R_PARISC_LTOFF_TP16WF	230	/* 16 bits LT-TP-rel. address.  */
#تعریف_کن R_PARISC_LTOFF_TP16DF	231	/* 16 bits LT-TP-rel. address.  */
#تعریف_کن R_PARISC_GNU_VTENTRY	232
#تعریف_کن R_PARISC_GNU_VTINHERIT	233
#تعریف_کن R_PARISC_TLS_GD21L	234	/* GD 21-bit left.  */
#تعریف_کن R_PARISC_TLS_GD14R	235	/* GD 14-bit right.  */
#تعریف_کن R_PARISC_TLS_GDCALL	236	/* GD call to __t_g_a.  */
#تعریف_کن R_PARISC_TLS_LDM21L	237	/* LD module 21-bit left.  */
#تعریف_کن R_PARISC_TLS_LDM14R	238	/* LD module 14-bit right.  */
#تعریف_کن R_PARISC_TLS_LDMCALL	239	/* LD module call to __t_g_a.  */
#تعریف_کن R_PARISC_TLS_LDO21L	240	/* LD offset 21-bit left.  */
#تعریف_کن R_PARISC_TLS_LDO14R	241	/* LD offset 14-bit right.  */
#تعریف_کن R_PARISC_TLS_DTPMOD32	242	/* DTP module 32-bit.  */
#تعریف_کن R_PARISC_TLS_DTPMOD64	243	/* DTP module 64-bit.  */
#تعریف_کن R_PARISC_TLS_DTPOFF32	244	/* DTP offset 32-bit.  */
#تعریف_کن R_PARISC_TLS_DTPOFF64	245	/* DTP offset 32-bit.  */
#تعریف_کن R_PARISC_TLS_LE21L	R_PARISC_TPREL21L
#تعریف_کن R_PARISC_TLS_LE14R	R_PARISC_TPREL14R
#تعریف_کن R_PARISC_TLS_IE21L	R_PARISC_LTOFF_TP21L
#تعریف_کن R_PARISC_TLS_IE14R	R_PARISC_LTOFF_TP14R
#تعریف_کن R_PARISC_TLS_TPREL32	R_PARISC_TPREL32
#تعریف_کن R_PARISC_TLS_TPREL64	R_PARISC_TPREL64
#تعریف_کن R_PARISC_HIRESERVE	255

/* Legal values for p_type field of Elf32_Phdr/Elf64_Phdr.  */

#تعریف_کن PT_HP_TLS		(PT_LOOS + 0x0)
#تعریف_کن PT_HP_CORE_NONE		(PT_LOOS + 0x1)
#تعریف_کن PT_HP_CORE_نسخه	(PT_LOOS + 0x2)
#تعریف_کن PT_HP_CORE_KERNEL	(PT_LOOS + 0x3)
#تعریف_کن PT_HP_CORE_COMM		(PT_LOOS + 0x4)
#تعریف_کن PT_HP_CORE_PROC		(PT_LOOS + 0x5)
#تعریف_کن PT_HP_CORE_LOADABLE	(PT_LOOS + 0x6)
#تعریف_کن PT_HP_CORE_پشته	(PT_LOOS + 0x7)
#تعریف_کن PT_HP_CORE_SHM		(PT_LOOS + 0x8)
#تعریف_کن PT_HP_CORE_MMF		(PT_LOOS + 0x9)
#تعریف_کن PT_HP_PARALLEL		(PT_LOOS + 0x10)
#تعریف_کن PT_HP_FASTBIND		(PT_LOOS + 0x11)
#تعریف_کن PT_HP_OPT_ANNOT		(PT_LOOS + 0x12)
#تعریف_کن PT_HP_HSL_ANNOT		(PT_LOOS + 0x13)
#تعریف_کن PT_HP_پشته		(PT_LOOS + 0x14)

#تعریف_کن PT_PARISC_ARCHEXT	0x70000000
#تعریف_کن PT_PARISC_UNWIND	0x70000001

/* Legal values for p_flags field of Elf32_Phdr/Elf64_Phdr.  */

#تعریف_کن PF_PARISC_SBP		0x08000000

#تعریف_کن PF_HP_صفحه_اندازه		0x00100000
#تعریف_کن PF_HP_FAR_SHARED	0x00200000
#تعریف_کن PF_HP_NEAR_SHARED	0x00400000
#تعریف_کن PF_HP_کد		0x01000000
#تعریف_کن PF_HP_MODIFY		0x02000000
#تعریف_کن PF_HP_LAZYSWAP		0x04000000
#تعریف_کن PF_HP_SBP		0x08000000


/* Alpha specific definitions.  */

/* Legal values for e_flags field of Elf64_Ehdr.  */

#تعریف_کن EF_ALPHA_32_بیت		1	/* All addresses must be < 2GB.  */
#تعریف_کن EF_ALPHA_CANRELAX	2	/* Relocations for relaxing exist.  */

/* Legal values for sh_type field of Elf64_Shdr.  */

/* These two are primarily concerned with ECOFF debugging info.  */
#تعریف_کن SHT_ALPHA_DEBUG		0x70000001
#تعریف_کن SHT_ALPHA_REGINFO	0x70000002

/* Legal values for sh_flags field of Elf64_Shdr.  */

#تعریف_کن SHF_ALPHA_GPREL		0x10000000

/* Legal values for st_other field of Elf64_Sym.  */
#تعریف_کن STO_ALPHA_NOPV		0x80	/* No PV required.  */
#تعریف_کن STO_ALPHA_STD_GPLOAD	0x88	/* PV only used for initial ldgp.  */

/* Alpha relocs.  */

#تعریف_کن R_ALPHA_NONE		0	/* No reloc */
#تعریف_کن R_ALPHA_REFLONG		1	/* Direct 32 bit */
#تعریف_کن R_ALPHA_REFQUAD		2	/* Direct 64 bit */
#تعریف_کن R_ALPHA_GPREL32		3	/* GP relative 32 bit */
#تعریف_کن R_ALPHA_LITERAL		4	/* GP relative 16 bit w/optimization */
#تعریف_کن R_ALPHA_LITUSE		5	/* Optimization hint for LITERAL */
#تعریف_کن R_ALPHA_GPDISP		6	/* Add displacement to GP */
#تعریف_کن R_ALPHA_BRADDR		7	/* PC+4 relative 23 bit shifted */
#تعریف_کن R_ALPHA_HINT		8	/* PC+4 relative 16 bit shifted */
#تعریف_کن R_ALPHA_SREL16		9	/* PC relative 16 bit */
#تعریف_کن R_ALPHA_SREL32		10	/* PC relative 32 bit */
#تعریف_کن R_ALPHA_SREL64		11	/* PC relative 64 bit */
#تعریف_کن R_ALPHA_GPRELHIGH	17	/* GP relative 32 bit, high 16 bits */
#تعریف_کن R_ALPHA_GPRELLOW	18	/* GP relative 32 bit, low 16 bits */
#تعریف_کن R_ALPHA_GPREL16		19	/* GP relative 16 bit */
#تعریف_کن R_ALPHA_COPY		24	/* Copy symbol at runtime */
#تعریف_کن R_ALPHA_GLOB_DAT	25	/* Create GOT entry */
#تعریف_کن R_ALPHA_JMP_جایگاه	26	/* Create PLT entry */
#تعریف_کن R_ALPHA_RELATIVE	27	/* Adjust by program base */
#تعریف_کن R_ALPHA_TLS_GD_HI	28
#تعریف_کن R_ALPHA_TLSGD		29
#تعریف_کن R_ALPHA_TLS_LDM		30
#تعریف_کن R_ALPHA_DTPMOD64	31
#تعریف_کن R_ALPHA_GOTDTPREL	32
#تعریف_کن R_ALPHA_DTPREL64	33
#تعریف_کن R_ALPHA_DTPRELHI	34
#تعریف_کن R_ALPHA_DTPRELLO	35
#تعریف_کن R_ALPHA_DTPREL16	36
#تعریف_کن R_ALPHA_GOTTPREL	37
#تعریف_کن R_ALPHA_TPREL64		38
#تعریف_کن R_ALPHA_TPRELHI		39
#تعریف_کن R_ALPHA_TPRELLO		40
#تعریف_کن R_ALPHA_TPREL16		41
/* Keep this the last entry.  */
#تعریف_کن R_ALPHA_رقم		46

/* Magic values of the LITUSE relocation addend.  */
#تعریف_کن LITUSE_ALPHA_ADDR	0
#تعریف_کن LITUSE_ALPHA_پایه	1
#تعریف_کن LITUSE_ALPHA_BYTOFF	2
#تعریف_کن LITUSE_ALPHA_JSR	3
#تعریف_کن LITUSE_ALPHA_TLS_GD	4
#تعریف_کن LITUSE_ALPHA_TLS_LDM	5

/* Legal values for d_tag of Elf64_Dyn.  */
#تعریف_کن DT_ALPHA_PLTRO		(DT_LOPROC + 0)
#تعریف_کن DT_ALPHA_رقم		1

/* PowerPC specific declarations */

/* Values for Elf32/64_Ehdr.e_flags.  */
#تعریف_کن EF_PPC_EMB		0x80000000	/* PowerPC embedded flag */

/* Cygnus local bits below */
#تعریف_کن EF_PPC_RELOCATABLE	0x00010000	/* PowerPC -mrelocatable flag*/
#تعریف_کن EF_PPC_RELOCATABLE_LIB	0x00008000	/* PowerPC -mrelocatable-lib
						   flag */

/* PowerPC relocations defined by the ABIs */
#تعریف_کن R_PPC_NONE		0
#تعریف_کن R_PPC_ADDR32		1	/* 32bit absolute address */
#تعریف_کن R_PPC_ADDR24		2	/* 26bit address, 2 bits ignored.  */
#تعریف_کن R_PPC_ADDR16		3	/* 16bit absolute address */
#تعریف_کن R_PPC_ADDR16_LO		4	/* lower 16bit of absolute address */
#تعریف_کن R_PPC_ADDR16_HI		5	/* high 16bit of absolute address */
#تعریف_کن R_PPC_ADDR16_HA		6	/* adjusted high 16bit */
#تعریف_کن R_PPC_ADDR14		7	/* 16bit address, 2 bits ignored */
#تعریف_کن R_PPC_ADDR14_BRTAKEN	8
#تعریف_کن R_PPC_ADDR14_BRNTAKEN	9
#تعریف_کن R_PPC_REL24		10	/* PC relative 26 bit */
#تعریف_کن R_PPC_REL14		11	/* PC relative 16 bit */
#تعریف_کن R_PPC_REL14_BRTAKEN	12
#تعریف_کن R_PPC_REL14_BRNTAKEN	13
#تعریف_کن R_PPC_GOT16		14
#تعریف_کن R_PPC_GOT16_LO		15
#تعریف_کن R_PPC_GOT16_HI		16
#تعریف_کن R_PPC_GOT16_HA		17
#تعریف_کن R_PPC_PLTREL24		18
#تعریف_کن R_PPC_COPY		19
#تعریف_کن R_PPC_GLOB_DAT		20
#تعریف_کن R_PPC_JMP_جایگاه		21
#تعریف_کن R_PPC_RELATIVE		22
#تعریف_کن R_PPC_LOCAL24PC		23
#تعریف_کن R_PPC_UADDR32		24
#تعریف_کن R_PPC_UADDR16		25
#تعریف_کن R_PPC_REL32		26
#تعریف_کن R_PPC_PLT32		27
#تعریف_کن R_PPC_PLTREL32		28
#تعریف_کن R_PPC_PLT16_LO		29
#تعریف_کن R_PPC_PLT16_HI		30
#تعریف_کن R_PPC_PLT16_HA		31
#تعریف_کن R_PPC_SDAREL16		32
#تعریف_کن R_PPC_SECTOFF		33
#تعریف_کن R_PPC_SECTOFF_LO	34
#تعریف_کن R_PPC_SECTOFF_HI	35
#تعریف_کن R_PPC_SECTOFF_HA	36

/* PowerPC relocations defined for the TLS access ABI.  */
#تعریف_کن R_PPC_TLS		67 /* none	(sym+add)@tls */
#تعریف_کن R_PPC_DTPMOD32		68 /* word32	(sym+add)@dtpmod */
#تعریف_کن R_PPC_TPREL16		69 /* half16*	(sym+add)@tprel */
#تعریف_کن R_PPC_TPREL16_LO	70 /* half16	(sym+add)@tprel@l */
#تعریف_کن R_PPC_TPREL16_HI	71 /* half16	(sym+add)@tprel@h */
#تعریف_کن R_PPC_TPREL16_HA	72 /* half16	(sym+add)@tprel@ha */
#تعریف_کن R_PPC_TPREL32		73 /* word32	(sym+add)@tprel */
#تعریف_کن R_PPC_DTPREL16		74 /* half16*	(sym+add)@dtprel */
#تعریف_کن R_PPC_DTPREL16_LO	75 /* half16	(sym+add)@dtprel@l */
#تعریف_کن R_PPC_DTPREL16_HI	76 /* half16	(sym+add)@dtprel@h */
#تعریف_کن R_PPC_DTPREL16_HA	77 /* half16	(sym+add)@dtprel@ha */
#تعریف_کن R_PPC_DTPREL32		78 /* word32	(sym+add)@dtprel */
#تعریف_کن R_PPC_GOT_TLSGD16	79 /* half16*	(sym+add)@got@tlsgd */
#تعریف_کن R_PPC_GOT_TLSGD16_LO	80 /* half16	(sym+add)@got@tlsgd@l */
#تعریف_کن R_PPC_GOT_TLSGD16_HI	81 /* half16	(sym+add)@got@tlsgd@h */
#تعریف_کن R_PPC_GOT_TLSGD16_HA	82 /* half16	(sym+add)@got@tlsgd@ha */
#تعریف_کن R_PPC_GOT_TLSLD16	83 /* half16*	(sym+add)@got@tlsld */
#تعریف_کن R_PPC_GOT_TLSLD16_LO	84 /* half16	(sym+add)@got@tlsld@l */
#تعریف_کن R_PPC_GOT_TLSLD16_HI	85 /* half16	(sym+add)@got@tlsld@h */
#تعریف_کن R_PPC_GOT_TLSLD16_HA	86 /* half16	(sym+add)@got@tlsld@ha */
#تعریف_کن R_PPC_GOT_TPREL16	87 /* half16*	(sym+add)@got@tprel */
#تعریف_کن R_PPC_GOT_TPREL16_LO	88 /* half16	(sym+add)@got@tprel@l */
#تعریف_کن R_PPC_GOT_TPREL16_HI	89 /* half16	(sym+add)@got@tprel@h */
#تعریف_کن R_PPC_GOT_TPREL16_HA	90 /* half16	(sym+add)@got@tprel@ha */
#تعریف_کن R_PPC_GOT_DTPREL16	91 /* half16*	(sym+add)@got@dtprel */
#تعریف_کن R_PPC_GOT_DTPREL16_LO	92 /* half16*	(sym+add)@got@dtprel@l */
#تعریف_کن R_PPC_GOT_DTPREL16_HI	93 /* half16*	(sym+add)@got@dtprel@h */
#تعریف_کن R_PPC_GOT_DTPREL16_HA	94 /* half16*	(sym+add)@got@dtprel@ha */

/* The remaining relocs are from the Embedded ELF ABI, and are not
   in the SVR4 ELF ABI.  */
#تعریف_کن R_PPC_EMB_NADDR32	101
#تعریف_کن R_PPC_EMB_NADDR16	102
#تعریف_کن R_PPC_EMB_NADDR16_LO	103
#تعریف_کن R_PPC_EMB_NADDR16_HI	104
#تعریف_کن R_PPC_EMB_NADDR16_HA	105
#تعریف_کن R_PPC_EMB_SDAI16	106
#تعریف_کن R_PPC_EMB_SDA2I16	107
#تعریف_کن R_PPC_EMB_SDA2REL	108
#تعریف_کن R_PPC_EMB_SDA21		109	/* 16 bit offset in SDA */
#تعریف_کن R_PPC_EMB_MRKREF	110
#تعریف_کن R_PPC_EMB_RELSEC16	111
#تعریف_کن R_PPC_EMB_RELST_LO	112
#تعریف_کن R_PPC_EMB_RELST_HI	113
#تعریف_کن R_PPC_EMB_RELST_HA	114
#تعریف_کن R_PPC_EMB_بیت_FLD	115
#تعریف_کن R_PPC_EMB_RELSDA	116	/* 16 bit relative offset in SDA */

/* Diab tool relocations.  */
#تعریف_کن R_PPC_DIAB_SDA21_LO	180	/* like EMB_SDA21, but lower 16 bit */
#تعریف_کن R_PPC_DIAB_SDA21_HI	181	/* like EMB_SDA21, but high 16 bit */
#تعریف_کن R_PPC_DIAB_SDA21_HA	182	/* like EMB_SDA21, adjusted high 16 */
#تعریف_کن R_PPC_DIAB_RELSDA_LO	183	/* like EMB_RELSDA, but lower 16 bit */
#تعریف_کن R_PPC_DIAB_RELSDA_HI	184	/* like EMB_RELSDA, but high 16 bit */
#تعریف_کن R_PPC_DIAB_RELSDA_HA	185	/* like EMB_RELSDA, adjusted high 16 */

/* GNU extension to support local ifunc.  */
#تعریف_کن R_PPC_IRELATIVE		248

/* GNU relocs used in PIC code sequences.  */
#تعریف_کن R_PPC_REL16		249	/* half16   (sym+add-.) */
#تعریف_کن R_PPC_REL16_LO		250	/* half16   (sym+add-.)@l */
#تعریف_کن R_PPC_REL16_HI		251	/* half16   (sym+add-.)@h */
#تعریف_کن R_PPC_REL16_HA		252	/* half16   (sym+add-.)@ha */

/* This is a phony reloc to handle any old fashioned TOC16 references
   that may still be in object files.  */
#تعریف_کن R_PPC_TOC16		255

/* PowerPC specific values for the Dyn d_tag field.  */
#تعریف_کن DT_PPC_GOT		(DT_LOPROC + 0)
#تعریف_کن DT_PPC_رقم		1

/* PowerPC64 relocations defined by the ABIs */
#تعریف_کن R_PPC64_NONE		R_PPC_NONE
#تعریف_کن R_PPC64_ADDR32		R_PPC_ADDR32 /* 32bit absolute address */
#تعریف_کن R_PPC64_ADDR24		R_PPC_ADDR24 /* 26bit address, word aligned */
#تعریف_کن R_PPC64_ADDR16		R_PPC_ADDR16 /* 16bit absolute address */
#تعریف_کن R_PPC64_ADDR16_LO	R_PPC_ADDR16_LO	/* lower 16bits of address */
#تعریف_کن R_PPC64_ADDR16_HI	R_PPC_ADDR16_HI	/* high 16bits of address. */
#تعریف_کن R_PPC64_ADDR16_HA	R_PPC_ADDR16_HA /* adjusted high 16bits.  */
#تعریف_کن R_PPC64_ADDR14		R_PPC_ADDR14 /* 16bit address, word aligned */
#تعریف_کن R_PPC64_ADDR14_BRTAKEN	R_PPC_ADDR14_BRTAKEN
#تعریف_کن R_PPC64_ADDR14_BRNTAKEN	R_PPC_ADDR14_BRNTAKEN
#تعریف_کن R_PPC64_REL24		R_PPC_REL24 /* PC-rel. 26 bit, word aligned */
#تعریف_کن R_PPC64_REL14		R_PPC_REL14 /* PC relative 16 bit */
#تعریف_کن R_PPC64_REL14_BRTAKEN	R_PPC_REL14_BRTAKEN
#تعریف_کن R_PPC64_REL14_BRNTAKEN	R_PPC_REL14_BRNTAKEN
#تعریف_کن R_PPC64_GOT16		R_PPC_GOT16
#تعریف_کن R_PPC64_GOT16_LO	R_PPC_GOT16_LO
#تعریف_کن R_PPC64_GOT16_HI	R_PPC_GOT16_HI
#تعریف_کن R_PPC64_GOT16_HA	R_PPC_GOT16_HA

#تعریف_کن R_PPC64_COPY		R_PPC_COPY
#تعریف_کن R_PPC64_GLOB_DAT	R_PPC_GLOB_DAT
#تعریف_کن R_PPC64_JMP_جایگاه	R_PPC_JMP_جایگاه
#تعریف_کن R_PPC64_RELATIVE	R_PPC_RELATIVE

#تعریف_کن R_PPC64_UADDR32		R_PPC_UADDR32
#تعریف_کن R_PPC64_UADDR16		R_PPC_UADDR16
#تعریف_کن R_PPC64_REL32		R_PPC_REL32
#تعریف_کن R_PPC64_PLT32		R_PPC_PLT32
#تعریف_کن R_PPC64_PLTREL32	R_PPC_PLTREL32
#تعریف_کن R_PPC64_PLT16_LO	R_PPC_PLT16_LO
#تعریف_کن R_PPC64_PLT16_HI	R_PPC_PLT16_HI
#تعریف_کن R_PPC64_PLT16_HA	R_PPC_PLT16_HA

#تعریف_کن R_PPC64_SECTOFF		R_PPC_SECTOFF
#تعریف_کن R_PPC64_SECTOFF_LO	R_PPC_SECTOFF_LO
#تعریف_کن R_PPC64_SECTOFF_HI	R_PPC_SECTOFF_HI
#تعریف_کن R_PPC64_SECTOFF_HA	R_PPC_SECTOFF_HA
#تعریف_کن R_PPC64_ADDR30		37 /* word30 (S + A - P) >> 2 */
#تعریف_کن R_PPC64_ADDR64		38 /* doubleword64 S + A */
#تعریف_کن R_PPC64_ADDR16_HIGHER	39 /* half16 #higher(S + A) */
#تعریف_کن R_PPC64_ADDR16_HIGHERA	40 /* half16 #highera(S + A) */
#تعریف_کن R_PPC64_ADDR16_HIGHEST	41 /* half16 #highest(S + A) */
#تعریف_کن R_PPC64_ADDR16_HIGHESTA	42 /* half16 #highesta(S + A) */
#تعریف_کن R_PPC64_UADDR64		43 /* doubleword64 S + A */
#تعریف_کن R_PPC64_REL64		44 /* doubleword64 S + A - P */
#تعریف_کن R_PPC64_PLT64		45 /* doubleword64 L + A */
#تعریف_کن R_PPC64_PLTREL64	46 /* doubleword64 L + A - P */
#تعریف_کن R_PPC64_TOC16		47 /* half16* S + A - .TOC */
#تعریف_کن R_PPC64_TOC16_LO	48 /* half16 #lo(S + A - .TOC.) */
#تعریف_کن R_PPC64_TOC16_HI	49 /* half16 #hi(S + A - .TOC.) */
#تعریف_کن R_PPC64_TOC16_HA	50 /* half16 #ha(S + A - .TOC.) */
#تعریف_کن R_PPC64_TOC		51 /* doubleword64 .TOC */
#تعریف_کن R_PPC64_PLTGOT16	52 /* half16* M + A */
#تعریف_کن R_PPC64_PLTGOT16_LO	53 /* half16 #lo(M + A) */
#تعریف_کن R_PPC64_PLTGOT16_HI	54 /* half16 #hi(M + A) */
#تعریف_کن R_PPC64_PLTGOT16_HA	55 /* half16 #ha(M + A) */

#تعریف_کن R_PPC64_ADDR16_DS	56 /* half16ds* (S + A) >> 2 */
#تعریف_کن R_PPC64_ADDR16_LO_DS	57 /* half16ds  #lo(S + A) >> 2 */
#تعریف_کن R_PPC64_GOT16_DS	58 /* half16ds* (G + A) >> 2 */
#تعریف_کن R_PPC64_GOT16_LO_DS	59 /* half16ds  #lo(G + A) >> 2 */
#تعریف_کن R_PPC64_PLT16_LO_DS	60 /* half16ds  #lo(L + A) >> 2 */
#تعریف_کن R_PPC64_SECTOFF_DS	61 /* half16ds* (R + A) >> 2 */
#تعریف_کن R_PPC64_SECTOFF_LO_DS	62 /* half16ds  #lo(R + A) >> 2 */
#تعریف_کن R_PPC64_TOC16_DS	63 /* half16ds* (S + A - .TOC.) >> 2 */
#تعریف_کن R_PPC64_TOC16_LO_DS	64 /* half16ds  #lo(S + A - .TOC.) >> 2 */
#تعریف_کن R_PPC64_PLTGOT16_DS	65 /* half16ds* (M + A) >> 2 */
#تعریف_کن R_PPC64_PLTGOT16_LO_DS	66 /* half16ds  #lo(M + A) >> 2 */

/* PowerPC64 relocations defined for the TLS access ABI.  */
#تعریف_کن R_PPC64_TLS		67 /* none	(sym+add)@tls */
#تعریف_کن R_PPC64_DTPMOD64	68 /* doubleword64 (sym+add)@dtpmod */
#تعریف_کن R_PPC64_TPREL16		69 /* half16*	(sym+add)@tprel */
#تعریف_کن R_PPC64_TPREL16_LO	70 /* half16	(sym+add)@tprel@l */
#تعریف_کن R_PPC64_TPREL16_HI	71 /* half16	(sym+add)@tprel@h */
#تعریف_کن R_PPC64_TPREL16_HA	72 /* half16	(sym+add)@tprel@ha */
#تعریف_کن R_PPC64_TPREL64		73 /* doubleword64 (sym+add)@tprel */
#تعریف_کن R_PPC64_DTPREL16	74 /* half16*	(sym+add)@dtprel */
#تعریف_کن R_PPC64_DTPREL16_LO	75 /* half16	(sym+add)@dtprel@l */
#تعریف_کن R_PPC64_DTPREL16_HI	76 /* half16	(sym+add)@dtprel@h */
#تعریف_کن R_PPC64_DTPREL16_HA	77 /* half16	(sym+add)@dtprel@ha */
#تعریف_کن R_PPC64_DTPREL64	78 /* doubleword64 (sym+add)@dtprel */
#تعریف_کن R_PPC64_GOT_TLSGD16	79 /* half16*	(sym+add)@got@tlsgd */
#تعریف_کن R_PPC64_GOT_TLSGD16_LO	80 /* half16	(sym+add)@got@tlsgd@l */
#تعریف_کن R_PPC64_GOT_TLSGD16_HI	81 /* half16	(sym+add)@got@tlsgd@h */
#تعریف_کن R_PPC64_GOT_TLSGD16_HA	82 /* half16	(sym+add)@got@tlsgd@ha */
#تعریف_کن R_PPC64_GOT_TLSLD16	83 /* half16*	(sym+add)@got@tlsld */
#تعریف_کن R_PPC64_GOT_TLSLD16_LO	84 /* half16	(sym+add)@got@tlsld@l */
#تعریف_کن R_PPC64_GOT_TLSLD16_HI	85 /* half16	(sym+add)@got@tlsld@h */
#تعریف_کن R_PPC64_GOT_TLSLD16_HA	86 /* half16	(sym+add)@got@tlsld@ha */
#تعریف_کن R_PPC64_GOT_TPREL16_DS	87 /* half16ds*	(sym+add)@got@tprel */
#تعریف_کن R_PPC64_GOT_TPREL16_LO_DS 88 /* half16ds (sym+add)@got@tprel@l */
#تعریف_کن R_PPC64_GOT_TPREL16_HI	89 /* half16	(sym+add)@got@tprel@h */
#تعریف_کن R_PPC64_GOT_TPREL16_HA	90 /* half16	(sym+add)@got@tprel@ha */
#تعریف_کن R_PPC64_GOT_DTPREL16_DS	91 /* half16ds*	(sym+add)@got@dtprel */
#تعریف_کن R_PPC64_GOT_DTPREL16_LO_DS 92 /* half16ds (sym+add)@got@dtprel@l */
#تعریف_کن R_PPC64_GOT_DTPREL16_HI	93 /* half16	(sym+add)@got@dtprel@h */
#تعریف_کن R_PPC64_GOT_DTPREL16_HA	94 /* half16	(sym+add)@got@dtprel@ha */
#تعریف_کن R_PPC64_TPREL16_DS	95 /* half16ds*	(sym+add)@tprel */
#تعریف_کن R_PPC64_TPREL16_LO_DS	96 /* half16ds	(sym+add)@tprel@l */
#تعریف_کن R_PPC64_TPREL16_HIGHER	97 /* half16	(sym+add)@tprel@higher */
#تعریف_کن R_PPC64_TPREL16_HIGHERA	98 /* half16	(sym+add)@tprel@highera */
#تعریف_کن R_PPC64_TPREL16_HIGHEST	99 /* half16	(sym+add)@tprel@highest */
#تعریف_کن R_PPC64_TPREL16_HIGHESTA 100 /* half16	(sym+add)@tprel@highesta */
#تعریف_کن R_PPC64_DTPREL16_DS	101 /* half16ds* (sym+add)@dtprel */
#تعریف_کن R_PPC64_DTPREL16_LO_DS	102 /* half16ds	(sym+add)@dtprel@l */
#تعریف_کن R_PPC64_DTPREL16_HIGHER	103 /* half16	(sym+add)@dtprel@higher */
#تعریف_کن R_PPC64_DTPREL16_HIGHERA 104 /* half16	(sym+add)@dtprel@highera */
#تعریف_کن R_PPC64_DTPREL16_HIGHEST 105 /* half16	(sym+add)@dtprel@highest */
#تعریف_کن R_PPC64_DTPREL16_HIGHESTA 106 /* half16	(sym+add)@dtprel@highesta */

/* GNU extension to support local ifunc.  */
#تعریف_کن R_PPC64_JMP_IREL	247
#تعریف_کن R_PPC64_IRELATIVE	248
#تعریف_کن R_PPC64_REL16		249	/* half16   (sym+add-.) */
#تعریف_کن R_PPC64_REL16_LO	250	/* half16   (sym+add-.)@l */
#تعریف_کن R_PPC64_REL16_HI	251	/* half16   (sym+add-.)@h */
#تعریف_کن R_PPC64_REL16_HA	252	/* half16   (sym+add-.)@ha */

/* PowerPC64 specific values for the Dyn d_tag field.  */
#تعریف_کن DT_PPC64_GLINK  (DT_LOPROC + 0)
#تعریف_کن DT_PPC64_OPD	(DT_LOPROC + 1)
#تعریف_کن DT_PPC64_OPDSZ	(DT_LOPROC + 2)
#تعریف_کن DT_PPC64_رقم    3


/* ARM specific declarations */

/* Processor specific flags for the ELF header e_flags field.  */
#تعریف_کن EF_ARM_RELEXEC		0x01
#تعریف_کن EF_ARM_HASENTRY		0x02
#تعریف_کن EF_ARM_INTERWORK	0x04
#تعریف_کن EF_ARM_APCS_26		0x08
#تعریف_کن EF_ARM_APCS_FLOAT	0x10
#تعریف_کن EF_ARM_PIC		0x20
#تعریف_کن EF_ARM_ALIGN8		0x40 /* 8-bit structure alignment is in use */
#تعریف_کن EF_ARM_NEW_ABI		0x80
#تعریف_کن EF_ARM_OLD_ABI		0x100
#تعریف_کن EF_ARM_SOFT_FLOAT	0x200
#تعریف_کن EF_ARM_VFP_FLOAT	0x400
#تعریف_کن EF_ARM_MAVERICK_FLOAT	0x800

#تعریف_کن EF_ARM_ABI_FLOAT_SOFT	0x200   /* NB conflicts with EF_ARM_SOFT_FLOAT */
#تعریف_کن EF_ARM_ABI_FLOAT_HARD	0x400   /* NB conflicts with EF_ARM_VFP_FLOAT */


/* Other constants defined in the ARM ELF spec. version B-01.  */
/* NB. These conflict with values defined above.  */
#تعریف_کن EF_ARM_SYMSARESORTED	0x04
#تعریف_کن EF_ARM_DYNSYMSUSESEGIDX	0x08
#تعریف_کن EF_ARM_MAPSYMSFIRST	0x10
#تعریف_کن EF_ARM_EABIMASK		0XFF000000

/* Constants defined in AAELF.  */
#تعریف_کن EF_ARM_BE8	    0x00800000
#تعریف_کن EF_ARM_LE8	    0x00400000

#تعریف_کن EF_ARM_EABI_نسخه(flags)	((flags) & EF_ARM_EABIMASK)
#تعریف_کن EF_ARM_EABI_UNKNOWN	0x00000000
#تعریف_کن EF_ARM_EABI_VER1	0x01000000
#تعریف_کن EF_ARM_EABI_VER2	0x02000000
#تعریف_کن EF_ARM_EABI_VER3	0x03000000
#تعریف_کن EF_ARM_EABI_VER4	0x04000000
#تعریف_کن EF_ARM_EABI_VER5	0x05000000

/* Additional symbol types for Thumb.  */
#تعریف_کن STT_ARM_TFUNC		STT_LOPROC /* A Thumb function.  */
#تعریف_کن STT_ARM_16_بیت		STT_HIPROC /* A Thumb label.  */

/* ARM-specific values for sh_flags */
#تعریف_کن SHF_ARM_ENTRYSECT	0x10000000 /* Section contains an entry point */
#تعریف_کن SHF_ARM_COMDEF		0x80000000 /* Section may be multiply defined
					      in the input to a link step.  */

/* ARM-specific program header flags */
#تعریف_کن PF_ARM_SB		0x10000000 /* Segment contains the location
					      addressed by the static base. */
#تعریف_کن PF_ARM_PI		0x20000000 /* Position-independent segment.  */
#تعریف_کن PF_ARM_ABS		0x40000000 /* Absolute segment.  */

/* Processor specific values for the Phdr p_type field.  */
#تعریف_کن PT_ARM_EXIDX		(PT_LOPROC + 1)	/* ARM unwind segment.  */

/* Processor specific values for the Shdr sh_type field.  */
#تعریف_کن SHT_ARM_EXIDX		(SHT_LOPROC + 1) /* ARM unwind section.  */
#تعریف_کن SHT_ARM_PREEMPTMAP	(SHT_LOPROC + 2) /* Preemption details.  */
#تعریف_کن	SHT_ARM_صفات	(SHT_LOPROC + 3) /* ARM attributes section.  */
#تعریف_کن SHT_RISCV_صفات	0x70000003


/* AArch64 relocs.  */

#تعریف_کن R_AARCH64_NONE            0	/* No relocation.  */
#تعریف_کن R_AARCH64_ABS64         257	/* Direct 64 bit. */
#تعریف_کن R_AARCH64_ABS32         258	/* Direct 32 bit.  */
#تعریف_کن R_AARCH64_ABS16         259	/* Direct 16-bit.  */
#تعریف_کن R_AARCH64_PREL64        260	/* PC-relative 64-bit.  */
#تعریف_کن R_AARCH64_PREL32        261	/* PC-relative 32-bit.  */
#تعریف_کن R_AARCH64_PREL16        262	/* PC-relative 16-bit.  */
#تعریف_کن R_AARCH64_MOVW_UABS_G0  263	/* Dir. MOVZ imm. from bits 15:0.  */
#تعریف_کن R_AARCH64_MOVW_UABS_G0_NC 264	/* Likewise for MOVK; no check.  */
#تعریف_کن R_AARCH64_MOVW_UABS_G1  265	/* Dir. MOVZ imm. from bits 31:16.  */
#تعریف_کن R_AARCH64_MOVW_UABS_G1_NC 266	/* Likewise for MOVK; no check.  */
#تعریف_کن R_AARCH64_MOVW_UABS_G2  267	/* Dir. MOVZ imm. from bits 47:32.  */
#تعریف_کن R_AARCH64_MOVW_UABS_G2_NC 268	/* Likewise for MOVK; no check.  */
#تعریف_کن R_AARCH64_MOVW_UABS_G3  269	/* Dir. MOV{K,Z} imm. from 63:48.  */
#تعریف_کن R_AARCH64_MOVW_SABS_G0  270	/* Dir. MOV{N,Z} imm. from 15:0.  */
#تعریف_کن R_AARCH64_MOVW_SABS_G1  271	/* Dir. MOV{N,Z} imm. from 31:16.  */
#تعریف_کن R_AARCH64_MOVW_SABS_G2  272	/* Dir. MOV{N,Z} imm. from 47:32.  */
#تعریف_کن R_AARCH64_LD_PREL_LO19  273	/* PC-rel. LD imm. from bits 20:2.  */
#تعریف_کن R_AARCH64_ADR_PREL_LO21 274	/* PC-rel. ADR imm. from bits 20:0.  */
#تعریف_کن R_AARCH64_ADR_PREL_PG_HI21 275	/* Page-rel. ADRP imm. from 32:12.  */
#تعریف_کن R_AARCH64_ADR_PREL_PG_HI21_NC 276	/* Likewise; no overflow check.  */
#تعریف_کن R_AARCH64_جمع_کن_ABS_LO12_NC 277	/* Dir. ADD imm. from bits 11:0.  */
#تعریف_کن R_AARCH64_LDST8_ABS_LO12_NC 278	/* Likewise for LD/ST; no check. */
#تعریف_کن R_AARCH64_TSTBR14       279	/* PC-rel. TBZ/TBNZ imm. from 15:2.  */
#تعریف_کن R_AARCH64_CONDBR19      280	/* PC-rel. cond. br. imm. from 20:2. */
#تعریف_کن R_AARCH64_JUMP26        282	/* PC-rel. B imm. from bits 27:2.  */
#تعریف_کن R_AARCH64_CALL26        283	/* Likewise for CALL.  */
#تعریف_کن R_AARCH64_LDST16_ABS_LO12_NC 284	/* Dir. ADD imm. from bits 11:1.  */
#تعریف_کن R_AARCH64_LDST32_ABS_LO12_NC 285	/* Likewise for bits 11:2.  */
#تعریف_کن R_AARCH64_LDST64_ABS_LO12_NC 286	/* Likewise for bits 11:3.  */
#تعریف_کن R_AARCH64_MOVW_PREL_G0  287	/* PC-rel. MOV{N,Z} imm. from 15:0.  */
#تعریف_کن R_AARCH64_MOVW_PREL_G0_NC 288	/* Likewise for MOVK; no check.  */
#تعریف_کن R_AARCH64_MOVW_PREL_G1  289	/* PC-rel. MOV{N,Z} imm. from 31:16. */
#تعریف_کن R_AARCH64_MOVW_PREL_G1_NC 290	/* Likewise for MOVK; no check.  */
#تعریف_کن R_AARCH64_MOVW_PREL_G2  291	/* PC-rel. MOV{N,Z} imm. from 47:32. */
#تعریف_کن R_AARCH64_MOVW_PREL_G2_NC 292	/* Likewise for MOVK; no check.  */
#تعریف_کن R_AARCH64_MOVW_PREL_G3  293	/* PC-rel. MOV{N,Z} imm. from 63:48. */
#تعریف_کن R_AARCH64_LDST128_ABS_LO12_NC 299	/* Dir. ADD imm. from bits 11:4.  */
#تعریف_کن R_AARCH64_MOVW_GOTOFF_G0 300	/* GOT-rel. off. MOV{N,Z} imm. 15:0. */
#تعریف_کن R_AARCH64_MOVW_GOTOFF_G0_NC 301	/* Likewise for MOVK; no check.  */
#تعریف_کن R_AARCH64_MOVW_GOTOFF_G1 302	/* GOT-rel. o. MOV{N,Z} imm. 31:16.  */
#تعریف_کن R_AARCH64_MOVW_GOTOFF_G1_NC 303	/* Likewise for MOVK; no check.  */
#تعریف_کن R_AARCH64_MOVW_GOTOFF_G2 304	/* GOT-rel. o. MOV{N,Z} imm. 47:32.  */
#تعریف_کن R_AARCH64_MOVW_GOTOFF_G2_NC 305	/* Likewise for MOVK; no check.  */
#تعریف_کن R_AARCH64_MOVW_GOTOFF_G3 306	/* GOT-rel. o. MOV{N,Z} imm. 63:48.  */
#تعریف_کن R_AARCH64_GOTREL64      307	/* GOT-relative 64-bit.  */
#تعریف_کن R_AARCH64_GOTREL32      308	/* GOT-relative 32-bit.  */
#تعریف_کن R_AARCH64_GOT_LD_PREL19 309	/* PC-rel. GOT off. load imm. 20:2.  */
#تعریف_کن R_AARCH64_LD64_GOTOFF_LO15 310	/* GOT-rel. off. LD/ST imm. 14:3.  */
#تعریف_کن R_AARCH64_ADR_GOT_صفحه  311	/* P-page-rel. GOT off. ADRP 32:12.  */
#تعریف_کن R_AARCH64_LD64_GOT_LO12_NC 312	/* Dir. GOT off. LD/ST imm. 11:3.  */
#تعریف_کن R_AARCH64_LD64_GOTPAGE_LO15 313	/* GOT-page-rel. GOT off. LD/ST 14:3 */
#تعریف_کن R_AARCH64_TLSGD_ADR_PREL21 512	/* PC-relative ADR imm. 20:0.  */
#تعریف_کن R_AARCH64_TLSGD_ADR_PAGE21 513	/* page-rel. ADRP imm. 32:12.  */
#تعریف_کن R_AARCH64_TLSGD_جمع_کن_LO12_NC 514	/* direct ADD imm. from 11:0.  */
#تعریف_کن R_AARCH64_TLSGD_MOVW_G1 515	/* GOT-rel. MOV{N,Z} 31:16.  */
#تعریف_کن R_AARCH64_TLSGD_MOVW_G0_NC 516	/* GOT-rel. MOVK imm. 15:0.  */
#تعریف_کن R_AARCH64_TLSLD_ADR_PREL21 517	/* Like 512; local dynamic model.  */
#تعریف_کن R_AARCH64_TLSLD_ADR_PAGE21 518	/* Like 513; local dynamic model.  */
#تعریف_کن R_AARCH64_TLSLD_جمع_کن_LO12_NC 519	/* Like 514; local dynamic model.  */
#تعریف_کن R_AARCH64_TLSLD_MOVW_G1 520	/* Like 515; local dynamic model.  */
#تعریف_کن R_AARCH64_TLSLD_MOVW_G0_NC 521	/* Like 516; local dynamic model.  */
#تعریف_کن R_AARCH64_TLSLD_LD_PREL19 522	/* TLS PC-rel. load imm. 20:2.  */
#تعریف_کن R_AARCH64_TLSLD_MOVW_DTPREL_G2 523	/* TLS DTP-rel. MOV{N,Z} 47:32.  */
#تعریف_کن R_AARCH64_TLSLD_MOVW_DTPREL_G1 524	/* TLS DTP-rel. MOV{N,Z} 31:16.  */
#تعریف_کن R_AARCH64_TLSLD_MOVW_DTPREL_G1_NC 525	/* Likewise; MOVK; no check.  */
#تعریف_کن R_AARCH64_TLSLD_MOVW_DTPREL_G0 526	/* TLS DTP-rel. MOV{N,Z} 15:0.  */
#تعریف_کن R_AARCH64_TLSLD_MOVW_DTPREL_G0_NC 527	/* Likewise; MOVK; no check.  */
#تعریف_کن R_AARCH64_TLSLD_جمع_کن_DTPREL_HI12 528	/* DTP-rel. ADD imm. from 23:12. */
#تعریف_کن R_AARCH64_TLSLD_جمع_کن_DTPREL_LO12 529	/* DTP-rel. ADD imm. from 11:0.  */
#تعریف_کن R_AARCH64_TLSLD_جمع_کن_DTPREL_LO12_NC 530	/* Likewise; no ovfl. check.  */
#تعریف_کن R_AARCH64_TLSLD_LDST8_DTPREL_LO12 531	/* DTP-rel. LD/ST imm. 11:0.  */
#تعریف_کن R_AARCH64_TLSLD_LDST8_DTPREL_LO12_NC 532	/* Likewise; no check.  */
#تعریف_کن R_AARCH64_TLSLD_LDST16_DTPREL_LO12 533	/* DTP-rel. LD/ST imm. 11:1.  */
#تعریف_کن R_AARCH64_TLSLD_LDST16_DTPREL_LO12_NC 534	/* Likewise; no check.  */
#تعریف_کن R_AARCH64_TLSLD_LDST32_DTPREL_LO12 535	/* DTP-rel. LD/ST imm. 11:2.  */
#تعریف_کن R_AARCH64_TLSLD_LDST32_DTPREL_LO12_NC 536	/* Likewise; no check.  */
#تعریف_کن R_AARCH64_TLSLD_LDST64_DTPREL_LO12 537	/* DTP-rel. LD/ST imm. 11:3.  */
#تعریف_کن R_AARCH64_TLSLD_LDST64_DTPREL_LO12_NC 538	/* Likewise; no check.  */
#تعریف_کن R_AARCH64_TLSIE_MOVW_GOTTPREL_G1 539	/* GOT-rel. MOV{N,Z} 31:16.  */
#تعریف_کن R_AARCH64_TLSIE_MOVW_GOTTPREL_G0_NC 540	/* GOT-rel. MOVK 15:0.  */
#تعریف_کن R_AARCH64_TLSIE_ADR_GOTTPREL_PAGE21 541	/* Page-rel. ADRP 32:12.  */
#تعریف_کن R_AARCH64_TLSIE_LD64_GOTTPREL_LO12_NC 542	/* Direct LD off. 11:3.  */
#تعریف_کن R_AARCH64_TLSIE_LD_GOTTPREL_PREL19 543	/* PC-rel. load imm. 20:2.  */
#تعریف_کن R_AARCH64_TLSLE_MOVW_TPREL_G2 544	/* TLS TP-rel. MOV{N,Z} 47:32.  */
#تعریف_کن R_AARCH64_TLSLE_MOVW_TPREL_G1 545	/* TLS TP-rel. MOV{N,Z} 31:16.  */
#تعریف_کن R_AARCH64_TLSLE_MOVW_TPREL_G1_NC 546	/* Likewise; MOVK; no check.  */
#تعریف_کن R_AARCH64_TLSLE_MOVW_TPREL_G0 547	/* TLS TP-rel. MOV{N,Z} 15:0.  */
#تعریف_کن R_AARCH64_TLSLE_MOVW_TPREL_G0_NC 548	/* Likewise; MOVK; no check.  */
#تعریف_کن R_AARCH64_TLSLE_جمع_کن_TPREL_HI12 549	/* TP-rel. ADD imm. 23:12.  */
#تعریف_کن R_AARCH64_TLSLE_جمع_کن_TPREL_LO12 550	/* TP-rel. ADD imm. 11:0.  */
#تعریف_کن R_AARCH64_TLSLE_جمع_کن_TPREL_LO12_NC 551	/* Likewise; no ovfl. check.  */
#تعریف_کن R_AARCH64_TLSLE_LDST8_TPREL_LO12 552	/* TP-rel. LD/ST off. 11:0.  */
#تعریف_کن R_AARCH64_TLSLE_LDST8_TPREL_LO12_NC 553	/* Likewise; no ovfl. check. */
#تعریف_کن R_AARCH64_TLSLE_LDST16_TPREL_LO12 554	/* TP-rel. LD/ST off. 11:1.  */
#تعریف_کن R_AARCH64_TLSLE_LDST16_TPREL_LO12_NC 555	/* Likewise; no check.  */
#تعریف_کن R_AARCH64_TLSLE_LDST32_TPREL_LO12 556	/* TP-rel. LD/ST off. 11:2.  */
#تعریف_کن R_AARCH64_TLSLE_LDST32_TPREL_LO12_NC 557	/* Likewise; no check.  */
#تعریف_کن R_AARCH64_TLSLE_LDST64_TPREL_LO12 558	/* TP-rel. LD/ST off. 11:3.  */
#تعریف_کن R_AARCH64_TLSLE_LDST64_TPREL_LO12_NC 559	/* Likewise; no check.  */
#تعریف_کن R_AARCH64_TLSDESC_LD_PREL19 560	/* PC-rel. load immediate 20:2.  */
#تعریف_کن R_AARCH64_TLSDESC_ADR_PREL21 561	/* PC-rel. ADR immediate 20:0.  */
#تعریف_کن R_AARCH64_TLSDESC_ADR_PAGE21 562	/* Page-rel. ADRP imm. 32:12.  */
#تعریف_کن R_AARCH64_TLSDESC_LD64_LO12 563	/* Direct LD off. from 11:3.  */
#تعریف_کن R_AARCH64_TLSDESC_جمع_کن_LO12 564	/* Direct ADD imm. from 11:0.  */
#تعریف_کن R_AARCH64_TLSDESC_OFF_G1 565	/* GOT-rel. MOV{N,Z} imm. 31:16.  */
#تعریف_کن R_AARCH64_TLSDESC_OFF_G0_NC 566	/* GOT-rel. MOVK imm. 15:0; no ck.  */
#تعریف_کن R_AARCH64_TLSDESC_LDR   567	/* Relax LDR.  */
#تعریف_کن R_AARCH64_TLSDESC_جمع_کن   568	/* Relax ADD.  */
#تعریف_کن R_AARCH64_TLSDESC_CALL  569	/* Relax BLR.  */
#تعریف_کن R_AARCH64_TLSLE_LDST128_TPREL_LO12 570	/* TP-rel. LD/ST off. 11:4.  */
#تعریف_کن R_AARCH64_TLSLE_LDST128_TPREL_LO12_NC 571	/* Likewise; no check.  */
#تعریف_کن R_AARCH64_TLSLD_LDST128_DTPREL_LO12 572	/* DTP-rel. LD/ST imm. 11:4. */
#تعریف_کن R_AARCH64_TLSLD_LDST128_DTPREL_LO12_NC 573	/* Likewise; no check.  */
#تعریف_کن R_AARCH64_COPY         1024	/* Copy symbol at runtime.  */
#تعریف_کن R_AARCH64_GLOB_DAT     1025	/* Create GOT entry.  */
#تعریف_کن R_AARCH64_JUMP_جایگاه    1026	/* Create PLT entry.  */
#تعریف_کن R_AARCH64_RELATIVE     1027	/* Adjust by program base.  */
#تعریف_کن R_AARCH64_TLS_DTPMOD64 1028	/* Module number, 64 bit.  */
#تعریف_کن R_AARCH64_TLS_DTPREL64 1029	/* Module-relative offset, 64 bit.  */
#تعریف_کن R_AARCH64_TLS_TPREL64  1030	/* TP-relative offset, 64 bit.  */
#تعریف_کن R_AARCH64_TLSDESC      1031	/* TLS Descriptor.  */
#تعریف_کن R_AARCH64_IRELATIVE    1032	/* STT_GNU_IFUNC relocation.  */
/* Keep this the last entry.  */
#تعریف_کن R_AARCH64_رقم          1033

/* ARM relocs.  */

#تعریف_کن R_ARM_NONE		0	/* No reloc */
#تعریف_کن R_ARM_PC24		1	/* PC relative 26 bit branch */
#تعریف_کن R_ARM_ABS32		2	/* Direct 32 bit  */
#تعریف_کن R_ARM_REL32		3	/* PC relative 32 bit */
#تعریف_کن R_ARM_PC13		4
#تعریف_کن R_ARM_ABS16		5	/* Direct 16 bit */
#تعریف_کن R_ARM_ABS12		6	/* Direct 12 bit */
#تعریف_کن R_ARM_THM_ABS5		7
#تعریف_کن R_ARM_ABS8		8	/* Direct 8 bit */
#تعریف_کن R_ARM_SBREL32		9
#تعریف_کن R_ARM_THM_PC22		10
#تعریف_کن R_ARM_THM_PC8		11
#تعریف_کن R_ARM_AMP_VCALL9	12
#تعریف_کن R_ARM_SWI24		13	/* Obsolete static relocation.  */
#تعریف_کن R_ARM_TLS_DESC		13      /* Dynamic relocation.  */
#تعریف_کن R_ARM_THM_SWI8		14
#تعریف_کن R_ARM_XPC25		15
#تعریف_کن R_ARM_THM_XPC22		16
#تعریف_کن R_ARM_TLS_DTPMOD32	17	/* ID of module containing symbol */
#تعریف_کن R_ARM_TLS_DTPOFF32	18	/* Offset in TLS block */
#تعریف_کن R_ARM_TLS_TPOFF32	19	/* Offset in static TLS block */
#تعریف_کن R_ARM_COPY		20	/* Copy symbol at runtime */
#تعریف_کن R_ARM_GLOB_DAT		21	/* Create GOT entry */
#تعریف_کن R_ARM_JUMP_جایگاه		22	/* Create PLT entry */
#تعریف_کن R_ARM_RELATIVE		23	/* Adjust by program base */
#تعریف_کن R_ARM_GOTOFF		24	/* 32 bit offset to GOT */
#تعریف_کن R_ARM_GOTPC		25	/* 32 bit PC relative offset to GOT */
#تعریف_کن R_ARM_GOT32		26	/* 32 bit GOT entry */
#تعریف_کن R_ARM_PLT32		27	/* 32 bit PLT address */
#تعریف_کن R_ARM_CALL		28
#تعریف_کن R_ARM_JUMP24		29
#تعریف_کن R_ARM_THM_JUMP24	30
#تعریف_کن R_ARM_پایه_ABS  31  /* Adjust by program base.  */
#تعریف_کن R_ARM_ALU_PCREL_7_0	32
#تعریف_کن R_ARM_ALU_PCREL_15_8	33
#تعریف_کن R_ARM_ALU_PCREL_23_15	34
#تعریف_کن R_ARM_LDR_SBREL_11_0	35
#تعریف_کن R_ARM_ALU_SBREL_19_12	36
#تعریف_کن R_ARM_ALU_SBREL_27_20	37
#تعریف_کن R_ARM_TARGET1 38
#تعریف_کن R_ARM_SBREL31 39  /* Program base relative.  */
#تعریف_کن R_ARM_V4BX		40
#تعریف_کن R_ARM_TARGET2   41
#تعریف_کن R_ARM_PREL31		42
#تعریف_کن R_ARM_MOVW_ABS_NC	43
#تعریف_کن R_ARM_MOVT_ABS		 44
#تعریف_کن R_ARM_MOVW_PREL_NC  45	/* PC relative 16-bit (MOVW).  */
#تعریف_کن R_ARM_MOVT_PREL 46  /* PC relative (MOVT).  */
#تعریف_کن R_ARM_THM_MOVW_ABS_NC	47
#تعریف_کن R_ARM_THM_MOVT_ABS	48
/* Values from 49 to 89 are not yet used/handled by tcc. */
#تعریف_کن R_ARM_TLS_GOTDESC	90
#تعریف_کن R_ARM_TLS_CALL		91
#تعریف_کن R_ARM_TLS_DESCSEQ	92
#تعریف_کن R_ARM_THM_TLS_CALL	93
#تعریف_کن R_ARM_GOT_PREL		96
#تعریف_کن R_ARM_GNU_VTENTRY	100
#تعریف_کن R_ARM_GNU_VTINHERIT	101
#تعریف_کن R_ARM_THM_PC11		102	/* thumb unconditional branch */
#تعریف_کن R_ARM_THM_PC9		103	/* thumb conditional branch */
#تعریف_کن R_ARM_TLS_GD32		104	/* PC-rel 32 bit for global dynamic
					   thread local data */
#تعریف_کن R_ARM_TLS_LDM32		105	/* PC-rel 32 bit for local dynamic
					   thread local data */
#تعریف_کن R_ARM_TLS_LDO32		106	/* 32 bit offset relative to TLS
بلوک*/
#تعریف_کن R_ARM_TLS_IE32		107	/* PC-rel 32 bit for GOT entry of
					   static TLS block offset */
#تعریف_کن R_ARM_TLS_LE32		108	/* 32 bit offset relative to static
					   TLS block */
#تعریف_کن	R_ARM_THM_TLS_DESCSEQ	129
#تعریف_کن R_ARM_IRELATIVE		160
#تعریف_کن R_ARM_RXPC25		249
#تعریف_کن R_ARM_RSBREL32		250
#تعریف_کن R_ARM_THM_RPC22		251
#تعریف_کن R_ARM_RREL32		252
#تعریف_کن R_ARM_RABS22		253
#تعریف_کن R_ARM_RPC24		254
#تعریف_کن R_ARM_RBASE		255
/* Keep this the last entry.  */
#تعریف_کن R_ARM_رقم		256

/* TMS320C67xx specific declarations */

/* XXX: no ELF standard yet*/

/* TMS320C67xx relocs. */
#تعریف_کن R_C60_32       1
#تعریف_کن R_C60_GOT32     3               /* 32 bit GOT entry */
#تعریف_کن R_C60_PLT32     4               /* 32 bit PLT address */
#تعریف_کن R_C60_COPY      5               /* Copy symbol at runtime */
#تعریف_کن R_C60_GLOB_DAT  6               /* Create GOT entry */
#تعریف_کن R_C60_JMP_جایگاه  7               /* Create PLT entry */
#تعریف_کن R_C60_RELATIVE  8               /* Adjust by program base */
#تعریف_کن R_C60_GOTOFF    9               /* 32 bit offset to GOT */
#تعریف_کن R_C60_GOTPC     10              /* 32 bit PC relative offset to GOT */

#تعریف_کن R_C60LO16      0x54       /* low 16 bit MVKL embedded */
#تعریف_کن R_C60HI16      0x55       /* high 16 bit MVKH embedded */
/* Keep this the last entry.  */
#تعریف_کن R_C60_رقم      0x56

/* IA-64 specific declarations.  */

/* Processor specific flags for the Ehdr e_flags field.  */
#تعریف_کن EF_IA_64_MASKOS		0x0000000f	/* os-specific flags */
#تعریف_کن EF_IA_64_ABI64		0x00000010	/* 64-bit ABI */
#تعریف_کن EF_IA_64_ARCH		0xff000000	/* arch. version mask */

/* Processor specific values for the Phdr p_type field.  */
#تعریف_کن PT_IA_64_ARCHEXT	(PT_LOPROC + 0)	/* arch extension bits */
#تعریف_کن PT_IA_64_UNWIND		(PT_LOPROC + 1)	/* ia64 unwind bits */
#تعریف_کن PT_IA_64_HP_OPT_ANOT	(PT_LOOS + 0x12)
#تعریف_کن PT_IA_64_HP_HSL_ANOT	(PT_LOOS + 0x13)
#تعریف_کن PT_IA_64_HP_پشته	(PT_LOOS + 0x14)

/* Processor specific flags for the Phdr p_flags field.  */
#تعریف_کن PF_IA_64_NORECOV	0x80000000	/* spec insns w/o recovery */

/* Processor specific values for the Shdr sh_type field.  */
#تعریف_کن SHT_IA_64_EXT		(SHT_LOPROC + 0) /* extension bits */
#تعریف_کن SHT_IA_64_UNWIND	(SHT_LOPROC + 1) /* unwind bits */

/* Processor specific flags for the Shdr sh_flags field.  */
#تعریف_کن SHF_IA_64_SHORT		0x10000000	/* section near gp */
#تعریف_کن SHF_IA_64_NORECOV	0x20000000	/* spec insns w/o recovery */

/* Processor specific values for the Dyn d_tag field.  */
#تعریف_کن DT_IA_64_PLT_RESERVE	(DT_LOPROC + 0)
#تعریف_کن DT_IA_64_رقم		1

/* IA-64 relocations.  */
#تعریف_کن R_IA64_NONE		0x00	/* none */
#تعریف_کن R_IA64_IMM14		0x21	/* symbol + addend, add imm14 */
#تعریف_کن R_IA64_IMM22		0x22	/* symbol + addend, add imm22 */
#تعریف_کن R_IA64_IMM64		0x23	/* symbol + addend, mov imm64 */
#تعریف_کن R_IA64_DIR32MSB		0x24	/* symbol + addend, data4 MSB */
#تعریف_کن R_IA64_DIR32LSB		0x25	/* symbol + addend, data4 LSB */
#تعریف_کن R_IA64_DIR64MSB		0x26	/* symbol + addend, data8 MSB */
#تعریف_کن R_IA64_DIR64LSB		0x27	/* symbol + addend, data8 LSB */
#تعریف_کن R_IA64_GPREL22		0x2a	/* @gprel(sym + add), add imm22 */
#تعریف_کن R_IA64_GPREL64I		0x2b	/* @gprel(sym + add), mov imm64 */
#تعریف_کن R_IA64_GPREL32MSB	0x2c	/* @gprel(sym + add), data4 MSB */
#تعریف_کن R_IA64_GPREL32LSB	0x2d	/* @gprel(sym + add), data4 LSB */
#تعریف_کن R_IA64_GPREL64MSB	0x2e	/* @gprel(sym + add), data8 MSB */
#تعریف_کن R_IA64_GPREL64LSB	0x2f	/* @gprel(sym + add), data8 LSB */
#تعریف_کن R_IA64_LTOFF22		0x32	/* @ltoff(sym + add), add imm22 */
#تعریف_کن R_IA64_LTOFF64I		0x33	/* @ltoff(sym + add), mov imm64 */
#تعریف_کن R_IA64_PLTOFF22		0x3a	/* @pltoff(sym + add), add imm22 */
#تعریف_کن R_IA64_PLTOFF64I	0x3b	/* @pltoff(sym + add), mov imm64 */
#تعریف_کن R_IA64_PLTOFF64MSB	0x3e	/* @pltoff(sym + add), data8 MSB */
#تعریف_کن R_IA64_PLTOFF64LSB	0x3f	/* @pltoff(sym + add), data8 LSB */
#تعریف_کن R_IA64_FPTR64I		0x43	/* @fptr(sym + add), mov imm64 */
#تعریف_کن R_IA64_FPTR32MSB	0x44	/* @fptr(sym + add), data4 MSB */
#تعریف_کن R_IA64_FPTR32LSB	0x45	/* @fptr(sym + add), data4 LSB */
#تعریف_کن R_IA64_FPTR64MSB	0x46	/* @fptr(sym + add), data8 MSB */
#تعریف_کن R_IA64_FPTR64LSB	0x47	/* @fptr(sym + add), data8 LSB */
#تعریف_کن R_IA64_PCREL60B		0x48	/* @pcrel(sym + add), brl */
#تعریف_کن R_IA64_PCREL21B		0x49	/* @pcrel(sym + add), ptb, call */
#تعریف_کن R_IA64_PCREL21M		0x4a	/* @pcrel(sym + add), chk.s */
#تعریف_کن R_IA64_PCREL21F		0x4b	/* @pcrel(sym + add), fchkf */
#تعریف_کن R_IA64_PCREL32MSB	0x4c	/* @pcrel(sym + add), data4 MSB */
#تعریف_کن R_IA64_PCREL32LSB	0x4d	/* @pcrel(sym + add), data4 LSB */
#تعریف_کن R_IA64_PCREL64MSB	0x4e	/* @pcrel(sym + add), data8 MSB */
#تعریف_کن R_IA64_PCREL64LSB	0x4f	/* @pcrel(sym + add), data8 LSB */
#تعریف_کن R_IA64_LTOFF_FPTR22	0x52	/* @ltoff(@fptr(s+a)), imm22 */
#تعریف_کن R_IA64_LTOFF_FPTR64I	0x53	/* @ltoff(@fptr(s+a)), imm64 */
#تعریف_کن R_IA64_LTOFF_FPTR32MSB	0x54	/* @ltoff(@fptr(s+a)), data4 MSB */
#تعریف_کن R_IA64_LTOFF_FPTR32LSB	0x55	/* @ltoff(@fptr(s+a)), data4 LSB */
#تعریف_کن R_IA64_LTOFF_FPTR64MSB	0x56	/* @ltoff(@fptr(s+a)), data8 MSB */
#تعریف_کن R_IA64_LTOFF_FPTR64LSB	0x57	/* @ltoff(@fptr(s+a)), data8 LSB */
#تعریف_کن R_IA64_SEGREL32MSB	0x5c	/* @segrel(sym + add), data4 MSB */
#تعریف_کن R_IA64_SEGREL32LSB	0x5d	/* @segrel(sym + add), data4 LSB */
#تعریف_کن R_IA64_SEGREL64MSB	0x5e	/* @segrel(sym + add), data8 MSB */
#تعریف_کن R_IA64_SEGREL64LSB	0x5f	/* @segrel(sym + add), data8 LSB */
#تعریف_کن R_IA64_SECREL32MSB	0x64	/* @secrel(sym + add), data4 MSB */
#تعریف_کن R_IA64_SECREL32LSB	0x65	/* @secrel(sym + add), data4 LSB */
#تعریف_کن R_IA64_SECREL64MSB	0x66	/* @secrel(sym + add), data8 MSB */
#تعریف_کن R_IA64_SECREL64LSB	0x67	/* @secrel(sym + add), data8 LSB */
#تعریف_کن R_IA64_REL32MSB		0x6c	/* data 4 + REL */
#تعریف_کن R_IA64_REL32LSB		0x6d	/* data 4 + REL */
#تعریف_کن R_IA64_REL64MSB		0x6e	/* data 8 + REL */
#تعریف_کن R_IA64_REL64LSB		0x6f	/* data 8 + REL */
#تعریف_کن R_IA64_LTV32MSB		0x74	/* symbol + addend, data4 MSB */
#تعریف_کن R_IA64_LTV32LSB		0x75	/* symbol + addend, data4 LSB */
#تعریف_کن R_IA64_LTV64MSB		0x76	/* symbol + addend, data8 MSB */
#تعریف_کن R_IA64_LTV64LSB		0x77	/* symbol + addend, data8 LSB */
#تعریف_کن R_IA64_PCREL21BI	0x79	/* @pcrel(sym + add), 21bit inst */
#تعریف_کن R_IA64_PCREL22		0x7a	/* @pcrel(sym + add), 22bit inst */
#تعریف_کن R_IA64_PCREL64I		0x7b	/* @pcrel(sym + add), 64bit inst */
#تعریف_کن R_IA64_IPLTMSB		0x80	/* dynamic reloc, imported PLT, MSB */
#تعریف_کن R_IA64_IPLTLSB		0x81	/* dynamic reloc, imported PLT, LSB */
#تعریف_کن R_IA64_COPY		0x84	/* copy relocation */
#تعریف_کن R_IA64_SUB		0x85	/* Addend and symbol difference */
#تعریف_کن R_IA64_LTOFF22X		0x86	/* LTOFF22, relaxable.  */
#تعریف_کن R_IA64_LDXMOV		0x87	/* Use of LTOFF22X.  */
#تعریف_کن R_IA64_TPREL14		0x91	/* @tprel(sym + add), imm14 */
#تعریف_کن R_IA64_TPREL22		0x92	/* @tprel(sym + add), imm22 */
#تعریف_کن R_IA64_TPREL64I		0x93	/* @tprel(sym + add), imm64 */
#تعریف_کن R_IA64_TPREL64MSB	0x96	/* @tprel(sym + add), data8 MSB */
#تعریف_کن R_IA64_TPREL64LSB	0x97	/* @tprel(sym + add), data8 LSB */
#تعریف_کن R_IA64_LTOFF_TPREL22	0x9a	/* @ltoff(@tprel(s+a)), imm2 */
#تعریف_کن R_IA64_DTPMOD64MSB	0xa6	/* @dtpmod(sym + add), data8 MSB */
#تعریف_کن R_IA64_DTPMOD64LSB	0xa7	/* @dtpmod(sym + add), data8 LSB */
#تعریف_کن R_IA64_LTOFF_DTPMOD22	0xaa	/* @ltoff(@dtpmod(sym + add)), imm22 */
#تعریف_کن R_IA64_DTPREL14		0xb1	/* @dtprel(sym + add), imm14 */
#تعریف_کن R_IA64_DTPREL22		0xb2	/* @dtprel(sym + add), imm22 */
#تعریف_کن R_IA64_DTPREL64I	0xb3	/* @dtprel(sym + add), imm64 */
#تعریف_کن R_IA64_DTPREL32MSB	0xb4	/* @dtprel(sym + add), data4 MSB */
#تعریف_کن R_IA64_DTPREL32LSB	0xb5	/* @dtprel(sym + add), data4 LSB */
#تعریف_کن R_IA64_DTPREL64MSB	0xb6	/* @dtprel(sym + add), data8 MSB */
#تعریف_کن R_IA64_DTPREL64LSB	0xb7	/* @dtprel(sym + add), data8 LSB */
#تعریف_کن R_IA64_LTOFF_DTPREL22	0xba	/* @ltoff(@dtprel(s+a)), imm22 */

/* SH specific declarations */

/* Processor specific flags for the ELF header e_flags field.  */
#تعریف_کن EF_SH_MACH_ماسک		0x1f
#تعریف_کن EF_SH_UNKNOWN		0x0
#تعریف_کن EF_SH1			0x1
#تعریف_کن EF_SH2			0x2
#تعریف_کن EF_SH3			0x3
#تعریف_کن EF_SH_DSP		0x4
#تعریف_کن EF_SH3_DSP		0x5
#تعریف_کن EF_SH4AL_DSP		0x6
#تعریف_کن EF_SH3E			0x8
#تعریف_کن EF_SH4			0x9
#تعریف_کن EF_SH2E			0xb
#تعریف_کن EF_SH4A			0xc
#تعریف_کن EF_SH2A			0xd
#تعریف_کن EF_SH4_NOFPU		0x10
#تعریف_کن EF_SH4A_NOFPU		0x11
#تعریف_کن EF_SH4_NOMMU_NOFPU	0x12
#تعریف_کن EF_SH2A_NOFPU		0x13
#تعریف_کن EF_SH3_NOMMU		0x14
#تعریف_کن EF_SH2A_SH4_NOFPU	0x15
#تعریف_کن EF_SH2A_SH3_NOFPU	0x16
#تعریف_کن EF_SH2A_SH4		0x17
#تعریف_کن EF_SH2A_SH3E		0x18

/* SH relocs.  */
#تعریف_کن	R_SH_NONE		0
#تعریف_کن	R_SH_DIR32		1
#تعریف_کن	R_SH_REL32		2
#تعریف_کن	R_SH_DIR8WPN		3
#تعریف_کن	R_SH_IND12W		4
#تعریف_کن	R_SH_DIR8WPL		5
#تعریف_کن	R_SH_DIR8WPZ		6
#تعریف_کن	R_SH_DIR8BP		7
#تعریف_کن	R_SH_DIR8W		8
#تعریف_کن	R_SH_DIR8L		9
#تعریف_کن	R_SH_SWITCH16		25
#تعریف_کن	R_SH_SWITCH32		26
#تعریف_کن	R_SH_استفاده_میکند		27
#تعریف_کن	R_SH_شمار		28
#تعریف_کن	R_SH_ALIGN		29
#تعریف_کن	R_SH_کد		30
#تعریف_کن	R_SH_داده		31
#تعریف_کن	R_SH_LABEL		32
#تعریف_کن	R_SH_SWITCH8		33
#تعریف_کن	R_SH_GNU_VTINHERIT	34
#تعریف_کن	R_SH_GNU_VTENTRY	35
#تعریف_کن	R_SH_TLS_GD_32		144
#تعریف_کن	R_SH_TLS_LD_32		145
#تعریف_کن	R_SH_TLS_LDO_32		146
#تعریف_کن	R_SH_TLS_IE_32		147
#تعریف_کن	R_SH_TLS_LE_32		148
#تعریف_کن	R_SH_TLS_DTPMOD32	149
#تعریف_کن	R_SH_TLS_DTPOFF32	150
#تعریف_کن	R_SH_TLS_TPOFF32	151
#تعریف_کن	R_SH_GOT32		160
#تعریف_کن	R_SH_PLT32		161
#تعریف_کن	R_SH_COPY		162
#تعریف_کن	R_SH_GLOB_DAT		163
#تعریف_کن	R_SH_JMP_جایگاه		164
#تعریف_کن	R_SH_RELATIVE		165
#تعریف_کن	R_SH_GOTOFF		166
#تعریف_کن	R_SH_GOTPC		167
/* Keep this the last entry.  */
#تعریف_کن	R_SH_رقم		256

/* S/390 specific definitions.  */

/* Valid values for the e_flags field.  */

#تعریف_کن EF_S390_بالا_GPRS    0x00000001  /* High GPRs kernel facility needed.  */

/* Additional s390 relocs */

#تعریف_کن R_390_NONE		0	/* No reloc.  */
#تعریف_کن R_390_8			1	/* Direct 8 bit.  */
#تعریف_کن R_390_12		2	/* Direct 12 bit.  */
#تعریف_کن R_390_16		3	/* Direct 16 bit.  */
#تعریف_کن R_390_32		4	/* Direct 32 bit.  */
#تعریف_کن R_390_PC32		5	/* PC relative 32 bit.	*/
#تعریف_کن R_390_GOT12		6	/* 12 bit GOT offset.  */
#تعریف_کن R_390_GOT32		7	/* 32 bit GOT offset.  */
#تعریف_کن R_390_PLT32		8	/* 32 bit PC relative PLT address.  */
#تعریف_کن R_390_COPY		9	/* Copy symbol at runtime.  */
#تعریف_کن R_390_GLOB_DAT		10	/* Create GOT entry.  */
#تعریف_کن R_390_JMP_جایگاه		11	/* Create PLT entry.  */
#تعریف_کن R_390_RELATIVE		12	/* Adjust by program base.  */
#تعریف_کن R_390_GOTOFF32		13	/* 32 bit offset to GOT.	 */
#تعریف_کن R_390_GOTPC		14	/* 32 bit PC relative offset to GOT.  */
#تعریف_کن R_390_GOT16		15	/* 16 bit GOT offset.  */
#تعریف_کن R_390_PC16		16	/* PC relative 16 bit.	*/
#تعریف_کن R_390_PC16DBL		17	/* PC relative 16 bit shifted by 1.  */
#تعریف_کن R_390_PLT16DBL		18	/* 16 bit PC rel. PLT shifted by 1.  */
#تعریف_کن R_390_PC32DBL		19	/* PC relative 32 bit shifted by 1.  */
#تعریف_کن R_390_PLT32DBL		20	/* 32 bit PC rel. PLT shifted by 1.  */
#تعریف_کن R_390_GOTPCDBL		21	/* 32 bit PC rel. GOT shifted by 1.  */
#تعریف_کن R_390_64		22	/* Direct 64 bit.  */
#تعریف_کن R_390_PC64		23	/* PC relative 64 bit.	*/
#تعریف_کن R_390_GOT64		24	/* 64 bit GOT offset.  */
#تعریف_کن R_390_PLT64		25	/* 64 bit PC relative PLT address.  */
#تعریف_کن R_390_GOTENT		26	/* 32 bit PC rel. to GOT entry >> 1. */
#تعریف_کن R_390_GOTOFF16		27	/* 16 bit offset to GOT. */
#تعریف_کن R_390_GOTOFF64		28	/* 64 bit offset to GOT. */
#تعریف_کن R_390_GOTPLT12		29	/* 12 bit offset to jump slot.	*/
#تعریف_کن R_390_GOTPLT16		30	/* 16 bit offset to jump slot.	*/
#تعریف_کن R_390_GOTPLT32		31	/* 32 bit offset to jump slot.	*/
#تعریف_کن R_390_GOTPLT64		32	/* 64 bit offset to jump slot.	*/
#تعریف_کن R_390_GOTPLTENT		33	/* 32 bit rel. offset to jump slot.  */
#تعریف_کن R_390_PLTOFF16		34	/* 16 bit offset from GOT to PLT. */
#تعریف_کن R_390_PLTOFF32		35	/* 32 bit offset from GOT to PLT. */
#تعریف_کن R_390_PLTOFF64		36	/* 16 bit offset from GOT to PLT. */
#تعریف_کن R_390_TLS_بارگیری		37	/* Tag for load insn in TLS code.  */
#تعریف_کن R_390_TLS_GDCALL	38	/* Tag for function call in general
					   dynamic TLS code. */
#تعریف_کن R_390_TLS_LDCALL	39	/* Tag for function call in local
					   dynamic TLS code. */
#تعریف_کن R_390_TLS_GD32		40	/* Direct 32 bit for general dynamic
					   thread local data.  */
#تعریف_کن R_390_TLS_GD64		41	/* Direct 64 bit for general dynamic
					  thread local data.  */
#تعریف_کن R_390_TLS_GOTIE12	42	/* 12 bit GOT offset for static TLS
					   block offset.  */
#تعریف_کن R_390_TLS_GOTIE32	43	/* 32 bit GOT offset for static TLS
					   block offset.  */
#تعریف_کن R_390_TLS_GOTIE64	44	/* 64 bit GOT offset for static TLS
					   block offset. */
#تعریف_کن R_390_TLS_LDM32		45	/* Direct 32 bit for local dynamic
					   thread local data in LE code.  */
#تعریف_کن R_390_TLS_LDM64		46	/* Direct 64 bit for local dynamic
					   thread local data in LE code.  */
#تعریف_کن R_390_TLS_IE32		47	/* 32 bit address of GOT entry for
					   negated static TLS block offset.  */
#تعریف_کن R_390_TLS_IE64		48	/* 64 bit address of GOT entry for
					   negated static TLS block offset.  */
#تعریف_کن R_390_TLS_IEENT		49	/* 32 bit rel. offset to GOT entry for
					   negated static TLS block offset.  */
#تعریف_کن R_390_TLS_LE32		50	/* 32 bit negated offset relative to
					   static TLS block.  */
#تعریف_کن R_390_TLS_LE64		51	/* 64 bit negated offset relative to
					   static TLS block.  */
#تعریف_کن R_390_TLS_LDO32		52	/* 32 bit offset relative to TLS
					   block.  */
#تعریف_کن R_390_TLS_LDO64		53	/* 64 bit offset relative to TLS
					   block.  */
#تعریف_کن R_390_TLS_DTPMOD	54	/* ID of module containing symbol.  */
#تعریف_کن R_390_TLS_DTPOFF	55	/* Offset in TLS block.	 */
#تعریف_کن R_390_TLS_TPOFF		56	/* Negated offset in static TLS
					   block.  */
#تعریف_کن R_390_20		57	/* Direct 20 bit.  */
#تعریف_کن R_390_GOT20		58	/* 20 bit GOT offset.  */
#تعریف_کن R_390_GOTPLT20		59	/* 20 bit offset to jump slot.  */
#تعریف_کن R_390_TLS_GOTIE20	60	/* 20 bit GOT offset for static TLS
					   block offset.  */
#تعریف_کن R_390_IRELATIVE         61      /* STT_GNU_IFUNC relocation.  */
/* Keep this the last entry.  */
#تعریف_کن R_390_رقم		62


/* CRIS relocations.  */
#تعریف_کن R_CRIS_NONE		0
#تعریف_کن R_CRIS_8		1
#تعریف_کن R_CRIS_16		2
#تعریف_کن R_CRIS_32		3
#تعریف_کن R_CRIS_8_PCREL		4
#تعریف_کن R_CRIS_16_PCREL		5
#تعریف_کن R_CRIS_32_PCREL		6
#تعریف_کن R_CRIS_GNU_VTINHERIT	7
#تعریف_کن R_CRIS_GNU_VTENTRY	8
#تعریف_کن R_CRIS_COPY		9
#تعریف_کن R_CRIS_GLOB_DAT		10
#تعریف_کن R_CRIS_JUMP_جایگاه	11
#تعریف_کن R_CRIS_RELATIVE		12
#تعریف_کن R_CRIS_16_GOT		13
#تعریف_کن R_CRIS_32_GOT		14
#تعریف_کن R_CRIS_16_GOTPLT	15
#تعریف_کن R_CRIS_32_GOTPLT	16
#تعریف_کن R_CRIS_32_GOTREL	17
#تعریف_کن R_CRIS_32_PLT_GOTREL	18
#تعریف_کن R_CRIS_32_PLT_PCREL	19

#تعریف_کن R_CRIS_رقم		20


/* AMD x86-64 relocations.  */
#تعریف_کن R_X86_64_NONE		0	/* No reloc */
#تعریف_کن R_X86_64_64		1	/* Direct 64 bit  */
#تعریف_کن R_X86_64_PC32		2	/* PC relative 32 bit signed */
#تعریف_کن R_X86_64_GOT32		3	/* 32 bit GOT entry */
#تعریف_کن R_X86_64_PLT32		4	/* 32 bit PLT address */
#تعریف_کن R_X86_64_COPY		5	/* Copy symbol at runtime */
#تعریف_کن R_X86_64_GLOB_DAT	6	/* Create GOT entry */
#تعریف_کن R_X86_64_JUMP_جایگاه	7	/* Create PLT entry */
#تعریف_کن R_X86_64_RELATIVE	8	/* Adjust by program base */
#تعریف_کن R_X86_64_GOTPCREL	9	/* 32 bit signed PC relative
					   offset to GOT */
#تعریف_کن R_X86_64_32		10	/* Direct 32 bit zero extended */
#تعریف_کن R_X86_64_32S		11	/* Direct 32 bit sign extended */
#تعریف_کن R_X86_64_16		12	/* Direct 16 bit zero extended */
#تعریف_کن R_X86_64_PC16		13	/* 16 bit sign extended pc relative */
#تعریف_کن R_X86_64_8		14	/* Direct 8 bit sign extended  */
#تعریف_کن R_X86_64_PC8		15	/* 8 bit sign extended pc relative */
#تعریف_کن R_X86_64_DTPMOD64	16	/* ID of module containing symbol */
#تعریف_کن R_X86_64_DTPOFF64	17	/* Offset in module's TLS block */
#تعریف_کن R_X86_64_TPOFF64	18	/* Offset in initial TLS block */
#تعریف_کن R_X86_64_TLSGD		19	/* 32 bit signed PC relative offset
					   to two GOT entries for GD symbol */
#تعریف_کن R_X86_64_TLSLD		20	/* 32 bit signed PC relative offset
					   to two GOT entries for LD symbol */
#تعریف_کن R_X86_64_DTPOFF32	21	/* Offset in TLS block */
#تعریف_کن R_X86_64_GOTTPOFF	22	/* 32 bit signed PC relative offset
					   to GOT entry for IE symbol */
#تعریف_کن R_X86_64_TPOFF32	23	/* Offset in initial TLS block */
#تعریف_کن R_X86_64_PC64		24	/* PC relative 64 bit */
#تعریف_کن R_X86_64_GOTOFF64	25	/* 64 bit offset to GOT */
#تعریف_کن R_X86_64_GOTPC32	26	/* 32 bit signed pc relative
					   offset to GOT */
#تعریف_کن R_X86_64_GOT64		27	/* 64-bit GOT entry offset */
#تعریف_کن R_X86_64_GOTPCREL64	28	/* 64-bit PC relative offset
					   to GOT entry */
#تعریف_کن R_X86_64_GOTPC64	29	/* 64-bit PC relative offset to GOT */
#تعریف_کن R_X86_64_GOTPLT64	30 	/* like GOT64, says PLT entry needed */
#تعریف_کن R_X86_64_PLTOFF64	31	/* 64-bit GOT relative offset
					   to PLT entry */
#تعریف_کن R_X86_64_SIZE32		32	/* Size of symbol plus 32-bit addend */
#تعریف_کن R_X86_64_SIZE64		33	/* Size of symbol plus 64-bit addend */
#تعریف_کن R_X86_64_GOTPC32_TLSDESC 34	/* GOT offset for TLS descriptor.  */
#تعریف_کن R_X86_64_TLSDESC_CALL   35	/* Marker for call through TLS
					   descriptor.  */
#تعریف_کن R_X86_64_TLSDESC        36	/* TLS descriptor.  */
#تعریف_کن R_X86_64_IRELATIVE	37	/* Adjust indirectly by program base */
#تعریف_کن R_X86_64_RELATIVE64	38	/* 64-bit adjust by program base */
#تعریف_کن R_X86_64_GOTPCRELX	41	/* like GOTPCREL, but optionally with
					   linker optimizations */
#تعریف_کن R_X86_64_REX_GOTPCRELX	42      /* like GOTPCRELX, but a REX prefix
					   is present */

#تعریف_کن R_X86_64_رقم		43

/* x86-64 sh_type values.  */
#تعریف_کن SHT_X86_64_UNWIND       0x70000001 /* Unwind information.  */

/* AM33 relocations.  */
#تعریف_کن R_MN10300_NONE		0	/* No reloc.  */
#تعریف_کن R_MN10300_32		1	/* Direct 32 bit.  */
#تعریف_کن R_MN10300_16		2	/* Direct 16 bit.  */
#تعریف_کن R_MN10300_8		3	/* Direct 8 bit.  */
#تعریف_کن R_MN10300_PCREL32	4	/* PC-relative 32-bit.  */
#تعریف_کن R_MN10300_PCREL16	5	/* PC-relative 16-bit signed.  */
#تعریف_کن R_MN10300_PCREL8	6	/* PC-relative 8-bit signed.  */
#تعریف_کن R_MN10300_GNU_VTINHERIT	7	/* Ancient C++ vtable garbage... */
#تعریف_کن R_MN10300_GNU_VTENTRY	8	/* ... collection annotation.  */
#تعریف_کن R_MN10300_24		9	/* Direct 24 bit.  */
#تعریف_کن R_MN10300_GOTPC32	10	/* 32-bit PCrel offset to GOT.  */
#تعریف_کن R_MN10300_GOTPC16	11	/* 16-bit PCrel offset to GOT.  */
#تعریف_کن R_MN10300_GOTOFF32	12	/* 32-bit offset from GOT.  */
#تعریف_کن R_MN10300_GOTOFF24	13	/* 24-bit offset from GOT.  */
#تعریف_کن R_MN10300_GOTOFF16	14	/* 16-bit offset from GOT.  */
#تعریف_کن R_MN10300_PLT32		15	/* 32-bit PCrel to PLT entry.  */
#تعریف_کن R_MN10300_PLT16		16	/* 16-bit PCrel to PLT entry.  */
#تعریف_کن R_MN10300_GOT32		17	/* 32-bit offset to GOT entry.  */
#تعریف_کن R_MN10300_GOT24		18	/* 24-bit offset to GOT entry.  */
#تعریف_کن R_MN10300_GOT16		19	/* 16-bit offset to GOT entry.  */
#تعریف_کن R_MN10300_COPY		20	/* Copy symbol at runtime.  */
#تعریف_کن R_MN10300_GLOB_DAT	21	/* Create GOT entry.  */
#تعریف_کن R_MN10300_JMP_جایگاه	22	/* Create PLT entry.  */
#تعریف_کن R_MN10300_RELATIVE	23	/* Adjust by program base.  */
#تعریف_کن R_MN10300_TLS_GD	24	/* 32-bit offset for global dynamic.  */
#تعریف_کن R_MN10300_TLS_LD	25	/* 32-bit offset for local dynamic.  */
#تعریف_کن R_MN10300_TLS_LDO	26	/* Module-relative offset.  */
#تعریف_کن R_MN10300_TLS_GOTIE	27	/* GOT offset for static TLS block
					   offset.  */
#تعریف_کن R_MN10300_TLS_IE	28	/* GOT address for static TLS block
					   offset.  */
#تعریف_کن R_MN10300_TLS_LE	29	/* Offset relative to static TLS
					   block.  */
#تعریف_کن R_MN10300_TLS_DTPMOD	30	/* ID of module containing symbol.  */
#تعریف_کن R_MN10300_TLS_DTPOFF	31	/* Offset in module TLS block.  */
#تعریف_کن R_MN10300_TLS_TPOFF	32	/* Offset in static TLS block.  */
#تعریف_کن R_MN10300_SYM_DIFF	33	/* Adjustment for next reloc as needed
					   by linker relaxation.  */
#تعریف_کن R_MN10300_ALIGN		34	/* Alignment requirement for linker
					   relaxation.  */
#تعریف_کن R_MN10300_رقم		35


/* M32R relocs.  */
#تعریف_کن R_M32R_NONE		0	/* No reloc. */
#تعریف_کن R_M32R_16		1	/* Direct 16 bit. */
#تعریف_کن R_M32R_32		2	/* Direct 32 bit. */
#تعریف_کن R_M32R_24		3	/* Direct 24 bit. */
#تعریف_کن R_M32R_10_PCREL		4	/* PC relative 10 bit shifted. */
#تعریف_کن R_M32R_18_PCREL		5	/* PC relative 18 bit shifted. */
#تعریف_کن R_M32R_26_PCREL		6	/* PC relative 26 bit shifted. */
#تعریف_کن R_M32R_HI16_ULO		7	/* High 16 bit with unsigned low. */
#تعریف_کن R_M32R_HI16_SLO		8	/* High 16 bit with signed low. */
#تعریف_کن R_M32R_LO16		9	/* Low 16 bit. */
#تعریف_کن R_M32R_SDA16		10	/* 16 bit offset in SDA. */
#تعریف_کن R_M32R_GNU_VTINHERIT	11
#تعریف_کن R_M32R_GNU_VTENTRY	12
/* M32R relocs use SHT_RELA.  */
#تعریف_کن R_M32R_16_RELA		33	/* Direct 16 bit. */
#تعریف_کن R_M32R_32_RELA		34	/* Direct 32 bit. */
#تعریف_کن R_M32R_24_RELA		35	/* Direct 24 bit. */
#تعریف_کن R_M32R_10_PCREL_RELA	36	/* PC relative 10 bit shifted. */
#تعریف_کن R_M32R_18_PCREL_RELA	37	/* PC relative 18 bit shifted. */
#تعریف_کن R_M32R_26_PCREL_RELA	38	/* PC relative 26 bit shifted. */
#تعریف_کن R_M32R_HI16_ULO_RELA	39	/* High 16 bit with unsigned low */
#تعریف_کن R_M32R_HI16_SLO_RELA	40	/* High 16 bit with signed low */
#تعریف_کن R_M32R_LO16_RELA	41	/* Low 16 bit */
#تعریف_کن R_M32R_SDA16_RELA	42	/* 16 bit offset in SDA */
#تعریف_کن R_M32R_RELA_GNU_VTINHERIT	43
#تعریف_کن R_M32R_RELA_GNU_VTENTRY	44
#تعریف_کن R_M32R_REL32		45	/* PC relative 32 bit.  */

#تعریف_کن R_M32R_GOT24		48	/* 24 bit GOT entry */
#تعریف_کن R_M32R_26_PLTREL	49	/* 26 bit PC relative to PLT shifted */
#تعریف_کن R_M32R_COPY		50	/* Copy symbol at runtime */
#تعریف_کن R_M32R_GLOB_DAT		51	/* Create GOT entry */
#تعریف_کن R_M32_R_JMP_جایگاه		52	/* Create PLT entry */
#تعریف_کن R_M32R_RELATIVE		53	/* Adjust by program base */
#تعریف_کن R_M32R_GOTOFF		54	/* 24 bit offset to GOT */
#تعریف_کن R_M32R_GOTPC24		55	/* 24 bit PC relative offset to GOT */
#تعریف_کن R_M32R_GOT16_HI_ULO	56	/* High 16 bit GOT entry with unsigned
کم*/
#تعریف_کن R_M32R_GOT16_HI_SLO	57	/* High 16 bit GOT entry with signed
کم*/
#تعریف_کن R_M32R_GOT16_LO		58	/* Low 16 bit GOT entry */
#تعریف_کن R_M32R_GOTPC_HI_ULO	59	/* High 16 bit PC relative offset to
					   GOT with unsigned low */
#تعریف_کن R_M32R_GOTPC_HI_SLO	60	/* High 16 bit PC relative offset to
					   GOT with signed low */
#تعریف_کن R_M32R_GOTPC_LO		61	/* Low 16 bit PC relative offset to
					   GOT */
#تعریف_کن R_M32R_GOTOFF_HI_ULO	62	/* High 16 bit offset to GOT
					   with unsigned low */
#تعریف_کن R_M32R_GOTOFF_HI_SLO	63	/* High 16 bit offset to GOT
					   with signed low */
#تعریف_کن R_M32R_GOTOFF_LO	64	/* Low 16 bit offset to GOT */
#تعریف_کن R_M32_R_رقم		256	/* Keep this the last entry. */


/* TILEPro relocations.  */
#تعریف_کن R_TILEPRO_NONE		0	/* No reloc */
#تعریف_کن R_TILEPRO_32		1	/* Direct 32 bit */
#تعریف_کن R_TILEPRO_16		2	/* Direct 16 bit */
#تعریف_کن R_TILEPRO_8		3	/* Direct 8 bit */
#تعریف_کن R_TILEPRO_32_PCREL	4	/* PC relative 32 bit */
#تعریف_کن R_TILEPRO_16_PCREL	5	/* PC relative 16 bit */
#تعریف_کن R_TILEPRO_8_PCREL	6	/* PC relative 8 bit */
#تعریف_کن R_TILEPRO_LO16		7	/* Low 16 bit */
#تعریف_کن R_TILEPRO_HI16		8	/* High 16 bit */
#تعریف_کن R_TILEPRO_HA16		9	/* High 16 bit, adjusted */
#تعریف_کن R_TILEPRO_COPY		10	/* Copy relocation */
#تعریف_کن R_TILEPRO_GLOB_DAT	11	/* Create GOT entry */
#تعریف_کن R_TILEPRO_JMP_جایگاه	12	/* Create PLT entry */
#تعریف_کن R_TILEPRO_RELATIVE	13	/* Adjust by program base */
#تعریف_کن R_TILEPRO_BROFF_X1	14	/* X1 pipe branch offset */
#تعریف_کن R_TILEPRO_JOFFLONG_X1	15	/* X1 pipe jump offset */
#تعریف_کن R_TILEPRO_JOFFLONG_X1_PLT 16	/* X1 pipe jump offset to PLT */
#تعریف_کن R_TILEPRO_IMM8_X0	17	/* X0 pipe 8-bit */
#تعریف_کن R_TILEPRO_IMM8_Y0	18	/* Y0 pipe 8-bit */
#تعریف_کن R_TILEPRO_IMM8_X1	19	/* X1 pipe 8-bit */
#تعریف_کن R_TILEPRO_IMM8_Y1	20	/* Y1 pipe 8-bit */
#تعریف_کن R_TILEPRO_MT_IMM15_X1	21	/* X1 pipe mtspr */
#تعریف_کن R_TILEPRO_MF_IMM15_X1	22	/* X1 pipe mfspr */
#تعریف_کن R_TILEPRO_IMM16_X0	23	/* X0 pipe 16-bit */
#تعریف_کن R_TILEPRO_IMM16_X1	24	/* X1 pipe 16-bit */
#تعریف_کن R_TILEPRO_IMM16_X0_LO	25	/* X0 pipe low 16-bit */
#تعریف_کن R_TILEPRO_IMM16_X1_LO	26	/* X1 pipe low 16-bit */
#تعریف_کن R_TILEPRO_IMM16_X0_HI	27	/* X0 pipe high 16-bit */
#تعریف_کن R_TILEPRO_IMM16_X1_HI	28	/* X1 pipe high 16-bit */
#تعریف_کن R_TILEPRO_IMM16_X0_HA	29	/* X0 pipe high 16-bit, adjusted */
#تعریف_کن R_TILEPRO_IMM16_X1_HA	30	/* X1 pipe high 16-bit, adjusted */
#تعریف_کن R_TILEPRO_IMM16_X0_PCREL 31	/* X0 pipe PC relative 16 bit */
#تعریف_کن R_TILEPRO_IMM16_X1_PCREL 32	/* X1 pipe PC relative 16 bit */
#تعریف_کن R_TILEPRO_IMM16_X0_LO_PCREL 33	/* X0 pipe PC relative low 16 bit */
#تعریف_کن R_TILEPRO_IMM16_X1_LO_PCREL 34	/* X1 pipe PC relative low 16 bit */
#تعریف_کن R_TILEPRO_IMM16_X0_HI_PCREL 35	/* X0 pipe PC relative high 16 bit */
#تعریف_کن R_TILEPRO_IMM16_X1_HI_PCREL 36	/* X1 pipe PC relative high 16 bit */
#تعریف_کن R_TILEPRO_IMM16_X0_HA_PCREL 37	/* X0 pipe PC relative ha() 16 bit */
#تعریف_کن R_TILEPRO_IMM16_X1_HA_PCREL 38	/* X1 pipe PC relative ha() 16 bit */
#تعریف_کن R_TILEPRO_IMM16_X0_GOT	39	/* X0 pipe 16-bit GOT offset */
#تعریف_کن R_TILEPRO_IMM16_X1_GOT	40	/* X1 pipe 16-bit GOT offset */
#تعریف_کن R_TILEPRO_IMM16_X0_GOT_LO 41	/* X0 pipe low 16-bit GOT offset */
#تعریف_کن R_TILEPRO_IMM16_X1_GOT_LO 42	/* X1 pipe low 16-bit GOT offset */
#تعریف_کن R_TILEPRO_IMM16_X0_GOT_HI 43	/* X0 pipe high 16-bit GOT offset */
#تعریف_کن R_TILEPRO_IMM16_X1_GOT_HI 44	/* X1 pipe high 16-bit GOT offset */
#تعریف_کن R_TILEPRO_IMM16_X0_GOT_HA 45	/* X0 pipe ha() 16-bit GOT offset */
#تعریف_کن R_TILEPRO_IMM16_X1_GOT_HA 46	/* X1 pipe ha() 16-bit GOT offset */
#تعریف_کن R_TILEPRO_MMSTART_X0	47	/* X0 pipe mm "start" */
#تعریف_کن R_TILEPRO_MMEND_X0	48	/* X0 pipe mm "end" */
#تعریف_کن R_TILEPRO_MMSTART_X1	49	/* X1 pipe mm "start" */
#تعریف_کن R_TILEPRO_MMEND_X1	50	/* X1 pipe mm "end" */
#تعریف_کن R_TILEPRO_SHAMT_X0	51	/* X0 pipe shift amount */
#تعریف_کن R_TILEPRO_SHAMT_X1	52	/* X1 pipe shift amount */
#تعریف_کن R_TILEPRO_SHAMT_Y0	53	/* Y0 pipe shift amount */
#تعریف_کن R_TILEPRO_SHAMT_Y1	54	/* Y1 pipe shift amount */
#تعریف_کن R_TILEPRO_DEST_IMM8_X1	55	/* X1 pipe destination 8-bit */
/* Relocs 56-59 are currently not defined.  */
#تعریف_کن R_TILEPRO_TLS_GD_CALL	60	/* "jal" for TLS GD */
#تعریف_کن R_TILEPRO_IMM8_X0_TLS_GD_جمع_کن 61	/* X0 pipe "addi" for TLS GD */
#تعریف_کن R_TILEPRO_IMM8_X1_TLS_GD_جمع_کن 62	/* X1 pipe "addi" for TLS GD */
#تعریف_کن R_TILEPRO_IMM8_Y0_TLS_GD_جمع_کن 63	/* Y0 pipe "addi" for TLS GD */
#تعریف_کن R_TILEPRO_IMM8_Y1_TLS_GD_جمع_کن 64	/* Y1 pipe "addi" for TLS GD */
#تعریف_کن R_TILEPRO_TLS_IE_بارگیری	65	/* "lw_tls" for TLS IE */
#تعریف_کن R_TILEPRO_IMM16_X0_TLS_GD 66	/* X0 pipe 16-bit TLS GD offset */
#تعریف_کن R_TILEPRO_IMM16_X1_TLS_GD 67	/* X1 pipe 16-bit TLS GD offset */
#تعریف_کن R_TILEPRO_IMM16_X0_TLS_GD_LO 68	/* X0 pipe low 16-bit TLS GD offset */
#تعریف_کن R_TILEPRO_IMM16_X1_TLS_GD_LO 69	/* X1 pipe low 16-bit TLS GD offset */
#تعریف_کن R_TILEPRO_IMM16_X0_TLS_GD_HI 70	/* X0 pipe high 16-bit TLS GD offset */
#تعریف_کن R_TILEPRO_IMM16_X1_TLS_GD_HI 71	/* X1 pipe high 16-bit TLS GD offset */
#تعریف_کن R_TILEPRO_IMM16_X0_TLS_GD_HA 72	/* X0 pipe ha() 16-bit TLS GD offset */
#تعریف_کن R_TILEPRO_IMM16_X1_TLS_GD_HA 73	/* X1 pipe ha() 16-bit TLS GD offset */
#تعریف_کن R_TILEPRO_IMM16_X0_TLS_IE 74	/* X0 pipe 16-bit TLS IE offset */
#تعریف_کن R_TILEPRO_IMM16_X1_TLS_IE 75	/* X1 pipe 16-bit TLS IE offset */
#تعریف_کن R_TILEPRO_IMM16_X0_TLS_IE_LO 76	/* X0 pipe low 16-bit TLS IE offset */
#تعریف_کن R_TILEPRO_IMM16_X1_TLS_IE_LO 77	/* X1 pipe low 16-bit TLS IE offset */
#تعریف_کن R_TILEPRO_IMM16_X0_TLS_IE_HI 78	/* X0 pipe high 16-bit TLS IE offset */
#تعریف_کن R_TILEPRO_IMM16_X1_TLS_IE_HI 79	/* X1 pipe high 16-bit TLS IE offset */
#تعریف_کن R_TILEPRO_IMM16_X0_TLS_IE_HA 80	/* X0 pipe ha() 16-bit TLS IE offset */
#تعریف_کن R_TILEPRO_IMM16_X1_TLS_IE_HA 81	/* X1 pipe ha() 16-bit TLS IE offset */
#تعریف_کن R_TILEPRO_TLS_DTPMOD32	82	/* ID of module containing symbol */
#تعریف_کن R_TILEPRO_TLS_DTPOFF32	83	/* Offset in TLS block */
#تعریف_کن R_TILEPRO_TLS_TPOFF32	84	/* Offset in static TLS block */
#تعریف_کن R_TILEPRO_IMM16_X0_TLS_LE 85	/* X0 pipe 16-bit TLS LE offset */
#تعریف_کن R_TILEPRO_IMM16_X1_TLS_LE 86	/* X1 pipe 16-bit TLS LE offset */
#تعریف_کن R_TILEPRO_IMM16_X0_TLS_LE_LO 87	/* X0 pipe low 16-bit TLS LE offset */
#تعریف_کن R_TILEPRO_IMM16_X1_TLS_LE_LO 88	/* X1 pipe low 16-bit TLS LE offset */
#تعریف_کن R_TILEPRO_IMM16_X0_TLS_LE_HI 89	/* X0 pipe high 16-bit TLS LE offset */
#تعریف_کن R_TILEPRO_IMM16_X1_TLS_LE_HI 90	/* X1 pipe high 16-bit TLS LE offset */
#تعریف_کن R_TILEPRO_IMM16_X0_TLS_LE_HA 91	/* X0 pipe ha() 16-bit TLS LE offset */
#تعریف_کن R_TILEPRO_IMM16_X1_TLS_LE_HA 92	/* X1 pipe ha() 16-bit TLS LE offset */

#تعریف_کن R_TILEPRO_GNU_VTINHERIT	128	/* GNU C++ vtable hierarchy */
#تعریف_کن R_TILEPRO_GNU_VTENTRY	129	/* GNU C++ vtable member usage */

#تعریف_کن R_TILEPRO_رقم		130


/* TILE-Gx relocations.  */
#تعریف_کن R_TILEGX_NONE		0	/* No reloc */
#تعریف_کن R_TILEGX_64		1	/* Direct 64 bit */
#تعریف_کن R_TILEGX_32		2	/* Direct 32 bit */
#تعریف_کن R_TILEGX_16		3	/* Direct 16 bit */
#تعریف_کن R_TILEGX_8		4	/* Direct 8 bit */
#تعریف_کن R_TILEGX_64_PCREL	5	/* PC relative 64 bit */
#تعریف_کن R_TILEGX_32_PCREL	6	/* PC relative 32 bit */
#تعریف_کن R_TILEGX_16_PCREL	7	/* PC relative 16 bit */
#تعریف_کن R_TILEGX_8_PCREL	8	/* PC relative 8 bit */
#تعریف_کن R_TILEGX_HW0		9	/* hword 0 16-bit */
#تعریف_کن R_TILEGX_HW1		10	/* hword 1 16-bit */
#تعریف_کن R_TILEGX_HW2		11	/* hword 2 16-bit */
#تعریف_کن R_TILEGX_HW3		12	/* hword 3 16-bit */
#تعریف_کن R_TILEGX_HW0_آخرین	13	/* last hword 0 16-bit */
#تعریف_کن R_TILEGX_HW1_آخرین	14	/* last hword 1 16-bit */
#تعریف_کن R_TILEGX_HW2_آخرین	15	/* last hword 2 16-bit */
#تعریف_کن R_TILEGX_COPY		16	/* Copy relocation */
#تعریف_کن R_TILEGX_GLOB_DAT	17	/* Create GOT entry */
#تعریف_کن R_TILEGX_JMP_جایگاه	18	/* Create PLT entry */
#تعریف_کن R_TILEGX_RELATIVE	19	/* Adjust by program base */
#تعریف_کن R_TILEGX_BROFF_X1	20	/* X1 pipe branch offset */
#تعریف_کن R_TILEGX_JUMPOFF_X1	21	/* X1 pipe jump offset */
#تعریف_کن R_TILEGX_JUMPOFF_X1_PLT	22	/* X1 pipe jump offset to PLT */
#تعریف_کن R_TILEGX_IMM8_X0	23	/* X0 pipe 8-bit */
#تعریف_کن R_TILEGX_IMM8_Y0	24	/* Y0 pipe 8-bit */
#تعریف_کن R_TILEGX_IMM8_X1	25	/* X1 pipe 8-bit */
#تعریف_کن R_TILEGX_IMM8_Y1	26	/* Y1 pipe 8-bit */
#تعریف_کن R_TILEGX_DEST_IMM8_X1	27	/* X1 pipe destination 8-bit */
#تعریف_کن R_TILEGX_MT_IMM14_X1	28	/* X1 pipe mtspr */
#تعریف_کن R_TILEGX_MF_IMM14_X1	29	/* X1 pipe mfspr */
#تعریف_کن R_TILEGX_MMSTART_X0	30	/* X0 pipe mm "start" */
#تعریف_کن R_TILEGX_MMEND_X0	31	/* X0 pipe mm "end" */
#تعریف_کن R_TILEGX_SHAMT_X0	32	/* X0 pipe shift amount */
#تعریف_کن R_TILEGX_SHAMT_X1	33	/* X1 pipe shift amount */
#تعریف_کن R_TILEGX_SHAMT_Y0	34	/* Y0 pipe shift amount */
#تعریف_کن R_TILEGX_SHAMT_Y1	35	/* Y1 pipe shift amount */
#تعریف_کن R_TILEGX_IMM16_X0_HW0	36	/* X0 pipe hword 0 */
#تعریف_کن R_TILEGX_IMM16_X1_HW0	37	/* X1 pipe hword 0 */
#تعریف_کن R_TILEGX_IMM16_X0_HW1	38	/* X0 pipe hword 1 */
#تعریف_کن R_TILEGX_IMM16_X1_HW1	39	/* X1 pipe hword 1 */
#تعریف_کن R_TILEGX_IMM16_X0_HW2	40	/* X0 pipe hword 2 */
#تعریف_کن R_TILEGX_IMM16_X1_HW2	41	/* X1 pipe hword 2 */
#تعریف_کن R_TILEGX_IMM16_X0_HW3	42	/* X0 pipe hword 3 */
#تعریف_کن R_TILEGX_IMM16_X1_HW3	43	/* X1 pipe hword 3 */
#تعریف_کن R_TILEGX_IMM16_X0_HW0_آخرین 44	/* X0 pipe last hword 0 */
#تعریف_کن R_TILEGX_IMM16_X1_HW0_آخرین 45	/* X1 pipe last hword 0 */
#تعریف_کن R_TILEGX_IMM16_X0_HW1_آخرین 46	/* X0 pipe last hword 1 */
#تعریف_کن R_TILEGX_IMM16_X1_HW1_آخرین 47	/* X1 pipe last hword 1 */
#تعریف_کن R_TILEGX_IMM16_X0_HW2_آخرین 48	/* X0 pipe last hword 2 */
#تعریف_کن R_TILEGX_IMM16_X1_HW2_آخرین 49	/* X1 pipe last hword 2 */
#تعریف_کن R_TILEGX_IMM16_X0_HW0_PCREL 50	/* X0 pipe PC relative hword 0 */
#تعریف_کن R_TILEGX_IMM16_X1_HW0_PCREL 51	/* X1 pipe PC relative hword 0 */
#تعریف_کن R_TILEGX_IMM16_X0_HW1_PCREL 52	/* X0 pipe PC relative hword 1 */
#تعریف_کن R_TILEGX_IMM16_X1_HW1_PCREL 53	/* X1 pipe PC relative hword 1 */
#تعریف_کن R_TILEGX_IMM16_X0_HW2_PCREL 54	/* X0 pipe PC relative hword 2 */
#تعریف_کن R_TILEGX_IMM16_X1_HW2_PCREL 55	/* X1 pipe PC relative hword 2 */
#تعریف_کن R_TILEGX_IMM16_X0_HW3_PCREL 56	/* X0 pipe PC relative hword 3 */
#تعریف_کن R_TILEGX_IMM16_X1_HW3_PCREL 57	/* X1 pipe PC relative hword 3 */
#تعریف_کن R_TILEGX_IMM16_X0_HW0_آخرین_PCREL 58 /* X0 pipe PC-rel last hword 0 */
#تعریف_کن R_TILEGX_IMM16_X1_HW0_آخرین_PCREL 59 /* X1 pipe PC-rel last hword 0 */
#تعریف_کن R_TILEGX_IMM16_X0_HW1_آخرین_PCREL 60 /* X0 pipe PC-rel last hword 1 */
#تعریف_کن R_TILEGX_IMM16_X1_HW1_آخرین_PCREL 61 /* X1 pipe PC-rel last hword 1 */
#تعریف_کن R_TILEGX_IMM16_X0_HW2_آخرین_PCREL 62 /* X0 pipe PC-rel last hword 2 */
#تعریف_کن R_TILEGX_IMM16_X1_HW2_آخرین_PCREL 63 /* X1 pipe PC-rel last hword 2 */
#تعریف_کن R_TILEGX_IMM16_X0_HW0_GOT 64	/* X0 pipe hword 0 GOT offset */
#تعریف_کن R_TILEGX_IMM16_X1_HW0_GOT 65	/* X1 pipe hword 0 GOT offset */
#تعریف_کن R_TILEGX_IMM16_X0_HW0_PLT_PCREL 66 /* X0 pipe PC-rel PLT hword 0 */
#تعریف_کن R_TILEGX_IMM16_X1_HW0_PLT_PCREL 67 /* X1 pipe PC-rel PLT hword 0 */
#تعریف_کن R_TILEGX_IMM16_X0_HW1_PLT_PCREL 68 /* X0 pipe PC-rel PLT hword 1 */
#تعریف_کن R_TILEGX_IMM16_X1_HW1_PLT_PCREL 69 /* X1 pipe PC-rel PLT hword 1 */
#تعریف_کن R_TILEGX_IMM16_X0_HW2_PLT_PCREL 70 /* X0 pipe PC-rel PLT hword 2 */
#تعریف_کن R_TILEGX_IMM16_X1_HW2_PLT_PCREL 71 /* X1 pipe PC-rel PLT hword 2 */
#تعریف_کن R_TILEGX_IMM16_X0_HW0_آخرین_GOT 72 /* X0 pipe last hword 0 GOT offset */
#تعریف_کن R_TILEGX_IMM16_X1_HW0_آخرین_GOT 73 /* X1 pipe last hword 0 GOT offset */
#تعریف_کن R_TILEGX_IMM16_X0_HW1_آخرین_GOT 74 /* X0 pipe last hword 1 GOT offset */
#تعریف_کن R_TILEGX_IMM16_X1_HW1_آخرین_GOT 75 /* X1 pipe last hword 1 GOT offset */
#تعریف_کن R_TILEGX_IMM16_X0_HW3_PLT_PCREL 76 /* X0 pipe PC-rel PLT hword 3 */
#تعریف_کن R_TILEGX_IMM16_X1_HW3_PLT_PCREL 77 /* X1 pipe PC-rel PLT hword 3 */
#تعریف_کن R_TILEGX_IMM16_X0_HW0_TLS_GD 78	/* X0 pipe hword 0 TLS GD offset */
#تعریف_کن R_TILEGX_IMM16_X1_HW0_TLS_GD 79	/* X1 pipe hword 0 TLS GD offset */
#تعریف_کن R_TILEGX_IMM16_X0_HW0_TLS_LE 80	/* X0 pipe hword 0 TLS LE offset */
#تعریف_کن R_TILEGX_IMM16_X1_HW0_TLS_LE 81	/* X1 pipe hword 0 TLS LE offset */
#تعریف_کن R_TILEGX_IMM16_X0_HW0_آخرین_TLS_LE 82 /* X0 pipe last hword 0 LE off */
#تعریف_کن R_TILEGX_IMM16_X1_HW0_آخرین_TLS_LE 83 /* X1 pipe last hword 0 LE off */
#تعریف_کن R_TILEGX_IMM16_X0_HW1_آخرین_TLS_LE 84 /* X0 pipe last hword 1 LE off */
#تعریف_کن R_TILEGX_IMM16_X1_HW1_آخرین_TLS_LE 85 /* X1 pipe last hword 1 LE off */
#تعریف_کن R_TILEGX_IMM16_X0_HW0_آخرین_TLS_GD 86 /* X0 pipe last hword 0 GD off */
#تعریف_کن R_TILEGX_IMM16_X1_HW0_آخرین_TLS_GD 87 /* X1 pipe last hword 0 GD off */
#تعریف_کن R_TILEGX_IMM16_X0_HW1_آخرین_TLS_GD 88 /* X0 pipe last hword 1 GD off */
#تعریف_کن R_TILEGX_IMM16_X1_HW1_آخرین_TLS_GD 89 /* X1 pipe last hword 1 GD off */
/* Relocs 90-91 are currently not defined.  */
#تعریف_کن R_TILEGX_IMM16_X0_HW0_TLS_IE 92	/* X0 pipe hword 0 TLS IE offset */
#تعریف_کن R_TILEGX_IMM16_X1_HW0_TLS_IE 93	/* X1 pipe hword 0 TLS IE offset */
#تعریف_کن R_TILEGX_IMM16_X0_HW0_آخرین_PLT_PCREL 94 /* X0 pipe PC-rel PLT last hword 0 */
#تعریف_کن R_TILEGX_IMM16_X1_HW0_آخرین_PLT_PCREL 95 /* X1 pipe PC-rel PLT last hword 0 */
#تعریف_کن R_TILEGX_IMM16_X0_HW1_آخرین_PLT_PCREL 96 /* X0 pipe PC-rel PLT last hword 1 */
#تعریف_کن R_TILEGX_IMM16_X1_HW1_آخرین_PLT_PCREL 97 /* X1 pipe PC-rel PLT last hword 1 */
#تعریف_کن R_TILEGX_IMM16_X0_HW2_آخرین_PLT_PCREL 98 /* X0 pipe PC-rel PLT last hword 2 */
#تعریف_کن R_TILEGX_IMM16_X1_HW2_آخرین_PLT_PCREL 99 /* X1 pipe PC-rel PLT last hword 2 */
#تعریف_کن R_TILEGX_IMM16_X0_HW0_آخرین_TLS_IE 100 /* X0 pipe last hword 0 IE off */
#تعریف_کن R_TILEGX_IMM16_X1_HW0_آخرین_TLS_IE 101 /* X1 pipe last hword 0 IE off */
#تعریف_کن R_TILEGX_IMM16_X0_HW1_آخرین_TLS_IE 102 /* X0 pipe last hword 1 IE off */
#تعریف_کن R_TILEGX_IMM16_X1_HW1_آخرین_TLS_IE 103 /* X1 pipe last hword 1 IE off */
/* Relocs 104-105 are currently not defined.  */
#تعریف_کن R_TILEGX_TLS_DTPMOD64	106	/* 64-bit ID of symbol's module */
#تعریف_کن R_TILEGX_TLS_DTPOFF64	107	/* 64-bit offset in TLS block */
#تعریف_کن R_TILEGX_TLS_TPOFF64	108	/* 64-bit offset in static TLS block */
#تعریف_کن R_TILEGX_TLS_DTPMOD32	109	/* 32-bit ID of symbol's module */
#تعریف_کن R_TILEGX_TLS_DTPOFF32	110	/* 32-bit offset in TLS block */
#تعریف_کن R_TILEGX_TLS_TPOFF32	111	/* 32-bit offset in static TLS block */
#تعریف_کن R_TILEGX_TLS_GD_CALL	112	/* "jal" for TLS GD */
#تعریف_کن R_TILEGX_IMM8_X0_TLS_GD_جمع_کن 113	/* X0 pipe "addi" for TLS GD */
#تعریف_کن R_TILEGX_IMM8_X1_TLS_GD_جمع_کن 114	/* X1 pipe "addi" for TLS GD */
#تعریف_کن R_TILEGX_IMM8_Y0_TLS_GD_جمع_کن 115	/* Y0 pipe "addi" for TLS GD */
#تعریف_کن R_TILEGX_IMM8_Y1_TLS_GD_جمع_کن 116	/* Y1 pipe "addi" for TLS GD */
#تعریف_کن R_TILEGX_TLS_IE_بارگیری	117	/* "ld_tls" for TLS IE */
#تعریف_کن R_TILEGX_IMM8_X0_TLS_جمع_کن 118	/* X0 pipe "addi" for TLS GD/IE */
#تعریف_کن R_TILEGX_IMM8_X1_TLS_جمع_کن 119	/* X1 pipe "addi" for TLS GD/IE */
#تعریف_کن R_TILEGX_IMM8_Y0_TLS_جمع_کن 120	/* Y0 pipe "addi" for TLS GD/IE */
#تعریف_کن R_TILEGX_IMM8_Y1_TLS_جمع_کن 121	/* Y1 pipe "addi" for TLS GD/IE */

#تعریف_کن R_TILEGX_GNU_VTINHERIT	128	/* GNU C++ vtable hierarchy */
#تعریف_کن R_TILEGX_GNU_VTENTRY	129	/* GNU C++ vtable member usage */

#تعریف_کن R_TILEGX_رقم		130

/* RISC-V ELF Flags */
#تعریف_کن EF_RISCV_RVC 			0x0001
#تعریف_کن EF_RISCV_FLOAT_ABI 		0x0006
#تعریف_کن EF_RISCV_FLOAT_ABI_SOFT 	0x0000
#تعریف_کن EF_RISCV_FLOAT_ABI_SINGLE 	0x0002
#تعریف_کن EF_RISCV_FLOAT_ABI_DOUBLE 	0x0004
#تعریف_کن EF_RISCV_FLOAT_ABI_QUAD 	0x0006

/* RISC-V relocations.  */
#تعریف_کن R_RISCV_NONE		 0
#تعریف_کن R_RISCV_32		 1
#تعریف_کن R_RISCV_64		 2
#تعریف_کن R_RISCV_RELATIVE	 3
#تعریف_کن R_RISCV_COPY		 4
#تعریف_کن R_RISCV_JUMP_جایگاه	 5
#تعریف_کن R_RISCV_TLS_DTPMOD32	 6
#تعریف_کن R_RISCV_TLS_DTPMOD64	 7
#تعریف_کن R_RISCV_TLS_DTPREL32	 8
#تعریف_کن R_RISCV_TLS_DTPREL64	 9
#تعریف_کن R_RISCV_TLS_TPREL32	10
#تعریف_کن R_RISCV_TLS_TPREL64	11
#تعریف_کن R_RISCV_BRANCH		16
#تعریف_کن R_RISCV_JAL		17
#تعریف_کن R_RISCV_CALL		18
#تعریف_کن R_RISCV_CALL_PLT	19
#تعریف_کن R_RISCV_GOT_HI20	20
#تعریف_کن R_RISCV_TLS_GOT_HI20	21
#تعریف_کن R_RISCV_TLS_GD_HI20	22
#تعریف_کن R_RISCV_PCREL_HI20	23
#تعریف_کن R_RISCV_PCREL_LO12_I	24
#تعریف_کن R_RISCV_PCREL_LO12_S	25
#تعریف_کن R_RISCV_HI20		26
#تعریف_کن R_RISCV_LO12_I		27
#تعریف_کن R_RISCV_LO12_S		28
#تعریف_کن R_RISCV_TPREL_HI20	29
#تعریف_کن R_RISCV_TPREL_LO12_I	30
#تعریف_کن R_RISCV_TPREL_LO12_S	31
#تعریف_کن R_RISCV_TPREL_جمع_کن	32
#تعریف_کن R_RISCV_ADD8		33
#تعریف_کن R_RISCV_ADD16		34
#تعریف_کن R_RISCV_ADD32		35
#تعریف_کن R_RISCV_ADD64		36
#تعریف_کن R_RISCV_SUB8		37
#تعریف_کن R_RISCV_SUB16		38
#تعریف_کن R_RISCV_SUB32		39
#تعریف_کن R_RISCV_SUB64		40
#تعریف_کن R_RISCV_GNU_VTINHERIT	41
#تعریف_کن R_RISCV_GNU_VTENTRY	42
#تعریف_کن R_RISCV_ALIGN		43
#تعریف_کن R_RISCV_RVC_BRANCH	44
#تعریف_کن R_RISCV_RVC_JUMP	45
#تعریف_کن R_RISCV_RVC_LUI		46
#تعریف_کن R_RISCV_GPREL_I		47
#تعریف_کن R_RISCV_GPREL_S		48
#تعریف_کن R_RISCV_TPREL_I		49
#تعریف_کن R_RISCV_TPREL_S		50
#تعریف_کن R_RISCV_RELAX		51
#تعریف_کن R_RISCV_SUB6		52
#تعریف_کن R_RISCV_SET6		53
#تعریف_کن R_RISCV_SET8		54
#تعریف_کن R_RISCV_SET16		55
#تعریف_کن R_RISCV_SET32		56
#تعریف_کن R_RISCV_32_PCREL	57
#تعریف_کن R_RISCV_IRELATIVE	58
#تعریف_کن R_RISCV_PLT32		59
#تعریف_کن R_RISCV_مجموعه_ULEB128	60
#تعریف_کن R_RISCV_SUB_ULEB128	61

#تعریف_کن R_RISCV_رقم		62


#پایان_اگر	/* elf.h */

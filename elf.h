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

#यदि_अपरिभाषितम् _ELF_H
#परिभाषय	_ELF_H 1

#यदि_अपरिभाषितम् _WIN32
#अन्तर्भाव <inttypes.h>
#अन्यथा
#यदि_अपरिभाषितम् __int8_t_defined
#परिभाषय __int8_t_defined
प्रकारनिर्देश चिह्नित वर्ण int8_t;
प्रकारनिर्देश ह्रस्व पूर्णाङ्क int16_t;
प्रकारनिर्देश पूर्णाङ्क int32_t;
प्रकारनिर्देश दीर्घ दीर्घ पूर्णाङ्क int64_t;
प्रकारनिर्देश अचिह्नित वर्ण           uint8_t;
प्रकारनिर्देश अचिह्नित ह्रस्व पूर्णाङ्क      uint16_t;
प्रकारनिर्देश अचिह्नित पूर्णाङ्क            uint32_t;
प्रकारनिर्देश अचिह्नित दीर्घ दीर्घ पूर्णाङ्क  uint64_t;
#यदि_अन्तः
#यदि_अन्तः

/* Standard ELF types.  */

/* Type for a 16-bit quantity.  */
प्रकारनिर्देश uint16_t Elf32_Half;
प्रकारनिर्देश uint16_t Elf64_Half;

/* Types for signed and unsigned 32-bit quantities.  */
प्रकारनिर्देश uint32_t Elf32_Word;
प्रकारनिर्देश	int32_t  Elf32_Sword;
प्रकारनिर्देश uint32_t Elf64_Word;
प्रकारनिर्देश	int32_t  Elf64_Sword;

/* Types for signed and unsigned 64-bit quantities.  */
प्रकारनिर्देश uint64_t Elf32_Xword;
प्रकारनिर्देश	int64_t  Elf32_Sxword;
प्रकारनिर्देश uint64_t Elf64_Xword;
प्रकारनिर्देश	int64_t  Elf64_Sxword;

/* Type of addresses.  */
प्रकारनिर्देश uint32_t Elf32_Addr;
प्रकारनिर्देश uint64_t Elf64_Addr;

/* Type of file offsets.  */
प्रकारनिर्देश uint32_t Elf32_Off;
प्रकारनिर्देश uint64_t Elf64_Off;

/* Type for section indices, which are 16-bit quantities.  */
प्रकारनिर्देश uint16_t Elf32_Section;
प्रकारनिर्देश uint16_t Elf64_Section;

/* Type for version symbol information.  */
प्रकारनिर्देश Elf32_Half Elf32_Versym;
प्रकारनिर्देश Elf64_Half Elf64_Versym;


/* The ELF file header.  This appears at the start of every ELF file.  */

#परिभाषय EI_NIDENT (16)

प्रकारनिर्देश संरचना
{
  अचिह्नित वर्ण	e_ident[EI_NIDENT];	/* Magic number and other info */
  Elf32_Half	e_type;			/* Object file type */
  Elf32_Half	e_machine;		/* Architecture */
  Elf32_Word	e_संस्करणम्;		/* Object file version */
  Elf32_Addr	e_प्रविष्टिः;		/* Entry point virtual address */
  Elf32_Off	e_phoff;		/* Program header table file offset */
  Elf32_Off	e_shoff;		/* Section header table file offset */
  Elf32_Word	e_flags;		/* Processor-specific flags */
  Elf32_Half	e_ehsize;		/* ELF header size in bytes */
  Elf32_Half	e_phentsize;		/* Program header table entry size */
  Elf32_Half	e_phnum;		/* Program header table entry count */
  Elf32_Half	e_shentsize;		/* Section header table entry size */
  Elf32_Half	e_shnum;		/* Section header table entry count */
  Elf32_Half	e_shstrndx;		/* Section header string table index */
} Elf32_Ehdr;

प्रकारनिर्देश संरचना
{
  अचिह्नित वर्ण	e_ident[EI_NIDENT];	/* Magic number and other info */
  Elf64_Half	e_type;			/* Object file type */
  Elf64_Half	e_machine;		/* Architecture */
  Elf64_Word	e_संस्करणम्;		/* Object file version */
  Elf64_Addr	e_प्रविष्टिः;		/* Entry point virtual address */
  Elf64_Off	e_phoff;		/* Program header table file offset */
  Elf64_Off	e_shoff;		/* Section header table file offset */
  Elf64_Word	e_flags;		/* Processor-specific flags */
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

#परिभाषय EI_MAG0		0		/* File identification byte 0 index */
#परिभाषय ELFMAG0		0x7f		/* Magic number byte 0 */

#परिभाषय EI_MAG1		1		/* File identification byte 1 index */
#परिभाषय ELFMAG1		'E'		/* Magic number byte 1 */

#परिभाषय EI_MAG2		2		/* File identification byte 2 index */
#परिभाषय ELFMAG2		'L'		/* Magic number byte 2 */

#परिभाषय EI_MAG3		3		/* File identification byte 3 index */
#परिभाषय ELFMAG3		'F'		/* Magic number byte 3 */

/* Conglomeration of the identification bytes, for easy testing as a word.  */
#परिभाषय	ELFMAG		"\177ELF"
#परिभाषय	SELFMAG		4

#परिभाषय EI_CLASS	4		/* File class byte index */
#परिभाषय ELFCLASSNONE	0		/* Invalid class */
#परिभाषय ELFCLASS32	1		/* 32-bit objects */
#परिभाषय ELFCLASS64	2		/* 64-bit objects */
#परिभाषय ELFCLASSNUM	3

#परिभाषय EI_दत्त		5		/* Data encoding byte index */
#परिभाषय ELFDATANONE	0		/* Invalid data encoding */
#परिभाषय ELFDATA2LSB	1		/* 2's complement, little endian */
#परिभाषय ELFDATA2MSB	2		/* 2's complement, big endian */
#परिभाषय ELFDATANUM	3

#परिभाषय EI_संस्करणम्	6		/* File version byte index */
					/* Value must be EV_CURRENT */

#परिभाषय EI_OSABI	7		/* OS ABI identification */
#परिभाषय ELFOSABI_NONE		0	/* UNIX System V ABI */
#परिभाषय ELFOSABI_SYSV		0	/* Alias.  */
#परिभाषय ELFOSABI_HPUX		1	/* HP-UX */
#परिभाषय ELFOSABI_NETBSD		2	/* NetBSD.  */
#परिभाषय ELFOSABI_GNU		3	/* Object uses GNU ELF extensions.  */
#परिभाषय ELFOSABI_LINUX		ELFOSABI_GNU /* Compatibility alias.  */
#परिभाषय ELFOSABI_SOLARIS	6	/* Sun Solaris.  */
#परिभाषय ELFOSABI_AIX		7	/* IBM AIX.  */
#परिभाषय ELFOSABI_IRIX		8	/* SGI Irix.  */
#परिभाषय ELFOSABI_FREEBSD	9	/* FreeBSD.  */
#परिभाषय ELFOSABI_TRU64		10	/* Compaq TRU64 UNIX.  */
#परिभाषय ELFOSABI_MODESTO	11	/* Novell Modesto.  */
#परिभाषय ELFOSABI_OPENBSD	12	/* OpenBSD.  */
#परिभाषय ELFOSABI_OPENVMS        13
#परिभाषय ELFOSABI_NSK            14      /* Hewlett-Packard Non-Stop Kernel.  */
#परिभाषय ELFOSABI_AROS           15      /* Amiga Research OS.  */
#परिभाषय ELFOSABI_FENIXOS        16      /* FenixOS.  */
#परिभाषय ELFOSABI_ARM_AEABI	64	/* ARM EABI.  */
#परिभाषय ELFOSABI_C6000_LINUX    65      /* Linux TMS320C6000.  */
#परिभाषय ELFOSABI_ARM		97	/* ARM */
#परिभाषय ELFOSABI_STANDALONE	255	/* Standalone (embedded) application */

#परिभाषय EI_ABIVERSION	8		/* ABI version */

#परिभाषय EI_PAD		9		/* Byte index of padding bytes */

/* Legal values for e_type (object file type).  */

#परिभाषय ET_NONE		0		/* No file type */
#परिभाषय ET_REL		1		/* Relocatable file */
#परिभाषय ET_EXEC		2		/* Executable file */
#परिभाषय ET_DYN		3		/* Shared object file */
#परिभाषय ET_CORE		4		/* Core file */
#परिभाषय	ET_अङ्कः		5		/* Number of defined types */
#परिभाषय ET_LOOS		0xfe00		/* OS-specific range start */
#परिभाषय ET_HIOS		0xfeff		/* OS-specific range end */
#परिभाषय ET_LOPROC	0xff00		/* Processor-specific range start */
#परिभाषय ET_HIPROC	0xffff		/* Processor-specific range end */

/* Legal values for e_machine (architecture).  */

#परिभाषय EM_NONE		 0		/* No machine */
#परिभाषय EM_M32		 1		/* AT&T WE 32100 */
#परिभाषय EM_SPARC	 2		/* SUN SPARC */
#परिभाषय EM_386		 3		/* Intel 80386 */
#परिभाषय EM_68K		 4		/* Motorola m68k family */
#परिभाषय EM_88K		 5		/* Motorola m88k family */
#परिभाषय EM_860		 7		/* Intel 80860 */
#परिभाषय EM_MIPS		 8		/* MIPS R3000 big-endian */
#परिभाषय EM_S370		 9		/* IBM System/370 */
#परिभाषय EM_MIPS_RS3_LE	10		/* MIPS R3000 little-endian */

#परिभाषय EM_PARISC	15		/* HPPA */
#परिभाषय EM_VPP500	17		/* Fujitsu VPP500 */
#परिभाषय EM_SPARC32PLUS	18		/* Sun's "v8plus" */
#परिभाषय EM_960		19		/* Intel 80960 */
#परिभाषय EM_PPC		20		/* PowerPC */
#परिभाषय EM_PPC64	21		/* PowerPC 64-bit */
#परिभाषय EM_S390		22		/* IBM S390 */

#परिभाषय EM_V800		36		/* NEC V800 series */
#परिभाषय EM_FR20		37		/* Fujitsu FR20 */
#परिभाषय EM_RH32		38		/* TRW RH-32 */
#परिभाषय EM_RCE		39		/* Motorola RCE */
#परिभाषय EM_ARM		40		/* ARM */
#परिभाषय EM_FAKE_ALPHA	41		/* Digital Alpha */
#परिभाषय EM_SH		42		/* Hitachi SH */
#परिभाषय EM_SPARCV9	43		/* SPARC v9 64-bit */
#परिभाषय EM_TRICORE	44		/* Siemens Tricore */
#परिभाषय EM_ARC		45		/* Argonaut RISC Core */
#परिभाषय EM_H8_300	46		/* Hitachi H8/300 */
#परिभाषय EM_H8_300H	47		/* Hitachi H8/300H */
#परिभाषय EM_H8S		48		/* Hitachi H8S */
#परिभाषय EM_H8_500	49		/* Hitachi H8/500 */
#परिभाषय EM_IA_64	50		/* Intel Merced */
#परिभाषय EM_MIPS_X	51		/* Stanford MIPS-X */
#परिभाषय EM_COLDFIRE	52		/* Motorola Coldfire */
#परिभाषय EM_68HC12	53		/* Motorola M68HC12 */
#परिभाषय EM_MMA		54		/* Fujitsu MMA Multimedia Accelerator*/
#परिभाषय EM_PCP		55		/* Siemens PCP */
#परिभाषय EM_NCPU		56		/* Sony nCPU embedded RISC */
#परिभाषय EM_NDR1		57		/* Denso NDR1 microprocessor */
#परिभाषय EM_STARCORE	58		/* Motorola Start*Core processor */
#परिभाषय EM_ME16		59		/* Toyota ME16 processor */
#परिभाषय EM_ST100	60		/* STMicroelectronic ST100 processor */
#परिभाषय EM_TINYJ	61		/* Advanced Logic Corp. Tinyj emb.fam*/
#परिभाषय EM_X86_64	62		/* AMD x86-64 architecture */
#परिभाषय EM_PDSP		63		/* Sony DSP Processor */

#परिभाषय EM_FX66		66		/* Siemens FX66 microcontroller */
#परिभाषय EM_ST9PLUS	67		/* STMicroelectronics ST9+ 8/16 mc */
#परिभाषय EM_ST7		68		/* STMicroelectronics ST7 8 bit mc */
#परिभाषय EM_68HC16	69		/* Motorola MC68HC16 microcontroller */
#परिभाषय EM_68HC11	70		/* Motorola MC68HC11 microcontroller */
#परिभाषय EM_68HC08	71		/* Motorola MC68HC08 microcontroller */
#परिभाषय EM_68HC05	72		/* Motorola MC68HC05 microcontroller */
#परिभाषय EM_SVX		73		/* Silicon Graphics SVx */
#परिभाषय EM_ST19		74		/* STMicroelectronics ST19 8 bit mc */
#परिभाषय EM_VAX		75		/* Digital VAX */
#परिभाषय EM_CRIS		76		/* Axis Communications 32-bit embedded processor */
#परिभाषय EM_JAVELIN	77		/* Infineon Technologies 32-bit embedded processor */
#परिभाषय EM_FIREPATH	78		/* Element 14 64-bit DSP Processor */
#परिभाषय EM_ZSP		79		/* LSI Logic 16-bit DSP Processor */
#परिभाषय EM_MMIX		80		/* Donald Knuth's educational 64-bit processor */
#परिभाषय EM_HUANY	81		/* Harvard University machine-independent object files */
#परिभाषय EM_PRISM	82		/* SiTera Prism */
#परिभाषय EM_AVR		83		/* Atmel AVR 8-bit microcontroller */
#परिभाषय EM_FR30		84		/* Fujitsu FR30 */
#परिभाषय EM_D10V		85		/* Mitsubishi D10V */
#परिभाषय EM_D30V		86		/* Mitsubishi D30V */
#परिभाषय EM_V850		87		/* NEC v850 */
#परिभाषय EM_M32R		88		/* Mitsubishi M32R */
#परिभाषय EM_MN10300	89		/* Matsushita MN10300 */
#परिभाषय EM_MN10200	90		/* Matsushita MN10200 */
#परिभाषय EM_PJ		91		/* picoJava */
#परिभाषय EM_OPENRISC	92		/* OpenRISC 32-bit embedded processor */
#परिभाषय EM_ARC_A5	93		/* ARC Cores Tangent-A5 */
#परिभाषय EM_XTENSA	94		/* Tensilica Xtensa Architecture */
#परिभाषय EM_AARCH64	183		/* ARM AARCH64 */
#परिभाषय EM_TILEPRO	188		/* Tilera TILEPro */
#परिभाषय EM_TILEGX	191		/* Tilera TILE-Gx */
#परिभाषय EM_RISCV	243	        /* RISC-V */
#परिभाषय EM_अङ्कः		253

/* If it is necessary to assign new unofficial EM_* values, please
   pick large random numbers (0x8523, 0xa7f2, etc.) to minimize the
   chances of collision with official or non-GNU unofficial values.  */

#परिभाषय EM_ALPHA	0x9026
#परिभाषय EM_C60		0x9c60

/* Legal values for e_version (version).  */

#परिभाषय EV_NONE		0		/* Invalid ELF version */
#परिभाषय EV_CURRENT	1		/* Current version */
#परिभाषय EV_अङ्कः		2

/* Section header.  */

प्रकारनिर्देश संरचना
{
  Elf32_Word	sh_name;		/* Section name (string tbl index) */
  Elf32_Word	sh_type;		/* Section type */
  Elf32_Word	sh_flags;		/* Section flags */
  Elf32_Addr	sh_addr;		/* Section virtual addr at execution */
  Elf32_Off	sh_विस्थापनम्;		/* Section file offset */
  Elf32_Word	sh_आकार;		/* Section size in bytes */
  Elf32_Word	sh_link;		/* Link to another section */
  Elf32_Word	sh_info;		/* Additional section information */
  Elf32_Word	sh_addralign;		/* Section alignment */
  Elf32_Word	sh_entsize;		/* Entry size if section holds table */
} Elf32_Shdr;

प्रकारनिर्देश संरचना
{
  Elf64_Word	sh_name;		/* Section name (string tbl index) */
  Elf64_Word	sh_type;		/* Section type */
  Elf64_Xword	sh_flags;		/* Section flags */
  Elf64_Addr	sh_addr;		/* Section virtual addr at execution */
  Elf64_Off	sh_विस्थापनम्;		/* Section file offset */
  Elf64_Xword	sh_आकार;		/* Section size in bytes */
  Elf64_Word	sh_link;		/* Link to another section */
  Elf64_Word	sh_info;		/* Additional section information */
  Elf64_Xword	sh_addralign;		/* Section alignment */
  Elf64_Xword	sh_entsize;		/* Entry size if section holds table */
} Elf64_Shdr;

/* Special section indices.  */

#परिभाषय SHN_UNDEF	0		/* Undefined section */
#परिभाषय SHN_LORESERVE	0xff00		/* Start of reserved indices */
#परिभाषय SHN_LOPROC	0xff00		/* Start of processor-specific */
#परिभाषय SHN_BEFORE	0xff00		/* Order section before all others
					   (Solaris).  */
#परिभाषय SHN_AFTER	0xff01		/* Order section after all others
					   (Solaris).  */
#परिभाषय SHN_HIPROC	0xff1f		/* End of processor-specific */
#परिभाषय SHN_LOOS	0xff20		/* Start of OS-specific */
#परिभाषय SHN_HIOS	0xff3f		/* End of OS-specific */
#परिभाषय SHN_ABS		0xfff1		/* Associated symbol is absolute */
#परिभाषय SHN_COMMON	0xfff2		/* Associated symbol is common */
#परिभाषय SHN_XINDEX	0xffff		/* Index is in extra table.  */
#परिभाषय SHN_HIRESERVE	0xffff		/* End of reserved indices */

/* Legal values for sh_type (section type).  */

#परिभाषय SHT_NULL	  0		/* Section header table entry unused */
#परिभाषय SHT_PROGBITS	  1		/* Program data */
#परिभाषय SHT_SYMTAB	  2		/* Symbol table */
#परिभाषय SHT_STRTAB	  3		/* String table */
#परिभाषय SHT_RELA	  4		/* Relocation entries with addends */
#परिभाषय SHT_HASH	  5		/* Symbol hash table */
#परिभाषय SHT_DYNAMIC	  6		/* Dynamic linking information */
#परिभाषय SHT_NOTE	  7		/* Notes */
#परिभाषय SHT_NOBITS	  8		/* Program space with no data (bss) */
#परिभाषय SHT_REL		  9		/* Relocation entries, no addends */
#परिभाषय SHT_SHLIB	  10		/* Reserved */
#परिभाषय SHT_DYNSYM	  11		/* Dynamic linker symbol table */
#परिभाषय SHT_INIT_ARRAY	  14		/* Array of constructors */
#परिभाषय SHT_FINI_ARRAY	  15		/* Array of destructors */
#परिभाषय SHT_PREINIT_ARRAY 16		/* Array of pre-constructors */
#परिभाषय SHT_गणः	  17		/* Section group */
#परिभाषय SHT_SYMTAB_SHNDX  18		/* Extended section indices */
#परिभाषय	SHT_अङ्कः		  19		/* Number of defined types.  */
#परिभाषय SHT_LOOS	  0x60000000	/* Start OS-specific.  */
#परिभाषय SHT_GNU_गुणाः 0x6ffffff5	/* Object attributes.  */
#परिभाषय SHT_GNU_HASH	  0x6ffffff6	/* GNU-style hash table.  */
#परिभाषय SHT_GNU_LIBLIST	  0x6ffffff7	/* Prelink library list */
#परिभाषय SHT_CHECKSUM	  0x6ffffff8	/* Checksum for DSO content.  */
#परिभाषय SHT_LOSUNW	  0x6ffffffa	/* Sun-specific low bound.  */
#परिभाषय SHT_SUNW_move	  0x6ffffffa
#परिभाषय SHT_SUNW_COMDAT   0x6ffffffb
#परिभाषय SHT_SUNW_syminfo  0x6ffffffc
#परिभाषय SHT_GNU_verdef	  0x6ffffffd	/* Version definition section.  */
#परिभाषय SHT_GNU_verneed	  0x6ffffffe	/* Version needs section.  */
#परिभाषय SHT_GNU_versym	  0x6fffffff	/* Version symbol table.  */
#परिभाषय SHT_HISUNW	  0x6fffffff	/* Sun-specific high bound.  */
#परिभाषय SHT_HIOS	  0x6fffffff	/* End OS-specific type */
#परिभाषय SHT_LOPROC	  0x70000000	/* Start of processor-specific */
#परिभाषय SHT_HIPROC	  0x7fffffff	/* End of processor-specific */
#परिभाषय SHT_LOUSER	  0x80000000	/* Start of application-specific */
#परिभाषय SHT_HIUSER	  0x8fffffff	/* End of application-specific */

/* Legal values for sh_flags (section flags).  */

#परिभाषय SHF_WRITE	     (1 << 0)	/* Writable */
#परिभाषय SHF_ALLOC	     (1 << 1)	/* Occupies memory during execution */
#परिभाषय SHF_EXECINSTR	     (1 << 2)	/* Executable */
#परिभाषय SHF_MERGE	     (1 << 4)	/* Might be merged */
#परिभाषय SHF_वाक्यानि	     (1 << 5)	/* Contains nul-terminated strings */
#परिभाषय SHF_INFO_LINK	     (1 << 6)	/* `sh_info' contains SHT index */
#परिभाषय SHF_LINK_क्रमः	     (1 << 7)	/* Preserve order after combining */
#परिभाषय SHF_OS_NONCONFORMING (1 << 8)	/* Non-standard OS specific handling
					   required */
#परिभाषय SHF_गणः	     (1 << 9)	/* Section is member of a group.  */
#परिभाषय SHF_TLS		     (1 << 10)	/* Section hold thread-local data.  */
#परिभाषय SHF_COMPRESSED	     (1 << 11)	/* Section with compressed data. */
#परिभाषय SHF_MASKOS	     0x0ff00000	/* OS-specific.  */
#परिभाषय SHF_MASKPROC	     0xf0000000	/* Processor-specific */
#परिभाषय SHF_ORDERED	     (1 << 30)	/* Special ordering requirement
					   (Solaris).  */
#परिभाषय SHF_EXCLUDE	     (1U << 31)	/* Section is excluded unless
					   referenced or allocated (Solaris).*/

/* Section group handling.  */
#परिभाषय GRP_COMDAT	0x1		/* Mark group as COMDAT.  */

/* Symbol table entry.  */

प्रकारनिर्देश संरचना
{
  Elf32_Word	st_name;		/* Symbol name (string tbl index) */
  Elf32_Addr	st_मानम्;		/* Symbol value */
  Elf32_Word	st_आकार;		/* Symbol size */
  अचिह्नित वर्ण	st_info;		/* Symbol type and binding */
  अचिह्नित वर्ण	st_other;		/* Symbol visibility */
  Elf32_Section	st_shndx;		/* Section index */
} Elf32_Sym;

प्रकारनिर्देश संरचना
{
  Elf64_Word	st_name;		/* Symbol name (string tbl index) */
  अचिह्नित वर्ण	st_info;		/* Symbol type and binding */
  अचिह्नित वर्ण st_other;		/* Symbol visibility */
  Elf64_Section	st_shndx;		/* Section index */
  Elf64_Addr	st_मानम्;		/* Symbol value */
  Elf64_Xword	st_आकार;		/* Symbol size */
} Elf64_Sym;

/* The syminfo section if available contains additional information about
   every dynamic symbol.  */

प्रकारनिर्देश संरचना
{
  Elf32_Half si_boundto;		/* Direct bindings, symbol bound to */
  Elf32_Half si_flags;			/* Per symbol flags */
} Elf32_Syminfo;

प्रकारनिर्देश संरचना
{
  Elf64_Half si_boundto;		/* Direct bindings, symbol bound to */
  Elf64_Half si_flags;			/* Per symbol flags */
} Elf64_Syminfo;

/* Possible values for si_boundto.  */
#परिभाषय SYMINFO_BT_SELF		0xffff	/* Symbol bound to self */
#परिभाषय SYMINFO_BT_PARENT	0xfffe	/* Symbol bound to parent */
#परिभाषय SYMINFO_BT_LOWRESERVE	0xff00	/* Beginning of reserved entries */

/* Possible bitmasks for si_flags.  */
#परिभाषय SYMINFO_FLG_प्रत्यक्षम्	0x0001	/* Direct bound symbol */
#परिभाषय SYMINFO_FLG_PASSTHRU	0x0002	/* Pass-thru symbol for translator */
#परिभाषय SYMINFO_FLG_COPY	0x0004	/* Symbol is a copy-reloc */
#परिभाषय SYMINFO_FLG_LAZYLOAD	0x0008	/* Symbol bound to object to be lazy
					   loaded */
/* Syminfo version values.  */
#परिभाषय SYMINFO_NONE		0
#परिभाषय SYMINFO_CURRENT		1
#परिभाषय SYMINFO_अङ्कः		2


/* How to extract and insert information held in the st_info field.  */

#परिभाषय ELF32_ST_BIND(val)		(((अचिह्नित वर्ण) (val)) >> 4)
#परिभाषय ELF32_ST_TYPE(val)		((val) & 0xf)
#परिभाषय ELF32_ST_INFO(bind, type)	(((bind) << 4) + ((type) & 0xf))

/* Both Elf32_Sym and Elf64_Sym use the same one-byte st_info field.  */
#परिभाषय ELF64_ST_BIND(val)		ELF32_ST_BIND (val)
#परिभाषय ELF64_ST_TYPE(val)		ELF32_ST_TYPE (val)
#परिभाषय ELF64_ST_INFO(bind, type)	ELF32_ST_INFO ((bind), (type))

/* Legal values for ST_BIND subfield of st_info (symbol binding).  */

#परिभाषय STB_LOCAL	0		/* Local symbol */
#परिभाषय STB_GLOBAL	1		/* Global symbol */
#परिभाषय STB_WEAK	2		/* Weak symbol */
#परिभाषय	STB_अङ्कः		3		/* Number of defined types.  */
#परिभाषय STB_LOOS	10		/* Start of OS-specific */
#परिभाषय STB_GNU_UNIQUE	10		/* Unique symbol.  */
#परिभाषय STB_HIOS	12		/* End of OS-specific */
#परिभाषय STB_LOPROC	13		/* Start of processor-specific */
#परिभाषय STB_HIPROC	15		/* End of processor-specific */

/* Legal values for ST_TYPE subfield of st_info (symbol type).  */

#परिभाषय STT_NOTYPE	0		/* Symbol type is unspecified */
#परिभाषय STT_OBJECT	1		/* Symbol is a data object */
#परिभाषय STT_FUNC	2		/* Symbol is a code object */
#परिभाषय STT_SECTION	3		/* Symbol associated with a section */
#परिभाषय STT_FILE	4		/* Symbol's name is file name */
#परिभाषय STT_COMMON	5		/* Symbol is a common data object */
#परिभाषय STT_TLS		6		/* Symbol is thread-local data object*/
#परिभाषय	STT_अङ्कः		7		/* Number of defined types.  */
#परिभाषय STT_LOOS	10		/* Start of OS-specific */
#परिभाषय STT_GNU_IFUNC	10		/* Symbol is indirect code object */
#परिभाषय STT_HIOS	12		/* End of OS-specific */
#परिभाषय STT_LOPROC	13		/* Start of processor-specific */
#परिभाषय STT_HIPROC	15		/* End of processor-specific */


/* Symbol table indices are found in the hash buckets and chain table
   of a symbol hash table section.  This special index value indicates
   the end of a chain, meaning no further symbols are found in that bucket.  */

#परिभाषय STN_UNDEF	0		/* End of a chain.  */


/* How to extract and insert information held in the st_other field.  */

#परिभाषय ELF32_ST_VISIBILITY(o)	((o) & 0x03)

/* For ELF64 the definitions are the same.  */
#परिभाषय ELF64_ST_VISIBILITY(o)	ELF32_ST_VISIBILITY (o)

/* Symbol visibility specification encoded in the st_other field.  */
#परिभाषय STV_DEFAULT	0		/* Default symbol visibility rules */
#परिभाषय STV_आन्तरिकम्	1		/* Processor specific hidden class */
#परिभाषय STV_HIDDEN	2		/* Sym unavailable in other modules */
#परिभाषय STV_PROTECTED	3		/* Not preemptible, not exported */


/* Relocation table entry without addend (in section of type SHT_REL).  */

प्रकारनिर्देश संरचना
{
  Elf32_Addr	r_विस्थापनम्;		/*स्थानाङ्कः*/
  Elf32_Word	r_info;			/* Relocation type and symbol index */
} Elf32_Rel;

/* I have seen two different definitions of the Elf64_Rel and
   Elf64_Rela structures, so we'll leave them out until Novell (or
   whoever) gets their act together.  */
/* The following, at least, is used on Sparc v9, MIPS, and Alpha.  */

प्रकारनिर्देश संरचना
{
  Elf64_Addr	r_विस्थापनम्;		/*स्थानाङ्कः*/
  Elf64_Xword	r_info;			/* Relocation type and symbol index */
} Elf64_Rel;

/* Relocation table entry with addend (in section of type SHT_RELA).  */

प्रकारनिर्देश संरचना
{
  Elf32_Addr	r_विस्थापनम्;		/*स्थानाङ्कः*/
  Elf32_Word	r_info;			/* Relocation type and symbol index */
  Elf32_Sword	r_addend;		/* Addend */
} Elf32_Rela;

प्रकारनिर्देश संरचना
{
  Elf64_Addr	r_विस्थापनम्;		/*स्थानाङ्कः*/
  Elf64_Xword	r_info;			/* Relocation type and symbol index */
  Elf64_Sxword	r_addend;		/* Addend */
} Elf64_Rela;

/* How to extract and insert information held in the r_info field.  */

#परिभाषय ELF32_R_SYM(val)		((val) >> 8)
#परिभाषय ELF32_R_TYPE(val)		((val) & 0xff)
#परिभाषय ELF32_R_INFO(sym, type)		(((sym) << 8) + ((type) & 0xff))

#परिभाषय ELF64_R_SYM(i)			((i) >> 32)
#परिभाषय ELF64_R_TYPE(i)			((i) & 0xffffffff)
#परिभाषय ELF64_R_INFO(sym,type)		((((Elf64_Xword) (sym)) << 32) + (type))

/* Program segment header.  */

प्रकारनिर्देश संरचना
{
  Elf32_Word	p_type;			/* Segment type */
  Elf32_Off	p_विस्थापनम्;		/* Segment file offset */
  Elf32_Addr	p_vaddr;		/* Segment virtual address */
  Elf32_Addr	p_paddr;		/* Segment physical address */
  Elf32_Word	p_filesz;		/* Segment size in file */
  Elf32_Word	p_memsz;		/* Segment size in memory */
  Elf32_Word	p_flags;		/* Segment flags */
  Elf32_Word	p_align;		/* Segment alignment */
} Elf32_Phdr;

प्रकारनिर्देश संरचना
{
  Elf64_Word	p_type;			/* Segment type */
  Elf64_Word	p_flags;		/* Segment flags */
  Elf64_Off	p_विस्थापनम्;		/* Segment file offset */
  Elf64_Addr	p_vaddr;		/* Segment virtual address */
  Elf64_Addr	p_paddr;		/* Segment physical address */
  Elf64_Xword	p_filesz;		/* Segment size in file */
  Elf64_Xword	p_memsz;		/* Segment size in memory */
  Elf64_Xword	p_align;		/* Segment alignment */
} Elf64_Phdr;

/* Special value for e_phnum.  This indicates that the real number of
   program headers is too large to fit into e_phnum.  Instead the real
   value is in the field sh_info of section 0.  */

#परिभाषय PN_XNUM		0xffff

/* Legal values for p_type (segment type).  */

#परिभाषय	PT_NULL		0		/* Program header table entry unused */
#परिभाषय PT_आरोपय		1		/* Loadable program segment */
#परिभाषय PT_DYNAMIC	2		/* Dynamic linking information */
#परिभाषय PT_INTERP	3		/* Program interpreter */
#परिभाषय PT_NOTE		4		/* Auxiliary information */
#परिभाषय PT_SHLIB	5		/* Reserved */
#परिभाषय PT_PHDR		6		/* Entry for header table itself */
#परिभाषय PT_TLS		7		/* Thread-local storage segment */
#परिभाषय	PT_अङ्कः		8		/* Number of defined types */
#परिभाषय PT_LOOS		0x60000000	/* Start of OS-specific */
#परिभाषय PT_GNU_EH_FRAME	0x6474e550	/* GCC .eh_frame_hdr segment */
#परिभाषय PT_GNU_राशिः	0x6474e551	/* Indicates stack executability */
#परिभाषय PT_GNU_RELRO	0x6474e552	/* Read-only after relocation */
#परिभाषय PT_LOSUNW	0x6ffffffa
#परिभाषय PT_SUNWBSS	0x6ffffffa	/* Sun Specific segment */
#परिभाषय PT_SUNWSTACK	0x6ffffffb	/* Stack segment */
#परिभाषय PT_HISUNW	0x6fffffff
#परिभाषय PT_HIOS		0x6fffffff	/* End of OS-specific */
#परिभाषय PT_LOPROC	0x70000000	/* Start of processor-specific */
#परिभाषय PT_HIPROC	0x7fffffff	/* End of processor-specific */

/* Legal values for p_flags (segment flags).  */

#परिभाषय PF_X		(1 << 0)	/* Segment is executable */
#परिभाषय PF_W		(1 << 1)	/* Segment is writable */
#परिभाषय PF_R		(1 << 2)	/* Segment is readable */
#परिभाषय PF_MASKOS	0x0ff00000	/* OS-specific */
#परिभाषय PF_MASKPROC	0xf0000000	/* Processor-specific */

/* Legal values for note segment descriptor types for core files. */

#परिभाषय NT_PRSTATUS	1		/* Contains copy of prstatus struct */
#परिभाषय NT_FPREGSET	2		/* Contains copy of fpregset struct */
#परिभाषय NT_PRPSINFO	3		/* Contains copy of prpsinfo struct */
#परिभाषय NT_PRXREG	4		/* Contains copy of prxregset struct */
#परिभाषय NT_TASKSTRUCT	4		/* Contains copy of task structure */
#परिभाषय NT_PLATFORM	5		/* String from sysinfo(SI_PLATFORM) */
#परिभाषय NT_AUXV		6		/* Contains copy of auxv array */
#परिभाषय NT_GWINDOWS	7		/* Contains copy of gwindows struct */
#परिभाषय NT_ASRS		8		/* Contains copy of asrset struct */
#परिभाषय NT_PSTATUS	10		/* Contains copy of pstatus struct */
#परिभाषय NT_PSINFO	13		/* Contains copy of psinfo struct */
#परिभाषय NT_PRCRED	14		/* Contains copy of prcred struct */
#परिभाषय NT_UTSNAME	15		/* Contains copy of utsname struct */
#परिभाषय NT_LWPSTATUS	16		/* Contains copy of lwpstatus struct */
#परिभाषय NT_LWPSINFO	17		/* Contains copy of lwpinfo struct */
#परिभाषय NT_PRFPXREG	20		/* Contains copy of fprxregset struct */
#परिभाषय NT_PRXFPREG	0x46e62b7f	/* Contains copy of user_fxsr_struct */
#परिभाषय NT_PPC_VMX	0x100		/* PowerPC Altivec/VMX registers */
#परिभाषय NT_PPC_SPE	0x101		/* PowerPC SPE/EVR registers */
#परिभाषय NT_PPC_VSX	0x102		/* PowerPC VSX registers */
#परिभाषय NT_386_TLS	0x200		/* i386 TLS slots (struct user_desc) */
#परिभाषय NT_386_IOPERM	0x201		/* x86 io permission bitmap (1=deny) */
#परिभाषय NT_X86_XSTATE	0x202		/* x86 extended state using xsave */
#परिभाषय NT_S390_उच्चः_GPRS	0x300	/* s390 upper register halves */
#परिभाषय NT_S390_TIMER	0x301		/* s390 timer register */
#परिभाषय NT_S390_TODCMP	0x302		/* s390 TOD clock comparator register */
#परिभाषय NT_S390_TODPREG	0x303		/* s390 TOD programmable register */
#परिभाषय NT_S390_CTRS	0x304		/* s390 control registers */
#परिभाषय NT_S390_उपसर्गः	0x305		/* s390 prefix register */
#परिभाषय NT_S390_चरमः_BREAK	0x306	/* s390 breaking event address */
#परिभाषय NT_S390_SYSTEM_CALL	0x307	/* s390 system call restart data */
#परिभाषय NT_ARM_VFP	0x400		/* ARM VFP/NEON registers */
#परिभाषय NT_ARM_TLS	0x401		/* ARM TLS register */
#परिभाषय NT_ARM_HW_BREAK	0x402		/* ARM hardware breakpoint registers */
#परिभाषय NT_ARM_HW_WATCH	0x403		/* ARM hardware watchpoint registers */

/* Legal values for the note segment descriptor types for object files.  */

#परिभाषय NT_संस्करणम्	1		/* Contains a version string.  */


/* Dynamic section entry.  */

प्रकारनिर्देश संरचना
{
  Elf32_Sword	d_चिह्नकम्;			/* Dynamic entry type */
  सङ्घ
    {
      Elf32_Word d_val;			/* Integer value */
      Elf32_Addr d_ptr;			/* Address value */
    } d_un;
} Elf32_Dyn;

प्रकारनिर्देश संरचना
{
  Elf64_Sxword	d_चिह्नकम्;			/* Dynamic entry type */
  सङ्घ
    {
      Elf64_Xword d_val;		/* Integer value */
      Elf64_Addr d_ptr;			/* Address value */
    } d_un;
} Elf64_Dyn;

/* Legal values for d_tag (dynamic entry type).  */

#परिभाषय DT_NULL		0		/* Marks end of dynamic section */
#परिभाषय DT_NEEDED	1		/* Name of needed library */
#परिभाषय DT_PLTRELSZ	2		/* Size in bytes of PLT relocs */
#परिभाषय DT_PLTGOT	3		/* Processor defined value */
#परिभाषय DT_HASH		4		/* Address of symbol hash table */
#परिभाषय DT_STRTAB	5		/* Address of string table */
#परिभाषय DT_SYMTAB	6		/* Address of symbol table */
#परिभाषय DT_RELA		7		/* Address of Rela relocs */
#परिभाषय DT_RELASZ	8		/* Total size of Rela relocs */
#परिभाषय DT_RELAENT	9		/* Size of one Rela reloc */
#परिभाषय DT_STRSZ	10		/* Size of string table */
#परिभाषय DT_SYMENT	11		/* Size of one symbol table entry */
#परिभाषय DT_INIT		12		/* Address of init function */
#परिभाषय DT_FINI		13		/* Address of termination function */
#परिभाषय DT_SONAME	14		/* Name of shared object */
#परिभाषय DT_RPATH	15		/* Library search path (deprecated) */
#परिभाषय DT_SYMBOLIC	16		/* Start symbol search here */
#परिभाषय DT_REL		17		/* Address of Rel relocs */
#परिभाषय DT_RELSZ	18		/* Total size of Rel relocs */
#परिभाषय DT_RELENT	19		/* Size of one Rel reloc */
#परिभाषय DT_PLTREL	20		/* Type of reloc in PLT */
#परिभाषय DT_DEBUG	21		/* For debugging; unspecified */
#परिभाषय DT_TEXTREL	22		/* Reloc might modify .text */
#परिभाषय DT_JMPREL	23		/* Address of PLT relocs */
#परिभाषय	DT_BIND_NOW	24		/* Process relocations of object */
#परिभाषय	DT_INIT_ARRAY	25		/* Array with addresses of init fct */
#परिभाषय	DT_FINI_ARRAY	26		/* Array with addresses of fini fct */
#परिभाषय	DT_INIT_ARRAYSZ	27		/* Size in bytes of DT_INIT_ARRAY */
#परिभाषय	DT_FINI_ARRAYSZ	28		/* Size in bytes of DT_FINI_ARRAY */
#परिभाषय DT_RUNPATH	29		/* Library search path */
#परिभाषय DT_FLAGS	30		/* Flags for the object being loaded */
#परिभाषय DT_ENCODING	32		/* Start of encoded range */
#परिभाषय DT_PREINIT_ARRAY 32		/* Array with addresses of preinit fct*/
#परिभाषय DT_PREINIT_ARRAYSZ 33		/* size in bytes of DT_PREINIT_ARRAY */
#परिभाषय	DT_अङ्कः		34		/* Number used */
#परिभाषय DT_LOOS		0x6000000d	/* Start of OS-specific */
#परिभाषय DT_HIOS		0x6ffff000	/* End of OS-specific */
#परिभाषय DT_LOPROC	0x70000000	/* Start of processor-specific */
#परिभाषय DT_HIPROC	0x7fffffff	/* End of processor-specific */
#परिभाषय	DT_PROCNUM	DT_MIPS_अङ्कः	/* Most used by any processor */

/* DT_* entries which fall between DT_VALRNGHI & DT_VALRNGLO use the
   Dyn.d_un.d_val field of the Elf*_Dyn structure.  This follows Sun's
   approach.  */
#परिभाषय DT_VALRNGLO	0x6ffffd00
#परिभाषय DT_GNU_PRELINKED 0x6ffffdf5	/* Prelinking timestamp */
#परिभाषय DT_GNU_CONFLICTSZ 0x6ffffdf6	/* Size of conflict section */
#परिभाषय DT_GNU_LIBLISTSZ 0x6ffffdf7	/* Size of library list */
#परिभाषय DT_CHECKSUM	0x6ffffdf8
#परिभाषय DT_PLTPADSZ	0x6ffffdf9
#परिभाषय DT_MOVEENT	0x6ffffdfa
#परिभाषय DT_MOVESZ	0x6ffffdfb
#परिभाषय DT_FEATURE_1	0x6ffffdfc	/* Feature selection (DTF_*).  */
#परिभाषय DT_POSFLAG_1	0x6ffffdfd	/* Flags for DT_* entries, effecting
					   the following DT_* entry.  */
#परिभाषय DT_SYMINSZ	0x6ffffdfe	/* Size of syminfo table (in bytes) */
#परिभाषय DT_SYMINENT	0x6ffffdff	/* Entry size of syminfo */
#परिभाषय DT_VALRNGHI	0x6ffffdff
#परिभाषय DT_VALTAGIDX(चिह्नकम्)	(DT_VALRNGHI - (चिह्नकम्))	/* Reverse order! */
#परिभाषय DT_VALNUM 12

/* DT_* entries which fall between DT_ADDRRNGHI & DT_ADDRRNGLO use the
   Dyn.d_un.d_ptr field of the Elf*_Dyn structure.

   If any adjustment is made to the ELF object after it has been
   built these entries will need to be adjusted.  */
#परिभाषय DT_ADDRRNGLO	0x6ffffe00
#परिभाषय DT_GNU_HASH	0x6ffffef5	/* GNU-style hash table.  */
#परिभाषय DT_TLSDESC_PLT	0x6ffffef6
#परिभाषय DT_TLSDESC_GOT	0x6ffffef7
#परिभाषय DT_GNU_CONFLICT	0x6ffffef8	/* Start of conflict section */
#परिभाषय DT_GNU_LIBLIST	0x6ffffef9	/* Library list */
#परिभाषय DT_CONFIG	0x6ffffefa	/* Configuration information.  */
#परिभाषय DT_DEPAUDIT	0x6ffffefb	/* Dependency auditing.  */
#परिभाषय DT_AUDIT	0x6ffffefc	/* Object auditing.  */
#परिभाषय	DT_PLTPAD	0x6ffffefd	/* PLT padding.  */
#परिभाषय	DT_MOVETAB	0x6ffffefe	/* Move table.  */
#परिभाषय DT_SYMINFO	0x6ffffeff	/* Syminfo table.  */
#परिभाषय DT_ADDRRNGHI	0x6ffffeff
#परिभाषय DT_ADDRTAGIDX(चिह्नकम्)	(DT_ADDRRNGHI - (चिह्नकम्))	/* Reverse order! */
#परिभाषय DT_ADDRNUM 11

/* The versioning entry types.  The next are defined as part of the
   GNU extension.  */
#परिभाषय DT_VERSYM	0x6ffffff0

#परिभाषय DT_RELACOUNT	0x6ffffff9
#परिभाषय DT_RELCOUNT	0x6ffffffa

/* These were chosen by Sun.  */
#परिभाषय DT_FLAGS_1	0x6ffffffb	/* State flags, see DF_1_* below.  */
#परिभाषय	DT_VERDEF	0x6ffffffc	/* Address of version definition
सारणी*/
#परिभाषय	DT_VERDEFNUM	0x6ffffffd	/* Number of version definitions */
#परिभाषय	DT_VERNEED	0x6ffffffe	/* Address of table with needed
					   versions */
#परिभाषय	DT_VERNEEDNUM	0x6fffffff	/* Number of needed versions */
#परिभाषय DT_VERSIONTAGIDX(चिह्नकम्)	(DT_VERNEEDNUM - (चिह्नकम्))	/* Reverse order! */
#परिभाषय DT_VERSIONTAGNUM 16

/* Sun added these machine-independent extensions in the "processor-specific"
   range.  Be compatible.  */
#परिभाषय DT_AUXILIARY    0x7ffffffd      /* Shared object to load before self */
#परिभाषय DT_FILTER       0x7fffffff      /* Shared object to get values from */
#परिभाषय DT_EXTRATAGIDX(चिह्नकम्)	((Elf32_Word)-((Elf32_Sword) (चिह्नकम्) <<1>>1)-1)
#परिभाषय DT_EXTRANUM	3

/* Values of `d_un.d_val' in the DT_FLAGS entry.  */
#परिभाषय DF_ORIGIN	0x00000001	/* Object may use DF_ORIGIN */
#परिभाषय DF_SYMBOLIC	0x00000002	/* Symbol resolutions starts here */
#परिभाषय DF_TEXTREL	0x00000004	/* Object contains text relocations */
#परिभाषय DF_BIND_NOW	0x00000008	/* No lazy binding for this object */
#परिभाषय DF_STATIC_TLS	0x00000010	/* Module uses the static TLS model */

/* State flags selectable in the `d_un.d_val' element of the DT_FLAGS_1
   entry in the dynamic section.  */
#परिभाषय DF_1_NOW	0x00000001	/* Set RTLD_NOW for this object.  */
#परिभाषय DF_1_GLOBAL	0x00000002	/* Set RTLD_GLOBAL for this object.  */
#परिभाषय DF_1_गणः	0x00000004	/* Set RTLD_GROUP for this object.  */
#परिभाषय DF_1_NODELETE	0x00000008	/* Set RTLD_NODELETE for this object.*/
#परिभाषय DF_1_LOADFLTR	0x00000010	/* Trigger filtee loading at runtime.*/
#परिभाषय DF_1_INITFIRST	0x00000020	/* Set RTLD_INITFIRST for this object*/
#परिभाषय DF_1_NOOPEN	0x00000040	/* Set RTLD_NOOPEN for this object.  */
#परिभाषय DF_1_ORIGIN	0x00000080	/* $ORIGIN must be handled.  */
#परिभाषय DF_1_प्रत्यक्षम्	0x00000100	/* Direct binding enabled.  */
#परिभाषय DF_1_TRANS	0x00000200
#परिभाषय DF_1_INTERPOSE	0x00000400	/* Object is used to interpose.  */
#परिभाषय DF_1_NODEFLIB	0x00000800	/* Ignore default lib search path.  */
#परिभाषय DF_1_NODUMP	0x00001000	/* Object can't be dldump'ed.  */
#परिभाषय DF_1_CONFALT	0x00002000	/* Configuration alternative created.*/
#परिभाषय DF_1_ENDFILTEE	0x00004000	/* Filtee terminates filters search. */
#परिभाषय	DF_1_DISPRELDNE	0x00008000	/* Disp reloc applied at build time. */
#परिभाषय	DF_1_DISPRELPND	0x00010000	/* Disp reloc applied at run-time.  */
#परिभाषय	DF_1_NODIRECT	0x00020000	/* Object has no-direct binding. */
#परिभाषय	DF_1_IGNMULDEF	0x00040000
#परिभाषय	DF_1_NOKSYMS	0x00080000
#परिभाषय	DF_1_NOHDR	0x00100000
#परिभाषय	DF_1_EDITED	0x00200000	/* Object is modified after built.  */
#परिभाषय	DF_1_NORELOC	0x00400000
#परिभाषय	DF_1_SYMINTPOSE	0x00800000	/* Object has individual interposers.  */
#परिभाषय	DF_1_GLOBAUDIT	0x01000000	/* Global auditing required.  */
#परिभाषय	DF_1_SINGLETON	0x02000000	/* Singleton symbols are used.  */
#परिभाषय	DF_1_PIE	0x08000000

/* Flags for the feature selection in DT_FEATURE_1.  */
#परिभाषय DTF_1_PARINIT	0x00000001
#परिभाषय DTF_1_CONFEXP	0x00000002

/* Flags in the DT_POSFLAG_1 entry effecting only the next DT_* entry.  */
#परिभाषय DF_P1_LAZYLOAD	0x00000001	/* Lazyload following object.  */
#परिभाषय DF_P1_GROUPPERM	0x00000002	/* Symbols from next object are not
					   generally available.  */

/* Version definition sections.  */

प्रकारनिर्देश संरचना
{
  Elf32_Half	vd_संस्करणम्;		/* Version revision */
  Elf32_Half	vd_flags;		/* Version information */
  Elf32_Half	vd_ndx;			/* Version Index */
  Elf32_Half	vd_cnt;			/* Number of associated aux entries */
  Elf32_Word	vd_hash;		/* Version name hash value */
  Elf32_Word	vd_aux;			/* Offset in bytes to verdaux array */
  Elf32_Word	vd_अग्र;		/* Offset in bytes to next verdef
प्रविष्टिः*/
} Elf32_Verdef;

प्रकारनिर्देश संरचना
{
  Elf64_Half	vd_संस्करणम्;		/* Version revision */
  Elf64_Half	vd_flags;		/* Version information */
  Elf64_Half	vd_ndx;			/* Version Index */
  Elf64_Half	vd_cnt;			/* Number of associated aux entries */
  Elf64_Word	vd_hash;		/* Version name hash value */
  Elf64_Word	vd_aux;			/* Offset in bytes to verdaux array */
  Elf64_Word	vd_अग्र;		/* Offset in bytes to next verdef
प्रविष्टिः*/
} Elf64_Verdef;


/* Legal values for vd_version (version revision).  */
#परिभाषय VER_DEF_NONE	0		/* No version */
#परिभाषय VER_DEF_CURRENT	1		/* Current version */
#परिभाषय VER_DEF_अङ्कः	2		/* Given version number */

/* Legal values for vd_flags (version information flags).  */
#परिभाषय VER_FLG_आधारः	0x1		/* Version definition of file itself */
#परिभाषय VER_FLG_WEAK	0x2		/* Weak version identifier */

/* Versym symbol index values.  */
#परिभाषय	VER_NDX_LOCAL		0	/* Symbol is local.  */
#परिभाषय	VER_NDX_GLOBAL		1	/* Symbol is global.  */
#परिभाषय	VER_NDX_LORESERVE	0xff00	/* Beginning of reserved entries.  */
#परिभाषय	VER_NDX_ELIMINATE	0xff01	/* Symbol is to be eliminated.  */

/* Auxiliary version information.  */

प्रकारनिर्देश संरचना
{
  Elf32_Word	vda_name;		/* Version or dependency names */
  Elf32_Word	vda_अग्र;		/* Offset in bytes to next verdaux
प्रविष्टिः*/
} Elf32_Verdaux;

प्रकारनिर्देश संरचना
{
  Elf64_Word	vda_name;		/* Version or dependency names */
  Elf64_Word	vda_अग्र;		/* Offset in bytes to next verdaux
प्रविष्टिः*/
} Elf64_Verdaux;


/* Version dependency section.  */

प्रकारनिर्देश संरचना
{
  Elf32_Half	vn_संस्करणम्;		/* Version of structure */
  Elf32_Half	vn_cnt;			/* Number of associated aux entries */
  Elf32_Word	vn_file;		/* Offset of filename for this
					   dependency */
  Elf32_Word	vn_aux;			/* Offset in bytes to vernaux array */
  Elf32_Word	vn_अग्र;		/* Offset in bytes to next verneed
प्रविष्टिः*/
} Elf32_Verneed;

प्रकारनिर्देश संरचना
{
  Elf64_Half	vn_संस्करणम्;		/* Version of structure */
  Elf64_Half	vn_cnt;			/* Number of associated aux entries */
  Elf64_Word	vn_file;		/* Offset of filename for this
					   dependency */
  Elf64_Word	vn_aux;			/* Offset in bytes to vernaux array */
  Elf64_Word	vn_अग्र;		/* Offset in bytes to next verneed
प्रविष्टिः*/
} Elf64_Verneed;


/* Legal values for vn_version (version revision).  */
#परिभाषय VER_NEED_NONE	 0		/* No version */
#परिभाषय VER_NEED_CURRENT 1		/* Current version */
#परिभाषय VER_NEED_अङ्कः	 2		/* Given version number */

/* Auxiliary needed version information.  */

प्रकारनिर्देश संरचना
{
  Elf32_Word	vna_hash;		/* Hash value of dependency name */
  Elf32_Half	vna_flags;		/* Dependency specific information */
  Elf32_Half	vna_other;		/* Unused */
  Elf32_Word	vna_name;		/* Dependency name string offset */
  Elf32_Word	vna_अग्र;		/* Offset in bytes to next vernaux
प्रविष्टिः*/
} Elf32_Vernaux;

प्रकारनिर्देश संरचना
{
  Elf64_Word	vna_hash;		/* Hash value of dependency name */
  Elf64_Half	vna_flags;		/* Dependency specific information */
  Elf64_Half	vna_other;		/* Unused */
  Elf64_Word	vna_name;		/* Dependency name string offset */
  Elf64_Word	vna_अग्र;		/* Offset in bytes to next vernaux
प्रविष्टिः*/
} Elf64_Vernaux;


/* Legal values for vna_flags.  */
#परिभाषय VER_FLG_WEAK	0x2		/* Weak version identifier */


/* Auxiliary vector.  */

/* This vector is normally only used by the program interpreter.  The
   usual definition in an ABI supplement uses the name auxv_t.  The
   vector is not usually defined in a standard <elf.h> file, but it
   can't hurt.  We rename it to avoid conflicts.  The sizes of these
   types are an arrangement between the exec server and the program
   interpreter, so we don't fully specify them here.  */

प्रकारनिर्देश संरचना
{
  uint32_t a_type;		/* Entry type */
  सङ्घ
    {
      uint32_t a_val;		/* Integer value */
      /* We use to have pointer elements added here.  We cannot do that,
	 though, since it does not work when using 32-bit definitions
	 on 64-bit platforms and vice versa.  */
    } a_un;
} Elf32_auxv_t;

प्रकारनिर्देश संरचना
{
  uint64_t a_type;		/* Entry type */
  सङ्घ
    {
      uint64_t a_val;		/* Integer value */
      /* We use to have pointer elements added here.  We cannot do that,
	 though, since it does not work when using 32-bit definitions
	 on 64-bit platforms and vice versa.  */
    } a_un;
} Elf64_auxv_t;

/* Legal values for a_type (entry type).  */

#परिभाषय AT_NULL		0		/* End of vector */
#परिभाषय AT_IGNORE	1		/* Entry should be ignored */
#परिभाषय AT_EXECFD	2		/* File descriptor of program */
#परिभाषय AT_PHDR		3		/* Program headers for program */
#परिभाषय AT_PHENT	4		/* Size of program header entry */
#परिभाषय AT_PHNUM	5		/* Number of program headers */
#परिभाषय AT_PAGESZ	6		/* System page size */
#परिभाषय AT_आधारः		7		/* Base address of interpreter */
#परिभाषय AT_FLAGS	8		/* Flags */
#परिभाषय AT_प्रविष्टिः	9		/* Entry point of program */
#परिभाषय AT_NOTELF	10		/* Program is not ELF */
#परिभाषय AT_UID		11		/* Real uid */
#परिभाषय AT_EUID		12		/* Effective uid */
#परिभाषय AT_GID		13		/* Real gid */
#परिभाषय AT_EGID		14		/* Effective gid */
#परिभाषय AT_CLKTCK	17		/* Frequency of times() */

/* Some more special a_type values describing the hardware.  */
#परिभाषय AT_PLATFORM	15		/* String identifying platform.  */
#परिभाषय AT_HWCAP	16		/* Machine dependent hints about
					   processor capabilities.  */

/* This entry gives some information about the FPU initialization
   performed by the kernel.  */
#परिभाषय AT_FPUCW	18		/* Used FPU control word.  */

/* Cache block sizes.  */
#परिभाषय AT_DCACHEBSIZE	19		/* Data cache block size.  */
#परिभाषय AT_ICACHEBSIZE	20		/* Instruction cache block size.  */
#परिभाषय AT_UCACHEBSIZE	21		/* Unified cache block size.  */

/* A special ignored value for PPC, used by the kernel to control the
   interpretation of the AUXV. Must be > 16.  */
#परिभाषय AT_IGNOREPPC	22		/* Entry should be ignored.  */

#परिभाषय	AT_SECURE	23		/* Boolean, was exec setuid-like?  */

#परिभाषय AT_आधारः_PLATFORM 24		/* String identifying real platforms.*/

#परिभाषय AT_RANDOM	25		/* Address of 16 random bytes.  */

#परिभाषय AT_EXECFN	31		/* Filename of executable.  */

/* Pointer to the global system page used for system calls and other
   nice things.  */
#परिभाषय AT_SYSINFO	32
#परिभाषय AT_SYSINFO_EHDR	33

/* Shapes of the caches.  Bits 0-3 contains associativity; bits 4-7 contains
   log2 of line size; mask those to get cache size.  */
#परिभाषय AT_L1I_CACHESHAPE	34
#परिभाषय AT_L1D_CACHESHAPE	35
#परिभाषय AT_L2_CACHESHAPE	36
#परिभाषय AT_L3_CACHESHAPE	37

/* Note section contents.  Each entry in the note section begins with
   a header of a fixed form.  */

प्रकारनिर्देश संरचना
{
  Elf32_Word n_namesz;			/* Length of the note's name.  */
  Elf32_Word n_descsz;			/* Length of the note's descriptor.  */
  Elf32_Word n_type;			/* Type of the note.  */
} Elf32_Nhdr;

प्रकारनिर्देश संरचना
{
  Elf64_Word n_namesz;			/* Length of the note's name.  */
  Elf64_Word n_descsz;			/* Length of the note's descriptor.  */
  Elf64_Word n_type;			/* Type of the note.  */
} Elf64_Nhdr;

/* Known names of notes.  */

/* Solaris entries in the note section have this name.  */
#परिभाषय ELF_NOTE_SOLARIS	"SUNW Solaris"

/* Note entries for GNU systems have this name.  */
#परिभाषय ELF_NOTE_GNU		"GNU"


/* Defined types of notes for Solaris.  */

/* Value of descriptor (one word) is desired pagesize for the binary.  */
#परिभाषय ELF_NOTE_PAGESIZE_HINT	1


/* Defined note types for GNU systems.  */

/* ABI information.  The descriptor consists of words:
   word 0: OS descriptor
   word 1: major version of the ABI
   word 2: minor version of the ABI
   word 3: subminor version of the ABI
*/
#परिभाषय NT_GNU_ABI_चिह्नकम्	1
#परिभाषय ELF_NOTE_ABI	NT_GNU_ABI_चिह्नकम् /* Old name.  */

/* Known OSes.  These values can appear in word 0 of an
   NT_GNU_ABI_TAG note section entry.  */
#परिभाषय ELF_NOTE_OS_LINUX	0
#परिभाषय ELF_NOTE_OS_GNU		1
#परिभाषय ELF_NOTE_OS_SOLARIS2	2
#परिभाषय ELF_NOTE_OS_FREEBSD	3

/* Synthetic hwcap information.  The descriptor begins with two words:
   word 0: number of entries
   word 1: bitmask of enabled entries
   Then follow variable-length entries, one byte followed by a
   '\0'-terminated hwcap name string.  The byte gives the bit
   number to test if enabled, (1U << bit) & bitmask.  */
#परिभाषय NT_GNU_HWCAP	2

/* Build ID bits as generated by ld --build-id.
   The descriptor consists of any nonzero number of bytes.  */
#परिभाषय NT_GNU_BUILD_ID	3

/* Version note generated by GNU gold containing a version string.  */
#परिभाषय NT_GNU_GOLD_संस्करणम्	4


/* Move records.  */
प्रकारनिर्देश संरचना
{
  Elf32_Xword m_मानम्;		/* Symbol value.  */
  Elf32_Word m_info;		/* Size and index.  */
  Elf32_Word m_poffset;		/* Symbol offset.  */
  Elf32_Half m_repeat;		/* Repeat count.  */
  Elf32_Half m_stride;		/* Stride info.  */
} Elf32_Move;

प्रकारनिर्देश संरचना
{
  Elf64_Xword m_मानम्;		/* Symbol value.  */
  Elf64_Xword m_info;		/* Size and index.  */
  Elf64_Xword m_poffset;	/* Symbol offset.  */
  Elf64_Half m_repeat;		/* Repeat count.  */
  Elf64_Half m_stride;		/* Stride info.  */
} Elf64_Move;

/* Macro to construct move records.  */
#परिभाषय ELF32_M_SYM(info)	((info) >> 8)
#परिभाषय ELF32_M_आकार(info)	((अचिह्नित वर्ण) (info))
#परिभाषय ELF32_M_INFO(sym, आकार)	(((sym) << 8) + (अचिह्नित वर्ण) (आकार))

#परिभाषय ELF64_M_SYM(info)	ELF32_M_SYM (info)
#परिभाषय ELF64_M_आकार(info)	ELF32_M_आकार (info)
#परिभाषय ELF64_M_INFO(sym, आकार)	ELF32_M_INFO (sym, आकार)


/* Motorola 68k specific definitions.  */

/* Values for Elf32_Ehdr.e_flags.  */
#परिभाषय EF_CPU32	0x00810000

/* m68k relocs.  */

#परिभाषय R_68K_NONE	0		/* No reloc */
#परिभाषय R_68K_32	1		/* Direct 32 bit  */
#परिभाषय R_68K_16	2		/* Direct 16 bit  */
#परिभाषय R_68K_8		3		/* Direct 8 bit  */
#परिभाषय R_68K_PC32	4		/* PC relative 32 bit */
#परिभाषय R_68K_PC16	5		/* PC relative 16 bit */
#परिभाषय R_68K_PC8	6		/* PC relative 8 bit */
#परिभाषय R_68K_GOT32	7		/* 32 bit PC relative GOT entry */
#परिभाषय R_68K_GOT16	8		/* 16 bit PC relative GOT entry */
#परिभाषय R_68K_GOT8	9		/* 8 bit PC relative GOT entry */
#परिभाषय R_68K_GOT32O	10		/* 32 bit GOT offset */
#परिभाषय R_68K_GOT16O	11		/* 16 bit GOT offset */
#परिभाषय R_68K_GOT8O	12		/* 8 bit GOT offset */
#परिभाषय R_68K_PLT32	13		/* 32 bit PC relative PLT address */
#परिभाषय R_68K_PLT16	14		/* 16 bit PC relative PLT address */
#परिभाषय R_68K_PLT8	15		/* 8 bit PC relative PLT address */
#परिभाषय R_68K_PLT32O	16		/* 32 bit PLT offset */
#परिभाषय R_68K_PLT16O	17		/* 16 bit PLT offset */
#परिभाषय R_68K_PLT8O	18		/* 8 bit PLT offset */
#परिभाषय R_68K_COPY	19		/* Copy symbol at runtime */
#परिभाषय R_68K_GLOB_DAT	20		/* Create GOT entry */
#परिभाषय R_68K_JMP_SLOT	21		/* Create PLT entry */
#परिभाषय R_68K_RELATIVE	22		/* Adjust by program base */
#परिभाषय R_68K_TLS_GD32      25          /* 32 bit GOT offset for GD */
#परिभाषय R_68K_TLS_GD16      26          /* 16 bit GOT offset for GD */
#परिभाषय R_68K_TLS_GD8       27          /* 8 bit GOT offset for GD */
#परिभाषय R_68K_TLS_LDM32     28          /* 32 bit GOT offset for LDM */
#परिभाषय R_68K_TLS_LDM16     29          /* 16 bit GOT offset for LDM */
#परिभाषय R_68K_TLS_LDM8      30          /* 8 bit GOT offset for LDM */
#परिभाषय R_68K_TLS_LDO32     31          /* 32 bit module-relative offset */
#परिभाषय R_68K_TLS_LDO16     32          /* 16 bit module-relative offset */
#परिभाषय R_68K_TLS_LDO8      33          /* 8 bit module-relative offset */
#परिभाषय R_68K_TLS_IE32      34          /* 32 bit GOT offset for IE */
#परिभाषय R_68K_TLS_IE16      35          /* 16 bit GOT offset for IE */
#परिभाषय R_68K_TLS_IE8       36          /* 8 bit GOT offset for IE */
#परिभाषय R_68K_TLS_LE32      37          /* 32 bit offset relative to
					   static TLS block */
#परिभाषय R_68K_TLS_LE16      38          /* 16 bit offset relative to
					   static TLS block */
#परिभाषय R_68K_TLS_LE8       39          /* 8 bit offset relative to
					   static TLS block */
#परिभाषय R_68K_TLS_DTPMOD32  40          /* 32 bit module number */
#परिभाषय R_68K_TLS_DTPREL32  41          /* 32 bit module-relative offset */
#परिभाषय R_68K_TLS_TPREL32   42          /* 32 bit TP-relative offset */
/* Keep this the last entry.  */
#परिभाषय R_68_K_अङ्कः	43

/* Intel 80386 specific definitions.  */

/* i386 relocs.  */

#परिभाषय R_386_NONE	   0		/* No reloc */
#परिभाषय R_386_32	   1		/* Direct 32 bit  */
#परिभाषय R_386_PC32	   2		/* PC relative 32 bit */
#परिभाषय R_386_GOT32	   3		/* 32 bit GOT entry */
#परिभाषय R_386_PLT32	   4		/* 32 bit PLT address */
#परिभाषय R_386_COPY	   5		/* Copy symbol at runtime */
#परिभाषय R_386_GLOB_DAT	   6		/* Create GOT entry */
#परिभाषय R_386_JMP_SLOT	   7		/* Create PLT entry */
#परिभाषय R_386_RELATIVE	   8		/* Adjust by program base */
#परिभाषय R_386_GOTOFF	   9		/* 32 bit offset to GOT */
#परिभाषय R_386_GOTPC	   10		/* 32 bit PC relative offset to GOT */
#परिभाषय R_386_32PLT	   11
#परिभाषय R_386_TLS_TPOFF	   14		/* Offset in static TLS block */
#परिभाषय R_386_TLS_IE	   15		/* Address of GOT entry for static TLS
					   block offset */
#परिभाषय R_386_TLS_GOTIE	   16		/* GOT entry for static TLS block
विस्थापनम्*/
#परिभाषय R_386_TLS_LE	   17		/* Offset relative to static TLS
खण्डम्*/
#परिभाषय R_386_TLS_GD	   18		/* Direct 32 bit for GNU version of
					   general dynamic thread local data */
#परिभाषय R_386_TLS_LDM	   19		/* Direct 32 bit for GNU version of
					   local dynamic thread local data
					   in LE code */
#परिभाषय R_386_16	   20
#परिभाषय R_386_PC16	   21
#परिभाषय R_386_8		   22
#परिभाषय R_386_PC8	   23
#परिभाषय R_386_TLS_GD_32	   24		/* Direct 32 bit for general dynamic
					   thread local data */
#परिभाषय R_386_TLS_GD_प्रक्षिप  25		/* Tag for pushl in GD TLS code */
#परिभाषय R_386_TLS_GD_CALL  26		/* Relocation for call to
					   __tls_get_addr() */
#परिभाषय R_386_TLS_GD_निष्कासय   27		/* Tag for popl in GD TLS code */
#परिभाषय R_386_TLS_LDM_32   28		/* Direct 32 bit for local dynamic
					   thread local data in LE code */
#परिभाषय R_386_TLS_LDM_प्रक्षिप 29		/* Tag for pushl in LDM TLS code */
#परिभाषय R_386_TLS_LDM_CALL 30		/* Relocation for call to
					   __tls_get_addr() in LDM code */
#परिभाषय R_386_TLS_LDM_निष्कासय  31		/* Tag for popl in LDM TLS code */
#परिभाषय R_386_TLS_LDO_32   32		/* Offset relative to TLS block */
#परिभाषय R_386_TLS_IE_32	   33		/* GOT entry for negated static TLS
					   block offset */
#परिभाषय R_386_TLS_LE_32	   34		/* Negated offset relative to static
					   TLS block */
#परिभाषय R_386_TLS_DTPMOD32 35		/* ID of module containing symbol */
#परिभाषय R_386_TLS_DTPOFF32 36		/* Offset in TLS block */
#परिभाषय R_386_TLS_TPOFF32  37		/* Negated offset in static TLS block */
/* 38? */
#परिभाषय R_386_TLS_GOTDESC  39		/* GOT offset for TLS descriptor.  */
#परिभाषय R_386_TLS_DESC_CALL 40		/* Marker of call through TLS
					   descriptor for
					   relaxation.  */
#परिभाषय R_386_TLS_DESC     41		/* TLS descriptor containing
					   pointer to code and to
					   argument, returning the TLS
					   offset for the symbol.  */
#परिभाषय R_386_IRELATIVE	   42		/* Adjust indirectly by program base */
#परिभाषय R_386_GOT32X       43		/* 32 bit GOT entry, relaxable */
/* Keep this the last entry.  */
#परिभाषय R_386_अङ्कः	   44

/* SUN SPARC specific definitions.  */

/* Legal values for ST_TYPE subfield of st_info (symbol type).  */

#परिभाषय STT_SPARC_पञ्जिकाकोशः	13	/* Global register reserved to app. */

/* Values for Elf64_Ehdr.e_flags.  */

#परिभाषय EF_SPARCV9_MM		3
#परिभाषय EF_SPARCV9_TSO		0
#परिभाषय EF_SPARCV9_PSO		1
#परिभाषय EF_SPARCV9_RMO		2
#परिभाषय EF_SPARC_LEDATA		0x800000 /* little endian data */
#परिभाषय EF_SPARC_EXT_आवरणम्	0xFFFF00
#परिभाषय EF_SPARC_32PLUS		0x000100 /* generic V8+ features */
#परिभाषय EF_SPARC_SUN_US1	0x000200 /* Sun UltraSPARC1 extensions */
#परिभाषय EF_SPARC_HAL_R1		0x000400 /* HAL R1 extensions */
#परिभाषय EF_SPARC_SUN_US3	0x000800 /* Sun UltraSPARCIII extensions */

/* SPARC relocs.  */

#परिभाषय R_SPARC_NONE		0	/* No reloc */
#परिभाषय R_SPARC_8		1	/* Direct 8 bit */
#परिभाषय R_SPARC_16		2	/* Direct 16 bit */
#परिभाषय R_SPARC_32		3	/* Direct 32 bit */
#परिभाषय R_SPARC_DISP8		4	/* PC relative 8 bit */
#परिभाषय R_SPARC_DISP16		5	/* PC relative 16 bit */
#परिभाषय R_SPARC_DISP32		6	/* PC relative 32 bit */
#परिभाषय R_SPARC_WDISP30		7	/* PC relative 30 bit shifted */
#परिभाषय R_SPARC_WDISP22		8	/* PC relative 22 bit shifted */
#परिभाषय R_SPARC_HI22		9	/* High 22 bit */
#परिभाषय R_SPARC_22		10	/* Direct 22 bit */
#परिभाषय R_SPARC_13		11	/* Direct 13 bit */
#परिभाषय R_SPARC_LO10		12	/* Truncated 10 bit */
#परिभाषय R_SPARC_GOT10		13	/* Truncated 10 bit GOT entry */
#परिभाषय R_SPARC_GOT13		14	/* 13 bit GOT entry */
#परिभाषय R_SPARC_GOT22		15	/* 22 bit GOT entry shifted */
#परिभाषय R_SPARC_PC10		16	/* PC relative 10 bit truncated */
#परिभाषय R_SPARC_PC22		17	/* PC relative 22 bit shifted */
#परिभाषय R_SPARC_WPLT30		18	/* 30 bit PC relative PLT address */
#परिभाषय R_SPARC_COPY		19	/* Copy symbol at runtime */
#परिभाषय R_SPARC_GLOB_DAT	20	/* Create GOT entry */
#परिभाषय R_SPARC_JMP_SLOT	21	/* Create PLT entry */
#परिभाषय R_SPARC_RELATIVE	22	/* Adjust by program base */
#परिभाषय R_SPARC_UA32		23	/* Direct 32 bit unaligned */

/* Additional Sparc64 relocs.  */

#परिभाषय R_SPARC_PLT32		24	/* Direct 32 bit ref to PLT entry */
#परिभाषय R_SPARC_HIPLT22		25	/* High 22 bit PLT entry */
#परिभाषय R_SPARC_LOPLT10		26	/* Truncated 10 bit PLT entry */
#परिभाषय R_SPARC_PCPLT32		27	/* PC rel 32 bit ref to PLT entry */
#परिभाषय R_SPARC_PCPLT22		28	/* PC rel high 22 bit PLT entry */
#परिभाषय R_SPARC_PCPLT10		29	/* PC rel trunc 10 bit PLT entry */
#परिभाषय R_SPARC_10		30	/* Direct 10 bit */
#परिभाषय R_SPARC_11		31	/* Direct 11 bit */
#परिभाषय R_SPARC_64		32	/* Direct 64 bit */
#परिभाषय R_SPARC_OLO10		33	/* 10bit with secondary 13bit addend */
#परिभाषय R_SPARC_HH22		34	/* Top 22 bits of direct 64 bit */
#परिभाषय R_SPARC_HM10		35	/* High middle 10 bits of ... */
#परिभाषय R_SPARC_LM22		36	/* Low middle 22 bits of ... */
#परिभाषय R_SPARC_PC_HH22		37	/* Top 22 bits of pc rel 64 bit */
#परिभाषय R_SPARC_PC_HM10		38	/* High middle 10 bit of ... */
#परिभाषय R_SPARC_PC_LM22		39	/* Low middle 22 bits of ... */
#परिभाषय R_SPARC_WDISP16		40	/* PC relative 16 bit shifted */
#परिभाषय R_SPARC_WDISP19		41	/* PC relative 19 bit shifted */
#परिभाषय R_SPARC_GLOB_JMP	42	/* was part of v9 ABI but was removed */
#परिभाषय R_SPARC_7		43	/* Direct 7 bit */
#परिभाषय R_SPARC_5		44	/* Direct 5 bit */
#परिभाषय R_SPARC_6		45	/* Direct 6 bit */
#परिभाषय R_SPARC_DISP64		46	/* PC relative 64 bit */
#परिभाषय R_SPARC_PLT64		47	/* Direct 64 bit ref to PLT entry */
#परिभाषय R_SPARC_HIX22		48	/* High 22 bit complemented */
#परिभाषय R_SPARC_LOX10		49	/* Truncated 11 bit complemented */
#परिभाषय R_SPARC_H44		50	/* Direct high 12 of 44 bit */
#परिभाषय R_SPARC_M44		51	/* Direct mid 22 of 44 bit */
#परिभाषय R_SPARC_L44		52	/* Direct low 10 of 44 bit */
#परिभाषय R_SPARC_पञ्जिकाकोशः	53	/* Global register usage */
#परिभाषय R_SPARC_UA64		54	/* Direct 64 bit unaligned */
#परिभाषय R_SPARC_UA16		55	/* Direct 16 bit unaligned */
#परिभाषय R_SPARC_TLS_GD_HI22	56
#परिभाषय R_SPARC_TLS_GD_LO10	57
#परिभाषय R_SPARC_TLS_GD_सङ्कलय	58
#परिभाषय R_SPARC_TLS_GD_CALL	59
#परिभाषय R_SPARC_TLS_LDM_HI22	60
#परिभाषय R_SPARC_TLS_LDM_LO10	61
#परिभाषय R_SPARC_TLS_LDM_सङ्कलय	62
#परिभाषय R_SPARC_TLS_LDM_CALL	63
#परिभाषय R_SPARC_TLS_LDO_HIX22	64
#परिभाषय R_SPARC_TLS_LDO_LOX10	65
#परिभाषय R_SPARC_TLS_LDO_सङ्कलय	66
#परिभाषय R_SPARC_TLS_IE_HI22	67
#परिभाषय R_SPARC_TLS_IE_LO10	68
#परिभाषय R_SPARC_TLS_IE_LD	69
#परिभाषय R_SPARC_TLS_IE_LDX	70
#परिभाषय R_SPARC_TLS_IE_सङ्कलय	71
#परिभाषय R_SPARC_TLS_LE_HIX22	72
#परिभाषय R_SPARC_TLS_LE_LOX10	73
#परिभाषय R_SPARC_TLS_DTPMOD32	74
#परिभाषय R_SPARC_TLS_DTPMOD64	75
#परिभाषय R_SPARC_TLS_DTPOFF32	76
#परिभाषय R_SPARC_TLS_DTPOFF64	77
#परिभाषय R_SPARC_TLS_TPOFF32	78
#परिभाषय R_SPARC_TLS_TPOFF64	79
#परिभाषय R_SPARC_GOTDATA_HIX22	80
#परिभाषय R_SPARC_GOTDATA_LOX10	81
#परिभाषय R_SPARC_GOTDATA_OP_HIX22	82
#परिभाषय R_SPARC_GOTDATA_OP_LOX10	83
#परिभाषय R_SPARC_GOTDATA_OP	84
#परिभाषय R_SPARC_H34		85
#परिभाषय R_SPARC_SIZE32		86
#परिभाषय R_SPARC_SIZE64		87
#परिभाषय R_SPARC_WDISP10		88
#परिभाषय R_SPARC_JMP_IREL	248
#परिभाषय R_SPARC_IRELATIVE	249
#परिभाषय R_SPARC_GNU_VTINHERIT	250
#परिभाषय R_SPARC_GNU_VTENTRY	251
#परिभाषय R_SPARC_REV32		252
/* Keep this the last entry.  */
#परिभाषय R_SPARC_अङ्कः		253

/* For Sparc64, legal values for d_tag of Elf64_Dyn.  */

#परिभाषय DT_SPARC_पञ्जिकाकोशः 0x70000001
#परिभाषय DT_SPARC_अङ्कः	2

/* MIPS R3000 specific definitions.  */

/* Legal values for e_flags field of Elf32_Ehdr.  */

#परिभाषय EF_MIPS_NOREORDER   1		/* A .noreorder directive was used */
#परिभाषय EF_MIPS_PIC	    2		/* Contains PIC code */
#परिभाषय EF_MIPS_CPIC	    4		/* Uses PIC calling sequence */
#परिभाषय EF_MIPS_XGOT	    8
#परिभाषय EF_MIPS_64BIT_WHIRL 16
#परिभाषय EF_MIPS_ABI2	    32
#परिभाषय EF_MIPS_ABI_ON32    64
#परिभाषय EF_MIPS_ARCH	    0xf0000000	/* MIPS architecture level */

/* Legal values for MIPS architecture level.  */

#परिभाषय EF_MIPS_ARCH_1	    0x00000000	/* -mips1 code.  */
#परिभाषय EF_MIPS_ARCH_2	    0x10000000	/* -mips2 code.  */
#परिभाषय EF_MIPS_ARCH_3	    0x20000000	/* -mips3 code.  */
#परिभाषय EF_MIPS_ARCH_4	    0x30000000	/* -mips4 code.  */
#परिभाषय EF_MIPS_ARCH_5	    0x40000000	/* -mips5 code.  */
#परिभाषय EF_MIPS_ARCH_32	    0x60000000	/* MIPS32 code.  */
#परिभाषय EF_MIPS_ARCH_64	    0x70000000	/* MIPS64 code.  */

/* The following are non-official names and should not be used.  */

#परिभाषय E_MIPS_ARCH_1	  0x00000000	/* -mips1 code.  */
#परिभाषय E_MIPS_ARCH_2	  0x10000000	/* -mips2 code.  */
#परिभाषय E_MIPS_ARCH_3	  0x20000000	/* -mips3 code.  */
#परिभाषय E_MIPS_ARCH_4	  0x30000000	/* -mips4 code.  */
#परिभाषय E_MIPS_ARCH_5	  0x40000000	/* -mips5 code.  */
#परिभाषय E_MIPS_ARCH_32	  0x60000000	/* MIPS32 code.  */
#परिभाषय E_MIPS_ARCH_64	  0x70000000	/* MIPS64 code.  */

/* Special section indices.  */

#परिभाषय SHN_MIPS_ACOMMON    0xff00	/* Allocated common symbols */
#परिभाषय SHN_MIPS_TEXT	    0xff01	/* Allocated test symbols.  */
#परिभाषय SHN_MIPS_दत्त	    0xff02	/* Allocated data symbols.  */
#परिभाषय SHN_MIPS_SCOMMON    0xff03	/* Small common symbols */
#परिभाषय SHN_MIPS_SUNDEFINED 0xff04	/* Small undefined symbols */

/* Legal values for sh_type field of Elf32_Shdr.  */

#परिभाषय SHT_MIPS_LIBLIST       0x70000000 /* Shared objects used in link */
#परिभाषय SHT_MIPS_MSYM	       0x70000001
#परिभाषय SHT_MIPS_CONFLICT      0x70000002 /* Conflicting symbols */
#परिभाषय SHT_MIPS_GPTAB	       0x70000003 /* Global data area sizes */
#परिभाषय SHT_MIPS_UCODE	       0x70000004 /* Reserved for SGI/MIPS compilers */
#परिभाषय SHT_MIPS_DEBUG	       0x70000005 /* MIPS ECOFF debugging information*/
#परिभाषय SHT_MIPS_REGINFO       0x70000006 /* Register usage information */
#परिभाषय SHT_MIPS_PACKAGE       0x70000007
#परिभाषय SHT_MIPS_PACKSYM       0x70000008
#परिभाषय SHT_MIPS_RELD	       0x70000009
#परिभाषय SHT_MIPS_IFACE         0x7000000b
#परिभाषय SHT_MIPS_CONTENT       0x7000000c
#परिभाषय SHT_MIPS_OPTIONS       0x7000000d /* Miscellaneous options.  */
#परिभाषय SHT_MIPS_SHDR	       0x70000010
#परिभाषय SHT_MIPS_FDESC	       0x70000011
#परिभाषय SHT_MIPS_EXTSYM	       0x70000012
#परिभाषय SHT_MIPS_DENSE	       0x70000013
#परिभाषय SHT_MIPS_PDESC	       0x70000014
#परिभाषय SHT_MIPS_LOCSYM	       0x70000015
#परिभाषय SHT_MIPS_AUXSYM	       0x70000016
#परिभाषय SHT_MIPS_OPTSYM	       0x70000017
#परिभाषय SHT_MIPS_LOCSTR	       0x70000018
#परिभाषय SHT_MIPS_पङ्क्तिः	       0x70000019
#परिभाषय SHT_MIPS_RFDESC	       0x7000001a
#परिभाषय SHT_MIPS_DELTASYM      0x7000001b
#परिभाषय SHT_MIPS_DELTAINST     0x7000001c
#परिभाषय SHT_MIPS_DELTACLASS    0x7000001d
#परिभाषय SHT_MIPS_DWARF         0x7000001e /* DWARF debugging information.  */
#परिभाषय SHT_MIPS_DELTADECL     0x7000001f
#परिभाषय SHT_MIPS_चिह्नम्_LIB    0x70000020
#परिभाषय SHT_MIPS_EVENTS	       0x70000021 /* Event section.  */
#परिभाषय SHT_MIPS_TRANSLATE     0x70000022
#परिभाषय SHT_MIPS_PIXIE	       0x70000023
#परिभाषय SHT_MIPS_XLATE	       0x70000024
#परिभाषय SHT_MIPS_XLATE_DEBUG   0x70000025
#परिभाषय SHT_MIPS_WHIRL	       0x70000026
#परिभाषय SHT_MIPS_EH_REGION     0x70000027
#परिभाषय SHT_MIPS_XLATE_OLD     0x70000028
#परिभाषय SHT_MIPS_PDR_EXCEPTION 0x70000029

/* Legal values for sh_flags field of Elf32_Shdr.  */

#परिभाषय SHF_MIPS_GPREL	 0x10000000	/* Must be part of global data area */
#परिभाषय SHF_MIPS_MERGE	 0x20000000
#परिभाषय SHF_MIPS_ADDR	 0x40000000
#परिभाषय SHF_MIPS_वाक्यानि 0x80000000
#परिभाषय SHF_MIPS_NOSTRIP 0x08000000
#परिभाषय SHF_MIPS_LOCAL	 0x04000000
#परिभाषय SHF_MIPS_नामानि	 0x02000000
#परिभाषय SHF_MIPS_NODUPE	 0x01000000


/* Symbol tables.  */

/* MIPS specific values for `st_other'.  */
#परिभाषय STO_MIPS_DEFAULT		0x0
#परिभाषय STO_MIPS_आन्तरिकम्		0x1
#परिभाषय STO_MIPS_HIDDEN			0x2
#परिभाषय STO_MIPS_PROTECTED		0x3
#परिभाषय STO_MIPS_PLT			0x8
#परिभाषय STO_MIPS_SC_ALIGN_अप्रयुक्तम्	0xff

/* MIPS specific values for `st_info'.  */
#परिभाषय STB_MIPS_विभज_COMMON		13

/* Entries found in sections of type SHT_MIPS_GPTAB.  */

प्रकारनिर्देश सङ्घ
{
  संरचना
    {
      Elf32_Word gt_current_g_मानम्;	/* -G value used for compilation */
      Elf32_Word gt_अप्रयुक्तम्;		/* Not used */
    } gt_शीर्षकम्;			/* First entry in section */
  संरचना
    {
      Elf32_Word gt_g_मानम्;		/* If this value were used for -G */
      Elf32_Word gt_अष्टकानि;		/* This many bytes would be used */
    } gt_प्रविष्टिः;				/* Subsequent entries in section */
} Elf32_gptab;

/* Entry found in sections of type SHT_MIPS_REGINFO.  */

प्रकारनिर्देश संरचना
{
  Elf32_Word	ri_gprmask;		/* General registers used */
  Elf32_Word	ri_cprmask[4];		/* Coprocessor registers used */
  Elf32_Sword	ri_gp_मानम्;		/* $gp register value */
} Elf32_RegInfo;

/* Entries found in sections of type SHT_MIPS_OPTIONS.  */

प्रकारनिर्देश संरचना
{
  अचिह्नित वर्ण विधा;		/* Determines interpretation of the
				   variable part of descriptor.  */
  अचिह्नित वर्ण आकार;		/* Size of descriptor, including header.  */
  Elf32_Section section;	/* Section header index of section affected,
				   0 for global options.  */
  Elf32_Word info;		/* Kind-specific information.  */
} Elf_Options;

/* Values for `kind' field in Elf_Options.  */

#परिभाषय ODK_NULL	0	/* Undefined.  */
#परिभाषय ODK_REGINFO	1	/* Register usage information.  */
#परिभाषय ODK_EXCEPTIONS	2	/* Exception processing options.  */
#परिभाषय ODK_PAD		3	/* Section padding options.  */
#परिभाषय ODK_HWPATCH	4	/* Hardware workarounds performed */
#परिभाषय ODK_FILL	5	/* record the fill value used by the linker. */
#परिभाषय ODK_चिह्नकानि	6	/* reserve space for desktop tools to write. */
#परिभाषय ODK_HWAND	7	/* HW workarounds.  'AND' bits when merging. */
#परिभाषय ODK_HWOR	8	/* HW workarounds.  'OR' bits when merging.  */

/* Values for `info' in Elf_Options for ODK_EXCEPTIONS entries.  */

#परिभाषय OEX_FPU_MIN	0x1f	/* FPE's which MUST be enabled.  */
#परिभाषय OEX_FPU_MAX	0x1f00	/* FPE's which MAY be enabled.  */
#परिभाषय OEX_PAGE0	0x10000	/* page zero must be mapped.  */
#परिभाषय OEX_SMM		0x20000	/* Force sequential memory mode?  */
#परिभाषय OEX_FPDBUG	0x40000	/* Force floating point debug mode?  */
#परिभाषय OEX_PRECISEFP	OEX_FPDBUG
#परिभाषय OEX_DISMISS	0x80000	/* Dismiss invalid address faults?  */

#परिभाषय OEX_FPU_INVAL	0x10
#परिभाषय OEX_FPU_DIV0	0x08
#परिभाषय OEX_FPU_OFLO	0x04
#परिभाषय OEX_FPU_UFLO	0x02
#परिभाषय OEX_FPU_INEX	0x01

/* Masks for `info' in Elf_Options for an ODK_HWPATCH entry.  */

#परिभाषय OHW_R4KEOP	0x1	/* R4000 end-of-page patch.  */
#परिभाषय OHW_R8KPFETCH	0x2	/* may need R8000 prefetch patch.  */
#परिभाषय OHW_R5KEOP	0x4	/* R5000 end-of-page patch.  */
#परिभाषय OHW_R5KCVTL	0x8	/* R5000 cvt.[ds].l bug.  clean=1.  */

#परिभाषय OPAD_उपसर्गः	0x1
#परिभाषय OPAD_POSTFIX	0x2
#परिभाषय OPAD_चिह्नम्	0x4

/* Entry found in `.options' section.  */

प्रकारनिर्देश संरचना
{
  Elf32_Word hwp_flags1;	/* Extra flags.  */
  Elf32_Word hwp_flags2;	/* Extra flags.  */
} Elf_Options_Hw;

/* Masks for `info' in ElfOptions for ODK_HWAND and ODK_HWOR entries.  */

#परिभाषय OHWA0_R4KEOP_CHECKED	0x00000001
#परिभाषय OHWA1_R4KEOP_CLEAN	0x00000002

/* MIPS relocs.  */

#परिभाषय R_MIPS_NONE		0	/* No reloc */
#परिभाषय R_MIPS_16		1	/* Direct 16 bit */
#परिभाषय R_MIPS_32		2	/* Direct 32 bit */
#परिभाषय R_MIPS_REL32		3	/* PC relative 32 bit */
#परिभाषय R_MIPS_26		4	/* Direct 26 bit shifted */
#परिभाषय R_MIPS_HI16		5	/* High 16 bit */
#परिभाषय R_MIPS_LO16		6	/* Low 16 bit */
#परिभाषय R_MIPS_GPREL16		7	/* GP relative 16 bit */
#परिभाषय R_MIPS_LITERAL		8	/* 16 bit literal entry */
#परिभाषय R_MIPS_GOT16		9	/* 16 bit GOT entry */
#परिभाषय R_MIPS_PC16		10	/* PC relative 16 bit */
#परिभाषय R_MIPS_CALL16		11	/* 16 bit GOT entry for function */
#परिभाषय R_MIPS_GPREL32		12	/* GP relative 32 bit */

#परिभाषय R_MIPS_SHIFT5		16
#परिभाषय R_MIPS_SHIFT6		17
#परिभाषय R_MIPS_64		18
#परिभाषय R_MIPS_GOT_DISP		19
#परिभाषय R_MIPS_GOT_PAGE		20
#परिभाषय R_MIPS_GOT_OFST		21
#परिभाषय R_MIPS_GOT_HI16		22
#परिभाषय R_MIPS_GOT_LO16		23
#परिभाषय R_MIPS_SUB		24
#परिभाषय R_MIPS_निवेशय_A		25
#परिभाषय R_MIPS_निवेशय_B		26
#परिभाषय R_MIPS_DELETE		27
#परिभाषय R_MIPS_HIGHER		28
#परिभाषय R_MIPS_HIGHEST		29
#परिभाषय R_MIPS_CALL_HI16	30
#परिभाषय R_MIPS_CALL_LO16	31
#परिभाषय R_MIPS_SCN_DISP		32
#परिभाषय R_MIPS_REL16		33
#परिभाषय R_MIPS_सङ्कलय_तात्कालिकम्	34
#परिभाषय R_MIPS_PJUMP		35
#परिभाषय R_MIPS_RELGOT		36
#परिभाषय R_MIPS_JALR		37
#परिभाषय R_MIPS_TLS_DTPMOD32	38	/* Module number 32 bit */
#परिभाषय R_MIPS_TLS_DTPREL32	39	/* Module-relative offset 32 bit */
#परिभाषय R_MIPS_TLS_DTPMOD64	40	/* Module number 64 bit */
#परिभाषय R_MIPS_TLS_DTPREL64	41	/* Module-relative offset 64 bit */
#परिभाषय R_MIPS_TLS_GD		42	/* 16 bit GOT offset for GD */
#परिभाषय R_MIPS_TLS_LDM		43	/* 16 bit GOT offset for LDM */
#परिभाषय R_MIPS_TLS_DTPREL_HI16	44	/* Module-relative offset, high 16 bits */
#परिभाषय R_MIPS_TLS_DTPREL_LO16	45	/* Module-relative offset, low 16 bits */
#परिभाषय R_MIPS_TLS_GOTTPREL	46	/* 16 bit GOT offset for IE */
#परिभाषय R_MIPS_TLS_TPREL32	47	/* TP-relative offset, 32 bit */
#परिभाषय R_MIPS_TLS_TPREL64	48	/* TP-relative offset, 64 bit */
#परिभाषय R_MIPS_TLS_TPREL_HI16	49	/* TP-relative offset, high 16 bits */
#परिभाषय R_MIPS_TLS_TPREL_LO16	50	/* TP-relative offset, low 16 bits */
#परिभाषय R_MIPS_GLOB_DAT		51
#परिभाषय R_MIPS_COPY		126
#परिभाषय R_MIPS_JUMP_SLOT        127
/* Keep this the last entry.  */
#परिभाषय R_MIPS_अङ्कः		128

/* Legal values for p_type field of Elf32_Phdr.  */

#परिभाषय PT_MIPS_REGINFO	0x70000000	/* Register usage information */
#परिभाषय PT_MIPS_RTPROC  0x70000001	/* Runtime procedure table. */
#परिभाषय PT_MIPS_OPTIONS 0x70000002

/* Special program header types.  */

#परिभाषय PF_MIPS_LOCAL	0x10000000

/* Legal values for d_tag field of Elf32_Dyn.  */

#परिभाषय DT_MIPS_RLD_संस्करणम्  0x70000001	/* Runtime linker interface version */
#परिभाषय DT_MIPS_TIME_STAMP   0x70000002	/* Timestamp */
#परिभाषय DT_MIPS_ICHECKSUM    0x70000003	/* Checksum */
#परिभाषय DT_MIPS_IVERSION     0x70000004	/* Version string (string tbl index) */
#परिभाषय DT_MIPS_FLAGS	     0x70000005	/* Flags */
#परिभाषय DT_MIPS_आधारः_स्थानाङ्कः 0x70000006	/* Base address */
#परिभाषय DT_MIPS_MSYM	     0x70000007
#परिभाषय DT_MIPS_CONFLICT     0x70000008	/* Address of CONFLICT section */
#परिभाषय DT_MIPS_LIBLIST	     0x70000009	/* Address of LIBLIST section */
#परिभाषय DT_MIPS_LOCAL_GOTNO  0x7000000a	/* Number of local GOT entries */
#परिभाषय DT_MIPS_CONFLICTNO   0x7000000b	/* Number of CONFLICT entries */
#परिभाषय DT_MIPS_LIBLISTNO    0x70000010	/* Number of LIBLIST entries */
#परिभाषय DT_MIPS_SYMTABNO     0x70000011	/* Number of DYNSYM entries */
#परिभाषय DT_MIPS_UNREFEXTNO   0x70000012	/* First external DYNSYM */
#परिभाषय DT_MIPS_GOTSYM	     0x70000013	/* First GOT entry in DYNSYM */
#परिभाषय DT_MIPS_HIPAGENO     0x70000014	/* Number of GOT page table entries */
#परिभाषय DT_MIPS_RLD_MAP	     0x70000016	/* Address of run time loader map.  */
#परिभाषय DT_MIPS_DELTA_CLASS  0x70000017	/* Delta C++ class definition.  */
#परिभाषय DT_MIPS_DELTA_CLASS_NO    0x70000018 /* Number of entries in
						DT_MIPS_DELTA_CLASS.  */
#परिभाषय DT_MIPS_DELTA_INSTANCE    0x70000019 /* Delta C++ class instances.  */
#परिभाषय DT_MIPS_DELTA_INSTANCE_NO 0x7000001a /* Number of entries in
						DT_MIPS_DELTA_INSTANCE.  */
#परिभाषय DT_MIPS_DELTA_RELOC  0x7000001b /* Delta relocations.  */
#परिभाषय DT_MIPS_DELTA_RELOC_NO 0x7000001c /* Number of entries in
					     DT_MIPS_DELTA_RELOC.  */
#परिभाषय DT_MIPS_DELTA_SYM    0x7000001d /* Delta symbols that Delta
					   relocations refer to.  */
#परिभाषय DT_MIPS_DELTA_SYM_NO 0x7000001e /* Number of entries in
					   DT_MIPS_DELTA_SYM.  */
#परिभाषय DT_MIPS_DELTA_CLASSSYM 0x70000020 /* Delta symbols that hold the
					     class declaration.  */
#परिभाषय DT_MIPS_DELTA_CLASSSYM_NO 0x70000021 /* Number of entries in
						DT_MIPS_DELTA_CLASSSYM.  */
#परिभाषय DT_MIPS_CXX_FLAGS    0x70000022 /* Flags indicating for C++ flavor.  */
#परिभाषय DT_MIPS_PIXIE_INIT   0x70000023
#परिभाषय DT_MIPS_चिह्नम्_LIB   0x70000024
#परिभाषय DT_MIPS_LOCALPAGE_GOTIDX 0x70000025
#परिभाषय DT_MIPS_LOCAL_GOTIDX 0x70000026
#परिभाषय DT_MIPS_HIDDEN_GOTIDX 0x70000027
#परिभाषय DT_MIPS_PROTECTED_GOTIDX 0x70000028
#परिभाषय DT_MIPS_OPTIONS	     0x70000029 /* Address of .options.  */
#परिभाषय DT_MIPS_INTERFACE    0x7000002a /* Address of .interface.  */
#परिभाषय DT_MIPS_DYNSTR_ALIGN 0x7000002b
#परिभाषय DT_MIPS_INTERFACE_आकार 0x7000002c /* Size of the .interface section. */
#परिभाषय DT_MIPS_RLD_TEXT_RESOLVE_ADDR 0x7000002d /* Address of rld_text_rsolve
						    function stored in GOT.  */
#परिभाषय DT_MIPS_PERF_SUFFIX  0x7000002e /* Default suffix of dso to be added
					   by rld on dlopen() calls.  */
#परिभाषय DT_MIPS_COMPACT_आकार 0x7000002f /* (O32)Size of compact rel section. */
#परिभाषय DT_MIPS_GP_मानम्     0x70000030 /* GP value for aux GOTs.  */
#परिभाषय DT_MIPS_AUX_DYNAMIC  0x70000031 /* Address of aux .dynamic.  */
/* The address of .got.plt in an executable using the new non-PIC ABI.  */
#परिभाषय DT_MIPS_PLTGOT	     0x70000032
/* The base of the PLT in an executable using the new non-PIC ABI if that
   PLT is writable.  For a non-writable PLT, this is omitted or has a zero
   value.  */
#परिभाषय DT_MIPS_RWPLT        0x70000034
#परिभाषय DT_MIPS_अङ्कः	     0x35

/* Legal values for DT_MIPS_FLAGS Elf32_Dyn entry.  */

#परिभाषय RHF_NONE		   0		/* No flags */
#परिभाषय RHF_QUICKSTART		   (1 << 0)	/* Use quickstart */
#परिभाषय RHF_NOTPOT		   (1 << 1)	/* Hash size not power of 2 */
#परिभाषय RHF_NO_LIBRARY_REPLACEMENT (1 << 2)	/* Ignore LD_LIBRARY_PATH */
#परिभाषय RHF_NO_MOVE		   (1 << 3)
#परिभाषय RHF_SGI_ONLY		   (1 << 4)
#परिभाषय RHF_GUARANTEE_INIT	   (1 << 5)
#परिभाषय RHF_DELTA_C_PLUS_PLUS	   (1 << 6)
#परिभाषय RHF_GUARANTEE_START_INIT   (1 << 7)
#परिभाषय RHF_PIXIE		   (1 << 8)
#परिभाषय RHF_DEFAULT_DELAY_आरोपय	   (1 << 9)
#परिभाषय RHF_REQUICKSTART	   (1 << 10)
#परिभाषय RHF_REQUICKSTARTED	   (1 << 11)
#परिभाषय RHF_CORD		   (1 << 12)
#परिभाषय RHF_NO_UNRES_UNDEF	   (1 << 13)
#परिभाषय RHF_RLD_क्रमः_SAFE	   (1 << 14)

/* Entries found in sections of type SHT_MIPS_LIBLIST.  */

प्रकारनिर्देश संरचना
{
  Elf32_Word l_name;		/* Name (string table index) */
  Elf32_Word l_time_stamp;	/* Timestamp */
  Elf32_Word l_checksum;	/* Checksum */
  Elf32_Word l_संस्करणम्;		/* Interface version */
  Elf32_Word l_flags;		/* Flags */
} Elf32_Lib;

प्रकारनिर्देश संरचना
{
  Elf64_Word l_name;		/* Name (string table index) */
  Elf64_Word l_time_stamp;	/* Timestamp */
  Elf64_Word l_checksum;	/* Checksum */
  Elf64_Word l_संस्करणम्;		/* Interface version */
  Elf64_Word l_flags;		/* Flags */
} Elf64_Lib;


/* Legal values for l_flags.  */

#परिभाषय LL_NONE		  0
#परिभाषय LL_EXACT_मेलनम्	  (1 << 0)	/* Require exact match */
#परिभाषय LL_IGNORE_INT_VER (1 << 1)	/* Ignore interface version */
#परिभाषय LL_REQUIRE_MINOR  (1 << 2)
#परिभाषय LL_EXPORTS	  (1 << 3)
#परिभाषय LL_DELAY_आरोपय	  (1 << 4)
#परिभाषय LL_DELTA	  (1 << 5)

/* Entries found in sections of type SHT_MIPS_CONFLICT.  */

प्रकारनिर्देश Elf32_Addr Elf32_Conflict;


/* HPPA specific definitions.  */

/* Legal values for e_flags field of Elf32_Ehdr.  */

#परिभाषय EF_PARISC_TRAPNIL	0x00010000 /* Trap nil pointer dereference.  */
#परिभाषय EF_PARISC_EXT		0x00020000 /* Program uses arch. extensions. */
#परिभाषय EF_PARISC_LSB		0x00040000 /* Program expects little endian. */
#परिभाषय EF_PARISC_WIDE		0x00080000 /* Program expects wide mode.  */
#परिभाषय EF_PARISC_NO_KABP	0x00100000 /* No kernel assisted branch
					      prediction.  */
#परिभाषय EF_PARISC_LAZYSWAP	0x00400000 /* Allow lazy swapping.  */
#परिभाषय EF_PARISC_ARCH		0x0000ffff /* Architecture version.  */

/* Defined values for `e_flags & EF_PARISC_ARCH' are:  */

#परिभाषय EFA_PARISC_1_0		    0x020b /* PA-RISC 1.0 big-endian.  */
#परिभाषय EFA_PARISC_1_1		    0x0210 /* PA-RISC 1.1 big-endian.  */
#परिभाषय EFA_PARISC_2_0		    0x0214 /* PA-RISC 2.0 big-endian.  */

/* Additional section indices.  */

#परिभाषय SHN_PARISC_ANSI_COMMON	0xff00	   /* Section for tentatively declared
					      symbols in ANSI C.  */
#परिभाषय SHN_PARISC_HUGE_COMMON	0xff01	   /* Common blocks in huge model.  */

/* Legal values for sh_type field of Elf32_Shdr.  */

#परिभाषय SHT_PARISC_EXT		0x70000000 /* Contains product specific ext. */
#परिभाषय SHT_PARISC_UNWIND	0x70000001 /* Unwind information.  */
#परिभाषय SHT_PARISC_DOC		0x70000002 /* Debug info for optimized code. */

/* Legal values for sh_flags field of Elf32_Shdr.  */

#परिभाषय SHF_PARISC_SHORT	0x20000000 /* Section with short addressing. */
#परिभाषय SHF_PARISC_HUGE		0x40000000 /* Section far from gp.  */
#परिभाषय SHF_PARISC_SBP		0x80000000 /* Static branch prediction code. */

/* Legal values for ST_TYPE subfield of st_info (symbol type).  */

#परिभाषय STT_PARISC_MILLICODE	13	/* Millicode function entry point.  */

#परिभाषय STT_HP_OPAQUE		(STT_LOOS + 0x1)
#परिभाषय STT_HP_STUB		(STT_LOOS + 0x2)

/* HPPA relocs.  */

#परिभाषय R_PARISC_NONE		0	/* No reloc.  */
#परिभाषय R_PARISC_DIR32		1	/* Direct 32-bit reference.  */
#परिभाषय R_PARISC_DIR21L		2	/* Left 21 bits of eff. address.  */
#परिभाषय R_PARISC_DIR17R		3	/* Right 17 bits of eff. address.  */
#परिभाषय R_PARISC_DIR17F		4	/* 17 bits of eff. address.  */
#परिभाषय R_PARISC_DIR14R		6	/* Right 14 bits of eff. address.  */
#परिभाषय R_PARISC_PCREL32	9	/* 32-bit rel. address.  */
#परिभाषय R_PARISC_PCREL21L	10	/* Left 21 bits of rel. address.  */
#परिभाषय R_PARISC_PCREL17R	11	/* Right 17 bits of rel. address.  */
#परिभाषय R_PARISC_PCREL17F	12	/* 17 bits of rel. address.  */
#परिभाषय R_PARISC_PCREL14R	14	/* Right 14 bits of rel. address.  */
#परिभाषय R_PARISC_DPREL21L	18	/* Left 21 bits of rel. address.  */
#परिभाषय R_PARISC_DPREL14R	22	/* Right 14 bits of rel. address.  */
#परिभाषय R_PARISC_GPREL21L	26	/* GP-relative, left 21 bits.  */
#परिभाषय R_PARISC_GPREL14R	30	/* GP-relative, right 14 bits.  */
#परिभाषय R_PARISC_LTOFF21L	34	/* LT-relative, left 21 bits.  */
#परिभाषय R_PARISC_LTOFF14R	38	/* LT-relative, right 14 bits.  */
#परिभाषय R_PARISC_SECREL32	41	/* 32 bits section rel. address.  */
#परिभाषय R_PARISC_SEGBASE	48	/* No relocation, set segment base.  */
#परिभाषय R_PARISC_SEGREL32	49	/* 32 bits segment rel. address.  */
#परिभाषय R_PARISC_PLTOFF21L	50	/* PLT rel. address, left 21 bits.  */
#परिभाषय R_PARISC_PLTOFF14R	54	/* PLT rel. address, right 14 bits.  */
#परिभाषय R_PARISC_LTOFF_FPTR32	57	/* 32 bits LT-rel. function pointer. */
#परिभाषय R_PARISC_LTOFF_FPTR21L	58	/* LT-rel. fct ptr, left 21 bits. */
#परिभाषय R_PARISC_LTOFF_FPTR14R	62	/* LT-rel. fct ptr, right 14 bits. */
#परिभाषय R_PARISC_FPTR64		64	/* 64 bits function address.  */
#परिभाषय R_PARISC_PLABEL32	65	/* 32 bits function address.  */
#परिभाषय R_PARISC_PLABEL21L	66	/* Left 21 bits of fdesc address.  */
#परिभाषय R_PARISC_PLABEL14R	70	/* Right 14 bits of fdesc address.  */
#परिभाषय R_PARISC_PCREL64	72	/* 64 bits PC-rel. address.  */
#परिभाषय R_PARISC_PCREL22F	74	/* 22 bits PC-rel. address.  */
#परिभाषय R_PARISC_PCREL14WR	75	/* PC-rel. address, right 14 bits.  */
#परिभाषय R_PARISC_PCREL14DR	76	/* PC rel. address, right 14 bits.  */
#परिभाषय R_PARISC_PCREL16F	77	/* 16 bits PC-rel. address.  */
#परिभाषय R_PARISC_PCREL16WF	78	/* 16 bits PC-rel. address.  */
#परिभाषय R_PARISC_PCREL16DF	79	/* 16 bits PC-rel. address.  */
#परिभाषय R_PARISC_DIR64		80	/* 64 bits of eff. address.  */
#परिभाषय R_PARISC_DIR14WR	83	/* 14 bits of eff. address.  */
#परिभाषय R_PARISC_DIR14DR	84	/* 14 bits of eff. address.  */
#परिभाषय R_PARISC_DIR16F		85	/* 16 bits of eff. address.  */
#परिभाषय R_PARISC_DIR16WF	86	/* 16 bits of eff. address.  */
#परिभाषय R_PARISC_DIR16DF	87	/* 16 bits of eff. address.  */
#परिभाषय R_PARISC_GPREL64	88	/* 64 bits of GP-rel. address.  */
#परिभाषय R_PARISC_GPREL14WR	91	/* GP-rel. address, right 14 bits.  */
#परिभाषय R_PARISC_GPREL14DR	92	/* GP-rel. address, right 14 bits.  */
#परिभाषय R_PARISC_GPREL16F	93	/* 16 bits GP-rel. address.  */
#परिभाषय R_PARISC_GPREL16WF	94	/* 16 bits GP-rel. address.  */
#परिभाषय R_PARISC_GPREL16DF	95	/* 16 bits GP-rel. address.  */
#परिभाषय R_PARISC_LTOFF64	96	/* 64 bits LT-rel. address.  */
#परिभाषय R_PARISC_LTOFF14WR	99	/* LT-rel. address, right 14 bits.  */
#परिभाषय R_PARISC_LTOFF14DR	100	/* LT-rel. address, right 14 bits.  */
#परिभाषय R_PARISC_LTOFF16F	101	/* 16 bits LT-rel. address.  */
#परिभाषय R_PARISC_LTOFF16WF	102	/* 16 bits LT-rel. address.  */
#परिभाषय R_PARISC_LTOFF16DF	103	/* 16 bits LT-rel. address.  */
#परिभाषय R_PARISC_SECREL64	104	/* 64 bits section rel. address.  */
#परिभाषय R_PARISC_SEGREL64	112	/* 64 bits segment rel. address.  */
#परिभाषय R_PARISC_PLTOFF14WR	115	/* PLT-rel. address, right 14 bits.  */
#परिभाषय R_PARISC_PLTOFF14DR	116	/* PLT-rel. address, right 14 bits.  */
#परिभाषय R_PARISC_PLTOFF16F	117	/* 16 bits LT-rel. address.  */
#परिभाषय R_PARISC_PLTOFF16WF	118	/* 16 bits PLT-rel. address.  */
#परिभाषय R_PARISC_PLTOFF16DF	119	/* 16 bits PLT-rel. address.  */
#परिभाषय R_PARISC_LTOFF_FPTR64	120	/* 64 bits LT-rel. function ptr.  */
#परिभाषय R_PARISC_LTOFF_FPTR14WR	123	/* LT-rel. fct. ptr., right 14 bits. */
#परिभाषय R_PARISC_LTOFF_FPTR14DR	124	/* LT-rel. fct. ptr., right 14 bits. */
#परिभाषय R_PARISC_LTOFF_FPTR16F	125	/* 16 bits LT-rel. function ptr.  */
#परिभाषय R_PARISC_LTOFF_FPTR16WF	126	/* 16 bits LT-rel. function ptr.  */
#परिभाषय R_PARISC_LTOFF_FPTR16DF	127	/* 16 bits LT-rel. function ptr.  */
#परिभाषय R_PARISC_LORESERVE	128
#परिभाषय R_PARISC_COPY		128	/* Copy relocation.  */
#परिभाषय R_PARISC_IPLT		129	/* Dynamic reloc, imported PLT */
#परिभाषय R_PARISC_EPLT		130	/* Dynamic reloc, exported PLT */
#परिभाषय R_PARISC_TPREL32	153	/* 32 bits TP-rel. address.  */
#परिभाषय R_PARISC_TPREL21L	154	/* TP-rel. address, left 21 bits.  */
#परिभाषय R_PARISC_TPREL14R	158	/* TP-rel. address, right 14 bits.  */
#परिभाषय R_PARISC_LTOFF_TP21L	162	/* LT-TP-rel. address, left 21 bits. */
#परिभाषय R_PARISC_LTOFF_TP14R	166	/* LT-TP-rel. address, right 14 bits.*/
#परिभाषय R_PARISC_LTOFF_TP14F	167	/* 14 bits LT-TP-rel. address.  */
#परिभाषय R_PARISC_TPREL64	216	/* 64 bits TP-rel. address.  */
#परिभाषय R_PARISC_TPREL14WR	219	/* TP-rel. address, right 14 bits.  */
#परिभाषय R_PARISC_TPREL14DR	220	/* TP-rel. address, right 14 bits.  */
#परिभाषय R_PARISC_TPREL16F	221	/* 16 bits TP-rel. address.  */
#परिभाषय R_PARISC_TPREL16WF	222	/* 16 bits TP-rel. address.  */
#परिभाषय R_PARISC_TPREL16DF	223	/* 16 bits TP-rel. address.  */
#परिभाषय R_PARISC_LTOFF_TP64	224	/* 64 bits LT-TP-rel. address.  */
#परिभाषय R_PARISC_LTOFF_TP14WR	227	/* LT-TP-rel. address, right 14 bits.*/
#परिभाषय R_PARISC_LTOFF_TP14DR	228	/* LT-TP-rel. address, right 14 bits.*/
#परिभाषय R_PARISC_LTOFF_TP16F	229	/* 16 bits LT-TP-rel. address.  */
#परिभाषय R_PARISC_LTOFF_TP16WF	230	/* 16 bits LT-TP-rel. address.  */
#परिभाषय R_PARISC_LTOFF_TP16DF	231	/* 16 bits LT-TP-rel. address.  */
#परिभाषय R_PARISC_GNU_VTENTRY	232
#परिभाषय R_PARISC_GNU_VTINHERIT	233
#परिभाषय R_PARISC_TLS_GD21L	234	/* GD 21-bit left.  */
#परिभाषय R_PARISC_TLS_GD14R	235	/* GD 14-bit right.  */
#परिभाषय R_PARISC_TLS_GDCALL	236	/* GD call to __t_g_a.  */
#परिभाषय R_PARISC_TLS_LDM21L	237	/* LD module 21-bit left.  */
#परिभाषय R_PARISC_TLS_LDM14R	238	/* LD module 14-bit right.  */
#परिभाषय R_PARISC_TLS_LDMCALL	239	/* LD module call to __t_g_a.  */
#परिभाषय R_PARISC_TLS_LDO21L	240	/* LD offset 21-bit left.  */
#परिभाषय R_PARISC_TLS_LDO14R	241	/* LD offset 14-bit right.  */
#परिभाषय R_PARISC_TLS_DTPMOD32	242	/* DTP module 32-bit.  */
#परिभाषय R_PARISC_TLS_DTPMOD64	243	/* DTP module 64-bit.  */
#परिभाषय R_PARISC_TLS_DTPOFF32	244	/* DTP offset 32-bit.  */
#परिभाषय R_PARISC_TLS_DTPOFF64	245	/* DTP offset 32-bit.  */
#परिभाषय R_PARISC_TLS_LE21L	R_PARISC_TPREL21L
#परिभाषय R_PARISC_TLS_LE14R	R_PARISC_TPREL14R
#परिभाषय R_PARISC_TLS_IE21L	R_PARISC_LTOFF_TP21L
#परिभाषय R_PARISC_TLS_IE14R	R_PARISC_LTOFF_TP14R
#परिभाषय R_PARISC_TLS_TPREL32	R_PARISC_TPREL32
#परिभाषय R_PARISC_TLS_TPREL64	R_PARISC_TPREL64
#परिभाषय R_PARISC_HIRESERVE	255

/* Legal values for p_type field of Elf32_Phdr/Elf64_Phdr.  */

#परिभाषय PT_HP_TLS		(PT_LOOS + 0x0)
#परिभाषय PT_HP_CORE_NONE		(PT_LOOS + 0x1)
#परिभाषय PT_HP_CORE_संस्करणम्	(PT_LOOS + 0x2)
#परिभाषय PT_HP_CORE_KERNEL	(PT_LOOS + 0x3)
#परिभाषय PT_HP_CORE_COMM		(PT_LOOS + 0x4)
#परिभाषय PT_HP_CORE_PROC		(PT_LOOS + 0x5)
#परिभाषय PT_HP_CORE_LOADABLE	(PT_LOOS + 0x6)
#परिभाषय PT_HP_CORE_राशिः	(PT_LOOS + 0x7)
#परिभाषय PT_HP_CORE_SHM		(PT_LOOS + 0x8)
#परिभाषय PT_HP_CORE_MMF		(PT_LOOS + 0x9)
#परिभाषय PT_HP_PARALLEL		(PT_LOOS + 0x10)
#परिभाषय PT_HP_FASTBIND		(PT_LOOS + 0x11)
#परिभाषय PT_HP_OPT_ANNOT		(PT_LOOS + 0x12)
#परिभाषय PT_HP_HSL_ANNOT		(PT_LOOS + 0x13)
#परिभाषय PT_HP_राशिः		(PT_LOOS + 0x14)

#परिभाषय PT_PARISC_ARCHEXT	0x70000000
#परिभाषय PT_PARISC_UNWIND	0x70000001

/* Legal values for p_flags field of Elf32_Phdr/Elf64_Phdr.  */

#परिभाषय PF_PARISC_SBP		0x08000000

#परिभाषय PF_HP_PAGE_आकार		0x00100000
#परिभाषय PF_HP_FAR_SHARED	0x00200000
#परिभाषय PF_HP_NEAR_SHARED	0x00400000
#परिभाषय PF_HP_संहिता		0x01000000
#परिभाषय PF_HP_MODIFY		0x02000000
#परिभाषय PF_HP_LAZYSWAP		0x04000000
#परिभाषय PF_HP_SBP		0x08000000


/* Alpha specific definitions.  */

/* Legal values for e_flags field of Elf64_Ehdr.  */

#परिभाषय EF_ALPHA_32BIT		1	/* All addresses must be < 2GB.  */
#परिभाषय EF_ALPHA_CANRELAX	2	/* Relocations for relaxing exist.  */

/* Legal values for sh_type field of Elf64_Shdr.  */

/* These two are primarily concerned with ECOFF debugging info.  */
#परिभाषय SHT_ALPHA_DEBUG		0x70000001
#परिभाषय SHT_ALPHA_REGINFO	0x70000002

/* Legal values for sh_flags field of Elf64_Shdr.  */

#परिभाषय SHF_ALPHA_GPREL		0x10000000

/* Legal values for st_other field of Elf64_Sym.  */
#परिभाषय STO_ALPHA_NOPV		0x80	/* No PV required.  */
#परिभाषय STO_ALPHA_STD_GPLOAD	0x88	/* PV only used for initial ldgp.  */

/* Alpha relocs.  */

#परिभाषय R_ALPHA_NONE		0	/* No reloc */
#परिभाषय R_ALPHA_REFLONG		1	/* Direct 32 bit */
#परिभाषय R_ALPHA_REFQUAD		2	/* Direct 64 bit */
#परिभाषय R_ALPHA_GPREL32		3	/* GP relative 32 bit */
#परिभाषय R_ALPHA_LITERAL		4	/* GP relative 16 bit w/optimization */
#परिभाषय R_ALPHA_LITUSE		5	/* Optimization hint for LITERAL */
#परिभाषय R_ALPHA_GPDISP		6	/* Add displacement to GP */
#परिभाषय R_ALPHA_BRADDR		7	/* PC+4 relative 23 bit shifted */
#परिभाषय R_ALPHA_HINT		8	/* PC+4 relative 16 bit shifted */
#परिभाषय R_ALPHA_SREL16		9	/* PC relative 16 bit */
#परिभाषय R_ALPHA_SREL32		10	/* PC relative 32 bit */
#परिभाषय R_ALPHA_SREL64		11	/* PC relative 64 bit */
#परिभाषय R_ALPHA_GPRELHIGH	17	/* GP relative 32 bit, high 16 bits */
#परिभाषय R_ALPHA_GPRELLOW	18	/* GP relative 32 bit, low 16 bits */
#परिभाषय R_ALPHA_GPREL16		19	/* GP relative 16 bit */
#परिभाषय R_ALPHA_COPY		24	/* Copy symbol at runtime */
#परिभाषय R_ALPHA_GLOB_DAT	25	/* Create GOT entry */
#परिभाषय R_ALPHA_JMP_SLOT	26	/* Create PLT entry */
#परिभाषय R_ALPHA_RELATIVE	27	/* Adjust by program base */
#परिभाषय R_ALPHA_TLS_GD_HI	28
#परिभाषय R_ALPHA_TLSGD		29
#परिभाषय R_ALPHA_TLS_LDM		30
#परिभाषय R_ALPHA_DTPMOD64	31
#परिभाषय R_ALPHA_GOTDTPREL	32
#परिभाषय R_ALPHA_DTPREL64	33
#परिभाषय R_ALPHA_DTPRELHI	34
#परिभाषय R_ALPHA_DTPRELLO	35
#परिभाषय R_ALPHA_DTPREL16	36
#परिभाषय R_ALPHA_GOTTPREL	37
#परिभाषय R_ALPHA_TPREL64		38
#परिभाषय R_ALPHA_TPRELHI		39
#परिभाषय R_ALPHA_TPRELLO		40
#परिभाषय R_ALPHA_TPREL16		41
/* Keep this the last entry.  */
#परिभाषय R_ALPHA_अङ्कः		46

/* Magic values of the LITUSE relocation addend.  */
#परिभाषय LITUSE_ALPHA_ADDR	0
#परिभाषय LITUSE_ALPHA_आधारः	1
#परिभाषय LITUSE_ALPHA_BYTOFF	2
#परिभाषय LITUSE_ALPHA_JSR	3
#परिभाषय LITUSE_ALPHA_TLS_GD	4
#परिभाषय LITUSE_ALPHA_TLS_LDM	5

/* Legal values for d_tag of Elf64_Dyn.  */
#परिभाषय DT_ALPHA_PLTRO		(DT_LOPROC + 0)
#परिभाषय DT_ALPHA_अङ्कः		1

/* PowerPC specific declarations */

/* Values for Elf32/64_Ehdr.e_flags.  */
#परिभाषय EF_PPC_EMB		0x80000000	/* PowerPC embedded flag */

/* Cygnus local bits below */
#परिभाषय EF_PPC_RELOCATABLE	0x00010000	/* PowerPC -mrelocatable flag*/
#परिभाषय EF_PPC_RELOCATABLE_LIB	0x00008000	/* PowerPC -mrelocatable-lib
						   flag */

/* PowerPC relocations defined by the ABIs */
#परिभाषय R_PPC_NONE		0
#परिभाषय R_PPC_ADDR32		1	/* 32bit absolute address */
#परिभाषय R_PPC_ADDR24		2	/* 26bit address, 2 bits ignored.  */
#परिभाषय R_PPC_ADDR16		3	/* 16bit absolute address */
#परिभाषय R_PPC_ADDR16_LO		4	/* lower 16bit of absolute address */
#परिभाषय R_PPC_ADDR16_HI		5	/* high 16bit of absolute address */
#परिभाषय R_PPC_ADDR16_HA		6	/* adjusted high 16bit */
#परिभाषय R_PPC_ADDR14		7	/* 16bit address, 2 bits ignored */
#परिभाषय R_PPC_ADDR14_BRTAKEN	8
#परिभाषय R_PPC_ADDR14_BRNTAKEN	9
#परिभाषय R_PPC_REL24		10	/* PC relative 26 bit */
#परिभाषय R_PPC_REL14		11	/* PC relative 16 bit */
#परिभाषय R_PPC_REL14_BRTAKEN	12
#परिभाषय R_PPC_REL14_BRNTAKEN	13
#परिभाषय R_PPC_GOT16		14
#परिभाषय R_PPC_GOT16_LO		15
#परिभाषय R_PPC_GOT16_HI		16
#परिभाषय R_PPC_GOT16_HA		17
#परिभाषय R_PPC_PLTREL24		18
#परिभाषय R_PPC_COPY		19
#परिभाषय R_PPC_GLOB_DAT		20
#परिभाषय R_PPC_JMP_SLOT		21
#परिभाषय R_PPC_RELATIVE		22
#परिभाषय R_PPC_LOCAL24PC		23
#परिभाषय R_PPC_UADDR32		24
#परिभाषय R_PPC_UADDR16		25
#परिभाषय R_PPC_REL32		26
#परिभाषय R_PPC_PLT32		27
#परिभाषय R_PPC_PLTREL32		28
#परिभाषय R_PPC_PLT16_LO		29
#परिभाषय R_PPC_PLT16_HI		30
#परिभाषय R_PPC_PLT16_HA		31
#परिभाषय R_PPC_SDAREL16		32
#परिभाषय R_PPC_SECTOFF		33
#परिभाषय R_PPC_SECTOFF_LO	34
#परिभाषय R_PPC_SECTOFF_HI	35
#परिभाषय R_PPC_SECTOFF_HA	36

/* PowerPC relocations defined for the TLS access ABI.  */
#परिभाषय R_PPC_TLS		67 /* none	(sym+add)@tls */
#परिभाषय R_PPC_DTPMOD32		68 /* word32	(sym+add)@dtpmod */
#परिभाषय R_PPC_TPREL16		69 /* half16*	(sym+add)@tprel */
#परिभाषय R_PPC_TPREL16_LO	70 /* half16	(sym+add)@tprel@l */
#परिभाषय R_PPC_TPREL16_HI	71 /* half16	(sym+add)@tprel@h */
#परिभाषय R_PPC_TPREL16_HA	72 /* half16	(sym+add)@tprel@ha */
#परिभाषय R_PPC_TPREL32		73 /* word32	(sym+add)@tprel */
#परिभाषय R_PPC_DTPREL16		74 /* half16*	(sym+add)@dtprel */
#परिभाषय R_PPC_DTPREL16_LO	75 /* half16	(sym+add)@dtprel@l */
#परिभाषय R_PPC_DTPREL16_HI	76 /* half16	(sym+add)@dtprel@h */
#परिभाषय R_PPC_DTPREL16_HA	77 /* half16	(sym+add)@dtprel@ha */
#परिभाषय R_PPC_DTPREL32		78 /* word32	(sym+add)@dtprel */
#परिभाषय R_PPC_GOT_TLSGD16	79 /* half16*	(sym+add)@got@tlsgd */
#परिभाषय R_PPC_GOT_TLSGD16_LO	80 /* half16	(sym+add)@got@tlsgd@l */
#परिभाषय R_PPC_GOT_TLSGD16_HI	81 /* half16	(sym+add)@got@tlsgd@h */
#परिभाषय R_PPC_GOT_TLSGD16_HA	82 /* half16	(sym+add)@got@tlsgd@ha */
#परिभाषय R_PPC_GOT_TLSLD16	83 /* half16*	(sym+add)@got@tlsld */
#परिभाषय R_PPC_GOT_TLSLD16_LO	84 /* half16	(sym+add)@got@tlsld@l */
#परिभाषय R_PPC_GOT_TLSLD16_HI	85 /* half16	(sym+add)@got@tlsld@h */
#परिभाषय R_PPC_GOT_TLSLD16_HA	86 /* half16	(sym+add)@got@tlsld@ha */
#परिभाषय R_PPC_GOT_TPREL16	87 /* half16*	(sym+add)@got@tprel */
#परिभाषय R_PPC_GOT_TPREL16_LO	88 /* half16	(sym+add)@got@tprel@l */
#परिभाषय R_PPC_GOT_TPREL16_HI	89 /* half16	(sym+add)@got@tprel@h */
#परिभाषय R_PPC_GOT_TPREL16_HA	90 /* half16	(sym+add)@got@tprel@ha */
#परिभाषय R_PPC_GOT_DTPREL16	91 /* half16*	(sym+add)@got@dtprel */
#परिभाषय R_PPC_GOT_DTPREL16_LO	92 /* half16*	(sym+add)@got@dtprel@l */
#परिभाषय R_PPC_GOT_DTPREL16_HI	93 /* half16*	(sym+add)@got@dtprel@h */
#परिभाषय R_PPC_GOT_DTPREL16_HA	94 /* half16*	(sym+add)@got@dtprel@ha */

/* The remaining relocs are from the Embedded ELF ABI, and are not
   in the SVR4 ELF ABI.  */
#परिभाषय R_PPC_EMB_NADDR32	101
#परिभाषय R_PPC_EMB_NADDR16	102
#परिभाषय R_PPC_EMB_NADDR16_LO	103
#परिभाषय R_PPC_EMB_NADDR16_HI	104
#परिभाषय R_PPC_EMB_NADDR16_HA	105
#परिभाषय R_PPC_EMB_SDAI16	106
#परिभाषय R_PPC_EMB_SDA2I16	107
#परिभाषय R_PPC_EMB_SDA2REL	108
#परिभाषय R_PPC_EMB_SDA21		109	/* 16 bit offset in SDA */
#परिभाषय R_PPC_EMB_MRKREF	110
#परिभाषय R_PPC_EMB_RELSEC16	111
#परिभाषय R_PPC_EMB_RELST_LO	112
#परिभाषय R_PPC_EMB_RELST_HI	113
#परिभाषय R_PPC_EMB_RELST_HA	114
#परिभाषय R_PPC_EMB_BIT_FLD	115
#परिभाषय R_PPC_EMB_RELSDA	116	/* 16 bit relative offset in SDA */

/* Diab tool relocations.  */
#परिभाषय R_PPC_DIAB_SDA21_LO	180	/* like EMB_SDA21, but lower 16 bit */
#परिभाषय R_PPC_DIAB_SDA21_HI	181	/* like EMB_SDA21, but high 16 bit */
#परिभाषय R_PPC_DIAB_SDA21_HA	182	/* like EMB_SDA21, adjusted high 16 */
#परिभाषय R_PPC_DIAB_RELSDA_LO	183	/* like EMB_RELSDA, but lower 16 bit */
#परिभाषय R_PPC_DIAB_RELSDA_HI	184	/* like EMB_RELSDA, but high 16 bit */
#परिभाषय R_PPC_DIAB_RELSDA_HA	185	/* like EMB_RELSDA, adjusted high 16 */

/* GNU extension to support local ifunc.  */
#परिभाषय R_PPC_IRELATIVE		248

/* GNU relocs used in PIC code sequences.  */
#परिभाषय R_PPC_REL16		249	/* half16   (sym+add-.) */
#परिभाषय R_PPC_REL16_LO		250	/* half16   (sym+add-.)@l */
#परिभाषय R_PPC_REL16_HI		251	/* half16   (sym+add-.)@h */
#परिभाषय R_PPC_REL16_HA		252	/* half16   (sym+add-.)@ha */

/* This is a phony reloc to handle any old fashioned TOC16 references
   that may still be in object files.  */
#परिभाषय R_PPC_TOC16		255

/* PowerPC specific values for the Dyn d_tag field.  */
#परिभाषय DT_PPC_GOT		(DT_LOPROC + 0)
#परिभाषय DT_PPC_अङ्कः		1

/* PowerPC64 relocations defined by the ABIs */
#परिभाषय R_PPC64_NONE		R_PPC_NONE
#परिभाषय R_PPC64_ADDR32		R_PPC_ADDR32 /* 32bit absolute address */
#परिभाषय R_PPC64_ADDR24		R_PPC_ADDR24 /* 26bit address, word aligned */
#परिभाषय R_PPC64_ADDR16		R_PPC_ADDR16 /* 16bit absolute address */
#परिभाषय R_PPC64_ADDR16_LO	R_PPC_ADDR16_LO	/* lower 16bits of address */
#परिभाषय R_PPC64_ADDR16_HI	R_PPC_ADDR16_HI	/* high 16bits of address. */
#परिभाषय R_PPC64_ADDR16_HA	R_PPC_ADDR16_HA /* adjusted high 16bits.  */
#परिभाषय R_PPC64_ADDR14		R_PPC_ADDR14 /* 16bit address, word aligned */
#परिभाषय R_PPC64_ADDR14_BRTAKEN	R_PPC_ADDR14_BRTAKEN
#परिभाषय R_PPC64_ADDR14_BRNTAKEN	R_PPC_ADDR14_BRNTAKEN
#परिभाषय R_PPC64_REL24		R_PPC_REL24 /* PC-rel. 26 bit, word aligned */
#परिभाषय R_PPC64_REL14		R_PPC_REL14 /* PC relative 16 bit */
#परिभाषय R_PPC64_REL14_BRTAKEN	R_PPC_REL14_BRTAKEN
#परिभाषय R_PPC64_REL14_BRNTAKEN	R_PPC_REL14_BRNTAKEN
#परिभाषय R_PPC64_GOT16		R_PPC_GOT16
#परिभाषय R_PPC64_GOT16_LO	R_PPC_GOT16_LO
#परिभाषय R_PPC64_GOT16_HI	R_PPC_GOT16_HI
#परिभाषय R_PPC64_GOT16_HA	R_PPC_GOT16_HA

#परिभाषय R_PPC64_COPY		R_PPC_COPY
#परिभाषय R_PPC64_GLOB_DAT	R_PPC_GLOB_DAT
#परिभाषय R_PPC64_JMP_SLOT	R_PPC_JMP_SLOT
#परिभाषय R_PPC64_RELATIVE	R_PPC_RELATIVE

#परिभाषय R_PPC64_UADDR32		R_PPC_UADDR32
#परिभाषय R_PPC64_UADDR16		R_PPC_UADDR16
#परिभाषय R_PPC64_REL32		R_PPC_REL32
#परिभाषय R_PPC64_PLT32		R_PPC_PLT32
#परिभाषय R_PPC64_PLTREL32	R_PPC_PLTREL32
#परिभाषय R_PPC64_PLT16_LO	R_PPC_PLT16_LO
#परिभाषय R_PPC64_PLT16_HI	R_PPC_PLT16_HI
#परिभाषय R_PPC64_PLT16_HA	R_PPC_PLT16_HA

#परिभाषय R_PPC64_SECTOFF		R_PPC_SECTOFF
#परिभाषय R_PPC64_SECTOFF_LO	R_PPC_SECTOFF_LO
#परिभाषय R_PPC64_SECTOFF_HI	R_PPC_SECTOFF_HI
#परिभाषय R_PPC64_SECTOFF_HA	R_PPC_SECTOFF_HA
#परिभाषय R_PPC64_ADDR30		37 /* word30 (S + A - P) >> 2 */
#परिभाषय R_PPC64_ADDR64		38 /* doubleword64 S + A */
#परिभाषय R_PPC64_ADDR16_HIGHER	39 /* half16 #higher(S + A) */
#परिभाषय R_PPC64_ADDR16_HIGHERA	40 /* half16 #highera(S + A) */
#परिभाषय R_PPC64_ADDR16_HIGHEST	41 /* half16 #highest(S + A) */
#परिभाषय R_PPC64_ADDR16_HIGHESTA	42 /* half16 #highesta(S + A) */
#परिभाषय R_PPC64_UADDR64		43 /* doubleword64 S + A */
#परिभाषय R_PPC64_REL64		44 /* doubleword64 S + A - P */
#परिभाषय R_PPC64_PLT64		45 /* doubleword64 L + A */
#परिभाषय R_PPC64_PLTREL64	46 /* doubleword64 L + A - P */
#परिभाषय R_PPC64_TOC16		47 /* half16* S + A - .TOC */
#परिभाषय R_PPC64_TOC16_LO	48 /* half16 #lo(S + A - .TOC.) */
#परिभाषय R_PPC64_TOC16_HI	49 /* half16 #hi(S + A - .TOC.) */
#परिभाषय R_PPC64_TOC16_HA	50 /* half16 #ha(S + A - .TOC.) */
#परिभाषय R_PPC64_TOC		51 /* doubleword64 .TOC */
#परिभाषय R_PPC64_PLTGOT16	52 /* half16* M + A */
#परिभाषय R_PPC64_PLTGOT16_LO	53 /* half16 #lo(M + A) */
#परिभाषय R_PPC64_PLTGOT16_HI	54 /* half16 #hi(M + A) */
#परिभाषय R_PPC64_PLTGOT16_HA	55 /* half16 #ha(M + A) */

#परिभाषय R_PPC64_ADDR16_DS	56 /* half16ds* (S + A) >> 2 */
#परिभाषय R_PPC64_ADDR16_LO_DS	57 /* half16ds  #lo(S + A) >> 2 */
#परिभाषय R_PPC64_GOT16_DS	58 /* half16ds* (G + A) >> 2 */
#परिभाषय R_PPC64_GOT16_LO_DS	59 /* half16ds  #lo(G + A) >> 2 */
#परिभाषय R_PPC64_PLT16_LO_DS	60 /* half16ds  #lo(L + A) >> 2 */
#परिभाषय R_PPC64_SECTOFF_DS	61 /* half16ds* (R + A) >> 2 */
#परिभाषय R_PPC64_SECTOFF_LO_DS	62 /* half16ds  #lo(R + A) >> 2 */
#परिभाषय R_PPC64_TOC16_DS	63 /* half16ds* (S + A - .TOC.) >> 2 */
#परिभाषय R_PPC64_TOC16_LO_DS	64 /* half16ds  #lo(S + A - .TOC.) >> 2 */
#परिभाषय R_PPC64_PLTGOT16_DS	65 /* half16ds* (M + A) >> 2 */
#परिभाषय R_PPC64_PLTGOT16_LO_DS	66 /* half16ds  #lo(M + A) >> 2 */

/* PowerPC64 relocations defined for the TLS access ABI.  */
#परिभाषय R_PPC64_TLS		67 /* none	(sym+add)@tls */
#परिभाषय R_PPC64_DTPMOD64	68 /* doubleword64 (sym+add)@dtpmod */
#परिभाषय R_PPC64_TPREL16		69 /* half16*	(sym+add)@tprel */
#परिभाषय R_PPC64_TPREL16_LO	70 /* half16	(sym+add)@tprel@l */
#परिभाषय R_PPC64_TPREL16_HI	71 /* half16	(sym+add)@tprel@h */
#परिभाषय R_PPC64_TPREL16_HA	72 /* half16	(sym+add)@tprel@ha */
#परिभाषय R_PPC64_TPREL64		73 /* doubleword64 (sym+add)@tprel */
#परिभाषय R_PPC64_DTPREL16	74 /* half16*	(sym+add)@dtprel */
#परिभाषय R_PPC64_DTPREL16_LO	75 /* half16	(sym+add)@dtprel@l */
#परिभाषय R_PPC64_DTPREL16_HI	76 /* half16	(sym+add)@dtprel@h */
#परिभाषय R_PPC64_DTPREL16_HA	77 /* half16	(sym+add)@dtprel@ha */
#परिभाषय R_PPC64_DTPREL64	78 /* doubleword64 (sym+add)@dtprel */
#परिभाषय R_PPC64_GOT_TLSGD16	79 /* half16*	(sym+add)@got@tlsgd */
#परिभाषय R_PPC64_GOT_TLSGD16_LO	80 /* half16	(sym+add)@got@tlsgd@l */
#परिभाषय R_PPC64_GOT_TLSGD16_HI	81 /* half16	(sym+add)@got@tlsgd@h */
#परिभाषय R_PPC64_GOT_TLSGD16_HA	82 /* half16	(sym+add)@got@tlsgd@ha */
#परिभाषय R_PPC64_GOT_TLSLD16	83 /* half16*	(sym+add)@got@tlsld */
#परिभाषय R_PPC64_GOT_TLSLD16_LO	84 /* half16	(sym+add)@got@tlsld@l */
#परिभाषय R_PPC64_GOT_TLSLD16_HI	85 /* half16	(sym+add)@got@tlsld@h */
#परिभाषय R_PPC64_GOT_TLSLD16_HA	86 /* half16	(sym+add)@got@tlsld@ha */
#परिभाषय R_PPC64_GOT_TPREL16_DS	87 /* half16ds*	(sym+add)@got@tprel */
#परिभाषय R_PPC64_GOT_TPREL16_LO_DS 88 /* half16ds (sym+add)@got@tprel@l */
#परिभाषय R_PPC64_GOT_TPREL16_HI	89 /* half16	(sym+add)@got@tprel@h */
#परिभाषय R_PPC64_GOT_TPREL16_HA	90 /* half16	(sym+add)@got@tprel@ha */
#परिभाषय R_PPC64_GOT_DTPREL16_DS	91 /* half16ds*	(sym+add)@got@dtprel */
#परिभाषय R_PPC64_GOT_DTPREL16_LO_DS 92 /* half16ds (sym+add)@got@dtprel@l */
#परिभाषय R_PPC64_GOT_DTPREL16_HI	93 /* half16	(sym+add)@got@dtprel@h */
#परिभाषय R_PPC64_GOT_DTPREL16_HA	94 /* half16	(sym+add)@got@dtprel@ha */
#परिभाषय R_PPC64_TPREL16_DS	95 /* half16ds*	(sym+add)@tprel */
#परिभाषय R_PPC64_TPREL16_LO_DS	96 /* half16ds	(sym+add)@tprel@l */
#परिभाषय R_PPC64_TPREL16_HIGHER	97 /* half16	(sym+add)@tprel@higher */
#परिभाषय R_PPC64_TPREL16_HIGHERA	98 /* half16	(sym+add)@tprel@highera */
#परिभाषय R_PPC64_TPREL16_HIGHEST	99 /* half16	(sym+add)@tprel@highest */
#परिभाषय R_PPC64_TPREL16_HIGHESTA 100 /* half16	(sym+add)@tprel@highesta */
#परिभाषय R_PPC64_DTPREL16_DS	101 /* half16ds* (sym+add)@dtprel */
#परिभाषय R_PPC64_DTPREL16_LO_DS	102 /* half16ds	(sym+add)@dtprel@l */
#परिभाषय R_PPC64_DTPREL16_HIGHER	103 /* half16	(sym+add)@dtprel@higher */
#परिभाषय R_PPC64_DTPREL16_HIGHERA 104 /* half16	(sym+add)@dtprel@highera */
#परिभाषय R_PPC64_DTPREL16_HIGHEST 105 /* half16	(sym+add)@dtprel@highest */
#परिभाषय R_PPC64_DTPREL16_HIGHESTA 106 /* half16	(sym+add)@dtprel@highesta */

/* GNU extension to support local ifunc.  */
#परिभाषय R_PPC64_JMP_IREL	247
#परिभाषय R_PPC64_IRELATIVE	248
#परिभाषय R_PPC64_REL16		249	/* half16   (sym+add-.) */
#परिभाषय R_PPC64_REL16_LO	250	/* half16   (sym+add-.)@l */
#परिभाषय R_PPC64_REL16_HI	251	/* half16   (sym+add-.)@h */
#परिभाषय R_PPC64_REL16_HA	252	/* half16   (sym+add-.)@ha */

/* PowerPC64 specific values for the Dyn d_tag field.  */
#परिभाषय DT_PPC64_GLINK  (DT_LOPROC + 0)
#परिभाषय DT_PPC64_OPD	(DT_LOPROC + 1)
#परिभाषय DT_PPC64_OPDSZ	(DT_LOPROC + 2)
#परिभाषय DT_PPC64_अङ्कः    3


/* ARM specific declarations */

/* Processor specific flags for the ELF header e_flags field.  */
#परिभाषय EF_ARM_RELEXEC		0x01
#परिभाषय EF_ARM_HASENTRY		0x02
#परिभाषय EF_ARM_INTERWORK	0x04
#परिभाषय EF_ARM_APCS_26		0x08
#परिभाषय EF_ARM_APCS_FLOAT	0x10
#परिभाषय EF_ARM_PIC		0x20
#परिभाषय EF_ARM_ALIGN8		0x40 /* 8-bit structure alignment is in use */
#परिभाषय EF_ARM_NEW_ABI		0x80
#परिभाषय EF_ARM_OLD_ABI		0x100
#परिभाषय EF_ARM_SOFT_FLOAT	0x200
#परिभाषय EF_ARM_VFP_FLOAT	0x400
#परिभाषय EF_ARM_MAVERICK_FLOAT	0x800

#परिभाषय EF_ARM_ABI_FLOAT_SOFT	0x200   /* NB conflicts with EF_ARM_SOFT_FLOAT */
#परिभाषय EF_ARM_ABI_FLOAT_HARD	0x400   /* NB conflicts with EF_ARM_VFP_FLOAT */


/* Other constants defined in the ARM ELF spec. version B-01.  */
/* NB. These conflict with values defined above.  */
#परिभाषय EF_ARM_SYMSARESORTED	0x04
#परिभाषय EF_ARM_DYNSYMSUSESEGIDX	0x08
#परिभाषय EF_ARM_MAPSYMSFIRST	0x10
#परिभाषय EF_ARM_EABIMASK		0XFF000000

/* Constants defined in AAELF.  */
#परिभाषय EF_ARM_BE8	    0x00800000
#परिभाषय EF_ARM_LE8	    0x00400000

#परिभाषय EF_ARM_EABI_संस्करणम्(flags)	((flags) & EF_ARM_EABIMASK)
#परिभाषय EF_ARM_EABI_UNKNOWN	0x00000000
#परिभाषय EF_ARM_EABI_VER1	0x01000000
#परिभाषय EF_ARM_EABI_VER2	0x02000000
#परिभाषय EF_ARM_EABI_VER3	0x03000000
#परिभाषय EF_ARM_EABI_VER4	0x04000000
#परिभाषय EF_ARM_EABI_VER5	0x05000000

/* Additional symbol types for Thumb.  */
#परिभाषय STT_ARM_TFUNC		STT_LOPROC /* A Thumb function.  */
#परिभाषय STT_ARM_16BIT		STT_HIPROC /* A Thumb label.  */

/* ARM-specific values for sh_flags */
#परिभाषय SHF_ARM_ENTRYSECT	0x10000000 /* Section contains an entry point */
#परिभाषय SHF_ARM_COMDEF		0x80000000 /* Section may be multiply defined
					      in the input to a link step.  */

/* ARM-specific program header flags */
#परिभाषय PF_ARM_SB		0x10000000 /* Segment contains the location
					      addressed by the static base. */
#परिभाषय PF_ARM_PI		0x20000000 /* Position-independent segment.  */
#परिभाषय PF_ARM_ABS		0x40000000 /* Absolute segment.  */

/* Processor specific values for the Phdr p_type field.  */
#परिभाषय PT_ARM_EXIDX		(PT_LOPROC + 1)	/* ARM unwind segment.  */

/* Processor specific values for the Shdr sh_type field.  */
#परिभाषय SHT_ARM_EXIDX		(SHT_LOPROC + 1) /* ARM unwind section.  */
#परिभाषय SHT_ARM_PREEMPTMAP	(SHT_LOPROC + 2) /* Preemption details.  */
#परिभाषय	SHT_ARM_गुणाः	(SHT_LOPROC + 3) /* ARM attributes section.  */
#परिभाषय SHT_RISCV_गुणाः	0x70000003


/* AArch64 relocs.  */

#परिभाषय R_AARCH64_NONE            0	/* No relocation.  */
#परिभाषय R_AARCH64_ABS64         257	/* Direct 64 bit. */
#परिभाषय R_AARCH64_ABS32         258	/* Direct 32 bit.  */
#परिभाषय R_AARCH64_ABS16         259	/* Direct 16-bit.  */
#परिभाषय R_AARCH64_PREL64        260	/* PC-relative 64-bit.  */
#परिभाषय R_AARCH64_PREL32        261	/* PC-relative 32-bit.  */
#परिभाषय R_AARCH64_PREL16        262	/* PC-relative 16-bit.  */
#परिभाषय R_AARCH64_MOVW_UABS_G0  263	/* Dir. MOVZ imm. from bits 15:0.  */
#परिभाषय R_AARCH64_MOVW_UABS_G0_NC 264	/* Likewise for MOVK; no check.  */
#परिभाषय R_AARCH64_MOVW_UABS_G1  265	/* Dir. MOVZ imm. from bits 31:16.  */
#परिभाषय R_AARCH64_MOVW_UABS_G1_NC 266	/* Likewise for MOVK; no check.  */
#परिभाषय R_AARCH64_MOVW_UABS_G2  267	/* Dir. MOVZ imm. from bits 47:32.  */
#परिभाषय R_AARCH64_MOVW_UABS_G2_NC 268	/* Likewise for MOVK; no check.  */
#परिभाषय R_AARCH64_MOVW_UABS_G3  269	/* Dir. MOV{K,Z} imm. from 63:48.  */
#परिभाषय R_AARCH64_MOVW_SABS_G0  270	/* Dir. MOV{N,Z} imm. from 15:0.  */
#परिभाषय R_AARCH64_MOVW_SABS_G1  271	/* Dir. MOV{N,Z} imm. from 31:16.  */
#परिभाषय R_AARCH64_MOVW_SABS_G2  272	/* Dir. MOV{N,Z} imm. from 47:32.  */
#परिभाषय R_AARCH64_LD_PREL_LO19  273	/* PC-rel. LD imm. from bits 20:2.  */
#परिभाषय R_AARCH64_ADR_PREL_LO21 274	/* PC-rel. ADR imm. from bits 20:0.  */
#परिभाषय R_AARCH64_ADR_PREL_PG_HI21 275	/* Page-rel. ADRP imm. from 32:12.  */
#परिभाषय R_AARCH64_ADR_PREL_PG_HI21_NC 276	/* Likewise; no overflow check.  */
#परिभाषय R_AARCH64_सङ्कलय_ABS_LO12_NC 277	/* Dir. ADD imm. from bits 11:0.  */
#परिभाषय R_AARCH64_LDST8_ABS_LO12_NC 278	/* Likewise for LD/ST; no check. */
#परिभाषय R_AARCH64_TSTBR14       279	/* PC-rel. TBZ/TBNZ imm. from 15:2.  */
#परिभाषय R_AARCH64_CONDBR19      280	/* PC-rel. cond. br. imm. from 20:2. */
#परिभाषय R_AARCH64_JUMP26        282	/* PC-rel. B imm. from bits 27:2.  */
#परिभाषय R_AARCH64_CALL26        283	/* Likewise for CALL.  */
#परिभाषय R_AARCH64_LDST16_ABS_LO12_NC 284	/* Dir. ADD imm. from bits 11:1.  */
#परिभाषय R_AARCH64_LDST32_ABS_LO12_NC 285	/* Likewise for bits 11:2.  */
#परिभाषय R_AARCH64_LDST64_ABS_LO12_NC 286	/* Likewise for bits 11:3.  */
#परिभाषय R_AARCH64_MOVW_PREL_G0  287	/* PC-rel. MOV{N,Z} imm. from 15:0.  */
#परिभाषय R_AARCH64_MOVW_PREL_G0_NC 288	/* Likewise for MOVK; no check.  */
#परिभाषय R_AARCH64_MOVW_PREL_G1  289	/* PC-rel. MOV{N,Z} imm. from 31:16. */
#परिभाषय R_AARCH64_MOVW_PREL_G1_NC 290	/* Likewise for MOVK; no check.  */
#परिभाषय R_AARCH64_MOVW_PREL_G2  291	/* PC-rel. MOV{N,Z} imm. from 47:32. */
#परिभाषय R_AARCH64_MOVW_PREL_G2_NC 292	/* Likewise for MOVK; no check.  */
#परिभाषय R_AARCH64_MOVW_PREL_G3  293	/* PC-rel. MOV{N,Z} imm. from 63:48. */
#परिभाषय R_AARCH64_LDST128_ABS_LO12_NC 299	/* Dir. ADD imm. from bits 11:4.  */
#परिभाषय R_AARCH64_MOVW_GOTOFF_G0 300	/* GOT-rel. off. MOV{N,Z} imm. 15:0. */
#परिभाषय R_AARCH64_MOVW_GOTOFF_G0_NC 301	/* Likewise for MOVK; no check.  */
#परिभाषय R_AARCH64_MOVW_GOTOFF_G1 302	/* GOT-rel. o. MOV{N,Z} imm. 31:16.  */
#परिभाषय R_AARCH64_MOVW_GOTOFF_G1_NC 303	/* Likewise for MOVK; no check.  */
#परिभाषय R_AARCH64_MOVW_GOTOFF_G2 304	/* GOT-rel. o. MOV{N,Z} imm. 47:32.  */
#परिभाषय R_AARCH64_MOVW_GOTOFF_G2_NC 305	/* Likewise for MOVK; no check.  */
#परिभाषय R_AARCH64_MOVW_GOTOFF_G3 306	/* GOT-rel. o. MOV{N,Z} imm. 63:48.  */
#परिभाषय R_AARCH64_GOTREL64      307	/* GOT-relative 64-bit.  */
#परिभाषय R_AARCH64_GOTREL32      308	/* GOT-relative 32-bit.  */
#परिभाषय R_AARCH64_GOT_LD_PREL19 309	/* PC-rel. GOT off. load imm. 20:2.  */
#परिभाषय R_AARCH64_LD64_GOTOFF_LO15 310	/* GOT-rel. off. LD/ST imm. 14:3.  */
#परिभाषय R_AARCH64_ADR_GOT_PAGE  311	/* P-page-rel. GOT off. ADRP 32:12.  */
#परिभाषय R_AARCH64_LD64_GOT_LO12_NC 312	/* Dir. GOT off. LD/ST imm. 11:3.  */
#परिभाषय R_AARCH64_LD64_GOTPAGE_LO15 313	/* GOT-page-rel. GOT off. LD/ST 14:3 */
#परिभाषय R_AARCH64_TLSGD_ADR_PREL21 512	/* PC-relative ADR imm. 20:0.  */
#परिभाषय R_AARCH64_TLSGD_ADR_PAGE21 513	/* page-rel. ADRP imm. 32:12.  */
#परिभाषय R_AARCH64_TLSGD_सङ्कलय_LO12_NC 514	/* direct ADD imm. from 11:0.  */
#परिभाषय R_AARCH64_TLSGD_MOVW_G1 515	/* GOT-rel. MOV{N,Z} 31:16.  */
#परिभाषय R_AARCH64_TLSGD_MOVW_G0_NC 516	/* GOT-rel. MOVK imm. 15:0.  */
#परिभाषय R_AARCH64_TLSLD_ADR_PREL21 517	/* Like 512; local dynamic model.  */
#परिभाषय R_AARCH64_TLSLD_ADR_PAGE21 518	/* Like 513; local dynamic model.  */
#परिभाषय R_AARCH64_TLSLD_सङ्कलय_LO12_NC 519	/* Like 514; local dynamic model.  */
#परिभाषय R_AARCH64_TLSLD_MOVW_G1 520	/* Like 515; local dynamic model.  */
#परिभाषय R_AARCH64_TLSLD_MOVW_G0_NC 521	/* Like 516; local dynamic model.  */
#परिभाषय R_AARCH64_TLSLD_LD_PREL19 522	/* TLS PC-rel. load imm. 20:2.  */
#परिभाषय R_AARCH64_TLSLD_MOVW_DTPREL_G2 523	/* TLS DTP-rel. MOV{N,Z} 47:32.  */
#परिभाषय R_AARCH64_TLSLD_MOVW_DTPREL_G1 524	/* TLS DTP-rel. MOV{N,Z} 31:16.  */
#परिभाषय R_AARCH64_TLSLD_MOVW_DTPREL_G1_NC 525	/* Likewise; MOVK; no check.  */
#परिभाषय R_AARCH64_TLSLD_MOVW_DTPREL_G0 526	/* TLS DTP-rel. MOV{N,Z} 15:0.  */
#परिभाषय R_AARCH64_TLSLD_MOVW_DTPREL_G0_NC 527	/* Likewise; MOVK; no check.  */
#परिभाषय R_AARCH64_TLSLD_सङ्कलय_DTPREL_HI12 528	/* DTP-rel. ADD imm. from 23:12. */
#परिभाषय R_AARCH64_TLSLD_सङ्कलय_DTPREL_LO12 529	/* DTP-rel. ADD imm. from 11:0.  */
#परिभाषय R_AARCH64_TLSLD_सङ्कलय_DTPREL_LO12_NC 530	/* Likewise; no ovfl. check.  */
#परिभाषय R_AARCH64_TLSLD_LDST8_DTPREL_LO12 531	/* DTP-rel. LD/ST imm. 11:0.  */
#परिभाषय R_AARCH64_TLSLD_LDST8_DTPREL_LO12_NC 532	/* Likewise; no check.  */
#परिभाषय R_AARCH64_TLSLD_LDST16_DTPREL_LO12 533	/* DTP-rel. LD/ST imm. 11:1.  */
#परिभाषय R_AARCH64_TLSLD_LDST16_DTPREL_LO12_NC 534	/* Likewise; no check.  */
#परिभाषय R_AARCH64_TLSLD_LDST32_DTPREL_LO12 535	/* DTP-rel. LD/ST imm. 11:2.  */
#परिभाषय R_AARCH64_TLSLD_LDST32_DTPREL_LO12_NC 536	/* Likewise; no check.  */
#परिभाषय R_AARCH64_TLSLD_LDST64_DTPREL_LO12 537	/* DTP-rel. LD/ST imm. 11:3.  */
#परिभाषय R_AARCH64_TLSLD_LDST64_DTPREL_LO12_NC 538	/* Likewise; no check.  */
#परिभाषय R_AARCH64_TLSIE_MOVW_GOTTPREL_G1 539	/* GOT-rel. MOV{N,Z} 31:16.  */
#परिभाषय R_AARCH64_TLSIE_MOVW_GOTTPREL_G0_NC 540	/* GOT-rel. MOVK 15:0.  */
#परिभाषय R_AARCH64_TLSIE_ADR_GOTTPREL_PAGE21 541	/* Page-rel. ADRP 32:12.  */
#परिभाषय R_AARCH64_TLSIE_LD64_GOTTPREL_LO12_NC 542	/* Direct LD off. 11:3.  */
#परिभाषय R_AARCH64_TLSIE_LD_GOTTPREL_PREL19 543	/* PC-rel. load imm. 20:2.  */
#परिभाषय R_AARCH64_TLSLE_MOVW_TPREL_G2 544	/* TLS TP-rel. MOV{N,Z} 47:32.  */
#परिभाषय R_AARCH64_TLSLE_MOVW_TPREL_G1 545	/* TLS TP-rel. MOV{N,Z} 31:16.  */
#परिभाषय R_AARCH64_TLSLE_MOVW_TPREL_G1_NC 546	/* Likewise; MOVK; no check.  */
#परिभाषय R_AARCH64_TLSLE_MOVW_TPREL_G0 547	/* TLS TP-rel. MOV{N,Z} 15:0.  */
#परिभाषय R_AARCH64_TLSLE_MOVW_TPREL_G0_NC 548	/* Likewise; MOVK; no check.  */
#परिभाषय R_AARCH64_TLSLE_सङ्कलय_TPREL_HI12 549	/* TP-rel. ADD imm. 23:12.  */
#परिभाषय R_AARCH64_TLSLE_सङ्कलय_TPREL_LO12 550	/* TP-rel. ADD imm. 11:0.  */
#परिभाषय R_AARCH64_TLSLE_सङ्कलय_TPREL_LO12_NC 551	/* Likewise; no ovfl. check.  */
#परिभाषय R_AARCH64_TLSLE_LDST8_TPREL_LO12 552	/* TP-rel. LD/ST off. 11:0.  */
#परिभाषय R_AARCH64_TLSLE_LDST8_TPREL_LO12_NC 553	/* Likewise; no ovfl. check. */
#परिभाषय R_AARCH64_TLSLE_LDST16_TPREL_LO12 554	/* TP-rel. LD/ST off. 11:1.  */
#परिभाषय R_AARCH64_TLSLE_LDST16_TPREL_LO12_NC 555	/* Likewise; no check.  */
#परिभाषय R_AARCH64_TLSLE_LDST32_TPREL_LO12 556	/* TP-rel. LD/ST off. 11:2.  */
#परिभाषय R_AARCH64_TLSLE_LDST32_TPREL_LO12_NC 557	/* Likewise; no check.  */
#परिभाषय R_AARCH64_TLSLE_LDST64_TPREL_LO12 558	/* TP-rel. LD/ST off. 11:3.  */
#परिभाषय R_AARCH64_TLSLE_LDST64_TPREL_LO12_NC 559	/* Likewise; no check.  */
#परिभाषय R_AARCH64_TLSDESC_LD_PREL19 560	/* PC-rel. load immediate 20:2.  */
#परिभाषय R_AARCH64_TLSDESC_ADR_PREL21 561	/* PC-rel. ADR immediate 20:0.  */
#परिभाषय R_AARCH64_TLSDESC_ADR_PAGE21 562	/* Page-rel. ADRP imm. 32:12.  */
#परिभाषय R_AARCH64_TLSDESC_LD64_LO12 563	/* Direct LD off. from 11:3.  */
#परिभाषय R_AARCH64_TLSDESC_सङ्कलय_LO12 564	/* Direct ADD imm. from 11:0.  */
#परिभाषय R_AARCH64_TLSDESC_OFF_G1 565	/* GOT-rel. MOV{N,Z} imm. 31:16.  */
#परिभाषय R_AARCH64_TLSDESC_OFF_G0_NC 566	/* GOT-rel. MOVK imm. 15:0; no ck.  */
#परिभाषय R_AARCH64_TLSDESC_LDR   567	/* Relax LDR.  */
#परिभाषय R_AARCH64_TLSDESC_सङ्कलय   568	/* Relax ADD.  */
#परिभाषय R_AARCH64_TLSDESC_CALL  569	/* Relax BLR.  */
#परिभाषय R_AARCH64_TLSLE_LDST128_TPREL_LO12 570	/* TP-rel. LD/ST off. 11:4.  */
#परिभाषय R_AARCH64_TLSLE_LDST128_TPREL_LO12_NC 571	/* Likewise; no check.  */
#परिभाषय R_AARCH64_TLSLD_LDST128_DTPREL_LO12 572	/* DTP-rel. LD/ST imm. 11:4. */
#परिभाषय R_AARCH64_TLSLD_LDST128_DTPREL_LO12_NC 573	/* Likewise; no check.  */
#परिभाषय R_AARCH64_COPY         1024	/* Copy symbol at runtime.  */
#परिभाषय R_AARCH64_GLOB_DAT     1025	/* Create GOT entry.  */
#परिभाषय R_AARCH64_JUMP_SLOT    1026	/* Create PLT entry.  */
#परिभाषय R_AARCH64_RELATIVE     1027	/* Adjust by program base.  */
#परिभाषय R_AARCH64_TLS_DTPMOD64 1028	/* Module number, 64 bit.  */
#परिभाषय R_AARCH64_TLS_DTPREL64 1029	/* Module-relative offset, 64 bit.  */
#परिभाषय R_AARCH64_TLS_TPREL64  1030	/* TP-relative offset, 64 bit.  */
#परिभाषय R_AARCH64_TLSDESC      1031	/* TLS Descriptor.  */
#परिभाषय R_AARCH64_IRELATIVE    1032	/* STT_GNU_IFUNC relocation.  */
/* Keep this the last entry.  */
#परिभाषय R_AARCH64_अङ्कः          1033

/* ARM relocs.  */

#परिभाषय R_ARM_NONE		0	/* No reloc */
#परिभाषय R_ARM_PC24		1	/* PC relative 26 bit branch */
#परिभाषय R_ARM_ABS32		2	/* Direct 32 bit  */
#परिभाषय R_ARM_REL32		3	/* PC relative 32 bit */
#परिभाषय R_ARM_PC13		4
#परिभाषय R_ARM_ABS16		5	/* Direct 16 bit */
#परिभाषय R_ARM_ABS12		6	/* Direct 12 bit */
#परिभाषय R_ARM_THM_ABS5		7
#परिभाषय R_ARM_ABS8		8	/* Direct 8 bit */
#परिभाषय R_ARM_SBREL32		9
#परिभाषय R_ARM_THM_PC22		10
#परिभाषय R_ARM_THM_PC8		11
#परिभाषय R_ARM_AMP_VCALL9	12
#परिभाषय R_ARM_SWI24		13	/* Obsolete static relocation.  */
#परिभाषय R_ARM_TLS_DESC		13      /* Dynamic relocation.  */
#परिभाषय R_ARM_THM_SWI8		14
#परिभाषय R_ARM_XPC25		15
#परिभाषय R_ARM_THM_XPC22		16
#परिभाषय R_ARM_TLS_DTPMOD32	17	/* ID of module containing symbol */
#परिभाषय R_ARM_TLS_DTPOFF32	18	/* Offset in TLS block */
#परिभाषय R_ARM_TLS_TPOFF32	19	/* Offset in static TLS block */
#परिभाषय R_ARM_COPY		20	/* Copy symbol at runtime */
#परिभाषय R_ARM_GLOB_DAT		21	/* Create GOT entry */
#परिभाषय R_ARM_JUMP_SLOT		22	/* Create PLT entry */
#परिभाषय R_ARM_RELATIVE		23	/* Adjust by program base */
#परिभाषय R_ARM_GOTOFF		24	/* 32 bit offset to GOT */
#परिभाषय R_ARM_GOTPC		25	/* 32 bit PC relative offset to GOT */
#परिभाषय R_ARM_GOT32		26	/* 32 bit GOT entry */
#परिभाषय R_ARM_PLT32		27	/* 32 bit PLT address */
#परिभाषय R_ARM_CALL		28
#परिभाषय R_ARM_JUMP24		29
#परिभाषय R_ARM_THM_JUMP24	30
#परिभाषय R_ARM_आधारः_ABS  31  /* Adjust by program base.  */
#परिभाषय R_ARM_ALU_PCREL_7_0	32
#परिभाषय R_ARM_ALU_PCREL_15_8	33
#परिभाषय R_ARM_ALU_PCREL_23_15	34
#परिभाषय R_ARM_LDR_SBREL_11_0	35
#परिभाषय R_ARM_ALU_SBREL_19_12	36
#परिभाषय R_ARM_ALU_SBREL_27_20	37
#परिभाषय R_ARM_TARGET1 38
#परिभाषय R_ARM_SBREL31 39  /* Program base relative.  */
#परिभाषय R_ARM_V4BX		40
#परिभाषय R_ARM_TARGET2   41
#परिभाषय R_ARM_PREL31		42
#परिभाषय R_ARM_MOVW_ABS_NC	43
#परिभाषय R_ARM_MOVT_ABS		 44
#परिभाषय R_ARM_MOVW_PREL_NC  45	/* PC relative 16-bit (MOVW).  */
#परिभाषय R_ARM_MOVT_PREL 46  /* PC relative (MOVT).  */
#परिभाषय R_ARM_THM_MOVW_ABS_NC	47
#परिभाषय R_ARM_THM_MOVT_ABS	48
/* Values from 49 to 89 are not yet used/handled by tcc. */
#परिभाषय R_ARM_TLS_GOTDESC	90
#परिभाषय R_ARM_TLS_CALL		91
#परिभाषय R_ARM_TLS_DESCSEQ	92
#परिभाषय R_ARM_THM_TLS_CALL	93
#परिभाषय R_ARM_GOT_PREL		96
#परिभाषय R_ARM_GNU_VTENTRY	100
#परिभाषय R_ARM_GNU_VTINHERIT	101
#परिभाषय R_ARM_THM_PC11		102	/* thumb unconditional branch */
#परिभाषय R_ARM_THM_PC9		103	/* thumb conditional branch */
#परिभाषय R_ARM_TLS_GD32		104	/* PC-rel 32 bit for global dynamic
					   thread local data */
#परिभाषय R_ARM_TLS_LDM32		105	/* PC-rel 32 bit for local dynamic
					   thread local data */
#परिभाषय R_ARM_TLS_LDO32		106	/* 32 bit offset relative to TLS
खण्डम्*/
#परिभाषय R_ARM_TLS_IE32		107	/* PC-rel 32 bit for GOT entry of
					   static TLS block offset */
#परिभाषय R_ARM_TLS_LE32		108	/* 32 bit offset relative to static
					   TLS block */
#परिभाषय	R_ARM_THM_TLS_DESCSEQ	129
#परिभाषय R_ARM_IRELATIVE		160
#परिभाषय R_ARM_RXPC25		249
#परिभाषय R_ARM_RSBREL32		250
#परिभाषय R_ARM_THM_RPC22		251
#परिभाषय R_ARM_RREL32		252
#परिभाषय R_ARM_RABS22		253
#परिभाषय R_ARM_RPC24		254
#परिभाषय R_ARM_RBASE		255
/* Keep this the last entry.  */
#परिभाषय R_ARM_अङ्कः		256

/* TMS320C67xx specific declarations */

/* XXX: no ELF standard yet*/

/* TMS320C67xx relocs. */
#परिभाषय R_C60_32       1
#परिभाषय R_C60_GOT32     3               /* 32 bit GOT entry */
#परिभाषय R_C60_PLT32     4               /* 32 bit PLT address */
#परिभाषय R_C60_COPY      5               /* Copy symbol at runtime */
#परिभाषय R_C60_GLOB_DAT  6               /* Create GOT entry */
#परिभाषय R_C60_JMP_SLOT  7               /* Create PLT entry */
#परिभाषय R_C60_RELATIVE  8               /* Adjust by program base */
#परिभाषय R_C60_GOTOFF    9               /* 32 bit offset to GOT */
#परिभाषय R_C60_GOTPC     10              /* 32 bit PC relative offset to GOT */

#परिभाषय R_C60LO16      0x54       /* low 16 bit MVKL embedded */
#परिभाषय R_C60HI16      0x55       /* high 16 bit MVKH embedded */
/* Keep this the last entry.  */
#परिभाषय R_C60_अङ्कः      0x56

/* IA-64 specific declarations.  */

/* Processor specific flags for the Ehdr e_flags field.  */
#परिभाषय EF_IA_64_MASKOS		0x0000000f	/* os-specific flags */
#परिभाषय EF_IA_64_ABI64		0x00000010	/* 64-bit ABI */
#परिभाषय EF_IA_64_ARCH		0xff000000	/* arch. version mask */

/* Processor specific values for the Phdr p_type field.  */
#परिभाषय PT_IA_64_ARCHEXT	(PT_LOPROC + 0)	/* arch extension bits */
#परिभाषय PT_IA_64_UNWIND		(PT_LOPROC + 1)	/* ia64 unwind bits */
#परिभाषय PT_IA_64_HP_OPT_ANOT	(PT_LOOS + 0x12)
#परिभाषय PT_IA_64_HP_HSL_ANOT	(PT_LOOS + 0x13)
#परिभाषय PT_IA_64_HP_राशिः	(PT_LOOS + 0x14)

/* Processor specific flags for the Phdr p_flags field.  */
#परिभाषय PF_IA_64_NORECOV	0x80000000	/* spec insns w/o recovery */

/* Processor specific values for the Shdr sh_type field.  */
#परिभाषय SHT_IA_64_EXT		(SHT_LOPROC + 0) /* extension bits */
#परिभाषय SHT_IA_64_UNWIND	(SHT_LOPROC + 1) /* unwind bits */

/* Processor specific flags for the Shdr sh_flags field.  */
#परिभाषय SHF_IA_64_SHORT		0x10000000	/* section near gp */
#परिभाषय SHF_IA_64_NORECOV	0x20000000	/* spec insns w/o recovery */

/* Processor specific values for the Dyn d_tag field.  */
#परिभाषय DT_IA_64_PLT_RESERVE	(DT_LOPROC + 0)
#परिभाषय DT_IA_64_अङ्कः		1

/* IA-64 relocations.  */
#परिभाषय R_IA64_NONE		0x00	/* none */
#परिभाषय R_IA64_IMM14		0x21	/* symbol + addend, add imm14 */
#परिभाषय R_IA64_IMM22		0x22	/* symbol + addend, add imm22 */
#परिभाषय R_IA64_IMM64		0x23	/* symbol + addend, mov imm64 */
#परिभाषय R_IA64_DIR32MSB		0x24	/* symbol + addend, data4 MSB */
#परिभाषय R_IA64_DIR32LSB		0x25	/* symbol + addend, data4 LSB */
#परिभाषय R_IA64_DIR64MSB		0x26	/* symbol + addend, data8 MSB */
#परिभाषय R_IA64_DIR64LSB		0x27	/* symbol + addend, data8 LSB */
#परिभाषय R_IA64_GPREL22		0x2a	/* @gprel(sym + add), add imm22 */
#परिभाषय R_IA64_GPREL64I		0x2b	/* @gprel(sym + add), mov imm64 */
#परिभाषय R_IA64_GPREL32MSB	0x2c	/* @gprel(sym + add), data4 MSB */
#परिभाषय R_IA64_GPREL32LSB	0x2d	/* @gprel(sym + add), data4 LSB */
#परिभाषय R_IA64_GPREL64MSB	0x2e	/* @gprel(sym + add), data8 MSB */
#परिभाषय R_IA64_GPREL64LSB	0x2f	/* @gprel(sym + add), data8 LSB */
#परिभाषय R_IA64_LTOFF22		0x32	/* @ltoff(sym + add), add imm22 */
#परिभाषय R_IA64_LTOFF64I		0x33	/* @ltoff(sym + add), mov imm64 */
#परिभाषय R_IA64_PLTOFF22		0x3a	/* @pltoff(sym + add), add imm22 */
#परिभाषय R_IA64_PLTOFF64I	0x3b	/* @pltoff(sym + add), mov imm64 */
#परिभाषय R_IA64_PLTOFF64MSB	0x3e	/* @pltoff(sym + add), data8 MSB */
#परिभाषय R_IA64_PLTOFF64LSB	0x3f	/* @pltoff(sym + add), data8 LSB */
#परिभाषय R_IA64_FPTR64I		0x43	/* @fptr(sym + add), mov imm64 */
#परिभाषय R_IA64_FPTR32MSB	0x44	/* @fptr(sym + add), data4 MSB */
#परिभाषय R_IA64_FPTR32LSB	0x45	/* @fptr(sym + add), data4 LSB */
#परिभाषय R_IA64_FPTR64MSB	0x46	/* @fptr(sym + add), data8 MSB */
#परिभाषय R_IA64_FPTR64LSB	0x47	/* @fptr(sym + add), data8 LSB */
#परिभाषय R_IA64_PCREL60B		0x48	/* @pcrel(sym + add), brl */
#परिभाषय R_IA64_PCREL21B		0x49	/* @pcrel(sym + add), ptb, call */
#परिभाषय R_IA64_PCREL21M		0x4a	/* @pcrel(sym + add), chk.s */
#परिभाषय R_IA64_PCREL21F		0x4b	/* @pcrel(sym + add), fchkf */
#परिभाषय R_IA64_PCREL32MSB	0x4c	/* @pcrel(sym + add), data4 MSB */
#परिभाषय R_IA64_PCREL32LSB	0x4d	/* @pcrel(sym + add), data4 LSB */
#परिभाषय R_IA64_PCREL64MSB	0x4e	/* @pcrel(sym + add), data8 MSB */
#परिभाषय R_IA64_PCREL64LSB	0x4f	/* @pcrel(sym + add), data8 LSB */
#परिभाषय R_IA64_LTOFF_FPTR22	0x52	/* @ltoff(@fptr(s+a)), imm22 */
#परिभाषय R_IA64_LTOFF_FPTR64I	0x53	/* @ltoff(@fptr(s+a)), imm64 */
#परिभाषय R_IA64_LTOFF_FPTR32MSB	0x54	/* @ltoff(@fptr(s+a)), data4 MSB */
#परिभाषय R_IA64_LTOFF_FPTR32LSB	0x55	/* @ltoff(@fptr(s+a)), data4 LSB */
#परिभाषय R_IA64_LTOFF_FPTR64MSB	0x56	/* @ltoff(@fptr(s+a)), data8 MSB */
#परिभाषय R_IA64_LTOFF_FPTR64LSB	0x57	/* @ltoff(@fptr(s+a)), data8 LSB */
#परिभाषय R_IA64_SEGREL32MSB	0x5c	/* @segrel(sym + add), data4 MSB */
#परिभाषय R_IA64_SEGREL32LSB	0x5d	/* @segrel(sym + add), data4 LSB */
#परिभाषय R_IA64_SEGREL64MSB	0x5e	/* @segrel(sym + add), data8 MSB */
#परिभाषय R_IA64_SEGREL64LSB	0x5f	/* @segrel(sym + add), data8 LSB */
#परिभाषय R_IA64_SECREL32MSB	0x64	/* @secrel(sym + add), data4 MSB */
#परिभाषय R_IA64_SECREL32LSB	0x65	/* @secrel(sym + add), data4 LSB */
#परिभाषय R_IA64_SECREL64MSB	0x66	/* @secrel(sym + add), data8 MSB */
#परिभाषय R_IA64_SECREL64LSB	0x67	/* @secrel(sym + add), data8 LSB */
#परिभाषय R_IA64_REL32MSB		0x6c	/* data 4 + REL */
#परिभाषय R_IA64_REL32LSB		0x6d	/* data 4 + REL */
#परिभाषय R_IA64_REL64MSB		0x6e	/* data 8 + REL */
#परिभाषय R_IA64_REL64LSB		0x6f	/* data 8 + REL */
#परिभाषय R_IA64_LTV32MSB		0x74	/* symbol + addend, data4 MSB */
#परिभाषय R_IA64_LTV32LSB		0x75	/* symbol + addend, data4 LSB */
#परिभाषय R_IA64_LTV64MSB		0x76	/* symbol + addend, data8 MSB */
#परिभाषय R_IA64_LTV64LSB		0x77	/* symbol + addend, data8 LSB */
#परिभाषय R_IA64_PCREL21BI	0x79	/* @pcrel(sym + add), 21bit inst */
#परिभाषय R_IA64_PCREL22		0x7a	/* @pcrel(sym + add), 22bit inst */
#परिभाषय R_IA64_PCREL64I		0x7b	/* @pcrel(sym + add), 64bit inst */
#परिभाषय R_IA64_IPLTMSB		0x80	/* dynamic reloc, imported PLT, MSB */
#परिभाषय R_IA64_IPLTLSB		0x81	/* dynamic reloc, imported PLT, LSB */
#परिभाषय R_IA64_COPY		0x84	/* copy relocation */
#परिभाषय R_IA64_SUB		0x85	/* Addend and symbol difference */
#परिभाषय R_IA64_LTOFF22X		0x86	/* LTOFF22, relaxable.  */
#परिभाषय R_IA64_LDXMOV		0x87	/* Use of LTOFF22X.  */
#परिभाषय R_IA64_TPREL14		0x91	/* @tprel(sym + add), imm14 */
#परिभाषय R_IA64_TPREL22		0x92	/* @tprel(sym + add), imm22 */
#परिभाषय R_IA64_TPREL64I		0x93	/* @tprel(sym + add), imm64 */
#परिभाषय R_IA64_TPREL64MSB	0x96	/* @tprel(sym + add), data8 MSB */
#परिभाषय R_IA64_TPREL64LSB	0x97	/* @tprel(sym + add), data8 LSB */
#परिभाषय R_IA64_LTOFF_TPREL22	0x9a	/* @ltoff(@tprel(s+a)), imm2 */
#परिभाषय R_IA64_DTPMOD64MSB	0xa6	/* @dtpmod(sym + add), data8 MSB */
#परिभाषय R_IA64_DTPMOD64LSB	0xa7	/* @dtpmod(sym + add), data8 LSB */
#परिभाषय R_IA64_LTOFF_DTPMOD22	0xaa	/* @ltoff(@dtpmod(sym + add)), imm22 */
#परिभाषय R_IA64_DTPREL14		0xb1	/* @dtprel(sym + add), imm14 */
#परिभाषय R_IA64_DTPREL22		0xb2	/* @dtprel(sym + add), imm22 */
#परिभाषय R_IA64_DTPREL64I	0xb3	/* @dtprel(sym + add), imm64 */
#परिभाषय R_IA64_DTPREL32MSB	0xb4	/* @dtprel(sym + add), data4 MSB */
#परिभाषय R_IA64_DTPREL32LSB	0xb5	/* @dtprel(sym + add), data4 LSB */
#परिभाषय R_IA64_DTPREL64MSB	0xb6	/* @dtprel(sym + add), data8 MSB */
#परिभाषय R_IA64_DTPREL64LSB	0xb7	/* @dtprel(sym + add), data8 LSB */
#परिभाषय R_IA64_LTOFF_DTPREL22	0xba	/* @ltoff(@dtprel(s+a)), imm22 */

/* SH specific declarations */

/* Processor specific flags for the ELF header e_flags field.  */
#परिभाषय EF_SH_MACH_आवरणम्		0x1f
#परिभाषय EF_SH_UNKNOWN		0x0
#परिभाषय EF_SH1			0x1
#परिभाषय EF_SH2			0x2
#परिभाषय EF_SH3			0x3
#परिभाषय EF_SH_DSP		0x4
#परिभाषय EF_SH3_DSP		0x5
#परिभाषय EF_SH4AL_DSP		0x6
#परिभाषय EF_SH3E			0x8
#परिभाषय EF_SH4			0x9
#परिभाषय EF_SH2E			0xb
#परिभाषय EF_SH4A			0xc
#परिभाषय EF_SH2A			0xd
#परिभाषय EF_SH4_NOFPU		0x10
#परिभाषय EF_SH4A_NOFPU		0x11
#परिभाषय EF_SH4_NOMMU_NOFPU	0x12
#परिभाषय EF_SH2A_NOFPU		0x13
#परिभाषय EF_SH3_NOMMU		0x14
#परिभाषय EF_SH2A_SH4_NOFPU	0x15
#परिभाषय EF_SH2A_SH3_NOFPU	0x16
#परिभाषय EF_SH2A_SH4		0x17
#परिभाषय EF_SH2A_SH3E		0x18

/* SH relocs.  */
#परिभाषय	R_SH_NONE		0
#परिभाषय	R_SH_DIR32		1
#परिभाषय	R_SH_REL32		2
#परिभाषय	R_SH_DIR8WPN		3
#परिभाषय	R_SH_IND12W		4
#परिभाषय	R_SH_DIR8WPL		5
#परिभाषय	R_SH_DIR8WPZ		6
#परिभाषय	R_SH_DIR8BP		7
#परिभाषय	R_SH_DIR8W		8
#परिभाषय	R_SH_DIR8L		9
#परिभाषय	R_SH_SWITCH16		25
#परिभाषय	R_SH_SWITCH32		26
#परिभाषय	R_SH_उपयुङ्क्ते		27
#परिभाषय	R_SH_गणनम्		28
#परिभाषय	R_SH_ALIGN		29
#परिभाषय	R_SH_संहिता		30
#परिभाषय	R_SH_दत्त		31
#परिभाषय	R_SH_LABEL		32
#परिभाषय	R_SH_SWITCH8		33
#परिभाषय	R_SH_GNU_VTINHERIT	34
#परिभाषय	R_SH_GNU_VTENTRY	35
#परिभाषय	R_SH_TLS_GD_32		144
#परिभाषय	R_SH_TLS_LD_32		145
#परिभाषय	R_SH_TLS_LDO_32		146
#परिभाषय	R_SH_TLS_IE_32		147
#परिभाषय	R_SH_TLS_LE_32		148
#परिभाषय	R_SH_TLS_DTPMOD32	149
#परिभाषय	R_SH_TLS_DTPOFF32	150
#परिभाषय	R_SH_TLS_TPOFF32	151
#परिभाषय	R_SH_GOT32		160
#परिभाषय	R_SH_PLT32		161
#परिभाषय	R_SH_COPY		162
#परिभाषय	R_SH_GLOB_DAT		163
#परिभाषय	R_SH_JMP_SLOT		164
#परिभाषय	R_SH_RELATIVE		165
#परिभाषय	R_SH_GOTOFF		166
#परिभाषय	R_SH_GOTPC		167
/* Keep this the last entry.  */
#परिभाषय	R_SH_अङ्कः		256

/* S/390 specific definitions.  */

/* Valid values for the e_flags field.  */

#परिभाषय EF_S390_उच्चः_GPRS    0x00000001  /* High GPRs kernel facility needed.  */

/* Additional s390 relocs */

#परिभाषय R_390_NONE		0	/* No reloc.  */
#परिभाषय R_390_8			1	/* Direct 8 bit.  */
#परिभाषय R_390_12		2	/* Direct 12 bit.  */
#परिभाषय R_390_16		3	/* Direct 16 bit.  */
#परिभाषय R_390_32		4	/* Direct 32 bit.  */
#परिभाषय R_390_PC32		5	/* PC relative 32 bit.	*/
#परिभाषय R_390_GOT12		6	/* 12 bit GOT offset.  */
#परिभाषय R_390_GOT32		7	/* 32 bit GOT offset.  */
#परिभाषय R_390_PLT32		8	/* 32 bit PC relative PLT address.  */
#परिभाषय R_390_COPY		9	/* Copy symbol at runtime.  */
#परिभाषय R_390_GLOB_DAT		10	/* Create GOT entry.  */
#परिभाषय R_390_JMP_SLOT		11	/* Create PLT entry.  */
#परिभाषय R_390_RELATIVE		12	/* Adjust by program base.  */
#परिभाषय R_390_GOTOFF32		13	/* 32 bit offset to GOT.	 */
#परिभाषय R_390_GOTPC		14	/* 32 bit PC relative offset to GOT.  */
#परिभाषय R_390_GOT16		15	/* 16 bit GOT offset.  */
#परिभाषय R_390_PC16		16	/* PC relative 16 bit.	*/
#परिभाषय R_390_PC16DBL		17	/* PC relative 16 bit shifted by 1.  */
#परिभाषय R_390_PLT16DBL		18	/* 16 bit PC rel. PLT shifted by 1.  */
#परिभाषय R_390_PC32DBL		19	/* PC relative 32 bit shifted by 1.  */
#परिभाषय R_390_PLT32DBL		20	/* 32 bit PC rel. PLT shifted by 1.  */
#परिभाषय R_390_GOTPCDBL		21	/* 32 bit PC rel. GOT shifted by 1.  */
#परिभाषय R_390_64		22	/* Direct 64 bit.  */
#परिभाषय R_390_PC64		23	/* PC relative 64 bit.	*/
#परिभाषय R_390_GOT64		24	/* 64 bit GOT offset.  */
#परिभाषय R_390_PLT64		25	/* 64 bit PC relative PLT address.  */
#परिभाषय R_390_GOTENT		26	/* 32 bit PC rel. to GOT entry >> 1. */
#परिभाषय R_390_GOTOFF16		27	/* 16 bit offset to GOT. */
#परिभाषय R_390_GOTOFF64		28	/* 64 bit offset to GOT. */
#परिभाषय R_390_GOTPLT12		29	/* 12 bit offset to jump slot.	*/
#परिभाषय R_390_GOTPLT16		30	/* 16 bit offset to jump slot.	*/
#परिभाषय R_390_GOTPLT32		31	/* 32 bit offset to jump slot.	*/
#परिभाषय R_390_GOTPLT64		32	/* 64 bit offset to jump slot.	*/
#परिभाषय R_390_GOTPLTENT		33	/* 32 bit rel. offset to jump slot.  */
#परिभाषय R_390_PLTOFF16		34	/* 16 bit offset from GOT to PLT. */
#परिभाषय R_390_PLTOFF32		35	/* 32 bit offset from GOT to PLT. */
#परिभाषय R_390_PLTOFF64		36	/* 16 bit offset from GOT to PLT. */
#परिभाषय R_390_TLS_आरोपय		37	/* Tag for load insn in TLS code.  */
#परिभाषय R_390_TLS_GDCALL	38	/* Tag for function call in general
					   dynamic TLS code. */
#परिभाषय R_390_TLS_LDCALL	39	/* Tag for function call in local
					   dynamic TLS code. */
#परिभाषय R_390_TLS_GD32		40	/* Direct 32 bit for general dynamic
					   thread local data.  */
#परिभाषय R_390_TLS_GD64		41	/* Direct 64 bit for general dynamic
					  thread local data.  */
#परिभाषय R_390_TLS_GOTIE12	42	/* 12 bit GOT offset for static TLS
					   block offset.  */
#परिभाषय R_390_TLS_GOTIE32	43	/* 32 bit GOT offset for static TLS
					   block offset.  */
#परिभाषय R_390_TLS_GOTIE64	44	/* 64 bit GOT offset for static TLS
					   block offset. */
#परिभाषय R_390_TLS_LDM32		45	/* Direct 32 bit for local dynamic
					   thread local data in LE code.  */
#परिभाषय R_390_TLS_LDM64		46	/* Direct 64 bit for local dynamic
					   thread local data in LE code.  */
#परिभाषय R_390_TLS_IE32		47	/* 32 bit address of GOT entry for
					   negated static TLS block offset.  */
#परिभाषय R_390_TLS_IE64		48	/* 64 bit address of GOT entry for
					   negated static TLS block offset.  */
#परिभाषय R_390_TLS_IEENT		49	/* 32 bit rel. offset to GOT entry for
					   negated static TLS block offset.  */
#परिभाषय R_390_TLS_LE32		50	/* 32 bit negated offset relative to
					   static TLS block.  */
#परिभाषय R_390_TLS_LE64		51	/* 64 bit negated offset relative to
					   static TLS block.  */
#परिभाषय R_390_TLS_LDO32		52	/* 32 bit offset relative to TLS
					   block.  */
#परिभाषय R_390_TLS_LDO64		53	/* 64 bit offset relative to TLS
					   block.  */
#परिभाषय R_390_TLS_DTPMOD	54	/* ID of module containing symbol.  */
#परिभाषय R_390_TLS_DTPOFF	55	/* Offset in TLS block.	 */
#परिभाषय R_390_TLS_TPOFF		56	/* Negated offset in static TLS
					   block.  */
#परिभाषय R_390_20		57	/* Direct 20 bit.  */
#परिभाषय R_390_GOT20		58	/* 20 bit GOT offset.  */
#परिभाषय R_390_GOTPLT20		59	/* 20 bit offset to jump slot.  */
#परिभाषय R_390_TLS_GOTIE20	60	/* 20 bit GOT offset for static TLS
					   block offset.  */
#परिभाषय R_390_IRELATIVE         61      /* STT_GNU_IFUNC relocation.  */
/* Keep this the last entry.  */
#परिभाषय R_390_अङ्कः		62


/* CRIS relocations.  */
#परिभाषय R_CRIS_NONE		0
#परिभाषय R_CRIS_8		1
#परिभाषय R_CRIS_16		2
#परिभाषय R_CRIS_32		3
#परिभाषय R_CRIS_8_PCREL		4
#परिभाषय R_CRIS_16_PCREL		5
#परिभाषय R_CRIS_32_PCREL		6
#परिभाषय R_CRIS_GNU_VTINHERIT	7
#परिभाषय R_CRIS_GNU_VTENTRY	8
#परिभाषय R_CRIS_COPY		9
#परिभाषय R_CRIS_GLOB_DAT		10
#परिभाषय R_CRIS_JUMP_SLOT	11
#परिभाषय R_CRIS_RELATIVE		12
#परिभाषय R_CRIS_16_GOT		13
#परिभाषय R_CRIS_32_GOT		14
#परिभाषय R_CRIS_16_GOTPLT	15
#परिभाषय R_CRIS_32_GOTPLT	16
#परिभाषय R_CRIS_32_GOTREL	17
#परिभाषय R_CRIS_32_PLT_GOTREL	18
#परिभाषय R_CRIS_32_PLT_PCREL	19

#परिभाषय R_CRIS_अङ्कः		20


/* AMD x86-64 relocations.  */
#परिभाषय R_X86_64_NONE		0	/* No reloc */
#परिभाषय R_X86_64_64		1	/* Direct 64 bit  */
#परिभाषय R_X86_64_PC32		2	/* PC relative 32 bit signed */
#परिभाषय R_X86_64_GOT32		3	/* 32 bit GOT entry */
#परिभाषय R_X86_64_PLT32		4	/* 32 bit PLT address */
#परिभाषय R_X86_64_COPY		5	/* Copy symbol at runtime */
#परिभाषय R_X86_64_GLOB_DAT	6	/* Create GOT entry */
#परिभाषय R_X86_64_JUMP_SLOT	7	/* Create PLT entry */
#परिभाषय R_X86_64_RELATIVE	8	/* Adjust by program base */
#परिभाषय R_X86_64_GOTPCREL	9	/* 32 bit signed PC relative
					   offset to GOT */
#परिभाषय R_X86_64_32		10	/* Direct 32 bit zero extended */
#परिभाषय R_X86_64_32S		11	/* Direct 32 bit sign extended */
#परिभाषय R_X86_64_16		12	/* Direct 16 bit zero extended */
#परिभाषय R_X86_64_PC16		13	/* 16 bit sign extended pc relative */
#परिभाषय R_X86_64_8		14	/* Direct 8 bit sign extended  */
#परिभाषय R_X86_64_PC8		15	/* 8 bit sign extended pc relative */
#परिभाषय R_X86_64_DTPMOD64	16	/* ID of module containing symbol */
#परिभाषय R_X86_64_DTPOFF64	17	/* Offset in module's TLS block */
#परिभाषय R_X86_64_TPOFF64	18	/* Offset in initial TLS block */
#परिभाषय R_X86_64_TLSGD		19	/* 32 bit signed PC relative offset
					   to two GOT entries for GD symbol */
#परिभाषय R_X86_64_TLSLD		20	/* 32 bit signed PC relative offset
					   to two GOT entries for LD symbol */
#परिभाषय R_X86_64_DTPOFF32	21	/* Offset in TLS block */
#परिभाषय R_X86_64_GOTTPOFF	22	/* 32 bit signed PC relative offset
					   to GOT entry for IE symbol */
#परिभाषय R_X86_64_TPOFF32	23	/* Offset in initial TLS block */
#परिभाषय R_X86_64_PC64		24	/* PC relative 64 bit */
#परिभाषय R_X86_64_GOTOFF64	25	/* 64 bit offset to GOT */
#परिभाषय R_X86_64_GOTPC32	26	/* 32 bit signed pc relative
					   offset to GOT */
#परिभाषय R_X86_64_GOT64		27	/* 64-bit GOT entry offset */
#परिभाषय R_X86_64_GOTPCREL64	28	/* 64-bit PC relative offset
					   to GOT entry */
#परिभाषय R_X86_64_GOTPC64	29	/* 64-bit PC relative offset to GOT */
#परिभाषय R_X86_64_GOTPLT64	30 	/* like GOT64, says PLT entry needed */
#परिभाषय R_X86_64_PLTOFF64	31	/* 64-bit GOT relative offset
					   to PLT entry */
#परिभाषय R_X86_64_SIZE32		32	/* Size of symbol plus 32-bit addend */
#परिभाषय R_X86_64_SIZE64		33	/* Size of symbol plus 64-bit addend */
#परिभाषय R_X86_64_GOTPC32_TLSDESC 34	/* GOT offset for TLS descriptor.  */
#परिभाषय R_X86_64_TLSDESC_CALL   35	/* Marker for call through TLS
					   descriptor.  */
#परिभाषय R_X86_64_TLSDESC        36	/* TLS descriptor.  */
#परिभाषय R_X86_64_IRELATIVE	37	/* Adjust indirectly by program base */
#परिभाषय R_X86_64_RELATIVE64	38	/* 64-bit adjust by program base */
#परिभाषय R_X86_64_GOTPCRELX	41	/* like GOTPCREL, but optionally with
					   linker optimizations */
#परिभाषय R_X86_64_REX_GOTPCRELX	42      /* like GOTPCRELX, but a REX prefix
					   is present */

#परिभाषय R_X86_64_अङ्कः		43

/* x86-64 sh_type values.  */
#परिभाषय SHT_X86_64_UNWIND       0x70000001 /* Unwind information.  */

/* AM33 relocations.  */
#परिभाषय R_MN10300_NONE		0	/* No reloc.  */
#परिभाषय R_MN10300_32		1	/* Direct 32 bit.  */
#परिभाषय R_MN10300_16		2	/* Direct 16 bit.  */
#परिभाषय R_MN10300_8		3	/* Direct 8 bit.  */
#परिभाषय R_MN10300_PCREL32	4	/* PC-relative 32-bit.  */
#परिभाषय R_MN10300_PCREL16	5	/* PC-relative 16-bit signed.  */
#परिभाषय R_MN10300_PCREL8	6	/* PC-relative 8-bit signed.  */
#परिभाषय R_MN10300_GNU_VTINHERIT	7	/* Ancient C++ vtable garbage... */
#परिभाषय R_MN10300_GNU_VTENTRY	8	/* ... collection annotation.  */
#परिभाषय R_MN10300_24		9	/* Direct 24 bit.  */
#परिभाषय R_MN10300_GOTPC32	10	/* 32-bit PCrel offset to GOT.  */
#परिभाषय R_MN10300_GOTPC16	11	/* 16-bit PCrel offset to GOT.  */
#परिभाषय R_MN10300_GOTOFF32	12	/* 32-bit offset from GOT.  */
#परिभाषय R_MN10300_GOTOFF24	13	/* 24-bit offset from GOT.  */
#परिभाषय R_MN10300_GOTOFF16	14	/* 16-bit offset from GOT.  */
#परिभाषय R_MN10300_PLT32		15	/* 32-bit PCrel to PLT entry.  */
#परिभाषय R_MN10300_PLT16		16	/* 16-bit PCrel to PLT entry.  */
#परिभाषय R_MN10300_GOT32		17	/* 32-bit offset to GOT entry.  */
#परिभाषय R_MN10300_GOT24		18	/* 24-bit offset to GOT entry.  */
#परिभाषय R_MN10300_GOT16		19	/* 16-bit offset to GOT entry.  */
#परिभाषय R_MN10300_COPY		20	/* Copy symbol at runtime.  */
#परिभाषय R_MN10300_GLOB_DAT	21	/* Create GOT entry.  */
#परिभाषय R_MN10300_JMP_SLOT	22	/* Create PLT entry.  */
#परिभाषय R_MN10300_RELATIVE	23	/* Adjust by program base.  */
#परिभाषय R_MN10300_TLS_GD	24	/* 32-bit offset for global dynamic.  */
#परिभाषय R_MN10300_TLS_LD	25	/* 32-bit offset for local dynamic.  */
#परिभाषय R_MN10300_TLS_LDO	26	/* Module-relative offset.  */
#परिभाषय R_MN10300_TLS_GOTIE	27	/* GOT offset for static TLS block
					   offset.  */
#परिभाषय R_MN10300_TLS_IE	28	/* GOT address for static TLS block
					   offset.  */
#परिभाषय R_MN10300_TLS_LE	29	/* Offset relative to static TLS
					   block.  */
#परिभाषय R_MN10300_TLS_DTPMOD	30	/* ID of module containing symbol.  */
#परिभाषय R_MN10300_TLS_DTPOFF	31	/* Offset in module TLS block.  */
#परिभाषय R_MN10300_TLS_TPOFF	32	/* Offset in static TLS block.  */
#परिभाषय R_MN10300_SYM_DIFF	33	/* Adjustment for next reloc as needed
					   by linker relaxation.  */
#परिभाषय R_MN10300_ALIGN		34	/* Alignment requirement for linker
					   relaxation.  */
#परिभाषय R_MN10300_अङ्कः		35


/* M32R relocs.  */
#परिभाषय R_M32R_NONE		0	/* No reloc. */
#परिभाषय R_M32R_16		1	/* Direct 16 bit. */
#परिभाषय R_M32R_32		2	/* Direct 32 bit. */
#परिभाषय R_M32R_24		3	/* Direct 24 bit. */
#परिभाषय R_M32R_10_PCREL		4	/* PC relative 10 bit shifted. */
#परिभाषय R_M32R_18_PCREL		5	/* PC relative 18 bit shifted. */
#परिभाषय R_M32R_26_PCREL		6	/* PC relative 26 bit shifted. */
#परिभाषय R_M32R_HI16_ULO		7	/* High 16 bit with unsigned low. */
#परिभाषय R_M32R_HI16_SLO		8	/* High 16 bit with signed low. */
#परिभाषय R_M32R_LO16		9	/* Low 16 bit. */
#परिभाषय R_M32R_SDA16		10	/* 16 bit offset in SDA. */
#परिभाषय R_M32R_GNU_VTINHERIT	11
#परिभाषय R_M32R_GNU_VTENTRY	12
/* M32R relocs use SHT_RELA.  */
#परिभाषय R_M32R_16_RELA		33	/* Direct 16 bit. */
#परिभाषय R_M32R_32_RELA		34	/* Direct 32 bit. */
#परिभाषय R_M32R_24_RELA		35	/* Direct 24 bit. */
#परिभाषय R_M32R_10_PCREL_RELA	36	/* PC relative 10 bit shifted. */
#परिभाषय R_M32R_18_PCREL_RELA	37	/* PC relative 18 bit shifted. */
#परिभाषय R_M32R_26_PCREL_RELA	38	/* PC relative 26 bit shifted. */
#परिभाषय R_M32R_HI16_ULO_RELA	39	/* High 16 bit with unsigned low */
#परिभाषय R_M32R_HI16_SLO_RELA	40	/* High 16 bit with signed low */
#परिभाषय R_M32R_LO16_RELA	41	/* Low 16 bit */
#परिभाषय R_M32R_SDA16_RELA	42	/* 16 bit offset in SDA */
#परिभाषय R_M32R_RELA_GNU_VTINHERIT	43
#परिभाषय R_M32R_RELA_GNU_VTENTRY	44
#परिभाषय R_M32R_REL32		45	/* PC relative 32 bit.  */

#परिभाषय R_M32R_GOT24		48	/* 24 bit GOT entry */
#परिभाषय R_M32R_26_PLTREL	49	/* 26 bit PC relative to PLT shifted */
#परिभाषय R_M32R_COPY		50	/* Copy symbol at runtime */
#परिभाषय R_M32R_GLOB_DAT		51	/* Create GOT entry */
#परिभाषय R_M32R_JMP_SLOT		52	/* Create PLT entry */
#परिभाषय R_M32R_RELATIVE		53	/* Adjust by program base */
#परिभाषय R_M32R_GOTOFF		54	/* 24 bit offset to GOT */
#परिभाषय R_M32R_GOTPC24		55	/* 24 bit PC relative offset to GOT */
#परिभाषय R_M32R_GOT16_HI_ULO	56	/* High 16 bit GOT entry with unsigned
नीचः*/
#परिभाषय R_M32R_GOT16_HI_SLO	57	/* High 16 bit GOT entry with signed
नीचः*/
#परिभाषय R_M32R_GOT16_LO		58	/* Low 16 bit GOT entry */
#परिभाषय R_M32R_GOTPC_HI_ULO	59	/* High 16 bit PC relative offset to
					   GOT with unsigned low */
#परिभाषय R_M32R_GOTPC_HI_SLO	60	/* High 16 bit PC relative offset to
					   GOT with signed low */
#परिभाषय R_M32R_GOTPC_LO		61	/* Low 16 bit PC relative offset to
					   GOT */
#परिभाषय R_M32R_GOTOFF_HI_ULO	62	/* High 16 bit offset to GOT
					   with unsigned low */
#परिभाषय R_M32R_GOTOFF_HI_SLO	63	/* High 16 bit offset to GOT
					   with signed low */
#परिभाषय R_M32R_GOTOFF_LO	64	/* Low 16 bit offset to GOT */
#परिभाषय R_M32_R_अङ्कः		256	/* Keep this the last entry. */


/* TILEPro relocations.  */
#परिभाषय R_TILEPRO_NONE		0	/* No reloc */
#परिभाषय R_TILEPRO_32		1	/* Direct 32 bit */
#परिभाषय R_TILEPRO_16		2	/* Direct 16 bit */
#परिभाषय R_TILEPRO_8		3	/* Direct 8 bit */
#परिभाषय R_TILEPRO_32_PCREL	4	/* PC relative 32 bit */
#परिभाषय R_TILEPRO_16_PCREL	5	/* PC relative 16 bit */
#परिभाषय R_TILEPRO_8_PCREL	6	/* PC relative 8 bit */
#परिभाषय R_TILEPRO_LO16		7	/* Low 16 bit */
#परिभाषय R_TILEPRO_HI16		8	/* High 16 bit */
#परिभाषय R_TILEPRO_HA16		9	/* High 16 bit, adjusted */
#परिभाषय R_TILEPRO_COPY		10	/* Copy relocation */
#परिभाषय R_TILEPRO_GLOB_DAT	11	/* Create GOT entry */
#परिभाषय R_TILEPRO_JMP_SLOT	12	/* Create PLT entry */
#परिभाषय R_TILEPRO_RELATIVE	13	/* Adjust by program base */
#परिभाषय R_TILEPRO_BROFF_X1	14	/* X1 pipe branch offset */
#परिभाषय R_TILEPRO_JOFFLONG_X1	15	/* X1 pipe jump offset */
#परिभाषय R_TILEPRO_JOFFLONG_X1_PLT 16	/* X1 pipe jump offset to PLT */
#परिभाषय R_TILEPRO_IMM8_X0	17	/* X0 pipe 8-bit */
#परिभाषय R_TILEPRO_IMM8_Y0	18	/* Y0 pipe 8-bit */
#परिभाषय R_TILEPRO_IMM8_X1	19	/* X1 pipe 8-bit */
#परिभाषय R_TILEPRO_IMM8_Y1	20	/* Y1 pipe 8-bit */
#परिभाषय R_TILEPRO_MT_IMM15_X1	21	/* X1 pipe mtspr */
#परिभाषय R_TILEPRO_MF_IMM15_X1	22	/* X1 pipe mfspr */
#परिभाषय R_TILEPRO_IMM16_X0	23	/* X0 pipe 16-bit */
#परिभाषय R_TILEPRO_IMM16_X1	24	/* X1 pipe 16-bit */
#परिभाषय R_TILEPRO_IMM16_X0_LO	25	/* X0 pipe low 16-bit */
#परिभाषय R_TILEPRO_IMM16_X1_LO	26	/* X1 pipe low 16-bit */
#परिभाषय R_TILEPRO_IMM16_X0_HI	27	/* X0 pipe high 16-bit */
#परिभाषय R_TILEPRO_IMM16_X1_HI	28	/* X1 pipe high 16-bit */
#परिभाषय R_TILEPRO_IMM16_X0_HA	29	/* X0 pipe high 16-bit, adjusted */
#परिभाषय R_TILEPRO_IMM16_X1_HA	30	/* X1 pipe high 16-bit, adjusted */
#परिभाषय R_TILEPRO_IMM16_X0_PCREL 31	/* X0 pipe PC relative 16 bit */
#परिभाषय R_TILEPRO_IMM16_X1_PCREL 32	/* X1 pipe PC relative 16 bit */
#परिभाषय R_TILEPRO_IMM16_X0_LO_PCREL 33	/* X0 pipe PC relative low 16 bit */
#परिभाषय R_TILEPRO_IMM16_X1_LO_PCREL 34	/* X1 pipe PC relative low 16 bit */
#परिभाषय R_TILEPRO_IMM16_X0_HI_PCREL 35	/* X0 pipe PC relative high 16 bit */
#परिभाषय R_TILEPRO_IMM16_X1_HI_PCREL 36	/* X1 pipe PC relative high 16 bit */
#परिभाषय R_TILEPRO_IMM16_X0_HA_PCREL 37	/* X0 pipe PC relative ha() 16 bit */
#परिभाषय R_TILEPRO_IMM16_X1_HA_PCREL 38	/* X1 pipe PC relative ha() 16 bit */
#परिभाषय R_TILEPRO_IMM16_X0_GOT	39	/* X0 pipe 16-bit GOT offset */
#परिभाषय R_TILEPRO_IMM16_X1_GOT	40	/* X1 pipe 16-bit GOT offset */
#परिभाषय R_TILEPRO_IMM16_X0_GOT_LO 41	/* X0 pipe low 16-bit GOT offset */
#परिभाषय R_TILEPRO_IMM16_X1_GOT_LO 42	/* X1 pipe low 16-bit GOT offset */
#परिभाषय R_TILEPRO_IMM16_X0_GOT_HI 43	/* X0 pipe high 16-bit GOT offset */
#परिभाषय R_TILEPRO_IMM16_X1_GOT_HI 44	/* X1 pipe high 16-bit GOT offset */
#परिभाषय R_TILEPRO_IMM16_X0_GOT_HA 45	/* X0 pipe ha() 16-bit GOT offset */
#परिभाषय R_TILEPRO_IMM16_X1_GOT_HA 46	/* X1 pipe ha() 16-bit GOT offset */
#परिभाषय R_TILEPRO_MMSTART_X0	47	/* X0 pipe mm "start" */
#परिभाषय R_TILEPRO_MMEND_X0	48	/* X0 pipe mm "end" */
#परिभाषय R_TILEPRO_MMSTART_X1	49	/* X1 pipe mm "start" */
#परिभाषय R_TILEPRO_MMEND_X1	50	/* X1 pipe mm "end" */
#परिभाषय R_TILEPRO_SHAMT_X0	51	/* X0 pipe shift amount */
#परिभाषय R_TILEPRO_SHAMT_X1	52	/* X1 pipe shift amount */
#परिभाषय R_TILEPRO_SHAMT_Y0	53	/* Y0 pipe shift amount */
#परिभाषय R_TILEPRO_SHAMT_Y1	54	/* Y1 pipe shift amount */
#परिभाषय R_TILEPRO_DEST_IMM8_X1	55	/* X1 pipe destination 8-bit */
/* Relocs 56-59 are currently not defined.  */
#परिभाषय R_TILEPRO_TLS_GD_CALL	60	/* "jal" for TLS GD */
#परिभाषय R_TILEPRO_IMM8_X0_TLS_GD_सङ्कलय 61	/* X0 pipe "addi" for TLS GD */
#परिभाषय R_TILEPRO_IMM8_X1_TLS_GD_सङ्कलय 62	/* X1 pipe "addi" for TLS GD */
#परिभाषय R_TILEPRO_IMM8_Y0_TLS_GD_सङ्कलय 63	/* Y0 pipe "addi" for TLS GD */
#परिभाषय R_TILEPRO_IMM8_Y1_TLS_GD_सङ्कलय 64	/* Y1 pipe "addi" for TLS GD */
#परिभाषय R_TILEPRO_TLS_IE_आरोपय	65	/* "lw_tls" for TLS IE */
#परिभाषय R_TILEPRO_IMM16_X0_TLS_GD 66	/* X0 pipe 16-bit TLS GD offset */
#परिभाषय R_TILEPRO_IMM16_X1_TLS_GD 67	/* X1 pipe 16-bit TLS GD offset */
#परिभाषय R_TILEPRO_IMM16_X0_TLS_GD_LO 68	/* X0 pipe low 16-bit TLS GD offset */
#परिभाषय R_TILEPRO_IMM16_X1_TLS_GD_LO 69	/* X1 pipe low 16-bit TLS GD offset */
#परिभाषय R_TILEPRO_IMM16_X0_TLS_GD_HI 70	/* X0 pipe high 16-bit TLS GD offset */
#परिभाषय R_TILEPRO_IMM16_X1_TLS_GD_HI 71	/* X1 pipe high 16-bit TLS GD offset */
#परिभाषय R_TILEPRO_IMM16_X0_TLS_GD_HA 72	/* X0 pipe ha() 16-bit TLS GD offset */
#परिभाषय R_TILEPRO_IMM16_X1_TLS_GD_HA 73	/* X1 pipe ha() 16-bit TLS GD offset */
#परिभाषय R_TILEPRO_IMM16_X0_TLS_IE 74	/* X0 pipe 16-bit TLS IE offset */
#परिभाषय R_TILEPRO_IMM16_X1_TLS_IE 75	/* X1 pipe 16-bit TLS IE offset */
#परिभाषय R_TILEPRO_IMM16_X0_TLS_IE_LO 76	/* X0 pipe low 16-bit TLS IE offset */
#परिभाषय R_TILEPRO_IMM16_X1_TLS_IE_LO 77	/* X1 pipe low 16-bit TLS IE offset */
#परिभाषय R_TILEPRO_IMM16_X0_TLS_IE_HI 78	/* X0 pipe high 16-bit TLS IE offset */
#परिभाषय R_TILEPRO_IMM16_X1_TLS_IE_HI 79	/* X1 pipe high 16-bit TLS IE offset */
#परिभाषय R_TILEPRO_IMM16_X0_TLS_IE_HA 80	/* X0 pipe ha() 16-bit TLS IE offset */
#परिभाषय R_TILEPRO_IMM16_X1_TLS_IE_HA 81	/* X1 pipe ha() 16-bit TLS IE offset */
#परिभाषय R_TILEPRO_TLS_DTPMOD32	82	/* ID of module containing symbol */
#परिभाषय R_TILEPRO_TLS_DTPOFF32	83	/* Offset in TLS block */
#परिभाषय R_TILEPRO_TLS_TPOFF32	84	/* Offset in static TLS block */
#परिभाषय R_TILEPRO_IMM16_X0_TLS_LE 85	/* X0 pipe 16-bit TLS LE offset */
#परिभाषय R_TILEPRO_IMM16_X1_TLS_LE 86	/* X1 pipe 16-bit TLS LE offset */
#परिभाषय R_TILEPRO_IMM16_X0_TLS_LE_LO 87	/* X0 pipe low 16-bit TLS LE offset */
#परिभाषय R_TILEPRO_IMM16_X1_TLS_LE_LO 88	/* X1 pipe low 16-bit TLS LE offset */
#परिभाषय R_TILEPRO_IMM16_X0_TLS_LE_HI 89	/* X0 pipe high 16-bit TLS LE offset */
#परिभाषय R_TILEPRO_IMM16_X1_TLS_LE_HI 90	/* X1 pipe high 16-bit TLS LE offset */
#परिभाषय R_TILEPRO_IMM16_X0_TLS_LE_HA 91	/* X0 pipe ha() 16-bit TLS LE offset */
#परिभाषय R_TILEPRO_IMM16_X1_TLS_LE_HA 92	/* X1 pipe ha() 16-bit TLS LE offset */

#परिभाषय R_TILEPRO_GNU_VTINHERIT	128	/* GNU C++ vtable hierarchy */
#परिभाषय R_TILEPRO_GNU_VTENTRY	129	/* GNU C++ vtable member usage */

#परिभाषय R_TILEPRO_अङ्कः		130


/* TILE-Gx relocations.  */
#परिभाषय R_TILEGX_NONE		0	/* No reloc */
#परिभाषय R_TILEGX_64		1	/* Direct 64 bit */
#परिभाषय R_TILEGX_32		2	/* Direct 32 bit */
#परिभाषय R_TILEGX_16		3	/* Direct 16 bit */
#परिभाषय R_TILEGX_8		4	/* Direct 8 bit */
#परिभाषय R_TILEGX_64_PCREL	5	/* PC relative 64 bit */
#परिभाषय R_TILEGX_32_PCREL	6	/* PC relative 32 bit */
#परिभाषय R_TILEGX_16_PCREL	7	/* PC relative 16 bit */
#परिभाषय R_TILEGX_8_PCREL	8	/* PC relative 8 bit */
#परिभाषय R_TILEGX_HW0		9	/* hword 0 16-bit */
#परिभाषय R_TILEGX_HW1		10	/* hword 1 16-bit */
#परिभाषय R_TILEGX_HW2		11	/* hword 2 16-bit */
#परिभाषय R_TILEGX_HW3		12	/* hword 3 16-bit */
#परिभाषय R_TILEGX_HW0_चरमः	13	/* last hword 0 16-bit */
#परिभाषय R_TILEGX_HW1_चरमः	14	/* last hword 1 16-bit */
#परिभाषय R_TILEGX_HW2_चरमः	15	/* last hword 2 16-bit */
#परिभाषय R_TILEGX_COPY		16	/* Copy relocation */
#परिभाषय R_TILEGX_GLOB_DAT	17	/* Create GOT entry */
#परिभाषय R_TILEGX_JMP_SLOT	18	/* Create PLT entry */
#परिभाषय R_TILEGX_RELATIVE	19	/* Adjust by program base */
#परिभाषय R_TILEGX_BROFF_X1	20	/* X1 pipe branch offset */
#परिभाषय R_TILEGX_JUMPOFF_X1	21	/* X1 pipe jump offset */
#परिभाषय R_TILEGX_JUMPOFF_X1_PLT	22	/* X1 pipe jump offset to PLT */
#परिभाषय R_TILEGX_IMM8_X0	23	/* X0 pipe 8-bit */
#परिभाषय R_TILEGX_IMM8_Y0	24	/* Y0 pipe 8-bit */
#परिभाषय R_TILEGX_IMM8_X1	25	/* X1 pipe 8-bit */
#परिभाषय R_TILEGX_IMM8_Y1	26	/* Y1 pipe 8-bit */
#परिभाषय R_TILEGX_DEST_IMM8_X1	27	/* X1 pipe destination 8-bit */
#परिभाषय R_TILEGX_MT_IMM14_X1	28	/* X1 pipe mtspr */
#परिभाषय R_TILEGX_MF_IMM14_X1	29	/* X1 pipe mfspr */
#परिभाषय R_TILEGX_MMSTART_X0	30	/* X0 pipe mm "start" */
#परिभाषय R_TILEGX_MMEND_X0	31	/* X0 pipe mm "end" */
#परिभाषय R_TILEGX_SHAMT_X0	32	/* X0 pipe shift amount */
#परिभाषय R_TILEGX_SHAMT_X1	33	/* X1 pipe shift amount */
#परिभाषय R_TILEGX_SHAMT_Y0	34	/* Y0 pipe shift amount */
#परिभाषय R_TILEGX_SHAMT_Y1	35	/* Y1 pipe shift amount */
#परिभाषय R_TILEGX_IMM16_X0_HW0	36	/* X0 pipe hword 0 */
#परिभाषय R_TILEGX_IMM16_X1_HW0	37	/* X1 pipe hword 0 */
#परिभाषय R_TILEGX_IMM16_X0_HW1	38	/* X0 pipe hword 1 */
#परिभाषय R_TILEGX_IMM16_X1_HW1	39	/* X1 pipe hword 1 */
#परिभाषय R_TILEGX_IMM16_X0_HW2	40	/* X0 pipe hword 2 */
#परिभाषय R_TILEGX_IMM16_X1_HW2	41	/* X1 pipe hword 2 */
#परिभाषय R_TILEGX_IMM16_X0_HW3	42	/* X0 pipe hword 3 */
#परिभाषय R_TILEGX_IMM16_X1_HW3	43	/* X1 pipe hword 3 */
#परिभाषय R_TILEGX_IMM16_X0_HW0_चरमः 44	/* X0 pipe last hword 0 */
#परिभाषय R_TILEGX_IMM16_X1_HW0_चरमः 45	/* X1 pipe last hword 0 */
#परिभाषय R_TILEGX_IMM16_X0_HW1_चरमः 46	/* X0 pipe last hword 1 */
#परिभाषय R_TILEGX_IMM16_X1_HW1_चरमः 47	/* X1 pipe last hword 1 */
#परिभाषय R_TILEGX_IMM16_X0_HW2_चरमः 48	/* X0 pipe last hword 2 */
#परिभाषय R_TILEGX_IMM16_X1_HW2_चरमः 49	/* X1 pipe last hword 2 */
#परिभाषय R_TILEGX_IMM16_X0_HW0_PCREL 50	/* X0 pipe PC relative hword 0 */
#परिभाषय R_TILEGX_IMM16_X1_HW0_PCREL 51	/* X1 pipe PC relative hword 0 */
#परिभाषय R_TILEGX_IMM16_X0_HW1_PCREL 52	/* X0 pipe PC relative hword 1 */
#परिभाषय R_TILEGX_IMM16_X1_HW1_PCREL 53	/* X1 pipe PC relative hword 1 */
#परिभाषय R_TILEGX_IMM16_X0_HW2_PCREL 54	/* X0 pipe PC relative hword 2 */
#परिभाषय R_TILEGX_IMM16_X1_HW2_PCREL 55	/* X1 pipe PC relative hword 2 */
#परिभाषय R_TILEGX_IMM16_X0_HW3_PCREL 56	/* X0 pipe PC relative hword 3 */
#परिभाषय R_TILEGX_IMM16_X1_HW3_PCREL 57	/* X1 pipe PC relative hword 3 */
#परिभाषय R_TILEGX_IMM16_X0_HW0_चरमः_PCREL 58 /* X0 pipe PC-rel last hword 0 */
#परिभाषय R_TILEGX_IMM16_X1_HW0_चरमः_PCREL 59 /* X1 pipe PC-rel last hword 0 */
#परिभाषय R_TILEGX_IMM16_X0_HW1_चरमः_PCREL 60 /* X0 pipe PC-rel last hword 1 */
#परिभाषय R_TILEGX_IMM16_X1_HW1_चरमः_PCREL 61 /* X1 pipe PC-rel last hword 1 */
#परिभाषय R_TILEGX_IMM16_X0_HW2_चरमः_PCREL 62 /* X0 pipe PC-rel last hword 2 */
#परिभाषय R_TILEGX_IMM16_X1_HW2_चरमः_PCREL 63 /* X1 pipe PC-rel last hword 2 */
#परिभाषय R_TILEGX_IMM16_X0_HW0_GOT 64	/* X0 pipe hword 0 GOT offset */
#परिभाषय R_TILEGX_IMM16_X1_HW0_GOT 65	/* X1 pipe hword 0 GOT offset */
#परिभाषय R_TILEGX_IMM16_X0_HW0_PLT_PCREL 66 /* X0 pipe PC-rel PLT hword 0 */
#परिभाषय R_TILEGX_IMM16_X1_HW0_PLT_PCREL 67 /* X1 pipe PC-rel PLT hword 0 */
#परिभाषय R_TILEGX_IMM16_X0_HW1_PLT_PCREL 68 /* X0 pipe PC-rel PLT hword 1 */
#परिभाषय R_TILEGX_IMM16_X1_HW1_PLT_PCREL 69 /* X1 pipe PC-rel PLT hword 1 */
#परिभाषय R_TILEGX_IMM16_X0_HW2_PLT_PCREL 70 /* X0 pipe PC-rel PLT hword 2 */
#परिभाषय R_TILEGX_IMM16_X1_HW2_PLT_PCREL 71 /* X1 pipe PC-rel PLT hword 2 */
#परिभाषय R_TILEGX_IMM16_X0_HW0_चरमः_GOT 72 /* X0 pipe last hword 0 GOT offset */
#परिभाषय R_TILEGX_IMM16_X1_HW0_चरमः_GOT 73 /* X1 pipe last hword 0 GOT offset */
#परिभाषय R_TILEGX_IMM16_X0_HW1_चरमः_GOT 74 /* X0 pipe last hword 1 GOT offset */
#परिभाषय R_TILEGX_IMM16_X1_HW1_चरमः_GOT 75 /* X1 pipe last hword 1 GOT offset */
#परिभाषय R_TILEGX_IMM16_X0_HW3_PLT_PCREL 76 /* X0 pipe PC-rel PLT hword 3 */
#परिभाषय R_TILEGX_IMM16_X1_HW3_PLT_PCREL 77 /* X1 pipe PC-rel PLT hword 3 */
#परिभाषय R_TILEGX_IMM16_X0_HW0_TLS_GD 78	/* X0 pipe hword 0 TLS GD offset */
#परिभाषय R_TILEGX_IMM16_X1_HW0_TLS_GD 79	/* X1 pipe hword 0 TLS GD offset */
#परिभाषय R_TILEGX_IMM16_X0_HW0_TLS_LE 80	/* X0 pipe hword 0 TLS LE offset */
#परिभाषय R_TILEGX_IMM16_X1_HW0_TLS_LE 81	/* X1 pipe hword 0 TLS LE offset */
#परिभाषय R_TILEGX_IMM16_X0_HW0_चरमः_TLS_LE 82 /* X0 pipe last hword 0 LE off */
#परिभाषय R_TILEGX_IMM16_X1_HW0_चरमः_TLS_LE 83 /* X1 pipe last hword 0 LE off */
#परिभाषय R_TILEGX_IMM16_X0_HW1_चरमः_TLS_LE 84 /* X0 pipe last hword 1 LE off */
#परिभाषय R_TILEGX_IMM16_X1_HW1_चरमः_TLS_LE 85 /* X1 pipe last hword 1 LE off */
#परिभाषय R_TILEGX_IMM16_X0_HW0_चरमः_TLS_GD 86 /* X0 pipe last hword 0 GD off */
#परिभाषय R_TILEGX_IMM16_X1_HW0_चरमः_TLS_GD 87 /* X1 pipe last hword 0 GD off */
#परिभाषय R_TILEGX_IMM16_X0_HW1_चरमः_TLS_GD 88 /* X0 pipe last hword 1 GD off */
#परिभाषय R_TILEGX_IMM16_X1_HW1_चरमः_TLS_GD 89 /* X1 pipe last hword 1 GD off */
/* Relocs 90-91 are currently not defined.  */
#परिभाषय R_TILEGX_IMM16_X0_HW0_TLS_IE 92	/* X0 pipe hword 0 TLS IE offset */
#परिभाषय R_TILEGX_IMM16_X1_HW0_TLS_IE 93	/* X1 pipe hword 0 TLS IE offset */
#परिभाषय R_TILEGX_IMM16_X0_HW0_चरमः_PLT_PCREL 94 /* X0 pipe PC-rel PLT last hword 0 */
#परिभाषय R_TILEGX_IMM16_X1_HW0_चरमः_PLT_PCREL 95 /* X1 pipe PC-rel PLT last hword 0 */
#परिभाषय R_TILEGX_IMM16_X0_HW1_चरमः_PLT_PCREL 96 /* X0 pipe PC-rel PLT last hword 1 */
#परिभाषय R_TILEGX_IMM16_X1_HW1_चरमः_PLT_PCREL 97 /* X1 pipe PC-rel PLT last hword 1 */
#परिभाषय R_TILEGX_IMM16_X0_HW2_चरमः_PLT_PCREL 98 /* X0 pipe PC-rel PLT last hword 2 */
#परिभाषय R_TILEGX_IMM16_X1_HW2_चरमः_PLT_PCREL 99 /* X1 pipe PC-rel PLT last hword 2 */
#परिभाषय R_TILEGX_IMM16_X0_HW0_चरमः_TLS_IE 100 /* X0 pipe last hword 0 IE off */
#परिभाषय R_TILEGX_IMM16_X1_HW0_चरमः_TLS_IE 101 /* X1 pipe last hword 0 IE off */
#परिभाषय R_TILEGX_IMM16_X0_HW1_चरमः_TLS_IE 102 /* X0 pipe last hword 1 IE off */
#परिभाषय R_TILEGX_IMM16_X1_HW1_चरमः_TLS_IE 103 /* X1 pipe last hword 1 IE off */
/* Relocs 104-105 are currently not defined.  */
#परिभाषय R_TILEGX_TLS_DTPMOD64	106	/* 64-bit ID of symbol's module */
#परिभाषय R_TILEGX_TLS_DTPOFF64	107	/* 64-bit offset in TLS block */
#परिभाषय R_TILEGX_TLS_TPOFF64	108	/* 64-bit offset in static TLS block */
#परिभाषय R_TILEGX_TLS_DTPMOD32	109	/* 32-bit ID of symbol's module */
#परिभाषय R_TILEGX_TLS_DTPOFF32	110	/* 32-bit offset in TLS block */
#परिभाषय R_TILEGX_TLS_TPOFF32	111	/* 32-bit offset in static TLS block */
#परिभाषय R_TILEGX_TLS_GD_CALL	112	/* "jal" for TLS GD */
#परिभाषय R_TILEGX_IMM8_X0_TLS_GD_सङ्कलय 113	/* X0 pipe "addi" for TLS GD */
#परिभाषय R_TILEGX_IMM8_X1_TLS_GD_सङ्कलय 114	/* X1 pipe "addi" for TLS GD */
#परिभाषय R_TILEGX_IMM8_Y0_TLS_GD_सङ्कलय 115	/* Y0 pipe "addi" for TLS GD */
#परिभाषय R_TILEGX_IMM8_Y1_TLS_GD_सङ्कलय 116	/* Y1 pipe "addi" for TLS GD */
#परिभाषय R_TILEGX_TLS_IE_आरोपय	117	/* "ld_tls" for TLS IE */
#परिभाषय R_TILEGX_IMM8_X0_TLS_सङ्कलय 118	/* X0 pipe "addi" for TLS GD/IE */
#परिभाषय R_TILEGX_IMM8_X1_TLS_सङ्कलय 119	/* X1 pipe "addi" for TLS GD/IE */
#परिभाषय R_TILEGX_IMM8_Y0_TLS_सङ्कलय 120	/* Y0 pipe "addi" for TLS GD/IE */
#परिभाषय R_TILEGX_IMM8_Y1_TLS_सङ्कलय 121	/* Y1 pipe "addi" for TLS GD/IE */

#परिभाषय R_TILEGX_GNU_VTINHERIT	128	/* GNU C++ vtable hierarchy */
#परिभाषय R_TILEGX_GNU_VTENTRY	129	/* GNU C++ vtable member usage */

#परिभाषय R_TILEGX_अङ्कः		130

/* RISC-V ELF Flags */
#परिभाषय EF_RISCV_RVC 			0x0001
#परिभाषय EF_RISCV_FLOAT_ABI 		0x0006
#परिभाषय EF_RISCV_FLOAT_ABI_SOFT 	0x0000
#परिभाषय EF_RISCV_FLOAT_ABI_SINGLE 	0x0002
#परिभाषय EF_RISCV_FLOAT_ABI_DOUBLE 	0x0004
#परिभाषय EF_RISCV_FLOAT_ABI_QUAD 	0x0006

/* RISC-V relocations.  */
#परिभाषय R_RISCV_NONE		 0
#परिभाषय R_RISCV_32		 1
#परिभाषय R_RISCV_64		 2
#परिभाषय R_RISCV_RELATIVE	 3
#परिभाषय R_RISCV_COPY		 4
#परिभाषय R_RISCV_JUMP_SLOT	 5
#परिभाषय R_RISCV_TLS_DTPMOD32	 6
#परिभाषय R_RISCV_TLS_DTPMOD64	 7
#परिभाषय R_RISCV_TLS_DTPREL32	 8
#परिभाषय R_RISCV_TLS_DTPREL64	 9
#परिभाषय R_RISCV_TLS_TPREL32	10
#परिभाषय R_RISCV_TLS_TPREL64	11
#परिभाषय R_RISCV_BRANCH		16
#परिभाषय R_RISCV_JAL		17
#परिभाषय R_RISCV_CALL		18
#परिभाषय R_RISCV_CALL_PLT	19
#परिभाषय R_RISCV_GOT_HI20	20
#परिभाषय R_RISCV_TLS_GOT_HI20	21
#परिभाषय R_RISCV_TLS_GD_HI20	22
#परिभाषय R_RISCV_PCREL_HI20	23
#परिभाषय R_RISCV_PCREL_LO12_I	24
#परिभाषय R_RISCV_PCREL_LO12_S	25
#परिभाषय R_RISCV_HI20		26
#परिभाषय R_RISCV_LO12_I		27
#परिभाषय R_RISCV_LO12_S		28
#परिभाषय R_RISCV_TPREL_HI20	29
#परिभाषय R_RISCV_TPREL_LO12_I	30
#परिभाषय R_RISCV_TPREL_LO12_S	31
#परिभाषय R_RISCV_TPREL_सङ्कलय	32
#परिभाषय R_RISCV_ADD8		33
#परिभाषय R_RISCV_ADD16		34
#परिभाषय R_RISCV_ADD32		35
#परिभाषय R_RISCV_ADD64		36
#परिभाषय R_RISCV_SUB8		37
#परिभाषय R_RISCV_SUB16		38
#परिभाषय R_RISCV_SUB32		39
#परिभाषय R_RISCV_SUB64		40
#परिभाषय R_RISCV_GNU_VTINHERIT	41
#परिभाषय R_RISCV_GNU_VTENTRY	42
#परिभाषय R_RISCV_ALIGN		43
#परिभाषय R_RISCV_RVC_BRANCH	44
#परिभाषय R_RISCV_RVC_JUMP	45
#परिभाषय R_RISCV_RVC_LUI		46
#परिभाषय R_RISCV_GPREL_I		47
#परिभाषय R_RISCV_GPREL_S		48
#परिभाषय R_RISCV_TPREL_I		49
#परिभाषय R_RISCV_TPREL_S		50
#परिभाषय R_RISCV_RELAX		51
#परिभाषय R_RISCV_SUB6		52
#परिभाषय R_RISCV_SET6		53
#परिभाषय R_RISCV_SET8		54
#परिभाषय R_RISCV_SET16		55
#परिभाषय R_RISCV_SET32		56
#परिभाषय R_RISCV_32_PCREL	57
#परिभाषय R_RISCV_IRELATIVE	58
#परिभाषय R_RISCV_PLT32		59
#परिभाषय R_RISCV_समुच्चयः_ULEB128	60
#परिभाषय R_RISCV_SUB_ULEB128	61

#परिभाषय R_RISCV_अङ्कः		62


#यदि_अन्तः	/* elf.h */

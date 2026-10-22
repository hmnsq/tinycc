/*
 *  ARM specific functions for TCC assembler
 *
 *  Copyright (c) 2001, 2002 Fabrice Bellard
 *  Copyright (c) 2020 Danny Milosavljevic
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifdef TARGET_DEFS_ONLY

#define CONFIG_TCC_ASM
#define NB_ASM_REGS 16

ST_FUNC শূন্য g(পূর্ণসংখ্যা c);
ST_FUNC শূন্য gen_le16(পূর্ণসংখ্যা c);
ST_FUNC শূন্য gen_le32(পূর্ণসংখ্যা c);

/*************************************************************/
#অন্যথা
/*************************************************************/

#define USING_GLOBALS
#অন্তর্ভাব "tcc.h"

গণনা {
    OPT_REG32,
    OPT_REGSET32,
    OPT_IM8,
    OPT_IM8N,
    OPT_IM32,
    OPT_VREG32,
    OPT_VREG64,
};
#define OP_REG32  (1 << OPT_REG32)
#define OP_VREG32 (1 << OPT_VREG32)
#define OP_VREG64 (1 << OPT_VREG64)
#define OP_REG    (OP_REG32 | OP_VREG32 | OP_VREG64)
#define OP_IM32   (1 << OPT_IM32)
#define OP_IM8   (1 << OPT_IM8)
#define OP_IM8N   (1 << OPT_IM8N)
#define OP_REGSET32  (1 << OPT_REGSET32)

প্রকারলেখ কাঠামো Operand {
    uint32_t type;
    সংঘ {
        uint8_t reg;
        uint16_t regset;
        রাশিমালা_মান e;
    };
} Operand;

/* Read the VFP register referred to by token T.
   If OK, returns its number.
   If not OK, returns -1. */
স্থির পূর্ণসংখ্যা asm_parse_vfp_regvar(পূর্ণসংখ্যা t, পূর্ণসংখ্যা double_precision)
{
    যদি (double_precision) {
        যদি (t >= TOK_ASM_d0 && t <= TOK_ASM_d15)
            ফেরত t - TOK_ASM_d0;
    } অন্যথা {
        যদি (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
            ফেরত t - TOK_ASM_s0;
    }
    ফেরত -1;
}

/* Parse a text containing operand and store the result in OP */
স্থির শূন্য parse_operand(TCCState *s1, Operand *op)
{
    রাশিমালা_মান e;
    int8_t reg;
    uint16_t regset = 0;

    op->type = 0;

    যদি (tok == '{') { // regset literal
        পরবর্তী(); // skip '{'
        যখন (tok != '}' && tok != TOK_EOF) {
            reg = asm_parse_regvar(tok);
            যদি (reg == -1) {
                expect("register");
            } অন্যথা
                পরবর্তী(); // skip register name

            যদি ((1 << reg) < regset)
                tcc_warning("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
            regset |= 1 << reg;
            যদি (tok != ',')
                বিরতি;
            পরবর্তী(); // skip ','
        }
        skip('}');
        যদি (regset == 0) {
            // ARM instructions don't support empty regset.
            tcc_error("empty register list is not supported");
        } অন্যথা {
            op->type = OP_REGSET32;
            op->regset = regset;
        }
        ফেরত;
    } অন্যথা যদি ((reg = asm_parse_regvar(tok)) != -1) {
        পরবর্তী(); // skip register name
        op->type = OP_REG32;
        op->reg = (uint8_t) reg;
        ফেরত;
    } অন্যথা যদি ((reg = asm_parse_vfp_regvar(tok, 0)) != -1) {
        পরবর্তী(); // skip register name
        op->type = OP_VREG32;
        op->reg = (uint8_t) reg;
        ফেরত;
    } অন্যথা যদি ((reg = asm_parse_vfp_regvar(tok, 1)) != -1) {
        পরবর্তী(); // skip register name
        op->type = OP_VREG64;
        op->reg = (uint8_t) reg;
        ফেরত;
    } অন্যথা যদি (tok == '#' || tok == '$') {
        /* constant value */
        পরবর্তী(); // skip '#' or '$'
    }
    asm_রাশিমালা(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    যদি (!op->e.sym) {
        যদি ((পূর্ণসংখ্যা) op->e.v < 0 && (পূর্ণসংখ্যা) op->e.v >= -255)
            op->type = OP_IM8N;
        অন্যথা যদি (op->e.v == (uint8_t)op->e.v)
            op->type = OP_IM8;
    } অন্যথা
        expect("operand");
}

/* XXX: make it faster ? */
ST_FUNC শূন্য g(পূর্ণসংখ্যা c)
{
    পূর্ণসংখ্যা ind1;
    যদি (nocode_wanted)
        ফেরত;
    ind1 = ind + 1;
    যদি (ind1 > cur_text_section->তথ্য_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->তথ্য[ind] = c;
    ind = ind1;
}

ST_FUNC শূন্য gen_le16 (পূর্ণসংখ্যা i)
{
    g(i);
    g(i>>8);
}

ST_FUNC শূন্য gen_le32 (পূর্ণসংখ্যা i)
{
    পূর্ণসংখ্যা ind1;
    যদি (nocode_wanted)
        ফেরত;
    ind1 = ind + 4;
    যদি (ind1 > cur_text_section->তথ্য_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->তথ্য[ind++] = i & 0xFF;
    cur_text_section->তথ্য[ind++] = (i >> 8) & 0xFF;
    cur_text_section->তথ্য[ind++] = (i >> 16) & 0xFF;
    cur_text_section->তথ্য[ind++] = (i >> 24) & 0xFF;
}

ST_FUNC শূন্য gen_expr32(রাশিমালা_মান *pe)
{
    gen_le32(pe->v);
}

স্থির uint32_t condition_code_of_token(পূর্ণসংখ্যা token) {
    যদি (token < TOK_ASM_nopeq) {
        expect("condition-enabled instruction");
    } অন্যথা
        ফেরত (token - TOK_ASM_nopeq) & 15;
}

স্থির শূন্য asm_emit_opcode(পূর্ণসংখ্যা token, uint32_t opcode) {
    gen_le32((condition_code_of_token(token) << 28) | opcode);
}

স্থির শূন্য asm_emit_unconditional_opcode(uint32_t opcode) {
    gen_le32(opcode);
}

স্থির শূন্য asm_emit_coprocessor_opcode(uint32_t উপরের_nibble, uint8_t cp_সংখ্যা, uint8_t cp_opcode, uint8_t cp_destination_register, uint8_t cp_n_operand_register, uint8_t cp_m_operand_register, uint8_t cp_opcode2, পূর্ণসংখ্যা inter_processor_transfer)
{
    uint32_t opcode = 0xe000000;
    যদি (inter_processor_transfer)
        opcode |= 1 << 4;
    //assert(cp_opcode < 16);
    opcode |= cp_opcode << 20;
    //assert(cp_n_operand_register < 16);
    opcode |= cp_n_operand_register << 16;
    //assert(cp_destination_register < 16);
    opcode |= cp_destination_register << 12;
    //assert(cp_number < 16);
    opcode |= cp_সংখ্যা << 8;
    //assert(cp_information < 8);
    opcode |= cp_opcode2 << 5;
    //assert(cp_m_operand_register < 16);
    opcode |= cp_m_operand_register;
    asm_emit_unconditional_opcode((উপরের_nibble << 28) | opcode);
}

স্থির শূন্য asm_nullary_opcode(পূর্ণসংখ্যা token)
{
    নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
    ক্ষেত্র TOK_ASM_nopeq:
        asm_emit_opcode(token, 0xd << 21); // mov r0, r0
        বিরতি;
    ক্ষেত্র TOK_ASM_wfeeq:
        asm_emit_opcode(token, 0x320f002);
    ক্ষেত্র TOK_ASM_wfieq:
        asm_emit_opcode(token, 0x320f003);
        বিরতি;
    পূর্বনির্ধারিত:
        expect("nullary instruction");
    }
}

স্থির শূন্য asm_unary_opcode(TCCState *s1, পূর্ণসংখ্যা token)
{
    Operand op;
    parse_operand(s1, &op);

    নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
    ক্ষেত্র TOK_ASM_swieq:
    ক্ষেত্র TOK_ASM_svceq:
        যদি (op.type != OP_IM8)
            expect("immediate 8-bit unsigned integer");
        অন্যথা {
            /* Note: Dummy operand (ignored by processor): ARM ref documented 0...255, ARM instruction set documented 24 bit */
            asm_emit_opcode(token, (0xf << 24) | op.e.v);
        }
        বিরতি;
    পূর্বনির্ধারিত:
        expect("unary instruction");
    }
}

স্থির শূন্য asm_দ্বিমিক_opcode(TCCState *s1, পূর্ণসংখ্যা token)
{
    Operand ops[2];
    Operand rotation;
    uint32_t encoded_rotation = 0;
    uint64_t amount;
    parse_operand(s1, &ops[0]);
    skip(',');
    parse_operand(s1, &ops[1]);
    যদি (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    }

    যদি (ops[0].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ফাঁকা));
    }

    যদি (ops[0].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, ফাঁকা));

    যদি (ops[1].type != OP_REG32) {
        নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
        ক্ষেত্র TOK_ASM_movteq:
        ক্ষেত্র TOK_ASM_movweq:
            যদি (ops[1].type == OP_IM8 || ops[1].type == OP_IM8N || ops[1].type == OP_IM32) {
                যদি (ops[1].e.v >= 0 && ops[1].e.v <= 0xFFFF) {
                    uint16_t immediate_মান = ops[1].e.v;
                    নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
                    ক্ষেত্র TOK_ASM_movteq:
                        asm_emit_opcode(token, 0x3400000 | (ops[0].reg << 12) | (immediate_মান & 0xF000) << 4 | (immediate_মান & 0xFFF));
                        বিরতি;
                    ক্ষেত্র TOK_ASM_movweq:
                        asm_emit_opcode(token, 0x3000000 | (ops[0].reg << 12) | (immediate_মান & 0xF000) << 4 | (immediate_মান & 0xFFF));
                        বিরতি;
                    }
                } অন্যথা
                    expect("(source operand) immediate 16 bit value");
            } অন্যথা
                expect("(source operand) immediate");
            বিরতি;
        পূর্বনির্ধারিত:
            expect("(source operand) register");
        }
        ফেরত;
    }

    যদি (ops[1].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ফাঁকা));
    }

    যদি (ops[1].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, ফাঁকা));

    যদি (tok == ',') {
        পরবর্তী(); // skip ','
        যদি (tok == TOK_ASM_ror) {
            পরবর্তী(); // skip 'ror'
            parse_operand(s1, &rotation);
            যদি (rotation.type != OP_IM8) {
                expect("immediate value for rotation");
            } অন্যথা {
                amount = rotation.e.v;
                নির্বাচন (amount) {
                ক্ষেত্র 8:
                    encoded_rotation = 1 << 10;
                    বিরতি;
                ক্ষেত্র 16:
                    encoded_rotation = 2 << 10;
                    বিরতি;
                ক্ষেত্র 24:
                    encoded_rotation = 3 << 10;
                    বিরতি;
                পূর্বনির্ধারিত:
                    expect("'8' or '16' or '24'");
                }
            }
        }
    }
    নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
    ক্ষেত্র TOK_ASM_clzeq:
        যদি (encoded_rotation)
            tcc_error("clz does not support rotation");
        asm_emit_opcode(token, 0x16f0f10 | (ops[0].reg << 12) | ops[1].reg);
        বিরতি;
    ক্ষেত্র TOK_ASM_sxtbeq:
        asm_emit_opcode(token, 0x6af0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        বিরতি;
    ক্ষেত্র TOK_ASM_sxtheq:
        asm_emit_opcode(token, 0x6bf0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        বিরতি;
    ক্ষেত্র TOK_ASM_uxtbeq:
        asm_emit_opcode(token, 0x6ef0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        বিরতি;
    ক্ষেত্র TOK_ASM_uxtheq:
        asm_emit_opcode(token, 0x6ff0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        বিরতি;
    পূর্বনির্ধারিত:
        expect("binary instruction");
    }
}

স্থির শূন্য asm_coprocessor_opcode(TCCState *s1, পূর্ণসংখ্যা token) {
    uint8_t coprocessor;
    Operand opcode1;
    Operand opcode2;
    uint8_t registers[3];
    unsigned পূর্ণসংখ্যা i;
    uint8_t উপরের_nibble;
    uint8_t mrc = 0;

    যদি (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        পরবর্তী();
    } অন্যথা {
        expect("'p<number>'");
    }
    skip(',');
    parse_operand(s1, &opcode1);
    যদি (opcode1.type != OP_IM8 || opcode1.e.v > 15) {
        tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, ফাঁকা));
    }

    জন্য (i = 0; i < 3; ++i) {
        skip(',');
        যদি (i == 0 && token != TOK_ASM_cdp2 && (ARM_INSTRUCTION_GROUP(token) == TOK_ASM_mrceq || ARM_INSTRUCTION_GROUP(token) == TOK_ASM_mcreq)) {
            যদি (tok >= TOK_ASM_r0 && tok <= TOK_ASM_pc) {
                registers[i] = asm_parse_regvar(tok);
                পরবর্তী();
            } অন্যথা {
                expect("'r<number>'");
            }
        } অন্যথা {
            যদি (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
                registers[i] = tok - TOK_ASM_c0;
                পরবর্তী();
            } অন্যথা {
                expect("'c<number>'");
            }
        }
    }
    যদি (tok == ',') {
        পরবর্তী();
        parse_operand(s1, &opcode2);
    } অন্যথা {
        opcode2.type = OP_IM8;
        opcode2.e.v = 0;
    }
    যদি (opcode2.type != OP_IM8 || opcode2.e.v > 15) {
        tcc_error("opcode2 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, ফাঁকা));
    }

    যদি (token == TOK_ASM_cdp2) {
        উপরের_nibble = 0xF;
        asm_emit_coprocessor_opcode(উপরের_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        ফেরত;
    } অন্যথা
        উপরের_nibble = condition_code_of_token(token);

    নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
    ক্ষেত্র TOK_ASM_cdpeq:
        asm_emit_coprocessor_opcode(উপরের_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        বিরতি;
    ক্ষেত্র TOK_ASM_mrceq:
        // opcode1 encoding changes! highest and lowest bit gone.
        mrc = 1;
        /* fallthrough */
    ক্ষেত্র TOK_ASM_mcreq:
        // opcode1 encoding changes! highest and lowest bit gone.
        যদি (opcode1.e.v > 7) {
            tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 7", get_tok_str(token, ফাঁকা));
        }
        asm_emit_coprocessor_opcode(উপরের_nibble, coprocessor, (opcode1.e.v << 1) | mrc, registers[0], registers[1], registers[2], opcode2.e.v, 1);
        বিরতি;
    পূর্বনির্ধারিত:
        expect("known instruction");
    }
}

/* data processing and single data transfer instructions only */
#define ENCODE_RN(register_সূচক) ((register_সূচক) << 16)
#define ENCODE_RD(register_সূচক) ((register_সূচক) << 12)
#define ENCODE_SET_CONDITION_CODES (1 << 20)

/* Note: For data processing instructions, "1" means immediate.
   Note: For single data transfer instructions, "0" means immediate. */
#define ENCODE_IMMEDIATE_FLAG (1 << 25)

#define ENCODE_BARREL_SHIFTER_SHIFT_BY_REGISTER (1 << 4)
#define ENCODE_BARREL_SHIFTER_MODE_LSL (0 << 5)
#define ENCODE_BARREL_SHIFTER_MODE_LSR (1 << 5)
#define ENCODE_BARREL_SHIFTER_MODE_ASR (2 << 5)
#define ENCODE_BARREL_SHIFTER_MODE_ROR (3 << 5)
#define ENCODE_BARREL_SHIFTER_REGISTER(register_সূচক) ((register_সূচক) << 8)
#define ENCODE_BARREL_SHIFTER_IMMEDIATE(মান) ((মান) << 7)

স্থির শূন্য asm_block_তথ্য_transfer_opcode(TCCState *s1, পূর্ণসংখ্যা token)
{
    uint32_t opcode;
    পূর্ণসংখ্যা op0_exclam = 0;
    Operand ops[2];
    পূর্ণসংখ্যা nb_ops = 1;
    parse_operand(s1, &ops[0]);
    যদি (tok == '!') {
        op0_exclam = 1;
        পরবর্তী(); // skip '!'
    }
    যদি (tok == ',') {
        পরবর্তী(); // skip comma
        parse_operand(s1, &ops[1]);
        ++nb_ops;
    }
    যদি (nb_ops < 1) {
        expect("at least one operand");
    } অন্যথা যদি (ops[nb_ops - 1].type != OP_REGSET32) {
        expect("(last operand) register list");
    }

    // block data transfer: 1 0 0 P U S W L << 20 (general case):
    // operands:
    //   Rn: bits 19...16 base register
    //   Register List: bits 15...0

    নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
    ক্ষেত্র TOK_ASM_pusheq: // TODO: Optimize 1-register case to: str ?, [sp, #-4]!
        // Instruction: 1 I=0 P=1 U=0 S=0 W=1 L=0 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        যদি (nb_ops != 1)
            expect("exactly one operand");
        অন্যথা
            asm_emit_opcode(token, (0x92d << 16) | ops[0].regset); // TODO: base register ?
        বিরতি;
    ক্ষেত্র TOK_ASM_popeq: // TODO: Optimize 1-register case to: ldr ?, [sp], #4
        // Instruction: 1 I=0 P=0 U=1 S=0 W=0 L=1 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        যদি (nb_ops != 1)
            expect("exactly one operand");
        অন্যথা
            asm_emit_opcode(token, (0x8bd << 16) | ops[0].regset); // TODO: base register ?
        বিরতি;
    ক্ষেত্র TOK_ASM_stmdaeq:
    ক্ষেত্র TOK_ASM_ldmdaeq:
    ক্ষেত্র TOK_ASM_stmeq:
    ক্ষেত্র TOK_ASM_ldmeq:
    ক্ষেত্র TOK_ASM_stmiaeq:
    ক্ষেত্র TOK_ASM_ldmiaeq:
    ক্ষেত্র TOK_ASM_stmdbeq:
    ক্ষেত্র TOK_ASM_ldmdbeq:
    ক্ষেত্র TOK_ASM_stmibeq:
    ক্ষেত্র TOK_ASM_ldmibeq:
        নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
        ক্ষেত্র TOK_ASM_stmdaeq: // post-decrement store
            opcode = 0x80 << 20;
            বিরতি;
        ক্ষেত্র TOK_ASM_ldmdaeq: // post-decrement load
            opcode = 0x81 << 20;
            বিরতি;
        ক্ষেত্র TOK_ASM_stmeq: // post-increment store
        ক্ষেত্র TOK_ASM_stmiaeq: // post-increment store
            opcode = 0x88 << 20;
            বিরতি;
        ক্ষেত্র TOK_ASM_ldmeq: // post-increment load
        ক্ষেত্র TOK_ASM_ldmiaeq: // post-increment load
            opcode = 0x89 << 20;
            বিরতি;
        ক্ষেত্র TOK_ASM_stmdbeq: // pre-decrement store
            opcode = 0x90 << 20;
            বিরতি;
        ক্ষেত্র TOK_ASM_ldmdbeq: // pre-decrement load
            opcode = 0x91 << 20;
            বিরতি;
        ক্ষেত্র TOK_ASM_stmibeq: // pre-increment store
            opcode = 0x98 << 20;
            বিরতি;
        ক্ষেত্র TOK_ASM_ldmibeq: // pre-increment load
            opcode = 0x99 << 20;
            বিরতি;
        পূর্বনির্ধারিত:
            tcc_error("internal error: This place should not be reached (fallback in asm_block_data_transfer_opcode)");
        }
        // operands:
        //    Rn: first operand
        //    Register List: lower bits
        যদি (nb_ops != 2)
            expect("exactly two operands");
        অন্যথা যদি (ops[0].type != OP_REG32)
            expect("(first operand) register");
        অন্যথা {
            যদি (op0_exclam)
                opcode |= 1 << 21; // writeback
            asm_emit_opcode(token, opcode | ENCODE_RN(ops[0].reg) | ops[1].regset);
        }
        বিরতি;
    পূর্বনির্ধারিত:
        expect("block data transfer instruction");
    }
}

/* Parses shift directive and returns the parts that would have to be set in the opcode because of it.
   Does not encode the actual shift amount.
   It's not an error if there is no shift directive.

   NB_SHIFT: will be set to 1 iff SHIFT is filled.  Note that for rrx, there's no need to fill SHIFT.
   SHIFT: will be filled in with the shift operand to use, if any. */
স্থির uint32_t asm_parse_optional_shift(TCCState* s1, পূর্ণসংখ্যা* nb_shift, Operand* shift)
{
    uint32_t opcode = 0;
    *nb_shift = 0;
    নির্বাচন (tok) {
    ক্ষেত্র TOK_ASM_asl:
    ক্ষেত্র TOK_ASM_lsl:
    ক্ষেত্র TOK_ASM_asr:
    ক্ষেত্র TOK_ASM_lsr:
    ক্ষেত্র TOK_ASM_ror:
        নির্বাচন (tok) {
        ক্ষেত্র TOK_ASM_asl:
            /* fallthrough */
        ক্ষেত্র TOK_ASM_lsl:
            opcode = ENCODE_BARREL_SHIFTER_MODE_LSL;
            বিরতি;
        ক্ষেত্র TOK_ASM_asr:
            opcode = ENCODE_BARREL_SHIFTER_MODE_ASR;
            বিরতি;
        ক্ষেত্র TOK_ASM_lsr:
            opcode = ENCODE_BARREL_SHIFTER_MODE_LSR;
            বিরতি;
        ক্ষেত্র TOK_ASM_ror:
            opcode = ENCODE_BARREL_SHIFTER_MODE_ROR;
            বিরতি;
        }
        পরবর্তী();
        parse_operand(s1, shift);
        *nb_shift = 1;
        বিরতি;
    ক্ষেত্র TOK_ASM_rrx:
        পরবর্তী();
        opcode = ENCODE_BARREL_SHIFTER_MODE_ROR;
        বিরতি;
    }
    ফেরত opcode;
}

স্থির uint32_t asm_encode_shift(Operand* shift)
{
    uint64_t amount;
    uint32_t operands = 0;
    নির্বাচন (shift->type) {
    ক্ষেত্র OP_REG32:
        যদি (shift->reg == 15)
            tcc_error("r15 cannot be used as a shift count");
        অন্যথা {
            operands = ENCODE_BARREL_SHIFTER_SHIFT_BY_REGISTER;
            operands |= ENCODE_BARREL_SHIFTER_REGISTER(shift->reg);
        }
        বিরতি;
    ক্ষেত্র OP_IM8:
        amount = shift->e.v;
        যদি (amount > 0 && amount < 32)
            operands = ENCODE_BARREL_SHIFTER_IMMEDIATE(amount);
        অন্যথা
            tcc_error("shift count out of range");
        বিরতি;
    পূর্বনির্ধারিত:
        tcc_error("unknown shift amount");
    }
    ফেরত operands;
}

স্থির শূন্য asm_তথ্য_processing_opcode(TCCState *s1, পূর্ণসংখ্যা token)
{
    Operand ops[3];
    পূর্ণসংখ্যা nb_ops;
    Operand shift = {0};
    পূর্ণসংখ্যা nb_shift = 0;
    uint32_t operands = 0;

    /* modulo 16 entries per instruction for the different condition codes */
    uint32_t opcode_idx = (ARM_INSTRUCTION_GROUP(token) - TOK_ASM_andeq) >> 4;
    uint32_t opcode_nos = opcode_idx >> 1; // without "s"; "OpCode" in ARM docs

    জন্য (nb_ops = 0; nb_ops < আকার(ops)/আকার(ops[0]); ) {
        যদি (tok == TOK_ASM_asl || tok == TOK_ASM_lsl || tok == TOK_ASM_lsr || tok == TOK_ASM_asr || tok == TOK_ASM_ror || tok == TOK_ASM_rrx)
            বিরতি;
        parse_operand(s1, &ops[nb_ops]);
        ++nb_ops;
        যদি (tok != ',')
            বিরতি;
        পরবর্তী(); // skip ','
    }
    যদি (tok == ',')
        পরবর্তী();
    operands |= asm_parse_optional_shift(s1, &nb_shift, &shift);
    যদি (nb_ops < 2)
        expect("at least two operands");
    অন্যথা যদি (nb_ops == 2) {
        memcpy(&ops[2], &ops[1], আকার(ops[1])); // move ops[2]
        memcpy(&ops[1], &ops[0], আকার(ops[0])); // ops[1] was implicit
        nb_ops = 3;
    } অন্যথা যদি (nb_ops == 3) {
        যদি (opcode_nos == 0xd || opcode_nos == 0xf || opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) { // mov, mvn, cmp, cmn, tst, teq
            tcc_error("'%s' cannot be used with three operands", get_tok_str(token, ফাঁকা));
        }
    }
    যদি (nb_ops != 3) {
        expect("two or three operands");
    } অন্যথা {
        uint32_t opcode = 0;
        uint32_t immediate_মান;
        uint8_t half_immediate_rotation;
        যদি (nb_shift && shift.type == OP_REG32) {
            যদি ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
                (ops[1].type == OP_REG32 && ops[1].reg == 15)) {
                tcc_error("Using the 'pc' register in data processing instructions that have a register-controlled shift is not implemented by ARM");
            }
        }

        // data processing (general case):
        // operands:
        //   Rn: bits 19...16 (first operand)
        //   Rd: bits 15...12 (destination)
        //   Operand2: bits 11...0 (second operand);  depending on I that's either a register or an immediate
        // operator:
        //   bits 24...21: "OpCode"--see below

        /* operations in the token list are ordered by opcode */
        opcode = opcode_nos << 21; // drop "s"
        যদি (ops[0].type != OP_REG32)
            expect("(destination operand) register");
        অন্যথা যদি (opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) // cmp, cmn, tst, teq
            operands |= ENCODE_SET_CONDITION_CODES; // force S set, otherwise it's a completely different instruction.
        অন্যথা
            operands |= ENCODE_RD(ops[0].reg);
        যদি (ops[1].type != OP_REG32)
            expect("(first source operand) register");
        অন্যথা যদি (!(opcode_nos == 0xd || opcode_nos == 0xf)) // not: mov, mvn (those have only one source operand)
            operands |= ENCODE_RN(ops[1].reg);
        নির্বাচন (ops[2].type) {
        ক্ষেত্র OP_REG32:
            operands |= ops[2].reg;
            বিরতি;
        ক্ষেত্র OP_IM8:
        ক্ষেত্র OP_IM32:
            operands |= ENCODE_IMMEDIATE_FLAG;
            immediate_মান = ops[2].e.v;
            জন্য (half_immediate_rotation = 0; half_immediate_rotation < 16; ++half_immediate_rotation) {
                যদি (immediate_মান >= 0x00 && immediate_মান < 0x100)
                    বিরতি;
                // rotate left by two
                immediate_মান = ((immediate_মান & 0x3FFFFFFF) << 2) | ((immediate_মান & 0xC0000000) >> 30);
            }
            যদি (half_immediate_rotation >= 16) {
                /* fallthrough */
            } অন্যথা {
                operands |= immediate_মান;
                operands |= half_immediate_rotation << 8;
                বিরতি;
            }
        ক্ষেত্র OP_IM8N: // immediate negative value
            operands |= ENCODE_IMMEDIATE_FLAG;
            immediate_মান = ops[2].e.v;
            /* Instruction swapping:
               0001 = EOR - Rd:= Op1 EOR Op2     -> difficult
               0011 = RSB - Rd:= Op2 - Op1       -> difficult
               0111 = RSC - Rd:= Op2 - Op1 + C   -> difficult
               1000 = TST - CC on: Op1 AND Op2   -> difficult
               1001 = TEQ - CC on: Op1 EOR Op2   -> difficult
               1100 = ORR - Rd:= Op1 OR Op2      -> difficult
            */
            নির্বাচন (opcode_nos) {
            ক্ষেত্র 0x0: // AND - Rd:= Op1 AND Op2
                opcode = 0xe << 21; // BIC
                immediate_মান = ~immediate_মান;
                বিরতি;
            ক্ষেত্র 0x2: // SUB - Rd:= Op1 - Op2
                opcode = 0x4 << 21; // ADD
                immediate_মান = -immediate_মান;
                বিরতি;
            ক্ষেত্র 0x4: // ADD - Rd:= Op1 + Op2
                opcode = 0x2 << 21; // SUB
                immediate_মান = -immediate_মান;
                বিরতি;
            ক্ষেত্র 0x5: // ADC - Rd:= Op1 + Op2 + C
                opcode = 0x6 << 21; // SBC
                immediate_মান = ~immediate_মান;
                বিরতি;
            ক্ষেত্র 0x6: // SBC - Rd:= Op1 - Op2 + C
                opcode = 0x5 << 21; // ADC
                immediate_মান = ~immediate_মান;
                বিরতি;
            ক্ষেত্র 0xa: // CMP - CC on: Op1 - Op2
                opcode = 0xb << 21; // CMN
                immediate_মান = -immediate_মান;
                বিরতি;
            ক্ষেত্র 0xb: // CMN - CC on: Op1 + Op2
                opcode = 0xa << 21; // CMP
                immediate_মান = -immediate_মান;
                বিরতি;
            ক্ষেত্র 0xd: // MOV - Rd:= Op2
                opcode = 0xf << 21; // MVN
                immediate_মান = ~immediate_মান;
                বিরতি;
            ক্ষেত্র 0xe: // BIC - Rd:= Op1 AND NOT Op2
                opcode = 0x0 << 21; // AND
                immediate_মান = ~immediate_মান;
                বিরতি;
            ক্ষেত্র 0xf: // MVN - Rd:= NOT Op2
                opcode = 0xd << 21; // MOV
                immediate_মান = ~immediate_মান;
                বিরতি;
            পূর্বনির্ধারিত:
                tcc_error("cannot use '%s' with a negative immediate value", get_tok_str(token, ফাঁকা));
            }
            জন্য (half_immediate_rotation = 0; half_immediate_rotation < 16; ++half_immediate_rotation) {
                যদি (immediate_মান >= 0x00 && immediate_মান < 0x100)
                    বিরতি;
                // rotate left by two
                immediate_মান = ((immediate_মান & 0x3FFFFFFF) << 2) | ((immediate_মান & 0xC0000000) >> 30);
            }
            যদি (half_immediate_rotation >= 16) {
                immediate_মান = ops[2].e.v;
                tcc_error("immediate value 0x%X cannot be encoded into ARM immediate", (unsigned) immediate_মান);
            }
            operands |= immediate_মান;
            operands |= half_immediate_rotation << 8;
            বিরতি;
        পূর্বনির্ধারিত:
            expect("(second source operand) register or immediate value");
        }

        যদি (nb_shift) {
            যদি (operands & ENCODE_IMMEDIATE_FLAG)
                tcc_error("immediate rotation not implemented");
            অন্যথা
                operands |= asm_encode_shift(&shift);
        }

        /* S=0 and S=1 entries alternate one after another, in that order */
        opcode |= (opcode_idx & 1) ? ENCODE_SET_CONDITION_CODES : 0;
        asm_emit_opcode(token, opcode | operands);
    }
}

স্থির শূন্য asm_shift_opcode(TCCState *s1, পূর্ণসংখ্যা token)
{
    Operand ops[3];
    পূর্ণসংখ্যা nb_ops;
    পূর্ণসংখ্যা definitely_neutral = 0;
    uint32_t opcode = 0xd << 21; // MOV
    uint32_t operands = 0;

    জন্য (nb_ops = 0; nb_ops < আকার(ops)/আকার(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        যদি (tok != ',') {
            ++nb_ops;
            বিরতি;
        }
        পরবর্তী(); // skip ','
    }
    যদি (nb_ops < 2) {
        expect("at least two operands");
    }

    যদি (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    } অন্যথা
        operands |= ENCODE_RD(ops[0].reg);

    যদি (nb_ops == 2) {
        নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
        ক্ষেত্র TOK_ASM_rrxseq:
            opcode |= ENCODE_SET_CONDITION_CODES;
            /* fallthrough */
        ক্ষেত্র TOK_ASM_rrxeq:
            যদি (ops[1].type == OP_REG32) {
                operands |= ops[1].reg;
                operands |= ENCODE_BARREL_SHIFTER_MODE_ROR;
                asm_emit_opcode(token, opcode | operands);
            } অন্যথা
                tcc_error("(first source operand) register");
            ফেরত;
        পূর্বনির্ধারিত:
            memcpy(&ops[2], &ops[1], আকার(ops[1])); // move ops[2]
            memcpy(&ops[1], &ops[0], আকার(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
    }
    যদি (nb_ops != 3) {
        expect("two or three operands");
    }

    নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
    ক্ষেত্র TOK_ASM_lslseq:
    ক্ষেত্র TOK_ASM_lsrseq:
    ক্ষেত্র TOK_ASM_asrseq:
    ক্ষেত্র TOK_ASM_rorseq:
        opcode |= ENCODE_SET_CONDITION_CODES;
        বিরতি;
    }

    নির্বাচন (ops[1].type) {
    ক্ষেত্র OP_REG32:
        operands |= ops[1].reg;
        বিরতি;
    ক্ষেত্র OP_IM8:
        operands |= ENCODE_IMMEDIATE_FLAG;
        operands |= ops[1].e.v;
        tcc_error("Using an immediate value as the source operand is not possible with '%s' instruction on ARM", get_tok_str(token, ফাঁকা));
    }

    নির্বাচন (ops[2].type) {
    ক্ষেত্র OP_REG32:
        যদি ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
            (ops[1].type == OP_REG32 && ops[1].reg == 15)) {
            tcc_error("Using the 'pc' register in data processing instructions that have a register-controlled shift is not implemented by ARM");
        }
        operands |= asm_encode_shift(&ops[2]);
        বিরতি;
    ক্ষেত্র OP_IM8:
        যদি (ops[2].e.v)
            operands |= asm_encode_shift(&ops[2]);
        অন্যথা
            definitely_neutral = 1;
        বিরতি;
    }

    যদি (!definitely_neutral) নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
    ক্ষেত্র TOK_ASM_lslseq:
    ক্ষেত্র TOK_ASM_lsleq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_LSL;
        বিরতি;
    ক্ষেত্র TOK_ASM_lsrseq:
    ক্ষেত্র TOK_ASM_lsreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_LSR;
        বিরতি;
    ক্ষেত্র TOK_ASM_asrseq:
    ক্ষেত্র TOK_ASM_asreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_ASR;
        বিরতি;
    ক্ষেত্র TOK_ASM_rorseq:
    ক্ষেত্র TOK_ASM_roreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_ROR;
        বিরতি;
    পূর্বনির্ধারিত:
        expect("shift instruction");
    }
    asm_emit_opcode(token, opcode | operands);
}

স্থির শূন্য asm_multiplication_opcode(TCCState *s1, পূর্ণসংখ্যা token)
{
    Operand ops[4];
    পূর্ণসংখ্যা nb_ops = 0;
    uint32_t opcode = 0x90;

    জন্য (nb_ops = 0; nb_ops < আকার(ops)/আকার(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        যদি (tok != ',') {
            ++nb_ops;
            বিরতি;
        }
        পরবর্তী(); // skip ','
    }
    যদি (nb_ops < 2)
        expect("at least two operands");
    অন্যথা যদি (nb_ops == 2) {
        নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
        ক্ষেত্র TOK_ASM_mulseq:
        ক্ষেত্র TOK_ASM_muleq:
            memcpy(&ops[2], &ops[0], আকার(ops[1])); // ARM is actually like this!
            বিরতি;
        পূর্বনির্ধারিত:
            expect("at least three operands");
        }
        nb_ops = 3;
    }

    // multiply (special case):
    // operands:
    //   Rd: bits 19...16
    //   Rm: bits 3...0
    //   Rs: bits 11...8
    //   Rn: bits 15...12

    যদি (ops[0].type == OP_REG32)
        opcode |= ops[0].reg << 16;
    অন্যথা
        expect("(destination operand) register");
    যদি (ops[1].type == OP_REG32)
        opcode |= ops[1].reg;
    অন্যথা
        expect("(first source operand) register");
    যদি (ops[2].type == OP_REG32)
        opcode |= ops[2].reg << 8;
    অন্যথা
        expect("(second source operand) register");
    যদি (nb_ops > 3) {
        যদি (ops[3].type == OP_REG32)
            opcode |= ops[3].reg << 12;
        অন্যথা
            expect("(third source operand) register");
    }

    নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
    ক্ষেত্র TOK_ASM_mulseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    ক্ষেত্র TOK_ASM_muleq:
        যদি (nb_ops != 3)
            expect("three operands");
        অন্যথা {
            asm_emit_opcode(token, opcode);
        }
        বিরতি;
    ক্ষেত্র TOK_ASM_mlaseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    ক্ষেত্র TOK_ASM_mlaeq:
    case_TOK_ASM_mlaeq:
        যদি (nb_ops != 4)
            expect("four operands");
        অন্যথা {
            opcode |= 1 << 21; // Accumulate
            asm_emit_opcode(token, opcode);
        }
        বিরতি;
    ক্ষেত্র TOK_ASM_mlseq:
        opcode |= 0x00400000;
        যাও case_TOK_ASM_mlaeq;
    ক্ষেত্র TOK_ASM_udiveq:
        opcode |= 0x00200000;
    ক্ষেত্র TOK_ASM_sdiveq:
        asm_emit_opcode(token, (opcode & ~0x80) | 0x0710f010);
        বিরতি;
    পূর্বনির্ধারিত:
        expect("known multiplication instruction");
    }
}

স্থির শূন্য asm_long_multiplication_opcode(TCCState *s1, পূর্ণসংখ্যা token)
{
    Operand ops[4];
    পূর্ণসংখ্যা nb_ops = 0;
    uint32_t opcode = 0x90 | (1 << 23);

    জন্য (nb_ops = 0; nb_ops < আকার(ops)/আকার(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        যদি (tok != ',') {
            ++nb_ops;
            বিরতি;
        }
        পরবর্তী(); // skip ','
    }
    যদি (nb_ops != 4) {
        expect("four operands");
    }

    // long multiply (special case):
    // operands:
    //   RdLo: bits 15...12
    //   RdHi: bits 19...16
    //   Rs: bits 11...8
    //   Rm: bits 3...0

    যদি (ops[0].type == OP_REG32)
        opcode |= ops[0].reg << 12;
    অন্যথা
        expect("(destination lo accumulator) register");
    যদি (ops[1].type == OP_REG32)
        opcode |= ops[1].reg << 16;
    অন্যথা
        expect("(destination hi accumulator) register");
    যদি (ops[2].type == OP_REG32)
        opcode |= ops[2].reg;
    অন্যথা
        expect("(first source operand) register");
    যদি (ops[3].type == OP_REG32)
        opcode |= ops[3].reg << 8;
    অন্যথা
        expect("(second source operand) register");

    নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
    ক্ষেত্র TOK_ASM_smullseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    ক্ষেত্র TOK_ASM_smulleq:
        opcode |= 1 << 22; // signed
        asm_emit_opcode(token, opcode);
        বিরতি;
    ক্ষেত্র TOK_ASM_umullseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    ক্ষেত্র TOK_ASM_umulleq:
        asm_emit_opcode(token, opcode);
        বিরতি;
    ক্ষেত্র TOK_ASM_smlalseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    ক্ষেত্র TOK_ASM_smlaleq:
        opcode |= 1 << 22; // signed
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        বিরতি;
    ক্ষেত্র TOK_ASM_umlalseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    ক্ষেত্র TOK_ASM_umlaleq:
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        বিরতি;
    পূর্বনির্ধারিত:
        expect("known long multiplication instruction");
    }
}

স্থির শূন্য asm_single_তথ্য_transfer_opcode(TCCState *s1, পূর্ণসংখ্যা token)
{
    Operand ops[3];
    Operand strex_operand;
    Operand shift;
    পূর্ণসংখ্যা nb_shift = 0;
    পূর্ণসংখ্যা exclam = 0;
    পূর্ণসংখ্যা closed_bracket = 0;
    পূর্ণসংখ্যা op2_minus = 0;
    uint32_t opcode = 0;
    // Note: ldr r0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: ldr r0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: ldr r0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_operand(s1, &ops[0]);
    যদি (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    অন্যথা {
        expect("(destination operand) register");
    }
    যদি (tok != ',')
        expect("at least two arguments");
    পরবর্তী(); // skip ','

    নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
    ক্ষেত্র TOK_ASM_strexheq:
    ক্ষেত্র TOK_ASM_strexbeq:
    ক্ষেত্র TOK_ASM_strexeq:
        parse_operand(s1, &strex_operand);
        যদি (strex_operand.type != OP_REG32) {
            expect("register");
        }
        যদি (tok != ',')
            expect("at least three arguments");
        অন্যথা
            পরবর্তী(); // skip ','
        বিরতি;
    }

    skip('[');
    parse_operand(s1, &ops[1]);
    যদি (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    অন্যথা {
        expect("(first source operand) register");
    }
    যদি (tok == ']') {
        পরবর্তী();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    যদি (tok == ',') {
        পরবর্তী(); // skip ','
        যদি (tok == '-') {
            op2_minus = 1;
            পরবর্তী();
        }
        parse_operand(s1, &ops[2]);
        যদি (ops[2].type == OP_REG32) {
            যদি (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, ফাঁকা));
            }
            যদি (tok == ',') {
                পরবর্তী();
                opcode |= asm_parse_optional_shift(s1, &nb_shift, &shift);
                যদি (opcode == 0)
                    expect("shift directive, or no comma");
            }
        }
    } অন্যথা {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        opcode |= 1 << 24; // add offset before transfer
    }
    যদি (!closed_bracket) {
        skip(']');
        opcode |= 1 << 24; // add offset before transfer
        যদি (tok == '!') {
            exclam = 1;
            পরবর্তী(); // skip '!'
        }
    }

    // single data transfer: 0 1 I P U B W L << 20 (general case):
    // operands:
    //    Rd: destination operand [ok]
    //    Rn: first source operand [ok]
    //    Operand2: bits 11...0 [ok]
    // I: immediate operand? [ok]
    // P: Pre/post indexing is PRE: Add offset before transfer [ok]
    // U: Up/down is up? (*adds* offset to base) [ok]
    // B: Byte/word is byte?  [ok]
    // W: Write address back into base? [ok]
    // L: Load/store is load? [ok]
    যদি (exclam)
        opcode |= 1 << 21; // write offset back into register

    যদি (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        পূর্ণসংখ্যা v = ops[2].e.v;
        যদি (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        যদি (v >= 0) {
            opcode |= 1 << 23; // up
            যদি (v >= 0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ফাঁকা));
            অন্যথা
                opcode |= v;
        } অন্যথা { // down
            যদি (v <= -0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ফাঁকা));
            অন্যথা
                opcode |= -v;
        }
    } অন্যথা যদি (ops[2].type == OP_REG32) {
        যদি (!op2_minus)
            opcode |= 1 << 23; // up
        opcode |= ENCODE_IMMEDIATE_FLAG; /* if set, it means it's NOT immediate */
        opcode |= ops[2].reg;
    } অন্যথা
        expect("register");

    নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
    ক্ষেত্র TOK_ASM_strbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    ক্ষেত্র TOK_ASM_streq:
        opcode |= 1 << 26; // Load/Store
        যদি (nb_shift)
            opcode |= asm_encode_shift(&shift);
        asm_emit_opcode(token, opcode);
        বিরতি;
    ক্ষেত্র TOK_ASM_ldrbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    ক্ষেত্র TOK_ASM_ldreq:
        opcode |= 1 << 20; // L
        opcode |= 1 << 26; // Load/Store
        যদি (nb_shift)
            opcode |= asm_encode_shift(&shift);
        asm_emit_opcode(token, opcode);
        বিরতি;
    ক্ষেত্র TOK_ASM_strexheq:
        opcode |= 1 << 21;
    ক্ষেত্র TOK_ASM_strexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    ক্ষেত্র TOK_ASM_strexeq:
        যদি ((opcode & 0xFFF) || nb_shift) {
            tcc_error("neither offset nor shift allowed with 'strex'");
        } অন্যথা যদি (opcode & ENCODE_IMMEDIATE_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'strex'");
        }
        যদি ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'strex'");
        }

        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        opcode |= strex_operand.reg;
        asm_emit_opcode(token, opcode);
        বিরতি;
    ক্ষেত্র TOK_ASM_ldrexheq:
        opcode |= 1 << 21;
    ক্ষেত্র TOK_ASM_ldrexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    ক্ষেত্র TOK_ASM_ldrexeq:
        যদি ((opcode & 0xFFF) || nb_shift) {
            tcc_error("neither offset nor shift allowed with 'ldrex'");
        } অন্যথা যদি (opcode & ENCODE_IMMEDIATE_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'ldrex'");
        }
        যদি ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'ldrex'");
        }
        opcode |= 1 << 20; // L
        opcode |= 0x00f;
        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        asm_emit_opcode(token, opcode);
        বিরতি;
    পূর্বনির্ধারিত:
        expect("data transfer instruction");
    }
}

// Note: Only call this using a VFP register if you know exactly what you are doing (i.e. cp_number is 10 or 11 and you are doing a vmov)
স্থির শূন্য asm_emit_coprocessor_তথ্য_transfer(uint32_t উপরের_nibble, uint8_t cp_সংখ্যা, uint8_t CRd, ধ্রুবক Operand* Rn, ধ্রুবক Operand* offset, পূর্ণসংখ্যা offset_minus, পূর্ণসংখ্যা preincrement, পূর্ণসংখ্যা writeback, পূর্ণসংখ্যা long_transfer, পূর্ণসংখ্যা load) {
    uint32_t opcode = 0x0;
    opcode |= 1 << 26; // Load/Store
    opcode |= 1 << 27; // coprocessor

    যদি (long_transfer)
        opcode |= 1 << 22; // long transfer

    যদি (load)
        opcode |= 1 << 20; // L

    opcode |= cp_সংখ্যা << 8;

    //assert(CRd < 16);
    opcode |= ENCODE_RD(CRd);

    যদি (Rn->type != OP_REG32)
        expect("register");

    //assert(Rn->reg < 16);
    opcode |= ENCODE_RN(Rn->reg);
    যদি (preincrement)
        opcode |= 1 << 24; // add offset before transfer

    যদি (writeback)
        opcode |= 1 << 21; // write offset back into register

    যদি (offset->type == OP_IM8 || offset->type == OP_IM8N || offset->type == OP_IM32) {
        পূর্ণসংখ্যা v = offset->e.v;
        যদি (offset_minus)
            tcc_error("minus before '#' not supported for immediate values");
        যদি (offset->type == OP_IM8N || v < 0)
            v = -v;
        অন্যথা
            opcode |= 1 << 23; // up
        যদি (v & 3) {
            tcc_error("immediate offset must be a multiple of 4");
        }
        v >>= 2;
        যদি (v > 255) {
            tcc_error("immediate offset must be between -1020 and 1020");
        }
        opcode |= v;
    } অন্যথা যদি (offset->type == OP_REG32) {
        যদি (!offset_minus)
            opcode |= 1 << 23; // up
        opcode |= ENCODE_IMMEDIATE_FLAG; /* if set, it means it's NOT immediate */
        opcode |= offset->reg;
        tcc_error("Using register offset to register address is not possible here");
    } অন্যথা যদি (offset->type == OP_VREG64) {
        opcode |= 16;
        opcode |= offset->reg;
    } অন্যথা
        expect("immediate or register");

    asm_emit_unconditional_opcode((উপরের_nibble << 28) | opcode);
}

// Almost exactly the same as asm_single_data_transfer_opcode.
// Difference: Offsets are smaller and multiples of 4; no shifts, no STREX, ENCODE_IMMEDIATE_FLAG is inverted again.
স্থির শূন্য asm_coprocessor_তথ্য_transfer_opcode(TCCState *s1, পূর্ণসংখ্যা token)
{
    Operand ops[3];
    uint8_t coprocessor;
    uint8_t coprocessor_destination_register;
    পূর্ণসংখ্যা preincrement = 0;
    পূর্ণসংখ্যা exclam = 0;
    পূর্ণসংখ্যা closed_bracket = 0;
    পূর্ণসংখ্যা op2_minus = 0;
    পূর্ণসংখ্যা long_transfer = 0;
    // Note: ldc p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: ldc p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: ldc p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    যদি (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        পরবর্তী();
    } অন্যথা {
        expect("'c<number>'");
    }

    skip(',');

    যদি (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
        coprocessor_destination_register = tok - TOK_ASM_c0;
        পরবর্তী();
    } অন্যথা {
        expect("'c<number>'");
    }

    skip(',');
    skip('[');
    parse_operand(s1, &ops[1]);
    যদি (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    যদি (tok == ']') {
        পরবর্তী();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    যদি (tok == ',') {
        পরবর্তী(); // skip ','
        যদি (tok == '-') {
            op2_minus = 1;
            পরবর্তী();
        }
        parse_operand(s1, &ops[2]);
        যদি (ops[2].type == OP_REG32) {
            যদি (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, ফাঁকা));
            }
        } অন্যথা যদি (ops[2].type == OP_VREG64) {
            tcc_error("'%s' does not support VFP register operand", get_tok_str(token, ফাঁকা));
        }
    } অন্যথা {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        preincrement = 1; // add offset before transfer
    }
    যদি (!closed_bracket) {
        skip(']');
        preincrement = 1; // add offset before transfer
        যদি (tok == '!') {
            exclam = 1;
            পরবর্তী(); // skip '!'
        }
    }

    // TODO: Support options.

    যদি (token == TOK_ASM_ldc2 || token == TOK_ASM_stc2 || token == TOK_ASM_ldc2l || token == TOK_ASM_stc2l) {
        নির্বাচন (token) {
        ক্ষেত্র TOK_ASM_ldc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        ক্ষেত্র TOK_ASM_ldc2:
            asm_emit_coprocessor_তথ্য_transfer(0xF, coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
            বিরতি;
        ক্ষেত্র TOK_ASM_stc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        ক্ষেত্র TOK_ASM_stc2:
            asm_emit_coprocessor_তথ্য_transfer(0xF, coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
            বিরতি;
        }
    } অন্যথা নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
    ক্ষেত্র TOK_ASM_stcleq:
        long_transfer = 1;
        /* fallthrough */
    ক্ষেত্র TOK_ASM_stceq:
        asm_emit_coprocessor_তথ্য_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
        বিরতি;
    ক্ষেত্র TOK_ASM_ldcleq:
        long_transfer = 1;
        /* fallthrough */
    ক্ষেত্র TOK_ASM_ldceq:
        asm_emit_coprocessor_তথ্য_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
        বিরতি;
    পূর্বনির্ধারিত:
        expect("coprocessor data transfer instruction");
    }
}

#যদি defined(TCC_ARM_VFP)
#define CP_SINGLE_PRECISION_FLOAT 10
#define CP_DOUBLE_PRECISION_FLOAT 11

স্থির শূন্য asm_floating_point_single_তথ্য_transfer_opcode(TCCState *s1, পূর্ণসংখ্যা token)
{
    Operand ops[3];
    uint8_t coprocessor = 0;
    uint8_t coprocessor_destination_register = 0;
    পূর্ণসংখ্যা long_transfer = 0;
    // Note: vldr p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: Not allowed: vldr p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: Not allowed: vldr p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_operand(s1, &ops[0]);
    যদি (ops[0].type == OP_VREG32) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        coprocessor_destination_register = ops[0].reg;
        long_transfer = coprocessor_destination_register & 1;
        coprocessor_destination_register >>= 1;
    } অন্যথা যদি (ops[0].type == OP_VREG64) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        coprocessor_destination_register = ops[0].reg;
        পরবর্তী();
    } অন্যথা {
        expect("floating point register");
    }

    skip(',');
    skip('[');
    parse_operand(s1, &ops[1]);
    যদি (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    যদি (tok == ',') {
        পরবর্তী(); // skip ','
        parse_operand(s1, &ops[2]);
        যদি (ops[2].type != OP_IM8 && ops[2].type != OP_IM8N) {
            expect("immediate offset");
        }
    } অন্যথা {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
    }
    skip(']');

    নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
    ক্ষেত্র TOK_ASM_vldreq:
        asm_emit_coprocessor_তথ্য_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], 0, 1, 0, long_transfer, 1);
        বিরতি;
    ক্ষেত্র TOK_ASM_vstreq:
        asm_emit_coprocessor_তথ্য_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], 0, 1, 0, long_transfer, 0);
        বিরতি;
    পূর্বনির্ধারিত:
        expect("floating point data transfer instruction");
    }
}

স্থির শূন্য asm_floating_point_block_তথ্য_transfer_opcode(TCCState *s1, পূর্ণসংখ্যা token)
{
    uint8_t coprocessor = 0;
    পূর্ণসংখ্যা first_regset_register;
    পূর্ণসংখ্যা last_regset_register;
    uint8_t regset_item_গুনতি;
    uint8_t extra_register_bit = 0;
    পূর্ণসংখ্যা op0_exclam = 0;
    পূর্ণসংখ্যা load = 0;
    পূর্ণসংখ্যা preincrement = 0;
    Operand ops[1];
    Operand offset;
    নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
    ক্ষেত্র TOK_ASM_vpusheq:
    ক্ষেত্র TOK_ASM_vpopeq:
        ops[0].type = OP_REG32;
        ops[0].reg = 13; // sp
        op0_exclam = 1;
        বিরতি;
    পূর্বনির্ধারিত:
        parse_operand(s1, &ops[0]);
        যদি (tok == '!') {
            op0_exclam = 1;
            পরবর্তী(); // skip '!'
        }
        skip(',');
    }

    skip('{');
    first_regset_register = asm_parse_vfp_regvar(tok, 1);
    যদি ((first_regset_register = asm_parse_vfp_regvar(tok, 1)) != -1) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        পরবর্তী();
    } অন্যথা যদি ((first_regset_register = asm_parse_vfp_regvar(tok, 0)) != -1) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        পরবর্তী();
    } অন্যথা {
        expect("floating-point register");
    }

    যদি (tok == '-') {
        পরবর্তী();
        যদি ((last_regset_register = asm_parse_vfp_regvar(tok, coprocessor == CP_DOUBLE_PRECISION_FLOAT)) != -1)
            পরবর্তী();
        অন্যথা {
            expect("floating-point register");
        }
    } অন্যথা
        last_regset_register = first_regset_register;

    যদি (last_regset_register < first_regset_register) {
        tcc_error("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
    }
    skip('}');
    // Note: 0 (one down) is not implemented by us regardless.
    regset_item_গুনতি = last_regset_register - first_regset_register + 1;
    যদি (coprocessor == CP_DOUBLE_PRECISION_FLOAT)
        regset_item_গুনতি <<= 1;
    অন্যথা {
        extra_register_bit = first_regset_register & 1;
        first_regset_register >>= 1;
    }
    offset.type = OP_IM8;
    offset.e.v = regset_item_গুনতি << 2;
    নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
    ক্ষেত্র TOK_ASM_vstmeq: // post-increment store
    ক্ষেত্র TOK_ASM_vstmiaeq: // post-increment store
        বিরতি;
    ক্ষেত্র TOK_ASM_vpopeq:
    ক্ষেত্র TOK_ASM_vldmeq: // post-increment load
    ক্ষেত্র TOK_ASM_vldmiaeq: // post-increment load
        load = 1;
        বিরতি;
    ক্ষেত্র TOK_ASM_vldmdbeq: // pre-decrement load
        load = 1;
        /* fallthrough */
    ক্ষেত্র TOK_ASM_vpusheq:
    ক্ষেত্র TOK_ASM_vstmdbeq: // pre-decrement store
        offset.type = OP_IM8N;
        offset.e.v = -offset.e.v;
        preincrement = 1;
        বিরতি;
    পূর্বনির্ধারিত:
        expect("floating point block data transfer instruction");
    }
    যদি (ops[0].type != OP_REG32)
        expect("(first operand) register");
    অন্যথা যদি (ops[0].reg == 15)
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ফাঁকা));
    অন্যথা যদি (!op0_exclam && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vldmeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vldmiaeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vstmeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vstmiaeq)
        tcc_error("first operand of '%s' should have an exclamation mark", get_tok_str(token, ফাঁকা));
    অন্যথা
        asm_emit_coprocessor_তথ্য_transfer(condition_code_of_token(token), coprocessor, first_regset_register, &ops[0], &offset, 0, preincrement, op0_exclam, extra_register_bit, load);
}

#define VMOV_FRACTIONAL_DIGITS 7
#define VMOV_ONE 10000000 /* pow(10, VMOV_FRACTIONAL_DIGITS) */

স্থির uint32_t vmov_parse_fractional_part(ধ্রুবক অক্ষর* s)
{
    uint32_t ফলাফল = 0;
    পূর্ণসংখ্যা i;
    জন্য (i = 0; i < VMOV_FRACTIONAL_DIGITS; ++i) {
        অক্ষর c = *s;
        ফলাফল *= 10;
        যদি (c >= '0' && c <= '9') {
            ফলাফল += (c - '0');
            ++s;
        }
    }
    যদি (*s)
        expect("decimal numeral");
    ফেরত ফলাফল;
}

স্থির পূর্ণসংখ্যা vmov_linear_approx_সূচক(uint32_t beginning, uint32_t end, uint32_t মান)
{
    পূর্ণসংখ্যা i;
    uint32_t k;
    uint32_t xvalue;

    k = (end - beginning)/16;
    জন্য (xvalue = beginning, i = 0; i < 16; ++i, xvalue += k) {
        যদি (মান == xvalue)
            ফেরত i;
    }
    //assert(0);
    ফেরত -1;
}

স্থির uint32_t vmov_parse_immediate_মান() {
    uint32_t মান;
    unsigned long integral_মান;
    ধ্রুবক অক্ষর *p;

    যদি (tok != TOK_PPNUM) {
        expect("immediate value");
    }
    p = tokc.str.তথ্য;
    errno = 0;
    integral_মান = strtoul(p, (অক্ষর **)&p, 0);

    যদি (errno || integral_মান >= 32) {
        tcc_error("invalid floating-point immediate value");
    }

    মান = (uint32_t) integral_মান * VMOV_ONE;
    যদি (*p == '.') {
        ++p;
        মান += vmov_parse_fractional_part(p);
    }
    পরবর্তী();
    ফেরত মান;
}

স্থির uint8_t vmov_encode_immediate_মান(uint32_t মান)
{
    uint32_t limit;
    uint32_t end = 0;
    uint32_t beginning = 0;
    পূর্ণসংখ্যা r = -1;
    পূর্ণসংখ্যা n;
    পূর্ণসংখ্যা i;

    limit = 32 * VMOV_ONE;
    জন্য (i = 0; i < 8; ++i) {
        যদি (মান < limit) {
            end = limit;
            limit >>= 1;
            beginning = limit;
            r = i;
        } অন্যথা
            limit >>= 1;
    }
    যদি (r == -1 || মান < beginning || মান > end) {
        tcc_error("invalid decimal number for vmov: %d", মান);
    }
    n = vmov_linear_approx_সূচক(beginning, end, মান);
    ফেরত n | (((3 - r) & 0x7) << 4);
}

// Not standalone.
স্থির শূন্য asm_floating_point_immediate_তথ্য_processing_opcode_লেজ(TCCState *s1, পূর্ণসংখ্যা token, uint8_t coprocessor, uint8_t CRd) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    uint8_t operands[3] = {0, 0, 0};
    uint32_t immediate_মান = 0;
    পূর্ণসংখ্যা op_minus = 0;
    uint8_t code;

    operands[0] = CRd;

    যদি (tok == '#' || tok == '$') {
        পরবর্তী();
    }
    যদি (tok == '-') {
        op_minus = 1;
        পরবর্তী();
    }
    immediate_মান = vmov_parse_immediate_মান();

    opcode1 = 11; // "Other" instruction
    নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
    ক্ষেত্র TOK_ASM_vcmpeq_f32:
    ক্ষেত্র TOK_ASM_vcmpeq_f64:
        opcode2 = 2;
        operands[1] = 5;
        যদি (immediate_মান) {
            expect("Immediate value 0");
        }
        বিরতি;
    ক্ষেত্র TOK_ASM_vcmpeeq_f32:
    ক্ষেত্র TOK_ASM_vcmpeeq_f64:
        opcode2 = 6;
        operands[1] = 5;
        যদি (immediate_মান) {
            expect("Immediate value 0");
        }
        বিরতি;
    ক্ষেত্র TOK_ASM_vmoveq_f32:
    ক্ষেত্র TOK_ASM_vmoveq_f64:
        opcode2 = 0;
        যদি (op_minus)
            operands[1] = 0x8;
        অন্যথা
            operands[1] = 0x0;
        code = vmov_encode_immediate_মান(immediate_মান);
        operands[1] |= code >> 4;
        operands[2] = code & 0xF;
        বিরতি;
    পূর্বনির্ধারিত:
        expect("known floating point with immediate instruction");
    }

    যদি (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        যদি (operands[0] & 1)
            opcode1 |= 4;
        operands[0] >>= 1;
    }

    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, operands[0], operands[1], operands[2], opcode2, 0);
}

স্থির শূন্য asm_floating_point_reg_arm_reg_transfer_opcode_লেজ(TCCState *s1, পূর্ণসংখ্যা token, পূর্ণসংখ্যা coprocessor, পূর্ণসংখ্যা nb_arm_regs, পূর্ণসংখ্যা nb_ops, Operand ops[3]) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    নির্বাচন (coprocessor) {
    ক্ষেত্র CP_SINGLE_PRECISION_FLOAT:
        // "vmov.f32 r2, s3" or "vmov.f32 s3, r2"
        যদি (nb_ops != 2 || nb_arm_regs != 1) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and one ARM register operands");
        }
        যদি (ops[0].type != OP_REG32) { // determine mode: load or store
            // need to swap operands 0 and 1
            memcpy(&ops[2], &ops[1], আকার(ops[2]));
            memcpy(&ops[1], &ops[0], আকার(ops[1]));
            memcpy(&ops[0], &ops[2], আকার(ops[0]));
        } অন্যথা
            opcode1 |= 1;

        যদি (ops[1].type == OP_VREG32) {
            যদি (ops[1].reg & 1)
                opcode2 |= 4;
            ops[1].reg >>= 1;
        }

        যদি (ops[0].type == OP_VREG32) {
            যদি (ops[0].reg & 1)
                opcode1 |= 4;
            ops[0].reg >>= 1;
        }

        asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, 0x10, opcode2, 0);
        বিরতি;
    ক্ষেত্র CP_DOUBLE_PRECISION_FLOAT:
        যদি (nb_ops != 3 || nb_arm_regs != 2) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and two ARM register operands");
        }
        // Determine whether it's a store into a VFP register (vmov "d1, r2, r3") rather than "vmov r2, r3, d1"
        যদি (ops[0].type == OP_VREG64) {
            যদি (ops[2].type == OP_REG32) {
                Operand অস্থায়ী;
                // need to rotate operand list to the left
                memcpy(&অস্থায়ী, &ops[0], আকার(অস্থায়ী));
                memcpy(&ops[0], &ops[1], আকার(ops[0]));
                memcpy(&ops[1], &ops[2], আকার(ops[1]));
                memcpy(&ops[2], &অস্থায়ী, আকার(ops[2]));
            } অন্যথা {
                tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
            }
        } অন্যথা যদি (ops[0].type != OP_REG32 || ops[1].type != OP_REG32 || ops[2].type != OP_VREG64) {
            tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
        } অন্যথা {
            opcode1 |= 1;
        }
        asm_emit_coprocessor_তথ্য_transfer(condition_code_of_token(token), coprocessor, ops[0].reg, &ops[1], &ops[2], 0, 0, 0, 1, opcode1);
        বিরতি;
    পূর্বনির্ধারিত:
        tcc_internal_error("unknown coprocessor");
    }
}

স্থির শূন্য asm_floating_point_vcvt_তথ্য_processing_opcode(TCCState *s1, পূর্ণসংখ্যা token) {
    uint8_t coprocessor = 0;
    Operand ops[3];
    uint8_t opcode1 = 11;
    uint8_t opcode2 = 2;

    নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
    ক্ষেত্র TOK_ASM_vcvtreq_s32_f64:
    ক্ষেত্র TOK_ASM_vcvtreq_u32_f64:
    ক্ষেত্র TOK_ASM_vcvteq_s32_f64:
    ক্ষেত্র TOK_ASM_vcvteq_u32_f64:
    ক্ষেত্র TOK_ASM_vcvteq_f64_s32:
    ক্ষেত্র TOK_ASM_vcvteq_f64_u32:
    ক্ষেত্র TOK_ASM_vcvteq_f32_f64:
       coprocessor = CP_DOUBLE_PRECISION_FLOAT;
       বিরতি;
    ক্ষেত্র TOK_ASM_vcvtreq_s32_f32:
    ক্ষেত্র TOK_ASM_vcvtreq_u32_f32:
    ক্ষেত্র TOK_ASM_vcvteq_s32_f32:
    ক্ষেত্র TOK_ASM_vcvteq_u32_f32:
    ক্ষেত্র TOK_ASM_vcvteq_f32_s32:
    ক্ষেত্র TOK_ASM_vcvteq_f32_u32:
    ক্ষেত্র TOK_ASM_vcvteq_f64_f32:
       coprocessor = CP_SINGLE_PRECISION_FLOAT;
       বিরতি;
    পূর্বনির্ধারিত:
       tcc_error("Unknown coprocessor for instruction '%s'", get_tok_str(token, ফাঁকা));
    }

    parse_operand(s1, &ops[0]);
    ops[1].type = OP_IM8;
    ops[1].e.v = 8;
    /* floating-point -> integer */
    নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
    ক্ষেত্র TOK_ASM_vcvtreq_s32_f32:
    ক্ষেত্র TOK_ASM_vcvtreq_s32_f64:
    ক্ষেত্র TOK_ASM_vcvteq_s32_f32:
    ক্ষেত্র TOK_ASM_vcvteq_s32_f64:
        ops[1].e.v |= 1; // signed
        /* fall through */
    ক্ষেত্র TOK_ASM_vcvteq_u32_f32:
    ক্ষেত্র TOK_ASM_vcvteq_u32_f64:
    ক্ষেত্র TOK_ASM_vcvtreq_u32_f32:
    ক্ষেত্র TOK_ASM_vcvtreq_u32_f64:
        ops[1].e.v |= 4; // to_integer (opc2)
        বিরতি;
    /* floating-point size conversion */
    ক্ষেত্র TOK_ASM_vcvteq_f64_f32:
    ক্ষেত্র TOK_ASM_vcvteq_f32_f64:
        ops[1].e.v = 7;
        বিরতি;
    }

    skip(',');
    parse_operand(s1, &ops[2]);

    নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
    /* floating-point -> integer */
    ক্ষেত্র TOK_ASM_vcvteq_s32_f32:
    ক্ষেত্র TOK_ASM_vcvteq_s32_f64:
    ক্ষেত্র TOK_ASM_vcvteq_u32_f32:
    ক্ষেত্র TOK_ASM_vcvteq_u32_f64:
        opcode2 |= 4; // round_zero
        বিরতি;

    /* integer -> floating-point */
    ক্ষেত্র TOK_ASM_vcvteq_f64_s32:
    ক্ষেত্র TOK_ASM_vcvteq_f32_s32:
        opcode2 |= 4; // signed--special
        বিরতি;

    /* floating-point size conversion */
    ক্ষেত্র TOK_ASM_vcvteq_f64_f32:
    ক্ষেত্র TOK_ASM_vcvteq_f32_f64:
        opcode2 |= 4; // always set
        বিরতি;
    }

    নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
    ক্ষেত্র TOK_ASM_vcvteq_f64_u32:
    ক্ষেত্র TOK_ASM_vcvteq_f64_s32:
    ক্ষেত্র TOK_ASM_vcvteq_f64_f32:
        যদি (ops[0].type == OP_VREG64 && ops[2].type == OP_VREG32) {
        } অন্যথা {
            expect("d<number>, s<number>");
        }
        বিরতি;
    পূর্বনির্ধারিত:
        যদি (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
            যদি (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG32) {
            } অন্যথা {
                expect("s<number>, s<number>");
            }
        } অন্যথা যদি (coprocessor == CP_DOUBLE_PRECISION_FLOAT) {
            যদি (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG64) {
            } অন্যথা {
                expect("s<number>, d<number>");
            }
        }
    }

    যদি (ops[2].type == OP_VREG32) {
        যদি (ops[2].reg & 1)
            opcode2 |= 1;
        ops[2].reg >>= 1;
    }
    যদি (ops[0].type == OP_VREG32) {
        যদি (ops[0].reg & 1)
            opcode1 |= 4;
        ops[0].reg >>= 1;
    }
    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

স্থির শূন্য asm_floating_point_তথ্য_processing_opcode(TCCState *s1, পূর্ণসংখ্যা token) {
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0; // (0 || 2) | register selection
    Operand ops[3];
    uint8_t nb_ops = 0;
    পূর্ণসংখ্যা vmov = 0;
    পূর্ণসংখ্যা nb_arm_regs = 0;

/* TODO:
   Instruction    opcode opcode2  Reason
   =============================================================
   -              1?00   ?1?      Undefined
   VFNMS          1?01   ?0?      Must be unconditional
   VFNMA          1?01   ?1?      Must be unconditional
   VFMA           1?10   ?0?      Must be unconditional
   VFMS           1?10   ?1?      Must be unconditional

   VMOV Fd, Fm
   VMOV Sn, Sm, Rd, Rn
   VMOV Rd, Rn, Sn, Sm
   VMOV Dn[0], Rd
   VMOV Rd, Dn[0]
   VMOV Dn[1], Rd
   VMOV Rd, Dn[1]
*/

    নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
    ক্ষেত্র TOK_ASM_vmlaeq_f64:
    ক্ষেত্র TOK_ASM_vmlseq_f64:
    ক্ষেত্র TOK_ASM_vnmlseq_f64:
    ক্ষেত্র TOK_ASM_vnmlaeq_f64:
    ক্ষেত্র TOK_ASM_vmuleq_f64:
    ক্ষেত্র TOK_ASM_vnmuleq_f64:
    ক্ষেত্র TOK_ASM_vaddeq_f64:
    ক্ষেত্র TOK_ASM_vsubeq_f64:
    ক্ষেত্র TOK_ASM_vdiveq_f64:
    ক্ষেত্র TOK_ASM_vnegeq_f64:
    ক্ষেত্র TOK_ASM_vabseq_f64:
    ক্ষেত্র TOK_ASM_vsqrteq_f64:
    ক্ষেত্র TOK_ASM_vcmpeq_f64:
    ক্ষেত্র TOK_ASM_vcmpeeq_f64:
    ক্ষেত্র TOK_ASM_vmoveq_f64:
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
    }

    নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
    ক্ষেত্র TOK_ASM_vmoveq_f32:
    ক্ষেত্র TOK_ASM_vmoveq_f64:
        vmov = 1;
        বিরতি;
    }

    জন্য (nb_ops = 0; nb_ops < 3; ) {
        // Note: Necessary because parse_operand can't parse decimal numerals.
        যদি (nb_ops == 1 && (tok == '#' || tok == '$' || tok == TOK_PPNUM || tok == '-')) {
            asm_floating_point_immediate_তথ্য_processing_opcode_লেজ(s1, token, coprocessor, ops[0].reg);
            ফেরত;
        }
        parse_operand(s1, &ops[nb_ops]);
        যদি (vmov && ops[nb_ops].type == OP_REG32) {
            ++nb_arm_regs;
        } অন্যথা যদি (ops[nb_ops].type == OP_VREG32) {
            যদি (coprocessor != CP_SINGLE_PRECISION_FLOAT) {
                expect("'s<number>'");
            }
        } অন্যথা যদি (ops[nb_ops].type == OP_VREG64) {
            যদি (coprocessor != CP_DOUBLE_PRECISION_FLOAT) {
                expect("'d<number>'");
            }
        } অন্যথা {
            expect("floating point register");
        }
        ++nb_ops;
        যদি (tok == ',')
            পরবর্তী();
        অন্যথা
            বিরতি;
    }

    যদি (nb_arm_regs == 0) {
        যদি (nb_ops == 2) { // implicit
            memcpy(&ops[2], &ops[1], আকার(ops[1])); // move ops[2]
            memcpy(&ops[1], &ops[0], আকার(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
        যদি (nb_ops < 3) {
            tcc_error("Not enough operands for '%s' (%u)", get_tok_str(token, ফাঁকা), nb_ops);
        }
    }

    নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
    ক্ষেত্র TOK_ASM_vmlaeq_f32:
    ক্ষেত্র TOK_ASM_vmlaeq_f64:
        opcode1 = 0;
        opcode2 = 0;
        বিরতি;
    ক্ষেত্র TOK_ASM_vmlseq_f32:
    ক্ষেত্র TOK_ASM_vmlseq_f64:
        opcode1 = 0;
        opcode2 = 2;
        বিরতি;
    ক্ষেত্র TOK_ASM_vnmlseq_f32:
    ক্ষেত্র TOK_ASM_vnmlseq_f64:
        opcode1 = 1;
        opcode2 = 0;
        বিরতি;
    ক্ষেত্র TOK_ASM_vnmlaeq_f32:
    ক্ষেত্র TOK_ASM_vnmlaeq_f64:
        opcode1 = 1;
        opcode2 = 2;
        বিরতি;
    ক্ষেত্র TOK_ASM_vmuleq_f32:
    ক্ষেত্র TOK_ASM_vmuleq_f64:
        opcode1 = 2;
        opcode2 = 0;
        বিরতি;
    ক্ষেত্র TOK_ASM_vnmuleq_f32:
    ক্ষেত্র TOK_ASM_vnmuleq_f64:
        opcode1 = 2;
        opcode2 = 2;
        বিরতি;
    ক্ষেত্র TOK_ASM_vaddeq_f32:
    ক্ষেত্র TOK_ASM_vaddeq_f64:
        opcode1 = 3;
        opcode2 = 0;
        বিরতি;
    ক্ষেত্র TOK_ASM_vsubeq_f32:
    ক্ষেত্র TOK_ASM_vsubeq_f64:
        opcode1 = 3;
        opcode2 = 2;
        বিরতি;
    ক্ষেত্র TOK_ASM_vdiveq_f32:
    ক্ষেত্র TOK_ASM_vdiveq_f64:
        opcode1 = 8;
        opcode2 = 0;
        বিরতি;
    ক্ষেত্র TOK_ASM_vnegeq_f32:
    ক্ষেত্র TOK_ASM_vnegeq_f64:
        opcode1 = 11; // Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        বিরতি;
    ক্ষেত্র TOK_ASM_vabseq_f32:
    ক্ষেত্র TOK_ASM_vabseq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 0;
        বিরতি;
    ক্ষেত্র TOK_ASM_vsqrteq_f32:
    ক্ষেত্র TOK_ASM_vsqrteq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        বিরতি;
    ক্ষেত্র TOK_ASM_vcmpeq_f32:
    ক্ষেত্র TOK_ASM_vcmpeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        বিরতি;
    ক্ষেত্র TOK_ASM_vcmpeeq_f32:
    ক্ষেত্র TOK_ASM_vcmpeeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        বিরতি;
    ক্ষেত্র TOK_ASM_vmoveq_f32:
    ক্ষেত্র TOK_ASM_vmoveq_f64:
        যদি (nb_arm_regs > 0) { // vmov.f32 r2, s3 or similar
            asm_floating_point_reg_arm_reg_transfer_opcode_লেজ(s1, token, coprocessor, nb_arm_regs, nb_ops, ops);
            ফেরত;
        } অন্যথা {
            opcode1 = 11; // "Other" instruction
            opcode2 = 2;
            ops[1].type = OP_IM8;
            ops[1].e.v = 0;
        }
        বিরতি;
    পূর্বনির্ধারিত:
        expect("known floating point instruction");
    }

    যদি (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        যদি (ops[2].type == OP_VREG32) {
            যদি (ops[2].reg & 1)
                opcode2 |= 1;
            ops[2].reg >>= 1;
        }

        যদি (ops[1].type == OP_VREG32) {
            যদি (ops[1].reg & 1)
                opcode2 |= 4;
            ops[1].reg >>= 1;
        }

        যদি (ops[0].type == OP_VREG32) {
            যদি (ops[0].reg & 1)
                opcode1 |= 4;
            ops[0].reg >>= 1;
        }
    }

    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

স্থির পূর্ণসংখ্যা asm_parse_vfp_status_regvar(পূর্ণসংখ্যা t)
{
    নির্বাচন (t) {
    ক্ষেত্র TOK_ASM_fpsid:
        ফেরত 0;
    ক্ষেত্র TOK_ASM_fpscr:
        ফেরত 1;
    ক্ষেত্র TOK_ASM_fpexc:
        ফেরত 8;
    পূর্বনির্ধারিত:
        ফেরত -1;
    }
}

স্থির শূন্য asm_floating_point_status_register_opcode(TCCState* s1, পূর্ণসংখ্যা token)
{
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode;
    পূর্ণসংখ্যা vfp_sys_reg = -1;
    Operand arm_operand;
    নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
    ক্ষেত্র TOK_ASM_vmrseq:
        opcode = 0xf;
        যদি (tok == TOK_ASM_apsr_nzcv) {
            arm_operand.type = OP_REG32;
            arm_operand.reg = 15; // not PC
            পরবর্তী(); // skip apsr_nzcv
        } অন্যথা {
            parse_operand(s1, &arm_operand);
            যদি (arm_operand.type == OP_REG32 && arm_operand.reg == 15) {
                tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ফাঁকা));
            }
        }

        skip(',');
        vfp_sys_reg = asm_parse_vfp_status_regvar(tok);
        পরবর্তী(); // skip vfp sys reg
        যদি (arm_operand.type == OP_REG32 && arm_operand.reg == 15 && vfp_sys_reg != 1) {
            tcc_error("'%s' only supports the variant 'vmrs apsr_nzcv, fpscr' here", get_tok_str(token, ফাঁকা));
        }
        বিরতি;
    ক্ষেত্র TOK_ASM_vmsreq:
        opcode = 0xe;
        vfp_sys_reg = asm_parse_vfp_status_regvar(tok);
        পরবর্তী(); // skip vfp sys reg
        skip(',');
        parse_operand(s1, &arm_operand);
        যদি (arm_operand.type == OP_REG32 && arm_operand.reg == 15) {
            tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ফাঁকা));
        }
        বিরতি;
    পূর্বনির্ধারিত:
        expect("floating point status register instruction");
    }
    যদি (vfp_sys_reg == -1) {
        expect("VFP system register");
    }
    যদি (arm_operand.type != OP_REG32) {
        expect("ARM register");
    }
    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode, arm_operand.reg, vfp_sys_reg, 0x10, 0, 0);
}

#endif

স্থির শূন্য asm_misc_single_তথ্য_transfer_opcode(TCCState *s1, পূর্ণসংখ্যা token)
{
    Operand ops[3];
    পূর্ণসংখ্যা exclam = 0;
    পূর্ণসংখ্যা closed_bracket = 0;
    পূর্ণসংখ্যা op2_minus = 0;
    uint32_t opcode = (1 << 7) | (1 << 4);

    /* Note:
       The argument syntax is exactly the same as in arm_single_data_transfer_opcode, except that there's no STREX argument form.
       The main difference between this function and asm_misc_single_data_transfer_opcode is that the immediate values here must be smaller.
       Also, the combination (P=0, W=1) is unpredictable here.
       The immediate flag has moved to bit index 22--and its meaning has flipped.
       The immediate value itself has been split into two parts: one at bits 11...8, one at bits 3...0
       bit 26 (Load/Store instruction) is unset here.
       bits 7 and 4 are set here. */

    // Here: 0 0 0 P U I W L << 20
    // [compare single data transfer: 0 1 I P U B W L << 20]

    parse_operand(s1, &ops[0]);
    যদি (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    অন্যথা {
        expect("(destination operand) register");
    }
    যদি (tok != ',')
        expect("at least two arguments");
    অন্যথা
        পরবর্তী(); // skip ','
    skip('[');
    parse_operand(s1, &ops[1]);
    যদি (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    অন্যথা {
        expect("(first source operand) register");
    }
    যদি (tok == ']') {
        পরবর্তী();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    যদি (tok == ',') {
        পরবর্তী(); // skip ','
        যদি (tok == '-') {
            op2_minus = 1;
            পরবর্তী();
        }
        parse_operand(s1, &ops[2]);
    } অন্যথা {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        opcode |= 1 << 24; // add offset before transfer
    }
    যদি (!closed_bracket) {
        skip(']');
        opcode |= 1 << 24; // add offset before transfer
        যদি (tok == '!') {
            exclam = 1;
            পরবর্তী(); // skip '!'
        }
    }

    যদি (exclam) {
        যদি ((opcode & (1 << 24)) == 0) {
            tcc_error("result of '%s' would be unpredictable here", get_tok_str(token, ফাঁকা));
        }
        opcode |= 1 << 21; // write offset back into register
    }

    যদি (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        পূর্ণসংখ্যা v = ops[2].e.v;
        যদি (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        যদি (v >= 0) {
            opcode |= 1 << 23; // up
            যদি (v >= 0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ফাঁকা));
            অন্যথা {
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        } অন্যথা { // down
            যদি (v <= -0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ফাঁকা));
            অন্যথা {
                v = -v;
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        }
        opcode |= 1 << 22; // not ENCODE_IMMEDIATE_FLAG;
    } অন্যথা যদি (ops[2].type == OP_REG32) {
        যদি (!op2_minus)
            opcode |= 1 << 23; // up
        opcode |= ops[2].reg;
    } অন্যথা
        expect("register");

    নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
    ক্ষেত্র TOK_ASM_ldrsheq:
        opcode |= 1 << 5; // halfword, not byte
        /* fallthrough */
    ক্ষেত্র TOK_ASM_ldrsbeq:
        opcode |= 1 << 6; // sign extend
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        বিরতি;
    ক্ষেত্র TOK_ASM_ldrheq:
        opcode |= 1 << 5; // halfword, not byte
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        বিরতি;
    ক্ষেত্র TOK_ASM_strheq:
        opcode |= 1 << 5; // halfword, not byte
        asm_emit_opcode(token, opcode);
        বিরতি;
    }
}

/* Note: almost dupe of encbranch in arm-gen.c */
স্থির uint32_t encbranchoffset(পূর্ণসংখ্যা pos, পূর্ণসংখ্যা addr, পূর্ণসংখ্যা fail)
{
  addr-=pos+8;
  addr/=4;
  যদি(addr>=0x7fffff || addr<-0x800000) {
    যদি(fail)
      tcc_error("branch offset is too far");
    ফেরত 0;
  }
  ফেরত /*not 0x0A000000|*/(addr&0xffffff);
}

স্থির শূন্য asm_branch_opcode(TCCState *s1, পূর্ণসংখ্যা token)
{
    পূর্ণসংখ্যা jmp_disp = 0;
    Operand op;
    রাশিমালা_মান e;
    ElfSym *esym;

    নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
    ক্ষেত্র TOK_ASM_beq:
    ক্ষেত্র TOK_ASM_bleq:
        asm_রাশিমালা(s1, &e);
        যদি (e.sym) {
            esym = elfsym(e.sym);
            যদি (esym && esym->st_shndx == cur_text_section->sh_অঙ্ক) {
                jmp_disp = esym->st_মান;
            } অন্যথা {
                greloca(cur_text_section, e.sym, ind, R_ARM_PC24, 0);
                jmp_disp = ind;
            }
        }
        jmp_disp = encbranchoffset(ind, e.v + jmp_disp, 1);
        বিরতি;
    পূর্বনির্ধারিত:
        parse_operand(s1, &op);
        বিরতি;
    }
    নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
    ক্ষেত্র TOK_ASM_beq:
        asm_emit_opcode(token, (0xa << 24) | (jmp_disp & 0xffffff));
        বিরতি;
    ক্ষেত্র TOK_ASM_bleq:
        asm_emit_opcode(token, (0xb << 24) | (jmp_disp & 0xffffff));
        বিরতি;
    ক্ষেত্র TOK_ASM_bxeq:
        যদি (op.type != OP_REG32)
            expect("register");
        অন্যথা
            asm_emit_opcode(token, (0x12fff1 << 4) | op.reg);
        বিরতি;
    ক্ষেত্র TOK_ASM_blxeq:
        যদি (op.type != OP_REG32)
            expect("register");
        অন্যথা
            asm_emit_opcode(token, (0x12fff3 << 4) | op.reg);
        বিরতি;
    পূর্বনির্ধারিত:
        expect("branch instruction");
    }
}

ST_FUNC শূন্য asm_opcode(TCCState *s1, পূর্ণসংখ্যা token)
{
    যখন (token == TOK_LINEFEED) {
        পরবর্তী();
        token = tok;
    }
    যদি (token == TOK_EOF)
        ফেরত;
    যদি (token < TOK_ASM_nopeq) { // no condition code
        নির্বাচন (token) {
        ক্ষেত্র TOK_ASM_cdp2:
            asm_coprocessor_opcode(s1, token);
            ফেরত;
        ক্ষেত্র TOK_ASM_ldc2:
        ক্ষেত্র TOK_ASM_ldc2l:
        ক্ষেত্র TOK_ASM_stc2:
        ক্ষেত্র TOK_ASM_stc2l:
            asm_coprocessor_তথ্য_transfer_opcode(s1, token);
            ফেরত;
        পূর্বনির্ধারিত:
            expect("instruction");
        }
    }

    নির্বাচন (ARM_INSTRUCTION_GROUP(token)) {
    ক্ষেত্র TOK_ASM_pusheq:
    ক্ষেত্র TOK_ASM_popeq:
    ক্ষেত্র TOK_ASM_stmdaeq:
    ক্ষেত্র TOK_ASM_ldmdaeq:
    ক্ষেত্র TOK_ASM_stmeq:
    ক্ষেত্র TOK_ASM_ldmeq:
    ক্ষেত্র TOK_ASM_stmiaeq:
    ক্ষেত্র TOK_ASM_ldmiaeq:
    ক্ষেত্র TOK_ASM_stmdbeq:
    ক্ষেত্র TOK_ASM_ldmdbeq:
    ক্ষেত্র TOK_ASM_stmibeq:
    ক্ষেত্র TOK_ASM_ldmibeq:
        asm_block_তথ্য_transfer_opcode(s1, token);
        ফেরত;
    ক্ষেত্র TOK_ASM_nopeq:
    ক্ষেত্র TOK_ASM_wfeeq:
    ক্ষেত্র TOK_ASM_wfieq:
        asm_nullary_opcode(token);
        ফেরত;
    ক্ষেত্র TOK_ASM_swieq:
    ক্ষেত্র TOK_ASM_svceq:
        asm_unary_opcode(s1, token);
        ফেরত;
    ক্ষেত্র TOK_ASM_beq:
    ক্ষেত্র TOK_ASM_bleq:
    ক্ষেত্র TOK_ASM_bxeq:
    ক্ষেত্র TOK_ASM_blxeq:
        asm_branch_opcode(s1, token);
        ফেরত;
    ক্ষেত্র TOK_ASM_clzeq:
    ক্ষেত্র TOK_ASM_sxtbeq:
    ক্ষেত্র TOK_ASM_sxtheq:
    ক্ষেত্র TOK_ASM_uxtbeq:
    ক্ষেত্র TOK_ASM_uxtheq:
    ক্ষেত্র TOK_ASM_movteq:
    ক্ষেত্র TOK_ASM_movweq:
        asm_দ্বিমিক_opcode(s1, token);
        ফেরত;

    ক্ষেত্র TOK_ASM_ldreq:
    ক্ষেত্র TOK_ASM_ldrbeq:
    ক্ষেত্র TOK_ASM_streq:
    ক্ষেত্র TOK_ASM_strbeq:
    ক্ষেত্র TOK_ASM_ldrexeq:
    ক্ষেত্র TOK_ASM_ldrexbeq:
    ক্ষেত্র TOK_ASM_ldrexheq:
    ক্ষেত্র TOK_ASM_strexeq:
    ক্ষেত্র TOK_ASM_strexbeq:
    ক্ষেত্র TOK_ASM_strexheq:
        asm_single_তথ্য_transfer_opcode(s1, token);
        ফেরত;

    ক্ষেত্র TOK_ASM_ldrheq:
    ক্ষেত্র TOK_ASM_ldrsheq:
    ক্ষেত্র TOK_ASM_ldrsbeq:
    ক্ষেত্র TOK_ASM_strheq:
       asm_misc_single_তথ্য_transfer_opcode(s1, token);
       ফেরত;

    ক্ষেত্র TOK_ASM_andeq:
    ক্ষেত্র TOK_ASM_eoreq:
    ক্ষেত্র TOK_ASM_subeq:
    ক্ষেত্র TOK_ASM_rsbeq:
    ক্ষেত্র TOK_ASM_addeq:
    ক্ষেত্র TOK_ASM_adceq:
    ক্ষেত্র TOK_ASM_sbceq:
    ক্ষেত্র TOK_ASM_rsceq:
    ক্ষেত্র TOK_ASM_tsteq:
    ক্ষেত্র TOK_ASM_teqeq:
    ক্ষেত্র TOK_ASM_cmpeq:
    ক্ষেত্র TOK_ASM_cmneq:
    ক্ষেত্র TOK_ASM_orreq:
    ক্ষেত্র TOK_ASM_moveq:
    ক্ষেত্র TOK_ASM_biceq:
    ক্ষেত্র TOK_ASM_mvneq:
    ক্ষেত্র TOK_ASM_andseq:
    ক্ষেত্র TOK_ASM_eorseq:
    ক্ষেত্র TOK_ASM_subseq:
    ক্ষেত্র TOK_ASM_rsbseq:
    ক্ষেত্র TOK_ASM_addseq:
    ক্ষেত্র TOK_ASM_adcseq:
    ক্ষেত্র TOK_ASM_sbcseq:
    ক্ষেত্র TOK_ASM_rscseq:
//  case TOK_ASM_tstseq:
//  case TOK_ASM_teqseq:
//  case TOK_ASM_cmpseq:
//  case TOK_ASM_cmnseq:
    ক্ষেত্র TOK_ASM_orrseq:
    ক্ষেত্র TOK_ASM_movseq:
    ক্ষেত্র TOK_ASM_bicseq:
    ক্ষেত্র TOK_ASM_mvnseq:
        asm_তথ্য_processing_opcode(s1, token);
        ফেরত;

    ক্ষেত্র TOK_ASM_lsleq:
    ক্ষেত্র TOK_ASM_lslseq:
    ক্ষেত্র TOK_ASM_lsreq:
    ক্ষেত্র TOK_ASM_lsrseq:
    ক্ষেত্র TOK_ASM_asreq:
    ক্ষেত্র TOK_ASM_asrseq:
    ক্ষেত্র TOK_ASM_roreq:
    ক্ষেত্র TOK_ASM_rorseq:
    ক্ষেত্র TOK_ASM_rrxseq:
    ক্ষেত্র TOK_ASM_rrxeq:
        asm_shift_opcode(s1, token);
        ফেরত;

    ক্ষেত্র TOK_ASM_muleq:
    ক্ষেত্র TOK_ASM_mulseq:
    ক্ষেত্র TOK_ASM_mlaeq:
    ক্ষেত্র TOK_ASM_mlaseq:
    ক্ষেত্র TOK_ASM_mlseq:
    ক্ষেত্র TOK_ASM_udiveq:
    ক্ষেত্র TOK_ASM_sdiveq:
        asm_multiplication_opcode(s1, token);
        ফেরত;

    ক্ষেত্র TOK_ASM_smulleq:
    ক্ষেত্র TOK_ASM_smullseq:
    ক্ষেত্র TOK_ASM_umulleq:
    ক্ষেত্র TOK_ASM_umullseq:
    ক্ষেত্র TOK_ASM_smlaleq:
    ক্ষেত্র TOK_ASM_smlalseq:
    ক্ষেত্র TOK_ASM_umlaleq:
    ক্ষেত্র TOK_ASM_umlalseq:
        asm_long_multiplication_opcode(s1, token);
        ফেরত;

    ক্ষেত্র TOK_ASM_cdpeq:
    ক্ষেত্র TOK_ASM_mcreq:
    ক্ষেত্র TOK_ASM_mrceq:
        asm_coprocessor_opcode(s1, token);
        ফেরত;

    ক্ষেত্র TOK_ASM_ldceq:
    ক্ষেত্র TOK_ASM_ldcleq:
    ক্ষেত্র TOK_ASM_stceq:
    ক্ষেত্র TOK_ASM_stcleq:
        asm_coprocessor_তথ্য_transfer_opcode(s1, token);
        ফেরত;

#যদি defined(TCC_ARM_VFP)
    ক্ষেত্র TOK_ASM_vldreq:
    ক্ষেত্র TOK_ASM_vstreq:
        asm_floating_point_single_তথ্য_transfer_opcode(s1, token);
        ফেরত;

    ক্ষেত্র TOK_ASM_vmlaeq_f32:
    ক্ষেত্র TOK_ASM_vmlseq_f32:
    ক্ষেত্র TOK_ASM_vnmlseq_f32:
    ক্ষেত্র TOK_ASM_vnmlaeq_f32:
    ক্ষেত্র TOK_ASM_vmuleq_f32:
    ক্ষেত্র TOK_ASM_vnmuleq_f32:
    ক্ষেত্র TOK_ASM_vaddeq_f32:
    ক্ষেত্র TOK_ASM_vsubeq_f32:
    ক্ষেত্র TOK_ASM_vdiveq_f32:
    ক্ষেত্র TOK_ASM_vnegeq_f32:
    ক্ষেত্র TOK_ASM_vabseq_f32:
    ক্ষেত্র TOK_ASM_vsqrteq_f32:
    ক্ষেত্র TOK_ASM_vcmpeq_f32:
    ক্ষেত্র TOK_ASM_vcmpeeq_f32:
    ক্ষেত্র TOK_ASM_vmoveq_f32:
    ক্ষেত্র TOK_ASM_vmlaeq_f64:
    ক্ষেত্র TOK_ASM_vmlseq_f64:
    ক্ষেত্র TOK_ASM_vnmlseq_f64:
    ক্ষেত্র TOK_ASM_vnmlaeq_f64:
    ক্ষেত্র TOK_ASM_vmuleq_f64:
    ক্ষেত্র TOK_ASM_vnmuleq_f64:
    ক্ষেত্র TOK_ASM_vaddeq_f64:
    ক্ষেত্র TOK_ASM_vsubeq_f64:
    ক্ষেত্র TOK_ASM_vdiveq_f64:
    ক্ষেত্র TOK_ASM_vnegeq_f64:
    ক্ষেত্র TOK_ASM_vabseq_f64:
    ক্ষেত্র TOK_ASM_vsqrteq_f64:
    ক্ষেত্র TOK_ASM_vcmpeq_f64:
    ক্ষেত্র TOK_ASM_vcmpeeq_f64:
    ক্ষেত্র TOK_ASM_vmoveq_f64:
        asm_floating_point_তথ্য_processing_opcode(s1, token);
        ফেরত;

    ক্ষেত্র TOK_ASM_vcvtreq_s32_f32:
    ক্ষেত্র TOK_ASM_vcvtreq_s32_f64:
    ক্ষেত্র TOK_ASM_vcvteq_s32_f32:
    ক্ষেত্র TOK_ASM_vcvteq_s32_f64:
    ক্ষেত্র TOK_ASM_vcvtreq_u32_f32:
    ক্ষেত্র TOK_ASM_vcvtreq_u32_f64:
    ক্ষেত্র TOK_ASM_vcvteq_u32_f32:
    ক্ষেত্র TOK_ASM_vcvteq_u32_f64:
    ক্ষেত্র TOK_ASM_vcvteq_f64_s32:
    ক্ষেত্র TOK_ASM_vcvteq_f32_s32:
    ক্ষেত্র TOK_ASM_vcvteq_f64_u32:
    ক্ষেত্র TOK_ASM_vcvteq_f32_u32:
    ক্ষেত্র TOK_ASM_vcvteq_f64_f32:
    ক্ষেত্র TOK_ASM_vcvteq_f32_f64:
        asm_floating_point_vcvt_তথ্য_processing_opcode(s1, token);
        ফেরত;

    ক্ষেত্র TOK_ASM_vpusheq:
    ক্ষেত্র TOK_ASM_vpopeq:
    ক্ষেত্র TOK_ASM_vldmeq:
    ক্ষেত্র TOK_ASM_vldmiaeq:
    ক্ষেত্র TOK_ASM_vldmdbeq:
    ক্ষেত্র TOK_ASM_vstmeq:
    ক্ষেত্র TOK_ASM_vstmiaeq:
    ক্ষেত্র TOK_ASM_vstmdbeq:
        asm_floating_point_block_তথ্য_transfer_opcode(s1, token);
        ফেরত;

    ক্ষেত্র TOK_ASM_vmsreq:
    ক্ষেত্র TOK_ASM_vmrseq:
        asm_floating_point_status_register_opcode(s1, token);
        ফেরত;
#endif

    পূর্বনির্ধারিত:
        expect("known instruction");
    }
}

ST_FUNC শূন্য subst_asm_operand(CString *add_str, SValue *sv, পূর্ণসংখ্যা modifier)
{
    পূর্ণসংখ্যা r, reg, আকার_2, val;

    r = sv->r;
    যদি ((r & VT_VALMASK) == VT_CONST) {
        যদি (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(add_str, '#');
        যদি (r & VT_SYM) {
            ধ্রুবক অক্ষর *name = get_tok_str(sv->sym->v, ফাঁকা);
            যদি (sv->sym->v >= SYM_FIRST_ANOM) {
                /* In case of anonymous symbols ("L.42", used
                   for static data labels) we can't find them
                   in the C symbol table when later looking up
                   this name.  So enter them now into the asm label
                   list when we still know the symbol.  */
                get_asm_sym(tok_alloc(name, strlen(name))->tok, sv->sym);
            }
            যদি (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            যদি ((uint32_t) sv->c.i == 0)
                যাও no_offset;
            cstr_ccat(add_str, '+');
        }
        val = sv->c.i;
        যদি (modifier == 'n')
            val = -val;
        cstr_printf(add_str, "%d", val);
      no_offset:;
    } অন্যথা যদি ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "[fp,#%d]", (পূর্ণসংখ্যা) sv->c.i);
    } অন্যথা যদি (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        যদি (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "[%s]",
                 get_tok_str(TOK_ASM_r0 + reg, ফাঁকা));
    } অন্যথা {
        /* register case */
        reg = r & VT_VALMASK;
        যদি (reg >= VT_CONST)
            tcc_internal_error("");

        /* choose register operand size */
        যদি ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            আকার_2 = 1;
        অন্যথা যদি ((sv->type.t & VT_BTYPE) == VT_SHORT)
            আকার_2 = 2;
        অন্যথা
            আকার_2 = 4;

        যদি (modifier == 'b') {
            আকার_2 = 1;
        } অন্যথা যদি (modifier == 'w') {
            আকার_2 = 2;
        } অন্যথা যদি (modifier == 'k') {
            আকার_2 = 4;
        }

        নির্বাচন (আকার_2) {
        পূর্বনির্ধারিত:
            reg = TOK_ASM_r0 + reg;
            বিরতি;
        }
        cstr_printf(add_str, "%s", get_tok_str(reg, ফাঁকা));
    }
}

/* generate prolog and epilog code for asm statement */
ST_FUNC শূন্য asm_gen_code(ASMOperand *operands, পূর্ণসংখ্যা nb_operands,
                          পূর্ণসংখ্যা nb_outputs, পূর্ণসংখ্যা is_output,
                          uint8_t *clobber_regs,
                          পূর্ণসংখ্যা out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    পূর্ণসংখ্যা i, reg;
    uint32_t saved_regset = 0;

    // TODO: Check non-E ABI.
    // Note: Technically, r13 (sp) is also callee-saved--but that does not matter yet
    স্থির ধ্রুবক uint8_t reg_saved[] = { 4, 5, 6, 7, 8, 9 /* Note: sometimes special reg "sb" */ , 10, 11 };

    /* mark all used registers */
    memcpy(regs_allocated, clobber_regs, আকার(regs_allocated));
    জন্য(i = 0; i < nb_operands;i++) {
        op = &operands[i];
        যদি (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }
    জন্য(i = 0; i < আকার(reg_saved)/আকার(reg_saved[0]); i++) {
        reg = reg_saved[i];
        যদি (regs_allocated[reg])
            saved_regset |= 1 << reg;
    }

    যদি (!is_output) { // prolog
        /* generate reg save code */
        যদি (saved_regset)
            gen_le32(0xe92d0000 | saved_regset); // push {...}

        /* generate load code */
        জন্য(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            যদি (op->reg >= 0) {
                যদি ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_memory) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    load(op->reg, &sv);
                } অন্যথা যদি (i >= nb_outputs || op->is_rw) { // not write-only
                    /* load value in register */
                    load(op->reg, op->vt);
                    যদি (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }
    } অন্যথা { // epilog
        /* generate save code */
        জন্য(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            যদি (op->reg >= 0) {
                যদি ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    যদি (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        load(out_reg, &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(op->reg, &sv);
                    }
                } অন্যথা {
                    store(op->reg, op->vt);
                    যদি (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }

        /* generate reg restore code */
        যদি (saved_regset)
            gen_le32(0xe8bd0000 | saved_regset); // pop {...}
    }
}

/* return the constraint priority (we allocate first the lowest
   numbered constraints) */
স্থির অন্তঃরেখ পূর্ণসংখ্যা constraint_priority(ধ্রুবক অক্ষর *str)
{
    পূর্ণসংখ্যা priority, c, pr;

    /* we take the lowest priority */
    priority = 0;
    জন্য(;;) {
        c = *str;
        যদি (c == '\0')
            বিরতি;
        str++;
        নির্বাচন(c) {
        ক্ষেত্র 'l': // in ARM mode, that's  an alias for 'r' [ARM].
        ক্ষেত্র 'r': // register [general]
        ক্ষেত্র 'p': // valid memory address for load,store [general]
            pr = 3;
            বিরতি;
        ক্ষেত্র 'M': // integer constant for shifts [ARM]
        ক্ষেত্র 'I': // integer valid for data processing instruction immediate
        ক্ষেত্র 'J': // integer in range -4095...4095

        ক্ষেত্র 'i': // immediate integer operand, including symbolic constants [general]
        ক্ষেত্র 'm': // memory operand [general]
        ক্ষেত্র 'g': // general-purpose-register, memory, immediate integer [general]
            pr = 4;
            বিরতি;
        পূর্বনির্ধারিত:
            tcc_error("unknown constraint '%c'", c);
        }
        যদি (pr > priority)
            priority = pr;
    }
    ফেরত priority;
}

স্থির ধ্রুবক অক্ষর *skip_constraint_modifiers(ধ্রুবক অক্ষর *p)
{
    /* Constraint modifier:
        =   Operand is written to by this instruction
        +   Operand is both read and written to by this instruction
        %   Instruction is commutative for this operand and the following operand.

       Per-alternative constraint modifier:
        &   Operand is clobbered before the instruction is done using the input operands
    */
    যখন (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    ফেরত p;
}

#define REG_OUT_MASK 0x01
#define REG_IN_MASK  0x02

#define is_reg_allocated(reg) (regs_allocated[reg] & reg_mask)

ST_FUNC শূন্য asm_compute_constraints(ASMOperand *operands,
                                    পূর্ণসংখ্যা nb_operands, পূর্ণসংখ্যা nb_outputs,
                                    ধ্রুবক uint8_t *clobber_regs,
                                    পূর্ণসংখ্যা *pout_reg)
{
    /* overall format: modifier, then ,-seperated list of alternatives; all operands for a single instruction must have the same number of alternatives */
    /* TODO: Simple constraints
        whitespace  ignored
        o  memory operand that is offsetable
        V  memory but not offsetable
        <  memory operand with autodecrement addressing is allowed.  Restrictions apply.
        >  memory operand with autoincrement addressing is allowed.  Restrictions apply.
        n  immediate integer operand with a known numeric value
        E  immediate floating operand (const_double) is allowed, but only if target=host
        F  immediate floating operand (const_double or const_vector) is allowed
        s  immediate integer operand whose value is not an explicit integer
        X  any operand whatsoever
        0...9 (postfix); (can also be more than 1 digit number);  an operand that matches the specified operand number is allowed
    */

    /* TODO: ARM constraints:
        k the stack pointer register
        G the floating-point constant 0.0
        Q memory reference where the exact address is in a single register ("m" is preferable for asm statements)
        R an item in the constant pool
        S symbol in the text segment of the current file
[       Uv memory reference suitable for VFP load/store insns (reg+constant offset)]
[       Uy memory reference suitable for iWMMXt load/store instructions]
        Uq memory reference suitable for the ARMv4 ldrsb instruction
    */
    ASMOperand *op;
    পূর্ণসংখ্যা sorted_op[MAX_ASM_OPERANDS];
    পূর্ণসংখ্যা i, j, k, p1, p2, tmp, reg, c, reg_mask;
    ধ্রুবক অক্ষর *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    জন্য (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->প্রবেশ_সূচক = -1;
        op->ref_সূচক = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    জন্য (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        যদি (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = find_constraint(operands, nb_operands, str, ফাঁকা);
            যদি ((unsigned) k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                          i, str);
            op->ref_সূচক = k;
            যদি (operands[k].প্রবেশ_সূচক >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].প্রবেশ_সূচক = i;
            op->priority = 5;
        } অন্যথা যদি ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->priority = 1;
            op->reg = reg;
        } অন্যথা {
            op->priority = constraint_priority(str);
        }
    }

    /* sort operands according to their priority */
    জন্য (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    জন্য (i = 0; i < nb_operands - 1; i++) {
        জন্য (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            যদি (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    জন্য (i = 0; i < NB_ASM_REGS; i++) {
        যদি (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        অন্যথা
            regs_allocated[i] = 0;
    }
    /* sp cannot be used */
    regs_allocated[13] = REG_IN_MASK | REG_OUT_MASK;
    /* fp cannot be used yet */
    regs_allocated[11] = REG_IN_MASK | REG_OUT_MASK;

    /* allocate registers and generate corresponding asm moves */
    জন্য (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        যদি (op->ref_সূচক >= 0)
            চালু;
        /* select if register is used for output, input or both */
        যদি (op->প্রবেশ_সূচক >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } অন্যথা যদি (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } অন্যথা {
            reg_mask = REG_IN_MASK;
        }
        যদি (op->reg >= 0) {
            যদি (is_reg_allocated(op->reg))
                tcc_error
                    ("asm regvar requests register that's taken already");
            reg = op->reg;
        }
      try_পরবর্তী:
        c = *str++;
        নির্বাচন (c) {
        ক্ষেত্র '=': // Operand is written-to
            যাও try_পরবর্তী;
        ক্ষেত্র '+': // Operand is both READ and written-to
            op->is_rw = 1;
            /* FALL THRU */
        ক্ষেত্র '&': // Operand is clobbered before the instruction is done using the input operands
            যদি (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs",
                          c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            যাও try_পরবর্তী;
        ক্ষেত্র 'l': // In non-thumb mode, alias for 'r'--otherwise r0-r7 [ARM]
        ক্ষেত্র 'r': // general-purpose register
        ক্ষেত্র 'p': // loadable/storable address
            /* any general register */
            যদি ((reg = op->reg) >= 0)
                যাও reg_found;
            অন্যথা জন্য (reg = 0; reg <= 8; reg++) {
                যদি (!is_reg_allocated(reg))
                    যাও reg_found;
            }
            যাও try_পরবর্তী;
          reg_found:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_mask;
            বিরতি;
        ক্ষেত্র 'I': // integer that is valid as an data processing instruction immediate (0...255, rotated by a multiple of two)
        ক্ষেত্র 'J': // integer in the range -4095 to 4095 [ARM]
        ক্ষেত্র 'K': // integer that satisfies constraint I when inverted (one's complement)
        ক্ষেত্র 'L': // integer that satisfies constraint I when inverted (two's complement)
        ক্ষেত্র 'i': // immediate integer operand, including symbolic constants
            যদি (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                যাও try_পরবর্তী;
            বিরতি;
        ক্ষেত্র 'M': // integer in the range 0 to 32
            যদি (!
                ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) ==
                 VT_CONST))
                যাও try_পরবর্তী;
            বিরতি;
        ক্ষেত্র 'm': // memory operand
        ক্ষেত্র 'g':
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            যদি (j < nb_outputs || c == 'm') {
                যদি ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register */
                    জন্য (reg = 0; reg <= 8; reg++) {
                        যদি (!(regs_allocated[reg] & REG_IN_MASK))
                            যাও reg_found1;
                    }
                    যাও try_পরবর্তী;
                  reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_IN_MASK;
                    op->reg = reg;
                    op->is_memory = 1;
                }
            }
            বিরতি;
        পূর্বনির্ধারিত:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                      j, op->constraint);
            বিরতি;
        }
        /* if a reference is present for that operand, we assign it too */
        যদি (op->প্রবেশ_সূচক >= 0) {
            operands[op->প্রবেশ_সূচক].reg = op->reg;
            operands[op->প্রবেশ_সূচক].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    জন্য (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        যদি (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL && !op->is_memory) {
            জন্য (reg = 0; reg <= 8; reg++) {
                যদি (!(regs_allocated[reg] & REG_OUT_MASK))
                    যাও reg_found2;
            }
            tcc_error("could not find free output register for reloading");
          reg_found2:
            *pout_reg = reg;
            বিরতি;
        }
    }

    /* print sorted constraints */
#ifdef ASM_DEBUG
    জন্য (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        printf("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, ফাঁকা) : "",
               op->constraint, op->vt->r, op->reg);
    }
    যদি (*pout_reg >= 0)
        printf("out_reg=%d\n", *pout_reg);
#endif
}

ST_FUNC শূন্য asm_clobber(uint8_t *clobber_regs, ধ্রুবক অক্ষর *str)
{
    পূর্ণসংখ্যা reg;
    TokenSym *ts;

    যদি (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        ফেরত;
    ts = tok_alloc(str, strlen(str));
    reg = asm_parse_regvar(ts->tok);
    যদি (reg == -1) {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}

/* If T refers to a register then return the register number and type.
   Otherwise return -1.  */
ST_FUNC পূর্ণসংখ্যা asm_parse_regvar (পূর্ণসংখ্যা t)
{
    /* coprocessors (p0-p15) and coprocessor registers (c0-c15) are handled elsewere */
    /* single fp (s0-s31) and double fp registers (d0-d15) are handled elsewere */

    যদি (t < TOK_ASM_r0 || t > TOK_ASM_pc) /* filter unrelated registers */
        ফেরত -1;

    যদি (t <= TOK_ASM_r15)       /* default register names r0-r15 */
        ফেরত t - TOK_ASM_r0;

    যদি (t <= TOK_ASM_v8)        /* synonym register names a1-a4,v1-v8 (alias: r0-r11) */
        ফেরত t - TOK_ASM_a1;

    /* special register names sb/sl/fp/ip/sp/lr/pc (alias: r9-r15) */
    ফেরত t - TOK_ASM_sb + (TOK_ASM_r9 - TOK_ASM_r0);
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */

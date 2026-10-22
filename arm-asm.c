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

ST_FUNC শূন্য g(পূর্ণাঙ্ক c);
ST_FUNC শূন্য gen_le16(পূর্ণাঙ্ক c);
ST_FUNC শূন্য gen_le32(পূর্ণাঙ্ক c);

/*************************************************************/
#অন্যথা
/*************************************************************/

#define USING_GLOBALS
#অন্তর্ভাৱ "tcc.h"

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

প্রকারনির্দেশ সংরচনা Operand {
    uint32_t type;
    সঙ্ঘ {
        uint8_t reg;
        uint16_t regset;
        ৰাশিমালা_মান e;
    };
} Operand;

/* Read the VFP register referred to by token T.
   If OK, returns its number.
   If not OK, returns -1. */
স্থির পূর্ণাঙ্ক asm_parse_vfp_regvar(পূর্ণাঙ্ক t, পূর্ণাঙ্ক double_precision)
{
    যদি (double_precision) {
        যদি (t >= TOK_ASM_d0 && t <= TOK_ASM_d15)
            ঘূৰাই t - TOK_ASM_d0;
    } অন্যথা {
        যদি (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
            ঘূৰাই t - TOK_ASM_s0;
    }
    ঘূৰাই -1;
}

/* Parse a text containing operand and store the result in OP */
স্থির শূন্য parse_operand(TCCState *s1, Operand *op)
{
    ৰাশিমালা_মান e;
    int8_t reg;
    uint16_t regset = 0;

    op->type = 0;

    যদি (tok == '{') { // regset literal
        next(); // skip '{'
        যেতিয়ালৈ (tok != '}' && tok != TOK_EOF) {
            reg = asm_parse_regvar(tok);
            যদি (reg == -1) {
                expect("register");
            } অন্যথা
                next(); // skip register name

            যদি ((1 << reg) < regset)
                tcc_warning("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
            regset |= 1 << reg;
            যদি (tok != ',')
                ভঙ্গ;
            next(); // skip ','
        }
        skip('}');
        যদি (regset == 0) {
            // ARM instructions don't support empty regset.
            tcc_error("empty register list is not supported");
        } অন্যথা {
            op->type = OP_REGSET32;
            op->regset = regset;
        }
        ঘূৰাই;
    } অন্যথা যদি ((reg = asm_parse_regvar(tok)) != -1) {
        next(); // skip register name
        op->type = OP_REG32;
        op->reg = (uint8_t) reg;
        ঘূৰাই;
    } অন্যথা যদি ((reg = asm_parse_vfp_regvar(tok, 0)) != -1) {
        next(); // skip register name
        op->type = OP_VREG32;
        op->reg = (uint8_t) reg;
        ঘূৰাই;
    } অন্যথা যদি ((reg = asm_parse_vfp_regvar(tok, 1)) != -1) {
        next(); // skip register name
        op->type = OP_VREG64;
        op->reg = (uint8_t) reg;
        ঘূৰাই;
    } অন্যথা যদি (tok == '#' || tok == '$') {
        /* constant value */
        next(); // skip '#' or '$'
    }
    asm_ৰাশিমালা(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    যদি (!op->e.sym) {
        যদি ((পূর্ণাঙ্ক) op->e.v < 0 && (পূর্ণাঙ্ক) op->e.v >= -255)
            op->type = OP_IM8N;
        অন্যথা যদি (op->e.v == (uint8_t)op->e.v)
            op->type = OP_IM8;
    } অন্যথা
        expect("operand");
}

/* XXX: make it faster ? */
ST_FUNC শূন্য g(পূর্ণাঙ্ক c)
{
    পূর্ণাঙ্ক ind1;
    যদি (nocode_wanted)
        ঘূৰাই;
    ind1 = ind + 1;
    যদি (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC শূন্য gen_le16 (পূর্ণাঙ্ক i)
{
    g(i);
    g(i>>8);
}

ST_FUNC শূন্য gen_le32 (পূর্ণাঙ্ক i)
{
    পূর্ণাঙ্ক ind1;
    যদি (nocode_wanted)
        ঘূৰাই;
    ind1 = ind + 4;
    যদি (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind++] = i & 0xFF;
    cur_text_section->data[ind++] = (i >> 8) & 0xFF;
    cur_text_section->data[ind++] = (i >> 16) & 0xFF;
    cur_text_section->data[ind++] = (i >> 24) & 0xFF;
}

ST_FUNC শূন্য gen_expr32(ৰাশিমালা_মান *pe)
{
    gen_le32(pe->v);
}

স্থির uint32_t condition_code_of_token(পূর্ণাঙ্ক token) {
    যদি (token < TOK_ASM_nopeq) {
        expect("condition-enabled instruction");
    } অন্যথা
        ঘূৰাই (token - TOK_ASM_nopeq) & 15;
}

স্থির শূন্য asm_emit_opcode(পূর্ণাঙ্ক token, uint32_t opcode) {
    gen_le32((condition_code_of_token(token) << 28) | opcode);
}

স্থির শূন্য asm_emit_unconditional_opcode(uint32_t opcode) {
    gen_le32(opcode);
}

স্থির শূন্য asm_emit_coprocessor_opcode(uint32_t উপৰেৰ_nibble, uint8_t cp_সংখ্যা, uint8_t cp_opcode, uint8_t cp_destination_register, uint8_t cp_n_operand_register, uint8_t cp_m_operand_register, uint8_t cp_opcode2, পূর্ণাঙ্ক inter_processor_transfer)
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
    asm_emit_unconditional_opcode((উপৰেৰ_nibble << 28) | opcode);
}

স্থির শূন্য asm_nullary_opcode(পূর্ণাঙ্ক token)
{
    ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
    পক্ষ TOK_ASM_nopeq:
        asm_emit_opcode(token, 0xd << 21); // mov r0, r0
        ভঙ্গ;
    পক্ষ TOK_ASM_wfeeq:
        asm_emit_opcode(token, 0x320f002);
    পক্ষ TOK_ASM_wfieq:
        asm_emit_opcode(token, 0x320f003);
        ভঙ্গ;
    স্ৱভাৱ:
        expect("nullary instruction");
    }
}

স্থির শূন্য asm_unary_opcode(TCCState *s1, পূর্ণাঙ্ক token)
{
    Operand op;
    parse_operand(s1, &op);

    ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
    পক্ষ TOK_ASM_swieq:
    পক্ষ TOK_ASM_svceq:
        যদি (op.type != OP_IM8)
            expect("immediate 8-bit unsigned integer");
        অন্যথা {
            /* Note: Dummy operand (ignored by processor): ARM ref documented 0...255, ARM instruction set documented 24 bit */
            asm_emit_opcode(token, (0xf << 24) | op.e.v);
        }
        ভঙ্গ;
    স্ৱভাৱ:
        expect("unary instruction");
    }
}

স্থির শূন্য asm_দ্বিমিক_opcode(TCCState *s1, পূর্ণাঙ্ক token)
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
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, রিক্ত));
    }

    যদি (ops[0].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, রিক্ত));

    যদি (ops[1].type != OP_REG32) {
        ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
        পক্ষ TOK_ASM_movteq:
        পক্ষ TOK_ASM_movweq:
            যদি (ops[1].type == OP_IM8 || ops[1].type == OP_IM8N || ops[1].type == OP_IM32) {
                যদি (ops[1].e.v >= 0 && ops[1].e.v <= 0xFFFF) {
                    uint16_t immediate_মান = ops[1].e.v;
                    ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
                    পক্ষ TOK_ASM_movteq:
                        asm_emit_opcode(token, 0x3400000 | (ops[0].reg << 12) | (immediate_মান & 0xF000) << 4 | (immediate_মান & 0xFFF));
                        ভঙ্গ;
                    পক্ষ TOK_ASM_movweq:
                        asm_emit_opcode(token, 0x3000000 | (ops[0].reg << 12) | (immediate_মান & 0xF000) << 4 | (immediate_মান & 0xFFF));
                        ভঙ্গ;
                    }
                } অন্যথা
                    expect("(source operand) immediate 16 bit value");
            } অন্যথা
                expect("(source operand) immediate");
            ভঙ্গ;
        স্ৱভাৱ:
            expect("(source operand) register");
        }
        ঘূৰাই;
    }

    যদি (ops[1].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, রিক্ত));
    }

    যদি (ops[1].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, রিক্ত));

    যদি (tok == ',') {
        next(); // skip ','
        যদি (tok == TOK_ASM_ror) {
            next(); // skip 'ror'
            parse_operand(s1, &rotation);
            যদি (rotation.type != OP_IM8) {
                expect("immediate value for rotation");
            } অন্যথা {
                amount = rotation.e.v;
                ৱিকল্প (amount) {
                পক্ষ 8:
                    encoded_rotation = 1 << 10;
                    ভঙ্গ;
                পক্ষ 16:
                    encoded_rotation = 2 << 10;
                    ভঙ্গ;
                পক্ষ 24:
                    encoded_rotation = 3 << 10;
                    ভঙ্গ;
                স্ৱভাৱ:
                    expect("'8' or '16' or '24'");
                }
            }
        }
    }
    ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
    পক্ষ TOK_ASM_clzeq:
        যদি (encoded_rotation)
            tcc_error("clz does not support rotation");
        asm_emit_opcode(token, 0x16f0f10 | (ops[0].reg << 12) | ops[1].reg);
        ভঙ্গ;
    পক্ষ TOK_ASM_sxtbeq:
        asm_emit_opcode(token, 0x6af0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        ভঙ্গ;
    পক্ষ TOK_ASM_sxtheq:
        asm_emit_opcode(token, 0x6bf0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        ভঙ্গ;
    পক্ষ TOK_ASM_uxtbeq:
        asm_emit_opcode(token, 0x6ef0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        ভঙ্গ;
    পক্ষ TOK_ASM_uxtheq:
        asm_emit_opcode(token, 0x6ff0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        ভঙ্গ;
    স্ৱভাৱ:
        expect("binary instruction");
    }
}

স্থির শূন্য asm_coprocessor_opcode(TCCState *s1, পূর্ণাঙ্ক token) {
    uint8_t coprocessor;
    Operand opcode1;
    Operand opcode2;
    uint8_t registers[3];
    unsigned পূর্ণাঙ্ক i;
    uint8_t উপৰেৰ_nibble;
    uint8_t mrc = 0;

    যদি (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        next();
    } অন্যথা {
        expect("'p<number>'");
    }
    skip(',');
    parse_operand(s1, &opcode1);
    যদি (opcode1.type != OP_IM8 || opcode1.e.v > 15) {
        tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, রিক্ত));
    }

    বাবে (i = 0; i < 3; ++i) {
        skip(',');
        যদি (i == 0 && token != TOK_ASM_cdp2 && (ARM_INSTRUCTION_GROUP(token) == TOK_ASM_mrceq || ARM_INSTRUCTION_GROUP(token) == TOK_ASM_mcreq)) {
            যদি (tok >= TOK_ASM_r0 && tok <= TOK_ASM_pc) {
                registers[i] = asm_parse_regvar(tok);
                next();
            } অন্যথা {
                expect("'r<number>'");
            }
        } অন্যথা {
            যদি (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
                registers[i] = tok - TOK_ASM_c0;
                next();
            } অন্যথা {
                expect("'c<number>'");
            }
        }
    }
    যদি (tok == ',') {
        next();
        parse_operand(s1, &opcode2);
    } অন্যথা {
        opcode2.type = OP_IM8;
        opcode2.e.v = 0;
    }
    যদি (opcode2.type != OP_IM8 || opcode2.e.v > 15) {
        tcc_error("opcode2 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, রিক্ত));
    }

    যদি (token == TOK_ASM_cdp2) {
        উপৰেৰ_nibble = 0xF;
        asm_emit_coprocessor_opcode(উপৰেৰ_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        ঘূৰাই;
    } অন্যথা
        উপৰেৰ_nibble = condition_code_of_token(token);

    ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
    পক্ষ TOK_ASM_cdpeq:
        asm_emit_coprocessor_opcode(উপৰেৰ_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        ভঙ্গ;
    পক্ষ TOK_ASM_mrceq:
        // opcode1 encoding changes! highest and lowest bit gone.
        mrc = 1;
        /* fallthrough */
    পক্ষ TOK_ASM_mcreq:
        // opcode1 encoding changes! highest and lowest bit gone.
        যদি (opcode1.e.v > 7) {
            tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 7", get_tok_str(token, রিক্ত));
        }
        asm_emit_coprocessor_opcode(উপৰেৰ_nibble, coprocessor, (opcode1.e.v << 1) | mrc, registers[0], registers[1], registers[2], opcode2.e.v, 1);
        ভঙ্গ;
    স্ৱভাৱ:
        expect("known instruction");
    }
}

/* data processing and single data transfer instructions only */
#define ENCODE_RN(register_index) ((register_index) << 16)
#define ENCODE_RD(register_index) ((register_index) << 12)
#define ENCODE_SET_CONDITION_CODES (1 << 20)

/* Note: For data processing instructions, "1" means immediate.
   Note: For single data transfer instructions, "0" means immediate. */
#define ENCODE_IMMEDIATE_FLAG (1 << 25)

#define ENCODE_BARREL_SHIFTER_SHIFT_BY_REGISTER (1 << 4)
#define ENCODE_BARREL_SHIFTER_MODE_LSL (0 << 5)
#define ENCODE_BARREL_SHIFTER_MODE_LSR (1 << 5)
#define ENCODE_BARREL_SHIFTER_MODE_ASR (2 << 5)
#define ENCODE_BARREL_SHIFTER_MODE_ROR (3 << 5)
#define ENCODE_BARREL_SHIFTER_REGISTER(register_index) ((register_index) << 8)
#define ENCODE_BARREL_SHIFTER_IMMEDIATE(মান) ((মান) << 7)

স্থির শূন্য asm_block_data_transfer_opcode(TCCState *s1, পূর্ণাঙ্ক token)
{
    uint32_t opcode;
    পূর্ণাঙ্ক op0_exclam = 0;
    Operand ops[2];
    পূর্ণাঙ্ক nb_ops = 1;
    parse_operand(s1, &ops[0]);
    যদি (tok == '!') {
        op0_exclam = 1;
        next(); // skip '!'
    }
    যদি (tok == ',') {
        next(); // skip comma
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

    ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
    পক্ষ TOK_ASM_pusheq: // TODO: Optimize 1-register case to: str ?, [sp, #-4]!
        // Instruction: 1 I=0 P=1 U=0 S=0 W=1 L=0 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        যদি (nb_ops != 1)
            expect("exactly one operand");
        অন্যথা
            asm_emit_opcode(token, (0x92d << 16) | ops[0].regset); // TODO: base register ?
        ভঙ্গ;
    পক্ষ TOK_ASM_popeq: // TODO: Optimize 1-register case to: ldr ?, [sp], #4
        // Instruction: 1 I=0 P=0 U=1 S=0 W=0 L=1 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        যদি (nb_ops != 1)
            expect("exactly one operand");
        অন্যথা
            asm_emit_opcode(token, (0x8bd << 16) | ops[0].regset); // TODO: base register ?
        ভঙ্গ;
    পক্ষ TOK_ASM_stmdaeq:
    পক্ষ TOK_ASM_ldmdaeq:
    পক্ষ TOK_ASM_stmeq:
    পক্ষ TOK_ASM_ldmeq:
    পক্ষ TOK_ASM_stmiaeq:
    পক্ষ TOK_ASM_ldmiaeq:
    পক্ষ TOK_ASM_stmdbeq:
    পক্ষ TOK_ASM_ldmdbeq:
    পক্ষ TOK_ASM_stmibeq:
    পক্ষ TOK_ASM_ldmibeq:
        ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
        পক্ষ TOK_ASM_stmdaeq: // post-decrement store
            opcode = 0x80 << 20;
            ভঙ্গ;
        পক্ষ TOK_ASM_ldmdaeq: // post-decrement load
            opcode = 0x81 << 20;
            ভঙ্গ;
        পক্ষ TOK_ASM_stmeq: // post-increment store
        পক্ষ TOK_ASM_stmiaeq: // post-increment store
            opcode = 0x88 << 20;
            ভঙ্গ;
        পক্ষ TOK_ASM_ldmeq: // post-increment load
        পক্ষ TOK_ASM_ldmiaeq: // post-increment load
            opcode = 0x89 << 20;
            ভঙ্গ;
        পক্ষ TOK_ASM_stmdbeq: // pre-decrement store
            opcode = 0x90 << 20;
            ভঙ্গ;
        পক্ষ TOK_ASM_ldmdbeq: // pre-decrement load
            opcode = 0x91 << 20;
            ভঙ্গ;
        পক্ষ TOK_ASM_stmibeq: // pre-increment store
            opcode = 0x98 << 20;
            ভঙ্গ;
        পক্ষ TOK_ASM_ldmibeq: // pre-increment load
            opcode = 0x99 << 20;
            ভঙ্গ;
        স্ৱভাৱ:
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
        ভঙ্গ;
    স্ৱভাৱ:
        expect("block data transfer instruction");
    }
}

/* Parses shift directive and returns the parts that would have to be set in the opcode because of it.
   Does not encode the actual shift amount.
   It's not an error if there is no shift directive.

   NB_SHIFT: will be set to 1 iff SHIFT is filled.  Note that for rrx, there's no need to fill SHIFT.
   SHIFT: will be filled in with the shift operand to use, if any. */
স্থির uint32_t asm_parse_optional_shift(TCCState* s1, পূর্ণাঙ্ক* nb_shift, Operand* shift)
{
    uint32_t opcode = 0;
    *nb_shift = 0;
    ৱিকল্প (tok) {
    পক্ষ TOK_ASM_asl:
    পক্ষ TOK_ASM_lsl:
    পক্ষ TOK_ASM_asr:
    পক্ষ TOK_ASM_lsr:
    পক্ষ TOK_ASM_ror:
        ৱিকল্প (tok) {
        পক্ষ TOK_ASM_asl:
            /* fallthrough */
        পক্ষ TOK_ASM_lsl:
            opcode = ENCODE_BARREL_SHIFTER_MODE_LSL;
            ভঙ্গ;
        পক্ষ TOK_ASM_asr:
            opcode = ENCODE_BARREL_SHIFTER_MODE_ASR;
            ভঙ্গ;
        পক্ষ TOK_ASM_lsr:
            opcode = ENCODE_BARREL_SHIFTER_MODE_LSR;
            ভঙ্গ;
        পক্ষ TOK_ASM_ror:
            opcode = ENCODE_BARREL_SHIFTER_MODE_ROR;
            ভঙ্গ;
        }
        next();
        parse_operand(s1, shift);
        *nb_shift = 1;
        ভঙ্গ;
    পক্ষ TOK_ASM_rrx:
        next();
        opcode = ENCODE_BARREL_SHIFTER_MODE_ROR;
        ভঙ্গ;
    }
    ঘূৰাই opcode;
}

স্থির uint32_t asm_encode_shift(Operand* shift)
{
    uint64_t amount;
    uint32_t operands = 0;
    ৱিকল্প (shift->type) {
    পক্ষ OP_REG32:
        যদি (shift->reg == 15)
            tcc_error("r15 cannot be used as a shift count");
        অন্যথা {
            operands = ENCODE_BARREL_SHIFTER_SHIFT_BY_REGISTER;
            operands |= ENCODE_BARREL_SHIFTER_REGISTER(shift->reg);
        }
        ভঙ্গ;
    পক্ষ OP_IM8:
        amount = shift->e.v;
        যদি (amount > 0 && amount < 32)
            operands = ENCODE_BARREL_SHIFTER_IMMEDIATE(amount);
        অন্যথা
            tcc_error("shift count out of range");
        ভঙ্গ;
    স্ৱভাৱ:
        tcc_error("unknown shift amount");
    }
    ঘূৰাই operands;
}

স্থির শূন্য asm_data_processing_opcode(TCCState *s1, পূর্ণাঙ্ক token)
{
    Operand ops[3];
    পূর্ণাঙ্ক nb_ops;
    Operand shift = {0};
    পূর্ণাঙ্ক nb_shift = 0;
    uint32_t operands = 0;

    /* modulo 16 entries per instruction for the different condition codes */
    uint32_t opcode_idx = (ARM_INSTRUCTION_GROUP(token) - TOK_ASM_andeq) >> 4;
    uint32_t opcode_nos = opcode_idx >> 1; // without "s"; "OpCode" in ARM docs

    বাবে (nb_ops = 0; nb_ops < পরিমাণ(ops)/পরিমাণ(ops[0]); ) {
        যদি (tok == TOK_ASM_asl || tok == TOK_ASM_lsl || tok == TOK_ASM_lsr || tok == TOK_ASM_asr || tok == TOK_ASM_ror || tok == TOK_ASM_rrx)
            ভঙ্গ;
        parse_operand(s1, &ops[nb_ops]);
        ++nb_ops;
        যদি (tok != ',')
            ভঙ্গ;
        next(); // skip ','
    }
    যদি (tok == ',')
        next();
    operands |= asm_parse_optional_shift(s1, &nb_shift, &shift);
    যদি (nb_ops < 2)
        expect("at least two operands");
    অন্যথা যদি (nb_ops == 2) {
        memcpy(&ops[2], &ops[1], পরিমাণ(ops[1])); // move ops[2]
        memcpy(&ops[1], &ops[0], পরিমাণ(ops[0])); // ops[1] was implicit
        nb_ops = 3;
    } অন্যথা যদি (nb_ops == 3) {
        যদি (opcode_nos == 0xd || opcode_nos == 0xf || opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) { // mov, mvn, cmp, cmn, tst, teq
            tcc_error("'%s' cannot be used with three operands", get_tok_str(token, রিক্ত));
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
        ৱিকল্প (ops[2].type) {
        পক্ষ OP_REG32:
            operands |= ops[2].reg;
            ভঙ্গ;
        পক্ষ OP_IM8:
        পক্ষ OP_IM32:
            operands |= ENCODE_IMMEDIATE_FLAG;
            immediate_মান = ops[2].e.v;
            বাবে (half_immediate_rotation = 0; half_immediate_rotation < 16; ++half_immediate_rotation) {
                যদি (immediate_মান >= 0x00 && immediate_মান < 0x100)
                    ভঙ্গ;
                // rotate left by two
                immediate_মান = ((immediate_মান & 0x3FFFFFFF) << 2) | ((immediate_মান & 0xC0000000) >> 30);
            }
            যদি (half_immediate_rotation >= 16) {
                /* fallthrough */
            } অন্যথা {
                operands |= immediate_মান;
                operands |= half_immediate_rotation << 8;
                ভঙ্গ;
            }
        পক্ষ OP_IM8N: // immediate negative value
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
            ৱিকল্প (opcode_nos) {
            পক্ষ 0x0: // AND - Rd:= Op1 AND Op2
                opcode = 0xe << 21; // BIC
                immediate_মান = ~immediate_মান;
                ভঙ্গ;
            পক্ষ 0x2: // SUB - Rd:= Op1 - Op2
                opcode = 0x4 << 21; // ADD
                immediate_মান = -immediate_মান;
                ভঙ্গ;
            পক্ষ 0x4: // ADD - Rd:= Op1 + Op2
                opcode = 0x2 << 21; // SUB
                immediate_মান = -immediate_মান;
                ভঙ্গ;
            পক্ষ 0x5: // ADC - Rd:= Op1 + Op2 + C
                opcode = 0x6 << 21; // SBC
                immediate_মান = ~immediate_মান;
                ভঙ্গ;
            পক্ষ 0x6: // SBC - Rd:= Op1 - Op2 + C
                opcode = 0x5 << 21; // ADC
                immediate_মান = ~immediate_মান;
                ভঙ্গ;
            পক্ষ 0xa: // CMP - CC on: Op1 - Op2
                opcode = 0xb << 21; // CMN
                immediate_মান = -immediate_মান;
                ভঙ্গ;
            পক্ষ 0xb: // CMN - CC on: Op1 + Op2
                opcode = 0xa << 21; // CMP
                immediate_মান = -immediate_মান;
                ভঙ্গ;
            পক্ষ 0xd: // MOV - Rd:= Op2
                opcode = 0xf << 21; // MVN
                immediate_মান = ~immediate_মান;
                ভঙ্গ;
            পক্ষ 0xe: // BIC - Rd:= Op1 AND NOT Op2
                opcode = 0x0 << 21; // AND
                immediate_মান = ~immediate_মান;
                ভঙ্গ;
            পক্ষ 0xf: // MVN - Rd:= NOT Op2
                opcode = 0xd << 21; // MOV
                immediate_মান = ~immediate_মান;
                ভঙ্গ;
            স্ৱভাৱ:
                tcc_error("cannot use '%s' with a negative immediate value", get_tok_str(token, রিক্ত));
            }
            বাবে (half_immediate_rotation = 0; half_immediate_rotation < 16; ++half_immediate_rotation) {
                যদি (immediate_মান >= 0x00 && immediate_মান < 0x100)
                    ভঙ্গ;
                // rotate left by two
                immediate_মান = ((immediate_মান & 0x3FFFFFFF) << 2) | ((immediate_মান & 0xC0000000) >> 30);
            }
            যদি (half_immediate_rotation >= 16) {
                immediate_মান = ops[2].e.v;
                tcc_error("immediate value 0x%X cannot be encoded into ARM immediate", (unsigned) immediate_মান);
            }
            operands |= immediate_মান;
            operands |= half_immediate_rotation << 8;
            ভঙ্গ;
        স্ৱভাৱ:
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

স্থির শূন্য asm_shift_opcode(TCCState *s1, পূর্ণাঙ্ক token)
{
    Operand ops[3];
    পূর্ণাঙ্ক nb_ops;
    পূর্ণাঙ্ক definitely_neutral = 0;
    uint32_t opcode = 0xd << 21; // MOV
    uint32_t operands = 0;

    বাবে (nb_ops = 0; nb_ops < পরিমাণ(ops)/পরিমাণ(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        যদি (tok != ',') {
            ++nb_ops;
            ভঙ্গ;
        }
        next(); // skip ','
    }
    যদি (nb_ops < 2) {
        expect("at least two operands");
    }

    যদি (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    } অন্যথা
        operands |= ENCODE_RD(ops[0].reg);

    যদি (nb_ops == 2) {
        ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
        পক্ষ TOK_ASM_rrxseq:
            opcode |= ENCODE_SET_CONDITION_CODES;
            /* fallthrough */
        পক্ষ TOK_ASM_rrxeq:
            যদি (ops[1].type == OP_REG32) {
                operands |= ops[1].reg;
                operands |= ENCODE_BARREL_SHIFTER_MODE_ROR;
                asm_emit_opcode(token, opcode | operands);
            } অন্যথা
                tcc_error("(first source operand) register");
            ঘূৰাই;
        স্ৱভাৱ:
            memcpy(&ops[2], &ops[1], পরিমাণ(ops[1])); // move ops[2]
            memcpy(&ops[1], &ops[0], পরিমাণ(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
    }
    যদি (nb_ops != 3) {
        expect("two or three operands");
    }

    ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
    পক্ষ TOK_ASM_lslseq:
    পক্ষ TOK_ASM_lsrseq:
    পক্ষ TOK_ASM_asrseq:
    পক্ষ TOK_ASM_rorseq:
        opcode |= ENCODE_SET_CONDITION_CODES;
        ভঙ্গ;
    }

    ৱিকল্প (ops[1].type) {
    পক্ষ OP_REG32:
        operands |= ops[1].reg;
        ভঙ্গ;
    পক্ষ OP_IM8:
        operands |= ENCODE_IMMEDIATE_FLAG;
        operands |= ops[1].e.v;
        tcc_error("Using an immediate value as the source operand is not possible with '%s' instruction on ARM", get_tok_str(token, রিক্ত));
    }

    ৱিকল্প (ops[2].type) {
    পক্ষ OP_REG32:
        যদি ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
            (ops[1].type == OP_REG32 && ops[1].reg == 15)) {
            tcc_error("Using the 'pc' register in data processing instructions that have a register-controlled shift is not implemented by ARM");
        }
        operands |= asm_encode_shift(&ops[2]);
        ভঙ্গ;
    পক্ষ OP_IM8:
        যদি (ops[2].e.v)
            operands |= asm_encode_shift(&ops[2]);
        অন্যথা
            definitely_neutral = 1;
        ভঙ্গ;
    }

    যদি (!definitely_neutral) ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
    পক্ষ TOK_ASM_lslseq:
    পক্ষ TOK_ASM_lsleq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_LSL;
        ভঙ্গ;
    পক্ষ TOK_ASM_lsrseq:
    পক্ষ TOK_ASM_lsreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_LSR;
        ভঙ্গ;
    পক্ষ TOK_ASM_asrseq:
    পক্ষ TOK_ASM_asreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_ASR;
        ভঙ্গ;
    পক্ষ TOK_ASM_rorseq:
    পক্ষ TOK_ASM_roreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_ROR;
        ভঙ্গ;
    স্ৱভাৱ:
        expect("shift instruction");
    }
    asm_emit_opcode(token, opcode | operands);
}

স্থির শূন্য asm_multiplication_opcode(TCCState *s1, পূর্ণাঙ্ক token)
{
    Operand ops[4];
    পূর্ণাঙ্ক nb_ops = 0;
    uint32_t opcode = 0x90;

    বাবে (nb_ops = 0; nb_ops < পরিমাণ(ops)/পরিমাণ(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        যদি (tok != ',') {
            ++nb_ops;
            ভঙ্গ;
        }
        next(); // skip ','
    }
    যদি (nb_ops < 2)
        expect("at least two operands");
    অন্যথা যদি (nb_ops == 2) {
        ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
        পক্ষ TOK_ASM_mulseq:
        পক্ষ TOK_ASM_muleq:
            memcpy(&ops[2], &ops[0], পরিমাণ(ops[1])); // ARM is actually like this!
            ভঙ্গ;
        স্ৱভাৱ:
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

    ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
    পক্ষ TOK_ASM_mulseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    পক্ষ TOK_ASM_muleq:
        যদি (nb_ops != 3)
            expect("three operands");
        অন্যথা {
            asm_emit_opcode(token, opcode);
        }
        ভঙ্গ;
    পক্ষ TOK_ASM_mlaseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    পক্ষ TOK_ASM_mlaeq:
    case_TOK_ASM_mlaeq:
        যদি (nb_ops != 4)
            expect("four operands");
        অন্যথা {
            opcode |= 1 << 21; // Accumulate
            asm_emit_opcode(token, opcode);
        }
        ভঙ্গ;
    পক্ষ TOK_ASM_mlseq:
        opcode |= 0x00400000;
        গচ্ছ case_TOK_ASM_mlaeq;
    পক্ষ TOK_ASM_udiveq:
        opcode |= 0x00200000;
    পক্ষ TOK_ASM_sdiveq:
        asm_emit_opcode(token, (opcode & ~0x80) | 0x0710f010);
        ভঙ্গ;
    স্ৱভাৱ:
        expect("known multiplication instruction");
    }
}

স্থির শূন্য asm_long_multiplication_opcode(TCCState *s1, পূর্ণাঙ্ক token)
{
    Operand ops[4];
    পূর্ণাঙ্ক nb_ops = 0;
    uint32_t opcode = 0x90 | (1 << 23);

    বাবে (nb_ops = 0; nb_ops < পরিমাণ(ops)/পরিমাণ(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        যদি (tok != ',') {
            ++nb_ops;
            ভঙ্গ;
        }
        next(); // skip ','
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

    ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
    পক্ষ TOK_ASM_smullseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    পক্ষ TOK_ASM_smulleq:
        opcode |= 1 << 22; // signed
        asm_emit_opcode(token, opcode);
        ভঙ্গ;
    পক্ষ TOK_ASM_umullseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    পক্ষ TOK_ASM_umulleq:
        asm_emit_opcode(token, opcode);
        ভঙ্গ;
    পক্ষ TOK_ASM_smlalseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    পক্ষ TOK_ASM_smlaleq:
        opcode |= 1 << 22; // signed
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        ভঙ্গ;
    পক্ষ TOK_ASM_umlalseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    পক্ষ TOK_ASM_umlaleq:
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        ভঙ্গ;
    স্ৱভাৱ:
        expect("known long multiplication instruction");
    }
}

স্থির শূন্য asm_single_data_transfer_opcode(TCCState *s1, পূর্ণাঙ্ক token)
{
    Operand ops[3];
    Operand strex_operand;
    Operand shift;
    পূর্ণাঙ্ক nb_shift = 0;
    পূর্ণাঙ্ক exclam = 0;
    পূর্ণাঙ্ক closed_bracket = 0;
    পূর্ণাঙ্ক op2_minus = 0;
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
    next(); // skip ','

    ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
    পক্ষ TOK_ASM_strexheq:
    পক্ষ TOK_ASM_strexbeq:
    পক্ষ TOK_ASM_strexeq:
        parse_operand(s1, &strex_operand);
        যদি (strex_operand.type != OP_REG32) {
            expect("register");
        }
        যদি (tok != ',')
            expect("at least three arguments");
        অন্যথা
            next(); // skip ','
        ভঙ্গ;
    }

    skip('[');
    parse_operand(s1, &ops[1]);
    যদি (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    অন্যথা {
        expect("(first source operand) register");
    }
    যদি (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    যদি (tok == ',') {
        next(); // skip ','
        যদি (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
        যদি (ops[2].type == OP_REG32) {
            যদি (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, রিক্ত));
            }
            যদি (tok == ',') {
                next();
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
            next(); // skip '!'
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
        পূর্ণাঙ্ক v = ops[2].e.v;
        যদি (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        যদি (v >= 0) {
            opcode |= 1 << 23; // up
            যদি (v >= 0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, রিক্ত));
            অন্যথা
                opcode |= v;
        } অন্যথা { // down
            যদি (v <= -0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, রিক্ত));
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

    ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
    পক্ষ TOK_ASM_strbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    পক্ষ TOK_ASM_streq:
        opcode |= 1 << 26; // Load/Store
        যদি (nb_shift)
            opcode |= asm_encode_shift(&shift);
        asm_emit_opcode(token, opcode);
        ভঙ্গ;
    পক্ষ TOK_ASM_ldrbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    পক্ষ TOK_ASM_ldreq:
        opcode |= 1 << 20; // L
        opcode |= 1 << 26; // Load/Store
        যদি (nb_shift)
            opcode |= asm_encode_shift(&shift);
        asm_emit_opcode(token, opcode);
        ভঙ্গ;
    পক্ষ TOK_ASM_strexheq:
        opcode |= 1 << 21;
    পক্ষ TOK_ASM_strexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    পক্ষ TOK_ASM_strexeq:
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
        ভঙ্গ;
    পক্ষ TOK_ASM_ldrexheq:
        opcode |= 1 << 21;
    পক্ষ TOK_ASM_ldrexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    পক্ষ TOK_ASM_ldrexeq:
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
        ভঙ্গ;
    স্ৱভাৱ:
        expect("data transfer instruction");
    }
}

// Note: Only call this using a VFP register if you know exactly what you are doing (i.e. cp_number is 10 or 11 and you are doing a vmov)
স্থির শূন্য asm_emit_coprocessor_data_transfer(uint32_t উপৰেৰ_nibble, uint8_t cp_সংখ্যা, uint8_t CRd, ধ্রুৱ Operand* Rn, ধ্রুৱ Operand* offset, পূর্ণাঙ্ক offset_minus, পূর্ণাঙ্ক preincrement, পূর্ণাঙ্ক writeback, পূর্ণাঙ্ক long_transfer, পূর্ণাঙ্ক load) {
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
        পূর্ণাঙ্ক v = offset->e.v;
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

    asm_emit_unconditional_opcode((উপৰেৰ_nibble << 28) | opcode);
}

// Almost exactly the same as asm_single_data_transfer_opcode.
// Difference: Offsets are smaller and multiples of 4; no shifts, no STREX, ENCODE_IMMEDIATE_FLAG is inverted again.
স্থির শূন্য asm_coprocessor_data_transfer_opcode(TCCState *s1, পূর্ণাঙ্ক token)
{
    Operand ops[3];
    uint8_t coprocessor;
    uint8_t coprocessor_destination_register;
    পূর্ণাঙ্ক preincrement = 0;
    পূর্ণাঙ্ক exclam = 0;
    পূর্ণাঙ্ক closed_bracket = 0;
    পূর্ণাঙ্ক op2_minus = 0;
    পূর্ণাঙ্ক long_transfer = 0;
    // Note: ldc p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: ldc p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: ldc p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    যদি (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        next();
    } অন্যথা {
        expect("'c<number>'");
    }

    skip(',');

    যদি (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
        coprocessor_destination_register = tok - TOK_ASM_c0;
        next();
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
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    যদি (tok == ',') {
        next(); // skip ','
        যদি (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
        যদি (ops[2].type == OP_REG32) {
            যদি (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, রিক্ত));
            }
        } অন্যথা যদি (ops[2].type == OP_VREG64) {
            tcc_error("'%s' does not support VFP register operand", get_tok_str(token, রিক্ত));
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
            next(); // skip '!'
        }
    }

    // TODO: Support options.

    যদি (token == TOK_ASM_ldc2 || token == TOK_ASM_stc2 || token == TOK_ASM_ldc2l || token == TOK_ASM_stc2l) {
        ৱিকল্প (token) {
        পক্ষ TOK_ASM_ldc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        পক্ষ TOK_ASM_ldc2:
            asm_emit_coprocessor_data_transfer(0xF, coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
            ভঙ্গ;
        পক্ষ TOK_ASM_stc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        পক্ষ TOK_ASM_stc2:
            asm_emit_coprocessor_data_transfer(0xF, coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
            ভঙ্গ;
        }
    } অন্যথা ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
    পক্ষ TOK_ASM_stcleq:
        long_transfer = 1;
        /* fallthrough */
    পক্ষ TOK_ASM_stceq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
        ভঙ্গ;
    পক্ষ TOK_ASM_ldcleq:
        long_transfer = 1;
        /* fallthrough */
    পক্ষ TOK_ASM_ldceq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
        ভঙ্গ;
    স্ৱভাৱ:
        expect("coprocessor data transfer instruction");
    }
}

#যদি defined(TCC_ARM_VFP)
#define CP_SINGLE_PRECISION_FLOAT 10
#define CP_DOUBLE_PRECISION_FLOAT 11

স্থির শূন্য asm_floating_point_single_data_transfer_opcode(TCCState *s1, পূর্ণাঙ্ক token)
{
    Operand ops[3];
    uint8_t coprocessor = 0;
    uint8_t coprocessor_destination_register = 0;
    পূর্ণাঙ্ক long_transfer = 0;
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
        next();
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
        next(); // skip ','
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

    ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
    পক্ষ TOK_ASM_vldreq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], 0, 1, 0, long_transfer, 1);
        ভঙ্গ;
    পক্ষ TOK_ASM_vstreq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], 0, 1, 0, long_transfer, 0);
        ভঙ্গ;
    স্ৱভাৱ:
        expect("floating point data transfer instruction");
    }
}

স্থির শূন্য asm_floating_point_block_data_transfer_opcode(TCCState *s1, পূর্ণাঙ্ক token)
{
    uint8_t coprocessor = 0;
    পূর্ণাঙ্ক first_regset_register;
    পূর্ণাঙ্ক last_regset_register;
    uint8_t regset_item_গুনতি;
    uint8_t extra_register_bit = 0;
    পূর্ণাঙ্ক op0_exclam = 0;
    পূর্ণাঙ্ক load = 0;
    পূর্ণাঙ্ক preincrement = 0;
    Operand ops[1];
    Operand offset;
    ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
    পক্ষ TOK_ASM_vpusheq:
    পক্ষ TOK_ASM_vpopeq:
        ops[0].type = OP_REG32;
        ops[0].reg = 13; // sp
        op0_exclam = 1;
        ভঙ্গ;
    স্ৱভাৱ:
        parse_operand(s1, &ops[0]);
        যদি (tok == '!') {
            op0_exclam = 1;
            next(); // skip '!'
        }
        skip(',');
    }

    skip('{');
    first_regset_register = asm_parse_vfp_regvar(tok, 1);
    যদি ((first_regset_register = asm_parse_vfp_regvar(tok, 1)) != -1) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        next();
    } অন্যথা যদি ((first_regset_register = asm_parse_vfp_regvar(tok, 0)) != -1) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        next();
    } অন্যথা {
        expect("floating-point register");
    }

    যদি (tok == '-') {
        next();
        যদি ((last_regset_register = asm_parse_vfp_regvar(tok, coprocessor == CP_DOUBLE_PRECISION_FLOAT)) != -1)
            next();
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
    ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
    পক্ষ TOK_ASM_vstmeq: // post-increment store
    পক্ষ TOK_ASM_vstmiaeq: // post-increment store
        ভঙ্গ;
    পক্ষ TOK_ASM_vpopeq:
    পক্ষ TOK_ASM_vldmeq: // post-increment load
    পক্ষ TOK_ASM_vldmiaeq: // post-increment load
        load = 1;
        ভঙ্গ;
    পক্ষ TOK_ASM_vldmdbeq: // pre-decrement load
        load = 1;
        /* fallthrough */
    পক্ষ TOK_ASM_vpusheq:
    পক্ষ TOK_ASM_vstmdbeq: // pre-decrement store
        offset.type = OP_IM8N;
        offset.e.v = -offset.e.v;
        preincrement = 1;
        ভঙ্গ;
    স্ৱভাৱ:
        expect("floating point block data transfer instruction");
    }
    যদি (ops[0].type != OP_REG32)
        expect("(first operand) register");
    অন্যথা যদি (ops[0].reg == 15)
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, রিক্ত));
    অন্যথা যদি (!op0_exclam && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vldmeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vldmiaeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vstmeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vstmiaeq)
        tcc_error("first operand of '%s' should have an exclamation mark", get_tok_str(token, রিক্ত));
    অন্যথা
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, first_regset_register, &ops[0], &offset, 0, preincrement, op0_exclam, extra_register_bit, load);
}

#define VMOV_FRACTIONAL_DIGITS 7
#define VMOV_ONE 10000000 /* pow(10, VMOV_FRACTIONAL_DIGITS) */

স্থির uint32_t vmov_parse_fractional_part(ধ্রুৱ ৱর্ণ* s)
{
    uint32_t result = 0;
    পূর্ণাঙ্ক i;
    বাবে (i = 0; i < VMOV_FRACTIONAL_DIGITS; ++i) {
        ৱর্ণ c = *s;
        result *= 10;
        যদি (c >= '0' && c <= '9') {
            result += (c - '0');
            ++s;
        }
    }
    যদি (*s)
        expect("decimal numeral");
    ঘূৰাই result;
}

স্থির পূর্ণাঙ্ক vmov_linear_approx_index(uint32_t beginning, uint32_t end, uint32_t মান)
{
    পূর্ণাঙ্ক i;
    uint32_t k;
    uint32_t xvalue;

    k = (end - beginning)/16;
    বাবে (xvalue = beginning, i = 0; i < 16; ++i, xvalue += k) {
        যদি (মান == xvalue)
            ঘূৰাই i;
    }
    //assert(0);
    ঘূৰাই -1;
}

স্থির uint32_t vmov_parse_immediate_মান() {
    uint32_t মান;
    unsigned long integral_মান;
    ধ্রুৱ ৱর্ণ *p;

    যদি (tok != TOK_PPNUM) {
        expect("immediate value");
    }
    p = tokc.str.data;
    errno = 0;
    integral_মান = strtoul(p, (ৱর্ণ **)&p, 0);

    যদি (errno || integral_মান >= 32) {
        tcc_error("invalid floating-point immediate value");
    }

    মান = (uint32_t) integral_মান * VMOV_ONE;
    যদি (*p == '.') {
        ++p;
        মান += vmov_parse_fractional_part(p);
    }
    next();
    ঘূৰাই মান;
}

স্থির uint8_t vmov_encode_immediate_মান(uint32_t মান)
{
    uint32_t limit;
    uint32_t end = 0;
    uint32_t beginning = 0;
    পূর্ণাঙ্ক r = -1;
    পূর্ণাঙ্ক n;
    পূর্ণাঙ্ক i;

    limit = 32 * VMOV_ONE;
    বাবে (i = 0; i < 8; ++i) {
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
    n = vmov_linear_approx_index(beginning, end, মান);
    ঘূৰাই n | (((3 - r) & 0x7) << 4);
}

// Not standalone.
স্থির শূন্য asm_floating_point_immediate_data_processing_opcode_tail(TCCState *s1, পূর্ণাঙ্ক token, uint8_t coprocessor, uint8_t CRd) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    uint8_t operands[3] = {0, 0, 0};
    uint32_t immediate_মান = 0;
    পূর্ণাঙ্ক op_minus = 0;
    uint8_t code;

    operands[0] = CRd;

    যদি (tok == '#' || tok == '$') {
        next();
    }
    যদি (tok == '-') {
        op_minus = 1;
        next();
    }
    immediate_মান = vmov_parse_immediate_মান();

    opcode1 = 11; // "Other" instruction
    ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
    পক্ষ TOK_ASM_vcmpeq_f32:
    পক্ষ TOK_ASM_vcmpeq_f64:
        opcode2 = 2;
        operands[1] = 5;
        যদি (immediate_মান) {
            expect("Immediate value 0");
        }
        ভঙ্গ;
    পক্ষ TOK_ASM_vcmpeeq_f32:
    পক্ষ TOK_ASM_vcmpeeq_f64:
        opcode2 = 6;
        operands[1] = 5;
        যদি (immediate_মান) {
            expect("Immediate value 0");
        }
        ভঙ্গ;
    পক্ষ TOK_ASM_vmoveq_f32:
    পক্ষ TOK_ASM_vmoveq_f64:
        opcode2 = 0;
        যদি (op_minus)
            operands[1] = 0x8;
        অন্যথা
            operands[1] = 0x0;
        code = vmov_encode_immediate_মান(immediate_মান);
        operands[1] |= code >> 4;
        operands[2] = code & 0xF;
        ভঙ্গ;
    স্ৱভাৱ:
        expect("known floating point with immediate instruction");
    }

    যদি (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        যদি (operands[0] & 1)
            opcode1 |= 4;
        operands[0] >>= 1;
    }

    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, operands[0], operands[1], operands[2], opcode2, 0);
}

স্থির শূন্য asm_floating_point_reg_arm_reg_transfer_opcode_tail(TCCState *s1, পূর্ণাঙ্ক token, পূর্ণাঙ্ক coprocessor, পূর্ণাঙ্ক nb_arm_regs, পূর্ণাঙ্ক nb_ops, Operand ops[3]) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    ৱিকল্প (coprocessor) {
    পক্ষ CP_SINGLE_PRECISION_FLOAT:
        // "vmov.f32 r2, s3" or "vmov.f32 s3, r2"
        যদি (nb_ops != 2 || nb_arm_regs != 1) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and one ARM register operands");
        }
        যদি (ops[0].type != OP_REG32) { // determine mode: load or store
            // need to swap operands 0 and 1
            memcpy(&ops[2], &ops[1], পরিমাণ(ops[2]));
            memcpy(&ops[1], &ops[0], পরিমাণ(ops[1]));
            memcpy(&ops[0], &ops[2], পরিমাণ(ops[0]));
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
        ভঙ্গ;
    পক্ষ CP_DOUBLE_PRECISION_FLOAT:
        যদি (nb_ops != 3 || nb_arm_regs != 2) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and two ARM register operands");
        }
        // Determine whether it's a store into a VFP register (vmov "d1, r2, r3") rather than "vmov r2, r3, d1"
        যদি (ops[0].type == OP_VREG64) {
            যদি (ops[2].type == OP_REG32) {
                Operand temp;
                // need to rotate operand list to the left
                memcpy(&temp, &ops[0], পরিমাণ(temp));
                memcpy(&ops[0], &ops[1], পরিমাণ(ops[0]));
                memcpy(&ops[1], &ops[2], পরিমাণ(ops[1]));
                memcpy(&ops[2], &temp, পরিমাণ(ops[2]));
            } অন্যথা {
                tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
            }
        } অন্যথা যদি (ops[0].type != OP_REG32 || ops[1].type != OP_REG32 || ops[2].type != OP_VREG64) {
            tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
        } অন্যথা {
            opcode1 |= 1;
        }
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, ops[0].reg, &ops[1], &ops[2], 0, 0, 0, 1, opcode1);
        ভঙ্গ;
    স্ৱভাৱ:
        tcc_internal_error("unknown coprocessor");
    }
}

স্থির শূন্য asm_floating_point_vcvt_data_processing_opcode(TCCState *s1, পূর্ণাঙ্ক token) {
    uint8_t coprocessor = 0;
    Operand ops[3];
    uint8_t opcode1 = 11;
    uint8_t opcode2 = 2;

    ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
    পক্ষ TOK_ASM_vcvtreq_s32_f64:
    পক্ষ TOK_ASM_vcvtreq_u32_f64:
    পক্ষ TOK_ASM_vcvteq_s32_f64:
    পক্ষ TOK_ASM_vcvteq_u32_f64:
    পক্ষ TOK_ASM_vcvteq_f64_s32:
    পক্ষ TOK_ASM_vcvteq_f64_u32:
    পক্ষ TOK_ASM_vcvteq_f32_f64:
       coprocessor = CP_DOUBLE_PRECISION_FLOAT;
       ভঙ্গ;
    পক্ষ TOK_ASM_vcvtreq_s32_f32:
    পক্ষ TOK_ASM_vcvtreq_u32_f32:
    পক্ষ TOK_ASM_vcvteq_s32_f32:
    পক্ষ TOK_ASM_vcvteq_u32_f32:
    পক্ষ TOK_ASM_vcvteq_f32_s32:
    পক্ষ TOK_ASM_vcvteq_f32_u32:
    পক্ষ TOK_ASM_vcvteq_f64_f32:
       coprocessor = CP_SINGLE_PRECISION_FLOAT;
       ভঙ্গ;
    স্ৱভাৱ:
       tcc_error("Unknown coprocessor for instruction '%s'", get_tok_str(token, রিক্ত));
    }

    parse_operand(s1, &ops[0]);
    ops[1].type = OP_IM8;
    ops[1].e.v = 8;
    /* floating-point -> integer */
    ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
    পক্ষ TOK_ASM_vcvtreq_s32_f32:
    পক্ষ TOK_ASM_vcvtreq_s32_f64:
    পক্ষ TOK_ASM_vcvteq_s32_f32:
    পক্ষ TOK_ASM_vcvteq_s32_f64:
        ops[1].e.v |= 1; // signed
        /* fall through */
    পক্ষ TOK_ASM_vcvteq_u32_f32:
    পক্ষ TOK_ASM_vcvteq_u32_f64:
    পক্ষ TOK_ASM_vcvtreq_u32_f32:
    পক্ষ TOK_ASM_vcvtreq_u32_f64:
        ops[1].e.v |= 4; // to_integer (opc2)
        ভঙ্গ;
    /* floating-point size conversion */
    পক্ষ TOK_ASM_vcvteq_f64_f32:
    পক্ষ TOK_ASM_vcvteq_f32_f64:
        ops[1].e.v = 7;
        ভঙ্গ;
    }

    skip(',');
    parse_operand(s1, &ops[2]);

    ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
    /* floating-point -> integer */
    পক্ষ TOK_ASM_vcvteq_s32_f32:
    পক্ষ TOK_ASM_vcvteq_s32_f64:
    পক্ষ TOK_ASM_vcvteq_u32_f32:
    পক্ষ TOK_ASM_vcvteq_u32_f64:
        opcode2 |= 4; // round_zero
        ভঙ্গ;

    /* integer -> floating-point */
    পক্ষ TOK_ASM_vcvteq_f64_s32:
    পক্ষ TOK_ASM_vcvteq_f32_s32:
        opcode2 |= 4; // signed--special
        ভঙ্গ;

    /* floating-point size conversion */
    পক্ষ TOK_ASM_vcvteq_f64_f32:
    পক্ষ TOK_ASM_vcvteq_f32_f64:
        opcode2 |= 4; // always set
        ভঙ্গ;
    }

    ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
    পক্ষ TOK_ASM_vcvteq_f64_u32:
    পক্ষ TOK_ASM_vcvteq_f64_s32:
    পক্ষ TOK_ASM_vcvteq_f64_f32:
        যদি (ops[0].type == OP_VREG64 && ops[2].type == OP_VREG32) {
        } অন্যথা {
            expect("d<number>, s<number>");
        }
        ভঙ্গ;
    স্ৱভাৱ:
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

স্থির শূন্য asm_floating_point_data_processing_opcode(TCCState *s1, পূর্ণাঙ্ক token) {
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0; // (0 || 2) | register selection
    Operand ops[3];
    uint8_t nb_ops = 0;
    পূর্ণাঙ্ক vmov = 0;
    পূর্ণাঙ্ক nb_arm_regs = 0;

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

    ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
    পক্ষ TOK_ASM_vmlaeq_f64:
    পক্ষ TOK_ASM_vmlseq_f64:
    পক্ষ TOK_ASM_vnmlseq_f64:
    পক্ষ TOK_ASM_vnmlaeq_f64:
    পক্ষ TOK_ASM_vmuleq_f64:
    পক্ষ TOK_ASM_vnmuleq_f64:
    পক্ষ TOK_ASM_vaddeq_f64:
    পক্ষ TOK_ASM_vsubeq_f64:
    পক্ষ TOK_ASM_vdiveq_f64:
    পক্ষ TOK_ASM_vnegeq_f64:
    পক্ষ TOK_ASM_vabseq_f64:
    পক্ষ TOK_ASM_vsqrteq_f64:
    পক্ষ TOK_ASM_vcmpeq_f64:
    পক্ষ TOK_ASM_vcmpeeq_f64:
    পক্ষ TOK_ASM_vmoveq_f64:
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
    }

    ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
    পক্ষ TOK_ASM_vmoveq_f32:
    পক্ষ TOK_ASM_vmoveq_f64:
        vmov = 1;
        ভঙ্গ;
    }

    বাবে (nb_ops = 0; nb_ops < 3; ) {
        // Note: Necessary because parse_operand can't parse decimal numerals.
        যদি (nb_ops == 1 && (tok == '#' || tok == '$' || tok == TOK_PPNUM || tok == '-')) {
            asm_floating_point_immediate_data_processing_opcode_tail(s1, token, coprocessor, ops[0].reg);
            ঘূৰাই;
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
            next();
        অন্যথা
            ভঙ্গ;
    }

    যদি (nb_arm_regs == 0) {
        যদি (nb_ops == 2) { // implicit
            memcpy(&ops[2], &ops[1], পরিমাণ(ops[1])); // move ops[2]
            memcpy(&ops[1], &ops[0], পরিমাণ(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
        যদি (nb_ops < 3) {
            tcc_error("Not enough operands for '%s' (%u)", get_tok_str(token, রিক্ত), nb_ops);
        }
    }

    ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
    পক্ষ TOK_ASM_vmlaeq_f32:
    পক্ষ TOK_ASM_vmlaeq_f64:
        opcode1 = 0;
        opcode2 = 0;
        ভঙ্গ;
    পক্ষ TOK_ASM_vmlseq_f32:
    পক্ষ TOK_ASM_vmlseq_f64:
        opcode1 = 0;
        opcode2 = 2;
        ভঙ্গ;
    পক্ষ TOK_ASM_vnmlseq_f32:
    পক্ষ TOK_ASM_vnmlseq_f64:
        opcode1 = 1;
        opcode2 = 0;
        ভঙ্গ;
    পক্ষ TOK_ASM_vnmlaeq_f32:
    পক্ষ TOK_ASM_vnmlaeq_f64:
        opcode1 = 1;
        opcode2 = 2;
        ভঙ্গ;
    পক্ষ TOK_ASM_vmuleq_f32:
    পক্ষ TOK_ASM_vmuleq_f64:
        opcode1 = 2;
        opcode2 = 0;
        ভঙ্গ;
    পক্ষ TOK_ASM_vnmuleq_f32:
    পক্ষ TOK_ASM_vnmuleq_f64:
        opcode1 = 2;
        opcode2 = 2;
        ভঙ্গ;
    পক্ষ TOK_ASM_vaddeq_f32:
    পক্ষ TOK_ASM_vaddeq_f64:
        opcode1 = 3;
        opcode2 = 0;
        ভঙ্গ;
    পক্ষ TOK_ASM_vsubeq_f32:
    পক্ষ TOK_ASM_vsubeq_f64:
        opcode1 = 3;
        opcode2 = 2;
        ভঙ্গ;
    পক্ষ TOK_ASM_vdiveq_f32:
    পক্ষ TOK_ASM_vdiveq_f64:
        opcode1 = 8;
        opcode2 = 0;
        ভঙ্গ;
    পক্ষ TOK_ASM_vnegeq_f32:
    পক্ষ TOK_ASM_vnegeq_f64:
        opcode1 = 11; // Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        ভঙ্গ;
    পক্ষ TOK_ASM_vabseq_f32:
    পক্ষ TOK_ASM_vabseq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 0;
        ভঙ্গ;
    পক্ষ TOK_ASM_vsqrteq_f32:
    পক্ষ TOK_ASM_vsqrteq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        ভঙ্গ;
    পক্ষ TOK_ASM_vcmpeq_f32:
    পক্ষ TOK_ASM_vcmpeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        ভঙ্গ;
    পক্ষ TOK_ASM_vcmpeeq_f32:
    পক্ষ TOK_ASM_vcmpeeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        ভঙ্গ;
    পক্ষ TOK_ASM_vmoveq_f32:
    পক্ষ TOK_ASM_vmoveq_f64:
        যদি (nb_arm_regs > 0) { // vmov.f32 r2, s3 or similar
            asm_floating_point_reg_arm_reg_transfer_opcode_tail(s1, token, coprocessor, nb_arm_regs, nb_ops, ops);
            ঘূৰাই;
        } অন্যথা {
            opcode1 = 11; // "Other" instruction
            opcode2 = 2;
            ops[1].type = OP_IM8;
            ops[1].e.v = 0;
        }
        ভঙ্গ;
    স্ৱভাৱ:
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

স্থির পূর্ণাঙ্ক asm_parse_vfp_status_regvar(পূর্ণাঙ্ক t)
{
    ৱিকল্প (t) {
    পক্ষ TOK_ASM_fpsid:
        ঘূৰাই 0;
    পক্ষ TOK_ASM_fpscr:
        ঘূৰাই 1;
    পক্ষ TOK_ASM_fpexc:
        ঘূৰাই 8;
    স্ৱভাৱ:
        ঘূৰাই -1;
    }
}

স্থির শূন্য asm_floating_point_status_register_opcode(TCCState* s1, পূর্ণাঙ্ক token)
{
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode;
    পূর্ণাঙ্ক vfp_sys_reg = -1;
    Operand arm_operand;
    ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
    পক্ষ TOK_ASM_vmrseq:
        opcode = 0xf;
        যদি (tok == TOK_ASM_apsr_nzcv) {
            arm_operand.type = OP_REG32;
            arm_operand.reg = 15; // not PC
            next(); // skip apsr_nzcv
        } অন্যথা {
            parse_operand(s1, &arm_operand);
            যদি (arm_operand.type == OP_REG32 && arm_operand.reg == 15) {
                tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, রিক্ত));
            }
        }

        skip(',');
        vfp_sys_reg = asm_parse_vfp_status_regvar(tok);
        next(); // skip vfp sys reg
        যদি (arm_operand.type == OP_REG32 && arm_operand.reg == 15 && vfp_sys_reg != 1) {
            tcc_error("'%s' only supports the variant 'vmrs apsr_nzcv, fpscr' here", get_tok_str(token, রিক্ত));
        }
        ভঙ্গ;
    পক্ষ TOK_ASM_vmsreq:
        opcode = 0xe;
        vfp_sys_reg = asm_parse_vfp_status_regvar(tok);
        next(); // skip vfp sys reg
        skip(',');
        parse_operand(s1, &arm_operand);
        যদি (arm_operand.type == OP_REG32 && arm_operand.reg == 15) {
            tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, রিক্ত));
        }
        ভঙ্গ;
    স্ৱভাৱ:
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

স্থির শূন্য asm_misc_single_data_transfer_opcode(TCCState *s1, পূর্ণাঙ্ক token)
{
    Operand ops[3];
    পূর্ণাঙ্ক exclam = 0;
    পূর্ণাঙ্ক closed_bracket = 0;
    পূর্ণাঙ্ক op2_minus = 0;
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
        next(); // skip ','
    skip('[');
    parse_operand(s1, &ops[1]);
    যদি (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    অন্যথা {
        expect("(first source operand) register");
    }
    যদি (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    যদি (tok == ',') {
        next(); // skip ','
        যদি (tok == '-') {
            op2_minus = 1;
            next();
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
            next(); // skip '!'
        }
    }

    যদি (exclam) {
        যদি ((opcode & (1 << 24)) == 0) {
            tcc_error("result of '%s' would be unpredictable here", get_tok_str(token, রিক্ত));
        }
        opcode |= 1 << 21; // write offset back into register
    }

    যদি (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        পূর্ণাঙ্ক v = ops[2].e.v;
        যদি (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        যদি (v >= 0) {
            opcode |= 1 << 23; // up
            যদি (v >= 0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, রিক্ত));
            অন্যথা {
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        } অন্যথা { // down
            যদি (v <= -0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, রিক্ত));
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

    ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
    পক্ষ TOK_ASM_ldrsheq:
        opcode |= 1 << 5; // halfword, not byte
        /* fallthrough */
    পক্ষ TOK_ASM_ldrsbeq:
        opcode |= 1 << 6; // sign extend
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        ভঙ্গ;
    পক্ষ TOK_ASM_ldrheq:
        opcode |= 1 << 5; // halfword, not byte
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        ভঙ্গ;
    পক্ষ TOK_ASM_strheq:
        opcode |= 1 << 5; // halfword, not byte
        asm_emit_opcode(token, opcode);
        ভঙ্গ;
    }
}

/* Note: almost dupe of encbranch in arm-gen.c */
স্থির uint32_t encbranchoffset(পূর্ণাঙ্ক pos, পূর্ণাঙ্ক addr, পূর্ণাঙ্ক fail)
{
  addr-=pos+8;
  addr/=4;
  যদি(addr>=0x7fffff || addr<-0x800000) {
    যদি(fail)
      tcc_error("branch offset is too far");
    ঘূৰাই 0;
  }
  ঘূৰাই /*not 0x0A000000|*/(addr&0xffffff);
}

স্থির শূন্য asm_branch_opcode(TCCState *s1, পূর্ণাঙ্ক token)
{
    পূর্ণাঙ্ক jmp_disp = 0;
    Operand op;
    ৰাশিমালা_মান e;
    ElfSym *esym;

    ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
    পক্ষ TOK_ASM_beq:
    পক্ষ TOK_ASM_bleq:
        asm_ৰাশিমালা(s1, &e);
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
        ভঙ্গ;
    স্ৱভাৱ:
        parse_operand(s1, &op);
        ভঙ্গ;
    }
    ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
    পক্ষ TOK_ASM_beq:
        asm_emit_opcode(token, (0xa << 24) | (jmp_disp & 0xffffff));
        ভঙ্গ;
    পক্ষ TOK_ASM_bleq:
        asm_emit_opcode(token, (0xb << 24) | (jmp_disp & 0xffffff));
        ভঙ্গ;
    পক্ষ TOK_ASM_bxeq:
        যদি (op.type != OP_REG32)
            expect("register");
        অন্যথা
            asm_emit_opcode(token, (0x12fff1 << 4) | op.reg);
        ভঙ্গ;
    পক্ষ TOK_ASM_blxeq:
        যদি (op.type != OP_REG32)
            expect("register");
        অন্যথা
            asm_emit_opcode(token, (0x12fff3 << 4) | op.reg);
        ভঙ্গ;
    স্ৱভাৱ:
        expect("branch instruction");
    }
}

ST_FUNC শূন্য asm_opcode(TCCState *s1, পূর্ণাঙ্ক token)
{
    যেতিয়ালৈ (token == TOK_LINEFEED) {
        next();
        token = tok;
    }
    যদি (token == TOK_EOF)
        ঘূৰাই;
    যদি (token < TOK_ASM_nopeq) { // no condition code
        ৱিকল্প (token) {
        পক্ষ TOK_ASM_cdp2:
            asm_coprocessor_opcode(s1, token);
            ঘূৰাই;
        পক্ষ TOK_ASM_ldc2:
        পক্ষ TOK_ASM_ldc2l:
        পক্ষ TOK_ASM_stc2:
        পক্ষ TOK_ASM_stc2l:
            asm_coprocessor_data_transfer_opcode(s1, token);
            ঘূৰাই;
        স্ৱভাৱ:
            expect("instruction");
        }
    }

    ৱিকল্প (ARM_INSTRUCTION_GROUP(token)) {
    পক্ষ TOK_ASM_pusheq:
    পক্ষ TOK_ASM_popeq:
    পক্ষ TOK_ASM_stmdaeq:
    পক্ষ TOK_ASM_ldmdaeq:
    পক্ষ TOK_ASM_stmeq:
    পক্ষ TOK_ASM_ldmeq:
    পক্ষ TOK_ASM_stmiaeq:
    পক্ষ TOK_ASM_ldmiaeq:
    পক্ষ TOK_ASM_stmdbeq:
    পক্ষ TOK_ASM_ldmdbeq:
    পক্ষ TOK_ASM_stmibeq:
    পক্ষ TOK_ASM_ldmibeq:
        asm_block_data_transfer_opcode(s1, token);
        ঘূৰাই;
    পক্ষ TOK_ASM_nopeq:
    পক্ষ TOK_ASM_wfeeq:
    পক্ষ TOK_ASM_wfieq:
        asm_nullary_opcode(token);
        ঘূৰাই;
    পক্ষ TOK_ASM_swieq:
    পক্ষ TOK_ASM_svceq:
        asm_unary_opcode(s1, token);
        ঘূৰাই;
    পক্ষ TOK_ASM_beq:
    পক্ষ TOK_ASM_bleq:
    পক্ষ TOK_ASM_bxeq:
    পক্ষ TOK_ASM_blxeq:
        asm_branch_opcode(s1, token);
        ঘূৰাই;
    পক্ষ TOK_ASM_clzeq:
    পক্ষ TOK_ASM_sxtbeq:
    পক্ষ TOK_ASM_sxtheq:
    পক্ষ TOK_ASM_uxtbeq:
    পক্ষ TOK_ASM_uxtheq:
    পক্ষ TOK_ASM_movteq:
    পক্ষ TOK_ASM_movweq:
        asm_দ্বিমিক_opcode(s1, token);
        ঘূৰাই;

    পক্ষ TOK_ASM_ldreq:
    পক্ষ TOK_ASM_ldrbeq:
    পক্ষ TOK_ASM_streq:
    পক্ষ TOK_ASM_strbeq:
    পক্ষ TOK_ASM_ldrexeq:
    পক্ষ TOK_ASM_ldrexbeq:
    পক্ষ TOK_ASM_ldrexheq:
    পক্ষ TOK_ASM_strexeq:
    পক্ষ TOK_ASM_strexbeq:
    পক্ষ TOK_ASM_strexheq:
        asm_single_data_transfer_opcode(s1, token);
        ঘূৰাই;

    পক্ষ TOK_ASM_ldrheq:
    পক্ষ TOK_ASM_ldrsheq:
    পক্ষ TOK_ASM_ldrsbeq:
    পক্ষ TOK_ASM_strheq:
       asm_misc_single_data_transfer_opcode(s1, token);
       ঘূৰাই;

    পক্ষ TOK_ASM_andeq:
    পক্ষ TOK_ASM_eoreq:
    পক্ষ TOK_ASM_subeq:
    পক্ষ TOK_ASM_rsbeq:
    পক্ষ TOK_ASM_addeq:
    পক্ষ TOK_ASM_adceq:
    পক্ষ TOK_ASM_sbceq:
    পক্ষ TOK_ASM_rsceq:
    পক্ষ TOK_ASM_tsteq:
    পক্ষ TOK_ASM_teqeq:
    পক্ষ TOK_ASM_cmpeq:
    পক্ষ TOK_ASM_cmneq:
    পক্ষ TOK_ASM_orreq:
    পক্ষ TOK_ASM_moveq:
    পক্ষ TOK_ASM_biceq:
    পক্ষ TOK_ASM_mvneq:
    পক্ষ TOK_ASM_andseq:
    পক্ষ TOK_ASM_eorseq:
    পক্ষ TOK_ASM_subseq:
    পক্ষ TOK_ASM_rsbseq:
    পক্ষ TOK_ASM_addseq:
    পক্ষ TOK_ASM_adcseq:
    পক্ষ TOK_ASM_sbcseq:
    পক্ষ TOK_ASM_rscseq:
//  case TOK_ASM_tstseq:
//  case TOK_ASM_teqseq:
//  case TOK_ASM_cmpseq:
//  case TOK_ASM_cmnseq:
    পক্ষ TOK_ASM_orrseq:
    পক্ষ TOK_ASM_movseq:
    পক্ষ TOK_ASM_bicseq:
    পক্ষ TOK_ASM_mvnseq:
        asm_data_processing_opcode(s1, token);
        ঘূৰাই;

    পক্ষ TOK_ASM_lsleq:
    পক্ষ TOK_ASM_lslseq:
    পক্ষ TOK_ASM_lsreq:
    পক্ষ TOK_ASM_lsrseq:
    পক্ষ TOK_ASM_asreq:
    পক্ষ TOK_ASM_asrseq:
    পক্ষ TOK_ASM_roreq:
    পক্ষ TOK_ASM_rorseq:
    পক্ষ TOK_ASM_rrxseq:
    পক্ষ TOK_ASM_rrxeq:
        asm_shift_opcode(s1, token);
        ঘূৰাই;

    পক্ষ TOK_ASM_muleq:
    পক্ষ TOK_ASM_mulseq:
    পক্ষ TOK_ASM_mlaeq:
    পক্ষ TOK_ASM_mlaseq:
    পক্ষ TOK_ASM_mlseq:
    পক্ষ TOK_ASM_udiveq:
    পক্ষ TOK_ASM_sdiveq:
        asm_multiplication_opcode(s1, token);
        ঘূৰাই;

    পক্ষ TOK_ASM_smulleq:
    পক্ষ TOK_ASM_smullseq:
    পক্ষ TOK_ASM_umulleq:
    পক্ষ TOK_ASM_umullseq:
    পক্ষ TOK_ASM_smlaleq:
    পক্ষ TOK_ASM_smlalseq:
    পক্ষ TOK_ASM_umlaleq:
    পক্ষ TOK_ASM_umlalseq:
        asm_long_multiplication_opcode(s1, token);
        ঘূৰাই;

    পক্ষ TOK_ASM_cdpeq:
    পক্ষ TOK_ASM_mcreq:
    পক্ষ TOK_ASM_mrceq:
        asm_coprocessor_opcode(s1, token);
        ঘূৰাই;

    পক্ষ TOK_ASM_ldceq:
    পক্ষ TOK_ASM_ldcleq:
    পক্ষ TOK_ASM_stceq:
    পক্ষ TOK_ASM_stcleq:
        asm_coprocessor_data_transfer_opcode(s1, token);
        ঘূৰাই;

#যদি defined(TCC_ARM_VFP)
    পক্ষ TOK_ASM_vldreq:
    পক্ষ TOK_ASM_vstreq:
        asm_floating_point_single_data_transfer_opcode(s1, token);
        ঘূৰাই;

    পক্ষ TOK_ASM_vmlaeq_f32:
    পক্ষ TOK_ASM_vmlseq_f32:
    পক্ষ TOK_ASM_vnmlseq_f32:
    পক্ষ TOK_ASM_vnmlaeq_f32:
    পক্ষ TOK_ASM_vmuleq_f32:
    পক্ষ TOK_ASM_vnmuleq_f32:
    পক্ষ TOK_ASM_vaddeq_f32:
    পক্ষ TOK_ASM_vsubeq_f32:
    পক্ষ TOK_ASM_vdiveq_f32:
    পক্ষ TOK_ASM_vnegeq_f32:
    পক্ষ TOK_ASM_vabseq_f32:
    পক্ষ TOK_ASM_vsqrteq_f32:
    পক্ষ TOK_ASM_vcmpeq_f32:
    পক্ষ TOK_ASM_vcmpeeq_f32:
    পক্ষ TOK_ASM_vmoveq_f32:
    পক্ষ TOK_ASM_vmlaeq_f64:
    পক্ষ TOK_ASM_vmlseq_f64:
    পক্ষ TOK_ASM_vnmlseq_f64:
    পক্ষ TOK_ASM_vnmlaeq_f64:
    পক্ষ TOK_ASM_vmuleq_f64:
    পক্ষ TOK_ASM_vnmuleq_f64:
    পক্ষ TOK_ASM_vaddeq_f64:
    পক্ষ TOK_ASM_vsubeq_f64:
    পক্ষ TOK_ASM_vdiveq_f64:
    পক্ষ TOK_ASM_vnegeq_f64:
    পক্ষ TOK_ASM_vabseq_f64:
    পক্ষ TOK_ASM_vsqrteq_f64:
    পক্ষ TOK_ASM_vcmpeq_f64:
    পক্ষ TOK_ASM_vcmpeeq_f64:
    পক্ষ TOK_ASM_vmoveq_f64:
        asm_floating_point_data_processing_opcode(s1, token);
        ঘূৰাই;

    পক্ষ TOK_ASM_vcvtreq_s32_f32:
    পক্ষ TOK_ASM_vcvtreq_s32_f64:
    পক্ষ TOK_ASM_vcvteq_s32_f32:
    পক্ষ TOK_ASM_vcvteq_s32_f64:
    পক্ষ TOK_ASM_vcvtreq_u32_f32:
    পক্ষ TOK_ASM_vcvtreq_u32_f64:
    পক্ষ TOK_ASM_vcvteq_u32_f32:
    পক্ষ TOK_ASM_vcvteq_u32_f64:
    পক্ষ TOK_ASM_vcvteq_f64_s32:
    পক্ষ TOK_ASM_vcvteq_f32_s32:
    পক্ষ TOK_ASM_vcvteq_f64_u32:
    পক্ষ TOK_ASM_vcvteq_f32_u32:
    পক্ষ TOK_ASM_vcvteq_f64_f32:
    পক্ষ TOK_ASM_vcvteq_f32_f64:
        asm_floating_point_vcvt_data_processing_opcode(s1, token);
        ঘূৰাই;

    পক্ষ TOK_ASM_vpusheq:
    পক্ষ TOK_ASM_vpopeq:
    পক্ষ TOK_ASM_vldmeq:
    পক্ষ TOK_ASM_vldmiaeq:
    পক্ষ TOK_ASM_vldmdbeq:
    পক্ষ TOK_ASM_vstmeq:
    পক্ষ TOK_ASM_vstmiaeq:
    পক্ষ TOK_ASM_vstmdbeq:
        asm_floating_point_block_data_transfer_opcode(s1, token);
        ঘূৰাই;

    পক্ষ TOK_ASM_vmsreq:
    পক্ষ TOK_ASM_vmrseq:
        asm_floating_point_status_register_opcode(s1, token);
        ঘূৰাই;
#endif

    স্ৱভাৱ:
        expect("known instruction");
    }
}

ST_FUNC শূন্য subst_asm_operand(CString *add_str, SValue *sv, পূর্ণাঙ্ক modifier)
{
    পূর্ণাঙ্ক r, reg, size, val;

    r = sv->r;
    যদি ((r & VT_VALMASK) == VT_CONST) {
        যদি (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(add_str, '#');
        যদি (r & VT_SYM) {
            ধ্রুৱ ৱর্ণ *name = get_tok_str(sv->sym->v, রিক্ত);
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
                গচ্ছ no_offset;
            cstr_ccat(add_str, '+');
        }
        val = sv->c.i;
        যদি (modifier == 'n')
            val = -val;
        cstr_printf(add_str, "%d", val);
      no_offset:;
    } অন্যথা যদি ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "[fp,#%d]", (পূর্ণাঙ্ক) sv->c.i);
    } অন্যথা যদি (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        যদি (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "[%s]",
                 get_tok_str(TOK_ASM_r0 + reg, রিক্ত));
    } অন্যথা {
        /* register case */
        reg = r & VT_VALMASK;
        যদি (reg >= VT_CONST)
            tcc_internal_error("");

        /* choose register operand size */
        যদি ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            size = 1;
        অন্যথা যদি ((sv->type.t & VT_BTYPE) == VT_SHORT)
            size = 2;
        অন্যথা
            size = 4;

        যদি (modifier == 'b') {
            size = 1;
        } অন্যথা যদি (modifier == 'w') {
            size = 2;
        } অন্যথা যদি (modifier == 'k') {
            size = 4;
        }

        ৱিকল্প (size) {
        স্ৱভাৱ:
            reg = TOK_ASM_r0 + reg;
            ভঙ্গ;
        }
        cstr_printf(add_str, "%s", get_tok_str(reg, রিক্ত));
    }
}

/* generate prolog and epilog code for asm statement */
ST_FUNC শূন্য asm_gen_code(ASMOperand *operands, পূর্ণাঙ্ক nb_operands,
                          পূর্ণাঙ্ক nb_outputs, পূর্ণাঙ্ক is_output,
                          uint8_t *clobber_regs,
                          পূর্ণাঙ্ক out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    পূর্ণাঙ্ক i, reg;
    uint32_t saved_regset = 0;

    // TODO: Check non-E ABI.
    // Note: Technically, r13 (sp) is also callee-saved--but that does not matter yet
    স্থির ধ্রুৱ uint8_t reg_saved[] = { 4, 5, 6, 7, 8, 9 /* Note: sometimes special reg "sb" */ , 10, 11 };

    /* mark all used registers */
    memcpy(regs_allocated, clobber_regs, পরিমাণ(regs_allocated));
    বাবে(i = 0; i < nb_operands;i++) {
        op = &operands[i];
        যদি (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }
    বাবে(i = 0; i < পরিমাণ(reg_saved)/পরিমাণ(reg_saved[0]); i++) {
        reg = reg_saved[i];
        যদি (regs_allocated[reg])
            saved_regset |= 1 << reg;
    }

    যদি (!is_output) { // prolog
        /* generate reg save code */
        যদি (saved_regset)
            gen_le32(0xe92d0000 | saved_regset); // push {...}

        /* generate load code */
        বাবে(i = 0; i < nb_operands; i++) {
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
        বাবে(i = 0 ; i < nb_outputs; i++) {
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
স্থির অন্তঃস্থ পূর্ণাঙ্ক constraint_priority(ধ্রুৱ ৱর্ণ *str)
{
    পূর্ণাঙ্ক priority, c, pr;

    /* we take the lowest priority */
    priority = 0;
    বাবে(;;) {
        c = *str;
        যদি (c == '\0')
            ভঙ্গ;
        str++;
        ৱিকল্প(c) {
        পক্ষ 'l': // in ARM mode, that's  an alias for 'r' [ARM].
        পক্ষ 'r': // register [general]
        পক্ষ 'p': // valid memory address for load,store [general]
            pr = 3;
            ভঙ্গ;
        পক্ষ 'M': // integer constant for shifts [ARM]
        পক্ষ 'I': // integer valid for data processing instruction immediate
        পক্ষ 'J': // integer in range -4095...4095

        পক্ষ 'i': // immediate integer operand, including symbolic constants [general]
        পক্ষ 'm': // memory operand [general]
        পক্ষ 'g': // general-purpose-register, memory, immediate integer [general]
            pr = 4;
            ভঙ্গ;
        স্ৱভাৱ:
            tcc_error("unknown constraint '%c'", c);
        }
        যদি (pr > priority)
            priority = pr;
    }
    ঘূৰাই priority;
}

স্থির ধ্রুৱ ৱর্ণ *skip_constraint_modifiers(ধ্রুৱ ৱর্ণ *p)
{
    /* Constraint modifier:
        =   Operand is written to by this instruction
        +   Operand is both read and written to by this instruction
        %   Instruction is commutative for this operand and the following operand.

       Per-alternative constraint modifier:
        &   Operand is clobbered before the instruction is done using the input operands
    */
    যেতিয়ালৈ (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    ঘূৰাই p;
}

#define REG_OUT_MASK 0x01
#define REG_IN_MASK  0x02

#define is_reg_allocated(reg) (regs_allocated[reg] & reg_mask)

ST_FUNC শূন্য asm_compute_constraints(ASMOperand *operands,
                                    পূর্ণাঙ্ক nb_operands, পূর্ণাঙ্ক nb_outputs,
                                    ধ্রুৱ uint8_t *clobber_regs,
                                    পূর্ণাঙ্ক *pout_reg)
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
    পূর্ণাঙ্ক sorted_op[MAX_ASM_OPERANDS];
    পূর্ণাঙ্ক i, j, k, p1, p2, tmp, reg, c, reg_mask;
    ধ্রুৱ ৱর্ণ *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    বাবে (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->প্ৰবেশ_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    বাবে (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        যদি (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = find_constraint(operands, nb_operands, str, রিক্ত);
            যদি ((unsigned) k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                          i, str);
            op->ref_index = k;
            যদি (operands[k].প্ৰবেশ_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].প্ৰবেশ_index = i;
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
    বাবে (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    বাবে (i = 0; i < nb_operands - 1; i++) {
        বাবে (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            যদি (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    বাবে (i = 0; i < NB_ASM_REGS; i++) {
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
    বাবে (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        যদি (op->ref_index >= 0)
            অনুৱর্ত;
        /* select if register is used for output, input or both */
        যদি (op->প্ৰবেশ_index >= 0) {
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
      try_next:
        c = *str++;
        ৱিকল্প (c) {
        পক্ষ '=': // Operand is written-to
            গচ্ছ try_next;
        পক্ষ '+': // Operand is both READ and written-to
            op->is_rw = 1;
            /* FALL THRU */
        পক্ষ '&': // Operand is clobbered before the instruction is done using the input operands
            যদি (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs",
                          c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            গচ্ছ try_next;
        পক্ষ 'l': // In non-thumb mode, alias for 'r'--otherwise r0-r7 [ARM]
        পক্ষ 'r': // general-purpose register
        পক্ষ 'p': // loadable/storable address
            /* any general register */
            যদি ((reg = op->reg) >= 0)
                গচ্ছ reg_found;
            অন্যথা বাবে (reg = 0; reg <= 8; reg++) {
                যদি (!is_reg_allocated(reg))
                    গচ্ছ reg_found;
            }
            গচ্ছ try_next;
          reg_found:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_mask;
            ভঙ্গ;
        পক্ষ 'I': // integer that is valid as an data processing instruction immediate (0...255, rotated by a multiple of two)
        পক্ষ 'J': // integer in the range -4095 to 4095 [ARM]
        পক্ষ 'K': // integer that satisfies constraint I when inverted (one's complement)
        পক্ষ 'L': // integer that satisfies constraint I when inverted (two's complement)
        পক্ষ 'i': // immediate integer operand, including symbolic constants
            যদি (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                গচ্ছ try_next;
            ভঙ্গ;
        পক্ষ 'M': // integer in the range 0 to 32
            যদি (!
                ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) ==
                 VT_CONST))
                গচ্ছ try_next;
            ভঙ্গ;
        পক্ষ 'm': // memory operand
        পক্ষ 'g':
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
                    বাবে (reg = 0; reg <= 8; reg++) {
                        যদি (!(regs_allocated[reg] & REG_IN_MASK))
                            গচ্ছ reg_found1;
                    }
                    গচ্ছ try_next;
                  reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_IN_MASK;
                    op->reg = reg;
                    op->is_memory = 1;
                }
            }
            ভঙ্গ;
        স্ৱভাৱ:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                      j, op->constraint);
            ভঙ্গ;
        }
        /* if a reference is present for that operand, we assign it too */
        যদি (op->প্ৰবেশ_index >= 0) {
            operands[op->প্ৰবেশ_index].reg = op->reg;
            operands[op->প্ৰবেশ_index].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    বাবে (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        যদি (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL && !op->is_memory) {
            বাবে (reg = 0; reg <= 8; reg++) {
                যদি (!(regs_allocated[reg] & REG_OUT_MASK))
                    গচ্ছ reg_found2;
            }
            tcc_error("could not find free output register for reloading");
          reg_found2:
            *pout_reg = reg;
            ভঙ্গ;
        }
    }

    /* print sorted constraints */
#ifdef ASM_DEBUG
    বাবে (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        printf("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, রিক্ত) : "",
               op->constraint, op->vt->r, op->reg);
    }
    যদি (*pout_reg >= 0)
        printf("out_reg=%d\n", *pout_reg);
#endif
}

ST_FUNC শূন্য asm_clobber(uint8_t *clobber_regs, ধ্রুৱ ৱর্ণ *str)
{
    পূর্ণাঙ্ক reg;
    TokenSym *ts;

    যদি (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        ঘূৰাই;
    ts = tok_alloc(str, strlen(str));
    reg = asm_parse_regvar(ts->tok);
    যদি (reg == -1) {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}

/* If T refers to a register then return the register number and type.
   Otherwise return -1.  */
ST_FUNC পূর্ণাঙ্ক asm_parse_regvar (পূর্ণাঙ্ক t)
{
    /* coprocessors (p0-p15) and coprocessor registers (c0-c15) are handled elsewere */
    /* single fp (s0-s31) and double fp registers (d0-d15) are handled elsewere */

    যদি (t < TOK_ASM_r0 || t > TOK_ASM_pc) /* filter unrelated registers */
        ঘূৰাই -1;

    যদি (t <= TOK_ASM_r15)       /* default register names r0-r15 */
        ঘূৰাই t - TOK_ASM_r0;

    যদি (t <= TOK_ASM_v8)        /* synonym register names a1-a4,v1-v8 (alias: r0-r11) */
        ঘূৰাই t - TOK_ASM_a1;

    /* special register names sb/sl/fp/ip/sp/lr/pc (alias: r9-r15) */
    ঘূৰাই t - TOK_ASM_sb + (TOK_ASM_r9 - TOK_ASM_r0);
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */

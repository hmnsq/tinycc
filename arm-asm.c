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

ST_FUNC शून्य g(पूर्णाङ्क c);
ST_FUNC शून्य gen_le16(पूर्णाङ्क c);
ST_FUNC शून्य gen_le32(पूर्णाङ्क c);

/*************************************************************/
#अन्यथा
/*************************************************************/

#define USING_GLOBALS
#अन्तर्भाव "tcc.h"

गणना {
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

प्रकारनिर्देश संरचना Operand {
    uint32_t type;
    सङ्घ {
        uint8_t reg;
        uint16_t regset;
        अभिव्यक्ती_मूल्य e;
    };
} Operand;

/* Read the VFP register referred to by token T.
   If OK, returns its number.
   If not OK, returns -1. */
स्थिर पूर्णाङ्क asm_parse_vfp_regvar(पूर्णाङ्क t, पूर्णाङ्क double_precision)
{
    यदि (double_precision) {
        यदि (t >= TOK_ASM_d0 && t <= TOK_ASM_d15)
            प्रत्यागम t - TOK_ASM_d0;
    } अन्यथा {
        यदि (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
            प्रत्यागम t - TOK_ASM_s0;
    }
    प्रत्यागम -1;
}

/* Parse a text containing operand and store the result in OP */
स्थिर शून्य parse_operand(TCCState *s1, Operand *op)
{
    अभिव्यक्ती_मूल्य e;
    int8_t reg;
    uint16_t regset = 0;

    op->type = 0;

    यदि (tok == '{') { // regset literal
        next(); // skip '{'
        यावत् (tok != '}' && tok != TOK_EOF) {
            reg = asm_parse_regvar(tok);
            यदि (reg == -1) {
                expect("register");
            } अन्यथा
                next(); // skip register name

            यदि ((1 << reg) < regset)
                tcc_warning("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
            regset |= 1 << reg;
            यदि (tok != ',')
                भङ्ग;
            next(); // skip ','
        }
        skip('}');
        यदि (regset == 0) {
            // ARM instructions don't support empty regset.
            tcc_error("empty register list is not supported");
        } अन्यथा {
            op->type = OP_REGSET32;
            op->regset = regset;
        }
        प्रत्यागम;
    } अन्यथा यदि ((reg = asm_parse_regvar(tok)) != -1) {
        next(); // skip register name
        op->type = OP_REG32;
        op->reg = (uint8_t) reg;
        प्रत्यागम;
    } अन्यथा यदि ((reg = asm_parse_vfp_regvar(tok, 0)) != -1) {
        next(); // skip register name
        op->type = OP_VREG32;
        op->reg = (uint8_t) reg;
        प्रत्यागम;
    } अन्यथा यदि ((reg = asm_parse_vfp_regvar(tok, 1)) != -1) {
        next(); // skip register name
        op->type = OP_VREG64;
        op->reg = (uint8_t) reg;
        प्रत्यागम;
    } अन्यथा यदि (tok == '#' || tok == '$') {
        /* constant value */
        next(); // skip '#' or '$'
    }
    asm_अभिव्यक्ती(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    यदि (!op->e.sym) {
        यदि ((पूर्णाङ्क) op->e.v < 0 && (पूर्णाङ्क) op->e.v >= -255)
            op->type = OP_IM8N;
        अन्यथा यदि (op->e.v == (uint8_t)op->e.v)
            op->type = OP_IM8;
    } अन्यथा
        expect("operand");
}

/* XXX: make it faster ? */
ST_FUNC शून्य g(पूर्णाङ्क c)
{
    पूर्णाङ्क ind1;
    यदि (nocode_wanted)
        प्रत्यागम;
    ind1 = ind + 1;
    यदि (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC शून्य gen_le16 (पूर्णाङ्क i)
{
    g(i);
    g(i>>8);
}

ST_FUNC शून्य gen_le32 (पूर्णाङ्क i)
{
    पूर्णाङ्क ind1;
    यदि (nocode_wanted)
        प्रत्यागम;
    ind1 = ind + 4;
    यदि (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind++] = i & 0xFF;
    cur_text_section->data[ind++] = (i >> 8) & 0xFF;
    cur_text_section->data[ind++] = (i >> 16) & 0xFF;
    cur_text_section->data[ind++] = (i >> 24) & 0xFF;
}

ST_FUNC शून्य gen_expr32(अभिव्यक्ती_मूल्य *pe)
{
    gen_le32(pe->v);
}

स्थिर uint32_t condition_code_of_token(पूर्णाङ्क token) {
    यदि (token < TOK_ASM_nopeq) {
        expect("condition-enabled instruction");
    } अन्यथा
        प्रत्यागम (token - TOK_ASM_nopeq) & 15;
}

स्थिर शून्य asm_emit_opcode(पूर्णाङ्क token, uint32_t opcode) {
    gen_le32((condition_code_of_token(token) << 28) | opcode);
}

स्थिर शून्य asm_emit_unconditional_opcode(uint32_t opcode) {
    gen_le32(opcode);
}

स्थिर शून्य asm_emit_coprocessor_opcode(uint32_t वरचा_nibble, uint8_t cp_संख्या, uint8_t cp_opcode, uint8_t cp_destination_register, uint8_t cp_n_operand_register, uint8_t cp_m_operand_register, uint8_t cp_opcode2, पूर्णाङ्क inter_processor_transfer)
{
    uint32_t opcode = 0xe000000;
    यदि (inter_processor_transfer)
        opcode |= 1 << 4;
    //assert(cp_opcode < 16);
    opcode |= cp_opcode << 20;
    //assert(cp_n_operand_register < 16);
    opcode |= cp_n_operand_register << 16;
    //assert(cp_destination_register < 16);
    opcode |= cp_destination_register << 12;
    //assert(cp_number < 16);
    opcode |= cp_संख्या << 8;
    //assert(cp_information < 8);
    opcode |= cp_opcode2 << 5;
    //assert(cp_m_operand_register < 16);
    opcode |= cp_m_operand_register;
    asm_emit_unconditional_opcode((वरचा_nibble << 28) | opcode);
}

स्थिर शून्य asm_nullary_opcode(पूर्णाङ्क token)
{
    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_nopeq:
        asm_emit_opcode(token, 0xd << 21); // mov r0, r0
        भङ्ग;
    पक्ष TOK_ASM_wfeeq:
        asm_emit_opcode(token, 0x320f002);
    पक्ष TOK_ASM_wfieq:
        asm_emit_opcode(token, 0x320f003);
        भङ्ग;
    स्वभाव:
        expect("nullary instruction");
    }
}

स्थिर शून्य asm_unary_opcode(TCCState *s1, पूर्णाङ्क token)
{
    Operand op;
    parse_operand(s1, &op);

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_swieq:
    पक्ष TOK_ASM_svceq:
        यदि (op.type != OP_IM8)
            expect("immediate 8-bit unsigned integer");
        अन्यथा {
            /* Note: Dummy operand (ignored by processor): ARM ref documented 0...255, ARM instruction set documented 24 bit */
            asm_emit_opcode(token, (0xf << 24) | op.e.v);
        }
        भङ्ग;
    स्वभाव:
        expect("unary instruction");
    }
}

स्थिर शून्य asm_द्विमान_opcode(TCCState *s1, पूर्णाङ्क token)
{
    Operand ops[2];
    Operand rotation;
    uint32_t encoded_rotation = 0;
    uint64_t amount;
    parse_operand(s1, &ops[0]);
    skip(',');
    parse_operand(s1, &ops[1]);
    यदि (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    }

    यदि (ops[0].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, रिक्त));
    }

    यदि (ops[0].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, रिक्त));

    यदि (ops[1].type != OP_REG32) {
        विकल्प (ARM_INSTRUCTION_GROUP(token)) {
        पक्ष TOK_ASM_movteq:
        पक्ष TOK_ASM_movweq:
            यदि (ops[1].type == OP_IM8 || ops[1].type == OP_IM8N || ops[1].type == OP_IM32) {
                यदि (ops[1].e.v >= 0 && ops[1].e.v <= 0xFFFF) {
                    uint16_t immediate_मूल्य = ops[1].e.v;
                    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
                    पक्ष TOK_ASM_movteq:
                        asm_emit_opcode(token, 0x3400000 | (ops[0].reg << 12) | (immediate_मूल्य & 0xF000) << 4 | (immediate_मूल्य & 0xFFF));
                        भङ्ग;
                    पक्ष TOK_ASM_movweq:
                        asm_emit_opcode(token, 0x3000000 | (ops[0].reg << 12) | (immediate_मूल्य & 0xF000) << 4 | (immediate_मूल्य & 0xFFF));
                        भङ्ग;
                    }
                } अन्यथा
                    expect("(source operand) immediate 16 bit value");
            } अन्यथा
                expect("(source operand) immediate");
            भङ्ग;
        स्वभाव:
            expect("(source operand) register");
        }
        प्रत्यागम;
    }

    यदि (ops[1].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, रिक्त));
    }

    यदि (ops[1].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, रिक्त));

    यदि (tok == ',') {
        next(); // skip ','
        यदि (tok == TOK_ASM_ror) {
            next(); // skip 'ror'
            parse_operand(s1, &rotation);
            यदि (rotation.type != OP_IM8) {
                expect("immediate value for rotation");
            } अन्यथा {
                amount = rotation.e.v;
                विकल्प (amount) {
                पक्ष 8:
                    encoded_rotation = 1 << 10;
                    भङ्ग;
                पक्ष 16:
                    encoded_rotation = 2 << 10;
                    भङ्ग;
                पक्ष 24:
                    encoded_rotation = 3 << 10;
                    भङ्ग;
                स्वभाव:
                    expect("'8' or '16' or '24'");
                }
            }
        }
    }
    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_clzeq:
        यदि (encoded_rotation)
            tcc_error("clz does not support rotation");
        asm_emit_opcode(token, 0x16f0f10 | (ops[0].reg << 12) | ops[1].reg);
        भङ्ग;
    पक्ष TOK_ASM_sxtbeq:
        asm_emit_opcode(token, 0x6af0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        भङ्ग;
    पक्ष TOK_ASM_sxtheq:
        asm_emit_opcode(token, 0x6bf0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        भङ्ग;
    पक्ष TOK_ASM_uxtbeq:
        asm_emit_opcode(token, 0x6ef0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        भङ्ग;
    पक्ष TOK_ASM_uxtheq:
        asm_emit_opcode(token, 0x6ff0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        भङ्ग;
    स्वभाव:
        expect("binary instruction");
    }
}

स्थिर शून्य asm_coprocessor_opcode(TCCState *s1, पूर्णाङ्क token) {
    uint8_t coprocessor;
    Operand opcode1;
    Operand opcode2;
    uint8_t registers[3];
    unsigned पूर्णाङ्क i;
    uint8_t वरचा_nibble;
    uint8_t mrc = 0;

    यदि (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        next();
    } अन्यथा {
        expect("'p<number>'");
    }
    skip(',');
    parse_operand(s1, &opcode1);
    यदि (opcode1.type != OP_IM8 || opcode1.e.v > 15) {
        tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, रिक्त));
    }

    प्रति (i = 0; i < 3; ++i) {
        skip(',');
        यदि (i == 0 && token != TOK_ASM_cdp2 && (ARM_INSTRUCTION_GROUP(token) == TOK_ASM_mrceq || ARM_INSTRUCTION_GROUP(token) == TOK_ASM_mcreq)) {
            यदि (tok >= TOK_ASM_r0 && tok <= TOK_ASM_pc) {
                registers[i] = asm_parse_regvar(tok);
                next();
            } अन्यथा {
                expect("'r<number>'");
            }
        } अन्यथा {
            यदि (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
                registers[i] = tok - TOK_ASM_c0;
                next();
            } अन्यथा {
                expect("'c<number>'");
            }
        }
    }
    यदि (tok == ',') {
        next();
        parse_operand(s1, &opcode2);
    } अन्यथा {
        opcode2.type = OP_IM8;
        opcode2.e.v = 0;
    }
    यदि (opcode2.type != OP_IM8 || opcode2.e.v > 15) {
        tcc_error("opcode2 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, रिक्त));
    }

    यदि (token == TOK_ASM_cdp2) {
        वरचा_nibble = 0xF;
        asm_emit_coprocessor_opcode(वरचा_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        प्रत्यागम;
    } अन्यथा
        वरचा_nibble = condition_code_of_token(token);

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_cdpeq:
        asm_emit_coprocessor_opcode(वरचा_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        भङ्ग;
    पक्ष TOK_ASM_mrceq:
        // opcode1 encoding changes! highest and lowest bit gone.
        mrc = 1;
        /* fallthrough */
    पक्ष TOK_ASM_mcreq:
        // opcode1 encoding changes! highest and lowest bit gone.
        यदि (opcode1.e.v > 7) {
            tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 7", get_tok_str(token, रिक्त));
        }
        asm_emit_coprocessor_opcode(वरचा_nibble, coprocessor, (opcode1.e.v << 1) | mrc, registers[0], registers[1], registers[2], opcode2.e.v, 1);
        भङ्ग;
    स्वभाव:
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
#define ENCODE_BARREL_SHIFTER_IMMEDIATE(मूल्य) ((मूल्य) << 7)

स्थिर शून्य asm_block_data_transfer_opcode(TCCState *s1, पूर्णाङ्क token)
{
    uint32_t opcode;
    पूर्णाङ्क op0_exclam = 0;
    Operand ops[2];
    पूर्णाङ्क nb_ops = 1;
    parse_operand(s1, &ops[0]);
    यदि (tok == '!') {
        op0_exclam = 1;
        next(); // skip '!'
    }
    यदि (tok == ',') {
        next(); // skip comma
        parse_operand(s1, &ops[1]);
        ++nb_ops;
    }
    यदि (nb_ops < 1) {
        expect("at least one operand");
    } अन्यथा यदि (ops[nb_ops - 1].type != OP_REGSET32) {
        expect("(last operand) register list");
    }

    // block data transfer: 1 0 0 P U S W L << 20 (general case):
    // operands:
    //   Rn: bits 19...16 base register
    //   Register List: bits 15...0

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_pusheq: // TODO: Optimize 1-register case to: str ?, [sp, #-4]!
        // Instruction: 1 I=0 P=1 U=0 S=0 W=1 L=0 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        यदि (nb_ops != 1)
            expect("exactly one operand");
        अन्यथा
            asm_emit_opcode(token, (0x92d << 16) | ops[0].regset); // TODO: base register ?
        भङ्ग;
    पक्ष TOK_ASM_popeq: // TODO: Optimize 1-register case to: ldr ?, [sp], #4
        // Instruction: 1 I=0 P=0 U=1 S=0 W=0 L=1 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        यदि (nb_ops != 1)
            expect("exactly one operand");
        अन्यथा
            asm_emit_opcode(token, (0x8bd << 16) | ops[0].regset); // TODO: base register ?
        भङ्ग;
    पक्ष TOK_ASM_stmdaeq:
    पक्ष TOK_ASM_ldmdaeq:
    पक्ष TOK_ASM_stmeq:
    पक्ष TOK_ASM_ldmeq:
    पक्ष TOK_ASM_stmiaeq:
    पक्ष TOK_ASM_ldmiaeq:
    पक्ष TOK_ASM_stmdbeq:
    पक्ष TOK_ASM_ldmdbeq:
    पक्ष TOK_ASM_stmibeq:
    पक्ष TOK_ASM_ldmibeq:
        विकल्प (ARM_INSTRUCTION_GROUP(token)) {
        पक्ष TOK_ASM_stmdaeq: // post-decrement store
            opcode = 0x80 << 20;
            भङ्ग;
        पक्ष TOK_ASM_ldmdaeq: // post-decrement load
            opcode = 0x81 << 20;
            भङ्ग;
        पक्ष TOK_ASM_stmeq: // post-increment store
        पक्ष TOK_ASM_stmiaeq: // post-increment store
            opcode = 0x88 << 20;
            भङ्ग;
        पक्ष TOK_ASM_ldmeq: // post-increment load
        पक्ष TOK_ASM_ldmiaeq: // post-increment load
            opcode = 0x89 << 20;
            भङ्ग;
        पक्ष TOK_ASM_stmdbeq: // pre-decrement store
            opcode = 0x90 << 20;
            भङ्ग;
        पक्ष TOK_ASM_ldmdbeq: // pre-decrement load
            opcode = 0x91 << 20;
            भङ्ग;
        पक्ष TOK_ASM_stmibeq: // pre-increment store
            opcode = 0x98 << 20;
            भङ्ग;
        पक्ष TOK_ASM_ldmibeq: // pre-increment load
            opcode = 0x99 << 20;
            भङ्ग;
        स्वभाव:
            tcc_error("internal error: This place should not be reached (fallback in asm_block_data_transfer_opcode)");
        }
        // operands:
        //    Rn: first operand
        //    Register List: lower bits
        यदि (nb_ops != 2)
            expect("exactly two operands");
        अन्यथा यदि (ops[0].type != OP_REG32)
            expect("(first operand) register");
        अन्यथा {
            यदि (op0_exclam)
                opcode |= 1 << 21; // writeback
            asm_emit_opcode(token, opcode | ENCODE_RN(ops[0].reg) | ops[1].regset);
        }
        भङ्ग;
    स्वभाव:
        expect("block data transfer instruction");
    }
}

/* Parses shift directive and returns the parts that would have to be set in the opcode because of it.
   Does not encode the actual shift amount.
   It's not an error if there is no shift directive.

   NB_SHIFT: will be set to 1 iff SHIFT is filled.  Note that for rrx, there's no need to fill SHIFT.
   SHIFT: will be filled in with the shift operand to use, if any. */
स्थिर uint32_t asm_parse_optional_shift(TCCState* s1, पूर्णाङ्क* nb_shift, Operand* shift)
{
    uint32_t opcode = 0;
    *nb_shift = 0;
    विकल्प (tok) {
    पक्ष TOK_ASM_asl:
    पक्ष TOK_ASM_lsl:
    पक्ष TOK_ASM_asr:
    पक्ष TOK_ASM_lsr:
    पक्ष TOK_ASM_ror:
        विकल्प (tok) {
        पक्ष TOK_ASM_asl:
            /* fallthrough */
        पक्ष TOK_ASM_lsl:
            opcode = ENCODE_BARREL_SHIFTER_MODE_LSL;
            भङ्ग;
        पक्ष TOK_ASM_asr:
            opcode = ENCODE_BARREL_SHIFTER_MODE_ASR;
            भङ्ग;
        पक्ष TOK_ASM_lsr:
            opcode = ENCODE_BARREL_SHIFTER_MODE_LSR;
            भङ्ग;
        पक्ष TOK_ASM_ror:
            opcode = ENCODE_BARREL_SHIFTER_MODE_ROR;
            भङ्ग;
        }
        next();
        parse_operand(s1, shift);
        *nb_shift = 1;
        भङ्ग;
    पक्ष TOK_ASM_rrx:
        next();
        opcode = ENCODE_BARREL_SHIFTER_MODE_ROR;
        भङ्ग;
    }
    प्रत्यागम opcode;
}

स्थिर uint32_t asm_encode_shift(Operand* shift)
{
    uint64_t amount;
    uint32_t operands = 0;
    विकल्प (shift->type) {
    पक्ष OP_REG32:
        यदि (shift->reg == 15)
            tcc_error("r15 cannot be used as a shift count");
        अन्यथा {
            operands = ENCODE_BARREL_SHIFTER_SHIFT_BY_REGISTER;
            operands |= ENCODE_BARREL_SHIFTER_REGISTER(shift->reg);
        }
        भङ्ग;
    पक्ष OP_IM8:
        amount = shift->e.v;
        यदि (amount > 0 && amount < 32)
            operands = ENCODE_BARREL_SHIFTER_IMMEDIATE(amount);
        अन्यथा
            tcc_error("shift count out of range");
        भङ्ग;
    स्वभाव:
        tcc_error("unknown shift amount");
    }
    प्रत्यागम operands;
}

स्थिर शून्य asm_data_processing_opcode(TCCState *s1, पूर्णाङ्क token)
{
    Operand ops[3];
    पूर्णाङ्क nb_ops;
    Operand shift = {0};
    पूर्णाङ्क nb_shift = 0;
    uint32_t operands = 0;

    /* modulo 16 entries per instruction for the different condition codes */
    uint32_t opcode_idx = (ARM_INSTRUCTION_GROUP(token) - TOK_ASM_andeq) >> 4;
    uint32_t opcode_nos = opcode_idx >> 1; // without "s"; "OpCode" in ARM docs

    प्रति (nb_ops = 0; nb_ops < परिमाण(ops)/परिमाण(ops[0]); ) {
        यदि (tok == TOK_ASM_asl || tok == TOK_ASM_lsl || tok == TOK_ASM_lsr || tok == TOK_ASM_asr || tok == TOK_ASM_ror || tok == TOK_ASM_rrx)
            भङ्ग;
        parse_operand(s1, &ops[nb_ops]);
        ++nb_ops;
        यदि (tok != ',')
            भङ्ग;
        next(); // skip ','
    }
    यदि (tok == ',')
        next();
    operands |= asm_parse_optional_shift(s1, &nb_shift, &shift);
    यदि (nb_ops < 2)
        expect("at least two operands");
    अन्यथा यदि (nb_ops == 2) {
        memcpy(&ops[2], &ops[1], परिमाण(ops[1])); // move ops[2]
        memcpy(&ops[1], &ops[0], परिमाण(ops[0])); // ops[1] was implicit
        nb_ops = 3;
    } अन्यथा यदि (nb_ops == 3) {
        यदि (opcode_nos == 0xd || opcode_nos == 0xf || opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) { // mov, mvn, cmp, cmn, tst, teq
            tcc_error("'%s' cannot be used with three operands", get_tok_str(token, रिक्त));
        }
    }
    यदि (nb_ops != 3) {
        expect("two or three operands");
    } अन्यथा {
        uint32_t opcode = 0;
        uint32_t immediate_मूल्य;
        uint8_t half_immediate_rotation;
        यदि (nb_shift && shift.type == OP_REG32) {
            यदि ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
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
        यदि (ops[0].type != OP_REG32)
            expect("(destination operand) register");
        अन्यथा यदि (opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) // cmp, cmn, tst, teq
            operands |= ENCODE_SET_CONDITION_CODES; // force S set, otherwise it's a completely different instruction.
        अन्यथा
            operands |= ENCODE_RD(ops[0].reg);
        यदि (ops[1].type != OP_REG32)
            expect("(first source operand) register");
        अन्यथा यदि (!(opcode_nos == 0xd || opcode_nos == 0xf)) // not: mov, mvn (those have only one source operand)
            operands |= ENCODE_RN(ops[1].reg);
        विकल्प (ops[2].type) {
        पक्ष OP_REG32:
            operands |= ops[2].reg;
            भङ्ग;
        पक्ष OP_IM8:
        पक्ष OP_IM32:
            operands |= ENCODE_IMMEDIATE_FLAG;
            immediate_मूल्य = ops[2].e.v;
            प्रति (half_immediate_rotation = 0; half_immediate_rotation < 16; ++half_immediate_rotation) {
                यदि (immediate_मूल्य >= 0x00 && immediate_मूल्य < 0x100)
                    भङ्ग;
                // rotate left by two
                immediate_मूल्य = ((immediate_मूल्य & 0x3FFFFFFF) << 2) | ((immediate_मूल्य & 0xC0000000) >> 30);
            }
            यदि (half_immediate_rotation >= 16) {
                /* fallthrough */
            } अन्यथा {
                operands |= immediate_मूल्य;
                operands |= half_immediate_rotation << 8;
                भङ्ग;
            }
        पक्ष OP_IM8N: // immediate negative value
            operands |= ENCODE_IMMEDIATE_FLAG;
            immediate_मूल्य = ops[2].e.v;
            /* Instruction swapping:
               0001 = EOR - Rd:= Op1 EOR Op2     -> difficult
               0011 = RSB - Rd:= Op2 - Op1       -> difficult
               0111 = RSC - Rd:= Op2 - Op1 + C   -> difficult
               1000 = TST - CC on: Op1 AND Op2   -> difficult
               1001 = TEQ - CC on: Op1 EOR Op2   -> difficult
               1100 = ORR - Rd:= Op1 OR Op2      -> difficult
            */
            विकल्प (opcode_nos) {
            पक्ष 0x0: // AND - Rd:= Op1 AND Op2
                opcode = 0xe << 21; // BIC
                immediate_मूल्य = ~immediate_मूल्य;
                भङ्ग;
            पक्ष 0x2: // SUB - Rd:= Op1 - Op2
                opcode = 0x4 << 21; // ADD
                immediate_मूल्य = -immediate_मूल्य;
                भङ्ग;
            पक्ष 0x4: // ADD - Rd:= Op1 + Op2
                opcode = 0x2 << 21; // SUB
                immediate_मूल्य = -immediate_मूल्य;
                भङ्ग;
            पक्ष 0x5: // ADC - Rd:= Op1 + Op2 + C
                opcode = 0x6 << 21; // SBC
                immediate_मूल्य = ~immediate_मूल्य;
                भङ्ग;
            पक्ष 0x6: // SBC - Rd:= Op1 - Op2 + C
                opcode = 0x5 << 21; // ADC
                immediate_मूल्य = ~immediate_मूल्य;
                भङ्ग;
            पक्ष 0xa: // CMP - CC on: Op1 - Op2
                opcode = 0xb << 21; // CMN
                immediate_मूल्य = -immediate_मूल्य;
                भङ्ग;
            पक्ष 0xb: // CMN - CC on: Op1 + Op2
                opcode = 0xa << 21; // CMP
                immediate_मूल्य = -immediate_मूल्य;
                भङ्ग;
            पक्ष 0xd: // MOV - Rd:= Op2
                opcode = 0xf << 21; // MVN
                immediate_मूल्य = ~immediate_मूल्य;
                भङ्ग;
            पक्ष 0xe: // BIC - Rd:= Op1 AND NOT Op2
                opcode = 0x0 << 21; // AND
                immediate_मूल्य = ~immediate_मूल्य;
                भङ्ग;
            पक्ष 0xf: // MVN - Rd:= NOT Op2
                opcode = 0xd << 21; // MOV
                immediate_मूल्य = ~immediate_मूल्य;
                भङ्ग;
            स्वभाव:
                tcc_error("cannot use '%s' with a negative immediate value", get_tok_str(token, रिक्त));
            }
            प्रति (half_immediate_rotation = 0; half_immediate_rotation < 16; ++half_immediate_rotation) {
                यदि (immediate_मूल्य >= 0x00 && immediate_मूल्य < 0x100)
                    भङ्ग;
                // rotate left by two
                immediate_मूल्य = ((immediate_मूल्य & 0x3FFFFFFF) << 2) | ((immediate_मूल्य & 0xC0000000) >> 30);
            }
            यदि (half_immediate_rotation >= 16) {
                immediate_मूल्य = ops[2].e.v;
                tcc_error("immediate value 0x%X cannot be encoded into ARM immediate", (unsigned) immediate_मूल्य);
            }
            operands |= immediate_मूल्य;
            operands |= half_immediate_rotation << 8;
            भङ्ग;
        स्वभाव:
            expect("(second source operand) register or immediate value");
        }

        यदि (nb_shift) {
            यदि (operands & ENCODE_IMMEDIATE_FLAG)
                tcc_error("immediate rotation not implemented");
            अन्यथा
                operands |= asm_encode_shift(&shift);
        }

        /* S=0 and S=1 entries alternate one after another, in that order */
        opcode |= (opcode_idx & 1) ? ENCODE_SET_CONDITION_CODES : 0;
        asm_emit_opcode(token, opcode | operands);
    }
}

स्थिर शून्य asm_shift_opcode(TCCState *s1, पूर्णाङ्क token)
{
    Operand ops[3];
    पूर्णाङ्क nb_ops;
    पूर्णाङ्क definitely_neutral = 0;
    uint32_t opcode = 0xd << 21; // MOV
    uint32_t operands = 0;

    प्रति (nb_ops = 0; nb_ops < परिमाण(ops)/परिमाण(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        यदि (tok != ',') {
            ++nb_ops;
            भङ्ग;
        }
        next(); // skip ','
    }
    यदि (nb_ops < 2) {
        expect("at least two operands");
    }

    यदि (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    } अन्यथा
        operands |= ENCODE_RD(ops[0].reg);

    यदि (nb_ops == 2) {
        विकल्प (ARM_INSTRUCTION_GROUP(token)) {
        पक्ष TOK_ASM_rrxseq:
            opcode |= ENCODE_SET_CONDITION_CODES;
            /* fallthrough */
        पक्ष TOK_ASM_rrxeq:
            यदि (ops[1].type == OP_REG32) {
                operands |= ops[1].reg;
                operands |= ENCODE_BARREL_SHIFTER_MODE_ROR;
                asm_emit_opcode(token, opcode | operands);
            } अन्यथा
                tcc_error("(first source operand) register");
            प्रत्यागम;
        स्वभाव:
            memcpy(&ops[2], &ops[1], परिमाण(ops[1])); // move ops[2]
            memcpy(&ops[1], &ops[0], परिमाण(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
    }
    यदि (nb_ops != 3) {
        expect("two or three operands");
    }

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_lslseq:
    पक्ष TOK_ASM_lsrseq:
    पक्ष TOK_ASM_asrseq:
    पक्ष TOK_ASM_rorseq:
        opcode |= ENCODE_SET_CONDITION_CODES;
        भङ्ग;
    }

    विकल्प (ops[1].type) {
    पक्ष OP_REG32:
        operands |= ops[1].reg;
        भङ्ग;
    पक्ष OP_IM8:
        operands |= ENCODE_IMMEDIATE_FLAG;
        operands |= ops[1].e.v;
        tcc_error("Using an immediate value as the source operand is not possible with '%s' instruction on ARM", get_tok_str(token, रिक्त));
    }

    विकल्प (ops[2].type) {
    पक्ष OP_REG32:
        यदि ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
            (ops[1].type == OP_REG32 && ops[1].reg == 15)) {
            tcc_error("Using the 'pc' register in data processing instructions that have a register-controlled shift is not implemented by ARM");
        }
        operands |= asm_encode_shift(&ops[2]);
        भङ्ग;
    पक्ष OP_IM8:
        यदि (ops[2].e.v)
            operands |= asm_encode_shift(&ops[2]);
        अन्यथा
            definitely_neutral = 1;
        भङ्ग;
    }

    यदि (!definitely_neutral) विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_lslseq:
    पक्ष TOK_ASM_lsleq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_LSL;
        भङ्ग;
    पक्ष TOK_ASM_lsrseq:
    पक्ष TOK_ASM_lsreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_LSR;
        भङ्ग;
    पक्ष TOK_ASM_asrseq:
    पक्ष TOK_ASM_asreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_ASR;
        भङ्ग;
    पक्ष TOK_ASM_rorseq:
    पक्ष TOK_ASM_roreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_ROR;
        भङ्ग;
    स्वभाव:
        expect("shift instruction");
    }
    asm_emit_opcode(token, opcode | operands);
}

स्थिर शून्य asm_multiplication_opcode(TCCState *s1, पूर्णाङ्क token)
{
    Operand ops[4];
    पूर्णाङ्क nb_ops = 0;
    uint32_t opcode = 0x90;

    प्रति (nb_ops = 0; nb_ops < परिमाण(ops)/परिमाण(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        यदि (tok != ',') {
            ++nb_ops;
            भङ्ग;
        }
        next(); // skip ','
    }
    यदि (nb_ops < 2)
        expect("at least two operands");
    अन्यथा यदि (nb_ops == 2) {
        विकल्प (ARM_INSTRUCTION_GROUP(token)) {
        पक्ष TOK_ASM_mulseq:
        पक्ष TOK_ASM_muleq:
            memcpy(&ops[2], &ops[0], परिमाण(ops[1])); // ARM is actually like this!
            भङ्ग;
        स्वभाव:
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

    यदि (ops[0].type == OP_REG32)
        opcode |= ops[0].reg << 16;
    अन्यथा
        expect("(destination operand) register");
    यदि (ops[1].type == OP_REG32)
        opcode |= ops[1].reg;
    अन्यथा
        expect("(first source operand) register");
    यदि (ops[2].type == OP_REG32)
        opcode |= ops[2].reg << 8;
    अन्यथा
        expect("(second source operand) register");
    यदि (nb_ops > 3) {
        यदि (ops[3].type == OP_REG32)
            opcode |= ops[3].reg << 12;
        अन्यथा
            expect("(third source operand) register");
    }

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_mulseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    पक्ष TOK_ASM_muleq:
        यदि (nb_ops != 3)
            expect("three operands");
        अन्यथा {
            asm_emit_opcode(token, opcode);
        }
        भङ्ग;
    पक्ष TOK_ASM_mlaseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    पक्ष TOK_ASM_mlaeq:
    case_TOK_ASM_mlaeq:
        यदि (nb_ops != 4)
            expect("four operands");
        अन्यथा {
            opcode |= 1 << 21; // Accumulate
            asm_emit_opcode(token, opcode);
        }
        भङ्ग;
    पक्ष TOK_ASM_mlseq:
        opcode |= 0x00400000;
        गच्छ case_TOK_ASM_mlaeq;
    पक्ष TOK_ASM_udiveq:
        opcode |= 0x00200000;
    पक्ष TOK_ASM_sdiveq:
        asm_emit_opcode(token, (opcode & ~0x80) | 0x0710f010);
        भङ्ग;
    स्वभाव:
        expect("known multiplication instruction");
    }
}

स्थिर शून्य asm_long_multiplication_opcode(TCCState *s1, पूर्णाङ्क token)
{
    Operand ops[4];
    पूर्णाङ्क nb_ops = 0;
    uint32_t opcode = 0x90 | (1 << 23);

    प्रति (nb_ops = 0; nb_ops < परिमाण(ops)/परिमाण(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        यदि (tok != ',') {
            ++nb_ops;
            भङ्ग;
        }
        next(); // skip ','
    }
    यदि (nb_ops != 4) {
        expect("four operands");
    }

    // long multiply (special case):
    // operands:
    //   RdLo: bits 15...12
    //   RdHi: bits 19...16
    //   Rs: bits 11...8
    //   Rm: bits 3...0

    यदि (ops[0].type == OP_REG32)
        opcode |= ops[0].reg << 12;
    अन्यथा
        expect("(destination lo accumulator) register");
    यदि (ops[1].type == OP_REG32)
        opcode |= ops[1].reg << 16;
    अन्यथा
        expect("(destination hi accumulator) register");
    यदि (ops[2].type == OP_REG32)
        opcode |= ops[2].reg;
    अन्यथा
        expect("(first source operand) register");
    यदि (ops[3].type == OP_REG32)
        opcode |= ops[3].reg << 8;
    अन्यथा
        expect("(second source operand) register");

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_smullseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    पक्ष TOK_ASM_smulleq:
        opcode |= 1 << 22; // signed
        asm_emit_opcode(token, opcode);
        भङ्ग;
    पक्ष TOK_ASM_umullseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    पक्ष TOK_ASM_umulleq:
        asm_emit_opcode(token, opcode);
        भङ्ग;
    पक्ष TOK_ASM_smlalseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    पक्ष TOK_ASM_smlaleq:
        opcode |= 1 << 22; // signed
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        भङ्ग;
    पक्ष TOK_ASM_umlalseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    पक्ष TOK_ASM_umlaleq:
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        भङ्ग;
    स्वभाव:
        expect("known long multiplication instruction");
    }
}

स्थिर शून्य asm_single_data_transfer_opcode(TCCState *s1, पूर्णाङ्क token)
{
    Operand ops[3];
    Operand strex_operand;
    Operand shift;
    पूर्णाङ्क nb_shift = 0;
    पूर्णाङ्क exclam = 0;
    पूर्णाङ्क closed_bracket = 0;
    पूर्णाङ्क op2_minus = 0;
    uint32_t opcode = 0;
    // Note: ldr r0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: ldr r0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: ldr r0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_operand(s1, &ops[0]);
    यदि (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    अन्यथा {
        expect("(destination operand) register");
    }
    यदि (tok != ',')
        expect("at least two arguments");
    next(); // skip ','

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_strexheq:
    पक्ष TOK_ASM_strexbeq:
    पक्ष TOK_ASM_strexeq:
        parse_operand(s1, &strex_operand);
        यदि (strex_operand.type != OP_REG32) {
            expect("register");
        }
        यदि (tok != ',')
            expect("at least three arguments");
        अन्यथा
            next(); // skip ','
        भङ्ग;
    }

    skip('[');
    parse_operand(s1, &ops[1]);
    यदि (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    अन्यथा {
        expect("(first source operand) register");
    }
    यदि (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    यदि (tok == ',') {
        next(); // skip ','
        यदि (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
        यदि (ops[2].type == OP_REG32) {
            यदि (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, रिक्त));
            }
            यदि (tok == ',') {
                next();
                opcode |= asm_parse_optional_shift(s1, &nb_shift, &shift);
                यदि (opcode == 0)
                    expect("shift directive, or no comma");
            }
        }
    } अन्यथा {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        opcode |= 1 << 24; // add offset before transfer
    }
    यदि (!closed_bracket) {
        skip(']');
        opcode |= 1 << 24; // add offset before transfer
        यदि (tok == '!') {
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
    यदि (exclam)
        opcode |= 1 << 21; // write offset back into register

    यदि (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        पूर्णाङ्क v = ops[2].e.v;
        यदि (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        यदि (v >= 0) {
            opcode |= 1 << 23; // up
            यदि (v >= 0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, रिक्त));
            अन्यथा
                opcode |= v;
        } अन्यथा { // down
            यदि (v <= -0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, रिक्त));
            अन्यथा
                opcode |= -v;
        }
    } अन्यथा यदि (ops[2].type == OP_REG32) {
        यदि (!op2_minus)
            opcode |= 1 << 23; // up
        opcode |= ENCODE_IMMEDIATE_FLAG; /* if set, it means it's NOT immediate */
        opcode |= ops[2].reg;
    } अन्यथा
        expect("register");

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_strbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    पक्ष TOK_ASM_streq:
        opcode |= 1 << 26; // Load/Store
        यदि (nb_shift)
            opcode |= asm_encode_shift(&shift);
        asm_emit_opcode(token, opcode);
        भङ्ग;
    पक्ष TOK_ASM_ldrbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    पक्ष TOK_ASM_ldreq:
        opcode |= 1 << 20; // L
        opcode |= 1 << 26; // Load/Store
        यदि (nb_shift)
            opcode |= asm_encode_shift(&shift);
        asm_emit_opcode(token, opcode);
        भङ्ग;
    पक्ष TOK_ASM_strexheq:
        opcode |= 1 << 21;
    पक्ष TOK_ASM_strexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    पक्ष TOK_ASM_strexeq:
        यदि ((opcode & 0xFFF) || nb_shift) {
            tcc_error("neither offset nor shift allowed with 'strex'");
        } अन्यथा यदि (opcode & ENCODE_IMMEDIATE_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'strex'");
        }
        यदि ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'strex'");
        }

        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        opcode |= strex_operand.reg;
        asm_emit_opcode(token, opcode);
        भङ्ग;
    पक्ष TOK_ASM_ldrexheq:
        opcode |= 1 << 21;
    पक्ष TOK_ASM_ldrexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    पक्ष TOK_ASM_ldrexeq:
        यदि ((opcode & 0xFFF) || nb_shift) {
            tcc_error("neither offset nor shift allowed with 'ldrex'");
        } अन्यथा यदि (opcode & ENCODE_IMMEDIATE_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'ldrex'");
        }
        यदि ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'ldrex'");
        }
        opcode |= 1 << 20; // L
        opcode |= 0x00f;
        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        asm_emit_opcode(token, opcode);
        भङ्ग;
    स्वभाव:
        expect("data transfer instruction");
    }
}

// Note: Only call this using a VFP register if you know exactly what you are doing (i.e. cp_number is 10 or 11 and you are doing a vmov)
स्थिर शून्य asm_emit_coprocessor_data_transfer(uint32_t वरचा_nibble, uint8_t cp_संख्या, uint8_t CRd, ध्रुव Operand* Rn, ध्रुव Operand* offset, पूर्णाङ्क offset_minus, पूर्णाङ्क preincrement, पूर्णाङ्क writeback, पूर्णाङ्क long_transfer, पूर्णाङ्क load) {
    uint32_t opcode = 0x0;
    opcode |= 1 << 26; // Load/Store
    opcode |= 1 << 27; // coprocessor

    यदि (long_transfer)
        opcode |= 1 << 22; // long transfer

    यदि (load)
        opcode |= 1 << 20; // L

    opcode |= cp_संख्या << 8;

    //assert(CRd < 16);
    opcode |= ENCODE_RD(CRd);

    यदि (Rn->type != OP_REG32)
        expect("register");

    //assert(Rn->reg < 16);
    opcode |= ENCODE_RN(Rn->reg);
    यदि (preincrement)
        opcode |= 1 << 24; // add offset before transfer

    यदि (writeback)
        opcode |= 1 << 21; // write offset back into register

    यदि (offset->type == OP_IM8 || offset->type == OP_IM8N || offset->type == OP_IM32) {
        पूर्णाङ्क v = offset->e.v;
        यदि (offset_minus)
            tcc_error("minus before '#' not supported for immediate values");
        यदि (offset->type == OP_IM8N || v < 0)
            v = -v;
        अन्यथा
            opcode |= 1 << 23; // up
        यदि (v & 3) {
            tcc_error("immediate offset must be a multiple of 4");
        }
        v >>= 2;
        यदि (v > 255) {
            tcc_error("immediate offset must be between -1020 and 1020");
        }
        opcode |= v;
    } अन्यथा यदि (offset->type == OP_REG32) {
        यदि (!offset_minus)
            opcode |= 1 << 23; // up
        opcode |= ENCODE_IMMEDIATE_FLAG; /* if set, it means it's NOT immediate */
        opcode |= offset->reg;
        tcc_error("Using register offset to register address is not possible here");
    } अन्यथा यदि (offset->type == OP_VREG64) {
        opcode |= 16;
        opcode |= offset->reg;
    } अन्यथा
        expect("immediate or register");

    asm_emit_unconditional_opcode((वरचा_nibble << 28) | opcode);
}

// Almost exactly the same as asm_single_data_transfer_opcode.
// Difference: Offsets are smaller and multiples of 4; no shifts, no STREX, ENCODE_IMMEDIATE_FLAG is inverted again.
स्थिर शून्य asm_coprocessor_data_transfer_opcode(TCCState *s1, पूर्णाङ्क token)
{
    Operand ops[3];
    uint8_t coprocessor;
    uint8_t coprocessor_destination_register;
    पूर्णाङ्क preincrement = 0;
    पूर्णाङ्क exclam = 0;
    पूर्णाङ्क closed_bracket = 0;
    पूर्णाङ्क op2_minus = 0;
    पूर्णाङ्क long_transfer = 0;
    // Note: ldc p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: ldc p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: ldc p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    यदि (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        next();
    } अन्यथा {
        expect("'c<number>'");
    }

    skip(',');

    यदि (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
        coprocessor_destination_register = tok - TOK_ASM_c0;
        next();
    } अन्यथा {
        expect("'c<number>'");
    }

    skip(',');
    skip('[');
    parse_operand(s1, &ops[1]);
    यदि (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    यदि (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    यदि (tok == ',') {
        next(); // skip ','
        यदि (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
        यदि (ops[2].type == OP_REG32) {
            यदि (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, रिक्त));
            }
        } अन्यथा यदि (ops[2].type == OP_VREG64) {
            tcc_error("'%s' does not support VFP register operand", get_tok_str(token, रिक्त));
        }
    } अन्यथा {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        preincrement = 1; // add offset before transfer
    }
    यदि (!closed_bracket) {
        skip(']');
        preincrement = 1; // add offset before transfer
        यदि (tok == '!') {
            exclam = 1;
            next(); // skip '!'
        }
    }

    // TODO: Support options.

    यदि (token == TOK_ASM_ldc2 || token == TOK_ASM_stc2 || token == TOK_ASM_ldc2l || token == TOK_ASM_stc2l) {
        विकल्प (token) {
        पक्ष TOK_ASM_ldc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        पक्ष TOK_ASM_ldc2:
            asm_emit_coprocessor_data_transfer(0xF, coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
            भङ्ग;
        पक्ष TOK_ASM_stc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        पक्ष TOK_ASM_stc2:
            asm_emit_coprocessor_data_transfer(0xF, coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
            भङ्ग;
        }
    } अन्यथा विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_stcleq:
        long_transfer = 1;
        /* fallthrough */
    पक्ष TOK_ASM_stceq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
        भङ्ग;
    पक्ष TOK_ASM_ldcleq:
        long_transfer = 1;
        /* fallthrough */
    पक्ष TOK_ASM_ldceq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
        भङ्ग;
    स्वभाव:
        expect("coprocessor data transfer instruction");
    }
}

#यदि defined(TCC_ARM_VFP)
#define CP_SINGLE_PRECISION_FLOAT 10
#define CP_DOUBLE_PRECISION_FLOAT 11

स्थिर शून्य asm_floating_point_single_data_transfer_opcode(TCCState *s1, पूर्णाङ्क token)
{
    Operand ops[3];
    uint8_t coprocessor = 0;
    uint8_t coprocessor_destination_register = 0;
    पूर्णाङ्क long_transfer = 0;
    // Note: vldr p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: Not allowed: vldr p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: Not allowed: vldr p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_operand(s1, &ops[0]);
    यदि (ops[0].type == OP_VREG32) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        coprocessor_destination_register = ops[0].reg;
        long_transfer = coprocessor_destination_register & 1;
        coprocessor_destination_register >>= 1;
    } अन्यथा यदि (ops[0].type == OP_VREG64) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        coprocessor_destination_register = ops[0].reg;
        next();
    } अन्यथा {
        expect("floating point register");
    }

    skip(',');
    skip('[');
    parse_operand(s1, &ops[1]);
    यदि (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    यदि (tok == ',') {
        next(); // skip ','
        parse_operand(s1, &ops[2]);
        यदि (ops[2].type != OP_IM8 && ops[2].type != OP_IM8N) {
            expect("immediate offset");
        }
    } अन्यथा {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
    }
    skip(']');

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_vldreq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], 0, 1, 0, long_transfer, 1);
        भङ्ग;
    पक्ष TOK_ASM_vstreq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], 0, 1, 0, long_transfer, 0);
        भङ्ग;
    स्वभाव:
        expect("floating point data transfer instruction");
    }
}

स्थिर शून्य asm_floating_point_block_data_transfer_opcode(TCCState *s1, पूर्णाङ्क token)
{
    uint8_t coprocessor = 0;
    पूर्णाङ्क first_regset_register;
    पूर्णाङ्क last_regset_register;
    uint8_t regset_item_मोजणी;
    uint8_t extra_register_bit = 0;
    पूर्णाङ्क op0_exclam = 0;
    पूर्णाङ्क load = 0;
    पूर्णाङ्क preincrement = 0;
    Operand ops[1];
    Operand offset;
    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_vpusheq:
    पक्ष TOK_ASM_vpopeq:
        ops[0].type = OP_REG32;
        ops[0].reg = 13; // sp
        op0_exclam = 1;
        भङ्ग;
    स्वभाव:
        parse_operand(s1, &ops[0]);
        यदि (tok == '!') {
            op0_exclam = 1;
            next(); // skip '!'
        }
        skip(',');
    }

    skip('{');
    first_regset_register = asm_parse_vfp_regvar(tok, 1);
    यदि ((first_regset_register = asm_parse_vfp_regvar(tok, 1)) != -1) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        next();
    } अन्यथा यदि ((first_regset_register = asm_parse_vfp_regvar(tok, 0)) != -1) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        next();
    } अन्यथा {
        expect("floating-point register");
    }

    यदि (tok == '-') {
        next();
        यदि ((last_regset_register = asm_parse_vfp_regvar(tok, coprocessor == CP_DOUBLE_PRECISION_FLOAT)) != -1)
            next();
        अन्यथा {
            expect("floating-point register");
        }
    } अन्यथा
        last_regset_register = first_regset_register;

    यदि (last_regset_register < first_regset_register) {
        tcc_error("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
    }
    skip('}');
    // Note: 0 (one down) is not implemented by us regardless.
    regset_item_मोजणी = last_regset_register - first_regset_register + 1;
    यदि (coprocessor == CP_DOUBLE_PRECISION_FLOAT)
        regset_item_मोजणी <<= 1;
    अन्यथा {
        extra_register_bit = first_regset_register & 1;
        first_regset_register >>= 1;
    }
    offset.type = OP_IM8;
    offset.e.v = regset_item_मोजणी << 2;
    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_vstmeq: // post-increment store
    पक्ष TOK_ASM_vstmiaeq: // post-increment store
        भङ्ग;
    पक्ष TOK_ASM_vpopeq:
    पक्ष TOK_ASM_vldmeq: // post-increment load
    पक्ष TOK_ASM_vldmiaeq: // post-increment load
        load = 1;
        भङ्ग;
    पक्ष TOK_ASM_vldmdbeq: // pre-decrement load
        load = 1;
        /* fallthrough */
    पक्ष TOK_ASM_vpusheq:
    पक्ष TOK_ASM_vstmdbeq: // pre-decrement store
        offset.type = OP_IM8N;
        offset.e.v = -offset.e.v;
        preincrement = 1;
        भङ्ग;
    स्वभाव:
        expect("floating point block data transfer instruction");
    }
    यदि (ops[0].type != OP_REG32)
        expect("(first operand) register");
    अन्यथा यदि (ops[0].reg == 15)
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, रिक्त));
    अन्यथा यदि (!op0_exclam && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vldmeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vldmiaeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vstmeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vstmiaeq)
        tcc_error("first operand of '%s' should have an exclamation mark", get_tok_str(token, रिक्त));
    अन्यथा
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, first_regset_register, &ops[0], &offset, 0, preincrement, op0_exclam, extra_register_bit, load);
}

#define VMOV_FRACTIONAL_DIGITS 7
#define VMOV_ONE 10000000 /* pow(10, VMOV_FRACTIONAL_DIGITS) */

स्थिर uint32_t vmov_parse_fractional_part(ध्रुव वर्ण* s)
{
    uint32_t result = 0;
    पूर्णाङ्क i;
    प्रति (i = 0; i < VMOV_FRACTIONAL_DIGITS; ++i) {
        वर्ण c = *s;
        result *= 10;
        यदि (c >= '0' && c <= '9') {
            result += (c - '0');
            ++s;
        }
    }
    यदि (*s)
        expect("decimal numeral");
    प्रत्यागम result;
}

स्थिर पूर्णाङ्क vmov_linear_approx_index(uint32_t beginning, uint32_t end, uint32_t मूल्य)
{
    पूर्णाङ्क i;
    uint32_t k;
    uint32_t xvalue;

    k = (end - beginning)/16;
    प्रति (xvalue = beginning, i = 0; i < 16; ++i, xvalue += k) {
        यदि (मूल्य == xvalue)
            प्रत्यागम i;
    }
    //assert(0);
    प्रत्यागम -1;
}

स्थिर uint32_t vmov_parse_immediate_मूल्य() {
    uint32_t मूल्य;
    unsigned long integral_मूल्य;
    ध्रुव वर्ण *p;

    यदि (tok != TOK_PPNUM) {
        expect("immediate value");
    }
    p = tokc.str.data;
    errno = 0;
    integral_मूल्य = strtoul(p, (वर्ण **)&p, 0);

    यदि (errno || integral_मूल्य >= 32) {
        tcc_error("invalid floating-point immediate value");
    }

    मूल्य = (uint32_t) integral_मूल्य * VMOV_ONE;
    यदि (*p == '.') {
        ++p;
        मूल्य += vmov_parse_fractional_part(p);
    }
    next();
    प्रत्यागम मूल्य;
}

स्थिर uint8_t vmov_encode_immediate_मूल्य(uint32_t मूल्य)
{
    uint32_t limit;
    uint32_t end = 0;
    uint32_t beginning = 0;
    पूर्णाङ्क r = -1;
    पूर्णाङ्क n;
    पूर्णाङ्क i;

    limit = 32 * VMOV_ONE;
    प्रति (i = 0; i < 8; ++i) {
        यदि (मूल्य < limit) {
            end = limit;
            limit >>= 1;
            beginning = limit;
            r = i;
        } अन्यथा
            limit >>= 1;
    }
    यदि (r == -1 || मूल्य < beginning || मूल्य > end) {
        tcc_error("invalid decimal number for vmov: %d", मूल्य);
    }
    n = vmov_linear_approx_index(beginning, end, मूल्य);
    प्रत्यागम n | (((3 - r) & 0x7) << 4);
}

// Not standalone.
स्थिर शून्य asm_floating_point_immediate_data_processing_opcode_tail(TCCState *s1, पूर्णाङ्क token, uint8_t coprocessor, uint8_t CRd) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    uint8_t operands[3] = {0, 0, 0};
    uint32_t immediate_मूल्य = 0;
    पूर्णाङ्क op_minus = 0;
    uint8_t code;

    operands[0] = CRd;

    यदि (tok == '#' || tok == '$') {
        next();
    }
    यदि (tok == '-') {
        op_minus = 1;
        next();
    }
    immediate_मूल्य = vmov_parse_immediate_मूल्य();

    opcode1 = 11; // "Other" instruction
    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_vcmpeq_f32:
    पक्ष TOK_ASM_vcmpeq_f64:
        opcode2 = 2;
        operands[1] = 5;
        यदि (immediate_मूल्य) {
            expect("Immediate value 0");
        }
        भङ्ग;
    पक्ष TOK_ASM_vcmpeeq_f32:
    पक्ष TOK_ASM_vcmpeeq_f64:
        opcode2 = 6;
        operands[1] = 5;
        यदि (immediate_मूल्य) {
            expect("Immediate value 0");
        }
        भङ्ग;
    पक्ष TOK_ASM_vmoveq_f32:
    पक्ष TOK_ASM_vmoveq_f64:
        opcode2 = 0;
        यदि (op_minus)
            operands[1] = 0x8;
        अन्यथा
            operands[1] = 0x0;
        code = vmov_encode_immediate_मूल्य(immediate_मूल्य);
        operands[1] |= code >> 4;
        operands[2] = code & 0xF;
        भङ्ग;
    स्वभाव:
        expect("known floating point with immediate instruction");
    }

    यदि (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        यदि (operands[0] & 1)
            opcode1 |= 4;
        operands[0] >>= 1;
    }

    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, operands[0], operands[1], operands[2], opcode2, 0);
}

स्थिर शून्य asm_floating_point_reg_arm_reg_transfer_opcode_tail(TCCState *s1, पूर्णाङ्क token, पूर्णाङ्क coprocessor, पूर्णाङ्क nb_arm_regs, पूर्णाङ्क nb_ops, Operand ops[3]) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    विकल्प (coprocessor) {
    पक्ष CP_SINGLE_PRECISION_FLOAT:
        // "vmov.f32 r2, s3" or "vmov.f32 s3, r2"
        यदि (nb_ops != 2 || nb_arm_regs != 1) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and one ARM register operands");
        }
        यदि (ops[0].type != OP_REG32) { // determine mode: load or store
            // need to swap operands 0 and 1
            memcpy(&ops[2], &ops[1], परिमाण(ops[2]));
            memcpy(&ops[1], &ops[0], परिमाण(ops[1]));
            memcpy(&ops[0], &ops[2], परिमाण(ops[0]));
        } अन्यथा
            opcode1 |= 1;

        यदि (ops[1].type == OP_VREG32) {
            यदि (ops[1].reg & 1)
                opcode2 |= 4;
            ops[1].reg >>= 1;
        }

        यदि (ops[0].type == OP_VREG32) {
            यदि (ops[0].reg & 1)
                opcode1 |= 4;
            ops[0].reg >>= 1;
        }

        asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, 0x10, opcode2, 0);
        भङ्ग;
    पक्ष CP_DOUBLE_PRECISION_FLOAT:
        यदि (nb_ops != 3 || nb_arm_regs != 2) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and two ARM register operands");
        }
        // Determine whether it's a store into a VFP register (vmov "d1, r2, r3") rather than "vmov r2, r3, d1"
        यदि (ops[0].type == OP_VREG64) {
            यदि (ops[2].type == OP_REG32) {
                Operand temp;
                // need to rotate operand list to the left
                memcpy(&temp, &ops[0], परिमाण(temp));
                memcpy(&ops[0], &ops[1], परिमाण(ops[0]));
                memcpy(&ops[1], &ops[2], परिमाण(ops[1]));
                memcpy(&ops[2], &temp, परिमाण(ops[2]));
            } अन्यथा {
                tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
            }
        } अन्यथा यदि (ops[0].type != OP_REG32 || ops[1].type != OP_REG32 || ops[2].type != OP_VREG64) {
            tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
        } अन्यथा {
            opcode1 |= 1;
        }
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, ops[0].reg, &ops[1], &ops[2], 0, 0, 0, 1, opcode1);
        भङ्ग;
    स्वभाव:
        tcc_internal_error("unknown coprocessor");
    }
}

स्थिर शून्य asm_floating_point_vcvt_data_processing_opcode(TCCState *s1, पूर्णाङ्क token) {
    uint8_t coprocessor = 0;
    Operand ops[3];
    uint8_t opcode1 = 11;
    uint8_t opcode2 = 2;

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_vcvtreq_s32_f64:
    पक्ष TOK_ASM_vcvtreq_u32_f64:
    पक्ष TOK_ASM_vcvteq_s32_f64:
    पक्ष TOK_ASM_vcvteq_u32_f64:
    पक्ष TOK_ASM_vcvteq_f64_s32:
    पक्ष TOK_ASM_vcvteq_f64_u32:
    पक्ष TOK_ASM_vcvteq_f32_f64:
       coprocessor = CP_DOUBLE_PRECISION_FLOAT;
       भङ्ग;
    पक्ष TOK_ASM_vcvtreq_s32_f32:
    पक्ष TOK_ASM_vcvtreq_u32_f32:
    पक्ष TOK_ASM_vcvteq_s32_f32:
    पक्ष TOK_ASM_vcvteq_u32_f32:
    पक्ष TOK_ASM_vcvteq_f32_s32:
    पक्ष TOK_ASM_vcvteq_f32_u32:
    पक्ष TOK_ASM_vcvteq_f64_f32:
       coprocessor = CP_SINGLE_PRECISION_FLOAT;
       भङ्ग;
    स्वभाव:
       tcc_error("Unknown coprocessor for instruction '%s'", get_tok_str(token, रिक्त));
    }

    parse_operand(s1, &ops[0]);
    ops[1].type = OP_IM8;
    ops[1].e.v = 8;
    /* floating-point -> integer */
    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_vcvtreq_s32_f32:
    पक्ष TOK_ASM_vcvtreq_s32_f64:
    पक्ष TOK_ASM_vcvteq_s32_f32:
    पक्ष TOK_ASM_vcvteq_s32_f64:
        ops[1].e.v |= 1; // signed
        /* fall through */
    पक्ष TOK_ASM_vcvteq_u32_f32:
    पक्ष TOK_ASM_vcvteq_u32_f64:
    पक्ष TOK_ASM_vcvtreq_u32_f32:
    पक्ष TOK_ASM_vcvtreq_u32_f64:
        ops[1].e.v |= 4; // to_integer (opc2)
        भङ्ग;
    /* floating-point size conversion */
    पक्ष TOK_ASM_vcvteq_f64_f32:
    पक्ष TOK_ASM_vcvteq_f32_f64:
        ops[1].e.v = 7;
        भङ्ग;
    }

    skip(',');
    parse_operand(s1, &ops[2]);

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    /* floating-point -> integer */
    पक्ष TOK_ASM_vcvteq_s32_f32:
    पक्ष TOK_ASM_vcvteq_s32_f64:
    पक्ष TOK_ASM_vcvteq_u32_f32:
    पक्ष TOK_ASM_vcvteq_u32_f64:
        opcode2 |= 4; // round_zero
        भङ्ग;

    /* integer -> floating-point */
    पक्ष TOK_ASM_vcvteq_f64_s32:
    पक्ष TOK_ASM_vcvteq_f32_s32:
        opcode2 |= 4; // signed--special
        भङ्ग;

    /* floating-point size conversion */
    पक्ष TOK_ASM_vcvteq_f64_f32:
    पक्ष TOK_ASM_vcvteq_f32_f64:
        opcode2 |= 4; // always set
        भङ्ग;
    }

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_vcvteq_f64_u32:
    पक्ष TOK_ASM_vcvteq_f64_s32:
    पक्ष TOK_ASM_vcvteq_f64_f32:
        यदि (ops[0].type == OP_VREG64 && ops[2].type == OP_VREG32) {
        } अन्यथा {
            expect("d<number>, s<number>");
        }
        भङ्ग;
    स्वभाव:
        यदि (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
            यदि (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG32) {
            } अन्यथा {
                expect("s<number>, s<number>");
            }
        } अन्यथा यदि (coprocessor == CP_DOUBLE_PRECISION_FLOAT) {
            यदि (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG64) {
            } अन्यथा {
                expect("s<number>, d<number>");
            }
        }
    }

    यदि (ops[2].type == OP_VREG32) {
        यदि (ops[2].reg & 1)
            opcode2 |= 1;
        ops[2].reg >>= 1;
    }
    यदि (ops[0].type == OP_VREG32) {
        यदि (ops[0].reg & 1)
            opcode1 |= 4;
        ops[0].reg >>= 1;
    }
    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

स्थिर शून्य asm_floating_point_data_processing_opcode(TCCState *s1, पूर्णाङ्क token) {
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0; // (0 || 2) | register selection
    Operand ops[3];
    uint8_t nb_ops = 0;
    पूर्णाङ्क vmov = 0;
    पूर्णाङ्क nb_arm_regs = 0;

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

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_vmlaeq_f64:
    पक्ष TOK_ASM_vmlseq_f64:
    पक्ष TOK_ASM_vnmlseq_f64:
    पक्ष TOK_ASM_vnmlaeq_f64:
    पक्ष TOK_ASM_vmuleq_f64:
    पक्ष TOK_ASM_vnmuleq_f64:
    पक्ष TOK_ASM_vaddeq_f64:
    पक्ष TOK_ASM_vsubeq_f64:
    पक्ष TOK_ASM_vdiveq_f64:
    पक्ष TOK_ASM_vnegeq_f64:
    पक्ष TOK_ASM_vabseq_f64:
    पक्ष TOK_ASM_vsqrteq_f64:
    पक्ष TOK_ASM_vcmpeq_f64:
    पक्ष TOK_ASM_vcmpeeq_f64:
    पक्ष TOK_ASM_vmoveq_f64:
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
    }

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_vmoveq_f32:
    पक्ष TOK_ASM_vmoveq_f64:
        vmov = 1;
        भङ्ग;
    }

    प्रति (nb_ops = 0; nb_ops < 3; ) {
        // Note: Necessary because parse_operand can't parse decimal numerals.
        यदि (nb_ops == 1 && (tok == '#' || tok == '$' || tok == TOK_PPNUM || tok == '-')) {
            asm_floating_point_immediate_data_processing_opcode_tail(s1, token, coprocessor, ops[0].reg);
            प्रत्यागम;
        }
        parse_operand(s1, &ops[nb_ops]);
        यदि (vmov && ops[nb_ops].type == OP_REG32) {
            ++nb_arm_regs;
        } अन्यथा यदि (ops[nb_ops].type == OP_VREG32) {
            यदि (coprocessor != CP_SINGLE_PRECISION_FLOAT) {
                expect("'s<number>'");
            }
        } अन्यथा यदि (ops[nb_ops].type == OP_VREG64) {
            यदि (coprocessor != CP_DOUBLE_PRECISION_FLOAT) {
                expect("'d<number>'");
            }
        } अन्यथा {
            expect("floating point register");
        }
        ++nb_ops;
        यदि (tok == ',')
            next();
        अन्यथा
            भङ्ग;
    }

    यदि (nb_arm_regs == 0) {
        यदि (nb_ops == 2) { // implicit
            memcpy(&ops[2], &ops[1], परिमाण(ops[1])); // move ops[2]
            memcpy(&ops[1], &ops[0], परिमाण(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
        यदि (nb_ops < 3) {
            tcc_error("Not enough operands for '%s' (%u)", get_tok_str(token, रिक्त), nb_ops);
        }
    }

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_vmlaeq_f32:
    पक्ष TOK_ASM_vmlaeq_f64:
        opcode1 = 0;
        opcode2 = 0;
        भङ्ग;
    पक्ष TOK_ASM_vmlseq_f32:
    पक्ष TOK_ASM_vmlseq_f64:
        opcode1 = 0;
        opcode2 = 2;
        भङ्ग;
    पक्ष TOK_ASM_vnmlseq_f32:
    पक्ष TOK_ASM_vnmlseq_f64:
        opcode1 = 1;
        opcode2 = 0;
        भङ्ग;
    पक्ष TOK_ASM_vnmlaeq_f32:
    पक्ष TOK_ASM_vnmlaeq_f64:
        opcode1 = 1;
        opcode2 = 2;
        भङ्ग;
    पक्ष TOK_ASM_vmuleq_f32:
    पक्ष TOK_ASM_vmuleq_f64:
        opcode1 = 2;
        opcode2 = 0;
        भङ्ग;
    पक्ष TOK_ASM_vnmuleq_f32:
    पक्ष TOK_ASM_vnmuleq_f64:
        opcode1 = 2;
        opcode2 = 2;
        भङ्ग;
    पक्ष TOK_ASM_vaddeq_f32:
    पक्ष TOK_ASM_vaddeq_f64:
        opcode1 = 3;
        opcode2 = 0;
        भङ्ग;
    पक्ष TOK_ASM_vsubeq_f32:
    पक्ष TOK_ASM_vsubeq_f64:
        opcode1 = 3;
        opcode2 = 2;
        भङ्ग;
    पक्ष TOK_ASM_vdiveq_f32:
    पक्ष TOK_ASM_vdiveq_f64:
        opcode1 = 8;
        opcode2 = 0;
        भङ्ग;
    पक्ष TOK_ASM_vnegeq_f32:
    पक्ष TOK_ASM_vnegeq_f64:
        opcode1 = 11; // Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        भङ्ग;
    पक्ष TOK_ASM_vabseq_f32:
    पक्ष TOK_ASM_vabseq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 0;
        भङ्ग;
    पक्ष TOK_ASM_vsqrteq_f32:
    पक्ष TOK_ASM_vsqrteq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        भङ्ग;
    पक्ष TOK_ASM_vcmpeq_f32:
    पक्ष TOK_ASM_vcmpeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        भङ्ग;
    पक्ष TOK_ASM_vcmpeeq_f32:
    पक्ष TOK_ASM_vcmpeeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        भङ्ग;
    पक्ष TOK_ASM_vmoveq_f32:
    पक्ष TOK_ASM_vmoveq_f64:
        यदि (nb_arm_regs > 0) { // vmov.f32 r2, s3 or similar
            asm_floating_point_reg_arm_reg_transfer_opcode_tail(s1, token, coprocessor, nb_arm_regs, nb_ops, ops);
            प्रत्यागम;
        } अन्यथा {
            opcode1 = 11; // "Other" instruction
            opcode2 = 2;
            ops[1].type = OP_IM8;
            ops[1].e.v = 0;
        }
        भङ्ग;
    स्वभाव:
        expect("known floating point instruction");
    }

    यदि (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        यदि (ops[2].type == OP_VREG32) {
            यदि (ops[2].reg & 1)
                opcode2 |= 1;
            ops[2].reg >>= 1;
        }

        यदि (ops[1].type == OP_VREG32) {
            यदि (ops[1].reg & 1)
                opcode2 |= 4;
            ops[1].reg >>= 1;
        }

        यदि (ops[0].type == OP_VREG32) {
            यदि (ops[0].reg & 1)
                opcode1 |= 4;
            ops[0].reg >>= 1;
        }
    }

    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

स्थिर पूर्णाङ्क asm_parse_vfp_status_regvar(पूर्णाङ्क t)
{
    विकल्प (t) {
    पक्ष TOK_ASM_fpsid:
        प्रत्यागम 0;
    पक्ष TOK_ASM_fpscr:
        प्रत्यागम 1;
    पक्ष TOK_ASM_fpexc:
        प्रत्यागम 8;
    स्वभाव:
        प्रत्यागम -1;
    }
}

स्थिर शून्य asm_floating_point_status_register_opcode(TCCState* s1, पूर्णाङ्क token)
{
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode;
    पूर्णाङ्क vfp_sys_reg = -1;
    Operand arm_operand;
    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_vmrseq:
        opcode = 0xf;
        यदि (tok == TOK_ASM_apsr_nzcv) {
            arm_operand.type = OP_REG32;
            arm_operand.reg = 15; // not PC
            next(); // skip apsr_nzcv
        } अन्यथा {
            parse_operand(s1, &arm_operand);
            यदि (arm_operand.type == OP_REG32 && arm_operand.reg == 15) {
                tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, रिक्त));
            }
        }

        skip(',');
        vfp_sys_reg = asm_parse_vfp_status_regvar(tok);
        next(); // skip vfp sys reg
        यदि (arm_operand.type == OP_REG32 && arm_operand.reg == 15 && vfp_sys_reg != 1) {
            tcc_error("'%s' only supports the variant 'vmrs apsr_nzcv, fpscr' here", get_tok_str(token, रिक्त));
        }
        भङ्ग;
    पक्ष TOK_ASM_vmsreq:
        opcode = 0xe;
        vfp_sys_reg = asm_parse_vfp_status_regvar(tok);
        next(); // skip vfp sys reg
        skip(',');
        parse_operand(s1, &arm_operand);
        यदि (arm_operand.type == OP_REG32 && arm_operand.reg == 15) {
            tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, रिक्त));
        }
        भङ्ग;
    स्वभाव:
        expect("floating point status register instruction");
    }
    यदि (vfp_sys_reg == -1) {
        expect("VFP system register");
    }
    यदि (arm_operand.type != OP_REG32) {
        expect("ARM register");
    }
    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode, arm_operand.reg, vfp_sys_reg, 0x10, 0, 0);
}

#endif

स्थिर शून्य asm_misc_single_data_transfer_opcode(TCCState *s1, पूर्णाङ्क token)
{
    Operand ops[3];
    पूर्णाङ्क exclam = 0;
    पूर्णाङ्क closed_bracket = 0;
    पूर्णाङ्क op2_minus = 0;
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
    यदि (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    अन्यथा {
        expect("(destination operand) register");
    }
    यदि (tok != ',')
        expect("at least two arguments");
    अन्यथा
        next(); // skip ','
    skip('[');
    parse_operand(s1, &ops[1]);
    यदि (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    अन्यथा {
        expect("(first source operand) register");
    }
    यदि (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    यदि (tok == ',') {
        next(); // skip ','
        यदि (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
    } अन्यथा {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        opcode |= 1 << 24; // add offset before transfer
    }
    यदि (!closed_bracket) {
        skip(']');
        opcode |= 1 << 24; // add offset before transfer
        यदि (tok == '!') {
            exclam = 1;
            next(); // skip '!'
        }
    }

    यदि (exclam) {
        यदि ((opcode & (1 << 24)) == 0) {
            tcc_error("result of '%s' would be unpredictable here", get_tok_str(token, रिक्त));
        }
        opcode |= 1 << 21; // write offset back into register
    }

    यदि (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        पूर्णाङ्क v = ops[2].e.v;
        यदि (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        यदि (v >= 0) {
            opcode |= 1 << 23; // up
            यदि (v >= 0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, रिक्त));
            अन्यथा {
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        } अन्यथा { // down
            यदि (v <= -0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, रिक्त));
            अन्यथा {
                v = -v;
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        }
        opcode |= 1 << 22; // not ENCODE_IMMEDIATE_FLAG;
    } अन्यथा यदि (ops[2].type == OP_REG32) {
        यदि (!op2_minus)
            opcode |= 1 << 23; // up
        opcode |= ops[2].reg;
    } अन्यथा
        expect("register");

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_ldrsheq:
        opcode |= 1 << 5; // halfword, not byte
        /* fallthrough */
    पक्ष TOK_ASM_ldrsbeq:
        opcode |= 1 << 6; // sign extend
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        भङ्ग;
    पक्ष TOK_ASM_ldrheq:
        opcode |= 1 << 5; // halfword, not byte
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        भङ्ग;
    पक्ष TOK_ASM_strheq:
        opcode |= 1 << 5; // halfword, not byte
        asm_emit_opcode(token, opcode);
        भङ्ग;
    }
}

/* Note: almost dupe of encbranch in arm-gen.c */
स्थिर uint32_t encbranchoffset(पूर्णाङ्क pos, पूर्णाङ्क addr, पूर्णाङ्क fail)
{
  addr-=pos+8;
  addr/=4;
  यदि(addr>=0x7fffff || addr<-0x800000) {
    यदि(fail)
      tcc_error("branch offset is too far");
    प्रत्यागम 0;
  }
  प्रत्यागम /*not 0x0A000000|*/(addr&0xffffff);
}

स्थिर शून्य asm_branch_opcode(TCCState *s1, पूर्णाङ्क token)
{
    पूर्णाङ्क jmp_disp = 0;
    Operand op;
    अभिव्यक्ती_मूल्य e;
    ElfSym *esym;

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_beq:
    पक्ष TOK_ASM_bleq:
        asm_अभिव्यक्ती(s1, &e);
        यदि (e.sym) {
            esym = elfsym(e.sym);
            यदि (esym && esym->st_shndx == cur_text_section->sh_अंक) {
                jmp_disp = esym->st_मूल्य;
            } अन्यथा {
                greloca(cur_text_section, e.sym, ind, R_ARM_PC24, 0);
                jmp_disp = ind;
            }
        }
        jmp_disp = encbranchoffset(ind, e.v + jmp_disp, 1);
        भङ्ग;
    स्वभाव:
        parse_operand(s1, &op);
        भङ्ग;
    }
    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_beq:
        asm_emit_opcode(token, (0xa << 24) | (jmp_disp & 0xffffff));
        भङ्ग;
    पक्ष TOK_ASM_bleq:
        asm_emit_opcode(token, (0xb << 24) | (jmp_disp & 0xffffff));
        भङ्ग;
    पक्ष TOK_ASM_bxeq:
        यदि (op.type != OP_REG32)
            expect("register");
        अन्यथा
            asm_emit_opcode(token, (0x12fff1 << 4) | op.reg);
        भङ्ग;
    पक्ष TOK_ASM_blxeq:
        यदि (op.type != OP_REG32)
            expect("register");
        अन्यथा
            asm_emit_opcode(token, (0x12fff3 << 4) | op.reg);
        भङ्ग;
    स्वभाव:
        expect("branch instruction");
    }
}

ST_FUNC शून्य asm_opcode(TCCState *s1, पूर्णाङ्क token)
{
    यावत् (token == TOK_LINEFEED) {
        next();
        token = tok;
    }
    यदि (token == TOK_EOF)
        प्रत्यागम;
    यदि (token < TOK_ASM_nopeq) { // no condition code
        विकल्प (token) {
        पक्ष TOK_ASM_cdp2:
            asm_coprocessor_opcode(s1, token);
            प्रत्यागम;
        पक्ष TOK_ASM_ldc2:
        पक्ष TOK_ASM_ldc2l:
        पक्ष TOK_ASM_stc2:
        पक्ष TOK_ASM_stc2l:
            asm_coprocessor_data_transfer_opcode(s1, token);
            प्रत्यागम;
        स्वभाव:
            expect("instruction");
        }
    }

    विकल्प (ARM_INSTRUCTION_GROUP(token)) {
    पक्ष TOK_ASM_pusheq:
    पक्ष TOK_ASM_popeq:
    पक्ष TOK_ASM_stmdaeq:
    पक्ष TOK_ASM_ldmdaeq:
    पक्ष TOK_ASM_stmeq:
    पक्ष TOK_ASM_ldmeq:
    पक्ष TOK_ASM_stmiaeq:
    पक्ष TOK_ASM_ldmiaeq:
    पक्ष TOK_ASM_stmdbeq:
    पक्ष TOK_ASM_ldmdbeq:
    पक्ष TOK_ASM_stmibeq:
    पक्ष TOK_ASM_ldmibeq:
        asm_block_data_transfer_opcode(s1, token);
        प्रत्यागम;
    पक्ष TOK_ASM_nopeq:
    पक्ष TOK_ASM_wfeeq:
    पक्ष TOK_ASM_wfieq:
        asm_nullary_opcode(token);
        प्रत्यागम;
    पक्ष TOK_ASM_swieq:
    पक्ष TOK_ASM_svceq:
        asm_unary_opcode(s1, token);
        प्रत्यागम;
    पक्ष TOK_ASM_beq:
    पक्ष TOK_ASM_bleq:
    पक्ष TOK_ASM_bxeq:
    पक्ष TOK_ASM_blxeq:
        asm_branch_opcode(s1, token);
        प्रत्यागम;
    पक्ष TOK_ASM_clzeq:
    पक्ष TOK_ASM_sxtbeq:
    पक्ष TOK_ASM_sxtheq:
    पक्ष TOK_ASM_uxtbeq:
    पक्ष TOK_ASM_uxtheq:
    पक्ष TOK_ASM_movteq:
    पक्ष TOK_ASM_movweq:
        asm_द्विमान_opcode(s1, token);
        प्रत्यागम;

    पक्ष TOK_ASM_ldreq:
    पक्ष TOK_ASM_ldrbeq:
    पक्ष TOK_ASM_streq:
    पक्ष TOK_ASM_strbeq:
    पक्ष TOK_ASM_ldrexeq:
    पक्ष TOK_ASM_ldrexbeq:
    पक्ष TOK_ASM_ldrexheq:
    पक्ष TOK_ASM_strexeq:
    पक्ष TOK_ASM_strexbeq:
    पक्ष TOK_ASM_strexheq:
        asm_single_data_transfer_opcode(s1, token);
        प्रत्यागम;

    पक्ष TOK_ASM_ldrheq:
    पक्ष TOK_ASM_ldrsheq:
    पक्ष TOK_ASM_ldrsbeq:
    पक्ष TOK_ASM_strheq:
       asm_misc_single_data_transfer_opcode(s1, token);
       प्रत्यागम;

    पक्ष TOK_ASM_andeq:
    पक्ष TOK_ASM_eoreq:
    पक्ष TOK_ASM_subeq:
    पक्ष TOK_ASM_rsbeq:
    पक्ष TOK_ASM_addeq:
    पक्ष TOK_ASM_adceq:
    पक्ष TOK_ASM_sbceq:
    पक्ष TOK_ASM_rsceq:
    पक्ष TOK_ASM_tsteq:
    पक्ष TOK_ASM_teqeq:
    पक्ष TOK_ASM_cmpeq:
    पक्ष TOK_ASM_cmneq:
    पक्ष TOK_ASM_orreq:
    पक्ष TOK_ASM_moveq:
    पक्ष TOK_ASM_biceq:
    पक्ष TOK_ASM_mvneq:
    पक्ष TOK_ASM_andseq:
    पक्ष TOK_ASM_eorseq:
    पक्ष TOK_ASM_subseq:
    पक्ष TOK_ASM_rsbseq:
    पक्ष TOK_ASM_addseq:
    पक्ष TOK_ASM_adcseq:
    पक्ष TOK_ASM_sbcseq:
    पक्ष TOK_ASM_rscseq:
//  case TOK_ASM_tstseq:
//  case TOK_ASM_teqseq:
//  case TOK_ASM_cmpseq:
//  case TOK_ASM_cmnseq:
    पक्ष TOK_ASM_orrseq:
    पक्ष TOK_ASM_movseq:
    पक्ष TOK_ASM_bicseq:
    पक्ष TOK_ASM_mvnseq:
        asm_data_processing_opcode(s1, token);
        प्रत्यागम;

    पक्ष TOK_ASM_lsleq:
    पक्ष TOK_ASM_lslseq:
    पक्ष TOK_ASM_lsreq:
    पक्ष TOK_ASM_lsrseq:
    पक्ष TOK_ASM_asreq:
    पक्ष TOK_ASM_asrseq:
    पक्ष TOK_ASM_roreq:
    पक्ष TOK_ASM_rorseq:
    पक्ष TOK_ASM_rrxseq:
    पक्ष TOK_ASM_rrxeq:
        asm_shift_opcode(s1, token);
        प्रत्यागम;

    पक्ष TOK_ASM_muleq:
    पक्ष TOK_ASM_mulseq:
    पक्ष TOK_ASM_mlaeq:
    पक्ष TOK_ASM_mlaseq:
    पक्ष TOK_ASM_mlseq:
    पक्ष TOK_ASM_udiveq:
    पक्ष TOK_ASM_sdiveq:
        asm_multiplication_opcode(s1, token);
        प्रत्यागम;

    पक्ष TOK_ASM_smulleq:
    पक्ष TOK_ASM_smullseq:
    पक्ष TOK_ASM_umulleq:
    पक्ष TOK_ASM_umullseq:
    पक्ष TOK_ASM_smlaleq:
    पक्ष TOK_ASM_smlalseq:
    पक्ष TOK_ASM_umlaleq:
    पक्ष TOK_ASM_umlalseq:
        asm_long_multiplication_opcode(s1, token);
        प्रत्यागम;

    पक्ष TOK_ASM_cdpeq:
    पक्ष TOK_ASM_mcreq:
    पक्ष TOK_ASM_mrceq:
        asm_coprocessor_opcode(s1, token);
        प्रत्यागम;

    पक्ष TOK_ASM_ldceq:
    पक्ष TOK_ASM_ldcleq:
    पक्ष TOK_ASM_stceq:
    पक्ष TOK_ASM_stcleq:
        asm_coprocessor_data_transfer_opcode(s1, token);
        प्रत्यागम;

#यदि defined(TCC_ARM_VFP)
    पक्ष TOK_ASM_vldreq:
    पक्ष TOK_ASM_vstreq:
        asm_floating_point_single_data_transfer_opcode(s1, token);
        प्रत्यागम;

    पक्ष TOK_ASM_vmlaeq_f32:
    पक्ष TOK_ASM_vmlseq_f32:
    पक्ष TOK_ASM_vnmlseq_f32:
    पक्ष TOK_ASM_vnmlaeq_f32:
    पक्ष TOK_ASM_vmuleq_f32:
    पक्ष TOK_ASM_vnmuleq_f32:
    पक्ष TOK_ASM_vaddeq_f32:
    पक्ष TOK_ASM_vsubeq_f32:
    पक्ष TOK_ASM_vdiveq_f32:
    पक्ष TOK_ASM_vnegeq_f32:
    पक्ष TOK_ASM_vabseq_f32:
    पक्ष TOK_ASM_vsqrteq_f32:
    पक्ष TOK_ASM_vcmpeq_f32:
    पक्ष TOK_ASM_vcmpeeq_f32:
    पक्ष TOK_ASM_vmoveq_f32:
    पक्ष TOK_ASM_vmlaeq_f64:
    पक्ष TOK_ASM_vmlseq_f64:
    पक्ष TOK_ASM_vnmlseq_f64:
    पक्ष TOK_ASM_vnmlaeq_f64:
    पक्ष TOK_ASM_vmuleq_f64:
    पक्ष TOK_ASM_vnmuleq_f64:
    पक्ष TOK_ASM_vaddeq_f64:
    पक्ष TOK_ASM_vsubeq_f64:
    पक्ष TOK_ASM_vdiveq_f64:
    पक्ष TOK_ASM_vnegeq_f64:
    पक्ष TOK_ASM_vabseq_f64:
    पक्ष TOK_ASM_vsqrteq_f64:
    पक्ष TOK_ASM_vcmpeq_f64:
    पक्ष TOK_ASM_vcmpeeq_f64:
    पक्ष TOK_ASM_vmoveq_f64:
        asm_floating_point_data_processing_opcode(s1, token);
        प्रत्यागम;

    पक्ष TOK_ASM_vcvtreq_s32_f32:
    पक्ष TOK_ASM_vcvtreq_s32_f64:
    पक्ष TOK_ASM_vcvteq_s32_f32:
    पक्ष TOK_ASM_vcvteq_s32_f64:
    पक्ष TOK_ASM_vcvtreq_u32_f32:
    पक्ष TOK_ASM_vcvtreq_u32_f64:
    पक्ष TOK_ASM_vcvteq_u32_f32:
    पक्ष TOK_ASM_vcvteq_u32_f64:
    पक्ष TOK_ASM_vcvteq_f64_s32:
    पक्ष TOK_ASM_vcvteq_f32_s32:
    पक्ष TOK_ASM_vcvteq_f64_u32:
    पक्ष TOK_ASM_vcvteq_f32_u32:
    पक्ष TOK_ASM_vcvteq_f64_f32:
    पक्ष TOK_ASM_vcvteq_f32_f64:
        asm_floating_point_vcvt_data_processing_opcode(s1, token);
        प्रत्यागम;

    पक्ष TOK_ASM_vpusheq:
    पक्ष TOK_ASM_vpopeq:
    पक्ष TOK_ASM_vldmeq:
    पक्ष TOK_ASM_vldmiaeq:
    पक्ष TOK_ASM_vldmdbeq:
    पक्ष TOK_ASM_vstmeq:
    पक्ष TOK_ASM_vstmiaeq:
    पक्ष TOK_ASM_vstmdbeq:
        asm_floating_point_block_data_transfer_opcode(s1, token);
        प्रत्यागम;

    पक्ष TOK_ASM_vmsreq:
    पक्ष TOK_ASM_vmrseq:
        asm_floating_point_status_register_opcode(s1, token);
        प्रत्यागम;
#endif

    स्वभाव:
        expect("known instruction");
    }
}

ST_FUNC शून्य subst_asm_operand(CString *add_str, SValue *sv, पूर्णाङ्क modifier)
{
    पूर्णाङ्क r, reg, size, val;

    r = sv->r;
    यदि ((r & VT_VALMASK) == VT_CONST) {
        यदि (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(add_str, '#');
        यदि (r & VT_SYM) {
            ध्रुव वर्ण *name = get_tok_str(sv->sym->v, रिक्त);
            यदि (sv->sym->v >= SYM_FIRST_ANOM) {
                /* In case of anonymous symbols ("L.42", used
                   for static data labels) we can't find them
                   in the C symbol table when later looking up
                   this name.  So enter them now into the asm label
                   list when we still know the symbol.  */
                get_asm_sym(tok_alloc(name, strlen(name))->tok, sv->sym);
            }
            यदि (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            यदि ((uint32_t) sv->c.i == 0)
                गच्छ no_offset;
            cstr_ccat(add_str, '+');
        }
        val = sv->c.i;
        यदि (modifier == 'n')
            val = -val;
        cstr_printf(add_str, "%d", val);
      no_offset:;
    } अन्यथा यदि ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "[fp,#%d]", (पूर्णाङ्क) sv->c.i);
    } अन्यथा यदि (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        यदि (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "[%s]",
                 get_tok_str(TOK_ASM_r0 + reg, रिक्त));
    } अन्यथा {
        /* register case */
        reg = r & VT_VALMASK;
        यदि (reg >= VT_CONST)
            tcc_internal_error("");

        /* choose register operand size */
        यदि ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            size = 1;
        अन्यथा यदि ((sv->type.t & VT_BTYPE) == VT_SHORT)
            size = 2;
        अन्यथा
            size = 4;

        यदि (modifier == 'b') {
            size = 1;
        } अन्यथा यदि (modifier == 'w') {
            size = 2;
        } अन्यथा यदि (modifier == 'k') {
            size = 4;
        }

        विकल्प (size) {
        स्वभाव:
            reg = TOK_ASM_r0 + reg;
            भङ्ग;
        }
        cstr_printf(add_str, "%s", get_tok_str(reg, रिक्त));
    }
}

/* generate prolog and epilog code for asm statement */
ST_FUNC शून्य asm_gen_code(ASMOperand *operands, पूर्णाङ्क nb_operands,
                          पूर्णाङ्क nb_outputs, पूर्णाङ्क is_output,
                          uint8_t *clobber_regs,
                          पूर्णाङ्क out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    पूर्णाङ्क i, reg;
    uint32_t saved_regset = 0;

    // TODO: Check non-E ABI.
    // Note: Technically, r13 (sp) is also callee-saved--but that does not matter yet
    स्थिर ध्रुव uint8_t reg_saved[] = { 4, 5, 6, 7, 8, 9 /* Note: sometimes special reg "sb" */ , 10, 11 };

    /* mark all used registers */
    memcpy(regs_allocated, clobber_regs, परिमाण(regs_allocated));
    प्रति(i = 0; i < nb_operands;i++) {
        op = &operands[i];
        यदि (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }
    प्रति(i = 0; i < परिमाण(reg_saved)/परिमाण(reg_saved[0]); i++) {
        reg = reg_saved[i];
        यदि (regs_allocated[reg])
            saved_regset |= 1 << reg;
    }

    यदि (!is_output) { // prolog
        /* generate reg save code */
        यदि (saved_regset)
            gen_le32(0xe92d0000 | saved_regset); // push {...}

        /* generate load code */
        प्रति(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            यदि (op->reg >= 0) {
                यदि ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_memory) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    load(op->reg, &sv);
                } अन्यथा यदि (i >= nb_outputs || op->is_rw) { // not write-only
                    /* load value in register */
                    load(op->reg, op->vt);
                    यदि (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }
    } अन्यथा { // epilog
        /* generate save code */
        प्रति(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            यदि (op->reg >= 0) {
                यदि ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    यदि (!op->is_memory) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        load(out_reg, &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | out_reg;
                        store(op->reg, &sv);
                    }
                } अन्यथा {
                    store(op->reg, op->vt);
                    यदि (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }

        /* generate reg restore code */
        यदि (saved_regset)
            gen_le32(0xe8bd0000 | saved_regset); // pop {...}
    }
}

/* return the constraint priority (we allocate first the lowest
   numbered constraints) */
स्थिर अन्तःस्थ पूर्णाङ्क constraint_priority(ध्रुव वर्ण *str)
{
    पूर्णाङ्क priority, c, pr;

    /* we take the lowest priority */
    priority = 0;
    प्रति(;;) {
        c = *str;
        यदि (c == '\0')
            भङ्ग;
        str++;
        विकल्प(c) {
        पक्ष 'l': // in ARM mode, that's  an alias for 'r' [ARM].
        पक्ष 'r': // register [general]
        पक्ष 'p': // valid memory address for load,store [general]
            pr = 3;
            भङ्ग;
        पक्ष 'M': // integer constant for shifts [ARM]
        पक्ष 'I': // integer valid for data processing instruction immediate
        पक्ष 'J': // integer in range -4095...4095

        पक्ष 'i': // immediate integer operand, including symbolic constants [general]
        पक्ष 'm': // memory operand [general]
        पक्ष 'g': // general-purpose-register, memory, immediate integer [general]
            pr = 4;
            भङ्ग;
        स्वभाव:
            tcc_error("unknown constraint '%c'", c);
        }
        यदि (pr > priority)
            priority = pr;
    }
    प्रत्यागम priority;
}

स्थिर ध्रुव वर्ण *skip_constraint_modifiers(ध्रुव वर्ण *p)
{
    /* Constraint modifier:
        =   Operand is written to by this instruction
        +   Operand is both read and written to by this instruction
        %   Instruction is commutative for this operand and the following operand.

       Per-alternative constraint modifier:
        &   Operand is clobbered before the instruction is done using the input operands
    */
    यावत् (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    प्रत्यागम p;
}

#define REG_OUT_MASK 0x01
#define REG_IN_MASK  0x02

#define is_reg_allocated(reg) (regs_allocated[reg] & reg_mask)

ST_FUNC शून्य asm_compute_constraints(ASMOperand *operands,
                                    पूर्णाङ्क nb_operands, पूर्णाङ्क nb_outputs,
                                    ध्रुव uint8_t *clobber_regs,
                                    पूर्णाङ्क *pout_reg)
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
    पूर्णाङ्क sorted_op[MAX_ASM_OPERANDS];
    पूर्णाङ्क i, j, k, p1, p2, tmp, reg, c, reg_mask;
    ध्रुव वर्ण *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    प्रति (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->आदान_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    प्रति (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        यदि (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = find_constraint(operands, nb_operands, str, रिक्त);
            यदि ((unsigned) k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                          i, str);
            op->ref_index = k;
            यदि (operands[k].आदान_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].आदान_index = i;
            op->priority = 5;
        } अन्यथा यदि ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->priority = 1;
            op->reg = reg;
        } अन्यथा {
            op->priority = constraint_priority(str);
        }
    }

    /* sort operands according to their priority */
    प्रति (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    प्रति (i = 0; i < nb_operands - 1; i++) {
        प्रति (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            यदि (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    प्रति (i = 0; i < NB_ASM_REGS; i++) {
        यदि (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        अन्यथा
            regs_allocated[i] = 0;
    }
    /* sp cannot be used */
    regs_allocated[13] = REG_IN_MASK | REG_OUT_MASK;
    /* fp cannot be used yet */
    regs_allocated[11] = REG_IN_MASK | REG_OUT_MASK;

    /* allocate registers and generate corresponding asm moves */
    प्रति (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        यदि (op->ref_index >= 0)
            अनुवर्त;
        /* select if register is used for output, input or both */
        यदि (op->आदान_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } अन्यथा यदि (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } अन्यथा {
            reg_mask = REG_IN_MASK;
        }
        यदि (op->reg >= 0) {
            यदि (is_reg_allocated(op->reg))
                tcc_error
                    ("asm regvar requests register that's taken already");
            reg = op->reg;
        }
      try_next:
        c = *str++;
        विकल्प (c) {
        पक्ष '=': // Operand is written-to
            गच्छ try_next;
        पक्ष '+': // Operand is both READ and written-to
            op->is_rw = 1;
            /* FALL THRU */
        पक्ष '&': // Operand is clobbered before the instruction is done using the input operands
            यदि (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs",
                          c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            गच्छ try_next;
        पक्ष 'l': // In non-thumb mode, alias for 'r'--otherwise r0-r7 [ARM]
        पक्ष 'r': // general-purpose register
        पक्ष 'p': // loadable/storable address
            /* any general register */
            यदि ((reg = op->reg) >= 0)
                गच्छ reg_found;
            अन्यथा प्रति (reg = 0; reg <= 8; reg++) {
                यदि (!is_reg_allocated(reg))
                    गच्छ reg_found;
            }
            गच्छ try_next;
          reg_found:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_mask;
            भङ्ग;
        पक्ष 'I': // integer that is valid as an data processing instruction immediate (0...255, rotated by a multiple of two)
        पक्ष 'J': // integer in the range -4095 to 4095 [ARM]
        पक्ष 'K': // integer that satisfies constraint I when inverted (one's complement)
        पक्ष 'L': // integer that satisfies constraint I when inverted (two's complement)
        पक्ष 'i': // immediate integer operand, including symbolic constants
            यदि (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                गच्छ try_next;
            भङ्ग;
        पक्ष 'M': // integer in the range 0 to 32
            यदि (!
                ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) ==
                 VT_CONST))
                गच्छ try_next;
            भङ्ग;
        पक्ष 'm': // memory operand
        पक्ष 'g':
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            यदि (j < nb_outputs || c == 'm') {
                यदि ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register */
                    प्रति (reg = 0; reg <= 8; reg++) {
                        यदि (!(regs_allocated[reg] & REG_IN_MASK))
                            गच्छ reg_found1;
                    }
                    गच्छ try_next;
                  reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_IN_MASK;
                    op->reg = reg;
                    op->is_memory = 1;
                }
            }
            भङ्ग;
        स्वभाव:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                      j, op->constraint);
            भङ्ग;
        }
        /* if a reference is present for that operand, we assign it too */
        यदि (op->आदान_index >= 0) {
            operands[op->आदान_index].reg = op->reg;
            operands[op->आदान_index].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    प्रति (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        यदि (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL && !op->is_memory) {
            प्रति (reg = 0; reg <= 8; reg++) {
                यदि (!(regs_allocated[reg] & REG_OUT_MASK))
                    गच्छ reg_found2;
            }
            tcc_error("could not find free output register for reloading");
          reg_found2:
            *pout_reg = reg;
            भङ्ग;
        }
    }

    /* print sorted constraints */
#ifdef ASM_DEBUG
    प्रति (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        printf("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, रिक्त) : "",
               op->constraint, op->vt->r, op->reg);
    }
    यदि (*pout_reg >= 0)
        printf("out_reg=%d\n", *pout_reg);
#endif
}

ST_FUNC शून्य asm_clobber(uint8_t *clobber_regs, ध्रुव वर्ण *str)
{
    पूर्णाङ्क reg;
    TokenSym *ts;

    यदि (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        प्रत्यागम;
    ts = tok_alloc(str, strlen(str));
    reg = asm_parse_regvar(ts->tok);
    यदि (reg == -1) {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}

/* If T refers to a register then return the register number and type.
   Otherwise return -1.  */
ST_FUNC पूर्णाङ्क asm_parse_regvar (पूर्णाङ्क t)
{
    /* coprocessors (p0-p15) and coprocessor registers (c0-c15) are handled elsewere */
    /* single fp (s0-s31) and double fp registers (d0-d15) are handled elsewere */

    यदि (t < TOK_ASM_r0 || t > TOK_ASM_pc) /* filter unrelated registers */
        प्रत्यागम -1;

    यदि (t <= TOK_ASM_r15)       /* default register names r0-r15 */
        प्रत्यागम t - TOK_ASM_r0;

    यदि (t <= TOK_ASM_v8)        /* synonym register names a1-a4,v1-v8 (alias: r0-r11) */
        प्रत्यागम t - TOK_ASM_a1;

    /* special register names sb/sl/fp/ip/sp/lr/pc (alias: r9-r15) */
    प्रत्यागम t - TOK_ASM_sb + (TOK_ASM_r9 - TOK_ASM_r0);
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */

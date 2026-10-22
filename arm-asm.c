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

#अगर_घोषित TARGET_DEFS_ONLY

#घोषणा CONFIG_TCC_ASM
#घोषणा NB_ASM_REGS 16

ST_FUNC व्योम g(पूर्णांक c);
ST_FUNC व्योम gen_le16(पूर्णांक c);
ST_FUNC व्योम gen_le32(पूर्णांक c);

/*************************************************************/
#अन्यथा
/*************************************************************/

#घोषणा USING_GLOBALS
#समावेश "tcc.h"

क्रमागत {
    OPT_REG32,
    OPT_REGSET32,
    OPT_IM8,
    OPT_IM8N,
    OPT_IM32,
    OPT_VREG32,
    OPT_VREG64,
};
#घोषणा OP_REG32  (1 << OPT_REG32)
#घोषणा OP_VREG32 (1 << OPT_VREG32)
#घोषणा OP_VREG64 (1 << OPT_VREG64)
#घोषणा OP_REG    (OP_REG32 | OP_VREG32 | OP_VREG64)
#घोषणा OP_IM32   (1 << OPT_IM32)
#घोषणा OP_IM8   (1 << OPT_IM8)
#घोषणा OP_IM8N   (1 << OPT_IM8N)
#घोषणा OP_REGSET32  (1 << OPT_REGSET32)

प्रकार काष्ठा Operand {
    uint32_t type;
    जोड़ {
        uint8_t reg;
        uint16_t regset;
        व्यंजक_मूल्य e;
    };
} Operand;

/* Read the VFP register referred to by token T.
   If OK, returns its number.
   If not OK, returns -1. */
अटल पूर्णांक asm_parse_vfp_regvar(पूर्णांक t, पूर्णांक double_precision)
{
    अगर (double_precision) {
        अगर (t >= TOK_ASM_d0 && t <= TOK_ASM_d15)
            वापस t - TOK_ASM_d0;
    } अन्यथा {
        अगर (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
            वापस t - TOK_ASM_s0;
    }
    वापस -1;
}

/* Parse a text containing operand and store the result in OP */
अटल व्योम parse_operand(TCCState *s1, Operand *op)
{
    व्यंजक_मूल्य e;
    int8_t reg;
    uint16_t regset = 0;

    op->type = 0;

    अगर (tok == '{') { // regset literal
        अग्र(); // skip '{'
        जबतक (tok != '}' && tok != TOK_EOF) {
            reg = asm_parse_regvar(tok);
            अगर (reg == -1) {
                expect("register");
            } अन्यथा
                अग्र(); // skip register name

            अगर ((1 << reg) < regset)
                tcc_warning("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
            regset |= 1 << reg;
            अगर (tok != ',')
                अवरोध;
            अग्र(); // skip ','
        }
        skip('}');
        अगर (regset == 0) {
            // ARM instructions don't support empty regset.
            tcc_error("empty register list is not supported");
        } अन्यथा {
            op->type = OP_REGSET32;
            op->regset = regset;
        }
        वापस;
    } अन्यथा अगर ((reg = asm_parse_regvar(tok)) != -1) {
        अग्र(); // skip register name
        op->type = OP_REG32;
        op->reg = (uint8_t) reg;
        वापस;
    } अन्यथा अगर ((reg = asm_parse_vfp_regvar(tok, 0)) != -1) {
        अग्र(); // skip register name
        op->type = OP_VREG32;
        op->reg = (uint8_t) reg;
        वापस;
    } अन्यथा अगर ((reg = asm_parse_vfp_regvar(tok, 1)) != -1) {
        अग्र(); // skip register name
        op->type = OP_VREG64;
        op->reg = (uint8_t) reg;
        वापस;
    } अन्यथा अगर (tok == '#' || tok == '$') {
        /* constant value */
        अग्र(); // skip '#' or '$'
    }
    asm_व्यंजक(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    अगर (!op->e.sym) {
        अगर ((पूर्णांक) op->e.v < 0 && (पूर्णांक) op->e.v >= -255)
            op->type = OP_IM8N;
        अन्यथा अगर (op->e.v == (uint8_t)op->e.v)
            op->type = OP_IM8;
    } अन्यथा
        expect("operand");
}

/* XXX: make it faster ? */
ST_FUNC व्योम g(पूर्णांक c)
{
    पूर्णांक ind1;
    अगर (nocode_wanted)
        वापस;
    ind1 = ind + 1;
    अगर (ind1 > cur_text_section->तथ्य_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->तथ्य[ind] = c;
    ind = ind1;
}

ST_FUNC व्योम gen_le16 (पूर्णांक i)
{
    g(i);
    g(i>>8);
}

ST_FUNC व्योम gen_le32 (पूर्णांक i)
{
    पूर्णांक ind1;
    अगर (nocode_wanted)
        वापस;
    ind1 = ind + 4;
    अगर (ind1 > cur_text_section->तथ्य_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->तथ्य[ind++] = i & 0xFF;
    cur_text_section->तथ्य[ind++] = (i >> 8) & 0xFF;
    cur_text_section->तथ्य[ind++] = (i >> 16) & 0xFF;
    cur_text_section->तथ्य[ind++] = (i >> 24) & 0xFF;
}

ST_FUNC व्योम gen_expr32(व्यंजक_मूल्य *pe)
{
    gen_le32(pe->v);
}

अटल uint32_t condition_code_of_token(पूर्णांक token) {
    अगर (token < TOK_ASM_nopeq) {
        expect("condition-enabled instruction");
    } अन्यथा
        वापस (token - TOK_ASM_nopeq) & 15;
}

अटल व्योम asm_emit_opcode(पूर्णांक token, uint32_t opcode) {
    gen_le32((condition_code_of_token(token) << 28) | opcode);
}

अटल व्योम asm_emit_unconditional_opcode(uint32_t opcode) {
    gen_le32(opcode);
}

अटल व्योम asm_emit_coprocessor_opcode(uint32_t ऊपरी_nibble, uint8_t cp_संख्या, uint8_t cp_opcode, uint8_t cp_destination_register, uint8_t cp_n_operand_register, uint8_t cp_m_operand_register, uint8_t cp_opcode2, पूर्णांक inter_processor_transfer)
{
    uint32_t opcode = 0xe000000;
    अगर (inter_processor_transfer)
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
    asm_emit_unconditional_opcode((ऊपरी_nibble << 28) | opcode);
}

अटल व्योम asm_nullary_opcode(पूर्णांक token)
{
    चयन (ARM_INSTRUCTION_GROUP(token)) {
    हाल TOK_ASM_nopeq:
        asm_emit_opcode(token, 0xd << 21); // mov r0, r0
        अवरोध;
    हाल TOK_ASM_wfeeq:
        asm_emit_opcode(token, 0x320f002);
    हाल TOK_ASM_wfieq:
        asm_emit_opcode(token, 0x320f003);
        अवरोध;
    शेष:
        expect("nullary instruction");
    }
}

अटल व्योम asm_unary_opcode(TCCState *s1, पूर्णांक token)
{
    Operand op;
    parse_operand(s1, &op);

    चयन (ARM_INSTRUCTION_GROUP(token)) {
    हाल TOK_ASM_swieq:
    हाल TOK_ASM_svceq:
        अगर (op.type != OP_IM8)
            expect("immediate 8-bit unsigned integer");
        अन्यथा {
            /* Note: Dummy operand (ignored by processor): ARM ref documented 0...255, ARM instruction set documented 24 bit */
            asm_emit_opcode(token, (0xf << 24) | op.e.v);
        }
        अवरोध;
    शेष:
        expect("unary instruction");
    }
}

अटल व्योम asm_द्विआधारी_opcode(TCCState *s1, पूर्णांक token)
{
    Operand ops[2];
    Operand rotation;
    uint32_t encoded_rotation = 0;
    uint64_t amount;
    parse_operand(s1, &ops[0]);
    skip(',');
    parse_operand(s1, &ops[1]);
    अगर (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    }

    अगर (ops[0].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, शून्य));
    }

    अगर (ops[0].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, शून्य));

    अगर (ops[1].type != OP_REG32) {
        चयन (ARM_INSTRUCTION_GROUP(token)) {
        हाल TOK_ASM_movteq:
        हाल TOK_ASM_movweq:
            अगर (ops[1].type == OP_IM8 || ops[1].type == OP_IM8N || ops[1].type == OP_IM32) {
                अगर (ops[1].e.v >= 0 && ops[1].e.v <= 0xFFFF) {
                    uint16_t immediate_मूल्य = ops[1].e.v;
                    चयन (ARM_INSTRUCTION_GROUP(token)) {
                    हाल TOK_ASM_movteq:
                        asm_emit_opcode(token, 0x3400000 | (ops[0].reg << 12) | (immediate_मूल्य & 0xF000) << 4 | (immediate_मूल्य & 0xFFF));
                        अवरोध;
                    हाल TOK_ASM_movweq:
                        asm_emit_opcode(token, 0x3000000 | (ops[0].reg << 12) | (immediate_मूल्य & 0xF000) << 4 | (immediate_मूल्य & 0xFFF));
                        अवरोध;
                    }
                } अन्यथा
                    expect("(source operand) immediate 16 bit value");
            } अन्यथा
                expect("(source operand) immediate");
            अवरोध;
        शेष:
            expect("(source operand) register");
        }
        वापस;
    }

    अगर (ops[1].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, शून्य));
    }

    अगर (ops[1].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, शून्य));

    अगर (tok == ',') {
        अग्र(); // skip ','
        अगर (tok == TOK_ASM_ror) {
            अग्र(); // skip 'ror'
            parse_operand(s1, &rotation);
            अगर (rotation.type != OP_IM8) {
                expect("immediate value for rotation");
            } अन्यथा {
                amount = rotation.e.v;
                चयन (amount) {
                हाल 8:
                    encoded_rotation = 1 << 10;
                    अवरोध;
                हाल 16:
                    encoded_rotation = 2 << 10;
                    अवरोध;
                हाल 24:
                    encoded_rotation = 3 << 10;
                    अवरोध;
                शेष:
                    expect("'8' or '16' or '24'");
                }
            }
        }
    }
    चयन (ARM_INSTRUCTION_GROUP(token)) {
    हाल TOK_ASM_clzeq:
        अगर (encoded_rotation)
            tcc_error("clz does not support rotation");
        asm_emit_opcode(token, 0x16f0f10 | (ops[0].reg << 12) | ops[1].reg);
        अवरोध;
    हाल TOK_ASM_sxtbeq:
        asm_emit_opcode(token, 0x6af0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        अवरोध;
    हाल TOK_ASM_sxtheq:
        asm_emit_opcode(token, 0x6bf0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        अवरोध;
    हाल TOK_ASM_uxtbeq:
        asm_emit_opcode(token, 0x6ef0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        अवरोध;
    हाल TOK_ASM_uxtheq:
        asm_emit_opcode(token, 0x6ff0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        अवरोध;
    शेष:
        expect("binary instruction");
    }
}

अटल व्योम asm_coprocessor_opcode(TCCState *s1, पूर्णांक token) {
    uint8_t coprocessor;
    Operand opcode1;
    Operand opcode2;
    uint8_t registers[3];
    अचिन्हित पूर्णांक i;
    uint8_t ऊपरी_nibble;
    uint8_t mrc = 0;

    अगर (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        अग्र();
    } अन्यथा {
        expect("'p<number>'");
    }
    skip(',');
    parse_operand(s1, &opcode1);
    अगर (opcode1.type != OP_IM8 || opcode1.e.v > 15) {
        tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, शून्य));
    }

    क्रम (i = 0; i < 3; ++i) {
        skip(',');
        अगर (i == 0 && token != TOK_ASM_cdp2 && (ARM_INSTRUCTION_GROUP(token) == TOK_ASM_mrceq || ARM_INSTRUCTION_GROUP(token) == TOK_ASM_mcreq)) {
            अगर (tok >= TOK_ASM_r0 && tok <= TOK_ASM_pc) {
                registers[i] = asm_parse_regvar(tok);
                अग्र();
            } अन्यथा {
                expect("'r<number>'");
            }
        } अन्यथा {
            अगर (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
                registers[i] = tok - TOK_ASM_c0;
                अग्र();
            } अन्यथा {
                expect("'c<number>'");
            }
        }
    }
    अगर (tok == ',') {
        अग्र();
        parse_operand(s1, &opcode2);
    } अन्यथा {
        opcode2.type = OP_IM8;
        opcode2.e.v = 0;
    }
    अगर (opcode2.type != OP_IM8 || opcode2.e.v > 15) {
        tcc_error("opcode2 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, शून्य));
    }

    अगर (token == TOK_ASM_cdp2) {
        ऊपरी_nibble = 0xF;
        asm_emit_coprocessor_opcode(ऊपरी_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        वापस;
    } अन्यथा
        ऊपरी_nibble = condition_code_of_token(token);

    चयन (ARM_INSTRUCTION_GROUP(token)) {
    हाल TOK_ASM_cdpeq:
        asm_emit_coprocessor_opcode(ऊपरी_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        अवरोध;
    हाल TOK_ASM_mrceq:
        // opcode1 encoding changes! highest and lowest bit gone.
        mrc = 1;
        /* fallthrough */
    हाल TOK_ASM_mcreq:
        // opcode1 encoding changes! highest and lowest bit gone.
        अगर (opcode1.e.v > 7) {
            tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 7", get_tok_str(token, शून्य));
        }
        asm_emit_coprocessor_opcode(ऊपरी_nibble, coprocessor, (opcode1.e.v << 1) | mrc, registers[0], registers[1], registers[2], opcode2.e.v, 1);
        अवरोध;
    शेष:
        expect("known instruction");
    }
}

/* data processing and single data transfer instructions only */
#घोषणा ENCODE_RN(register_सूचकांक) ((register_सूचकांक) << 16)
#घोषणा ENCODE_RD(register_सूचकांक) ((register_सूचकांक) << 12)
#घोषणा ENCODE_SET_CONDITION_CODES (1 << 20)

/* Note: For data processing instructions, "1" means immediate.
   Note: For single data transfer instructions, "0" means immediate. */
#घोषणा ENCODE_IMMEDIATE_FLAG (1 << 25)

#घोषणा ENCODE_BARREL_SHIFTER_SHIFT_BY_REGISTER (1 << 4)
#घोषणा ENCODE_BARREL_SHIFTER_MODE_LSL (0 << 5)
#घोषणा ENCODE_BARREL_SHIFTER_MODE_LSR (1 << 5)
#घोषणा ENCODE_BARREL_SHIFTER_MODE_ASR (2 << 5)
#घोषणा ENCODE_BARREL_SHIFTER_MODE_ROR (3 << 5)
#घोषणा ENCODE_BARREL_SHIFTER_REGISTER(register_सूचकांक) ((register_सूचकांक) << 8)
#घोषणा ENCODE_BARREL_SHIFTER_IMMEDIATE(मूल्य) ((मूल्य) << 7)

अटल व्योम asm_block_तथ्य_transfer_opcode(TCCState *s1, पूर्णांक token)
{
    uint32_t opcode;
    पूर्णांक op0_exclam = 0;
    Operand ops[2];
    पूर्णांक nb_ops = 1;
    parse_operand(s1, &ops[0]);
    अगर (tok == '!') {
        op0_exclam = 1;
        अग्र(); // skip '!'
    }
    अगर (tok == ',') {
        अग्र(); // skip comma
        parse_operand(s1, &ops[1]);
        ++nb_ops;
    }
    अगर (nb_ops < 1) {
        expect("at least one operand");
    } अन्यथा अगर (ops[nb_ops - 1].type != OP_REGSET32) {
        expect("(last operand) register list");
    }

    // block data transfer: 1 0 0 P U S W L << 20 (general case):
    // operands:
    //   Rn: bits 19...16 base register
    //   Register List: bits 15...0

    चयन (ARM_INSTRUCTION_GROUP(token)) {
    हाल TOK_ASM_pusheq: // TODO: Optimize 1-register case to: str ?, [sp, #-4]!
        // Instruction: 1 I=0 P=1 U=0 S=0 W=1 L=0 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        अगर (nb_ops != 1)
            expect("exactly one operand");
        अन्यथा
            asm_emit_opcode(token, (0x92d << 16) | ops[0].regset); // TODO: base register ?
        अवरोध;
    हाल TOK_ASM_popeq: // TODO: Optimize 1-register case to: ldr ?, [sp], #4
        // Instruction: 1 I=0 P=0 U=1 S=0 W=0 L=1 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        अगर (nb_ops != 1)
            expect("exactly one operand");
        अन्यथा
            asm_emit_opcode(token, (0x8bd << 16) | ops[0].regset); // TODO: base register ?
        अवरोध;
    हाल TOK_ASM_stmdaeq:
    हाल TOK_ASM_ldmdaeq:
    हाल TOK_ASM_stmeq:
    हाल TOK_ASM_ldmeq:
    हाल TOK_ASM_stmiaeq:
    हाल TOK_ASM_ldmiaeq:
    हाल TOK_ASM_stmdbeq:
    हाल TOK_ASM_ldmdbeq:
    हाल TOK_ASM_stmibeq:
    हाल TOK_ASM_ldmibeq:
        चयन (ARM_INSTRUCTION_GROUP(token)) {
        हाल TOK_ASM_stmdaeq: // post-decrement store
            opcode = 0x80 << 20;
            अवरोध;
        हाल TOK_ASM_ldmdaeq: // post-decrement load
            opcode = 0x81 << 20;
            अवरोध;
        हाल TOK_ASM_stmeq: // post-increment store
        हाल TOK_ASM_stmiaeq: // post-increment store
            opcode = 0x88 << 20;
            अवरोध;
        हाल TOK_ASM_ldmeq: // post-increment load
        हाल TOK_ASM_ldmiaeq: // post-increment load
            opcode = 0x89 << 20;
            अवरोध;
        हाल TOK_ASM_stmdbeq: // pre-decrement store
            opcode = 0x90 << 20;
            अवरोध;
        हाल TOK_ASM_ldmdbeq: // pre-decrement load
            opcode = 0x91 << 20;
            अवरोध;
        हाल TOK_ASM_stmibeq: // pre-increment store
            opcode = 0x98 << 20;
            अवरोध;
        हाल TOK_ASM_ldmibeq: // pre-increment load
            opcode = 0x99 << 20;
            अवरोध;
        शेष:
            tcc_error("internal error: This place should not be reached (fallback in asm_block_data_transfer_opcode)");
        }
        // operands:
        //    Rn: first operand
        //    Register List: lower bits
        अगर (nb_ops != 2)
            expect("exactly two operands");
        अन्यथा अगर (ops[0].type != OP_REG32)
            expect("(first operand) register");
        अन्यथा {
            अगर (op0_exclam)
                opcode |= 1 << 21; // writeback
            asm_emit_opcode(token, opcode | ENCODE_RN(ops[0].reg) | ops[1].regset);
        }
        अवरोध;
    शेष:
        expect("block data transfer instruction");
    }
}

/* Parses shift directive and returns the parts that would have to be set in the opcode because of it.
   Does not encode the actual shift amount.
   It's not an error if there is no shift directive.

   NB_SHIFT: will be set to 1 iff SHIFT is filled.  Note that for rrx, there's no need to fill SHIFT.
   SHIFT: will be filled in with the shift operand to use, if any. */
अटल uint32_t asm_parse_optional_shift(TCCState* s1, पूर्णांक* nb_shift, Operand* shift)
{
    uint32_t opcode = 0;
    *nb_shift = 0;
    चयन (tok) {
    हाल TOK_ASM_asl:
    हाल TOK_ASM_lsl:
    हाल TOK_ASM_asr:
    हाल TOK_ASM_lsr:
    हाल TOK_ASM_ror:
        चयन (tok) {
        हाल TOK_ASM_asl:
            /* fallthrough */
        हाल TOK_ASM_lsl:
            opcode = ENCODE_BARREL_SHIFTER_MODE_LSL;
            अवरोध;
        हाल TOK_ASM_asr:
            opcode = ENCODE_BARREL_SHIFTER_MODE_ASR;
            अवरोध;
        हाल TOK_ASM_lsr:
            opcode = ENCODE_BARREL_SHIFTER_MODE_LSR;
            अवरोध;
        हाल TOK_ASM_ror:
            opcode = ENCODE_BARREL_SHIFTER_MODE_ROR;
            अवरोध;
        }
        अग्र();
        parse_operand(s1, shift);
        *nb_shift = 1;
        अवरोध;
    हाल TOK_ASM_rrx:
        अग्र();
        opcode = ENCODE_BARREL_SHIFTER_MODE_ROR;
        अवरोध;
    }
    वापस opcode;
}

अटल uint32_t asm_encode_shift(Operand* shift)
{
    uint64_t amount;
    uint32_t operands = 0;
    चयन (shift->type) {
    हाल OP_REG32:
        अगर (shift->reg == 15)
            tcc_error("r15 cannot be used as a shift count");
        अन्यथा {
            operands = ENCODE_BARREL_SHIFTER_SHIFT_BY_REGISTER;
            operands |= ENCODE_BARREL_SHIFTER_REGISTER(shift->reg);
        }
        अवरोध;
    हाल OP_IM8:
        amount = shift->e.v;
        अगर (amount > 0 && amount < 32)
            operands = ENCODE_BARREL_SHIFTER_IMMEDIATE(amount);
        अन्यथा
            tcc_error("shift count out of range");
        अवरोध;
    शेष:
        tcc_error("unknown shift amount");
    }
    वापस operands;
}

अटल व्योम asm_तथ्य_processing_opcode(TCCState *s1, पूर्णांक token)
{
    Operand ops[3];
    पूर्णांक nb_ops;
    Operand shift = {0};
    पूर्णांक nb_shift = 0;
    uint32_t operands = 0;

    /* modulo 16 entries per instruction for the different condition codes */
    uint32_t opcode_idx = (ARM_INSTRUCTION_GROUP(token) - TOK_ASM_andeq) >> 4;
    uint32_t opcode_nos = opcode_idx >> 1; // without "s"; "OpCode" in ARM docs

    क्रम (nb_ops = 0; nb_ops < माप(ops)/माप(ops[0]); ) {
        अगर (tok == TOK_ASM_asl || tok == TOK_ASM_lsl || tok == TOK_ASM_lsr || tok == TOK_ASM_asr || tok == TOK_ASM_ror || tok == TOK_ASM_rrx)
            अवरोध;
        parse_operand(s1, &ops[nb_ops]);
        ++nb_ops;
        अगर (tok != ',')
            अवरोध;
        अग्र(); // skip ','
    }
    अगर (tok == ',')
        अग्र();
    operands |= asm_parse_optional_shift(s1, &nb_shift, &shift);
    अगर (nb_ops < 2)
        expect("at least two operands");
    अन्यथा अगर (nb_ops == 2) {
        स_नकल(&ops[2], &ops[1], माप(ops[1])); // move ops[2]
        स_नकल(&ops[1], &ops[0], माप(ops[0])); // ops[1] was implicit
        nb_ops = 3;
    } अन्यथा अगर (nb_ops == 3) {
        अगर (opcode_nos == 0xd || opcode_nos == 0xf || opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) { // mov, mvn, cmp, cmn, tst, teq
            tcc_error("'%s' cannot be used with three operands", get_tok_str(token, शून्य));
        }
    }
    अगर (nb_ops != 3) {
        expect("two or three operands");
    } अन्यथा {
        uint32_t opcode = 0;
        uint32_t immediate_मूल्य;
        uint8_t half_immediate_rotation;
        अगर (nb_shift && shift.type == OP_REG32) {
            अगर ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
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
        अगर (ops[0].type != OP_REG32)
            expect("(destination operand) register");
        अन्यथा अगर (opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) // cmp, cmn, tst, teq
            operands |= ENCODE_SET_CONDITION_CODES; // force S set, otherwise it's a completely different instruction.
        अन्यथा
            operands |= ENCODE_RD(ops[0].reg);
        अगर (ops[1].type != OP_REG32)
            expect("(first source operand) register");
        अन्यथा अगर (!(opcode_nos == 0xd || opcode_nos == 0xf)) // not: mov, mvn (those have only one source operand)
            operands |= ENCODE_RN(ops[1].reg);
        चयन (ops[2].type) {
        हाल OP_REG32:
            operands |= ops[2].reg;
            अवरोध;
        हाल OP_IM8:
        हाल OP_IM32:
            operands |= ENCODE_IMMEDIATE_FLAG;
            immediate_मूल्य = ops[2].e.v;
            क्रम (half_immediate_rotation = 0; half_immediate_rotation < 16; ++half_immediate_rotation) {
                अगर (immediate_मूल्य >= 0x00 && immediate_मूल्य < 0x100)
                    अवरोध;
                // rotate left by two
                immediate_मूल्य = ((immediate_मूल्य & 0x3FFFFFFF) << 2) | ((immediate_मूल्य & 0xC0000000) >> 30);
            }
            अगर (half_immediate_rotation >= 16) {
                /* fallthrough */
            } अन्यथा {
                operands |= immediate_मूल्य;
                operands |= half_immediate_rotation << 8;
                अवरोध;
            }
        हाल OP_IM8N: // immediate negative value
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
            चयन (opcode_nos) {
            हाल 0x0: // AND - Rd:= Op1 AND Op2
                opcode = 0xe << 21; // BIC
                immediate_मूल्य = ~immediate_मूल्य;
                अवरोध;
            हाल 0x2: // SUB - Rd:= Op1 - Op2
                opcode = 0x4 << 21; // ADD
                immediate_मूल्य = -immediate_मूल्य;
                अवरोध;
            हाल 0x4: // ADD - Rd:= Op1 + Op2
                opcode = 0x2 << 21; // SUB
                immediate_मूल्य = -immediate_मूल्य;
                अवरोध;
            हाल 0x5: // ADC - Rd:= Op1 + Op2 + C
                opcode = 0x6 << 21; // SBC
                immediate_मूल्य = ~immediate_मूल्य;
                अवरोध;
            हाल 0x6: // SBC - Rd:= Op1 - Op2 + C
                opcode = 0x5 << 21; // ADC
                immediate_मूल्य = ~immediate_मूल्य;
                अवरोध;
            हाल 0xa: // CMP - CC on: Op1 - Op2
                opcode = 0xb << 21; // CMN
                immediate_मूल्य = -immediate_मूल्य;
                अवरोध;
            हाल 0xb: // CMN - CC on: Op1 + Op2
                opcode = 0xa << 21; // CMP
                immediate_मूल्य = -immediate_मूल्य;
                अवरोध;
            हाल 0xd: // MOV - Rd:= Op2
                opcode = 0xf << 21; // MVN
                immediate_मूल्य = ~immediate_मूल्य;
                अवरोध;
            हाल 0xe: // BIC - Rd:= Op1 AND NOT Op2
                opcode = 0x0 << 21; // AND
                immediate_मूल्य = ~immediate_मूल्य;
                अवरोध;
            हाल 0xf: // MVN - Rd:= NOT Op2
                opcode = 0xd << 21; // MOV
                immediate_मूल्य = ~immediate_मूल्य;
                अवरोध;
            शेष:
                tcc_error("cannot use '%s' with a negative immediate value", get_tok_str(token, शून्य));
            }
            क्रम (half_immediate_rotation = 0; half_immediate_rotation < 16; ++half_immediate_rotation) {
                अगर (immediate_मूल्य >= 0x00 && immediate_मूल्य < 0x100)
                    अवरोध;
                // rotate left by two
                immediate_मूल्य = ((immediate_मूल्य & 0x3FFFFFFF) << 2) | ((immediate_मूल्य & 0xC0000000) >> 30);
            }
            अगर (half_immediate_rotation >= 16) {
                immediate_मूल्य = ops[2].e.v;
                tcc_error("immediate value 0x%X cannot be encoded into ARM immediate", (अचिन्हित) immediate_मूल्य);
            }
            operands |= immediate_मूल्य;
            operands |= half_immediate_rotation << 8;
            अवरोध;
        शेष:
            expect("(second source operand) register or immediate value");
        }

        अगर (nb_shift) {
            अगर (operands & ENCODE_IMMEDIATE_FLAG)
                tcc_error("immediate rotation not implemented");
            अन्यथा
                operands |= asm_encode_shift(&shift);
        }

        /* S=0 and S=1 entries alternate one after another, in that order */
        opcode |= (opcode_idx & 1) ? ENCODE_SET_CONDITION_CODES : 0;
        asm_emit_opcode(token, opcode | operands);
    }
}

अटल व्योम asm_shift_opcode(TCCState *s1, पूर्णांक token)
{
    Operand ops[3];
    पूर्णांक nb_ops;
    पूर्णांक definitely_neutral = 0;
    uint32_t opcode = 0xd << 21; // MOV
    uint32_t operands = 0;

    क्रम (nb_ops = 0; nb_ops < माप(ops)/माप(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        अगर (tok != ',') {
            ++nb_ops;
            अवरोध;
        }
        अग्र(); // skip ','
    }
    अगर (nb_ops < 2) {
        expect("at least two operands");
    }

    अगर (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    } अन्यथा
        operands |= ENCODE_RD(ops[0].reg);

    अगर (nb_ops == 2) {
        चयन (ARM_INSTRUCTION_GROUP(token)) {
        हाल TOK_ASM_rrxseq:
            opcode |= ENCODE_SET_CONDITION_CODES;
            /* fallthrough */
        हाल TOK_ASM_rrxeq:
            अगर (ops[1].type == OP_REG32) {
                operands |= ops[1].reg;
                operands |= ENCODE_BARREL_SHIFTER_MODE_ROR;
                asm_emit_opcode(token, opcode | operands);
            } अन्यथा
                tcc_error("(first source operand) register");
            वापस;
        शेष:
            स_नकल(&ops[2], &ops[1], माप(ops[1])); // move ops[2]
            स_नकल(&ops[1], &ops[0], माप(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
    }
    अगर (nb_ops != 3) {
        expect("two or three operands");
    }

    चयन (ARM_INSTRUCTION_GROUP(token)) {
    हाल TOK_ASM_lslseq:
    हाल TOK_ASM_lsrseq:
    हाल TOK_ASM_asrseq:
    हाल TOK_ASM_rorseq:
        opcode |= ENCODE_SET_CONDITION_CODES;
        अवरोध;
    }

    चयन (ops[1].type) {
    हाल OP_REG32:
        operands |= ops[1].reg;
        अवरोध;
    हाल OP_IM8:
        operands |= ENCODE_IMMEDIATE_FLAG;
        operands |= ops[1].e.v;
        tcc_error("Using an immediate value as the source operand is not possible with '%s' instruction on ARM", get_tok_str(token, शून्य));
    }

    चयन (ops[2].type) {
    हाल OP_REG32:
        अगर ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
            (ops[1].type == OP_REG32 && ops[1].reg == 15)) {
            tcc_error("Using the 'pc' register in data processing instructions that have a register-controlled shift is not implemented by ARM");
        }
        operands |= asm_encode_shift(&ops[2]);
        अवरोध;
    हाल OP_IM8:
        अगर (ops[2].e.v)
            operands |= asm_encode_shift(&ops[2]);
        अन्यथा
            definitely_neutral = 1;
        अवरोध;
    }

    अगर (!definitely_neutral) चयन (ARM_INSTRUCTION_GROUP(token)) {
    हाल TOK_ASM_lslseq:
    हाल TOK_ASM_lsleq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_LSL;
        अवरोध;
    हाल TOK_ASM_lsrseq:
    हाल TOK_ASM_lsreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_LSR;
        अवरोध;
    हाल TOK_ASM_asrseq:
    हाल TOK_ASM_asreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_ASR;
        अवरोध;
    हाल TOK_ASM_rorseq:
    हाल TOK_ASM_roreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_ROR;
        अवरोध;
    शेष:
        expect("shift instruction");
    }
    asm_emit_opcode(token, opcode | operands);
}

अटल व्योम asm_multiplication_opcode(TCCState *s1, पूर्णांक token)
{
    Operand ops[4];
    पूर्णांक nb_ops = 0;
    uint32_t opcode = 0x90;

    क्रम (nb_ops = 0; nb_ops < माप(ops)/माप(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        अगर (tok != ',') {
            ++nb_ops;
            अवरोध;
        }
        अग्र(); // skip ','
    }
    अगर (nb_ops < 2)
        expect("at least two operands");
    अन्यथा अगर (nb_ops == 2) {
        चयन (ARM_INSTRUCTION_GROUP(token)) {
        हाल TOK_ASM_mulseq:
        हाल TOK_ASM_muleq:
            स_नकल(&ops[2], &ops[0], माप(ops[1])); // ARM is actually like this!
            अवरोध;
        शेष:
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

    अगर (ops[0].type == OP_REG32)
        opcode |= ops[0].reg << 16;
    अन्यथा
        expect("(destination operand) register");
    अगर (ops[1].type == OP_REG32)
        opcode |= ops[1].reg;
    अन्यथा
        expect("(first source operand) register");
    अगर (ops[2].type == OP_REG32)
        opcode |= ops[2].reg << 8;
    अन्यथा
        expect("(second source operand) register");
    अगर (nb_ops > 3) {
        अगर (ops[3].type == OP_REG32)
            opcode |= ops[3].reg << 12;
        अन्यथा
            expect("(third source operand) register");
    }

    चयन (ARM_INSTRUCTION_GROUP(token)) {
    हाल TOK_ASM_mulseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    हाल TOK_ASM_muleq:
        अगर (nb_ops != 3)
            expect("three operands");
        अन्यथा {
            asm_emit_opcode(token, opcode);
        }
        अवरोध;
    हाल TOK_ASM_mlaseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    हाल TOK_ASM_mlaeq:
    case_TOK_ASM_mlaeq:
        अगर (nb_ops != 4)
            expect("four operands");
        अन्यथा {
            opcode |= 1 << 21; // Accumulate
            asm_emit_opcode(token, opcode);
        }
        अवरोध;
    हाल TOK_ASM_mlseq:
        opcode |= 0x00400000;
        जाओ case_TOK_ASM_mlaeq;
    हाल TOK_ASM_udiveq:
        opcode |= 0x00200000;
    हाल TOK_ASM_sdiveq:
        asm_emit_opcode(token, (opcode & ~0x80) | 0x0710f010);
        अवरोध;
    शेष:
        expect("known multiplication instruction");
    }
}

अटल व्योम asm_long_multiplication_opcode(TCCState *s1, पूर्णांक token)
{
    Operand ops[4];
    पूर्णांक nb_ops = 0;
    uint32_t opcode = 0x90 | (1 << 23);

    क्रम (nb_ops = 0; nb_ops < माप(ops)/माप(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        अगर (tok != ',') {
            ++nb_ops;
            अवरोध;
        }
        अग्र(); // skip ','
    }
    अगर (nb_ops != 4) {
        expect("four operands");
    }

    // long multiply (special case):
    // operands:
    //   RdLo: bits 15...12
    //   RdHi: bits 19...16
    //   Rs: bits 11...8
    //   Rm: bits 3...0

    अगर (ops[0].type == OP_REG32)
        opcode |= ops[0].reg << 12;
    अन्यथा
        expect("(destination lo accumulator) register");
    अगर (ops[1].type == OP_REG32)
        opcode |= ops[1].reg << 16;
    अन्यथा
        expect("(destination hi accumulator) register");
    अगर (ops[2].type == OP_REG32)
        opcode |= ops[2].reg;
    अन्यथा
        expect("(first source operand) register");
    अगर (ops[3].type == OP_REG32)
        opcode |= ops[3].reg << 8;
    अन्यथा
        expect("(second source operand) register");

    चयन (ARM_INSTRUCTION_GROUP(token)) {
    हाल TOK_ASM_smullseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    हाल TOK_ASM_smulleq:
        opcode |= 1 << 22; // signed
        asm_emit_opcode(token, opcode);
        अवरोध;
    हाल TOK_ASM_umullseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    हाल TOK_ASM_umulleq:
        asm_emit_opcode(token, opcode);
        अवरोध;
    हाल TOK_ASM_smlalseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    हाल TOK_ASM_smlaleq:
        opcode |= 1 << 22; // signed
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        अवरोध;
    हाल TOK_ASM_umlalseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    हाल TOK_ASM_umlaleq:
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        अवरोध;
    शेष:
        expect("known long multiplication instruction");
    }
}

अटल व्योम asm_single_तथ्य_transfer_opcode(TCCState *s1, पूर्णांक token)
{
    Operand ops[3];
    Operand strex_operand;
    Operand shift;
    पूर्णांक nb_shift = 0;
    पूर्णांक exclam = 0;
    पूर्णांक closed_bracket = 0;
    पूर्णांक op2_minus = 0;
    uint32_t opcode = 0;
    // Note: ldr r0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: ldr r0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: ldr r0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_operand(s1, &ops[0]);
    अगर (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    अन्यथा {
        expect("(destination operand) register");
    }
    अगर (tok != ',')
        expect("at least two arguments");
    अग्र(); // skip ','

    चयन (ARM_INSTRUCTION_GROUP(token)) {
    हाल TOK_ASM_strexheq:
    हाल TOK_ASM_strexbeq:
    हाल TOK_ASM_strexeq:
        parse_operand(s1, &strex_operand);
        अगर (strex_operand.type != OP_REG32) {
            expect("register");
        }
        अगर (tok != ',')
            expect("at least three arguments");
        अन्यथा
            अग्र(); // skip ','
        अवरोध;
    }

    skip('[');
    parse_operand(s1, &ops[1]);
    अगर (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    अन्यथा {
        expect("(first source operand) register");
    }
    अगर (tok == ']') {
        अग्र();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    अगर (tok == ',') {
        अग्र(); // skip ','
        अगर (tok == '-') {
            op2_minus = 1;
            अग्र();
        }
        parse_operand(s1, &ops[2]);
        अगर (ops[2].type == OP_REG32) {
            अगर (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, शून्य));
            }
            अगर (tok == ',') {
                अग्र();
                opcode |= asm_parse_optional_shift(s1, &nb_shift, &shift);
                अगर (opcode == 0)
                    expect("shift directive, or no comma");
            }
        }
    } अन्यथा {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        opcode |= 1 << 24; // add offset before transfer
    }
    अगर (!closed_bracket) {
        skip(']');
        opcode |= 1 << 24; // add offset before transfer
        अगर (tok == '!') {
            exclam = 1;
            अग्र(); // skip '!'
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
    अगर (exclam)
        opcode |= 1 << 21; // write offset back into register

    अगर (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        पूर्णांक v = ops[2].e.v;
        अगर (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        अगर (v >= 0) {
            opcode |= 1 << 23; // up
            अगर (v >= 0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, शून्य));
            अन्यथा
                opcode |= v;
        } अन्यथा { // down
            अगर (v <= -0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, शून्य));
            अन्यथा
                opcode |= -v;
        }
    } अन्यथा अगर (ops[2].type == OP_REG32) {
        अगर (!op2_minus)
            opcode |= 1 << 23; // up
        opcode |= ENCODE_IMMEDIATE_FLAG; /* if set, it means it's NOT immediate */
        opcode |= ops[2].reg;
    } अन्यथा
        expect("register");

    चयन (ARM_INSTRUCTION_GROUP(token)) {
    हाल TOK_ASM_strbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    हाल TOK_ASM_streq:
        opcode |= 1 << 26; // Load/Store
        अगर (nb_shift)
            opcode |= asm_encode_shift(&shift);
        asm_emit_opcode(token, opcode);
        अवरोध;
    हाल TOK_ASM_ldrbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    हाल TOK_ASM_ldreq:
        opcode |= 1 << 20; // L
        opcode |= 1 << 26; // Load/Store
        अगर (nb_shift)
            opcode |= asm_encode_shift(&shift);
        asm_emit_opcode(token, opcode);
        अवरोध;
    हाल TOK_ASM_strexheq:
        opcode |= 1 << 21;
    हाल TOK_ASM_strexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    हाल TOK_ASM_strexeq:
        अगर ((opcode & 0xFFF) || nb_shift) {
            tcc_error("neither offset nor shift allowed with 'strex'");
        } अन्यथा अगर (opcode & ENCODE_IMMEDIATE_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'strex'");
        }
        अगर ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'strex'");
        }

        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        opcode |= strex_operand.reg;
        asm_emit_opcode(token, opcode);
        अवरोध;
    हाल TOK_ASM_ldrexheq:
        opcode |= 1 << 21;
    हाल TOK_ASM_ldrexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    हाल TOK_ASM_ldrexeq:
        अगर ((opcode & 0xFFF) || nb_shift) {
            tcc_error("neither offset nor shift allowed with 'ldrex'");
        } अन्यथा अगर (opcode & ENCODE_IMMEDIATE_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'ldrex'");
        }
        अगर ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'ldrex'");
        }
        opcode |= 1 << 20; // L
        opcode |= 0x00f;
        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        asm_emit_opcode(token, opcode);
        अवरोध;
    शेष:
        expect("data transfer instruction");
    }
}

// Note: Only call this using a VFP register if you know exactly what you are doing (i.e. cp_number is 10 or 11 and you are doing a vmov)
अटल व्योम asm_emit_coprocessor_तथ्य_transfer(uint32_t ऊपरी_nibble, uint8_t cp_संख्या, uint8_t CRd, स्थिर Operand* Rn, स्थिर Operand* offset, पूर्णांक offset_minus, पूर्णांक preincrement, पूर्णांक writeback, पूर्णांक long_transfer, पूर्णांक load) {
    uint32_t opcode = 0x0;
    opcode |= 1 << 26; // Load/Store
    opcode |= 1 << 27; // coprocessor

    अगर (long_transfer)
        opcode |= 1 << 22; // long transfer

    अगर (load)
        opcode |= 1 << 20; // L

    opcode |= cp_संख्या << 8;

    //assert(CRd < 16);
    opcode |= ENCODE_RD(CRd);

    अगर (Rn->type != OP_REG32)
        expect("register");

    //assert(Rn->reg < 16);
    opcode |= ENCODE_RN(Rn->reg);
    अगर (preincrement)
        opcode |= 1 << 24; // add offset before transfer

    अगर (writeback)
        opcode |= 1 << 21; // write offset back into register

    अगर (offset->type == OP_IM8 || offset->type == OP_IM8N || offset->type == OP_IM32) {
        पूर्णांक v = offset->e.v;
        अगर (offset_minus)
            tcc_error("minus before '#' not supported for immediate values");
        अगर (offset->type == OP_IM8N || v < 0)
            v = -v;
        अन्यथा
            opcode |= 1 << 23; // up
        अगर (v & 3) {
            tcc_error("immediate offset must be a multiple of 4");
        }
        v >>= 2;
        अगर (v > 255) {
            tcc_error("immediate offset must be between -1020 and 1020");
        }
        opcode |= v;
    } अन्यथा अगर (offset->type == OP_REG32) {
        अगर (!offset_minus)
            opcode |= 1 << 23; // up
        opcode |= ENCODE_IMMEDIATE_FLAG; /* if set, it means it's NOT immediate */
        opcode |= offset->reg;
        tcc_error("Using register offset to register address is not possible here");
    } अन्यथा अगर (offset->type == OP_VREG64) {
        opcode |= 16;
        opcode |= offset->reg;
    } अन्यथा
        expect("immediate or register");

    asm_emit_unconditional_opcode((ऊपरी_nibble << 28) | opcode);
}

// Almost exactly the same as asm_single_data_transfer_opcode.
// Difference: Offsets are smaller and multiples of 4; no shifts, no STREX, ENCODE_IMMEDIATE_FLAG is inverted again.
अटल व्योम asm_coprocessor_तथ्य_transfer_opcode(TCCState *s1, पूर्णांक token)
{
    Operand ops[3];
    uint8_t coprocessor;
    uint8_t coprocessor_destination_register;
    पूर्णांक preincrement = 0;
    पूर्णांक exclam = 0;
    पूर्णांक closed_bracket = 0;
    पूर्णांक op2_minus = 0;
    पूर्णांक long_transfer = 0;
    // Note: ldc p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: ldc p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: ldc p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    अगर (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        अग्र();
    } अन्यथा {
        expect("'c<number>'");
    }

    skip(',');

    अगर (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
        coprocessor_destination_register = tok - TOK_ASM_c0;
        अग्र();
    } अन्यथा {
        expect("'c<number>'");
    }

    skip(',');
    skip('[');
    parse_operand(s1, &ops[1]);
    अगर (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    अगर (tok == ']') {
        अग्र();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    अगर (tok == ',') {
        अग्र(); // skip ','
        अगर (tok == '-') {
            op2_minus = 1;
            अग्र();
        }
        parse_operand(s1, &ops[2]);
        अगर (ops[2].type == OP_REG32) {
            अगर (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, शून्य));
            }
        } अन्यथा अगर (ops[2].type == OP_VREG64) {
            tcc_error("'%s' does not support VFP register operand", get_tok_str(token, शून्य));
        }
    } अन्यथा {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        preincrement = 1; // add offset before transfer
    }
    अगर (!closed_bracket) {
        skip(']');
        preincrement = 1; // add offset before transfer
        अगर (tok == '!') {
            exclam = 1;
            अग्र(); // skip '!'
        }
    }

    // TODO: Support options.

    अगर (token == TOK_ASM_ldc2 || token == TOK_ASM_stc2 || token == TOK_ASM_ldc2l || token == TOK_ASM_stc2l) {
        चयन (token) {
        हाल TOK_ASM_ldc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        हाल TOK_ASM_ldc2:
            asm_emit_coprocessor_तथ्य_transfer(0xF, coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
            अवरोध;
        हाल TOK_ASM_stc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        हाल TOK_ASM_stc2:
            asm_emit_coprocessor_तथ्य_transfer(0xF, coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
            अवरोध;
        }
    } अन्यथा चयन (ARM_INSTRUCTION_GROUP(token)) {
    हाल TOK_ASM_stcleq:
        long_transfer = 1;
        /* fallthrough */
    हाल TOK_ASM_stceq:
        asm_emit_coprocessor_तथ्य_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
        अवरोध;
    हाल TOK_ASM_ldcleq:
        long_transfer = 1;
        /* fallthrough */
    हाल TOK_ASM_ldceq:
        asm_emit_coprocessor_तथ्य_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
        अवरोध;
    शेष:
        expect("coprocessor data transfer instruction");
    }
}

#अगर defined(TCC_ARM_VFP)
#घोषणा CP_SINGLE_PRECISION_FLOAT 10
#घोषणा CP_DOUBLE_PRECISION_FLOAT 11

अटल व्योम asm_floating_point_single_तथ्य_transfer_opcode(TCCState *s1, पूर्णांक token)
{
    Operand ops[3];
    uint8_t coprocessor = 0;
    uint8_t coprocessor_destination_register = 0;
    पूर्णांक long_transfer = 0;
    // Note: vldr p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: Not allowed: vldr p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: Not allowed: vldr p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_operand(s1, &ops[0]);
    अगर (ops[0].type == OP_VREG32) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        coprocessor_destination_register = ops[0].reg;
        long_transfer = coprocessor_destination_register & 1;
        coprocessor_destination_register >>= 1;
    } अन्यथा अगर (ops[0].type == OP_VREG64) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        coprocessor_destination_register = ops[0].reg;
        अग्र();
    } अन्यथा {
        expect("floating point register");
    }

    skip(',');
    skip('[');
    parse_operand(s1, &ops[1]);
    अगर (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    अगर (tok == ',') {
        अग्र(); // skip ','
        parse_operand(s1, &ops[2]);
        अगर (ops[2].type != OP_IM8 && ops[2].type != OP_IM8N) {
            expect("immediate offset");
        }
    } अन्यथा {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
    }
    skip(']');

    चयन (ARM_INSTRUCTION_GROUP(token)) {
    हाल TOK_ASM_vldreq:
        asm_emit_coprocessor_तथ्य_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], 0, 1, 0, long_transfer, 1);
        अवरोध;
    हाल TOK_ASM_vstreq:
        asm_emit_coprocessor_तथ्य_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], 0, 1, 0, long_transfer, 0);
        अवरोध;
    शेष:
        expect("floating point data transfer instruction");
    }
}

अटल व्योम asm_floating_point_block_तथ्य_transfer_opcode(TCCState *s1, पूर्णांक token)
{
    uint8_t coprocessor = 0;
    पूर्णांक first_regset_register;
    पूर्णांक last_regset_register;
    uint8_t regset_item_गिनती;
    uint8_t extra_register_bit = 0;
    पूर्णांक op0_exclam = 0;
    पूर्णांक load = 0;
    पूर्णांक preincrement = 0;
    Operand ops[1];
    Operand offset;
    चयन (ARM_INSTRUCTION_GROUP(token)) {
    हाल TOK_ASM_vpusheq:
    हाल TOK_ASM_vpopeq:
        ops[0].type = OP_REG32;
        ops[0].reg = 13; // sp
        op0_exclam = 1;
        अवरोध;
    शेष:
        parse_operand(s1, &ops[0]);
        अगर (tok == '!') {
            op0_exclam = 1;
            अग्र(); // skip '!'
        }
        skip(',');
    }

    skip('{');
    first_regset_register = asm_parse_vfp_regvar(tok, 1);
    अगर ((first_regset_register = asm_parse_vfp_regvar(tok, 1)) != -1) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        अग्र();
    } अन्यथा अगर ((first_regset_register = asm_parse_vfp_regvar(tok, 0)) != -1) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        अग्र();
    } अन्यथा {
        expect("floating-point register");
    }

    अगर (tok == '-') {
        अग्र();
        अगर ((last_regset_register = asm_parse_vfp_regvar(tok, coprocessor == CP_DOUBLE_PRECISION_FLOAT)) != -1)
            अग्र();
        अन्यथा {
            expect("floating-point register");
        }
    } अन्यथा
        last_regset_register = first_regset_register;

    अगर (last_regset_register < first_regset_register) {
        tcc_error("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
    }
    skip('}');
    // Note: 0 (one down) is not implemented by us regardless.
    regset_item_गिनती = last_regset_register - first_regset_register + 1;
    अगर (coprocessor == CP_DOUBLE_PRECISION_FLOAT)
        regset_item_गिनती <<= 1;
    अन्यथा {
        extra_register_bit = first_regset_register & 1;
        first_regset_register >>= 1;
    }
    offset.type = OP_IM8;
    offset.e.v = regset_item_गिनती << 2;
    चयन (ARM_INSTRUCTION_GROUP(token)) {
    हाल TOK_ASM_vstmeq: // post-increment store
    हाल TOK_ASM_vstmiaeq: // post-increment store
        अवरोध;
    हाल TOK_ASM_vpopeq:
    हाल TOK_ASM_vldmeq: // post-increment load
    हाल TOK_ASM_vldmiaeq: // post-increment load
        load = 1;
        अवरोध;
    हाल TOK_ASM_vldmdbeq: // pre-decrement load
        load = 1;
        /* fallthrough */
    हाल TOK_ASM_vpusheq:
    हाल TOK_ASM_vstmdbeq: // pre-decrement store
        offset.type = OP_IM8N;
        offset.e.v = -offset.e.v;
        preincrement = 1;
        अवरोध;
    शेष:
        expect("floating point block data transfer instruction");
    }
    अगर (ops[0].type != OP_REG32)
        expect("(first operand) register");
    अन्यथा अगर (ops[0].reg == 15)
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, शून्य));
    अन्यथा अगर (!op0_exclam && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vldmeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vldmiaeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vstmeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vstmiaeq)
        tcc_error("first operand of '%s' should have an exclamation mark", get_tok_str(token, शून्य));
    अन्यथा
        asm_emit_coprocessor_तथ्य_transfer(condition_code_of_token(token), coprocessor, first_regset_register, &ops[0], &offset, 0, preincrement, op0_exclam, extra_register_bit, load);
}

#घोषणा VMOV_FRACTIONAL_DIGITS 7
#घोषणा VMOV_ONE 10000000 /* pow(10, VMOV_FRACTIONAL_DIGITS) */

अटल uint32_t vmov_parse_fractional_part(स्थिर अक्षर* s)
{
    uint32_t परिणाम = 0;
    पूर्णांक i;
    क्रम (i = 0; i < VMOV_FRACTIONAL_DIGITS; ++i) {
        अक्षर c = *s;
        परिणाम *= 10;
        अगर (c >= '0' && c <= '9') {
            परिणाम += (c - '0');
            ++s;
        }
    }
    अगर (*s)
        expect("decimal numeral");
    वापस परिणाम;
}

अटल पूर्णांक vmov_linear_approx_सूचकांक(uint32_t beginning, uint32_t end, uint32_t मूल्य)
{
    पूर्णांक i;
    uint32_t k;
    uint32_t xvalue;

    k = (end - beginning)/16;
    क्रम (xvalue = beginning, i = 0; i < 16; ++i, xvalue += k) {
        अगर (मूल्य == xvalue)
            वापस i;
    }
    //assert(0);
    वापस -1;
}

अटल uint32_t vmov_parse_immediate_मूल्य() {
    uint32_t मूल्य;
    अचिन्हित दीर्घ integral_मूल्य;
    स्थिर अक्षर *p;

    अगर (tok != TOK_PPNUM) {
        expect("immediate value");
    }
    p = tokc.str.तथ्य;
    त्रुटि_सं = 0;
    integral_मूल्य = म_से_अदीर्घ(p, (अक्षर **)&p, 0);

    अगर (त्रुटि_सं || integral_मूल्य >= 32) {
        tcc_error("invalid floating-point immediate value");
    }

    मूल्य = (uint32_t) integral_मूल्य * VMOV_ONE;
    अगर (*p == '.') {
        ++p;
        मूल्य += vmov_parse_fractional_part(p);
    }
    अग्र();
    वापस मूल्य;
}

अटल uint8_t vmov_encode_immediate_मूल्य(uint32_t मूल्य)
{
    uint32_t limit;
    uint32_t end = 0;
    uint32_t beginning = 0;
    पूर्णांक r = -1;
    पूर्णांक n;
    पूर्णांक i;

    limit = 32 * VMOV_ONE;
    क्रम (i = 0; i < 8; ++i) {
        अगर (मूल्य < limit) {
            end = limit;
            limit >>= 1;
            beginning = limit;
            r = i;
        } अन्यथा
            limit >>= 1;
    }
    अगर (r == -1 || मूल्य < beginning || मूल्य > end) {
        tcc_error("invalid decimal number for vmov: %d", मूल्य);
    }
    n = vmov_linear_approx_सूचकांक(beginning, end, मूल्य);
    वापस n | (((3 - r) & 0x7) << 4);
}

// Not standalone.
अटल व्योम asm_floating_point_immediate_तथ्य_processing_opcode_पुच्छ(TCCState *s1, पूर्णांक token, uint8_t coprocessor, uint8_t CRd) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    uint8_t operands[3] = {0, 0, 0};
    uint32_t immediate_मूल्य = 0;
    पूर्णांक op_minus = 0;
    uint8_t code;

    operands[0] = CRd;

    अगर (tok == '#' || tok == '$') {
        अग्र();
    }
    अगर (tok == '-') {
        op_minus = 1;
        अग्र();
    }
    immediate_मूल्य = vmov_parse_immediate_मूल्य();

    opcode1 = 11; // "Other" instruction
    चयन (ARM_INSTRUCTION_GROUP(token)) {
    हाल TOK_ASM_vcmpeq_f32:
    हाल TOK_ASM_vcmpeq_f64:
        opcode2 = 2;
        operands[1] = 5;
        अगर (immediate_मूल्य) {
            expect("Immediate value 0");
        }
        अवरोध;
    हाल TOK_ASM_vcmpeeq_f32:
    हाल TOK_ASM_vcmpeeq_f64:
        opcode2 = 6;
        operands[1] = 5;
        अगर (immediate_मूल्य) {
            expect("Immediate value 0");
        }
        अवरोध;
    हाल TOK_ASM_vmoveq_f32:
    हाल TOK_ASM_vmoveq_f64:
        opcode2 = 0;
        अगर (op_minus)
            operands[1] = 0x8;
        अन्यथा
            operands[1] = 0x0;
        code = vmov_encode_immediate_मूल्य(immediate_मूल्य);
        operands[1] |= code >> 4;
        operands[2] = code & 0xF;
        अवरोध;
    शेष:
        expect("known floating point with immediate instruction");
    }

    अगर (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        अगर (operands[0] & 1)
            opcode1 |= 4;
        operands[0] >>= 1;
    }

    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, operands[0], operands[1], operands[2], opcode2, 0);
}

अटल व्योम asm_floating_point_reg_arm_reg_transfer_opcode_पुच्छ(TCCState *s1, पूर्णांक token, पूर्णांक coprocessor, पूर्णांक nb_arm_regs, पूर्णांक nb_ops, Operand ops[3]) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    चयन (coprocessor) {
    हाल CP_SINGLE_PRECISION_FLOAT:
        // "vmov.f32 r2, s3" or "vmov.f32 s3, r2"
        अगर (nb_ops != 2 || nb_arm_regs != 1) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and one ARM register operands");
        }
        अगर (ops[0].type != OP_REG32) { // determine mode: load or store
            // need to swap operands 0 and 1
            स_नकल(&ops[2], &ops[1], माप(ops[2]));
            स_नकल(&ops[1], &ops[0], माप(ops[1]));
            स_नकल(&ops[0], &ops[2], माप(ops[0]));
        } अन्यथा
            opcode1 |= 1;

        अगर (ops[1].type == OP_VREG32) {
            अगर (ops[1].reg & 1)
                opcode2 |= 4;
            ops[1].reg >>= 1;
        }

        अगर (ops[0].type == OP_VREG32) {
            अगर (ops[0].reg & 1)
                opcode1 |= 4;
            ops[0].reg >>= 1;
        }

        asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, 0x10, opcode2, 0);
        अवरोध;
    हाल CP_DOUBLE_PRECISION_FLOAT:
        अगर (nb_ops != 3 || nb_arm_regs != 2) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and two ARM register operands");
        }
        // Determine whether it's a store into a VFP register (vmov "d1, r2, r3") rather than "vmov r2, r3, d1"
        अगर (ops[0].type == OP_VREG64) {
            अगर (ops[2].type == OP_REG32) {
                Operand अस्थायी;
                // need to rotate operand list to the left
                स_नकल(&अस्थायी, &ops[0], माप(अस्थायी));
                स_नकल(&ops[0], &ops[1], माप(ops[0]));
                स_नकल(&ops[1], &ops[2], माप(ops[1]));
                स_नकल(&ops[2], &अस्थायी, माप(ops[2]));
            } अन्यथा {
                tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
            }
        } अन्यथा अगर (ops[0].type != OP_REG32 || ops[1].type != OP_REG32 || ops[2].type != OP_VREG64) {
            tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
        } अन्यथा {
            opcode1 |= 1;
        }
        asm_emit_coprocessor_तथ्य_transfer(condition_code_of_token(token), coprocessor, ops[0].reg, &ops[1], &ops[2], 0, 0, 0, 1, opcode1);
        अवरोध;
    शेष:
        tcc_internal_error("unknown coprocessor");
    }
}

अटल व्योम asm_floating_point_vcvt_तथ्य_processing_opcode(TCCState *s1, पूर्णांक token) {
    uint8_t coprocessor = 0;
    Operand ops[3];
    uint8_t opcode1 = 11;
    uint8_t opcode2 = 2;

    चयन (ARM_INSTRUCTION_GROUP(token)) {
    हाल TOK_ASM_vcvtreq_s32_f64:
    हाल TOK_ASM_vcvtreq_u32_f64:
    हाल TOK_ASM_vcvteq_s32_f64:
    हाल TOK_ASM_vcvteq_u32_f64:
    हाल TOK_ASM_vcvteq_f64_s32:
    हाल TOK_ASM_vcvteq_f64_u32:
    हाल TOK_ASM_vcvteq_f32_f64:
       coprocessor = CP_DOUBLE_PRECISION_FLOAT;
       अवरोध;
    हाल TOK_ASM_vcvtreq_s32_f32:
    हाल TOK_ASM_vcvtreq_u32_f32:
    हाल TOK_ASM_vcvteq_s32_f32:
    हाल TOK_ASM_vcvteq_u32_f32:
    हाल TOK_ASM_vcvteq_f32_s32:
    हाल TOK_ASM_vcvteq_f32_u32:
    हाल TOK_ASM_vcvteq_f64_f32:
       coprocessor = CP_SINGLE_PRECISION_FLOAT;
       अवरोध;
    शेष:
       tcc_error("Unknown coprocessor for instruction '%s'", get_tok_str(token, शून्य));
    }

    parse_operand(s1, &ops[0]);
    ops[1].type = OP_IM8;
    ops[1].e.v = 8;
    /* floating-point -> integer */
    चयन (ARM_INSTRUCTION_GROUP(token)) {
    हाल TOK_ASM_vcvtreq_s32_f32:
    हाल TOK_ASM_vcvtreq_s32_f64:
    हाल TOK_ASM_vcvteq_s32_f32:
    हाल TOK_ASM_vcvteq_s32_f64:
        ops[1].e.v |= 1; // signed
        /* fall through */
    हाल TOK_ASM_vcvteq_u32_f32:
    हाल TOK_ASM_vcvteq_u32_f64:
    हाल TOK_ASM_vcvtreq_u32_f32:
    हाल TOK_ASM_vcvtreq_u32_f64:
        ops[1].e.v |= 4; // to_integer (opc2)
        अवरोध;
    /* floating-point size conversion */
    हाल TOK_ASM_vcvteq_f64_f32:
    हाल TOK_ASM_vcvteq_f32_f64:
        ops[1].e.v = 7;
        अवरोध;
    }

    skip(',');
    parse_operand(s1, &ops[2]);

    चयन (ARM_INSTRUCTION_GROUP(token)) {
    /* floating-point -> integer */
    हाल TOK_ASM_vcvteq_s32_f32:
    हाल TOK_ASM_vcvteq_s32_f64:
    हाल TOK_ASM_vcvteq_u32_f32:
    हाल TOK_ASM_vcvteq_u32_f64:
        opcode2 |= 4; // round_zero
        अवरोध;

    /* integer -> floating-point */
    हाल TOK_ASM_vcvteq_f64_s32:
    हाल TOK_ASM_vcvteq_f32_s32:
        opcode2 |= 4; // signed--special
        अवरोध;

    /* floating-point size conversion */
    हाल TOK_ASM_vcvteq_f64_f32:
    हाल TOK_ASM_vcvteq_f32_f64:
        opcode2 |= 4; // always set
        अवरोध;
    }

    चयन (ARM_INSTRUCTION_GROUP(token)) {
    हाल TOK_ASM_vcvteq_f64_u32:
    हाल TOK_ASM_vcvteq_f64_s32:
    हाल TOK_ASM_vcvteq_f64_f32:
        अगर (ops[0].type == OP_VREG64 && ops[2].type == OP_VREG32) {
        } अन्यथा {
            expect("d<number>, s<number>");
        }
        अवरोध;
    शेष:
        अगर (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
            अगर (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG32) {
            } अन्यथा {
                expect("s<number>, s<number>");
            }
        } अन्यथा अगर (coprocessor == CP_DOUBLE_PRECISION_FLOAT) {
            अगर (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG64) {
            } अन्यथा {
                expect("s<number>, d<number>");
            }
        }
    }

    अगर (ops[2].type == OP_VREG32) {
        अगर (ops[2].reg & 1)
            opcode2 |= 1;
        ops[2].reg >>= 1;
    }
    अगर (ops[0].type == OP_VREG32) {
        अगर (ops[0].reg & 1)
            opcode1 |= 4;
        ops[0].reg >>= 1;
    }
    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

अटल व्योम asm_floating_point_तथ्य_processing_opcode(TCCState *s1, पूर्णांक token) {
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0; // (0 || 2) | register selection
    Operand ops[3];
    uint8_t nb_ops = 0;
    पूर्णांक vmov = 0;
    पूर्णांक nb_arm_regs = 0;

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

    चयन (ARM_INSTRUCTION_GROUP(token)) {
    हाल TOK_ASM_vmlaeq_f64:
    हाल TOK_ASM_vmlseq_f64:
    हाल TOK_ASM_vnmlseq_f64:
    हाल TOK_ASM_vnmlaeq_f64:
    हाल TOK_ASM_vmuleq_f64:
    हाल TOK_ASM_vnmuleq_f64:
    हाल TOK_ASM_vaddeq_f64:
    हाल TOK_ASM_vsubeq_f64:
    हाल TOK_ASM_vdiveq_f64:
    हाल TOK_ASM_vnegeq_f64:
    हाल TOK_ASM_vabseq_f64:
    हाल TOK_ASM_vsqrteq_f64:
    हाल TOK_ASM_vcmpeq_f64:
    हाल TOK_ASM_vcmpeeq_f64:
    हाल TOK_ASM_vmoveq_f64:
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
    }

    चयन (ARM_INSTRUCTION_GROUP(token)) {
    हाल TOK_ASM_vmoveq_f32:
    हाल TOK_ASM_vmoveq_f64:
        vmov = 1;
        अवरोध;
    }

    क्रम (nb_ops = 0; nb_ops < 3; ) {
        // Note: Necessary because parse_operand can't parse decimal numerals.
        अगर (nb_ops == 1 && (tok == '#' || tok == '$' || tok == TOK_PPNUM || tok == '-')) {
            asm_floating_point_immediate_तथ्य_processing_opcode_पुच्छ(s1, token, coprocessor, ops[0].reg);
            वापस;
        }
        parse_operand(s1, &ops[nb_ops]);
        अगर (vmov && ops[nb_ops].type == OP_REG32) {
            ++nb_arm_regs;
        } अन्यथा अगर (ops[nb_ops].type == OP_VREG32) {
            अगर (coprocessor != CP_SINGLE_PRECISION_FLOAT) {
                expect("'s<number>'");
            }
        } अन्यथा अगर (ops[nb_ops].type == OP_VREG64) {
            अगर (coprocessor != CP_DOUBLE_PRECISION_FLOAT) {
                expect("'d<number>'");
            }
        } अन्यथा {
            expect("floating point register");
        }
        ++nb_ops;
        अगर (tok == ',')
            अग्र();
        अन्यथा
            अवरोध;
    }

    अगर (nb_arm_regs == 0) {
        अगर (nb_ops == 2) { // implicit
            स_नकल(&ops[2], &ops[1], माप(ops[1])); // move ops[2]
            स_नकल(&ops[1], &ops[0], माप(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
        अगर (nb_ops < 3) {
            tcc_error("Not enough operands for '%s' (%u)", get_tok_str(token, शून्य), nb_ops);
        }
    }

    चयन (ARM_INSTRUCTION_GROUP(token)) {
    हाल TOK_ASM_vmlaeq_f32:
    हाल TOK_ASM_vmlaeq_f64:
        opcode1 = 0;
        opcode2 = 0;
        अवरोध;
    हाल TOK_ASM_vmlseq_f32:
    हाल TOK_ASM_vmlseq_f64:
        opcode1 = 0;
        opcode2 = 2;
        अवरोध;
    हाल TOK_ASM_vnmlseq_f32:
    हाल TOK_ASM_vnmlseq_f64:
        opcode1 = 1;
        opcode2 = 0;
        अवरोध;
    हाल TOK_ASM_vnmlaeq_f32:
    हाल TOK_ASM_vnmlaeq_f64:
        opcode1 = 1;
        opcode2 = 2;
        अवरोध;
    हाल TOK_ASM_vmuleq_f32:
    हाल TOK_ASM_vmuleq_f64:
        opcode1 = 2;
        opcode2 = 0;
        अवरोध;
    हाल TOK_ASM_vnmuleq_f32:
    हाल TOK_ASM_vnmuleq_f64:
        opcode1 = 2;
        opcode2 = 2;
        अवरोध;
    हाल TOK_ASM_vaddeq_f32:
    हाल TOK_ASM_vaddeq_f64:
        opcode1 = 3;
        opcode2 = 0;
        अवरोध;
    हाल TOK_ASM_vsubeq_f32:
    हाल TOK_ASM_vsubeq_f64:
        opcode1 = 3;
        opcode2 = 2;
        अवरोध;
    हाल TOK_ASM_vdiveq_f32:
    हाल TOK_ASM_vdiveq_f64:
        opcode1 = 8;
        opcode2 = 0;
        अवरोध;
    हाल TOK_ASM_vnegeq_f32:
    हाल TOK_ASM_vnegeq_f64:
        opcode1 = 11; // Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        अवरोध;
    हाल TOK_ASM_vabseq_f32:
    हाल TOK_ASM_vabseq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 0;
        अवरोध;
    हाल TOK_ASM_vsqrteq_f32:
    हाल TOK_ASM_vsqrteq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        अवरोध;
    हाल TOK_ASM_vcmpeq_f32:
    हाल TOK_ASM_vcmpeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        अवरोध;
    हाल TOK_ASM_vcmpeeq_f32:
    हाल TOK_ASM_vcmpeeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        अवरोध;
    हाल TOK_ASM_vmoveq_f32:
    हाल TOK_ASM_vmoveq_f64:
        अगर (nb_arm_regs > 0) { // vmov.f32 r2, s3 or similar
            asm_floating_point_reg_arm_reg_transfer_opcode_पुच्छ(s1, token, coprocessor, nb_arm_regs, nb_ops, ops);
            वापस;
        } अन्यथा {
            opcode1 = 11; // "Other" instruction
            opcode2 = 2;
            ops[1].type = OP_IM8;
            ops[1].e.v = 0;
        }
        अवरोध;
    शेष:
        expect("known floating point instruction");
    }

    अगर (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        अगर (ops[2].type == OP_VREG32) {
            अगर (ops[2].reg & 1)
                opcode2 |= 1;
            ops[2].reg >>= 1;
        }

        अगर (ops[1].type == OP_VREG32) {
            अगर (ops[1].reg & 1)
                opcode2 |= 4;
            ops[1].reg >>= 1;
        }

        अगर (ops[0].type == OP_VREG32) {
            अगर (ops[0].reg & 1)
                opcode1 |= 4;
            ops[0].reg >>= 1;
        }
    }

    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

अटल पूर्णांक asm_parse_vfp_status_regvar(पूर्णांक t)
{
    चयन (t) {
    हाल TOK_ASM_fpsid:
        वापस 0;
    हाल TOK_ASM_fpscr:
        वापस 1;
    हाल TOK_ASM_fpexc:
        वापस 8;
    शेष:
        वापस -1;
    }
}

अटल व्योम asm_floating_point_status_register_opcode(TCCState* s1, पूर्णांक token)
{
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode;
    पूर्णांक vfp_sys_reg = -1;
    Operand arm_operand;
    चयन (ARM_INSTRUCTION_GROUP(token)) {
    हाल TOK_ASM_vmrseq:
        opcode = 0xf;
        अगर (tok == TOK_ASM_apsr_nzcv) {
            arm_operand.type = OP_REG32;
            arm_operand.reg = 15; // not PC
            अग्र(); // skip apsr_nzcv
        } अन्यथा {
            parse_operand(s1, &arm_operand);
            अगर (arm_operand.type == OP_REG32 && arm_operand.reg == 15) {
                tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, शून्य));
            }
        }

        skip(',');
        vfp_sys_reg = asm_parse_vfp_status_regvar(tok);
        अग्र(); // skip vfp sys reg
        अगर (arm_operand.type == OP_REG32 && arm_operand.reg == 15 && vfp_sys_reg != 1) {
            tcc_error("'%s' only supports the variant 'vmrs apsr_nzcv, fpscr' here", get_tok_str(token, शून्य));
        }
        अवरोध;
    हाल TOK_ASM_vmsreq:
        opcode = 0xe;
        vfp_sys_reg = asm_parse_vfp_status_regvar(tok);
        अग्र(); // skip vfp sys reg
        skip(',');
        parse_operand(s1, &arm_operand);
        अगर (arm_operand.type == OP_REG32 && arm_operand.reg == 15) {
            tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, शून्य));
        }
        अवरोध;
    शेष:
        expect("floating point status register instruction");
    }
    अगर (vfp_sys_reg == -1) {
        expect("VFP system register");
    }
    अगर (arm_operand.type != OP_REG32) {
        expect("ARM register");
    }
    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode, arm_operand.reg, vfp_sys_reg, 0x10, 0, 0);
}

#पूर्ण_अगर

अटल व्योम asm_misc_single_तथ्य_transfer_opcode(TCCState *s1, पूर्णांक token)
{
    Operand ops[3];
    पूर्णांक exclam = 0;
    पूर्णांक closed_bracket = 0;
    पूर्णांक op2_minus = 0;
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
    अगर (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    अन्यथा {
        expect("(destination operand) register");
    }
    अगर (tok != ',')
        expect("at least two arguments");
    अन्यथा
        अग्र(); // skip ','
    skip('[');
    parse_operand(s1, &ops[1]);
    अगर (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    अन्यथा {
        expect("(first source operand) register");
    }
    अगर (tok == ']') {
        अग्र();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    अगर (tok == ',') {
        अग्र(); // skip ','
        अगर (tok == '-') {
            op2_minus = 1;
            अग्र();
        }
        parse_operand(s1, &ops[2]);
    } अन्यथा {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        opcode |= 1 << 24; // add offset before transfer
    }
    अगर (!closed_bracket) {
        skip(']');
        opcode |= 1 << 24; // add offset before transfer
        अगर (tok == '!') {
            exclam = 1;
            अग्र(); // skip '!'
        }
    }

    अगर (exclam) {
        अगर ((opcode & (1 << 24)) == 0) {
            tcc_error("result of '%s' would be unpredictable here", get_tok_str(token, शून्य));
        }
        opcode |= 1 << 21; // write offset back into register
    }

    अगर (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        पूर्णांक v = ops[2].e.v;
        अगर (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        अगर (v >= 0) {
            opcode |= 1 << 23; // up
            अगर (v >= 0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, शून्य));
            अन्यथा {
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        } अन्यथा { // down
            अगर (v <= -0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, शून्य));
            अन्यथा {
                v = -v;
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        }
        opcode |= 1 << 22; // not ENCODE_IMMEDIATE_FLAG;
    } अन्यथा अगर (ops[2].type == OP_REG32) {
        अगर (!op2_minus)
            opcode |= 1 << 23; // up
        opcode |= ops[2].reg;
    } अन्यथा
        expect("register");

    चयन (ARM_INSTRUCTION_GROUP(token)) {
    हाल TOK_ASM_ldrsheq:
        opcode |= 1 << 5; // halfword, not byte
        /* fallthrough */
    हाल TOK_ASM_ldrsbeq:
        opcode |= 1 << 6; // sign extend
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        अवरोध;
    हाल TOK_ASM_ldrheq:
        opcode |= 1 << 5; // halfword, not byte
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        अवरोध;
    हाल TOK_ASM_strheq:
        opcode |= 1 << 5; // halfword, not byte
        asm_emit_opcode(token, opcode);
        अवरोध;
    }
}

/* Note: almost dupe of encbranch in arm-gen.c */
अटल uint32_t encbranchoffset(पूर्णांक pos, पूर्णांक addr, पूर्णांक fail)
{
  addr-=pos+8;
  addr/=4;
  अगर(addr>=0x7fffff || addr<-0x800000) {
    अगर(fail)
      tcc_error("branch offset is too far");
    वापस 0;
  }
  वापस /*not 0x0A000000|*/(addr&0xffffff);
}

अटल व्योम asm_branch_opcode(TCCState *s1, पूर्णांक token)
{
    पूर्णांक jmp_disp = 0;
    Operand op;
    व्यंजक_मूल्य e;
    ElfSym *esym;

    चयन (ARM_INSTRUCTION_GROUP(token)) {
    हाल TOK_ASM_beq:
    हाल TOK_ASM_bleq:
        asm_व्यंजक(s1, &e);
        अगर (e.sym) {
            esym = elfsym(e.sym);
            अगर (esym && esym->st_shndx == cur_text_section->sh_अंक) {
                jmp_disp = esym->st_मूल्य;
            } अन्यथा {
                greloca(cur_text_section, e.sym, ind, R_ARM_PC24, 0);
                jmp_disp = ind;
            }
        }
        jmp_disp = encbranchoffset(ind, e.v + jmp_disp, 1);
        अवरोध;
    शेष:
        parse_operand(s1, &op);
        अवरोध;
    }
    चयन (ARM_INSTRUCTION_GROUP(token)) {
    हाल TOK_ASM_beq:
        asm_emit_opcode(token, (0xa << 24) | (jmp_disp & 0xffffff));
        अवरोध;
    हाल TOK_ASM_bleq:
        asm_emit_opcode(token, (0xb << 24) | (jmp_disp & 0xffffff));
        अवरोध;
    हाल TOK_ASM_bxeq:
        अगर (op.type != OP_REG32)
            expect("register");
        अन्यथा
            asm_emit_opcode(token, (0x12fff1 << 4) | op.reg);
        अवरोध;
    हाल TOK_ASM_blxeq:
        अगर (op.type != OP_REG32)
            expect("register");
        अन्यथा
            asm_emit_opcode(token, (0x12fff3 << 4) | op.reg);
        अवरोध;
    शेष:
        expect("branch instruction");
    }
}

ST_FUNC व्योम asm_opcode(TCCState *s1, पूर्णांक token)
{
    जबतक (token == TOK_LINEFEED) {
        अग्र();
        token = tok;
    }
    अगर (token == TOK_EOF)
        वापस;
    अगर (token < TOK_ASM_nopeq) { // no condition code
        चयन (token) {
        हाल TOK_ASM_cdp2:
            asm_coprocessor_opcode(s1, token);
            वापस;
        हाल TOK_ASM_ldc2:
        हाल TOK_ASM_ldc2l:
        हाल TOK_ASM_stc2:
        हाल TOK_ASM_stc2l:
            asm_coprocessor_तथ्य_transfer_opcode(s1, token);
            वापस;
        शेष:
            expect("instruction");
        }
    }

    चयन (ARM_INSTRUCTION_GROUP(token)) {
    हाल TOK_ASM_pusheq:
    हाल TOK_ASM_popeq:
    हाल TOK_ASM_stmdaeq:
    हाल TOK_ASM_ldmdaeq:
    हाल TOK_ASM_stmeq:
    हाल TOK_ASM_ldmeq:
    हाल TOK_ASM_stmiaeq:
    हाल TOK_ASM_ldmiaeq:
    हाल TOK_ASM_stmdbeq:
    हाल TOK_ASM_ldmdbeq:
    हाल TOK_ASM_stmibeq:
    हाल TOK_ASM_ldmibeq:
        asm_block_तथ्य_transfer_opcode(s1, token);
        वापस;
    हाल TOK_ASM_nopeq:
    हाल TOK_ASM_wfeeq:
    हाल TOK_ASM_wfieq:
        asm_nullary_opcode(token);
        वापस;
    हाल TOK_ASM_swieq:
    हाल TOK_ASM_svceq:
        asm_unary_opcode(s1, token);
        वापस;
    हाल TOK_ASM_beq:
    हाल TOK_ASM_bleq:
    हाल TOK_ASM_bxeq:
    हाल TOK_ASM_blxeq:
        asm_branch_opcode(s1, token);
        वापस;
    हाल TOK_ASM_clzeq:
    हाल TOK_ASM_sxtbeq:
    हाल TOK_ASM_sxtheq:
    हाल TOK_ASM_uxtbeq:
    हाल TOK_ASM_uxtheq:
    हाल TOK_ASM_movteq:
    हाल TOK_ASM_movweq:
        asm_द्विआधारी_opcode(s1, token);
        वापस;

    हाल TOK_ASM_ldreq:
    हाल TOK_ASM_ldrbeq:
    हाल TOK_ASM_streq:
    हाल TOK_ASM_strbeq:
    हाल TOK_ASM_ldrexeq:
    हाल TOK_ASM_ldrexbeq:
    हाल TOK_ASM_ldrexheq:
    हाल TOK_ASM_strexeq:
    हाल TOK_ASM_strexbeq:
    हाल TOK_ASM_strexheq:
        asm_single_तथ्य_transfer_opcode(s1, token);
        वापस;

    हाल TOK_ASM_ldrheq:
    हाल TOK_ASM_ldrsheq:
    हाल TOK_ASM_ldrsbeq:
    हाल TOK_ASM_strheq:
       asm_misc_single_तथ्य_transfer_opcode(s1, token);
       वापस;

    हाल TOK_ASM_andeq:
    हाल TOK_ASM_eoreq:
    हाल TOK_ASM_subeq:
    हाल TOK_ASM_rsbeq:
    हाल TOK_ASM_addeq:
    हाल TOK_ASM_adceq:
    हाल TOK_ASM_sbceq:
    हाल TOK_ASM_rsceq:
    हाल TOK_ASM_tsteq:
    हाल TOK_ASM_teqeq:
    हाल TOK_ASM_cmpeq:
    हाल TOK_ASM_cmneq:
    हाल TOK_ASM_orreq:
    हाल TOK_ASM_moveq:
    हाल TOK_ASM_biceq:
    हाल TOK_ASM_mvneq:
    हाल TOK_ASM_andseq:
    हाल TOK_ASM_eorseq:
    हाल TOK_ASM_subseq:
    हाल TOK_ASM_rsbseq:
    हाल TOK_ASM_addseq:
    हाल TOK_ASM_adcseq:
    हाल TOK_ASM_sbcseq:
    हाल TOK_ASM_rscseq:
//  case TOK_ASM_tstseq:
//  case TOK_ASM_teqseq:
//  case TOK_ASM_cmpseq:
//  case TOK_ASM_cmnseq:
    हाल TOK_ASM_orrseq:
    हाल TOK_ASM_movseq:
    हाल TOK_ASM_bicseq:
    हाल TOK_ASM_mvnseq:
        asm_तथ्य_processing_opcode(s1, token);
        वापस;

    हाल TOK_ASM_lsleq:
    हाल TOK_ASM_lslseq:
    हाल TOK_ASM_lsreq:
    हाल TOK_ASM_lsrseq:
    हाल TOK_ASM_asreq:
    हाल TOK_ASM_asrseq:
    हाल TOK_ASM_roreq:
    हाल TOK_ASM_rorseq:
    हाल TOK_ASM_rrxseq:
    हाल TOK_ASM_rrxeq:
        asm_shift_opcode(s1, token);
        वापस;

    हाल TOK_ASM_muleq:
    हाल TOK_ASM_mulseq:
    हाल TOK_ASM_mlaeq:
    हाल TOK_ASM_mlaseq:
    हाल TOK_ASM_mlseq:
    हाल TOK_ASM_udiveq:
    हाल TOK_ASM_sdiveq:
        asm_multiplication_opcode(s1, token);
        वापस;

    हाल TOK_ASM_smulleq:
    हाल TOK_ASM_smullseq:
    हाल TOK_ASM_umulleq:
    हाल TOK_ASM_umullseq:
    हाल TOK_ASM_smlaleq:
    हाल TOK_ASM_smlalseq:
    हाल TOK_ASM_umlaleq:
    हाल TOK_ASM_umlalseq:
        asm_long_multiplication_opcode(s1, token);
        वापस;

    हाल TOK_ASM_cdpeq:
    हाल TOK_ASM_mcreq:
    हाल TOK_ASM_mrceq:
        asm_coprocessor_opcode(s1, token);
        वापस;

    हाल TOK_ASM_ldceq:
    हाल TOK_ASM_ldcleq:
    हाल TOK_ASM_stceq:
    हाल TOK_ASM_stcleq:
        asm_coprocessor_तथ्य_transfer_opcode(s1, token);
        वापस;

#अगर defined(TCC_ARM_VFP)
    हाल TOK_ASM_vldreq:
    हाल TOK_ASM_vstreq:
        asm_floating_point_single_तथ्य_transfer_opcode(s1, token);
        वापस;

    हाल TOK_ASM_vmlaeq_f32:
    हाल TOK_ASM_vmlseq_f32:
    हाल TOK_ASM_vnmlseq_f32:
    हाल TOK_ASM_vnmlaeq_f32:
    हाल TOK_ASM_vmuleq_f32:
    हाल TOK_ASM_vnmuleq_f32:
    हाल TOK_ASM_vaddeq_f32:
    हाल TOK_ASM_vsubeq_f32:
    हाल TOK_ASM_vdiveq_f32:
    हाल TOK_ASM_vnegeq_f32:
    हाल TOK_ASM_vabseq_f32:
    हाल TOK_ASM_vsqrteq_f32:
    हाल TOK_ASM_vcmpeq_f32:
    हाल TOK_ASM_vcmpeeq_f32:
    हाल TOK_ASM_vmoveq_f32:
    हाल TOK_ASM_vmlaeq_f64:
    हाल TOK_ASM_vmlseq_f64:
    हाल TOK_ASM_vnmlseq_f64:
    हाल TOK_ASM_vnmlaeq_f64:
    हाल TOK_ASM_vmuleq_f64:
    हाल TOK_ASM_vnmuleq_f64:
    हाल TOK_ASM_vaddeq_f64:
    हाल TOK_ASM_vsubeq_f64:
    हाल TOK_ASM_vdiveq_f64:
    हाल TOK_ASM_vnegeq_f64:
    हाल TOK_ASM_vabseq_f64:
    हाल TOK_ASM_vsqrteq_f64:
    हाल TOK_ASM_vcmpeq_f64:
    हाल TOK_ASM_vcmpeeq_f64:
    हाल TOK_ASM_vmoveq_f64:
        asm_floating_point_तथ्य_processing_opcode(s1, token);
        वापस;

    हाल TOK_ASM_vcvtreq_s32_f32:
    हाल TOK_ASM_vcvtreq_s32_f64:
    हाल TOK_ASM_vcvteq_s32_f32:
    हाल TOK_ASM_vcvteq_s32_f64:
    हाल TOK_ASM_vcvtreq_u32_f32:
    हाल TOK_ASM_vcvtreq_u32_f64:
    हाल TOK_ASM_vcvteq_u32_f32:
    हाल TOK_ASM_vcvteq_u32_f64:
    हाल TOK_ASM_vcvteq_f64_s32:
    हाल TOK_ASM_vcvteq_f32_s32:
    हाल TOK_ASM_vcvteq_f64_u32:
    हाल TOK_ASM_vcvteq_f32_u32:
    हाल TOK_ASM_vcvteq_f64_f32:
    हाल TOK_ASM_vcvteq_f32_f64:
        asm_floating_point_vcvt_तथ्य_processing_opcode(s1, token);
        वापस;

    हाल TOK_ASM_vpusheq:
    हाल TOK_ASM_vpopeq:
    हाल TOK_ASM_vldmeq:
    हाल TOK_ASM_vldmiaeq:
    हाल TOK_ASM_vldmdbeq:
    हाल TOK_ASM_vstmeq:
    हाल TOK_ASM_vstmiaeq:
    हाल TOK_ASM_vstmdbeq:
        asm_floating_point_block_तथ्य_transfer_opcode(s1, token);
        वापस;

    हाल TOK_ASM_vmsreq:
    हाल TOK_ASM_vmrseq:
        asm_floating_point_status_register_opcode(s1, token);
        वापस;
#पूर्ण_अगर

    शेष:
        expect("known instruction");
    }
}

ST_FUNC व्योम subst_asm_operand(CString *add_str, SValue *sv, पूर्णांक modifier)
{
    पूर्णांक r, reg, आकार, val;

    r = sv->r;
    अगर ((r & VT_VALMASK) == VT_CONST) {
        अगर (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(add_str, '#');
        अगर (r & VT_SYM) {
            स्थिर अक्षर *name = get_tok_str(sv->sym->v, शून्य);
            अगर (sv->sym->v >= SYM_FIRST_ANOM) {
                /* In case of anonymous symbols ("L.42", used
                   for static data labels) we can't find them
                   in the C symbol table when later looking up
                   this name.  So enter them now into the asm label
                   list when we still know the symbol.  */
                get_asm_sym(tok_alloc(name, म_माप(name))->tok, sv->sym);
            }
            अगर (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            अगर ((uint32_t) sv->c.i == 0)
                जाओ no_offset;
            cstr_ccat(add_str, '+');
        }
        val = sv->c.i;
        अगर (modifier == 'n')
            val = -val;
        cstr_printf(add_str, "%d", val);
      no_offset:;
    } अन्यथा अगर ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "[fp,#%d]", (पूर्णांक) sv->c.i);
    } अन्यथा अगर (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        अगर (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "[%s]",
                 get_tok_str(TOK_ASM_r0 + reg, शून्य));
    } अन्यथा {
        /* register case */
        reg = r & VT_VALMASK;
        अगर (reg >= VT_CONST)
            tcc_internal_error("");

        /* choose register operand size */
        अगर ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            आकार = 1;
        अन्यथा अगर ((sv->type.t & VT_BTYPE) == VT_SHORT)
            आकार = 2;
        अन्यथा
            आकार = 4;

        अगर (modifier == 'b') {
            आकार = 1;
        } अन्यथा अगर (modifier == 'w') {
            आकार = 2;
        } अन्यथा अगर (modifier == 'k') {
            आकार = 4;
        }

        चयन (आकार) {
        शेष:
            reg = TOK_ASM_r0 + reg;
            अवरोध;
        }
        cstr_printf(add_str, "%s", get_tok_str(reg, शून्य));
    }
}

/* generate prolog and epilog code for asm statement */
ST_FUNC व्योम asm_gen_code(ASMOperand *operands, पूर्णांक nb_operands,
                          पूर्णांक nb_outputs, पूर्णांक is_output,
                          uint8_t *clobber_regs,
                          पूर्णांक out_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    पूर्णांक i, reg;
    uint32_t saved_regset = 0;

    // TODO: Check non-E ABI.
    // Note: Technically, r13 (sp) is also callee-saved--but that does not matter yet
    अटल स्थिर uint8_t reg_saved[] = { 4, 5, 6, 7, 8, 9 /* Note: sometimes special reg "sb" */ , 10, 11 };

    /* mark all used registers */
    स_नकल(regs_allocated, clobber_regs, माप(regs_allocated));
    क्रम(i = 0; i < nb_operands;i++) {
        op = &operands[i];
        अगर (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }
    क्रम(i = 0; i < माप(reg_saved)/माप(reg_saved[0]); i++) {
        reg = reg_saved[i];
        अगर (regs_allocated[reg])
            saved_regset |= 1 << reg;
    }

    अगर (!is_output) { // prolog
        /* generate reg save code */
        अगर (saved_regset)
            gen_le32(0xe92d0000 | saved_regset); // push {...}

        /* generate load code */
        क्रम(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            अगर (op->reg >= 0) {
                अगर ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_memory) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    load(op->reg, &sv);
                } अन्यथा अगर (i >= nb_outputs || op->is_rw) { // not write-only
                    /* load value in register */
                    load(op->reg, op->vt);
                    अगर (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }
    } अन्यथा { // epilog
        /* generate save code */
        क्रम(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            अगर (op->reg >= 0) {
                अगर ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    अगर (!op->is_memory) {
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
                    अगर (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }

        /* generate reg restore code */
        अगर (saved_regset)
            gen_le32(0xe8bd0000 | saved_regset); // pop {...}
    }
}

/* return the constraint priority (we allocate first the lowest
   numbered constraints) */
अटल अंतरभूत पूर्णांक constraint_priority(स्थिर अक्षर *str)
{
    पूर्णांक priority, c, pr;

    /* we take the lowest priority */
    priority = 0;
    क्रम(;;) {
        c = *str;
        अगर (c == '\0')
            अवरोध;
        str++;
        चयन(c) {
        हाल 'l': // in ARM mode, that's  an alias for 'r' [ARM].
        हाल 'r': // register [general]
        हाल 'p': // valid memory address for load,store [general]
            pr = 3;
            अवरोध;
        हाल 'M': // integer constant for shifts [ARM]
        हाल 'I': // integer valid for data processing instruction immediate
        हाल 'J': // integer in range -4095...4095

        हाल 'i': // immediate integer operand, including symbolic constants [general]
        हाल 'm': // memory operand [general]
        हाल 'g': // general-purpose-register, memory, immediate integer [general]
            pr = 4;
            अवरोध;
        शेष:
            tcc_error("unknown constraint '%c'", c);
        }
        अगर (pr > priority)
            priority = pr;
    }
    वापस priority;
}

अटल स्थिर अक्षर *skip_constraint_modifiers(स्थिर अक्षर *p)
{
    /* Constraint modifier:
        =   Operand is written to by this instruction
        +   Operand is both read and written to by this instruction
        %   Instruction is commutative for this operand and the following operand.

       Per-alternative constraint modifier:
        &   Operand is clobbered before the instruction is done using the input operands
    */
    जबतक (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    वापस p;
}

#घोषणा REG_OUT_MASK 0x01
#घोषणा REG_IN_MASK  0x02

#घोषणा is_reg_allocated(reg) (regs_allocated[reg] & reg_mask)

ST_FUNC व्योम asm_compute_constraints(ASMOperand *operands,
                                    पूर्णांक nb_operands, पूर्णांक nb_outputs,
                                    स्थिर uint8_t *clobber_regs,
                                    पूर्णांक *pout_reg)
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
    पूर्णांक sorted_op[MAX_ASM_OPERANDS];
    पूर्णांक i, j, k, p1, p2, tmp, reg, c, reg_mask;
    स्थिर अक्षर *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    क्रम (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->निवेश_सूचकांक = -1;
        op->ref_सूचकांक = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    क्रम (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        अगर (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = find_constraint(operands, nb_operands, str, शून्य);
            अगर ((अचिन्हित) k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                          i, str);
            op->ref_सूचकांक = k;
            अगर (operands[k].निवेश_सूचकांक >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].निवेश_सूचकांक = i;
            op->priority = 5;
        } अन्यथा अगर ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->priority = 1;
            op->reg = reg;
        } अन्यथा {
            op->priority = constraint_priority(str);
        }
    }

    /* sort operands according to their priority */
    क्रम (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    क्रम (i = 0; i < nb_operands - 1; i++) {
        क्रम (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            अगर (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    क्रम (i = 0; i < NB_ASM_REGS; i++) {
        अगर (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        अन्यथा
            regs_allocated[i] = 0;
    }
    /* sp cannot be used */
    regs_allocated[13] = REG_IN_MASK | REG_OUT_MASK;
    /* fp cannot be used yet */
    regs_allocated[11] = REG_IN_MASK | REG_OUT_MASK;

    /* allocate registers and generate corresponding asm moves */
    क्रम (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        अगर (op->ref_सूचकांक >= 0)
            जारी;
        /* select if register is used for output, input or both */
        अगर (op->निवेश_सूचकांक >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } अन्यथा अगर (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } अन्यथा {
            reg_mask = REG_IN_MASK;
        }
        अगर (op->reg >= 0) {
            अगर (is_reg_allocated(op->reg))
                tcc_error
                    ("asm regvar requests register that's taken already");
            reg = op->reg;
        }
      try_अग्र:
        c = *str++;
        चयन (c) {
        हाल '=': // Operand is written-to
            जाओ try_अग्र;
        हाल '+': // Operand is both READ and written-to
            op->is_rw = 1;
            /* FALL THRU */
        हाल '&': // Operand is clobbered before the instruction is done using the input operands
            अगर (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs",
                          c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            जाओ try_अग्र;
        हाल 'l': // In non-thumb mode, alias for 'r'--otherwise r0-r7 [ARM]
        हाल 'r': // general-purpose register
        हाल 'p': // loadable/storable address
            /* any general register */
            अगर ((reg = op->reg) >= 0)
                जाओ reg_found;
            अन्यथा क्रम (reg = 0; reg <= 8; reg++) {
                अगर (!is_reg_allocated(reg))
                    जाओ reg_found;
            }
            जाओ try_अग्र;
          reg_found:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_mask;
            अवरोध;
        हाल 'I': // integer that is valid as an data processing instruction immediate (0...255, rotated by a multiple of two)
        हाल 'J': // integer in the range -4095 to 4095 [ARM]
        हाल 'K': // integer that satisfies constraint I when inverted (one's complement)
        हाल 'L': // integer that satisfies constraint I when inverted (two's complement)
        हाल 'i': // immediate integer operand, including symbolic constants
            अगर (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                जाओ try_अग्र;
            अवरोध;
        हाल 'M': // integer in the range 0 to 32
            अगर (!
                ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) ==
                 VT_CONST))
                जाओ try_अग्र;
            अवरोध;
        हाल 'm': // memory operand
        हाल 'g':
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            अगर (j < nb_outputs || c == 'm') {
                अगर ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register */
                    क्रम (reg = 0; reg <= 8; reg++) {
                        अगर (!(regs_allocated[reg] & REG_IN_MASK))
                            जाओ reg_found1;
                    }
                    जाओ try_अग्र;
                  reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_IN_MASK;
                    op->reg = reg;
                    op->is_memory = 1;
                }
            }
            अवरोध;
        शेष:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                      j, op->constraint);
            अवरोध;
        }
        /* if a reference is present for that operand, we assign it too */
        अगर (op->निवेश_सूचकांक >= 0) {
            operands[op->निवेश_सूचकांक].reg = op->reg;
            operands[op->निवेश_सूचकांक].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    क्रम (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        अगर (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL && !op->is_memory) {
            क्रम (reg = 0; reg <= 8; reg++) {
                अगर (!(regs_allocated[reg] & REG_OUT_MASK))
                    जाओ reg_found2;
            }
            tcc_error("could not find free output register for reloading");
          reg_found2:
            *pout_reg = reg;
            अवरोध;
        }
    }

    /* print sorted constraints */
#अगर_घोषित ASM_DEBUG
    क्रम (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        म_लिखो("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, शून्य) : "",
               op->constraint, op->vt->r, op->reg);
    }
    अगर (*pout_reg >= 0)
        म_लिखो("out_reg=%d\n", *pout_reg);
#पूर्ण_अगर
}

ST_FUNC व्योम asm_clobber(uint8_t *clobber_regs, स्थिर अक्षर *str)
{
    पूर्णांक reg;
    TokenSym *ts;

    अगर (!म_भेद(str, "memory") ||
        !म_भेद(str, "cc") ||
        !म_भेद(str, "flags"))
        वापस;
    ts = tok_alloc(str, म_माप(str));
    reg = asm_parse_regvar(ts->tok);
    अगर (reg == -1) {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}

/* If T refers to a register then return the register number and type.
   Otherwise return -1.  */
ST_FUNC पूर्णांक asm_parse_regvar (पूर्णांक t)
{
    /* coprocessors (p0-p15) and coprocessor registers (c0-c15) are handled elsewere */
    /* single fp (s0-s31) and double fp registers (d0-d15) are handled elsewere */

    अगर (t < TOK_ASM_r0 || t > TOK_ASM_pc) /* filter unrelated registers */
        वापस -1;

    अगर (t <= TOK_ASM_r15)       /* default register names r0-r15 */
        वापस t - TOK_ASM_r0;

    अगर (t <= TOK_ASM_v8)        /* synonym register names a1-a4,v1-v8 (alias: r0-r11) */
        वापस t - TOK_ASM_a1;

    /* special register names sb/sl/fp/ip/sp/lr/pc (alias: r9-r15) */
    वापस t - TOK_ASM_sb + (TOK_ASM_r9 - TOK_ASM_r0);
}

/*************************************************************/
#पूर्ण_अगर /* ndef TARGET_DEFS_ONLY */

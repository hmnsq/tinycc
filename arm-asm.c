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

ST_FUNC शून्य g(पूर्णांक c);
ST_FUNC शून्य gen_le16(पूर्णांक c);
ST_FUNC शून्य gen_le32(पूर्णांक c);

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

प्रकारव्याख्या संरचना Operand {
    uint32_t type;
    संघ {
        uint8_t reg;
        uint16_t regset;
        अभिव्यक्ती_मूल्य e;
    };
} Operand;

/* Read the VFP register referred to by token T.
   If OK, returns its number.
   If not OK, returns -1. */
स्थिर पूर्णांक asm_parse_vfp_regvar(पूर्णांक t, पूर्णांक double_precision)
{
    जर (double_precision) {
        जर (t >= TOK_ASM_d0 && t <= TOK_ASM_d15)
            परत t - TOK_ASM_d0;
    } अन्यथा {
        जर (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
            परत t - TOK_ASM_s0;
    }
    परत -1;
}

/* Parse a text containing operand and store the result in OP */
स्थिर शून्य parse_operand(TCCState *s1, Operand *op)
{
    अभिव्यक्ती_मूल्य e;
    int8_t reg;
    uint16_t regset = 0;

    op->type = 0;

    जर (tok == '{') { // regset literal
        next(); // skip '{'
        पर्यंत (tok != '}' && tok != TOK_EOF) {
            reg = asm_parse_regvar(tok);
            जर (reg == -1) {
                expect("register");
            } अन्यथा
                next(); // skip register name

            जर ((1 << reg) < regset)
                tcc_warning("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
            regset |= 1 << reg;
            जर (tok != ',')
                थांबा;
            next(); // skip ','
        }
        skip('}');
        जर (regset == 0) {
            // ARM instructions don't support empty regset.
            tcc_error("empty register list is not supported");
        } अन्यथा {
            op->type = OP_REGSET32;
            op->regset = regset;
        }
        परत;
    } अन्यथा जर ((reg = asm_parse_regvar(tok)) != -1) {
        next(); // skip register name
        op->type = OP_REG32;
        op->reg = (uint8_t) reg;
        परत;
    } अन्यथा जर ((reg = asm_parse_vfp_regvar(tok, 0)) != -1) {
        next(); // skip register name
        op->type = OP_VREG32;
        op->reg = (uint8_t) reg;
        परत;
    } अन्यथा जर ((reg = asm_parse_vfp_regvar(tok, 1)) != -1) {
        next(); // skip register name
        op->type = OP_VREG64;
        op->reg = (uint8_t) reg;
        परत;
    } अन्यथा जर (tok == '#' || tok == '$') {
        /* constant value */
        next(); // skip '#' or '$'
    }
    asm_अभिव्यक्ती(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    जर (!op->e.sym) {
        जर ((पूर्णांक) op->e.v < 0 && (पूर्णांक) op->e.v >= -255)
            op->type = OP_IM8N;
        अन्यथा जर (op->e.v == (uint8_t)op->e.v)
            op->type = OP_IM8;
    } अन्यथा
        expect("operand");
}

/* XXX: make it faster ? */
ST_FUNC शून्य g(पूर्णांक c)
{
    पूर्णांक ind1;
    जर (nocode_wanted)
        परत;
    ind1 = ind + 1;
    जर (ind1 > cur_text_section->data_allocated)
        section_realloc(cur_text_section, ind1);
    cur_text_section->data[ind] = c;
    ind = ind1;
}

ST_FUNC शून्य gen_le16 (पूर्णांक i)
{
    g(i);
    g(i>>8);
}

ST_FUNC शून्य gen_le32 (पूर्णांक i)
{
    पूर्णांक ind1;
    जर (nocode_wanted)
        परत;
    ind1 = ind + 4;
    जर (ind1 > cur_text_section->data_allocated)
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

स्थिर uint32_t condition_code_of_token(पूर्णांक token) {
    जर (token < TOK_ASM_nopeq) {
        expect("condition-enabled instruction");
    } अन्यथा
        परत (token - TOK_ASM_nopeq) & 15;
}

स्थिर शून्य asm_emit_opcode(पूर्णांक token, uint32_t opcode) {
    gen_le32((condition_code_of_token(token) << 28) | opcode);
}

स्थिर शून्य asm_emit_unconditional_opcode(uint32_t opcode) {
    gen_le32(opcode);
}

स्थिर शून्य asm_emit_coprocessor_opcode(uint32_t वरचा_nibble, uint8_t cp_संख्या, uint8_t cp_opcode, uint8_t cp_destination_register, uint8_t cp_n_operand_register, uint8_t cp_m_operand_register, uint8_t cp_opcode2, पूर्णांक inter_processor_transfer)
{
    uint32_t opcode = 0xe000000;
    जर (inter_processor_transfer)
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

स्थिर शून्य asm_nullary_opcode(पूर्णांक token)
{
    निवड (ARM_INSTRUCTION_GROUP(token)) {
    स्थिती TOK_ASM_nopeq:
        asm_emit_opcode(token, 0xd << 21); // mov r0, r0
        थांबा;
    स्थिती TOK_ASM_wfeeq:
        asm_emit_opcode(token, 0x320f002);
    स्थिती TOK_ASM_wfieq:
        asm_emit_opcode(token, 0x320f003);
        थांबा;
    पूर्वनिर्धारित:
        expect("nullary instruction");
    }
}

स्थिर शून्य asm_unary_opcode(TCCState *s1, पूर्णांक token)
{
    Operand op;
    parse_operand(s1, &op);

    निवड (ARM_INSTRUCTION_GROUP(token)) {
    स्थिती TOK_ASM_swieq:
    स्थिती TOK_ASM_svceq:
        जर (op.type != OP_IM8)
            expect("immediate 8-bit unsigned integer");
        अन्यथा {
            /* Note: Dummy operand (ignored by processor): ARM ref documented 0...255, ARM instruction set documented 24 bit */
            asm_emit_opcode(token, (0xf << 24) | op.e.v);
        }
        थांबा;
    पूर्वनिर्धारित:
        expect("unary instruction");
    }
}

स्थिर शून्य asm_द्विमान_opcode(TCCState *s1, पूर्णांक token)
{
    Operand ops[2];
    Operand rotation;
    uint32_t encoded_rotation = 0;
    uint64_t amount;
    parse_operand(s1, &ops[0]);
    skip(',');
    parse_operand(s1, &ops[1]);
    जर (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    }

    जर (ops[0].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, रिक्त));
    }

    जर (ops[0].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, रिक्त));

    जर (ops[1].type != OP_REG32) {
        निवड (ARM_INSTRUCTION_GROUP(token)) {
        स्थिती TOK_ASM_movteq:
        स्थिती TOK_ASM_movweq:
            जर (ops[1].type == OP_IM8 || ops[1].type == OP_IM8N || ops[1].type == OP_IM32) {
                जर (ops[1].e.v >= 0 && ops[1].e.v <= 0xFFFF) {
                    uint16_t immediate_मूल्य = ops[1].e.v;
                    निवड (ARM_INSTRUCTION_GROUP(token)) {
                    स्थिती TOK_ASM_movteq:
                        asm_emit_opcode(token, 0x3400000 | (ops[0].reg << 12) | (immediate_मूल्य & 0xF000) << 4 | (immediate_मूल्य & 0xFFF));
                        थांबा;
                    स्थिती TOK_ASM_movweq:
                        asm_emit_opcode(token, 0x3000000 | (ops[0].reg << 12) | (immediate_मूल्य & 0xF000) << 4 | (immediate_मूल्य & 0xFFF));
                        थांबा;
                    }
                } अन्यथा
                    expect("(source operand) immediate 16 bit value");
            } अन्यथा
                expect("(source operand) immediate");
            थांबा;
        पूर्वनिर्धारित:
            expect("(source operand) register");
        }
        परत;
    }

    जर (ops[1].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, रिक्त));
    }

    जर (ops[1].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, रिक्त));

    जर (tok == ',') {
        next(); // skip ','
        जर (tok == TOK_ASM_ror) {
            next(); // skip 'ror'
            parse_operand(s1, &rotation);
            जर (rotation.type != OP_IM8) {
                expect("immediate value for rotation");
            } अन्यथा {
                amount = rotation.e.v;
                निवड (amount) {
                स्थिती 8:
                    encoded_rotation = 1 << 10;
                    थांबा;
                स्थिती 16:
                    encoded_rotation = 2 << 10;
                    थांबा;
                स्थिती 24:
                    encoded_rotation = 3 << 10;
                    थांबा;
                पूर्वनिर्धारित:
                    expect("'8' or '16' or '24'");
                }
            }
        }
    }
    निवड (ARM_INSTRUCTION_GROUP(token)) {
    स्थिती TOK_ASM_clzeq:
        जर (encoded_rotation)
            tcc_error("clz does not support rotation");
        asm_emit_opcode(token, 0x16f0f10 | (ops[0].reg << 12) | ops[1].reg);
        थांबा;
    स्थिती TOK_ASM_sxtbeq:
        asm_emit_opcode(token, 0x6af0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        थांबा;
    स्थिती TOK_ASM_sxtheq:
        asm_emit_opcode(token, 0x6bf0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        थांबा;
    स्थिती TOK_ASM_uxtbeq:
        asm_emit_opcode(token, 0x6ef0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        थांबा;
    स्थिती TOK_ASM_uxtheq:
        asm_emit_opcode(token, 0x6ff0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        थांबा;
    पूर्वनिर्धारित:
        expect("binary instruction");
    }
}

स्थिर शून्य asm_coprocessor_opcode(TCCState *s1, पूर्णांक token) {
    uint8_t coprocessor;
    Operand opcode1;
    Operand opcode2;
    uint8_t registers[3];
    अचिन्हित पूर्णांक i;
    uint8_t वरचा_nibble;
    uint8_t mrc = 0;

    जर (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        next();
    } अन्यथा {
        expect("'p<number>'");
    }
    skip(',');
    parse_operand(s1, &opcode1);
    जर (opcode1.type != OP_IM8 || opcode1.e.v > 15) {
        tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, रिक्त));
    }

    साठी (i = 0; i < 3; ++i) {
        skip(',');
        जर (i == 0 && token != TOK_ASM_cdp2 && (ARM_INSTRUCTION_GROUP(token) == TOK_ASM_mrceq || ARM_INSTRUCTION_GROUP(token) == TOK_ASM_mcreq)) {
            जर (tok >= TOK_ASM_r0 && tok <= TOK_ASM_pc) {
                registers[i] = asm_parse_regvar(tok);
                next();
            } अन्यथा {
                expect("'r<number>'");
            }
        } अन्यथा {
            जर (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
                registers[i] = tok - TOK_ASM_c0;
                next();
            } अन्यथा {
                expect("'c<number>'");
            }
        }
    }
    जर (tok == ',') {
        next();
        parse_operand(s1, &opcode2);
    } अन्यथा {
        opcode2.type = OP_IM8;
        opcode2.e.v = 0;
    }
    जर (opcode2.type != OP_IM8 || opcode2.e.v > 15) {
        tcc_error("opcode2 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, रिक्त));
    }

    जर (token == TOK_ASM_cdp2) {
        वरचा_nibble = 0xF;
        asm_emit_coprocessor_opcode(वरचा_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        परत;
    } अन्यथा
        वरचा_nibble = condition_code_of_token(token);

    निवड (ARM_INSTRUCTION_GROUP(token)) {
    स्थिती TOK_ASM_cdpeq:
        asm_emit_coprocessor_opcode(वरचा_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        थांबा;
    स्थिती TOK_ASM_mrceq:
        // opcode1 encoding changes! highest and lowest bit gone.
        mrc = 1;
        /* fallthrough */
    स्थिती TOK_ASM_mcreq:
        // opcode1 encoding changes! highest and lowest bit gone.
        जर (opcode1.e.v > 7) {
            tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 7", get_tok_str(token, रिक्त));
        }
        asm_emit_coprocessor_opcode(वरचा_nibble, coprocessor, (opcode1.e.v << 1) | mrc, registers[0], registers[1], registers[2], opcode2.e.v, 1);
        थांबा;
    पूर्वनिर्धारित:
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

स्थिर शून्य asm_block_data_transfer_opcode(TCCState *s1, पूर्णांक token)
{
    uint32_t opcode;
    पूर्णांक op0_exclam = 0;
    Operand ops[2];
    पूर्णांक nb_ops = 1;
    parse_operand(s1, &ops[0]);
    जर (tok == '!') {
        op0_exclam = 1;
        next(); // skip '!'
    }
    जर (tok == ',') {
        next(); // skip comma
        parse_operand(s1, &ops[1]);
        ++nb_ops;
    }
    जर (nb_ops < 1) {
        expect("at least one operand");
    } अन्यथा जर (ops[nb_ops - 1].type != OP_REGSET32) {
        expect("(last operand) register list");
    }

    // block data transfer: 1 0 0 P U S W L << 20 (general case):
    // operands:
    //   Rn: bits 19...16 base register
    //   Register List: bits 15...0

    निवड (ARM_INSTRUCTION_GROUP(token)) {
    स्थिती TOK_ASM_pusheq: // TODO: Optimize 1-register case to: str ?, [sp, #-4]!
        // Instruction: 1 I=0 P=1 U=0 S=0 W=1 L=0 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        जर (nb_ops != 1)
            expect("exactly one operand");
        अन्यथा
            asm_emit_opcode(token, (0x92d << 16) | ops[0].regset); // TODO: base register ?
        थांबा;
    स्थिती TOK_ASM_popeq: // TODO: Optimize 1-register case to: ldr ?, [sp], #4
        // Instruction: 1 I=0 P=0 U=1 S=0 W=0 L=1 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        जर (nb_ops != 1)
            expect("exactly one operand");
        अन्यथा
            asm_emit_opcode(token, (0x8bd << 16) | ops[0].regset); // TODO: base register ?
        थांबा;
    स्थिती TOK_ASM_stmdaeq:
    स्थिती TOK_ASM_ldmdaeq:
    स्थिती TOK_ASM_stmeq:
    स्थिती TOK_ASM_ldmeq:
    स्थिती TOK_ASM_stmiaeq:
    स्थिती TOK_ASM_ldmiaeq:
    स्थिती TOK_ASM_stmdbeq:
    स्थिती TOK_ASM_ldmdbeq:
    स्थिती TOK_ASM_stmibeq:
    स्थिती TOK_ASM_ldmibeq:
        निवड (ARM_INSTRUCTION_GROUP(token)) {
        स्थिती TOK_ASM_stmdaeq: // post-decrement store
            opcode = 0x80 << 20;
            थांबा;
        स्थिती TOK_ASM_ldmdaeq: // post-decrement load
            opcode = 0x81 << 20;
            थांबा;
        स्थिती TOK_ASM_stmeq: // post-increment store
        स्थिती TOK_ASM_stmiaeq: // post-increment store
            opcode = 0x88 << 20;
            थांबा;
        स्थिती TOK_ASM_ldmeq: // post-increment load
        स्थिती TOK_ASM_ldmiaeq: // post-increment load
            opcode = 0x89 << 20;
            थांबा;
        स्थिती TOK_ASM_stmdbeq: // pre-decrement store
            opcode = 0x90 << 20;
            थांबा;
        स्थिती TOK_ASM_ldmdbeq: // pre-decrement load
            opcode = 0x91 << 20;
            थांबा;
        स्थिती TOK_ASM_stmibeq: // pre-increment store
            opcode = 0x98 << 20;
            थांबा;
        स्थिती TOK_ASM_ldmibeq: // pre-increment load
            opcode = 0x99 << 20;
            थांबा;
        पूर्वनिर्धारित:
            tcc_error("internal error: This place should not be reached (fallback in asm_block_data_transfer_opcode)");
        }
        // operands:
        //    Rn: first operand
        //    Register List: lower bits
        जर (nb_ops != 2)
            expect("exactly two operands");
        अन्यथा जर (ops[0].type != OP_REG32)
            expect("(first operand) register");
        अन्यथा {
            जर (op0_exclam)
                opcode |= 1 << 21; // writeback
            asm_emit_opcode(token, opcode | ENCODE_RN(ops[0].reg) | ops[1].regset);
        }
        थांबा;
    पूर्वनिर्धारित:
        expect("block data transfer instruction");
    }
}

/* Parses shift directive and returns the parts that would have to be set in the opcode because of it.
   Does not encode the actual shift amount.
   It's not an error if there is no shift directive.

   NB_SHIFT: will be set to 1 iff SHIFT is filled.  Note that for rrx, there's no need to fill SHIFT.
   SHIFT: will be filled in with the shift operand to use, if any. */
स्थिर uint32_t asm_parse_optional_shift(TCCState* s1, पूर्णांक* nb_shift, Operand* shift)
{
    uint32_t opcode = 0;
    *nb_shift = 0;
    निवड (tok) {
    स्थिती TOK_ASM_asl:
    स्थिती TOK_ASM_lsl:
    स्थिती TOK_ASM_asr:
    स्थिती TOK_ASM_lsr:
    स्थिती TOK_ASM_ror:
        निवड (tok) {
        स्थिती TOK_ASM_asl:
            /* fallthrough */
        स्थिती TOK_ASM_lsl:
            opcode = ENCODE_BARREL_SHIFTER_MODE_LSL;
            थांबा;
        स्थिती TOK_ASM_asr:
            opcode = ENCODE_BARREL_SHIFTER_MODE_ASR;
            थांबा;
        स्थिती TOK_ASM_lsr:
            opcode = ENCODE_BARREL_SHIFTER_MODE_LSR;
            थांबा;
        स्थिती TOK_ASM_ror:
            opcode = ENCODE_BARREL_SHIFTER_MODE_ROR;
            थांबा;
        }
        next();
        parse_operand(s1, shift);
        *nb_shift = 1;
        थांबा;
    स्थिती TOK_ASM_rrx:
        next();
        opcode = ENCODE_BARREL_SHIFTER_MODE_ROR;
        थांबा;
    }
    परत opcode;
}

स्थिर uint32_t asm_encode_shift(Operand* shift)
{
    uint64_t amount;
    uint32_t operands = 0;
    निवड (shift->type) {
    स्थिती OP_REG32:
        जर (shift->reg == 15)
            tcc_error("r15 cannot be used as a shift count");
        अन्यथा {
            operands = ENCODE_BARREL_SHIFTER_SHIFT_BY_REGISTER;
            operands |= ENCODE_BARREL_SHIFTER_REGISTER(shift->reg);
        }
        थांबा;
    स्थिती OP_IM8:
        amount = shift->e.v;
        जर (amount > 0 && amount < 32)
            operands = ENCODE_BARREL_SHIFTER_IMMEDIATE(amount);
        अन्यथा
            tcc_error("shift count out of range");
        थांबा;
    पूर्वनिर्धारित:
        tcc_error("unknown shift amount");
    }
    परत operands;
}

स्थिर शून्य asm_data_processing_opcode(TCCState *s1, पूर्णांक token)
{
    Operand ops[3];
    पूर्णांक nb_ops;
    Operand shift = {0};
    पूर्णांक nb_shift = 0;
    uint32_t operands = 0;

    /* modulo 16 entries per instruction for the different condition codes */
    uint32_t opcode_idx = (ARM_INSTRUCTION_GROUP(token) - TOK_ASM_andeq) >> 4;
    uint32_t opcode_nos = opcode_idx >> 1; // without "s"; "OpCode" in ARM docs

    साठी (nb_ops = 0; nb_ops < आकार(ops)/आकार(ops[0]); ) {
        जर (tok == TOK_ASM_asl || tok == TOK_ASM_lsl || tok == TOK_ASM_lsr || tok == TOK_ASM_asr || tok == TOK_ASM_ror || tok == TOK_ASM_rrx)
            थांबा;
        parse_operand(s1, &ops[nb_ops]);
        ++nb_ops;
        जर (tok != ',')
            थांबा;
        next(); // skip ','
    }
    जर (tok == ',')
        next();
    operands |= asm_parse_optional_shift(s1, &nb_shift, &shift);
    जर (nb_ops < 2)
        expect("at least two operands");
    अन्यथा जर (nb_ops == 2) {
        स_नकल(&ops[2], &ops[1], आकार(ops[1])); // move ops[2]
        स_नकल(&ops[1], &ops[0], आकार(ops[0])); // ops[1] was implicit
        nb_ops = 3;
    } अन्यथा जर (nb_ops == 3) {
        जर (opcode_nos == 0xd || opcode_nos == 0xf || opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) { // mov, mvn, cmp, cmn, tst, teq
            tcc_error("'%s' cannot be used with three operands", get_tok_str(token, रिक्त));
        }
    }
    जर (nb_ops != 3) {
        expect("two or three operands");
    } अन्यथा {
        uint32_t opcode = 0;
        uint32_t immediate_मूल्य;
        uint8_t half_immediate_rotation;
        जर (nb_shift && shift.type == OP_REG32) {
            जर ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
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
        जर (ops[0].type != OP_REG32)
            expect("(destination operand) register");
        अन्यथा जर (opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) // cmp, cmn, tst, teq
            operands |= ENCODE_SET_CONDITION_CODES; // force S set, otherwise it's a completely different instruction.
        अन्यथा
            operands |= ENCODE_RD(ops[0].reg);
        जर (ops[1].type != OP_REG32)
            expect("(first source operand) register");
        अन्यथा जर (!(opcode_nos == 0xd || opcode_nos == 0xf)) // not: mov, mvn (those have only one source operand)
            operands |= ENCODE_RN(ops[1].reg);
        निवड (ops[2].type) {
        स्थिती OP_REG32:
            operands |= ops[2].reg;
            थांबा;
        स्थिती OP_IM8:
        स्थिती OP_IM32:
            operands |= ENCODE_IMMEDIATE_FLAG;
            immediate_मूल्य = ops[2].e.v;
            साठी (half_immediate_rotation = 0; half_immediate_rotation < 16; ++half_immediate_rotation) {
                जर (immediate_मूल्य >= 0x00 && immediate_मूल्य < 0x100)
                    थांबा;
                // rotate left by two
                immediate_मूल्य = ((immediate_मूल्य & 0x3FFFFFFF) << 2) | ((immediate_मूल्य & 0xC0000000) >> 30);
            }
            जर (half_immediate_rotation >= 16) {
                /* fallthrough */
            } अन्यथा {
                operands |= immediate_मूल्य;
                operands |= half_immediate_rotation << 8;
                थांबा;
            }
        स्थिती OP_IM8N: // immediate negative value
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
            निवड (opcode_nos) {
            स्थिती 0x0: // AND - Rd:= Op1 AND Op2
                opcode = 0xe << 21; // BIC
                immediate_मूल्य = ~immediate_मूल्य;
                थांबा;
            स्थिती 0x2: // SUB - Rd:= Op1 - Op2
                opcode = 0x4 << 21; // ADD
                immediate_मूल्य = -immediate_मूल्य;
                थांबा;
            स्थिती 0x4: // ADD - Rd:= Op1 + Op2
                opcode = 0x2 << 21; // SUB
                immediate_मूल्य = -immediate_मूल्य;
                थांबा;
            स्थिती 0x5: // ADC - Rd:= Op1 + Op2 + C
                opcode = 0x6 << 21; // SBC
                immediate_मूल्य = ~immediate_मूल्य;
                थांबा;
            स्थिती 0x6: // SBC - Rd:= Op1 - Op2 + C
                opcode = 0x5 << 21; // ADC
                immediate_मूल्य = ~immediate_मूल्य;
                थांबा;
            स्थिती 0xa: // CMP - CC on: Op1 - Op2
                opcode = 0xb << 21; // CMN
                immediate_मूल्य = -immediate_मूल्य;
                थांबा;
            स्थिती 0xb: // CMN - CC on: Op1 + Op2
                opcode = 0xa << 21; // CMP
                immediate_मूल्य = -immediate_मूल्य;
                थांबा;
            स्थिती 0xd: // MOV - Rd:= Op2
                opcode = 0xf << 21; // MVN
                immediate_मूल्य = ~immediate_मूल्य;
                थांबा;
            स्थिती 0xe: // BIC - Rd:= Op1 AND NOT Op2
                opcode = 0x0 << 21; // AND
                immediate_मूल्य = ~immediate_मूल्य;
                थांबा;
            स्थिती 0xf: // MVN - Rd:= NOT Op2
                opcode = 0xd << 21; // MOV
                immediate_मूल्य = ~immediate_मूल्य;
                थांबा;
            पूर्वनिर्धारित:
                tcc_error("cannot use '%s' with a negative immediate value", get_tok_str(token, रिक्त));
            }
            साठी (half_immediate_rotation = 0; half_immediate_rotation < 16; ++half_immediate_rotation) {
                जर (immediate_मूल्य >= 0x00 && immediate_मूल्य < 0x100)
                    थांबा;
                // rotate left by two
                immediate_मूल्य = ((immediate_मूल्य & 0x3FFFFFFF) << 2) | ((immediate_मूल्य & 0xC0000000) >> 30);
            }
            जर (half_immediate_rotation >= 16) {
                immediate_मूल्य = ops[2].e.v;
                tcc_error("immediate value 0x%X cannot be encoded into ARM immediate", (अचिन्हित) immediate_मूल्य);
            }
            operands |= immediate_मूल्य;
            operands |= half_immediate_rotation << 8;
            थांबा;
        पूर्वनिर्धारित:
            expect("(second source operand) register or immediate value");
        }

        जर (nb_shift) {
            जर (operands & ENCODE_IMMEDIATE_FLAG)
                tcc_error("immediate rotation not implemented");
            अन्यथा
                operands |= asm_encode_shift(&shift);
        }

        /* S=0 and S=1 entries alternate one after another, in that order */
        opcode |= (opcode_idx & 1) ? ENCODE_SET_CONDITION_CODES : 0;
        asm_emit_opcode(token, opcode | operands);
    }
}

स्थिर शून्य asm_shift_opcode(TCCState *s1, पूर्णांक token)
{
    Operand ops[3];
    पूर्णांक nb_ops;
    पूर्णांक definitely_neutral = 0;
    uint32_t opcode = 0xd << 21; // MOV
    uint32_t operands = 0;

    साठी (nb_ops = 0; nb_ops < आकार(ops)/आकार(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        जर (tok != ',') {
            ++nb_ops;
            थांबा;
        }
        next(); // skip ','
    }
    जर (nb_ops < 2) {
        expect("at least two operands");
    }

    जर (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    } अन्यथा
        operands |= ENCODE_RD(ops[0].reg);

    जर (nb_ops == 2) {
        निवड (ARM_INSTRUCTION_GROUP(token)) {
        स्थिती TOK_ASM_rrxseq:
            opcode |= ENCODE_SET_CONDITION_CODES;
            /* fallthrough */
        स्थिती TOK_ASM_rrxeq:
            जर (ops[1].type == OP_REG32) {
                operands |= ops[1].reg;
                operands |= ENCODE_BARREL_SHIFTER_MODE_ROR;
                asm_emit_opcode(token, opcode | operands);
            } अन्यथा
                tcc_error("(first source operand) register");
            परत;
        पूर्वनिर्धारित:
            स_नकल(&ops[2], &ops[1], आकार(ops[1])); // move ops[2]
            स_नकल(&ops[1], &ops[0], आकार(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
    }
    जर (nb_ops != 3) {
        expect("two or three operands");
    }

    निवड (ARM_INSTRUCTION_GROUP(token)) {
    स्थिती TOK_ASM_lslseq:
    स्थिती TOK_ASM_lsrseq:
    स्थिती TOK_ASM_asrseq:
    स्थिती TOK_ASM_rorseq:
        opcode |= ENCODE_SET_CONDITION_CODES;
        थांबा;
    }

    निवड (ops[1].type) {
    स्थिती OP_REG32:
        operands |= ops[1].reg;
        थांबा;
    स्थिती OP_IM8:
        operands |= ENCODE_IMMEDIATE_FLAG;
        operands |= ops[1].e.v;
        tcc_error("Using an immediate value as the source operand is not possible with '%s' instruction on ARM", get_tok_str(token, रिक्त));
    }

    निवड (ops[2].type) {
    स्थिती OP_REG32:
        जर ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
            (ops[1].type == OP_REG32 && ops[1].reg == 15)) {
            tcc_error("Using the 'pc' register in data processing instructions that have a register-controlled shift is not implemented by ARM");
        }
        operands |= asm_encode_shift(&ops[2]);
        थांबा;
    स्थिती OP_IM8:
        जर (ops[2].e.v)
            operands |= asm_encode_shift(&ops[2]);
        अन्यथा
            definitely_neutral = 1;
        थांबा;
    }

    जर (!definitely_neutral) निवड (ARM_INSTRUCTION_GROUP(token)) {
    स्थिती TOK_ASM_lslseq:
    स्थिती TOK_ASM_lsleq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_LSL;
        थांबा;
    स्थिती TOK_ASM_lsrseq:
    स्थिती TOK_ASM_lsreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_LSR;
        थांबा;
    स्थिती TOK_ASM_asrseq:
    स्थिती TOK_ASM_asreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_ASR;
        थांबा;
    स्थिती TOK_ASM_rorseq:
    स्थिती TOK_ASM_roreq:
        operands |= ENCODE_BARREL_SHIFTER_MODE_ROR;
        थांबा;
    पूर्वनिर्धारित:
        expect("shift instruction");
    }
    asm_emit_opcode(token, opcode | operands);
}

स्थिर शून्य asm_multiplication_opcode(TCCState *s1, पूर्णांक token)
{
    Operand ops[4];
    पूर्णांक nb_ops = 0;
    uint32_t opcode = 0x90;

    साठी (nb_ops = 0; nb_ops < आकार(ops)/आकार(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        जर (tok != ',') {
            ++nb_ops;
            थांबा;
        }
        next(); // skip ','
    }
    जर (nb_ops < 2)
        expect("at least two operands");
    अन्यथा जर (nb_ops == 2) {
        निवड (ARM_INSTRUCTION_GROUP(token)) {
        स्थिती TOK_ASM_mulseq:
        स्थिती TOK_ASM_muleq:
            स_नकल(&ops[2], &ops[0], आकार(ops[1])); // ARM is actually like this!
            थांबा;
        पूर्वनिर्धारित:
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

    जर (ops[0].type == OP_REG32)
        opcode |= ops[0].reg << 16;
    अन्यथा
        expect("(destination operand) register");
    जर (ops[1].type == OP_REG32)
        opcode |= ops[1].reg;
    अन्यथा
        expect("(first source operand) register");
    जर (ops[2].type == OP_REG32)
        opcode |= ops[2].reg << 8;
    अन्यथा
        expect("(second source operand) register");
    जर (nb_ops > 3) {
        जर (ops[3].type == OP_REG32)
            opcode |= ops[3].reg << 12;
        अन्यथा
            expect("(third source operand) register");
    }

    निवड (ARM_INSTRUCTION_GROUP(token)) {
    स्थिती TOK_ASM_mulseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    स्थिती TOK_ASM_muleq:
        जर (nb_ops != 3)
            expect("three operands");
        अन्यथा {
            asm_emit_opcode(token, opcode);
        }
        थांबा;
    स्थिती TOK_ASM_mlaseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    स्थिती TOK_ASM_mlaeq:
    case_TOK_ASM_mlaeq:
        जर (nb_ops != 4)
            expect("four operands");
        अन्यथा {
            opcode |= 1 << 21; // Accumulate
            asm_emit_opcode(token, opcode);
        }
        थांबा;
    स्थिती TOK_ASM_mlseq:
        opcode |= 0x00400000;
        जा case_TOK_ASM_mlaeq;
    स्थिती TOK_ASM_udiveq:
        opcode |= 0x00200000;
    स्थिती TOK_ASM_sdiveq:
        asm_emit_opcode(token, (opcode & ~0x80) | 0x0710f010);
        थांबा;
    पूर्वनिर्धारित:
        expect("known multiplication instruction");
    }
}

स्थिर शून्य asm_long_multiplication_opcode(TCCState *s1, पूर्णांक token)
{
    Operand ops[4];
    पूर्णांक nb_ops = 0;
    uint32_t opcode = 0x90 | (1 << 23);

    साठी (nb_ops = 0; nb_ops < आकार(ops)/आकार(ops[0]); ++nb_ops) {
        parse_operand(s1, &ops[nb_ops]);
        जर (tok != ',') {
            ++nb_ops;
            थांबा;
        }
        next(); // skip ','
    }
    जर (nb_ops != 4) {
        expect("four operands");
    }

    // long multiply (special case):
    // operands:
    //   RdLo: bits 15...12
    //   RdHi: bits 19...16
    //   Rs: bits 11...8
    //   Rm: bits 3...0

    जर (ops[0].type == OP_REG32)
        opcode |= ops[0].reg << 12;
    अन्यथा
        expect("(destination lo accumulator) register");
    जर (ops[1].type == OP_REG32)
        opcode |= ops[1].reg << 16;
    अन्यथा
        expect("(destination hi accumulator) register");
    जर (ops[2].type == OP_REG32)
        opcode |= ops[2].reg;
    अन्यथा
        expect("(first source operand) register");
    जर (ops[3].type == OP_REG32)
        opcode |= ops[3].reg << 8;
    अन्यथा
        expect("(second source operand) register");

    निवड (ARM_INSTRUCTION_GROUP(token)) {
    स्थिती TOK_ASM_smullseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    स्थिती TOK_ASM_smulleq:
        opcode |= 1 << 22; // signed
        asm_emit_opcode(token, opcode);
        थांबा;
    स्थिती TOK_ASM_umullseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    स्थिती TOK_ASM_umulleq:
        asm_emit_opcode(token, opcode);
        थांबा;
    स्थिती TOK_ASM_smlalseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    स्थिती TOK_ASM_smlaleq:
        opcode |= 1 << 22; // signed
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        थांबा;
    स्थिती TOK_ASM_umlalseq:
        opcode |= 1 << 20; // Status
        /* fallthrough */
    स्थिती TOK_ASM_umlaleq:
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        थांबा;
    पूर्वनिर्धारित:
        expect("known long multiplication instruction");
    }
}

स्थिर शून्य asm_single_data_transfer_opcode(TCCState *s1, पूर्णांक token)
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
    जर (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    अन्यथा {
        expect("(destination operand) register");
    }
    जर (tok != ',')
        expect("at least two arguments");
    next(); // skip ','

    निवड (ARM_INSTRUCTION_GROUP(token)) {
    स्थिती TOK_ASM_strexheq:
    स्थिती TOK_ASM_strexbeq:
    स्थिती TOK_ASM_strexeq:
        parse_operand(s1, &strex_operand);
        जर (strex_operand.type != OP_REG32) {
            expect("register");
        }
        जर (tok != ',')
            expect("at least three arguments");
        अन्यथा
            next(); // skip ','
        थांबा;
    }

    skip('[');
    parse_operand(s1, &ops[1]);
    जर (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    अन्यथा {
        expect("(first source operand) register");
    }
    जर (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    जर (tok == ',') {
        next(); // skip ','
        जर (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
        जर (ops[2].type == OP_REG32) {
            जर (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, रिक्त));
            }
            जर (tok == ',') {
                next();
                opcode |= asm_parse_optional_shift(s1, &nb_shift, &shift);
                जर (opcode == 0)
                    expect("shift directive, or no comma");
            }
        }
    } अन्यथा {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        opcode |= 1 << 24; // add offset before transfer
    }
    जर (!closed_bracket) {
        skip(']');
        opcode |= 1 << 24; // add offset before transfer
        जर (tok == '!') {
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
    जर (exclam)
        opcode |= 1 << 21; // write offset back into register

    जर (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        पूर्णांक v = ops[2].e.v;
        जर (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        जर (v >= 0) {
            opcode |= 1 << 23; // up
            जर (v >= 0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, रिक्त));
            अन्यथा
                opcode |= v;
        } अन्यथा { // down
            जर (v <= -0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, रिक्त));
            अन्यथा
                opcode |= -v;
        }
    } अन्यथा जर (ops[2].type == OP_REG32) {
        जर (!op2_minus)
            opcode |= 1 << 23; // up
        opcode |= ENCODE_IMMEDIATE_FLAG; /* if set, it means it's NOT immediate */
        opcode |= ops[2].reg;
    } अन्यथा
        expect("register");

    निवड (ARM_INSTRUCTION_GROUP(token)) {
    स्थिती TOK_ASM_strbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    स्थिती TOK_ASM_streq:
        opcode |= 1 << 26; // Load/Store
        जर (nb_shift)
            opcode |= asm_encode_shift(&shift);
        asm_emit_opcode(token, opcode);
        थांबा;
    स्थिती TOK_ASM_ldrbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    स्थिती TOK_ASM_ldreq:
        opcode |= 1 << 20; // L
        opcode |= 1 << 26; // Load/Store
        जर (nb_shift)
            opcode |= asm_encode_shift(&shift);
        asm_emit_opcode(token, opcode);
        थांबा;
    स्थिती TOK_ASM_strexheq:
        opcode |= 1 << 21;
    स्थिती TOK_ASM_strexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    स्थिती TOK_ASM_strexeq:
        जर ((opcode & 0xFFF) || nb_shift) {
            tcc_error("neither offset nor shift allowed with 'strex'");
        } अन्यथा जर (opcode & ENCODE_IMMEDIATE_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'strex'");
        }
        जर ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'strex'");
        }

        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        opcode |= strex_operand.reg;
        asm_emit_opcode(token, opcode);
        थांबा;
    स्थिती TOK_ASM_ldrexheq:
        opcode |= 1 << 21;
    स्थिती TOK_ASM_ldrexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    स्थिती TOK_ASM_ldrexeq:
        जर ((opcode & 0xFFF) || nb_shift) {
            tcc_error("neither offset nor shift allowed with 'ldrex'");
        } अन्यथा जर (opcode & ENCODE_IMMEDIATE_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'ldrex'");
        }
        जर ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'ldrex'");
        }
        opcode |= 1 << 20; // L
        opcode |= 0x00f;
        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        asm_emit_opcode(token, opcode);
        थांबा;
    पूर्वनिर्धारित:
        expect("data transfer instruction");
    }
}

// Note: Only call this using a VFP register if you know exactly what you are doing (i.e. cp_number is 10 or 11 and you are doing a vmov)
स्थिर शून्य asm_emit_coprocessor_data_transfer(uint32_t वरचा_nibble, uint8_t cp_संख्या, uint8_t CRd, स्थिरांक Operand* Rn, स्थिरांक Operand* offset, पूर्णांक offset_minus, पूर्णांक preincrement, पूर्णांक writeback, पूर्णांक long_transfer, पूर्णांक load) {
    uint32_t opcode = 0x0;
    opcode |= 1 << 26; // Load/Store
    opcode |= 1 << 27; // coprocessor

    जर (long_transfer)
        opcode |= 1 << 22; // long transfer

    जर (load)
        opcode |= 1 << 20; // L

    opcode |= cp_संख्या << 8;

    //assert(CRd < 16);
    opcode |= ENCODE_RD(CRd);

    जर (Rn->type != OP_REG32)
        expect("register");

    //assert(Rn->reg < 16);
    opcode |= ENCODE_RN(Rn->reg);
    जर (preincrement)
        opcode |= 1 << 24; // add offset before transfer

    जर (writeback)
        opcode |= 1 << 21; // write offset back into register

    जर (offset->type == OP_IM8 || offset->type == OP_IM8N || offset->type == OP_IM32) {
        पूर्णांक v = offset->e.v;
        जर (offset_minus)
            tcc_error("minus before '#' not supported for immediate values");
        जर (offset->type == OP_IM8N || v < 0)
            v = -v;
        अन्यथा
            opcode |= 1 << 23; // up
        जर (v & 3) {
            tcc_error("immediate offset must be a multiple of 4");
        }
        v >>= 2;
        जर (v > 255) {
            tcc_error("immediate offset must be between -1020 and 1020");
        }
        opcode |= v;
    } अन्यथा जर (offset->type == OP_REG32) {
        जर (!offset_minus)
            opcode |= 1 << 23; // up
        opcode |= ENCODE_IMMEDIATE_FLAG; /* if set, it means it's NOT immediate */
        opcode |= offset->reg;
        tcc_error("Using register offset to register address is not possible here");
    } अन्यथा जर (offset->type == OP_VREG64) {
        opcode |= 16;
        opcode |= offset->reg;
    } अन्यथा
        expect("immediate or register");

    asm_emit_unconditional_opcode((वरचा_nibble << 28) | opcode);
}

// Almost exactly the same as asm_single_data_transfer_opcode.
// Difference: Offsets are smaller and multiples of 4; no shifts, no STREX, ENCODE_IMMEDIATE_FLAG is inverted again.
स्थिर शून्य asm_coprocessor_data_transfer_opcode(TCCState *s1, पूर्णांक token)
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

    जर (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        next();
    } अन्यथा {
        expect("'c<number>'");
    }

    skip(',');

    जर (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
        coprocessor_destination_register = tok - TOK_ASM_c0;
        next();
    } अन्यथा {
        expect("'c<number>'");
    }

    skip(',');
    skip('[');
    parse_operand(s1, &ops[1]);
    जर (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    जर (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    जर (tok == ',') {
        next(); // skip ','
        जर (tok == '-') {
            op2_minus = 1;
            next();
        }
        parse_operand(s1, &ops[2]);
        जर (ops[2].type == OP_REG32) {
            जर (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, रिक्त));
            }
        } अन्यथा जर (ops[2].type == OP_VREG64) {
            tcc_error("'%s' does not support VFP register operand", get_tok_str(token, रिक्त));
        }
    } अन्यथा {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        preincrement = 1; // add offset before transfer
    }
    जर (!closed_bracket) {
        skip(']');
        preincrement = 1; // add offset before transfer
        जर (tok == '!') {
            exclam = 1;
            next(); // skip '!'
        }
    }

    // TODO: Support options.

    जर (token == TOK_ASM_ldc2 || token == TOK_ASM_stc2 || token == TOK_ASM_ldc2l || token == TOK_ASM_stc2l) {
        निवड (token) {
        स्थिती TOK_ASM_ldc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        स्थिती TOK_ASM_ldc2:
            asm_emit_coprocessor_data_transfer(0xF, coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
            थांबा;
        स्थिती TOK_ASM_stc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        स्थिती TOK_ASM_stc2:
            asm_emit_coprocessor_data_transfer(0xF, coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
            थांबा;
        }
    } अन्यथा निवड (ARM_INSTRUCTION_GROUP(token)) {
    स्थिती TOK_ASM_stcleq:
        long_transfer = 1;
        /* fallthrough */
    स्थिती TOK_ASM_stceq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
        थांबा;
    स्थिती TOK_ASM_ldcleq:
        long_transfer = 1;
        /* fallthrough */
    स्थिती TOK_ASM_ldceq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
        थांबा;
    पूर्वनिर्धारित:
        expect("coprocessor data transfer instruction");
    }
}

#जर defined(TCC_ARM_VFP)
#define CP_SINGLE_PRECISION_FLOAT 10
#define CP_DOUBLE_PRECISION_FLOAT 11

स्थिर शून्य asm_floating_point_single_data_transfer_opcode(TCCState *s1, पूर्णांक token)
{
    Operand ops[3];
    uint8_t coprocessor = 0;
    uint8_t coprocessor_destination_register = 0;
    पूर्णांक long_transfer = 0;
    // Note: vldr p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: Not allowed: vldr p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: Not allowed: vldr p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_operand(s1, &ops[0]);
    जर (ops[0].type == OP_VREG32) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        coprocessor_destination_register = ops[0].reg;
        long_transfer = coprocessor_destination_register & 1;
        coprocessor_destination_register >>= 1;
    } अन्यथा जर (ops[0].type == OP_VREG64) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        coprocessor_destination_register = ops[0].reg;
        next();
    } अन्यथा {
        expect("floating point register");
    }

    skip(',');
    skip('[');
    parse_operand(s1, &ops[1]);
    जर (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    जर (tok == ',') {
        next(); // skip ','
        parse_operand(s1, &ops[2]);
        जर (ops[2].type != OP_IM8 && ops[2].type != OP_IM8N) {
            expect("immediate offset");
        }
    } अन्यथा {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
    }
    skip(']');

    निवड (ARM_INSTRUCTION_GROUP(token)) {
    स्थिती TOK_ASM_vldreq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], 0, 1, 0, long_transfer, 1);
        थांबा;
    स्थिती TOK_ASM_vstreq:
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, coprocessor_destination_register, &ops[1], &ops[2], 0, 1, 0, long_transfer, 0);
        थांबा;
    पूर्वनिर्धारित:
        expect("floating point data transfer instruction");
    }
}

स्थिर शून्य asm_floating_point_block_data_transfer_opcode(TCCState *s1, पूर्णांक token)
{
    uint8_t coprocessor = 0;
    पूर्णांक first_regset_register;
    पूर्णांक last_regset_register;
    uint8_t regset_item_मोजणी;
    uint8_t extra_register_bit = 0;
    पूर्णांक op0_exclam = 0;
    पूर्णांक load = 0;
    पूर्णांक preincrement = 0;
    Operand ops[1];
    Operand offset;
    निवड (ARM_INSTRUCTION_GROUP(token)) {
    स्थिती TOK_ASM_vpusheq:
    स्थिती TOK_ASM_vpopeq:
        ops[0].type = OP_REG32;
        ops[0].reg = 13; // sp
        op0_exclam = 1;
        थांबा;
    पूर्वनिर्धारित:
        parse_operand(s1, &ops[0]);
        जर (tok == '!') {
            op0_exclam = 1;
            next(); // skip '!'
        }
        skip(',');
    }

    skip('{');
    first_regset_register = asm_parse_vfp_regvar(tok, 1);
    जर ((first_regset_register = asm_parse_vfp_regvar(tok, 1)) != -1) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        next();
    } अन्यथा जर ((first_regset_register = asm_parse_vfp_regvar(tok, 0)) != -1) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        next();
    } अन्यथा {
        expect("floating-point register");
    }

    जर (tok == '-') {
        next();
        जर ((last_regset_register = asm_parse_vfp_regvar(tok, coprocessor == CP_DOUBLE_PRECISION_FLOAT)) != -1)
            next();
        अन्यथा {
            expect("floating-point register");
        }
    } अन्यथा
        last_regset_register = first_regset_register;

    जर (last_regset_register < first_regset_register) {
        tcc_error("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
    }
    skip('}');
    // Note: 0 (one down) is not implemented by us regardless.
    regset_item_मोजणी = last_regset_register - first_regset_register + 1;
    जर (coprocessor == CP_DOUBLE_PRECISION_FLOAT)
        regset_item_मोजणी <<= 1;
    अन्यथा {
        extra_register_bit = first_regset_register & 1;
        first_regset_register >>= 1;
    }
    offset.type = OP_IM8;
    offset.e.v = regset_item_मोजणी << 2;
    निवड (ARM_INSTRUCTION_GROUP(token)) {
    स्थिती TOK_ASM_vstmeq: // post-increment store
    स्थिती TOK_ASM_vstmiaeq: // post-increment store
        थांबा;
    स्थिती TOK_ASM_vpopeq:
    स्थिती TOK_ASM_vldmeq: // post-increment load
    स्थिती TOK_ASM_vldmiaeq: // post-increment load
        load = 1;
        थांबा;
    स्थिती TOK_ASM_vldmdbeq: // pre-decrement load
        load = 1;
        /* fallthrough */
    स्थिती TOK_ASM_vpusheq:
    स्थिती TOK_ASM_vstmdbeq: // pre-decrement store
        offset.type = OP_IM8N;
        offset.e.v = -offset.e.v;
        preincrement = 1;
        थांबा;
    पूर्वनिर्धारित:
        expect("floating point block data transfer instruction");
    }
    जर (ops[0].type != OP_REG32)
        expect("(first operand) register");
    अन्यथा जर (ops[0].reg == 15)
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, रिक्त));
    अन्यथा जर (!op0_exclam && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vldmeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vldmiaeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vstmeq && ARM_INSTRUCTION_GROUP(token) != TOK_ASM_vstmiaeq)
        tcc_error("first operand of '%s' should have an exclamation mark", get_tok_str(token, रिक्त));
    अन्यथा
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, first_regset_register, &ops[0], &offset, 0, preincrement, op0_exclam, extra_register_bit, load);
}

#define VMOV_FRACTIONAL_DIGITS 7
#define VMOV_ONE 10000000 /* pow(10, VMOV_FRACTIONAL_DIGITS) */

स्थिर uint32_t vmov_parse_fractional_part(स्थिरांक अक्षर* s)
{
    uint32_t result = 0;
    पूर्णांक i;
    साठी (i = 0; i < VMOV_FRACTIONAL_DIGITS; ++i) {
        अक्षर c = *s;
        result *= 10;
        जर (c >= '0' && c <= '9') {
            result += (c - '0');
            ++s;
        }
    }
    जर (*s)
        expect("decimal numeral");
    परत result;
}

स्थिर पूर्णांक vmov_linear_approx_index(uint32_t beginning, uint32_t end, uint32_t मूल्य)
{
    पूर्णांक i;
    uint32_t k;
    uint32_t xvalue;

    k = (end - beginning)/16;
    साठी (xvalue = beginning, i = 0; i < 16; ++i, xvalue += k) {
        जर (मूल्य == xvalue)
            परत i;
    }
    //assert(0);
    परत -1;
}

स्थिर uint32_t vmov_parse_immediate_मूल्य() {
    uint32_t मूल्य;
    अचिन्हित दीर्घ integral_मूल्य;
    स्थिरांक अक्षर *p;

    जर (tok != TOK_PPNUM) {
        expect("immediate value");
    }
    p = tokc.str.data;
    त्रुटि_सं = 0;
    integral_मूल्य = म_से_अदीर्घ(p, (अक्षर **)&p, 0);

    जर (त्रुटि_सं || integral_मूल्य >= 32) {
        tcc_error("invalid floating-point immediate value");
    }

    मूल्य = (uint32_t) integral_मूल्य * VMOV_ONE;
    जर (*p == '.') {
        ++p;
        मूल्य += vmov_parse_fractional_part(p);
    }
    next();
    परत मूल्य;
}

स्थिर uint8_t vmov_encode_immediate_मूल्य(uint32_t मूल्य)
{
    uint32_t limit;
    uint32_t end = 0;
    uint32_t beginning = 0;
    पूर्णांक r = -1;
    पूर्णांक n;
    पूर्णांक i;

    limit = 32 * VMOV_ONE;
    साठी (i = 0; i < 8; ++i) {
        जर (मूल्य < limit) {
            end = limit;
            limit >>= 1;
            beginning = limit;
            r = i;
        } अन्यथा
            limit >>= 1;
    }
    जर (r == -1 || मूल्य < beginning || मूल्य > end) {
        tcc_error("invalid decimal number for vmov: %d", मूल्य);
    }
    n = vmov_linear_approx_index(beginning, end, मूल्य);
    परत n | (((3 - r) & 0x7) << 4);
}

// Not standalone.
स्थिर शून्य asm_floating_point_immediate_data_processing_opcode_tail(TCCState *s1, पूर्णांक token, uint8_t coprocessor, uint8_t CRd) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    uint8_t operands[3] = {0, 0, 0};
    uint32_t immediate_मूल्य = 0;
    पूर्णांक op_minus = 0;
    uint8_t code;

    operands[0] = CRd;

    जर (tok == '#' || tok == '$') {
        next();
    }
    जर (tok == '-') {
        op_minus = 1;
        next();
    }
    immediate_मूल्य = vmov_parse_immediate_मूल्य();

    opcode1 = 11; // "Other" instruction
    निवड (ARM_INSTRUCTION_GROUP(token)) {
    स्थिती TOK_ASM_vcmpeq_f32:
    स्थिती TOK_ASM_vcmpeq_f64:
        opcode2 = 2;
        operands[1] = 5;
        जर (immediate_मूल्य) {
            expect("Immediate value 0");
        }
        थांबा;
    स्थिती TOK_ASM_vcmpeeq_f32:
    स्थिती TOK_ASM_vcmpeeq_f64:
        opcode2 = 6;
        operands[1] = 5;
        जर (immediate_मूल्य) {
            expect("Immediate value 0");
        }
        थांबा;
    स्थिती TOK_ASM_vmoveq_f32:
    स्थिती TOK_ASM_vmoveq_f64:
        opcode2 = 0;
        जर (op_minus)
            operands[1] = 0x8;
        अन्यथा
            operands[1] = 0x0;
        code = vmov_encode_immediate_मूल्य(immediate_मूल्य);
        operands[1] |= code >> 4;
        operands[2] = code & 0xF;
        थांबा;
    पूर्वनिर्धारित:
        expect("known floating point with immediate instruction");
    }

    जर (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        जर (operands[0] & 1)
            opcode1 |= 4;
        operands[0] >>= 1;
    }

    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, operands[0], operands[1], operands[2], opcode2, 0);
}

स्थिर शून्य asm_floating_point_reg_arm_reg_transfer_opcode_tail(TCCState *s1, पूर्णांक token, पूर्णांक coprocessor, पूर्णांक nb_arm_regs, पूर्णांक nb_ops, Operand ops[3]) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    निवड (coprocessor) {
    स्थिती CP_SINGLE_PRECISION_FLOAT:
        // "vmov.f32 r2, s3" or "vmov.f32 s3, r2"
        जर (nb_ops != 2 || nb_arm_regs != 1) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and one ARM register operands");
        }
        जर (ops[0].type != OP_REG32) { // determine mode: load or store
            // need to swap operands 0 and 1
            स_नकल(&ops[2], &ops[1], आकार(ops[2]));
            स_नकल(&ops[1], &ops[0], आकार(ops[1]));
            स_नकल(&ops[0], &ops[2], आकार(ops[0]));
        } अन्यथा
            opcode1 |= 1;

        जर (ops[1].type == OP_VREG32) {
            जर (ops[1].reg & 1)
                opcode2 |= 4;
            ops[1].reg >>= 1;
        }

        जर (ops[0].type == OP_VREG32) {
            जर (ops[0].reg & 1)
                opcode1 |= 4;
            ops[0].reg >>= 1;
        }

        asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, 0x10, opcode2, 0);
        थांबा;
    स्थिती CP_DOUBLE_PRECISION_FLOAT:
        जर (nb_ops != 3 || nb_arm_regs != 2) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and two ARM register operands");
        }
        // Determine whether it's a store into a VFP register (vmov "d1, r2, r3") rather than "vmov r2, r3, d1"
        जर (ops[0].type == OP_VREG64) {
            जर (ops[2].type == OP_REG32) {
                Operand temp;
                // need to rotate operand list to the left
                स_नकल(&temp, &ops[0], आकार(temp));
                स_नकल(&ops[0], &ops[1], आकार(ops[0]));
                स_नकल(&ops[1], &ops[2], आकार(ops[1]));
                स_नकल(&ops[2], &temp, आकार(ops[2]));
            } अन्यथा {
                tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
            }
        } अन्यथा जर (ops[0].type != OP_REG32 || ops[1].type != OP_REG32 || ops[2].type != OP_VREG64) {
            tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
        } अन्यथा {
            opcode1 |= 1;
        }
        asm_emit_coprocessor_data_transfer(condition_code_of_token(token), coprocessor, ops[0].reg, &ops[1], &ops[2], 0, 0, 0, 1, opcode1);
        थांबा;
    पूर्वनिर्धारित:
        tcc_internal_error("unknown coprocessor");
    }
}

स्थिर शून्य asm_floating_point_vcvt_data_processing_opcode(TCCState *s1, पूर्णांक token) {
    uint8_t coprocessor = 0;
    Operand ops[3];
    uint8_t opcode1 = 11;
    uint8_t opcode2 = 2;

    निवड (ARM_INSTRUCTION_GROUP(token)) {
    स्थिती TOK_ASM_vcvtreq_s32_f64:
    स्थिती TOK_ASM_vcvtreq_u32_f64:
    स्थिती TOK_ASM_vcvteq_s32_f64:
    स्थिती TOK_ASM_vcvteq_u32_f64:
    स्थिती TOK_ASM_vcvteq_f64_s32:
    स्थिती TOK_ASM_vcvteq_f64_u32:
    स्थिती TOK_ASM_vcvteq_f32_f64:
       coprocessor = CP_DOUBLE_PRECISION_FLOAT;
       थांबा;
    स्थिती TOK_ASM_vcvtreq_s32_f32:
    स्थिती TOK_ASM_vcvtreq_u32_f32:
    स्थिती TOK_ASM_vcvteq_s32_f32:
    स्थिती TOK_ASM_vcvteq_u32_f32:
    स्थिती TOK_ASM_vcvteq_f32_s32:
    स्थिती TOK_ASM_vcvteq_f32_u32:
    स्थिती TOK_ASM_vcvteq_f64_f32:
       coprocessor = CP_SINGLE_PRECISION_FLOAT;
       थांबा;
    पूर्वनिर्धारित:
       tcc_error("Unknown coprocessor for instruction '%s'", get_tok_str(token, रिक्त));
    }

    parse_operand(s1, &ops[0]);
    ops[1].type = OP_IM8;
    ops[1].e.v = 8;
    /* floating-point -> integer */
    निवड (ARM_INSTRUCTION_GROUP(token)) {
    स्थिती TOK_ASM_vcvtreq_s32_f32:
    स्थिती TOK_ASM_vcvtreq_s32_f64:
    स्थिती TOK_ASM_vcvteq_s32_f32:
    स्थिती TOK_ASM_vcvteq_s32_f64:
        ops[1].e.v |= 1; // signed
        /* fall through */
    स्थिती TOK_ASM_vcvteq_u32_f32:
    स्थिती TOK_ASM_vcvteq_u32_f64:
    स्थिती TOK_ASM_vcvtreq_u32_f32:
    स्थिती TOK_ASM_vcvtreq_u32_f64:
        ops[1].e.v |= 4; // to_integer (opc2)
        थांबा;
    /* floating-point size conversion */
    स्थिती TOK_ASM_vcvteq_f64_f32:
    स्थिती TOK_ASM_vcvteq_f32_f64:
        ops[1].e.v = 7;
        थांबा;
    }

    skip(',');
    parse_operand(s1, &ops[2]);

    निवड (ARM_INSTRUCTION_GROUP(token)) {
    /* floating-point -> integer */
    स्थिती TOK_ASM_vcvteq_s32_f32:
    स्थिती TOK_ASM_vcvteq_s32_f64:
    स्थिती TOK_ASM_vcvteq_u32_f32:
    स्थिती TOK_ASM_vcvteq_u32_f64:
        opcode2 |= 4; // round_zero
        थांबा;

    /* integer -> floating-point */
    स्थिती TOK_ASM_vcvteq_f64_s32:
    स्थिती TOK_ASM_vcvteq_f32_s32:
        opcode2 |= 4; // signed--special
        थांबा;

    /* floating-point size conversion */
    स्थिती TOK_ASM_vcvteq_f64_f32:
    स्थिती TOK_ASM_vcvteq_f32_f64:
        opcode2 |= 4; // always set
        थांबा;
    }

    निवड (ARM_INSTRUCTION_GROUP(token)) {
    स्थिती TOK_ASM_vcvteq_f64_u32:
    स्थिती TOK_ASM_vcvteq_f64_s32:
    स्थिती TOK_ASM_vcvteq_f64_f32:
        जर (ops[0].type == OP_VREG64 && ops[2].type == OP_VREG32) {
        } अन्यथा {
            expect("d<number>, s<number>");
        }
        थांबा;
    पूर्वनिर्धारित:
        जर (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
            जर (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG32) {
            } अन्यथा {
                expect("s<number>, s<number>");
            }
        } अन्यथा जर (coprocessor == CP_DOUBLE_PRECISION_FLOAT) {
            जर (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG64) {
            } अन्यथा {
                expect("s<number>, d<number>");
            }
        }
    }

    जर (ops[2].type == OP_VREG32) {
        जर (ops[2].reg & 1)
            opcode2 |= 1;
        ops[2].reg >>= 1;
    }
    जर (ops[0].type == OP_VREG32) {
        जर (ops[0].reg & 1)
            opcode1 |= 4;
        ops[0].reg >>= 1;
    }
    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

स्थिर शून्य asm_floating_point_data_processing_opcode(TCCState *s1, पूर्णांक token) {
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

    निवड (ARM_INSTRUCTION_GROUP(token)) {
    स्थिती TOK_ASM_vmlaeq_f64:
    स्थिती TOK_ASM_vmlseq_f64:
    स्थिती TOK_ASM_vnmlseq_f64:
    स्थिती TOK_ASM_vnmlaeq_f64:
    स्थिती TOK_ASM_vmuleq_f64:
    स्थिती TOK_ASM_vnmuleq_f64:
    स्थिती TOK_ASM_vaddeq_f64:
    स्थिती TOK_ASM_vsubeq_f64:
    स्थिती TOK_ASM_vdiveq_f64:
    स्थिती TOK_ASM_vnegeq_f64:
    स्थिती TOK_ASM_vabseq_f64:
    स्थिती TOK_ASM_vsqrteq_f64:
    स्थिती TOK_ASM_vcmpeq_f64:
    स्थिती TOK_ASM_vcmpeeq_f64:
    स्थिती TOK_ASM_vmoveq_f64:
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
    }

    निवड (ARM_INSTRUCTION_GROUP(token)) {
    स्थिती TOK_ASM_vmoveq_f32:
    स्थिती TOK_ASM_vmoveq_f64:
        vmov = 1;
        थांबा;
    }

    साठी (nb_ops = 0; nb_ops < 3; ) {
        // Note: Necessary because parse_operand can't parse decimal numerals.
        जर (nb_ops == 1 && (tok == '#' || tok == '$' || tok == TOK_PPNUM || tok == '-')) {
            asm_floating_point_immediate_data_processing_opcode_tail(s1, token, coprocessor, ops[0].reg);
            परत;
        }
        parse_operand(s1, &ops[nb_ops]);
        जर (vmov && ops[nb_ops].type == OP_REG32) {
            ++nb_arm_regs;
        } अन्यथा जर (ops[nb_ops].type == OP_VREG32) {
            जर (coprocessor != CP_SINGLE_PRECISION_FLOAT) {
                expect("'s<number>'");
            }
        } अन्यथा जर (ops[nb_ops].type == OP_VREG64) {
            जर (coprocessor != CP_DOUBLE_PRECISION_FLOAT) {
                expect("'d<number>'");
            }
        } अन्यथा {
            expect("floating point register");
        }
        ++nb_ops;
        जर (tok == ',')
            next();
        अन्यथा
            थांबा;
    }

    जर (nb_arm_regs == 0) {
        जर (nb_ops == 2) { // implicit
            स_नकल(&ops[2], &ops[1], आकार(ops[1])); // move ops[2]
            स_नकल(&ops[1], &ops[0], आकार(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
        जर (nb_ops < 3) {
            tcc_error("Not enough operands for '%s' (%u)", get_tok_str(token, रिक्त), nb_ops);
        }
    }

    निवड (ARM_INSTRUCTION_GROUP(token)) {
    स्थिती TOK_ASM_vmlaeq_f32:
    स्थिती TOK_ASM_vmlaeq_f64:
        opcode1 = 0;
        opcode2 = 0;
        थांबा;
    स्थिती TOK_ASM_vmlseq_f32:
    स्थिती TOK_ASM_vmlseq_f64:
        opcode1 = 0;
        opcode2 = 2;
        थांबा;
    स्थिती TOK_ASM_vnmlseq_f32:
    स्थिती TOK_ASM_vnmlseq_f64:
        opcode1 = 1;
        opcode2 = 0;
        थांबा;
    स्थिती TOK_ASM_vnmlaeq_f32:
    स्थिती TOK_ASM_vnmlaeq_f64:
        opcode1 = 1;
        opcode2 = 2;
        थांबा;
    स्थिती TOK_ASM_vmuleq_f32:
    स्थिती TOK_ASM_vmuleq_f64:
        opcode1 = 2;
        opcode2 = 0;
        थांबा;
    स्थिती TOK_ASM_vnmuleq_f32:
    स्थिती TOK_ASM_vnmuleq_f64:
        opcode1 = 2;
        opcode2 = 2;
        थांबा;
    स्थिती TOK_ASM_vaddeq_f32:
    स्थिती TOK_ASM_vaddeq_f64:
        opcode1 = 3;
        opcode2 = 0;
        थांबा;
    स्थिती TOK_ASM_vsubeq_f32:
    स्थिती TOK_ASM_vsubeq_f64:
        opcode1 = 3;
        opcode2 = 2;
        थांबा;
    स्थिती TOK_ASM_vdiveq_f32:
    स्थिती TOK_ASM_vdiveq_f64:
        opcode1 = 8;
        opcode2 = 0;
        थांबा;
    स्थिती TOK_ASM_vnegeq_f32:
    स्थिती TOK_ASM_vnegeq_f64:
        opcode1 = 11; // Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        थांबा;
    स्थिती TOK_ASM_vabseq_f32:
    स्थिती TOK_ASM_vabseq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 0;
        थांबा;
    स्थिती TOK_ASM_vsqrteq_f32:
    स्थिती TOK_ASM_vsqrteq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        थांबा;
    स्थिती TOK_ASM_vcmpeq_f32:
    स्थिती TOK_ASM_vcmpeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        थांबा;
    स्थिती TOK_ASM_vcmpeeq_f32:
    स्थिती TOK_ASM_vcmpeeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        थांबा;
    स्थिती TOK_ASM_vmoveq_f32:
    स्थिती TOK_ASM_vmoveq_f64:
        जर (nb_arm_regs > 0) { // vmov.f32 r2, s3 or similar
            asm_floating_point_reg_arm_reg_transfer_opcode_tail(s1, token, coprocessor, nb_arm_regs, nb_ops, ops);
            परत;
        } अन्यथा {
            opcode1 = 11; // "Other" instruction
            opcode2 = 2;
            ops[1].type = OP_IM8;
            ops[1].e.v = 0;
        }
        थांबा;
    पूर्वनिर्धारित:
        expect("known floating point instruction");
    }

    जर (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        जर (ops[2].type == OP_VREG32) {
            जर (ops[2].reg & 1)
                opcode2 |= 1;
            ops[2].reg >>= 1;
        }

        जर (ops[1].type == OP_VREG32) {
            जर (ops[1].reg & 1)
                opcode2 |= 4;
            ops[1].reg >>= 1;
        }

        जर (ops[0].type == OP_VREG32) {
            जर (ops[0].reg & 1)
                opcode1 |= 4;
            ops[0].reg >>= 1;
        }
    }

    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

स्थिर पूर्णांक asm_parse_vfp_status_regvar(पूर्णांक t)
{
    निवड (t) {
    स्थिती TOK_ASM_fpsid:
        परत 0;
    स्थिती TOK_ASM_fpscr:
        परत 1;
    स्थिती TOK_ASM_fpexc:
        परत 8;
    पूर्वनिर्धारित:
        परत -1;
    }
}

स्थिर शून्य asm_floating_point_status_register_opcode(TCCState* s1, पूर्णांक token)
{
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode;
    पूर्णांक vfp_sys_reg = -1;
    Operand arm_operand;
    निवड (ARM_INSTRUCTION_GROUP(token)) {
    स्थिती TOK_ASM_vmrseq:
        opcode = 0xf;
        जर (tok == TOK_ASM_apsr_nzcv) {
            arm_operand.type = OP_REG32;
            arm_operand.reg = 15; // not PC
            next(); // skip apsr_nzcv
        } अन्यथा {
            parse_operand(s1, &arm_operand);
            जर (arm_operand.type == OP_REG32 && arm_operand.reg == 15) {
                tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, रिक्त));
            }
        }

        skip(',');
        vfp_sys_reg = asm_parse_vfp_status_regvar(tok);
        next(); // skip vfp sys reg
        जर (arm_operand.type == OP_REG32 && arm_operand.reg == 15 && vfp_sys_reg != 1) {
            tcc_error("'%s' only supports the variant 'vmrs apsr_nzcv, fpscr' here", get_tok_str(token, रिक्त));
        }
        थांबा;
    स्थिती TOK_ASM_vmsreq:
        opcode = 0xe;
        vfp_sys_reg = asm_parse_vfp_status_regvar(tok);
        next(); // skip vfp sys reg
        skip(',');
        parse_operand(s1, &arm_operand);
        जर (arm_operand.type == OP_REG32 && arm_operand.reg == 15) {
            tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, रिक्त));
        }
        थांबा;
    पूर्वनिर्धारित:
        expect("floating point status register instruction");
    }
    जर (vfp_sys_reg == -1) {
        expect("VFP system register");
    }
    जर (arm_operand.type != OP_REG32) {
        expect("ARM register");
    }
    asm_emit_coprocessor_opcode(condition_code_of_token(token), coprocessor, opcode, arm_operand.reg, vfp_sys_reg, 0x10, 0, 0);
}

#endif

स्थिर शून्य asm_misc_single_data_transfer_opcode(TCCState *s1, पूर्णांक token)
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
    जर (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    अन्यथा {
        expect("(destination operand) register");
    }
    जर (tok != ',')
        expect("at least two arguments");
    अन्यथा
        next(); // skip ','
    skip('[');
    parse_operand(s1, &ops[1]);
    जर (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    अन्यथा {
        expect("(first source operand) register");
    }
    जर (tok == ']') {
        next();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    जर (tok == ',') {
        next(); // skip ','
        जर (tok == '-') {
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
    जर (!closed_bracket) {
        skip(']');
        opcode |= 1 << 24; // add offset before transfer
        जर (tok == '!') {
            exclam = 1;
            next(); // skip '!'
        }
    }

    जर (exclam) {
        जर ((opcode & (1 << 24)) == 0) {
            tcc_error("result of '%s' would be unpredictable here", get_tok_str(token, रिक्त));
        }
        opcode |= 1 << 21; // write offset back into register
    }

    जर (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        पूर्णांक v = ops[2].e.v;
        जर (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        जर (v >= 0) {
            opcode |= 1 << 23; // up
            जर (v >= 0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, रिक्त));
            अन्यथा {
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        } अन्यथा { // down
            जर (v <= -0x100)
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
    } अन्यथा जर (ops[2].type == OP_REG32) {
        जर (!op2_minus)
            opcode |= 1 << 23; // up
        opcode |= ops[2].reg;
    } अन्यथा
        expect("register");

    निवड (ARM_INSTRUCTION_GROUP(token)) {
    स्थिती TOK_ASM_ldrsheq:
        opcode |= 1 << 5; // halfword, not byte
        /* fallthrough */
    स्थिती TOK_ASM_ldrsbeq:
        opcode |= 1 << 6; // sign extend
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        थांबा;
    स्थिती TOK_ASM_ldrheq:
        opcode |= 1 << 5; // halfword, not byte
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        थांबा;
    स्थिती TOK_ASM_strheq:
        opcode |= 1 << 5; // halfword, not byte
        asm_emit_opcode(token, opcode);
        थांबा;
    }
}

/* Note: almost dupe of encbranch in arm-gen.c */
स्थिर uint32_t encbranchoffset(पूर्णांक pos, पूर्णांक addr, पूर्णांक fail)
{
  addr-=pos+8;
  addr/=4;
  जर(addr>=0x7fffff || addr<-0x800000) {
    जर(fail)
      tcc_error("branch offset is too far");
    परत 0;
  }
  परत /*not 0x0A000000|*/(addr&0xffffff);
}

स्थिर शून्य asm_branch_opcode(TCCState *s1, पूर्णांक token)
{
    पूर्णांक jmp_disp = 0;
    Operand op;
    अभिव्यक्ती_मूल्य e;
    ElfSym *esym;

    निवड (ARM_INSTRUCTION_GROUP(token)) {
    स्थिती TOK_ASM_beq:
    स्थिती TOK_ASM_bleq:
        asm_अभिव्यक्ती(s1, &e);
        जर (e.sym) {
            esym = elfsym(e.sym);
            जर (esym && esym->st_shndx == cur_text_section->sh_अंक) {
                jmp_disp = esym->st_मूल्य;
            } अन्यथा {
                greloca(cur_text_section, e.sym, ind, R_ARM_PC24, 0);
                jmp_disp = ind;
            }
        }
        jmp_disp = encbranchoffset(ind, e.v + jmp_disp, 1);
        थांबा;
    पूर्वनिर्धारित:
        parse_operand(s1, &op);
        थांबा;
    }
    निवड (ARM_INSTRUCTION_GROUP(token)) {
    स्थिती TOK_ASM_beq:
        asm_emit_opcode(token, (0xa << 24) | (jmp_disp & 0xffffff));
        थांबा;
    स्थिती TOK_ASM_bleq:
        asm_emit_opcode(token, (0xb << 24) | (jmp_disp & 0xffffff));
        थांबा;
    स्थिती TOK_ASM_bxeq:
        जर (op.type != OP_REG32)
            expect("register");
        अन्यथा
            asm_emit_opcode(token, (0x12fff1 << 4) | op.reg);
        थांबा;
    स्थिती TOK_ASM_blxeq:
        जर (op.type != OP_REG32)
            expect("register");
        अन्यथा
            asm_emit_opcode(token, (0x12fff3 << 4) | op.reg);
        थांबा;
    पूर्वनिर्धारित:
        expect("branch instruction");
    }
}

ST_FUNC शून्य asm_opcode(TCCState *s1, पूर्णांक token)
{
    पर्यंत (token == TOK_LINEFEED) {
        next();
        token = tok;
    }
    जर (token == TOK_EOF)
        परत;
    जर (token < TOK_ASM_nopeq) { // no condition code
        निवड (token) {
        स्थिती TOK_ASM_cdp2:
            asm_coprocessor_opcode(s1, token);
            परत;
        स्थिती TOK_ASM_ldc2:
        स्थिती TOK_ASM_ldc2l:
        स्थिती TOK_ASM_stc2:
        स्थिती TOK_ASM_stc2l:
            asm_coprocessor_data_transfer_opcode(s1, token);
            परत;
        पूर्वनिर्धारित:
            expect("instruction");
        }
    }

    निवड (ARM_INSTRUCTION_GROUP(token)) {
    स्थिती TOK_ASM_pusheq:
    स्थिती TOK_ASM_popeq:
    स्थिती TOK_ASM_stmdaeq:
    स्थिती TOK_ASM_ldmdaeq:
    स्थिती TOK_ASM_stmeq:
    स्थिती TOK_ASM_ldmeq:
    स्थिती TOK_ASM_stmiaeq:
    स्थिती TOK_ASM_ldmiaeq:
    स्थिती TOK_ASM_stmdbeq:
    स्थिती TOK_ASM_ldmdbeq:
    स्थिती TOK_ASM_stmibeq:
    स्थिती TOK_ASM_ldmibeq:
        asm_block_data_transfer_opcode(s1, token);
        परत;
    स्थिती TOK_ASM_nopeq:
    स्थिती TOK_ASM_wfeeq:
    स्थिती TOK_ASM_wfieq:
        asm_nullary_opcode(token);
        परत;
    स्थिती TOK_ASM_swieq:
    स्थिती TOK_ASM_svceq:
        asm_unary_opcode(s1, token);
        परत;
    स्थिती TOK_ASM_beq:
    स्थिती TOK_ASM_bleq:
    स्थिती TOK_ASM_bxeq:
    स्थिती TOK_ASM_blxeq:
        asm_branch_opcode(s1, token);
        परत;
    स्थिती TOK_ASM_clzeq:
    स्थिती TOK_ASM_sxtbeq:
    स्थिती TOK_ASM_sxtheq:
    स्थिती TOK_ASM_uxtbeq:
    स्थिती TOK_ASM_uxtheq:
    स्थिती TOK_ASM_movteq:
    स्थिती TOK_ASM_movweq:
        asm_द्विमान_opcode(s1, token);
        परत;

    स्थिती TOK_ASM_ldreq:
    स्थिती TOK_ASM_ldrbeq:
    स्थिती TOK_ASM_streq:
    स्थिती TOK_ASM_strbeq:
    स्थिती TOK_ASM_ldrexeq:
    स्थिती TOK_ASM_ldrexbeq:
    स्थिती TOK_ASM_ldrexheq:
    स्थिती TOK_ASM_strexeq:
    स्थिती TOK_ASM_strexbeq:
    स्थिती TOK_ASM_strexheq:
        asm_single_data_transfer_opcode(s1, token);
        परत;

    स्थिती TOK_ASM_ldrheq:
    स्थिती TOK_ASM_ldrsheq:
    स्थिती TOK_ASM_ldrsbeq:
    स्थिती TOK_ASM_strheq:
       asm_misc_single_data_transfer_opcode(s1, token);
       परत;

    स्थिती TOK_ASM_andeq:
    स्थिती TOK_ASM_eoreq:
    स्थिती TOK_ASM_subeq:
    स्थिती TOK_ASM_rsbeq:
    स्थिती TOK_ASM_addeq:
    स्थिती TOK_ASM_adceq:
    स्थिती TOK_ASM_sbceq:
    स्थिती TOK_ASM_rsceq:
    स्थिती TOK_ASM_tsteq:
    स्थिती TOK_ASM_teqeq:
    स्थिती TOK_ASM_cmpeq:
    स्थिती TOK_ASM_cmneq:
    स्थिती TOK_ASM_orreq:
    स्थिती TOK_ASM_moveq:
    स्थिती TOK_ASM_biceq:
    स्थिती TOK_ASM_mvneq:
    स्थिती TOK_ASM_andseq:
    स्थिती TOK_ASM_eorseq:
    स्थिती TOK_ASM_subseq:
    स्थिती TOK_ASM_rsbseq:
    स्थिती TOK_ASM_addseq:
    स्थिती TOK_ASM_adcseq:
    स्थिती TOK_ASM_sbcseq:
    स्थिती TOK_ASM_rscseq:
//  case TOK_ASM_tstseq:
//  case TOK_ASM_teqseq:
//  case TOK_ASM_cmpseq:
//  case TOK_ASM_cmnseq:
    स्थिती TOK_ASM_orrseq:
    स्थिती TOK_ASM_movseq:
    स्थिती TOK_ASM_bicseq:
    स्थिती TOK_ASM_mvnseq:
        asm_data_processing_opcode(s1, token);
        परत;

    स्थिती TOK_ASM_lsleq:
    स्थिती TOK_ASM_lslseq:
    स्थिती TOK_ASM_lsreq:
    स्थिती TOK_ASM_lsrseq:
    स्थिती TOK_ASM_asreq:
    स्थिती TOK_ASM_asrseq:
    स्थिती TOK_ASM_roreq:
    स्थिती TOK_ASM_rorseq:
    स्थिती TOK_ASM_rrxseq:
    स्थिती TOK_ASM_rrxeq:
        asm_shift_opcode(s1, token);
        परत;

    स्थिती TOK_ASM_muleq:
    स्थिती TOK_ASM_mulseq:
    स्थिती TOK_ASM_mlaeq:
    स्थिती TOK_ASM_mlaseq:
    स्थिती TOK_ASM_mlseq:
    स्थिती TOK_ASM_udiveq:
    स्थिती TOK_ASM_sdiveq:
        asm_multiplication_opcode(s1, token);
        परत;

    स्थिती TOK_ASM_smulleq:
    स्थिती TOK_ASM_smullseq:
    स्थिती TOK_ASM_umulleq:
    स्थिती TOK_ASM_umullseq:
    स्थिती TOK_ASM_smlaleq:
    स्थिती TOK_ASM_smlalseq:
    स्थिती TOK_ASM_umlaleq:
    स्थिती TOK_ASM_umlalseq:
        asm_long_multiplication_opcode(s1, token);
        परत;

    स्थिती TOK_ASM_cdpeq:
    स्थिती TOK_ASM_mcreq:
    स्थिती TOK_ASM_mrceq:
        asm_coprocessor_opcode(s1, token);
        परत;

    स्थिती TOK_ASM_ldceq:
    स्थिती TOK_ASM_ldcleq:
    स्थिती TOK_ASM_stceq:
    स्थिती TOK_ASM_stcleq:
        asm_coprocessor_data_transfer_opcode(s1, token);
        परत;

#जर defined(TCC_ARM_VFP)
    स्थिती TOK_ASM_vldreq:
    स्थिती TOK_ASM_vstreq:
        asm_floating_point_single_data_transfer_opcode(s1, token);
        परत;

    स्थिती TOK_ASM_vmlaeq_f32:
    स्थिती TOK_ASM_vmlseq_f32:
    स्थिती TOK_ASM_vnmlseq_f32:
    स्थिती TOK_ASM_vnmlaeq_f32:
    स्थिती TOK_ASM_vmuleq_f32:
    स्थिती TOK_ASM_vnmuleq_f32:
    स्थिती TOK_ASM_vaddeq_f32:
    स्थिती TOK_ASM_vsubeq_f32:
    स्थिती TOK_ASM_vdiveq_f32:
    स्थिती TOK_ASM_vnegeq_f32:
    स्थिती TOK_ASM_vabseq_f32:
    स्थिती TOK_ASM_vsqrteq_f32:
    स्थिती TOK_ASM_vcmpeq_f32:
    स्थिती TOK_ASM_vcmpeeq_f32:
    स्थिती TOK_ASM_vmoveq_f32:
    स्थिती TOK_ASM_vmlaeq_f64:
    स्थिती TOK_ASM_vmlseq_f64:
    स्थिती TOK_ASM_vnmlseq_f64:
    स्थिती TOK_ASM_vnmlaeq_f64:
    स्थिती TOK_ASM_vmuleq_f64:
    स्थिती TOK_ASM_vnmuleq_f64:
    स्थिती TOK_ASM_vaddeq_f64:
    स्थिती TOK_ASM_vsubeq_f64:
    स्थिती TOK_ASM_vdiveq_f64:
    स्थिती TOK_ASM_vnegeq_f64:
    स्थिती TOK_ASM_vabseq_f64:
    स्थिती TOK_ASM_vsqrteq_f64:
    स्थिती TOK_ASM_vcmpeq_f64:
    स्थिती TOK_ASM_vcmpeeq_f64:
    स्थिती TOK_ASM_vmoveq_f64:
        asm_floating_point_data_processing_opcode(s1, token);
        परत;

    स्थिती TOK_ASM_vcvtreq_s32_f32:
    स्थिती TOK_ASM_vcvtreq_s32_f64:
    स्थिती TOK_ASM_vcvteq_s32_f32:
    स्थिती TOK_ASM_vcvteq_s32_f64:
    स्थिती TOK_ASM_vcvtreq_u32_f32:
    स्थिती TOK_ASM_vcvtreq_u32_f64:
    स्थिती TOK_ASM_vcvteq_u32_f32:
    स्थिती TOK_ASM_vcvteq_u32_f64:
    स्थिती TOK_ASM_vcvteq_f64_s32:
    स्थिती TOK_ASM_vcvteq_f32_s32:
    स्थिती TOK_ASM_vcvteq_f64_u32:
    स्थिती TOK_ASM_vcvteq_f32_u32:
    स्थिती TOK_ASM_vcvteq_f64_f32:
    स्थिती TOK_ASM_vcvteq_f32_f64:
        asm_floating_point_vcvt_data_processing_opcode(s1, token);
        परत;

    स्थिती TOK_ASM_vpusheq:
    स्थिती TOK_ASM_vpopeq:
    स्थिती TOK_ASM_vldmeq:
    स्थिती TOK_ASM_vldmiaeq:
    स्थिती TOK_ASM_vldmdbeq:
    स्थिती TOK_ASM_vstmeq:
    स्थिती TOK_ASM_vstmiaeq:
    स्थिती TOK_ASM_vstmdbeq:
        asm_floating_point_block_data_transfer_opcode(s1, token);
        परत;

    स्थिती TOK_ASM_vmsreq:
    स्थिती TOK_ASM_vmrseq:
        asm_floating_point_status_register_opcode(s1, token);
        परत;
#endif

    पूर्वनिर्धारित:
        expect("known instruction");
    }
}

ST_FUNC शून्य subst_asm_operand(CString *add_str, SValue *sv, पूर्णांक modifier)
{
    पूर्णांक r, reg, size, val;

    r = sv->r;
    जर ((r & VT_VALMASK) == VT_CONST) {
        जर (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(add_str, '#');
        जर (r & VT_SYM) {
            स्थिरांक अक्षर *name = get_tok_str(sv->sym->v, रिक्त);
            जर (sv->sym->v >= SYM_FIRST_ANOM) {
                /* In case of anonymous symbols ("L.42", used
                   for static data labels) we can't find them
                   in the C symbol table when later looking up
                   this name.  So enter them now into the asm label
                   list when we still know the symbol.  */
                get_asm_sym(tok_alloc(name, म_माप(name))->tok, sv->sym);
            }
            जर (tcc_state->leading_underscore)
                cstr_ccat(add_str, '_');
            cstr_cat(add_str, name, -1);
            जर ((uint32_t) sv->c.i == 0)
                जा no_offset;
            cstr_ccat(add_str, '+');
        }
        val = sv->c.i;
        जर (modifier == 'n')
            val = -val;
        cstr_printf(add_str, "%d", val);
      no_offset:;
    } अन्यथा जर ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(add_str, "[fp,#%d]", (पूर्णांक) sv->c.i);
    } अन्यथा जर (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        जर (reg >= VT_CONST)
            tcc_internal_error("");
        cstr_printf(add_str, "[%s]",
                 get_tok_str(TOK_ASM_r0 + reg, रिक्त));
    } अन्यथा {
        /* register case */
        reg = r & VT_VALMASK;
        जर (reg >= VT_CONST)
            tcc_internal_error("");

        /* choose register operand size */
        जर ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            size = 1;
        अन्यथा जर ((sv->type.t & VT_BTYPE) == VT_SHORT)
            size = 2;
        अन्यथा
            size = 4;

        जर (modifier == 'b') {
            size = 1;
        } अन्यथा जर (modifier == 'w') {
            size = 2;
        } अन्यथा जर (modifier == 'k') {
            size = 4;
        }

        निवड (size) {
        पूर्वनिर्धारित:
            reg = TOK_ASM_r0 + reg;
            थांबा;
        }
        cstr_printf(add_str, "%s", get_tok_str(reg, रिक्त));
    }
}

/* generate prolog and epilog code for asm statement */
ST_FUNC शून्य asm_gen_code(ASMOperand *operands, पूर्णांक nb_operands,
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
    स्थिर स्थिरांक uint8_t reg_saved[] = { 4, 5, 6, 7, 8, 9 /* Note: sometimes special reg "sb" */ , 10, 11 };

    /* mark all used registers */
    स_नकल(regs_allocated, clobber_regs, आकार(regs_allocated));
    साठी(i = 0; i < nb_operands;i++) {
        op = &operands[i];
        जर (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }
    साठी(i = 0; i < आकार(reg_saved)/आकार(reg_saved[0]); i++) {
        reg = reg_saved[i];
        जर (regs_allocated[reg])
            saved_regset |= 1 << reg;
    }

    जर (!is_output) { // prolog
        /* generate reg save code */
        जर (saved_regset)
            gen_le32(0xe92d0000 | saved_regset); // push {...}

        /* generate load code */
        साठी(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            जर (op->reg >= 0) {
                जर ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_memory) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    load(op->reg, &sv);
                } अन्यथा जर (i >= nb_outputs || op->is_rw) { // not write-only
                    /* load value in register */
                    load(op->reg, op->vt);
                    जर (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }
    } अन्यथा { // epilog
        /* generate save code */
        साठी(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            जर (op->reg >= 0) {
                जर ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    जर (!op->is_memory) {
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
                    जर (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }

        /* generate reg restore code */
        जर (saved_regset)
            gen_le32(0xe8bd0000 | saved_regset); // pop {...}
    }
}

/* return the constraint priority (we allocate first the lowest
   numbered constraints) */
स्थिर ओळीत पूर्णांक constraint_priority(स्थिरांक अक्षर *str)
{
    पूर्णांक priority, c, pr;

    /* we take the lowest priority */
    priority = 0;
    साठी(;;) {
        c = *str;
        जर (c == '\0')
            थांबा;
        str++;
        निवड(c) {
        स्थिती 'l': // in ARM mode, that's  an alias for 'r' [ARM].
        स्थिती 'r': // register [general]
        स्थिती 'p': // valid memory address for load,store [general]
            pr = 3;
            थांबा;
        स्थिती 'M': // integer constant for shifts [ARM]
        स्थिती 'I': // integer valid for data processing instruction immediate
        स्थिती 'J': // integer in range -4095...4095

        स्थिती 'i': // immediate integer operand, including symbolic constants [general]
        स्थिती 'm': // memory operand [general]
        स्थिती 'g': // general-purpose-register, memory, immediate integer [general]
            pr = 4;
            थांबा;
        पूर्वनिर्धारित:
            tcc_error("unknown constraint '%c'", c);
        }
        जर (pr > priority)
            priority = pr;
    }
    परत priority;
}

स्थिर स्थिरांक अक्षर *skip_constraint_modifiers(स्थिरांक अक्षर *p)
{
    /* Constraint modifier:
        =   Operand is written to by this instruction
        +   Operand is both read and written to by this instruction
        %   Instruction is commutative for this operand and the following operand.

       Per-alternative constraint modifier:
        &   Operand is clobbered before the instruction is done using the input operands
    */
    पर्यंत (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    परत p;
}

#define REG_OUT_MASK 0x01
#define REG_IN_MASK  0x02

#define is_reg_allocated(reg) (regs_allocated[reg] & reg_mask)

ST_FUNC शून्य asm_compute_constraints(ASMOperand *operands,
                                    पूर्णांक nb_operands, पूर्णांक nb_outputs,
                                    स्थिरांक uint8_t *clobber_regs,
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
    स्थिरांक अक्षर *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    साठी (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->आदान_index = -1;
        op->ref_index = -1;
        op->reg = -1;
        op->is_memory = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    साठी (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        जर (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = find_constraint(operands, nb_operands, str, रिक्त);
            जर ((अचिन्हित) k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                          i, str);
            op->ref_index = k;
            जर (operands[k].आदान_index >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].आदान_index = i;
            op->priority = 5;
        } अन्यथा जर ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->priority = 1;
            op->reg = reg;
        } अन्यथा {
            op->priority = constraint_priority(str);
        }
    }

    /* sort operands according to their priority */
    साठी (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    साठी (i = 0; i < nb_operands - 1; i++) {
        साठी (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].priority;
            p2 = operands[sorted_op[j]].priority;
            जर (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    साठी (i = 0; i < NB_ASM_REGS; i++) {
        जर (clobber_regs[i])
            regs_allocated[i] = REG_IN_MASK | REG_OUT_MASK;
        अन्यथा
            regs_allocated[i] = 0;
    }
    /* sp cannot be used */
    regs_allocated[13] = REG_IN_MASK | REG_OUT_MASK;
    /* fp cannot be used yet */
    regs_allocated[11] = REG_IN_MASK | REG_OUT_MASK;

    /* allocate registers and generate corresponding asm moves */
    साठी (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        जर (op->ref_index >= 0)
            सुरूठेवा;
        /* select if register is used for output, input or both */
        जर (op->आदान_index >= 0) {
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
        } अन्यथा जर (j < nb_outputs) {
            reg_mask = REG_OUT_MASK;
        } अन्यथा {
            reg_mask = REG_IN_MASK;
        }
        जर (op->reg >= 0) {
            जर (is_reg_allocated(op->reg))
                tcc_error
                    ("asm regvar requests register that's taken already");
            reg = op->reg;
        }
      try_next:
        c = *str++;
        निवड (c) {
        स्थिती '=': // Operand is written-to
            जा try_next;
        स्थिती '+': // Operand is both READ and written-to
            op->is_rw = 1;
            /* FALL THRU */
        स्थिती '&': // Operand is clobbered before the instruction is done using the input operands
            जर (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs",
                          c);
            reg_mask = REG_IN_MASK | REG_OUT_MASK;
            जा try_next;
        स्थिती 'l': // In non-thumb mode, alias for 'r'--otherwise r0-r7 [ARM]
        स्थिती 'r': // general-purpose register
        स्थिती 'p': // loadable/storable address
            /* any general register */
            जर ((reg = op->reg) >= 0)
                जा reg_found;
            अन्यथा साठी (reg = 0; reg <= 8; reg++) {
                जर (!is_reg_allocated(reg))
                    जा reg_found;
            }
            जा try_next;
          reg_found:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_mask;
            थांबा;
        स्थिती 'I': // integer that is valid as an data processing instruction immediate (0...255, rotated by a multiple of two)
        स्थिती 'J': // integer in the range -4095 to 4095 [ARM]
        स्थिती 'K': // integer that satisfies constraint I when inverted (one's complement)
        स्थिती 'L': // integer that satisfies constraint I when inverted (two's complement)
        स्थिती 'i': // immediate integer operand, including symbolic constants
            जर (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                जा try_next;
            थांबा;
        स्थिती 'M': // integer in the range 0 to 32
            जर (!
                ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) ==
                 VT_CONST))
                जा try_next;
            थांबा;
        स्थिती 'm': // memory operand
        स्थिती 'g':
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            जर (j < nb_outputs || c == 'm') {
                जर ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register */
                    साठी (reg = 0; reg <= 8; reg++) {
                        जर (!(regs_allocated[reg] & REG_IN_MASK))
                            जा reg_found1;
                    }
                    जा try_next;
                  reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_IN_MASK;
                    op->reg = reg;
                    op->is_memory = 1;
                }
            }
            थांबा;
        पूर्वनिर्धारित:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                      j, op->constraint);
            थांबा;
        }
        /* if a reference is present for that operand, we assign it too */
        जर (op->आदान_index >= 0) {
            operands[op->आदान_index].reg = op->reg;
            operands[op->आदान_index].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    साठी (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        जर (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL && !op->is_memory) {
            साठी (reg = 0; reg <= 8; reg++) {
                जर (!(regs_allocated[reg] & REG_OUT_MASK))
                    जा reg_found2;
            }
            tcc_error("could not find free output register for reloading");
          reg_found2:
            *pout_reg = reg;
            थांबा;
        }
    }

    /* print sorted constraints */
#ifdef ASM_DEBUG
    साठी (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        म_लिखो("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, रिक्त) : "",
               op->constraint, op->vt->r, op->reg);
    }
    जर (*pout_reg >= 0)
        म_लिखो("out_reg=%d\n", *pout_reg);
#endif
}

ST_FUNC शून्य asm_clobber(uint8_t *clobber_regs, स्थिरांक अक्षर *str)
{
    पूर्णांक reg;
    TokenSym *ts;

    जर (!म_भेद(str, "memory") ||
        !म_भेद(str, "cc") ||
        !म_भेद(str, "flags"))
        परत;
    ts = tok_alloc(str, म_माप(str));
    reg = asm_parse_regvar(ts->tok);
    जर (reg == -1) {
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

    जर (t < TOK_ASM_r0 || t > TOK_ASM_pc) /* filter unrelated registers */
        परत -1;

    जर (t <= TOK_ASM_r15)       /* default register names r0-r15 */
        परत t - TOK_ASM_r0;

    जर (t <= TOK_ASM_v8)        /* synonym register names a1-a4,v1-v8 (alias: r0-r11) */
        परत t - TOK_ASM_a1;

    /* special register names sb/sl/fp/ip/sp/lr/pc (alias: r9-r15) */
    परत t - TOK_ASM_sb + (TOK_ASM_r9 - TOK_ASM_r0);
}

/*************************************************************/
#endif /* ndef TARGET_DEFS_ONLY */

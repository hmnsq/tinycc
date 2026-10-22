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

#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ ਨਿਸ਼ਾਨਾ_DEFS_ONLY

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CONFIG_TCC_ASM
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ NB_ASM_REGS 16

ST_FUNC ਖਾਲੀ g(ਪੂਰਨ c);
ST_FUNC ਖਾਲੀ gen_le16(ਪੂਰਨ c);
ST_FUNC ਖਾਲੀ gen_le32(ਪੂਰਨ c);

/*************************************************************/
#ਨਹੀਂਤਾਂ
/*************************************************************/

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ USING_GLOBALS
#ਅਨ੍ਤਰ੍ਭਾਵ "tcc.h"

ਗਿਣਤੀ {
    OPT_REG32,
    OPT_REGSET32,
    OPT_IM8,
    OPT_IM8N,
    OPT_IM32,
    OPT_VREG32,
    OPT_VREG64,
};
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_REG32  (1 << OPT_REG32)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_VREG32 (1 << OPT_VREG32)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_VREG64 (1 << OPT_VREG64)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_REG    (OP_REG32 | OP_VREG32 | OP_VREG64)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_IM32   (1 << OPT_IM32)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_IM8   (1 << OPT_IM8)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_IM8N   (1 << OPT_IM8N)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ OP_REGSET32  (1 << OPT_REGSET32)

ਕਿਸਮਪਰਿਭਾਸ਼ਾ ਬਣਤਰ ਸੰਕਾਰਜ {
    uint32_t type;
    ਸੰਘ {
        uint8_t reg;
        uint16_t regset;
        ਵਿਅੰਜਕ_ਮੁੱਲ e;
    };
} ਸੰਕਾਰਜ;

/* Read the VFP register referred to by token T.
   If OK, returns its number.
   If not OK, returns -1. */
ਸਥਿਰ ਪੂਰਨ asm_parse_vfp_regvar(ਪੂਰਨ t, ਪੂਰਨ double_precision)
{
    ਜੇ (double_precision) {
        ਜੇ (t >= TOK_ASM_d0 && t <= TOK_ASM_d15)
            ਵਾਪਸ t - TOK_ASM_d0;
    } ਨਹੀਂਤਾਂ {
        ਜੇ (t >= TOK_ASM_s0 && t <= TOK_ASM_s31)
            ਵਾਪਸ t - TOK_ASM_s0;
    }
    ਵਾਪਸ -1;
}

/* Parse a text containing operand and store the result in OP */
ਸਥਿਰ ਖਾਲੀ parse_ਸੰਕਾਰਜ(TCCState *s1, ਸੰਕਾਰਜ *op)
{
    ਵਿਅੰਜਕ_ਮੁੱਲ e;
    int8_t reg;
    uint16_t regset = 0;

    op->type = 0;

    ਜੇ (tok == '{') { // regset literal
        ਅਗਲਾ(); // skip '{'
        ਜਦੋਂ (tok != '}' && tok != TOK_EOF) {
            reg = asm_parse_regvar(tok);
            ਜੇ (reg == -1) {
                expect("register");
            } ਨਹੀਂਤਾਂ
                ਅਗਲਾ(); // skip register name

            ਜੇ ((1 << reg) < regset)
                tcc_warning("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
            regset |= 1 << reg;
            ਜੇ (tok != ',')
                ਰੋਕੋ;
            ਅਗਲਾ(); // skip ','
        }
        skip('}');
        ਜੇ (regset == 0) {
            // ARM instructions don't support empty regset.
            tcc_error("empty register list is not supported");
        } ਨਹੀਂਤਾਂ {
            op->type = OP_REGSET32;
            op->regset = regset;
        }
        ਵਾਪਸ;
    } ਨਹੀਂਤਾਂ ਜੇ ((reg = asm_parse_regvar(tok)) != -1) {
        ਅਗਲਾ(); // skip register name
        op->type = OP_REG32;
        op->reg = (uint8_t) reg;
        ਵਾਪਸ;
    } ਨਹੀਂਤਾਂ ਜੇ ((reg = asm_parse_vfp_regvar(tok, 0)) != -1) {
        ਅਗਲਾ(); // skip register name
        op->type = OP_VREG32;
        op->reg = (uint8_t) reg;
        ਵਾਪਸ;
    } ਨਹੀਂਤਾਂ ਜੇ ((reg = asm_parse_vfp_regvar(tok, 1)) != -1) {
        ਅਗਲਾ(); // skip register name
        op->type = OP_VREG64;
        op->reg = (uint8_t) reg;
        ਵਾਪਸ;
    } ਨਹੀਂਤਾਂ ਜੇ (tok == '#' || tok == '$') {
        /* constant value */
        ਅਗਲਾ(); // skip '#' or '$'
    }
    asm_ਵਿਅੰਜਕ(s1, &e);
    op->type = OP_IM32;
    op->e = e;
    ਜੇ (!op->e.sym) {
        ਜੇ ((ਪੂਰਨ) op->e.v < 0 && (ਪੂਰਨ) op->e.v >= -255)
            op->type = OP_IM8N;
        ਨਹੀਂਤਾਂ ਜੇ (op->e.v == (uint8_t)op->e.v)
            op->type = OP_IM8;
    } ਨਹੀਂਤਾਂ
        expect("operand");
}

/* XXX: make it faster ? */
ST_FUNC ਖਾਲੀ g(ਪੂਰਨ c)
{
    ਪੂਰਨ ind1;
    ਜੇ (nocode_wanted)
        ਵਾਪਸ;
    ind1 = ind + 1;
    ਜੇ (ind1 > cur_ਪਾਠ_section->ਅੰਕੜੇ_allocated)
        section_realloc(cur_ਪਾਠ_section, ind1);
    cur_ਪਾਠ_section->ਅੰਕੜੇ[ind] = c;
    ind = ind1;
}

ST_FUNC ਖਾਲੀ gen_le16 (ਪੂਰਨ i)
{
    g(i);
    g(i>>8);
}

ST_FUNC ਖਾਲੀ gen_le32 (ਪੂਰਨ i)
{
    ਪੂਰਨ ind1;
    ਜੇ (nocode_wanted)
        ਵਾਪਸ;
    ind1 = ind + 4;
    ਜੇ (ind1 > cur_ਪਾਠ_section->ਅੰਕੜੇ_allocated)
        section_realloc(cur_ਪਾਠ_section, ind1);
    cur_ਪਾਠ_section->ਅੰਕੜੇ[ind++] = i & 0xFF;
    cur_ਪਾਠ_section->ਅੰਕੜੇ[ind++] = (i >> 8) & 0xFF;
    cur_ਪਾਠ_section->ਅੰਕੜੇ[ind++] = (i >> 16) & 0xFF;
    cur_ਪਾਠ_section->ਅੰਕੜੇ[ind++] = (i >> 24) & 0xFF;
}

ST_FUNC ਖਾਲੀ gen_expr32(ਵਿਅੰਜਕ_ਮੁੱਲ *pe)
{
    gen_le32(pe->v);
}

ਸਥਿਰ uint32_t condition_ਕੋਡ_ਦਾ_token(ਪੂਰਨ token) {
    ਜੇ (token < TOK_ASM_nopeq) {
        expect("condition-enabled instruction");
    } ਨਹੀਂਤਾਂ
        ਵਾਪਸ (token - TOK_ASM_nopeq) & 15;
}

ਸਥਿਰ ਖਾਲੀ asm_emit_opcode(ਪੂਰਨ token, uint32_t opcode) {
    gen_le32((condition_ਕੋਡ_ਦਾ_token(token) << 28) | opcode);
}

ਸਥਿਰ ਖਾਲੀ asm_emit_unconditional_opcode(uint32_t opcode) {
    gen_le32(opcode);
}

ਸਥਿਰ ਖਾਲੀ asm_emit_coprocessor_opcode(uint32_t ਉੱਚਾ_nibble, uint8_t cp_ਸੰਖਿਆ, uint8_t cp_opcode, uint8_t cp_destination_ਰਜਿਸਟਰ, uint8_t cp_n_ਸੰਕਾਰਜ_ਰਜਿਸਟਰ, uint8_t cp_m_ਸੰਕਾਰਜ_ਰਜਿਸਟਰ, uint8_t cp_opcode2, ਪੂਰਨ inter_processor_transfer)
{
    uint32_t opcode = 0xe000000;
    ਜੇ (inter_processor_transfer)
        opcode |= 1 << 4;
    //assert(cp_opcode < 16);
    opcode |= cp_opcode << 20;
    //assert(cp_n_operand_register < 16);
    opcode |= cp_n_ਸੰਕਾਰਜ_ਰਜਿਸਟਰ << 16;
    //assert(cp_destination_register < 16);
    opcode |= cp_destination_ਰਜਿਸਟਰ << 12;
    //assert(cp_number < 16);
    opcode |= cp_ਸੰਖਿਆ << 8;
    //assert(cp_information < 8);
    opcode |= cp_opcode2 << 5;
    //assert(cp_m_operand_register < 16);
    opcode |= cp_m_ਸੰਕਾਰਜ_ਰਜਿਸਟਰ;
    asm_emit_unconditional_opcode((ਉੱਚਾ_nibble << 28) | opcode);
}

ਸਥਿਰ ਖਾਲੀ asm_nullary_opcode(ਪੂਰਨ token)
{
    ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
    ਹਾਲਤ TOK_ASM_nopeq:
        asm_emit_opcode(token, 0xd << 21); // mov r0, r0
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_wfeeq:
        asm_emit_opcode(token, 0x320f002);
    ਹਾਲਤ TOK_ASM_wfieq:
        asm_emit_opcode(token, 0x320f003);
        ਰੋਕੋ;
    ਮੂਲ:
        expect("nullary instruction");
    }
}

ਸਥਿਰ ਖਾਲੀ asm_unary_opcode(TCCState *s1, ਪੂਰਨ token)
{
    ਸੰਕਾਰਜ op;
    parse_ਸੰਕਾਰਜ(s1, &op);

    ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
    ਹਾਲਤ TOK_ASM_swieq:
    ਹਾਲਤ TOK_ASM_svceq:
        ਜੇ (op.type != OP_IM8)
            expect("immediate 8-bit unsigned integer");
        ਨਹੀਂਤਾਂ {
            /* Note: Dummy operand (ignored by processor): ARM ref documented 0...255, ARM instruction set documented 24 bit */
            asm_emit_opcode(token, (0xf << 24) | op.e.v);
        }
        ਰੋਕੋ;
    ਮੂਲ:
        expect("unary instruction");
    }
}

ਸਥਿਰ ਖਾਲੀ asm_ਦੁਆਧਾਰੀ_opcode(TCCState *s1, ਪੂਰਨ token)
{
    ਸੰਕਾਰਜ ops[2];
    ਸੰਕਾਰਜ rotation;
    uint32_t encoded_rotation = 0;
    uint64_t amount;
    parse_ਸੰਕਾਰਜ(s1, &ops[0]);
    skip(',');
    parse_ਸੰਕਾਰਜ(s1, &ops[1]);
    ਜੇ (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    }

    ਜੇ (ops[0].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ਨਿਰਾ));
    }

    ਜੇ (ops[0].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, ਨਿਰਾ));

    ਜੇ (ops[1].type != OP_REG32) {
        ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
        ਹਾਲਤ TOK_ASM_movteq:
        ਹਾਲਤ TOK_ASM_movweq:
            ਜੇ (ops[1].type == OP_IM8 || ops[1].type == OP_IM8N || ops[1].type == OP_IM32) {
                ਜੇ (ops[1].e.v >= 0 && ops[1].e.v <= 0xFFFF) {
                    uint16_t ਤੁਰੰਤ_ਮੁੱਲ = ops[1].e.v;
                    ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
                    ਹਾਲਤ TOK_ASM_movteq:
                        asm_emit_opcode(token, 0x3400000 | (ops[0].reg << 12) | (ਤੁਰੰਤ_ਮੁੱਲ & 0xF000) << 4 | (ਤੁਰੰਤ_ਮੁੱਲ & 0xFFF));
                        ਰੋਕੋ;
                    ਹਾਲਤ TOK_ASM_movweq:
                        asm_emit_opcode(token, 0x3000000 | (ops[0].reg << 12) | (ਤੁਰੰਤ_ਮੁੱਲ & 0xF000) << 4 | (ਤੁਰੰਤ_ਮੁੱਲ & 0xFFF));
                        ਰੋਕੋ;
                    }
                } ਨਹੀਂਤਾਂ
                    expect("(source operand) immediate 16 bit value");
            } ਨਹੀਂਤਾਂ
                expect("(source operand) immediate");
            ਰੋਕੋ;
        ਮੂਲ:
            expect("(source operand) register");
        }
        ਵਾਪਸ;
    }

    ਜੇ (ops[1].reg == 15) {
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ਨਿਰਾ));
    }

    ਜੇ (ops[1].reg == 13)
        tcc_warning("Using 'sp' as operand with '%s' is deprecated by ARM", get_tok_str(token, ਨਿਰਾ));

    ਜੇ (tok == ',') {
        ਅਗਲਾ(); // skip ','
        ਜੇ (tok == TOK_ASM_ror) {
            ਅਗਲਾ(); // skip 'ror'
            parse_ਸੰਕਾਰਜ(s1, &rotation);
            ਜੇ (rotation.type != OP_IM8) {
                expect("immediate value for rotation");
            } ਨਹੀਂਤਾਂ {
                amount = rotation.e.v;
                ਚੋਣ (amount) {
                ਹਾਲਤ 8:
                    encoded_rotation = 1 << 10;
                    ਰੋਕੋ;
                ਹਾਲਤ 16:
                    encoded_rotation = 2 << 10;
                    ਰੋਕੋ;
                ਹਾਲਤ 24:
                    encoded_rotation = 3 << 10;
                    ਰੋਕੋ;
                ਮੂਲ:
                    expect("'8' or '16' or '24'");
                }
            }
        }
    }
    ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
    ਹਾਲਤ TOK_ASM_clzeq:
        ਜੇ (encoded_rotation)
            tcc_error("clz does not support rotation");
        asm_emit_opcode(token, 0x16f0f10 | (ops[0].reg << 12) | ops[1].reg);
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_sxtbeq:
        asm_emit_opcode(token, 0x6af0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_sxtheq:
        asm_emit_opcode(token, 0x6bf0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_uxtbeq:
        asm_emit_opcode(token, 0x6ef0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_uxtheq:
        asm_emit_opcode(token, 0x6ff0070 | (ops[0].reg << 12) | ops[1].reg | encoded_rotation);
        ਰੋਕੋ;
    ਮੂਲ:
        expect("binary instruction");
    }
}

ਸਥਿਰ ਖਾਲੀ asm_coprocessor_opcode(TCCState *s1, ਪੂਰਨ token) {
    uint8_t coprocessor;
    ਸੰਕਾਰਜ opcode1;
    ਸੰਕਾਰਜ opcode2;
    uint8_t registers[3];
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਪੂਰਨ i;
    uint8_t ਉੱਚਾ_nibble;
    uint8_t mrc = 0;

    ਜੇ (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        ਅਗਲਾ();
    } ਨਹੀਂਤਾਂ {
        expect("'p<number>'");
    }
    skip(',');
    parse_ਸੰਕਾਰਜ(s1, &opcode1);
    ਜੇ (opcode1.type != OP_IM8 || opcode1.e.v > 15) {
        tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, ਨਿਰਾ));
    }

    ਲਈ (i = 0; i < 3; ++i) {
        skip(',');
        ਜੇ (i == 0 && token != TOK_ASM_cdp2 && (ARM_INSTRUCTION_ਸਮੂਹ(token) == TOK_ASM_mrceq || ARM_INSTRUCTION_ਸਮੂਹ(token) == TOK_ASM_mcreq)) {
            ਜੇ (tok >= TOK_ASM_r0 && tok <= TOK_ASM_pc) {
                registers[i] = asm_parse_regvar(tok);
                ਅਗਲਾ();
            } ਨਹੀਂਤਾਂ {
                expect("'r<number>'");
            }
        } ਨਹੀਂਤਾਂ {
            ਜੇ (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
                registers[i] = tok - TOK_ASM_c0;
                ਅਗਲਾ();
            } ਨਹੀਂਤਾਂ {
                expect("'c<number>'");
            }
        }
    }
    ਜੇ (tok == ',') {
        ਅਗਲਾ();
        parse_ਸੰਕਾਰਜ(s1, &opcode2);
    } ਨਹੀਂਤਾਂ {
        opcode2.type = OP_IM8;
        opcode2.e.v = 0;
    }
    ਜੇ (opcode2.type != OP_IM8 || opcode2.e.v > 15) {
        tcc_error("opcode2 of instruction '%s' must be an immediate value between 0 and 15", get_tok_str(token, ਨਿਰਾ));
    }

    ਜੇ (token == TOK_ASM_cdp2) {
        ਉੱਚਾ_nibble = 0xF;
        asm_emit_coprocessor_opcode(ਉੱਚਾ_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        ਵਾਪਸ;
    } ਨਹੀਂਤਾਂ
        ਉੱਚਾ_nibble = condition_ਕੋਡ_ਦਾ_token(token);

    ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
    ਹਾਲਤ TOK_ASM_cdpeq:
        asm_emit_coprocessor_opcode(ਉੱਚਾ_nibble, coprocessor, opcode1.e.v, registers[0], registers[1], registers[2], opcode2.e.v, 0);
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_mrceq:
        // opcode1 encoding changes! highest and lowest bit gone.
        mrc = 1;
        /* fallthrough */
    ਹਾਲਤ TOK_ASM_mcreq:
        // opcode1 encoding changes! highest and lowest bit gone.
        ਜੇ (opcode1.e.v > 7) {
            tcc_error("opcode1 of instruction '%s' must be an immediate value between 0 and 7", get_tok_str(token, ਨਿਰਾ));
        }
        asm_emit_coprocessor_opcode(ਉੱਚਾ_nibble, coprocessor, (opcode1.e.v << 1) | mrc, registers[0], registers[1], registers[2], opcode2.e.v, 1);
        ਰੋਕੋ;
    ਮੂਲ:
        expect("known instruction");
    }
}

/* data processing and single data transfer instructions only */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENCODE_RN(ਰਜਿਸਟਰ_ਸੂਚਕਾਂਕ) ((ਰਜਿਸਟਰ_ਸੂਚਕਾਂਕ) << 16)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENCODE_RD(ਰਜਿਸਟਰ_ਸੂਚਕਾਂਕ) ((ਰਜਿਸਟਰ_ਸੂਚਕਾਂਕ) << 12)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENCODE_ਸੈੱਟ_CONDITION_CODES (1 << 20)

/* Note: For data processing instructions, "1" means immediate.
   Note: For single data transfer instructions, "0" means immediate. */
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENCODE_ਤੁਰੰਤ_FLAG (1 << 25)

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENCODE_BARREL_SHIFTER_ਖਿਸਕਾਓ_BY_ਰਜਿਸਟਰ (1 << 4)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENCODE_BARREL_SHIFTER_ਬਹੁਲਕ_LSL (0 << 5)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENCODE_BARREL_SHIFTER_ਬਹੁਲਕ_LSR (1 << 5)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENCODE_BARREL_SHIFTER_ਬਹੁਲਕ_ASR (2 << 5)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENCODE_BARREL_SHIFTER_ਬਹੁਲਕ_ROR (3 << 5)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENCODE_BARREL_SHIFTER_ਰਜਿਸਟਰ(ਰਜਿਸਟਰ_ਸੂਚਕਾਂਕ) ((ਰਜਿਸਟਰ_ਸੂਚਕਾਂਕ) << 8)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ ENCODE_BARREL_SHIFTER_ਤੁਰੰਤ(ਮੁੱਲ) ((ਮੁੱਲ) << 7)

ਸਥਿਰ ਖਾਲੀ asm_ਖੰਡ_ਅੰਕੜੇ_transfer_opcode(TCCState *s1, ਪੂਰਨ token)
{
    uint32_t opcode;
    ਪੂਰਨ op0_exclam = 0;
    ਸੰਕਾਰਜ ops[2];
    ਪੂਰਨ nb_ops = 1;
    parse_ਸੰਕਾਰਜ(s1, &ops[0]);
    ਜੇ (tok == '!') {
        op0_exclam = 1;
        ਅਗਲਾ(); // skip '!'
    }
    ਜੇ (tok == ',') {
        ਅਗਲਾ(); // skip comma
        parse_ਸੰਕਾਰਜ(s1, &ops[1]);
        ++nb_ops;
    }
    ਜੇ (nb_ops < 1) {
        expect("at least one operand");
    } ਨਹੀਂਤਾਂ ਜੇ (ops[nb_ops - 1].type != OP_REGSET32) {
        expect("(last operand) register list");
    }

    // block data transfer: 1 0 0 P U S W L << 20 (general case):
    // operands:
    //   Rn: bits 19...16 base register
    //   Register List: bits 15...0

    ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
    ਹਾਲਤ TOK_ASM_pusheq: // TODO: Optimize 1-register case to: str ?, [sp, #-4]!
        // Instruction: 1 I=0 P=1 U=0 S=0 W=1 L=0 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        ਜੇ (nb_ops != 1)
            expect("exactly one operand");
        ਨਹੀਂਤਾਂ
            asm_emit_opcode(token, (0x92d << 16) | ops[0].regset); // TODO: base register ?
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_popeq: // TODO: Optimize 1-register case to: ldr ?, [sp], #4
        // Instruction: 1 I=0 P=0 U=1 S=0 W=0 L=1 << 20, op 1101
        //   operands:
        //      Rn: base register
        //      Register List: bits 15...0
        ਜੇ (nb_ops != 1)
            expect("exactly one operand");
        ਨਹੀਂਤਾਂ
            asm_emit_opcode(token, (0x8bd << 16) | ops[0].regset); // TODO: base register ?
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_stmdaeq:
    ਹਾਲਤ TOK_ASM_ldmdaeq:
    ਹਾਲਤ TOK_ASM_stmeq:
    ਹਾਲਤ TOK_ASM_ldmeq:
    ਹਾਲਤ TOK_ASM_stmiaeq:
    ਹਾਲਤ TOK_ASM_ldmiaeq:
    ਹਾਲਤ TOK_ASM_stmdbeq:
    ਹਾਲਤ TOK_ASM_ldmdbeq:
    ਹਾਲਤ TOK_ASM_stmibeq:
    ਹਾਲਤ TOK_ASM_ldmibeq:
        ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
        ਹਾਲਤ TOK_ASM_stmdaeq: // post-decrement store
            opcode = 0x80 << 20;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_ldmdaeq: // post-decrement load
            opcode = 0x81 << 20;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_stmeq: // post-increment store
        ਹਾਲਤ TOK_ASM_stmiaeq: // post-increment store
            opcode = 0x88 << 20;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_ldmeq: // post-increment load
        ਹਾਲਤ TOK_ASM_ldmiaeq: // post-increment load
            opcode = 0x89 << 20;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_stmdbeq: // pre-decrement store
            opcode = 0x90 << 20;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_ldmdbeq: // pre-decrement load
            opcode = 0x91 << 20;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_stmibeq: // pre-increment store
            opcode = 0x98 << 20;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_ldmibeq: // pre-increment load
            opcode = 0x99 << 20;
            ਰੋਕੋ;
        ਮੂਲ:
            tcc_error("internal error: This place should not be reached (fallback in asm_block_data_transfer_opcode)");
        }
        // operands:
        //    Rn: first operand
        //    Register List: lower bits
        ਜੇ (nb_ops != 2)
            expect("exactly two operands");
        ਨਹੀਂਤਾਂ ਜੇ (ops[0].type != OP_REG32)
            expect("(first operand) register");
        ਨਹੀਂਤਾਂ {
            ਜੇ (op0_exclam)
                opcode |= 1 << 21; // writeback
            asm_emit_opcode(token, opcode | ENCODE_RN(ops[0].reg) | ops[1].regset);
        }
        ਰੋਕੋ;
    ਮੂਲ:
        expect("block data transfer instruction");
    }
}

/* Parses shift directive and returns the parts that would have to be set in the opcode because of it.
   Does not encode the actual shift amount.
   It's not an error if there is no shift directive.

   NB_SHIFT: will be set to 1 iff SHIFT is filled.  Note that for rrx, there's no need to fill SHIFT.
   SHIFT: will be filled in with the shift operand to use, if any. */
ਸਥਿਰ uint32_t asm_parse_optional_ਖਿਸਕਾਓ(TCCState* s1, ਪੂਰਨ* nb_ਖਿਸਕਾਓ, ਸੰਕਾਰਜ* ਖਿਸਕਾਓ)
{
    uint32_t opcode = 0;
    *nb_ਖਿਸਕਾਓ = 0;
    ਚੋਣ (tok) {
    ਹਾਲਤ TOK_ASM_asl:
    ਹਾਲਤ TOK_ASM_lsl:
    ਹਾਲਤ TOK_ASM_asr:
    ਹਾਲਤ TOK_ASM_lsr:
    ਹਾਲਤ TOK_ASM_ror:
        ਚੋਣ (tok) {
        ਹਾਲਤ TOK_ASM_asl:
            /* fallthrough */
        ਹਾਲਤ TOK_ASM_lsl:
            opcode = ENCODE_BARREL_SHIFTER_ਬਹੁਲਕ_LSL;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_asr:
            opcode = ENCODE_BARREL_SHIFTER_ਬਹੁਲਕ_ASR;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_lsr:
            opcode = ENCODE_BARREL_SHIFTER_ਬਹੁਲਕ_LSR;
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_ror:
            opcode = ENCODE_BARREL_SHIFTER_ਬਹੁਲਕ_ROR;
            ਰੋਕੋ;
        }
        ਅਗਲਾ();
        parse_ਸੰਕਾਰਜ(s1, ਖਿਸਕਾਓ);
        *nb_ਖਿਸਕਾਓ = 1;
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_rrx:
        ਅਗਲਾ();
        opcode = ENCODE_BARREL_SHIFTER_ਬਹੁਲਕ_ROR;
        ਰੋਕੋ;
    }
    ਵਾਪਸ opcode;
}

ਸਥਿਰ uint32_t asm_encode_ਖਿਸਕਾਓ(ਸੰਕਾਰਜ* ਖਿਸਕਾਓ)
{
    uint64_t amount;
    uint32_t operands = 0;
    ਚੋਣ (ਖਿਸਕਾਓ->type) {
    ਹਾਲਤ OP_REG32:
        ਜੇ (ਖਿਸਕਾਓ->reg == 15)
            tcc_error("r15 cannot be used as a shift count");
        ਨਹੀਂਤਾਂ {
            operands = ENCODE_BARREL_SHIFTER_ਖਿਸਕਾਓ_BY_ਰਜਿਸਟਰ;
            operands |= ENCODE_BARREL_SHIFTER_ਰਜਿਸਟਰ(ਖਿਸਕਾਓ->reg);
        }
        ਰੋਕੋ;
    ਹਾਲਤ OP_IM8:
        amount = ਖਿਸਕਾਓ->e.v;
        ਜੇ (amount > 0 && amount < 32)
            operands = ENCODE_BARREL_SHIFTER_ਤੁਰੰਤ(amount);
        ਨਹੀਂਤਾਂ
            tcc_error("shift count out of range");
        ਰੋਕੋ;
    ਮੂਲ:
        tcc_error("unknown shift amount");
    }
    ਵਾਪਸ operands;
}

ਸਥਿਰ ਖਾਲੀ asm_ਅੰਕੜੇ_processing_opcode(TCCState *s1, ਪੂਰਨ token)
{
    ਸੰਕਾਰਜ ops[3];
    ਪੂਰਨ nb_ops;
    ਸੰਕਾਰਜ ਖਿਸਕਾਓ = {0};
    ਪੂਰਨ nb_ਖਿਸਕਾਓ = 0;
    uint32_t operands = 0;

    /* modulo 16 entries per instruction for the different condition codes */
    uint32_t opcode_idx = (ARM_INSTRUCTION_ਸਮੂਹ(token) - TOK_ASM_andeq) >> 4;
    uint32_t opcode_nos = opcode_idx >> 1; // without "s"; "OpCode" in ARM docs

    ਲਈ (nb_ops = 0; nb_ops < ਆਕਾਰ(ops)/ਆਕਾਰ(ops[0]); ) {
        ਜੇ (tok == TOK_ASM_asl || tok == TOK_ASM_lsl || tok == TOK_ASM_lsr || tok == TOK_ASM_asr || tok == TOK_ASM_ror || tok == TOK_ASM_rrx)
            ਰੋਕੋ;
        parse_ਸੰਕਾਰਜ(s1, &ops[nb_ops]);
        ++nb_ops;
        ਜੇ (tok != ',')
            ਰੋਕੋ;
        ਅਗਲਾ(); // skip ','
    }
    ਜੇ (tok == ',')
        ਅਗਲਾ();
    operands |= asm_parse_optional_ਖਿਸਕਾਓ(s1, &nb_ਖਿਸਕਾਓ, &ਖਿਸਕਾਓ);
    ਜੇ (nb_ops < 2)
        expect("at least two operands");
    ਨਹੀਂਤਾਂ ਜੇ (nb_ops == 2) {
        ਸਮ੍ਰਿਤੀ_ਨਕਲ(&ops[2], &ops[1], ਆਕਾਰ(ops[1])); // move ops[2]
        ਸਮ੍ਰਿਤੀ_ਨਕਲ(&ops[1], &ops[0], ਆਕਾਰ(ops[0])); // ops[1] was implicit
        nb_ops = 3;
    } ਨਹੀਂਤਾਂ ਜੇ (nb_ops == 3) {
        ਜੇ (opcode_nos == 0xd || opcode_nos == 0xf || opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) { // mov, mvn, cmp, cmn, tst, teq
            tcc_error("'%s' cannot be used with three operands", get_tok_str(token, ਨਿਰਾ));
        }
    }
    ਜੇ (nb_ops != 3) {
        expect("two or three operands");
    } ਨਹੀਂਤਾਂ {
        uint32_t opcode = 0;
        uint32_t ਤੁਰੰਤ_ਮੁੱਲ;
        uint8_t half_ਤੁਰੰਤ_rotation;
        ਜੇ (nb_ਖਿਸਕਾਓ && ਖਿਸਕਾਓ.type == OP_REG32) {
            ਜੇ ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
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
        ਜੇ (ops[0].type != OP_REG32)
            expect("(destination operand) register");
        ਨਹੀਂਤਾਂ ਜੇ (opcode_nos == 0xa || opcode_nos == 0xb || opcode_nos == 0x8 || opcode_nos == 0x9) // cmp, cmn, tst, teq
            operands |= ENCODE_ਸੈੱਟ_CONDITION_CODES; // force S set, otherwise it's a completely different instruction.
        ਨਹੀਂਤਾਂ
            operands |= ENCODE_RD(ops[0].reg);
        ਜੇ (ops[1].type != OP_REG32)
            expect("(first source operand) register");
        ਨਹੀਂਤਾਂ ਜੇ (!(opcode_nos == 0xd || opcode_nos == 0xf)) // not: mov, mvn (those have only one source operand)
            operands |= ENCODE_RN(ops[1].reg);
        ਚੋਣ (ops[2].type) {
        ਹਾਲਤ OP_REG32:
            operands |= ops[2].reg;
            ਰੋਕੋ;
        ਹਾਲਤ OP_IM8:
        ਹਾਲਤ OP_IM32:
            operands |= ENCODE_ਤੁਰੰਤ_FLAG;
            ਤੁਰੰਤ_ਮੁੱਲ = ops[2].e.v;
            ਲਈ (half_ਤੁਰੰਤ_rotation = 0; half_ਤੁਰੰਤ_rotation < 16; ++half_ਤੁਰੰਤ_rotation) {
                ਜੇ (ਤੁਰੰਤ_ਮੁੱਲ >= 0x00 && ਤੁਰੰਤ_ਮੁੱਲ < 0x100)
                    ਰੋਕੋ;
                // rotate left by two
                ਤੁਰੰਤ_ਮੁੱਲ = ((ਤੁਰੰਤ_ਮੁੱਲ & 0x3FFFFFFF) << 2) | ((ਤੁਰੰਤ_ਮੁੱਲ & 0xC0000000) >> 30);
            }
            ਜੇ (half_ਤੁਰੰਤ_rotation >= 16) {
                /* fallthrough */
            } ਨਹੀਂਤਾਂ {
                operands |= ਤੁਰੰਤ_ਮੁੱਲ;
                operands |= half_ਤੁਰੰਤ_rotation << 8;
                ਰੋਕੋ;
            }
        ਹਾਲਤ OP_IM8N: // immediate negative value
            operands |= ENCODE_ਤੁਰੰਤ_FLAG;
            ਤੁਰੰਤ_ਮੁੱਲ = ops[2].e.v;
            /* Instruction swapping:
               0001 = EOR - Rd:= Op1 EOR Op2     -> difficult
               0011 = RSB - Rd:= Op2 - Op1       -> difficult
               0111 = RSC - Rd:= Op2 - Op1 + C   -> difficult
               1000 = TST - CC on: Op1 AND Op2   -> difficult
               1001 = TEQ - CC on: Op1 EOR Op2   -> difficult
               1100 = ORR - Rd:= Op1 OR Op2      -> difficult
            */
            ਚੋਣ (opcode_nos) {
            ਹਾਲਤ 0x0: // AND - Rd:= Op1 AND Op2
                opcode = 0xe << 21; // BIC
                ਤੁਰੰਤ_ਮੁੱਲ = ~ਤੁਰੰਤ_ਮੁੱਲ;
                ਰੋਕੋ;
            ਹਾਲਤ 0x2: // SUB - Rd:= Op1 - Op2
                opcode = 0x4 << 21; //ਜੋੜੋ
                ਤੁਰੰਤ_ਮੁੱਲ = -ਤੁਰੰਤ_ਮੁੱਲ;
                ਰੋਕੋ;
            ਹਾਲਤ 0x4: // ADD - Rd:= Op1 + Op2
                opcode = 0x2 << 21; // SUB
                ਤੁਰੰਤ_ਮੁੱਲ = -ਤੁਰੰਤ_ਮੁੱਲ;
                ਰੋਕੋ;
            ਹਾਲਤ 0x5: // ADC - Rd:= Op1 + Op2 + C
                opcode = 0x6 << 21; // SBC
                ਤੁਰੰਤ_ਮੁੱਲ = ~ਤੁਰੰਤ_ਮੁੱਲ;
                ਰੋਕੋ;
            ਹਾਲਤ 0x6: // SBC - Rd:= Op1 - Op2 + C
                opcode = 0x5 << 21; // ADC
                ਤੁਰੰਤ_ਮੁੱਲ = ~ਤੁਰੰਤ_ਮੁੱਲ;
                ਰੋਕੋ;
            ਹਾਲਤ 0xa: // CMP - CC on: Op1 - Op2
                opcode = 0xb << 21; // CMN
                ਤੁਰੰਤ_ਮੁੱਲ = -ਤੁਰੰਤ_ਮੁੱਲ;
                ਰੋਕੋ;
            ਹਾਲਤ 0xb: // CMN - CC on: Op1 + Op2
                opcode = 0xa << 21; // CMP
                ਤੁਰੰਤ_ਮੁੱਲ = -ਤੁਰੰਤ_ਮੁੱਲ;
                ਰੋਕੋ;
            ਹਾਲਤ 0xd: // MOV - Rd:= Op2
                opcode = 0xf << 21; // MVN
                ਤੁਰੰਤ_ਮੁੱਲ = ~ਤੁਰੰਤ_ਮੁੱਲ;
                ਰੋਕੋ;
            ਹਾਲਤ 0xe: // BIC - Rd:= Op1 AND NOT Op2
                opcode = 0x0 << 21; // AND
                ਤੁਰੰਤ_ਮੁੱਲ = ~ਤੁਰੰਤ_ਮੁੱਲ;
                ਰੋਕੋ;
            ਹਾਲਤ 0xf: // MVN - Rd:= NOT Op2
                opcode = 0xd << 21; // MOV
                ਤੁਰੰਤ_ਮੁੱਲ = ~ਤੁਰੰਤ_ਮੁੱਲ;
                ਰੋਕੋ;
            ਮੂਲ:
                tcc_error("cannot use '%s' with a negative immediate value", get_tok_str(token, ਨਿਰਾ));
            }
            ਲਈ (half_ਤੁਰੰਤ_rotation = 0; half_ਤੁਰੰਤ_rotation < 16; ++half_ਤੁਰੰਤ_rotation) {
                ਜੇ (ਤੁਰੰਤ_ਮੁੱਲ >= 0x00 && ਤੁਰੰਤ_ਮੁੱਲ < 0x100)
                    ਰੋਕੋ;
                // rotate left by two
                ਤੁਰੰਤ_ਮੁੱਲ = ((ਤੁਰੰਤ_ਮੁੱਲ & 0x3FFFFFFF) << 2) | ((ਤੁਰੰਤ_ਮੁੱਲ & 0xC0000000) >> 30);
            }
            ਜੇ (half_ਤੁਰੰਤ_rotation >= 16) {
                ਤੁਰੰਤ_ਮੁੱਲ = ops[2].e.v;
                tcc_error("immediate value 0x%X cannot be encoded into ARM immediate", (ਬਿਨਾਨਿਸ਼ਾਨੀ) ਤੁਰੰਤ_ਮੁੱਲ);
            }
            operands |= ਤੁਰੰਤ_ਮੁੱਲ;
            operands |= half_ਤੁਰੰਤ_rotation << 8;
            ਰੋਕੋ;
        ਮੂਲ:
            expect("(second source operand) register or immediate value");
        }

        ਜੇ (nb_ਖਿਸਕਾਓ) {
            ਜੇ (operands & ENCODE_ਤੁਰੰਤ_FLAG)
                tcc_error("immediate rotation not implemented");
            ਨਹੀਂਤਾਂ
                operands |= asm_encode_ਖਿਸਕਾਓ(&ਖਿਸਕਾਓ);
        }

        /* S=0 and S=1 entries alternate one after another, in that order */
        opcode |= (opcode_idx & 1) ? ENCODE_ਸੈੱਟ_CONDITION_CODES : 0;
        asm_emit_opcode(token, opcode | operands);
    }
}

ਸਥਿਰ ਖਾਲੀ asm_ਖਿਸਕਾਓ_opcode(TCCState *s1, ਪੂਰਨ token)
{
    ਸੰਕਾਰਜ ops[3];
    ਪੂਰਨ nb_ops;
    ਪੂਰਨ definitely_neutral = 0;
    uint32_t opcode = 0xd << 21; // MOV
    uint32_t operands = 0;

    ਲਈ (nb_ops = 0; nb_ops < ਆਕਾਰ(ops)/ਆਕਾਰ(ops[0]); ++nb_ops) {
        parse_ਸੰਕਾਰਜ(s1, &ops[nb_ops]);
        ਜੇ (tok != ',') {
            ++nb_ops;
            ਰੋਕੋ;
        }
        ਅਗਲਾ(); // skip ','
    }
    ਜੇ (nb_ops < 2) {
        expect("at least two operands");
    }

    ਜੇ (ops[0].type != OP_REG32) {
        expect("(destination operand) register");
    } ਨਹੀਂਤਾਂ
        operands |= ENCODE_RD(ops[0].reg);

    ਜੇ (nb_ops == 2) {
        ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
        ਹਾਲਤ TOK_ASM_rrxseq:
            opcode |= ENCODE_ਸੈੱਟ_CONDITION_CODES;
            /* fallthrough */
        ਹਾਲਤ TOK_ASM_rrxeq:
            ਜੇ (ops[1].type == OP_REG32) {
                operands |= ops[1].reg;
                operands |= ENCODE_BARREL_SHIFTER_ਬਹੁਲਕ_ROR;
                asm_emit_opcode(token, opcode | operands);
            } ਨਹੀਂਤਾਂ
                tcc_error("(first source operand) register");
            ਵਾਪਸ;
        ਮੂਲ:
            ਸਮ੍ਰਿਤੀ_ਨਕਲ(&ops[2], &ops[1], ਆਕਾਰ(ops[1])); // move ops[2]
            ਸਮ੍ਰਿਤੀ_ਨਕਲ(&ops[1], &ops[0], ਆਕਾਰ(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
    }
    ਜੇ (nb_ops != 3) {
        expect("two or three operands");
    }

    ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
    ਹਾਲਤ TOK_ASM_lslseq:
    ਹਾਲਤ TOK_ASM_lsrseq:
    ਹਾਲਤ TOK_ASM_asrseq:
    ਹਾਲਤ TOK_ASM_rorseq:
        opcode |= ENCODE_ਸੈੱਟ_CONDITION_CODES;
        ਰੋਕੋ;
    }

    ਚੋਣ (ops[1].type) {
    ਹਾਲਤ OP_REG32:
        operands |= ops[1].reg;
        ਰੋਕੋ;
    ਹਾਲਤ OP_IM8:
        operands |= ENCODE_ਤੁਰੰਤ_FLAG;
        operands |= ops[1].e.v;
        tcc_error("Using an immediate value as the source operand is not possible with '%s' instruction on ARM", get_tok_str(token, ਨਿਰਾ));
    }

    ਚੋਣ (ops[2].type) {
    ਹਾਲਤ OP_REG32:
        ਜੇ ((ops[0].type == OP_REG32 && ops[0].reg == 15) ||
            (ops[1].type == OP_REG32 && ops[1].reg == 15)) {
            tcc_error("Using the 'pc' register in data processing instructions that have a register-controlled shift is not implemented by ARM");
        }
        operands |= asm_encode_ਖਿਸਕਾਓ(&ops[2]);
        ਰੋਕੋ;
    ਹਾਲਤ OP_IM8:
        ਜੇ (ops[2].e.v)
            operands |= asm_encode_ਖਿਸਕਾਓ(&ops[2]);
        ਨਹੀਂਤਾਂ
            definitely_neutral = 1;
        ਰੋਕੋ;
    }

    ਜੇ (!definitely_neutral) ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
    ਹਾਲਤ TOK_ASM_lslseq:
    ਹਾਲਤ TOK_ASM_lsleq:
        operands |= ENCODE_BARREL_SHIFTER_ਬਹੁਲਕ_LSL;
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_lsrseq:
    ਹਾਲਤ TOK_ASM_lsreq:
        operands |= ENCODE_BARREL_SHIFTER_ਬਹੁਲਕ_LSR;
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_asrseq:
    ਹਾਲਤ TOK_ASM_asreq:
        operands |= ENCODE_BARREL_SHIFTER_ਬਹੁਲਕ_ASR;
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_rorseq:
    ਹਾਲਤ TOK_ASM_roreq:
        operands |= ENCODE_BARREL_SHIFTER_ਬਹੁਲਕ_ROR;
        ਰੋਕੋ;
    ਮੂਲ:
        expect("shift instruction");
    }
    asm_emit_opcode(token, opcode | operands);
}

ਸਥਿਰ ਖਾਲੀ asm_multiplication_opcode(TCCState *s1, ਪੂਰਨ token)
{
    ਸੰਕਾਰਜ ops[4];
    ਪੂਰਨ nb_ops = 0;
    uint32_t opcode = 0x90;

    ਲਈ (nb_ops = 0; nb_ops < ਆਕਾਰ(ops)/ਆਕਾਰ(ops[0]); ++nb_ops) {
        parse_ਸੰਕਾਰਜ(s1, &ops[nb_ops]);
        ਜੇ (tok != ',') {
            ++nb_ops;
            ਰੋਕੋ;
        }
        ਅਗਲਾ(); // skip ','
    }
    ਜੇ (nb_ops < 2)
        expect("at least two operands");
    ਨਹੀਂਤਾਂ ਜੇ (nb_ops == 2) {
        ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
        ਹਾਲਤ TOK_ASM_mulseq:
        ਹਾਲਤ TOK_ASM_muleq:
            ਸਮ੍ਰਿਤੀ_ਨਕਲ(&ops[2], &ops[0], ਆਕਾਰ(ops[1])); // ARM is actually like this!
            ਰੋਕੋ;
        ਮੂਲ:
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

    ਜੇ (ops[0].type == OP_REG32)
        opcode |= ops[0].reg << 16;
    ਨਹੀਂਤਾਂ
        expect("(destination operand) register");
    ਜੇ (ops[1].type == OP_REG32)
        opcode |= ops[1].reg;
    ਨਹੀਂਤਾਂ
        expect("(first source operand) register");
    ਜੇ (ops[2].type == OP_REG32)
        opcode |= ops[2].reg << 8;
    ਨਹੀਂਤਾਂ
        expect("(second source operand) register");
    ਜੇ (nb_ops > 3) {
        ਜੇ (ops[3].type == OP_REG32)
            opcode |= ops[3].reg << 12;
        ਨਹੀਂਤਾਂ
            expect("(third source operand) register");
    }

    ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
    ਹਾਲਤ TOK_ASM_mulseq:
        opcode |= 1 << 20; //ਸਥਿਤੀ
        /* fallthrough */
    ਹਾਲਤ TOK_ASM_muleq:
        ਜੇ (nb_ops != 3)
            expect("three operands");
        ਨਹੀਂਤਾਂ {
            asm_emit_opcode(token, opcode);
        }
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_mlaseq:
        opcode |= 1 << 20; //ਸਥਿਤੀ
        /* fallthrough */
    ਹਾਲਤ TOK_ASM_mlaeq:
    case_TOK_ASM_mlaeq:
        ਜੇ (nb_ops != 4)
            expect("four operands");
        ਨਹੀਂਤਾਂ {
            opcode |= 1 << 21; // Accumulate
            asm_emit_opcode(token, opcode);
        }
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_mlseq:
        opcode |= 0x00400000;
        ਜਾਓ case_TOK_ASM_mlaeq;
    ਹਾਲਤ TOK_ASM_udiveq:
        opcode |= 0x00200000;
    ਹਾਲਤ TOK_ASM_sdiveq:
        asm_emit_opcode(token, (opcode & ~0x80) | 0x0710f010);
        ਰੋਕੋ;
    ਮੂਲ:
        expect("known multiplication instruction");
    }
}

ਸਥਿਰ ਖਾਲੀ asm_long_multiplication_opcode(TCCState *s1, ਪੂਰਨ token)
{
    ਸੰਕਾਰਜ ops[4];
    ਪੂਰਨ nb_ops = 0;
    uint32_t opcode = 0x90 | (1 << 23);

    ਲਈ (nb_ops = 0; nb_ops < ਆਕਾਰ(ops)/ਆਕਾਰ(ops[0]); ++nb_ops) {
        parse_ਸੰਕਾਰਜ(s1, &ops[nb_ops]);
        ਜੇ (tok != ',') {
            ++nb_ops;
            ਰੋਕੋ;
        }
        ਅਗਲਾ(); // skip ','
    }
    ਜੇ (nb_ops != 4) {
        expect("four operands");
    }

    // long multiply (special case):
    // operands:
    //   RdLo: bits 15...12
    //   RdHi: bits 19...16
    //   Rs: bits 11...8
    //   Rm: bits 3...0

    ਜੇ (ops[0].type == OP_REG32)
        opcode |= ops[0].reg << 12;
    ਨਹੀਂਤਾਂ
        expect("(destination lo accumulator) register");
    ਜੇ (ops[1].type == OP_REG32)
        opcode |= ops[1].reg << 16;
    ਨਹੀਂਤਾਂ
        expect("(destination hi accumulator) register");
    ਜੇ (ops[2].type == OP_REG32)
        opcode |= ops[2].reg;
    ਨਹੀਂਤਾਂ
        expect("(first source operand) register");
    ਜੇ (ops[3].type == OP_REG32)
        opcode |= ops[3].reg << 8;
    ਨਹੀਂਤਾਂ
        expect("(second source operand) register");

    ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
    ਹਾਲਤ TOK_ASM_smullseq:
        opcode |= 1 << 20; //ਸਥਿਤੀ
        /* fallthrough */
    ਹਾਲਤ TOK_ASM_smulleq:
        opcode |= 1 << 22; // signed
        asm_emit_opcode(token, opcode);
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_umullseq:
        opcode |= 1 << 20; //ਸਥਿਤੀ
        /* fallthrough */
    ਹਾਲਤ TOK_ASM_umulleq:
        asm_emit_opcode(token, opcode);
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_smlalseq:
        opcode |= 1 << 20; //ਸਥਿਤੀ
        /* fallthrough */
    ਹਾਲਤ TOK_ASM_smlaleq:
        opcode |= 1 << 22; // signed
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_umlalseq:
        opcode |= 1 << 20; //ਸਥਿਤੀ
        /* fallthrough */
    ਹਾਲਤ TOK_ASM_umlaleq:
        opcode |= 1 << 21; // Accumulate
        asm_emit_opcode(token, opcode);
        ਰੋਕੋ;
    ਮੂਲ:
        expect("known long multiplication instruction");
    }
}

ਸਥਿਰ ਖਾਲੀ asm_single_ਅੰਕੜੇ_transfer_opcode(TCCState *s1, ਪੂਰਨ token)
{
    ਸੰਕਾਰਜ ops[3];
    ਸੰਕਾਰਜ strex_ਸੰਕਾਰਜ;
    ਸੰਕਾਰਜ ਖਿਸਕਾਓ;
    ਪੂਰਨ nb_ਖਿਸਕਾਓ = 0;
    ਪੂਰਨ exclam = 0;
    ਪੂਰਨ closed_bracket = 0;
    ਪੂਰਨ op2_minus = 0;
    uint32_t opcode = 0;
    // Note: ldr r0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: ldr r0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: ldr r0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_ਸੰਕਾਰਜ(s1, &ops[0]);
    ਜੇ (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    ਨਹੀਂਤਾਂ {
        expect("(destination operand) register");
    }
    ਜੇ (tok != ',')
        expect("at least two arguments");
    ਅਗਲਾ(); // skip ','

    ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
    ਹਾਲਤ TOK_ASM_strexheq:
    ਹਾਲਤ TOK_ASM_strexbeq:
    ਹਾਲਤ TOK_ASM_strexeq:
        parse_ਸੰਕਾਰਜ(s1, &strex_ਸੰਕਾਰਜ);
        ਜੇ (strex_ਸੰਕਾਰਜ.type != OP_REG32) {
            expect("register");
        }
        ਜੇ (tok != ',')
            expect("at least three arguments");
        ਨਹੀਂਤਾਂ
            ਅਗਲਾ(); // skip ','
        ਰੋਕੋ;
    }

    skip('[');
    parse_ਸੰਕਾਰਜ(s1, &ops[1]);
    ਜੇ (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    ਨਹੀਂਤਾਂ {
        expect("(first source operand) register");
    }
    ਜੇ (tok == ']') {
        ਅਗਲਾ();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    ਜੇ (tok == ',') {
        ਅਗਲਾ(); // skip ','
        ਜੇ (tok == '-') {
            op2_minus = 1;
            ਅਗਲਾ();
        }
        parse_ਸੰਕਾਰਜ(s1, &ops[2]);
        ਜੇ (ops[2].type == OP_REG32) {
            ਜੇ (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, ਨਿਰਾ));
            }
            ਜੇ (tok == ',') {
                ਅਗਲਾ();
                opcode |= asm_parse_optional_ਖਿਸਕਾਓ(s1, &nb_ਖਿਸਕਾਓ, &ਖਿਸਕਾਓ);
                ਜੇ (opcode == 0)
                    expect("shift directive, or no comma");
            }
        }
    } ਨਹੀਂਤਾਂ {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        opcode |= 1 << 24; // add offset before transfer
    }
    ਜੇ (!closed_bracket) {
        skip(']');
        opcode |= 1 << 24; // add offset before transfer
        ਜੇ (tok == '!') {
            exclam = 1;
            ਅਗਲਾ(); // skip '!'
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
    ਜੇ (exclam)
        opcode |= 1 << 21; // write offset back into register

    ਜੇ (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        ਪੂਰਨ v = ops[2].e.v;
        ਜੇ (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        ਜੇ (v >= 0) {
            opcode |= 1 << 23; //ਉੱਪਰ
            ਜੇ (v >= 0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ਨਿਰਾ));
            ਨਹੀਂਤਾਂ
                opcode |= v;
        } ਨਹੀਂਤਾਂ { //ਥੱਲੇ
            ਜੇ (v <= -0x1000)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ਨਿਰਾ));
            ਨਹੀਂਤਾਂ
                opcode |= -v;
        }
    } ਨਹੀਂਤਾਂ ਜੇ (ops[2].type == OP_REG32) {
        ਜੇ (!op2_minus)
            opcode |= 1 << 23; //ਉੱਪਰ
        opcode |= ENCODE_ਤੁਰੰਤ_FLAG; /* if set, it means it's NOT immediate */
        opcode |= ops[2].reg;
    } ਨਹੀਂਤਾਂ
        expect("register");

    ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
    ਹਾਲਤ TOK_ASM_strbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    ਹਾਲਤ TOK_ASM_streq:
        opcode |= 1 << 26; // Load/Store
        ਜੇ (nb_ਖਿਸਕਾਓ)
            opcode |= asm_encode_ਖਿਸਕਾਓ(&ਖਿਸਕਾਓ);
        asm_emit_opcode(token, opcode);
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_ldrbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    ਹਾਲਤ TOK_ASM_ldreq:
        opcode |= 1 << 20; // L
        opcode |= 1 << 26; // Load/Store
        ਜੇ (nb_ਖਿਸਕਾਓ)
            opcode |= asm_encode_ਖਿਸਕਾਓ(&ਖਿਸਕਾਓ);
        asm_emit_opcode(token, opcode);
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_strexheq:
        opcode |= 1 << 21;
    ਹਾਲਤ TOK_ASM_strexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    ਹਾਲਤ TOK_ASM_strexeq:
        ਜੇ ((opcode & 0xFFF) || nb_ਖਿਸਕਾਓ) {
            tcc_error("neither offset nor shift allowed with 'strex'");
        } ਨਹੀਂਤਾਂ ਜੇ (opcode & ENCODE_ਤੁਰੰਤ_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'strex'");
        }
        ਜੇ ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'strex'");
        }

        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        opcode |= strex_ਸੰਕਾਰਜ.reg;
        asm_emit_opcode(token, opcode);
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_ldrexheq:
        opcode |= 1 << 21;
    ਹਾਲਤ TOK_ASM_ldrexbeq:
        opcode |= 1 << 22; // B
        /* fallthrough */
    ਹਾਲਤ TOK_ASM_ldrexeq:
        ਜੇ ((opcode & 0xFFF) || nb_ਖਿਸਕਾਓ) {
            tcc_error("neither offset nor shift allowed with 'ldrex'");
        } ਨਹੀਂਤਾਂ ਜੇ (opcode & ENCODE_ਤੁਰੰਤ_FLAG) { // if set, it means it's NOT immediate
            tcc_error("offset not allowed with 'ldrex'");
        }
        ਜੇ ((opcode & (1 << 24)) == 0) { // add offset after transfer
            tcc_error("adding offset after transfer not allowed with 'ldrex'");
        }
        opcode |= 1 << 20; // L
        opcode |= 0x00f;
        opcode |= 0xf90; // Used to mean: barrel shifter is enabled, barrel shift register is r15, mode is LSL
        asm_emit_opcode(token, opcode);
        ਰੋਕੋ;
    ਮੂਲ:
        expect("data transfer instruction");
    }
}

// Note: Only call this using a VFP register if you know exactly what you are doing (i.e. cp_number is 10 or 11 and you are doing a vmov)
ਸਥਿਰ ਖਾਲੀ asm_emit_coprocessor_ਅੰਕੜੇ_transfer(uint32_t ਉੱਚਾ_nibble, uint8_t cp_ਸੰਖਿਆ, uint8_t CRd, ਅਚਲ ਸੰਕਾਰਜ* Rn, ਅਚਲ ਸੰਕਾਰਜ* ਵਿੱਥ, ਪੂਰਨ ਵਿੱਥ_minus, ਪੂਰਨ preincrement, ਪੂਰਨ writeback, ਪੂਰਨ long_transfer, ਪੂਰਨ ਲੱਦੋ) {
    uint32_t opcode = 0x0;
    opcode |= 1 << 26; // Load/Store
    opcode |= 1 << 27; // coprocessor

    ਜੇ (long_transfer)
        opcode |= 1 << 22; // long transfer

    ਜੇ (ਲੱਦੋ)
        opcode |= 1 << 20; // L

    opcode |= cp_ਸੰਖਿਆ << 8;

    //assert(CRd < 16);
    opcode |= ENCODE_RD(CRd);

    ਜੇ (Rn->type != OP_REG32)
        expect("register");

    //assert(Rn->reg < 16);
    opcode |= ENCODE_RN(Rn->reg);
    ਜੇ (preincrement)
        opcode |= 1 << 24; // add offset before transfer

    ਜੇ (writeback)
        opcode |= 1 << 21; // write offset back into register

    ਜੇ (ਵਿੱਥ->type == OP_IM8 || ਵਿੱਥ->type == OP_IM8N || ਵਿੱਥ->type == OP_IM32) {
        ਪੂਰਨ v = ਵਿੱਥ->e.v;
        ਜੇ (ਵਿੱਥ_minus)
            tcc_error("minus before '#' not supported for immediate values");
        ਜੇ (ਵਿੱਥ->type == OP_IM8N || v < 0)
            v = -v;
        ਨਹੀਂਤਾਂ
            opcode |= 1 << 23; //ਉੱਪਰ
        ਜੇ (v & 3) {
            tcc_error("immediate offset must be a multiple of 4");
        }
        v >>= 2;
        ਜੇ (v > 255) {
            tcc_error("immediate offset must be between -1020 and 1020");
        }
        opcode |= v;
    } ਨਹੀਂਤਾਂ ਜੇ (ਵਿੱਥ->type == OP_REG32) {
        ਜੇ (!ਵਿੱਥ_minus)
            opcode |= 1 << 23; //ਉੱਪਰ
        opcode |= ENCODE_ਤੁਰੰਤ_FLAG; /* if set, it means it's NOT immediate */
        opcode |= ਵਿੱਥ->reg;
        tcc_error("Using register offset to register address is not possible here");
    } ਨਹੀਂਤਾਂ ਜੇ (ਵਿੱਥ->type == OP_VREG64) {
        opcode |= 16;
        opcode |= ਵਿੱਥ->reg;
    } ਨਹੀਂਤਾਂ
        expect("immediate or register");

    asm_emit_unconditional_opcode((ਉੱਚਾ_nibble << 28) | opcode);
}

// Almost exactly the same as asm_single_data_transfer_opcode.
// Difference: Offsets are smaller and multiples of 4; no shifts, no STREX, ENCODE_IMMEDIATE_FLAG is inverted again.
ਸਥਿਰ ਖਾਲੀ asm_coprocessor_ਅੰਕੜੇ_transfer_opcode(TCCState *s1, ਪੂਰਨ token)
{
    ਸੰਕਾਰਜ ops[3];
    uint8_t coprocessor;
    uint8_t coprocessor_destination_ਰਜਿਸਟਰ;
    ਪੂਰਨ preincrement = 0;
    ਪੂਰਨ exclam = 0;
    ਪੂਰਨ closed_bracket = 0;
    ਪੂਰਨ op2_minus = 0;
    ਪੂਰਨ long_transfer = 0;
    // Note: ldc p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: ldc p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: ldc p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    ਜੇ (tok >= TOK_ASM_p0 && tok <= TOK_ASM_p15) {
        coprocessor = tok - TOK_ASM_p0;
        ਅਗਲਾ();
    } ਨਹੀਂਤਾਂ {
        expect("'c<number>'");
    }

    skip(',');

    ਜੇ (tok >= TOK_ASM_c0 && tok <= TOK_ASM_c15) {
        coprocessor_destination_ਰਜਿਸਟਰ = tok - TOK_ASM_c0;
        ਅਗਲਾ();
    } ਨਹੀਂਤਾਂ {
        expect("'c<number>'");
    }

    skip(',');
    skip('[');
    parse_ਸੰਕਾਰਜ(s1, &ops[1]);
    ਜੇ (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    ਜੇ (tok == ']') {
        ਅਗਲਾ();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    ਜੇ (tok == ',') {
        ਅਗਲਾ(); // skip ','
        ਜੇ (tok == '-') {
            op2_minus = 1;
            ਅਗਲਾ();
        }
        parse_ਸੰਕਾਰਜ(s1, &ops[2]);
        ਜੇ (ops[2].type == OP_REG32) {
            ਜੇ (ops[2].reg == 15) {
                tcc_error("Using 'pc' for register offset in '%s' is not implemented by ARM", get_tok_str(token, ਨਿਰਾ));
            }
        } ਨਹੀਂਤਾਂ ਜੇ (ops[2].type == OP_VREG64) {
            tcc_error("'%s' does not support VFP register operand", get_tok_str(token, ਨਿਰਾ));
        }
    } ਨਹੀਂਤਾਂ {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        preincrement = 1; // add offset before transfer
    }
    ਜੇ (!closed_bracket) {
        skip(']');
        preincrement = 1; // add offset before transfer
        ਜੇ (tok == '!') {
            exclam = 1;
            ਅਗਲਾ(); // skip '!'
        }
    }

    // TODO: Support options.

    ਜੇ (token == TOK_ASM_ldc2 || token == TOK_ASM_stc2 || token == TOK_ASM_ldc2l || token == TOK_ASM_stc2l) {
        ਚੋਣ (token) {
        ਹਾਲਤ TOK_ASM_ldc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        ਹਾਲਤ TOK_ASM_ldc2:
            asm_emit_coprocessor_ਅੰਕੜੇ_transfer(0xF, coprocessor, coprocessor_destination_ਰਜਿਸਟਰ, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
            ਰੋਕੋ;
        ਹਾਲਤ TOK_ASM_stc2l:
            long_transfer = 1; // long transfer
            /* fallthrough */
        ਹਾਲਤ TOK_ASM_stc2:
            asm_emit_coprocessor_ਅੰਕੜੇ_transfer(0xF, coprocessor, coprocessor_destination_ਰਜਿਸਟਰ, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
            ਰੋਕੋ;
        }
    } ਨਹੀਂਤਾਂ ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
    ਹਾਲਤ TOK_ASM_stcleq:
        long_transfer = 1;
        /* fallthrough */
    ਹਾਲਤ TOK_ASM_stceq:
        asm_emit_coprocessor_ਅੰਕੜੇ_transfer(condition_ਕੋਡ_ਦਾ_token(token), coprocessor, coprocessor_destination_ਰਜਿਸਟਰ, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 0);
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_ldcleq:
        long_transfer = 1;
        /* fallthrough */
    ਹਾਲਤ TOK_ASM_ldceq:
        asm_emit_coprocessor_ਅੰਕੜੇ_transfer(condition_ਕੋਡ_ਦਾ_token(token), coprocessor, coprocessor_destination_ਰਜਿਸਟਰ, &ops[1], &ops[2], op2_minus, preincrement, exclam, long_transfer, 1);
        ਰੋਕੋ;
    ਮੂਲ:
        expect("coprocessor data transfer instruction");
    }
}

#ਜੇ defined(TCC_ARM_VFP)
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CP_SINGLE_PRECISION_FLOAT 10
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ CP_DOUBLE_PRECISION_FLOAT 11

ਸਥਿਰ ਖਾਲੀ asm_floating_ਬਿੰਦੂ_single_ਅੰਕੜੇ_transfer_opcode(TCCState *s1, ਪੂਰਨ token)
{
    ਸੰਕਾਰਜ ops[3];
    uint8_t coprocessor = 0;
    uint8_t coprocessor_destination_ਰਜਿਸਟਰ = 0;
    ਪੂਰਨ long_transfer = 0;
    // Note: vldr p1, c0, [r4, #4]  ; simple offset: r0 = *(int*)(r4+4); r4 unchanged
    // Note: Not allowed: vldr p2, c0, [r4, #4]! ; pre-indexed:   r0 = *(int*)(r4+4); r4 = r4+4
    // Note: Not allowed: vldr p3, c0, [r4], #4  ; post-indexed:  r0 = *(int*)(r4+0); r4 = r4+4

    parse_ਸੰਕਾਰਜ(s1, &ops[0]);
    ਜੇ (ops[0].type == OP_VREG32) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        coprocessor_destination_ਰਜਿਸਟਰ = ops[0].reg;
        long_transfer = coprocessor_destination_ਰਜਿਸਟਰ & 1;
        coprocessor_destination_ਰਜਿਸਟਰ >>= 1;
    } ਨਹੀਂਤਾਂ ਜੇ (ops[0].type == OP_VREG64) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        coprocessor_destination_ਰਜਿਸਟਰ = ops[0].reg;
        ਅਗਲਾ();
    } ਨਹੀਂਤਾਂ {
        expect("floating point register");
    }

    skip(',');
    skip('[');
    parse_ਸੰਕਾਰਜ(s1, &ops[1]);
    ਜੇ (ops[1].type != OP_REG32) {
        expect("(first source operand) register");
    }
    ਜੇ (tok == ',') {
        ਅਗਲਾ(); // skip ','
        parse_ਸੰਕਾਰਜ(s1, &ops[2]);
        ਜੇ (ops[2].type != OP_IM8 && ops[2].type != OP_IM8N) {
            expect("immediate offset");
        }
    } ਨਹੀਂਤਾਂ {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
    }
    skip(']');

    ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
    ਹਾਲਤ TOK_ASM_vldreq:
        asm_emit_coprocessor_ਅੰਕੜੇ_transfer(condition_ਕੋਡ_ਦਾ_token(token), coprocessor, coprocessor_destination_ਰਜਿਸਟਰ, &ops[1], &ops[2], 0, 1, 0, long_transfer, 1);
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_vstreq:
        asm_emit_coprocessor_ਅੰਕੜੇ_transfer(condition_ਕੋਡ_ਦਾ_token(token), coprocessor, coprocessor_destination_ਰਜਿਸਟਰ, &ops[1], &ops[2], 0, 1, 0, long_transfer, 0);
        ਰੋਕੋ;
    ਮੂਲ:
        expect("floating point data transfer instruction");
    }
}

ਸਥਿਰ ਖਾਲੀ asm_floating_ਬਿੰਦੂ_ਖੰਡ_ਅੰਕੜੇ_transfer_opcode(TCCState *s1, ਪੂਰਨ token)
{
    uint8_t coprocessor = 0;
    ਪੂਰਨ ਪਹਿਲਾ_regset_ਰਜਿਸਟਰ;
    ਪੂਰਨ ਆਖਰੀ_regset_ਰਜਿਸਟਰ;
    uint8_t regset_ਵਸਤੂ_ਗਿਣਤੀ;
    uint8_t extra_ਰਜਿਸਟਰ_ਦੋਆਧਾਰੀ_ਅੰਕ = 0;
    ਪੂਰਨ op0_exclam = 0;
    ਪੂਰਨ ਲੱਦੋ = 0;
    ਪੂਰਨ preincrement = 0;
    ਸੰਕਾਰਜ ops[1];
    ਸੰਕਾਰਜ ਵਿੱਥ;
    ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
    ਹਾਲਤ TOK_ASM_vpusheq:
    ਹਾਲਤ TOK_ASM_vpopeq:
        ops[0].type = OP_REG32;
        ops[0].reg = 13; // sp
        op0_exclam = 1;
        ਰੋਕੋ;
    ਮੂਲ:
        parse_ਸੰਕਾਰਜ(s1, &ops[0]);
        ਜੇ (tok == '!') {
            op0_exclam = 1;
            ਅਗਲਾ(); // skip '!'
        }
        skip(',');
    }

    skip('{');
    ਪਹਿਲਾ_regset_ਰਜਿਸਟਰ = asm_parse_vfp_regvar(tok, 1);
    ਜੇ ((ਪਹਿਲਾ_regset_ਰਜਿਸਟਰ = asm_parse_vfp_regvar(tok, 1)) != -1) {
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
        ਅਗਲਾ();
    } ਨਹੀਂਤਾਂ ਜੇ ((ਪਹਿਲਾ_regset_ਰਜਿਸਟਰ = asm_parse_vfp_regvar(tok, 0)) != -1) {
        coprocessor = CP_SINGLE_PRECISION_FLOAT;
        ਅਗਲਾ();
    } ਨਹੀਂਤਾਂ {
        expect("floating-point register");
    }

    ਜੇ (tok == '-') {
        ਅਗਲਾ();
        ਜੇ ((ਆਖਰੀ_regset_ਰਜਿਸਟਰ = asm_parse_vfp_regvar(tok, coprocessor == CP_DOUBLE_PRECISION_FLOAT)) != -1)
            ਅਗਲਾ();
        ਨਹੀਂਤਾਂ {
            expect("floating-point register");
        }
    } ਨਹੀਂਤਾਂ
        ਆਖਰੀ_regset_ਰਜਿਸਟਰ = ਪਹਿਲਾ_regset_ਰਜਿਸਟਰ;

    ਜੇ (ਆਖਰੀ_regset_ਰਜਿਸਟਰ < ਪਹਿਲਾ_regset_ਰਜਿਸਟਰ) {
        tcc_error("registers will be processed in ascending order by hardware--but are not specified in ascending order here");
    }
    skip('}');
    // Note: 0 (one down) is not implemented by us regardless.
    regset_ਵਸਤੂ_ਗਿਣਤੀ = ਆਖਰੀ_regset_ਰਜਿਸਟਰ - ਪਹਿਲਾ_regset_ਰਜਿਸਟਰ + 1;
    ਜੇ (coprocessor == CP_DOUBLE_PRECISION_FLOAT)
        regset_ਵਸਤੂ_ਗਿਣਤੀ <<= 1;
    ਨਹੀਂਤਾਂ {
        extra_ਰਜਿਸਟਰ_ਦੋਆਧਾਰੀ_ਅੰਕ = ਪਹਿਲਾ_regset_ਰਜਿਸਟਰ & 1;
        ਪਹਿਲਾ_regset_ਰਜਿਸਟਰ >>= 1;
    }
    ਵਿੱਥ.type = OP_IM8;
    ਵਿੱਥ.e.v = regset_ਵਸਤੂ_ਗਿਣਤੀ << 2;
    ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
    ਹਾਲਤ TOK_ASM_vstmeq: // post-increment store
    ਹਾਲਤ TOK_ASM_vstmiaeq: // post-increment store
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_vpopeq:
    ਹਾਲਤ TOK_ASM_vldmeq: // post-increment load
    ਹਾਲਤ TOK_ASM_vldmiaeq: // post-increment load
        ਲੱਦੋ = 1;
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_vldmdbeq: // pre-decrement load
        ਲੱਦੋ = 1;
        /* fallthrough */
    ਹਾਲਤ TOK_ASM_vpusheq:
    ਹਾਲਤ TOK_ASM_vstmdbeq: // pre-decrement store
        ਵਿੱਥ.type = OP_IM8N;
        ਵਿੱਥ.e.v = -ਵਿੱਥ.e.v;
        preincrement = 1;
        ਰੋਕੋ;
    ਮੂਲ:
        expect("floating point block data transfer instruction");
    }
    ਜੇ (ops[0].type != OP_REG32)
        expect("(first operand) register");
    ਨਹੀਂਤਾਂ ਜੇ (ops[0].reg == 15)
        tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ਨਿਰਾ));
    ਨਹੀਂਤਾਂ ਜੇ (!op0_exclam && ARM_INSTRUCTION_ਸਮੂਹ(token) != TOK_ASM_vldmeq && ARM_INSTRUCTION_ਸਮੂਹ(token) != TOK_ASM_vldmiaeq && ARM_INSTRUCTION_ਸਮੂਹ(token) != TOK_ASM_vstmeq && ARM_INSTRUCTION_ਸਮੂਹ(token) != TOK_ASM_vstmiaeq)
        tcc_error("first operand of '%s' should have an exclamation mark", get_tok_str(token, ਨਿਰਾ));
    ਨਹੀਂਤਾਂ
        asm_emit_coprocessor_ਅੰਕੜੇ_transfer(condition_ਕੋਡ_ਦਾ_token(token), coprocessor, ਪਹਿਲਾ_regset_ਰਜਿਸਟਰ, &ops[0], &ਵਿੱਥ, 0, preincrement, op0_exclam, extra_ਰਜਿਸਟਰ_ਦੋਆਧਾਰੀ_ਅੰਕ, ਲੱਦੋ);
}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VMOV_FRACTIONAL_DIGITS 7
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ VMOV_ONE 10000000 /* pow(10, VMOV_FRACTIONAL_DIGITS) */

ਸਥਿਰ uint32_t vmov_parse_fractional_part(ਅਚਲ ਅੱਖਰ* s)
{
    uint32_t ਨਤੀਜਾ = 0;
    ਪੂਰਨ i;
    ਲਈ (i = 0; i < VMOV_FRACTIONAL_DIGITS; ++i) {
        ਅੱਖਰ c = *s;
        ਨਤੀਜਾ *= 10;
        ਜੇ (c >= '0' && c <= '9') {
            ਨਤੀਜਾ += (c - '0');
            ++s;
        }
    }
    ਜੇ (*s)
        expect("decimal numeral");
    ਵਾਪਸ ਨਤੀਜਾ;
}

ਸਥਿਰ ਪੂਰਨ vmov_ਰੇਖਿਕ_approx_ਸੂਚਕਾਂਕ(uint32_t beginning, uint32_t ਸਿਰਾ, uint32_t ਮੁੱਲ)
{
    ਪੂਰਨ i;
    uint32_t k;
    uint32_t xvalue;

    k = (ਸਿਰਾ - beginning)/16;
    ਲਈ (xvalue = beginning, i = 0; i < 16; ++i, xvalue += k) {
        ਜੇ (ਮੁੱਲ == xvalue)
            ਵਾਪਸ i;
    }
    //assert(0);
    ਵਾਪਸ -1;
}

ਸਥਿਰ uint32_t vmov_parse_ਤੁਰੰਤ_ਮੁੱਲ() {
    uint32_t ਮੁੱਲ;
    ਬਿਨਾਨਿਸ਼ਾਨੀ ਲੰਮਾ integral_ਮੁੱਲ;
    ਅਚਲ ਅੱਖਰ *p;

    ਜੇ (tok != TOK_PPNUM) {
        expect("immediate value");
    }
    p = tokc.str.ਅੰਕੜੇ;
    errno = 0;
    integral_ਮੁੱਲ = strtoul(p, (ਅੱਖਰ **)&p, 0);

    ਜੇ (errno || integral_ਮੁੱਲ >= 32) {
        tcc_error("invalid floating-point immediate value");
    }

    ਮੁੱਲ = (uint32_t) integral_ਮੁੱਲ * VMOV_ONE;
    ਜੇ (*p == '.') {
        ++p;
        ਮੁੱਲ += vmov_parse_fractional_part(p);
    }
    ਅਗਲਾ();
    ਵਾਪਸ ਮੁੱਲ;
}

ਸਥਿਰ uint8_t vmov_encode_ਤੁਰੰਤ_ਮੁੱਲ(uint32_t ਮੁੱਲ)
{
    uint32_t ਹੱਦਬੰਦੀ;
    uint32_t ਸਿਰਾ = 0;
    uint32_t beginning = 0;
    ਪੂਰਨ r = -1;
    ਪੂਰਨ n;
    ਪੂਰਨ i;

    ਹੱਦਬੰਦੀ = 32 * VMOV_ONE;
    ਲਈ (i = 0; i < 8; ++i) {
        ਜੇ (ਮੁੱਲ < ਹੱਦਬੰਦੀ) {
            ਸਿਰਾ = ਹੱਦਬੰਦੀ;
            ਹੱਦਬੰਦੀ >>= 1;
            beginning = ਹੱਦਬੰਦੀ;
            r = i;
        } ਨਹੀਂਤਾਂ
            ਹੱਦਬੰਦੀ >>= 1;
    }
    ਜੇ (r == -1 || ਮੁੱਲ < beginning || ਮੁੱਲ > ਸਿਰਾ) {
        tcc_error("invalid decimal number for vmov: %d", ਮੁੱਲ);
    }
    n = vmov_ਰੇਖਿਕ_approx_ਸੂਚਕਾਂਕ(beginning, ਸਿਰਾ, ਮੁੱਲ);
    ਵਾਪਸ n | (((3 - r) & 0x7) << 4);
}

// Not standalone.
ਸਥਿਰ ਖਾਲੀ asm_floating_ਬਿੰਦੂ_ਤੁਰੰਤ_ਅੰਕੜੇ_processing_opcode_ਪੂਛ(TCCState *s1, ਪੂਰਨ token, uint8_t coprocessor, uint8_t CRd) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    uint8_t operands[3] = {0, 0, 0};
    uint32_t ਤੁਰੰਤ_ਮੁੱਲ = 0;
    ਪੂਰਨ op_minus = 0;
    uint8_t ਕੋਡ;

    operands[0] = CRd;

    ਜੇ (tok == '#' || tok == '$') {
        ਅਗਲਾ();
    }
    ਜੇ (tok == '-') {
        op_minus = 1;
        ਅਗਲਾ();
    }
    ਤੁਰੰਤ_ਮੁੱਲ = vmov_parse_ਤੁਰੰਤ_ਮੁੱਲ();

    opcode1 = 11; // "Other" instruction
    ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
    ਹਾਲਤ TOK_ASM_vcmpeq_f32:
    ਹਾਲਤ TOK_ASM_vcmpeq_f64:
        opcode2 = 2;
        operands[1] = 5;
        ਜੇ (ਤੁਰੰਤ_ਮੁੱਲ) {
            expect("Immediate value 0");
        }
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_vcmpeeq_f32:
    ਹਾਲਤ TOK_ASM_vcmpeeq_f64:
        opcode2 = 6;
        operands[1] = 5;
        ਜੇ (ਤੁਰੰਤ_ਮੁੱਲ) {
            expect("Immediate value 0");
        }
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_vmoveq_f32:
    ਹਾਲਤ TOK_ASM_vmoveq_f64:
        opcode2 = 0;
        ਜੇ (op_minus)
            operands[1] = 0x8;
        ਨਹੀਂਤਾਂ
            operands[1] = 0x0;
        ਕੋਡ = vmov_encode_ਤੁਰੰਤ_ਮੁੱਲ(ਤੁਰੰਤ_ਮੁੱਲ);
        operands[1] |= ਕੋਡ >> 4;
        operands[2] = ਕੋਡ & 0xF;
        ਰੋਕੋ;
    ਮੂਲ:
        expect("known floating point with immediate instruction");
    }

    ਜੇ (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        ਜੇ (operands[0] & 1)
            opcode1 |= 4;
        operands[0] >>= 1;
    }

    asm_emit_coprocessor_opcode(condition_ਕੋਡ_ਦਾ_token(token), coprocessor, opcode1, operands[0], operands[1], operands[2], opcode2, 0);
}

ਸਥਿਰ ਖਾਲੀ asm_floating_ਬਿੰਦੂ_reg_arm_reg_transfer_opcode_ਪੂਛ(TCCState *s1, ਪੂਰਨ token, ਪੂਰਨ coprocessor, ਪੂਰਨ nb_arm_regs, ਪੂਰਨ nb_ops, ਸੰਕਾਰਜ ops[3]) {
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0;
    ਚੋਣ (coprocessor) {
    ਹਾਲਤ CP_SINGLE_PRECISION_FLOAT:
        // "vmov.f32 r2, s3" or "vmov.f32 s3, r2"
        ਜੇ (nb_ops != 2 || nb_arm_regs != 1) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and one ARM register operands");
        }
        ਜੇ (ops[0].type != OP_REG32) { // determine mode: load or store
            // need to swap operands 0 and 1
            ਸਮ੍ਰਿਤੀ_ਨਕਲ(&ops[2], &ops[1], ਆਕਾਰ(ops[2]));
            ਸਮ੍ਰਿਤੀ_ਨਕਲ(&ops[1], &ops[0], ਆਕਾਰ(ops[1]));
            ਸਮ੍ਰਿਤੀ_ਨਕਲ(&ops[0], &ops[2], ਆਕਾਰ(ops[0]));
        } ਨਹੀਂਤਾਂ
            opcode1 |= 1;

        ਜੇ (ops[1].type == OP_VREG32) {
            ਜੇ (ops[1].reg & 1)
                opcode2 |= 4;
            ops[1].reg >>= 1;
        }

        ਜੇ (ops[0].type == OP_VREG32) {
            ਜੇ (ops[0].reg & 1)
                opcode1 |= 4;
            ops[0].reg >>= 1;
        }

        asm_emit_coprocessor_opcode(condition_ਕੋਡ_ਦਾ_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, 0x10, opcode2, 0);
        ਰੋਕੋ;
    ਹਾਲਤ CP_DOUBLE_PRECISION_FLOAT:
        ਜੇ (nb_ops != 3 || nb_arm_regs != 2) {
            tcc_error("vmov.f32 only implemented for one VFP register operand and two ARM register operands");
        }
        // Determine whether it's a store into a VFP register (vmov "d1, r2, r3") rather than "vmov r2, r3, d1"
        ਜੇ (ops[0].type == OP_VREG64) {
            ਜੇ (ops[2].type == OP_REG32) {
                ਸੰਕਾਰਜ ਆਰਜ਼ੀ;
                // need to rotate operand list to the left
                ਸਮ੍ਰਿਤੀ_ਨਕਲ(&ਆਰਜ਼ੀ, &ops[0], ਆਕਾਰ(ਆਰਜ਼ੀ));
                ਸਮ੍ਰਿਤੀ_ਨਕਲ(&ops[0], &ops[1], ਆਕਾਰ(ops[0]));
                ਸਮ੍ਰਿਤੀ_ਨਕਲ(&ops[1], &ops[2], ਆਕਾਰ(ops[1]));
                ਸਮ੍ਰਿਤੀ_ਨਕਲ(&ops[2], &ਆਰਜ਼ੀ, ਆਕਾਰ(ops[2]));
            } ਨਹੀਂਤਾਂ {
                tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
            }
        } ਨਹੀਂਤਾਂ ਜੇ (ops[0].type != OP_REG32 || ops[1].type != OP_REG32 || ops[2].type != OP_VREG64) {
            tcc_error("vmov.f64 only implemented for one VFP register operand and two ARM register operands");
        } ਨਹੀਂਤਾਂ {
            opcode1 |= 1;
        }
        asm_emit_coprocessor_ਅੰਕੜੇ_transfer(condition_ਕੋਡ_ਦਾ_token(token), coprocessor, ops[0].reg, &ops[1], &ops[2], 0, 0, 0, 1, opcode1);
        ਰੋਕੋ;
    ਮੂਲ:
        tcc_ਅੰਦਰੂਨੀ_error("unknown coprocessor");
    }
}

ਸਥਿਰ ਖਾਲੀ asm_floating_ਬਿੰਦੂ_vcvt_ਅੰਕੜੇ_processing_opcode(TCCState *s1, ਪੂਰਨ token) {
    uint8_t coprocessor = 0;
    ਸੰਕਾਰਜ ops[3];
    uint8_t opcode1 = 11;
    uint8_t opcode2 = 2;

    ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
    ਹਾਲਤ TOK_ASM_vcvtreq_s32_f64:
    ਹਾਲਤ TOK_ASM_vcvtreq_u32_f64:
    ਹਾਲਤ TOK_ASM_vcvteq_s32_f64:
    ਹਾਲਤ TOK_ASM_vcvteq_u32_f64:
    ਹਾਲਤ TOK_ASM_vcvteq_f64_s32:
    ਹਾਲਤ TOK_ASM_vcvteq_f64_u32:
    ਹਾਲਤ TOK_ASM_vcvteq_f32_f64:
       coprocessor = CP_DOUBLE_PRECISION_FLOAT;
       ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_vcvtreq_s32_f32:
    ਹਾਲਤ TOK_ASM_vcvtreq_u32_f32:
    ਹਾਲਤ TOK_ASM_vcvteq_s32_f32:
    ਹਾਲਤ TOK_ASM_vcvteq_u32_f32:
    ਹਾਲਤ TOK_ASM_vcvteq_f32_s32:
    ਹਾਲਤ TOK_ASM_vcvteq_f32_u32:
    ਹਾਲਤ TOK_ASM_vcvteq_f64_f32:
       coprocessor = CP_SINGLE_PRECISION_FLOAT;
       ਰੋਕੋ;
    ਮੂਲ:
       tcc_error("Unknown coprocessor for instruction '%s'", get_tok_str(token, ਨਿਰਾ));
    }

    parse_ਸੰਕਾਰਜ(s1, &ops[0]);
    ops[1].type = OP_IM8;
    ops[1].e.v = 8;
    /* floating-point -> integer */
    ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
    ਹਾਲਤ TOK_ASM_vcvtreq_s32_f32:
    ਹਾਲਤ TOK_ASM_vcvtreq_s32_f64:
    ਹਾਲਤ TOK_ASM_vcvteq_s32_f32:
    ਹਾਲਤ TOK_ASM_vcvteq_s32_f64:
        ops[1].e.v |= 1; // signed
        /* fall through */
    ਹਾਲਤ TOK_ASM_vcvteq_u32_f32:
    ਹਾਲਤ TOK_ASM_vcvteq_u32_f64:
    ਹਾਲਤ TOK_ASM_vcvtreq_u32_f32:
    ਹਾਲਤ TOK_ASM_vcvtreq_u32_f64:
        ops[1].e.v |= 4; // to_integer (opc2)
        ਰੋਕੋ;
    /* floating-point size conversion */
    ਹਾਲਤ TOK_ASM_vcvteq_f64_f32:
    ਹਾਲਤ TOK_ASM_vcvteq_f32_f64:
        ops[1].e.v = 7;
        ਰੋਕੋ;
    }

    skip(',');
    parse_ਸੰਕਾਰਜ(s1, &ops[2]);

    ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
    /* floating-point -> integer */
    ਹਾਲਤ TOK_ASM_vcvteq_s32_f32:
    ਹਾਲਤ TOK_ASM_vcvteq_s32_f64:
    ਹਾਲਤ TOK_ASM_vcvteq_u32_f32:
    ਹਾਲਤ TOK_ASM_vcvteq_u32_f64:
        opcode2 |= 4; // round_zero
        ਰੋਕੋ;

    /* integer -> floating-point */
    ਹਾਲਤ TOK_ASM_vcvteq_f64_s32:
    ਹਾਲਤ TOK_ASM_vcvteq_f32_s32:
        opcode2 |= 4; // signed--special
        ਰੋਕੋ;

    /* floating-point size conversion */
    ਹਾਲਤ TOK_ASM_vcvteq_f64_f32:
    ਹਾਲਤ TOK_ASM_vcvteq_f32_f64:
        opcode2 |= 4; // always set
        ਰੋਕੋ;
    }

    ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
    ਹਾਲਤ TOK_ASM_vcvteq_f64_u32:
    ਹਾਲਤ TOK_ASM_vcvteq_f64_s32:
    ਹਾਲਤ TOK_ASM_vcvteq_f64_f32:
        ਜੇ (ops[0].type == OP_VREG64 && ops[2].type == OP_VREG32) {
        } ਨਹੀਂਤਾਂ {
            expect("d<number>, s<number>");
        }
        ਰੋਕੋ;
    ਮੂਲ:
        ਜੇ (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
            ਜੇ (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG32) {
            } ਨਹੀਂਤਾਂ {
                expect("s<number>, s<number>");
            }
        } ਨਹੀਂਤਾਂ ਜੇ (coprocessor == CP_DOUBLE_PRECISION_FLOAT) {
            ਜੇ (ops[0].type == OP_VREG32 && ops[2].type == OP_VREG64) {
            } ਨਹੀਂਤਾਂ {
                expect("s<number>, d<number>");
            }
        }
    }

    ਜੇ (ops[2].type == OP_VREG32) {
        ਜੇ (ops[2].reg & 1)
            opcode2 |= 1;
        ops[2].reg >>= 1;
    }
    ਜੇ (ops[0].type == OP_VREG32) {
        ਜੇ (ops[0].reg & 1)
            opcode1 |= 4;
        ops[0].reg >>= 1;
    }
    asm_emit_coprocessor_opcode(condition_ਕੋਡ_ਦਾ_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

ਸਥਿਰ ਖਾਲੀ asm_floating_ਬਿੰਦੂ_ਅੰਕੜੇ_processing_opcode(TCCState *s1, ਪੂਰਨ token) {
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode1 = 0;
    uint8_t opcode2 = 0; // (0 || 2) | register selection
    ਸੰਕਾਰਜ ops[3];
    uint8_t nb_ops = 0;
    ਪੂਰਨ vmov = 0;
    ਪੂਰਨ nb_arm_regs = 0;

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

    ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
    ਹਾਲਤ TOK_ASM_vmlaeq_f64:
    ਹਾਲਤ TOK_ASM_vmlseq_f64:
    ਹਾਲਤ TOK_ASM_vnmlseq_f64:
    ਹਾਲਤ TOK_ASM_vnmlaeq_f64:
    ਹਾਲਤ TOK_ASM_vmuleq_f64:
    ਹਾਲਤ TOK_ASM_vnmuleq_f64:
    ਹਾਲਤ TOK_ASM_vaddeq_f64:
    ਹਾਲਤ TOK_ASM_vsubeq_f64:
    ਹਾਲਤ TOK_ASM_vdiveq_f64:
    ਹਾਲਤ TOK_ASM_vnegeq_f64:
    ਹਾਲਤ TOK_ASM_vabseq_f64:
    ਹਾਲਤ TOK_ASM_vsqrteq_f64:
    ਹਾਲਤ TOK_ASM_vcmpeq_f64:
    ਹਾਲਤ TOK_ASM_vcmpeeq_f64:
    ਹਾਲਤ TOK_ASM_vmoveq_f64:
        coprocessor = CP_DOUBLE_PRECISION_FLOAT;
    }

    ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
    ਹਾਲਤ TOK_ASM_vmoveq_f32:
    ਹਾਲਤ TOK_ASM_vmoveq_f64:
        vmov = 1;
        ਰੋਕੋ;
    }

    ਲਈ (nb_ops = 0; nb_ops < 3; ) {
        // Note: Necessary because parse_operand can't parse decimal numerals.
        ਜੇ (nb_ops == 1 && (tok == '#' || tok == '$' || tok == TOK_PPNUM || tok == '-')) {
            asm_floating_ਬਿੰਦੂ_ਤੁਰੰਤ_ਅੰਕੜੇ_processing_opcode_ਪੂਛ(s1, token, coprocessor, ops[0].reg);
            ਵਾਪਸ;
        }
        parse_ਸੰਕਾਰਜ(s1, &ops[nb_ops]);
        ਜੇ (vmov && ops[nb_ops].type == OP_REG32) {
            ++nb_arm_regs;
        } ਨਹੀਂਤਾਂ ਜੇ (ops[nb_ops].type == OP_VREG32) {
            ਜੇ (coprocessor != CP_SINGLE_PRECISION_FLOAT) {
                expect("'s<number>'");
            }
        } ਨਹੀਂਤਾਂ ਜੇ (ops[nb_ops].type == OP_VREG64) {
            ਜੇ (coprocessor != CP_DOUBLE_PRECISION_FLOAT) {
                expect("'d<number>'");
            }
        } ਨਹੀਂਤਾਂ {
            expect("floating point register");
        }
        ++nb_ops;
        ਜੇ (tok == ',')
            ਅਗਲਾ();
        ਨਹੀਂਤਾਂ
            ਰੋਕੋ;
    }

    ਜੇ (nb_arm_regs == 0) {
        ਜੇ (nb_ops == 2) { // implicit
            ਸਮ੍ਰਿਤੀ_ਨਕਲ(&ops[2], &ops[1], ਆਕਾਰ(ops[1])); // move ops[2]
            ਸਮ੍ਰਿਤੀ_ਨਕਲ(&ops[1], &ops[0], ਆਕਾਰ(ops[0])); // ops[1] was implicit
            nb_ops = 3;
        }
        ਜੇ (nb_ops < 3) {
            tcc_error("Not enough operands for '%s' (%u)", get_tok_str(token, ਨਿਰਾ), nb_ops);
        }
    }

    ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
    ਹਾਲਤ TOK_ASM_vmlaeq_f32:
    ਹਾਲਤ TOK_ASM_vmlaeq_f64:
        opcode1 = 0;
        opcode2 = 0;
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_vmlseq_f32:
    ਹਾਲਤ TOK_ASM_vmlseq_f64:
        opcode1 = 0;
        opcode2 = 2;
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_vnmlseq_f32:
    ਹਾਲਤ TOK_ASM_vnmlseq_f64:
        opcode1 = 1;
        opcode2 = 0;
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_vnmlaeq_f32:
    ਹਾਲਤ TOK_ASM_vnmlaeq_f64:
        opcode1 = 1;
        opcode2 = 2;
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_vmuleq_f32:
    ਹਾਲਤ TOK_ASM_vmuleq_f64:
        opcode1 = 2;
        opcode2 = 0;
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_vnmuleq_f32:
    ਹਾਲਤ TOK_ASM_vnmuleq_f64:
        opcode1 = 2;
        opcode2 = 2;
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_vaddeq_f32:
    ਹਾਲਤ TOK_ASM_vaddeq_f64:
        opcode1 = 3;
        opcode2 = 0;
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_vsubeq_f32:
    ਹਾਲਤ TOK_ASM_vsubeq_f64:
        opcode1 = 3;
        opcode2 = 2;
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_vdiveq_f32:
    ਹਾਲਤ TOK_ASM_vdiveq_f64:
        opcode1 = 8;
        opcode2 = 0;
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_vnegeq_f32:
    ਹਾਲਤ TOK_ASM_vnegeq_f64:
        opcode1 = 11; // Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_vabseq_f32:
    ਹਾਲਤ TOK_ASM_vabseq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 0;
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_vsqrteq_f32:
    ਹਾਲਤ TOK_ASM_vsqrteq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 1;
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_vcmpeq_f32:
    ਹਾਲਤ TOK_ASM_vcmpeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 2;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_vcmpeeq_f32:
    ਹਾਲਤ TOK_ASM_vcmpeeq_f64:
        opcode1 = 11; // "Other" instruction
        opcode2 = 6;
        ops[1].type = OP_IM8;
        ops[1].e.v = 4;
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_vmoveq_f32:
    ਹਾਲਤ TOK_ASM_vmoveq_f64:
        ਜੇ (nb_arm_regs > 0) { // vmov.f32 r2, s3 or similar
            asm_floating_ਬਿੰਦੂ_reg_arm_reg_transfer_opcode_ਪੂਛ(s1, token, coprocessor, nb_arm_regs, nb_ops, ops);
            ਵਾਪਸ;
        } ਨਹੀਂਤਾਂ {
            opcode1 = 11; // "Other" instruction
            opcode2 = 2;
            ops[1].type = OP_IM8;
            ops[1].e.v = 0;
        }
        ਰੋਕੋ;
    ਮੂਲ:
        expect("known floating point instruction");
    }

    ਜੇ (coprocessor == CP_SINGLE_PRECISION_FLOAT) {
        ਜੇ (ops[2].type == OP_VREG32) {
            ਜੇ (ops[2].reg & 1)
                opcode2 |= 1;
            ops[2].reg >>= 1;
        }

        ਜੇ (ops[1].type == OP_VREG32) {
            ਜੇ (ops[1].reg & 1)
                opcode2 |= 4;
            ops[1].reg >>= 1;
        }

        ਜੇ (ops[0].type == OP_VREG32) {
            ਜੇ (ops[0].reg & 1)
                opcode1 |= 4;
            ops[0].reg >>= 1;
        }
    }

    asm_emit_coprocessor_opcode(condition_ਕੋਡ_ਦਾ_token(token), coprocessor, opcode1, ops[0].reg, (ops[1].type == OP_IM8) ? ops[1].e.v : ops[1].reg, (ops[2].type == OP_IM8) ? ops[2].e.v : ops[2].reg, opcode2, 0);
}

ਸਥਿਰ ਪੂਰਨ asm_parse_vfp_ਸਥਿਤੀ_regvar(ਪੂਰਨ t)
{
    ਚੋਣ (t) {
    ਹਾਲਤ TOK_ASM_fpsid:
        ਵਾਪਸ 0;
    ਹਾਲਤ TOK_ASM_fpscr:
        ਵਾਪਸ 1;
    ਹਾਲਤ TOK_ASM_fpexc:
        ਵਾਪਸ 8;
    ਮੂਲ:
        ਵਾਪਸ -1;
    }
}

ਸਥਿਰ ਖਾਲੀ asm_floating_ਬਿੰਦੂ_ਸਥਿਤੀ_ਰਜਿਸਟਰ_opcode(TCCState* s1, ਪੂਰਨ token)
{
    uint8_t coprocessor = CP_SINGLE_PRECISION_FLOAT;
    uint8_t opcode;
    ਪੂਰਨ vfp_sys_reg = -1;
    ਸੰਕਾਰਜ arm_ਸੰਕਾਰਜ;
    ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
    ਹਾਲਤ TOK_ASM_vmrseq:
        opcode = 0xf;
        ਜੇ (tok == TOK_ASM_apsr_nzcv) {
            arm_ਸੰਕਾਰਜ.type = OP_REG32;
            arm_ਸੰਕਾਰਜ.reg = 15; // not PC
            ਅਗਲਾ(); // skip apsr_nzcv
        } ਨਹੀਂਤਾਂ {
            parse_ਸੰਕਾਰਜ(s1, &arm_ਸੰਕਾਰਜ);
            ਜੇ (arm_ਸੰਕਾਰਜ.type == OP_REG32 && arm_ਸੰਕਾਰਜ.reg == 15) {
                tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ਨਿਰਾ));
            }
        }

        skip(',');
        vfp_sys_reg = asm_parse_vfp_ਸਥਿਤੀ_regvar(tok);
        ਅਗਲਾ(); // skip vfp sys reg
        ਜੇ (arm_ਸੰਕਾਰਜ.type == OP_REG32 && arm_ਸੰਕਾਰਜ.reg == 15 && vfp_sys_reg != 1) {
            tcc_error("'%s' only supports the variant 'vmrs apsr_nzcv, fpscr' here", get_tok_str(token, ਨਿਰਾ));
        }
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_vmsreq:
        opcode = 0xe;
        vfp_sys_reg = asm_parse_vfp_ਸਥਿਤੀ_regvar(tok);
        ਅਗਲਾ(); // skip vfp sys reg
        skip(',');
        parse_ਸੰਕਾਰਜ(s1, &arm_ਸੰਕਾਰਜ);
        ਜੇ (arm_ਸੰਕਾਰਜ.type == OP_REG32 && arm_ਸੰਕਾਰਜ.reg == 15) {
            tcc_error("'%s' does not support 'pc' as operand", get_tok_str(token, ਨਿਰਾ));
        }
        ਰੋਕੋ;
    ਮੂਲ:
        expect("floating point status register instruction");
    }
    ਜੇ (vfp_sys_reg == -1) {
        expect("VFP system register");
    }
    ਜੇ (arm_ਸੰਕਾਰਜ.type != OP_REG32) {
        expect("ARM register");
    }
    asm_emit_coprocessor_opcode(condition_ਕੋਡ_ਦਾ_token(token), coprocessor, opcode, arm_ਸੰਕਾਰਜ.reg, vfp_sys_reg, 0x10, 0, 0);
}

#ਜੇ_ਅੰਤ

ਸਥਿਰ ਖਾਲੀ asm_misc_single_ਅੰਕੜੇ_transfer_opcode(TCCState *s1, ਪੂਰਨ token)
{
    ਸੰਕਾਰਜ ops[3];
    ਪੂਰਨ exclam = 0;
    ਪੂਰਨ closed_bracket = 0;
    ਪੂਰਨ op2_minus = 0;
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

    parse_ਸੰਕਾਰਜ(s1, &ops[0]);
    ਜੇ (ops[0].type == OP_REG32)
        opcode |= ENCODE_RD(ops[0].reg);
    ਨਹੀਂਤਾਂ {
        expect("(destination operand) register");
    }
    ਜੇ (tok != ',')
        expect("at least two arguments");
    ਨਹੀਂਤਾਂ
        ਅਗਲਾ(); // skip ','
    skip('[');
    parse_ਸੰਕਾਰਜ(s1, &ops[1]);
    ਜੇ (ops[1].type == OP_REG32)
        opcode |= ENCODE_RN(ops[1].reg);
    ਨਹੀਂਤਾਂ {
        expect("(first source operand) register");
    }
    ਜੇ (tok == ']') {
        ਅਗਲਾ();
        closed_bracket = 1;
        // exclam = 1; // implicit in hardware; don't do it in software
    }
    ਜੇ (tok == ',') {
        ਅਗਲਾ(); // skip ','
        ਜੇ (tok == '-') {
            op2_minus = 1;
            ਅਗਲਾ();
        }
        parse_ਸੰਕਾਰਜ(s1, &ops[2]);
    } ਨਹੀਂਤਾਂ {
        // end of input expression in brackets--assume 0 offset
        ops[2].type = OP_IM8;
        ops[2].e.v = 0;
        opcode |= 1 << 24; // add offset before transfer
    }
    ਜੇ (!closed_bracket) {
        skip(']');
        opcode |= 1 << 24; // add offset before transfer
        ਜੇ (tok == '!') {
            exclam = 1;
            ਅਗਲਾ(); // skip '!'
        }
    }

    ਜੇ (exclam) {
        ਜੇ ((opcode & (1 << 24)) == 0) {
            tcc_error("result of '%s' would be unpredictable here", get_tok_str(token, ਨਿਰਾ));
        }
        opcode |= 1 << 21; // write offset back into register
    }

    ਜੇ (ops[2].type == OP_IM32 || ops[2].type == OP_IM8 || ops[2].type == OP_IM8N) {
        ਪੂਰਨ v = ops[2].e.v;
        ਜੇ (op2_minus)
            tcc_error("minus before '#' not supported for immediate values");
        ਜੇ (v >= 0) {
            opcode |= 1 << 23; //ਉੱਪਰ
            ਜੇ (v >= 0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ਨਿਰਾ));
            ਨਹੀਂਤਾਂ {
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        } ਨਹੀਂਤਾਂ { //ਥੱਲੇ
            ਜੇ (v <= -0x100)
                tcc_error("offset out of range for '%s'", get_tok_str(token, ਨਿਰਾ));
            ਨਹੀਂਤਾਂ {
                v = -v;
                // bits 11...8: immediate hi nibble
                // bits 3...0: immediate lo nibble
                opcode |= (v & 0xF0) << 4;
                opcode |= v & 0xF;
            }
        }
        opcode |= 1 << 22; // not ENCODE_IMMEDIATE_FLAG;
    } ਨਹੀਂਤਾਂ ਜੇ (ops[2].type == OP_REG32) {
        ਜੇ (!op2_minus)
            opcode |= 1 << 23; //ਉੱਪਰ
        opcode |= ops[2].reg;
    } ਨਹੀਂਤਾਂ
        expect("register");

    ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
    ਹਾਲਤ TOK_ASM_ldrsheq:
        opcode |= 1 << 5; // halfword, not byte
        /* fallthrough */
    ਹਾਲਤ TOK_ASM_ldrsbeq:
        opcode |= 1 << 6; // sign extend
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_ldrheq:
        opcode |= 1 << 5; // halfword, not byte
        opcode |= 1 << 20; // L
        asm_emit_opcode(token, opcode);
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_strheq:
        opcode |= 1 << 5; // halfword, not byte
        asm_emit_opcode(token, opcode);
        ਰੋਕੋ;
    }
}

/* Note: almost dupe of encbranch in arm-gen.c */
ਸਥਿਰ uint32_t encbranchoffset(ਪੂਰਨ pos, ਪੂਰਨ addr, ਪੂਰਨ fail)
{
  addr-=pos+8;
  addr/=4;
  ਜੇ(addr>=0x7fffff || addr<-0x800000) {
    ਜੇ(fail)
      tcc_error("branch offset is too far");
    ਵਾਪਸ 0;
  }
  ਵਾਪਸ /*not 0x0A000000|*/(addr&0xffffff);
}

ਸਥਿਰ ਖਾਲੀ asm_branch_opcode(TCCState *s1, ਪੂਰਨ token)
{
    ਪੂਰਨ jmp_disp = 0;
    ਸੰਕਾਰਜ op;
    ਵਿਅੰਜਕ_ਮੁੱਲ e;
    ElfSym *esym;

    ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
    ਹਾਲਤ TOK_ASM_beq:
    ਹਾਲਤ TOK_ASM_bleq:
        asm_ਵਿਅੰਜਕ(s1, &e);
        ਜੇ (e.sym) {
            esym = elfsym(e.sym);
            ਜੇ (esym && esym->st_shndx == cur_ਪਾਠ_section->sh_ਅੰਕ) {
                jmp_disp = esym->st_ਮੁੱਲ;
            } ਨਹੀਂਤਾਂ {
                greloca(cur_ਪਾਠ_section, e.sym, ind, R_ARM_PC24, 0);
                jmp_disp = ind;
            }
        }
        jmp_disp = encbranchoffset(ind, e.v + jmp_disp, 1);
        ਰੋਕੋ;
    ਮੂਲ:
        parse_ਸੰਕਾਰਜ(s1, &op);
        ਰੋਕੋ;
    }
    ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
    ਹਾਲਤ TOK_ASM_beq:
        asm_emit_opcode(token, (0xa << 24) | (jmp_disp & 0xffffff));
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_bleq:
        asm_emit_opcode(token, (0xb << 24) | (jmp_disp & 0xffffff));
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_bxeq:
        ਜੇ (op.type != OP_REG32)
            expect("register");
        ਨਹੀਂਤਾਂ
            asm_emit_opcode(token, (0x12fff1 << 4) | op.reg);
        ਰੋਕੋ;
    ਹਾਲਤ TOK_ASM_blxeq:
        ਜੇ (op.type != OP_REG32)
            expect("register");
        ਨਹੀਂਤਾਂ
            asm_emit_opcode(token, (0x12fff3 << 4) | op.reg);
        ਰੋਕੋ;
    ਮੂਲ:
        expect("branch instruction");
    }
}

ST_FUNC ਖਾਲੀ asm_opcode(TCCState *s1, ਪੂਰਨ token)
{
    ਜਦੋਂ (token == TOK_LINEFEED) {
        ਅਗਲਾ();
        token = tok;
    }
    ਜੇ (token == TOK_EOF)
        ਵਾਪਸ;
    ਜੇ (token < TOK_ASM_nopeq) { // no condition code
        ਚੋਣ (token) {
        ਹਾਲਤ TOK_ASM_cdp2:
            asm_coprocessor_opcode(s1, token);
            ਵਾਪਸ;
        ਹਾਲਤ TOK_ASM_ldc2:
        ਹਾਲਤ TOK_ASM_ldc2l:
        ਹਾਲਤ TOK_ASM_stc2:
        ਹਾਲਤ TOK_ASM_stc2l:
            asm_coprocessor_ਅੰਕੜੇ_transfer_opcode(s1, token);
            ਵਾਪਸ;
        ਮੂਲ:
            expect("instruction");
        }
    }

    ਚੋਣ (ARM_INSTRUCTION_ਸਮੂਹ(token)) {
    ਹਾਲਤ TOK_ASM_pusheq:
    ਹਾਲਤ TOK_ASM_popeq:
    ਹਾਲਤ TOK_ASM_stmdaeq:
    ਹਾਲਤ TOK_ASM_ldmdaeq:
    ਹਾਲਤ TOK_ASM_stmeq:
    ਹਾਲਤ TOK_ASM_ldmeq:
    ਹਾਲਤ TOK_ASM_stmiaeq:
    ਹਾਲਤ TOK_ASM_ldmiaeq:
    ਹਾਲਤ TOK_ASM_stmdbeq:
    ਹਾਲਤ TOK_ASM_ldmdbeq:
    ਹਾਲਤ TOK_ASM_stmibeq:
    ਹਾਲਤ TOK_ASM_ldmibeq:
        asm_ਖੰਡ_ਅੰਕੜੇ_transfer_opcode(s1, token);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_nopeq:
    ਹਾਲਤ TOK_ASM_wfeeq:
    ਹਾਲਤ TOK_ASM_wfieq:
        asm_nullary_opcode(token);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_swieq:
    ਹਾਲਤ TOK_ASM_svceq:
        asm_unary_opcode(s1, token);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_beq:
    ਹਾਲਤ TOK_ASM_bleq:
    ਹਾਲਤ TOK_ASM_bxeq:
    ਹਾਲਤ TOK_ASM_blxeq:
        asm_branch_opcode(s1, token);
        ਵਾਪਸ;
    ਹਾਲਤ TOK_ASM_clzeq:
    ਹਾਲਤ TOK_ASM_sxtbeq:
    ਹਾਲਤ TOK_ASM_sxtheq:
    ਹਾਲਤ TOK_ASM_uxtbeq:
    ਹਾਲਤ TOK_ASM_uxtheq:
    ਹਾਲਤ TOK_ASM_movteq:
    ਹਾਲਤ TOK_ASM_movweq:
        asm_ਦੁਆਧਾਰੀ_opcode(s1, token);
        ਵਾਪਸ;

    ਹਾਲਤ TOK_ASM_ldreq:
    ਹਾਲਤ TOK_ASM_ldrbeq:
    ਹਾਲਤ TOK_ASM_streq:
    ਹਾਲਤ TOK_ASM_strbeq:
    ਹਾਲਤ TOK_ASM_ldrexeq:
    ਹਾਲਤ TOK_ASM_ldrexbeq:
    ਹਾਲਤ TOK_ASM_ldrexheq:
    ਹਾਲਤ TOK_ASM_strexeq:
    ਹਾਲਤ TOK_ASM_strexbeq:
    ਹਾਲਤ TOK_ASM_strexheq:
        asm_single_ਅੰਕੜੇ_transfer_opcode(s1, token);
        ਵਾਪਸ;

    ਹਾਲਤ TOK_ASM_ldrheq:
    ਹਾਲਤ TOK_ASM_ldrsheq:
    ਹਾਲਤ TOK_ASM_ldrsbeq:
    ਹਾਲਤ TOK_ASM_strheq:
       asm_misc_single_ਅੰਕੜੇ_transfer_opcode(s1, token);
       ਵਾਪਸ;

    ਹਾਲਤ TOK_ASM_andeq:
    ਹਾਲਤ TOK_ASM_eoreq:
    ਹਾਲਤ TOK_ASM_subeq:
    ਹਾਲਤ TOK_ASM_rsbeq:
    ਹਾਲਤ TOK_ASM_addeq:
    ਹਾਲਤ TOK_ASM_adceq:
    ਹਾਲਤ TOK_ASM_sbceq:
    ਹਾਲਤ TOK_ASM_rsceq:
    ਹਾਲਤ TOK_ASM_tsteq:
    ਹਾਲਤ TOK_ASM_teqeq:
    ਹਾਲਤ TOK_ASM_cmpeq:
    ਹਾਲਤ TOK_ASM_cmneq:
    ਹਾਲਤ TOK_ASM_orreq:
    ਹਾਲਤ TOK_ASM_moveq:
    ਹਾਲਤ TOK_ASM_biceq:
    ਹਾਲਤ TOK_ASM_mvneq:
    ਹਾਲਤ TOK_ASM_andseq:
    ਹਾਲਤ TOK_ASM_eorseq:
    ਹਾਲਤ TOK_ASM_subseq:
    ਹਾਲਤ TOK_ASM_rsbseq:
    ਹਾਲਤ TOK_ASM_addseq:
    ਹਾਲਤ TOK_ASM_adcseq:
    ਹਾਲਤ TOK_ASM_sbcseq:
    ਹਾਲਤ TOK_ASM_rscseq:
//  case TOK_ASM_tstseq:
//  case TOK_ASM_teqseq:
//  case TOK_ASM_cmpseq:
//  case TOK_ASM_cmnseq:
    ਹਾਲਤ TOK_ASM_orrseq:
    ਹਾਲਤ TOK_ASM_movseq:
    ਹਾਲਤ TOK_ASM_bicseq:
    ਹਾਲਤ TOK_ASM_mvnseq:
        asm_ਅੰਕੜੇ_processing_opcode(s1, token);
        ਵਾਪਸ;

    ਹਾਲਤ TOK_ASM_lsleq:
    ਹਾਲਤ TOK_ASM_lslseq:
    ਹਾਲਤ TOK_ASM_lsreq:
    ਹਾਲਤ TOK_ASM_lsrseq:
    ਹਾਲਤ TOK_ASM_asreq:
    ਹਾਲਤ TOK_ASM_asrseq:
    ਹਾਲਤ TOK_ASM_roreq:
    ਹਾਲਤ TOK_ASM_rorseq:
    ਹਾਲਤ TOK_ASM_rrxseq:
    ਹਾਲਤ TOK_ASM_rrxeq:
        asm_ਖਿਸਕਾਓ_opcode(s1, token);
        ਵਾਪਸ;

    ਹਾਲਤ TOK_ASM_muleq:
    ਹਾਲਤ TOK_ASM_mulseq:
    ਹਾਲਤ TOK_ASM_mlaeq:
    ਹਾਲਤ TOK_ASM_mlaseq:
    ਹਾਲਤ TOK_ASM_mlseq:
    ਹਾਲਤ TOK_ASM_udiveq:
    ਹਾਲਤ TOK_ASM_sdiveq:
        asm_multiplication_opcode(s1, token);
        ਵਾਪਸ;

    ਹਾਲਤ TOK_ASM_smulleq:
    ਹਾਲਤ TOK_ASM_smullseq:
    ਹਾਲਤ TOK_ASM_umulleq:
    ਹਾਲਤ TOK_ASM_umullseq:
    ਹਾਲਤ TOK_ASM_smlaleq:
    ਹਾਲਤ TOK_ASM_smlalseq:
    ਹਾਲਤ TOK_ASM_umlaleq:
    ਹਾਲਤ TOK_ASM_umlalseq:
        asm_long_multiplication_opcode(s1, token);
        ਵਾਪਸ;

    ਹਾਲਤ TOK_ASM_cdpeq:
    ਹਾਲਤ TOK_ASM_mcreq:
    ਹਾਲਤ TOK_ASM_mrceq:
        asm_coprocessor_opcode(s1, token);
        ਵਾਪਸ;

    ਹਾਲਤ TOK_ASM_ldceq:
    ਹਾਲਤ TOK_ASM_ldcleq:
    ਹਾਲਤ TOK_ASM_stceq:
    ਹਾਲਤ TOK_ASM_stcleq:
        asm_coprocessor_ਅੰਕੜੇ_transfer_opcode(s1, token);
        ਵਾਪਸ;

#ਜੇ defined(TCC_ARM_VFP)
    ਹਾਲਤ TOK_ASM_vldreq:
    ਹਾਲਤ TOK_ASM_vstreq:
        asm_floating_ਬਿੰਦੂ_single_ਅੰਕੜੇ_transfer_opcode(s1, token);
        ਵਾਪਸ;

    ਹਾਲਤ TOK_ASM_vmlaeq_f32:
    ਹਾਲਤ TOK_ASM_vmlseq_f32:
    ਹਾਲਤ TOK_ASM_vnmlseq_f32:
    ਹਾਲਤ TOK_ASM_vnmlaeq_f32:
    ਹਾਲਤ TOK_ASM_vmuleq_f32:
    ਹਾਲਤ TOK_ASM_vnmuleq_f32:
    ਹਾਲਤ TOK_ASM_vaddeq_f32:
    ਹਾਲਤ TOK_ASM_vsubeq_f32:
    ਹਾਲਤ TOK_ASM_vdiveq_f32:
    ਹਾਲਤ TOK_ASM_vnegeq_f32:
    ਹਾਲਤ TOK_ASM_vabseq_f32:
    ਹਾਲਤ TOK_ASM_vsqrteq_f32:
    ਹਾਲਤ TOK_ASM_vcmpeq_f32:
    ਹਾਲਤ TOK_ASM_vcmpeeq_f32:
    ਹਾਲਤ TOK_ASM_vmoveq_f32:
    ਹਾਲਤ TOK_ASM_vmlaeq_f64:
    ਹਾਲਤ TOK_ASM_vmlseq_f64:
    ਹਾਲਤ TOK_ASM_vnmlseq_f64:
    ਹਾਲਤ TOK_ASM_vnmlaeq_f64:
    ਹਾਲਤ TOK_ASM_vmuleq_f64:
    ਹਾਲਤ TOK_ASM_vnmuleq_f64:
    ਹਾਲਤ TOK_ASM_vaddeq_f64:
    ਹਾਲਤ TOK_ASM_vsubeq_f64:
    ਹਾਲਤ TOK_ASM_vdiveq_f64:
    ਹਾਲਤ TOK_ASM_vnegeq_f64:
    ਹਾਲਤ TOK_ASM_vabseq_f64:
    ਹਾਲਤ TOK_ASM_vsqrteq_f64:
    ਹਾਲਤ TOK_ASM_vcmpeq_f64:
    ਹਾਲਤ TOK_ASM_vcmpeeq_f64:
    ਹਾਲਤ TOK_ASM_vmoveq_f64:
        asm_floating_ਬਿੰਦੂ_ਅੰਕੜੇ_processing_opcode(s1, token);
        ਵਾਪਸ;

    ਹਾਲਤ TOK_ASM_vcvtreq_s32_f32:
    ਹਾਲਤ TOK_ASM_vcvtreq_s32_f64:
    ਹਾਲਤ TOK_ASM_vcvteq_s32_f32:
    ਹਾਲਤ TOK_ASM_vcvteq_s32_f64:
    ਹਾਲਤ TOK_ASM_vcvtreq_u32_f32:
    ਹਾਲਤ TOK_ASM_vcvtreq_u32_f64:
    ਹਾਲਤ TOK_ASM_vcvteq_u32_f32:
    ਹਾਲਤ TOK_ASM_vcvteq_u32_f64:
    ਹਾਲਤ TOK_ASM_vcvteq_f64_s32:
    ਹਾਲਤ TOK_ASM_vcvteq_f32_s32:
    ਹਾਲਤ TOK_ASM_vcvteq_f64_u32:
    ਹਾਲਤ TOK_ASM_vcvteq_f32_u32:
    ਹਾਲਤ TOK_ASM_vcvteq_f64_f32:
    ਹਾਲਤ TOK_ASM_vcvteq_f32_f64:
        asm_floating_ਬਿੰਦੂ_vcvt_ਅੰਕੜੇ_processing_opcode(s1, token);
        ਵਾਪਸ;

    ਹਾਲਤ TOK_ASM_vpusheq:
    ਹਾਲਤ TOK_ASM_vpopeq:
    ਹਾਲਤ TOK_ASM_vldmeq:
    ਹਾਲਤ TOK_ASM_vldmiaeq:
    ਹਾਲਤ TOK_ASM_vldmdbeq:
    ਹਾਲਤ TOK_ASM_vstmeq:
    ਹਾਲਤ TOK_ASM_vstmiaeq:
    ਹਾਲਤ TOK_ASM_vstmdbeq:
        asm_floating_ਬਿੰਦੂ_ਖੰਡ_ਅੰਕੜੇ_transfer_opcode(s1, token);
        ਵਾਪਸ;

    ਹਾਲਤ TOK_ASM_vmsreq:
    ਹਾਲਤ TOK_ASM_vmrseq:
        asm_floating_ਬਿੰਦੂ_ਸਥਿਤੀ_ਰਜਿਸਟਰ_opcode(s1, token);
        ਵਾਪਸ;
#ਜੇ_ਅੰਤ

    ਮੂਲ:
        expect("known instruction");
    }
}

ST_FUNC ਖਾਲੀ subst_asm_ਸੰਕਾਰਜ(CString *ਜੋੜੋ_str, SValue *sv, ਪੂਰਨ modifier)
{
    ਪੂਰਨ r, reg, ਮਾਪ, val;

    r = sv->r;
    ਜੇ ((r & VT_VALMASK) == VT_CONST) {
        ਜੇ (!(r & VT_LVAL) && modifier != 'c' && modifier != 'n' &&
            modifier != 'P')
            cstr_ccat(ਜੋੜੋ_str, '#');
        ਜੇ (r & VT_SYM) {
            ਅਚਲ ਅੱਖਰ *name = get_tok_str(sv->sym->v, ਨਿਰਾ);
            ਜੇ (sv->sym->v >= SYM_ਪਹਿਲਾ_ANOM) {
                /* In case of anonymous symbols ("L.42", used
                   for static data labels) we can't find them
                   in the C symbol table when later looking up
                   this name.  So enter them now into the asm label
                   list when we still know the symbol.  */
                get_asm_sym(tok_alloc(name, ਲੜੀ_ਲੰਬਾਈ(name))->tok, sv->sym);
            }
            ਜੇ (tcc_state->leading_underscore)
                cstr_ccat(ਜੋੜੋ_str, '_');
            cstr_cat(ਜੋੜੋ_str, name, -1);
            ਜੇ ((uint32_t) sv->c.i == 0)
                ਜਾਓ no_ਵਿੱਥ;
            cstr_ccat(ਜੋੜੋ_str, '+');
        }
        val = sv->c.i;
        ਜੇ (modifier == 'n')
            val = -val;
        cstr_printf(ਜੋੜੋ_str, "%d", val);
      no_ਵਿੱਥ:;
    } ਨਹੀਂਤਾਂ ਜੇ ((r & VT_VALMASK) == VT_LOCAL) {
        cstr_printf(ਜੋੜੋ_str, "[fp,#%d]", (ਪੂਰਨ) sv->c.i);
    } ਨਹੀਂਤਾਂ ਜੇ (r & VT_LVAL) {
        reg = r & VT_VALMASK;
        ਜੇ (reg >= VT_CONST)
            tcc_ਅੰਦਰੂਨੀ_error("");
        cstr_printf(ਜੋੜੋ_str, "[%s]",
                 get_tok_str(TOK_ASM_r0 + reg, ਨਿਰਾ));
    } ਨਹੀਂਤਾਂ {
        /* register case */
        reg = r & VT_VALMASK;
        ਜੇ (reg >= VT_CONST)
            tcc_ਅੰਦਰੂਨੀ_error("");

        /* choose register operand size */
        ਜੇ ((sv->type.t & VT_BTYPE) == VT_BYTE ||
            (sv->type.t & VT_BTYPE) == VT_BOOL)
            ਮਾਪ = 1;
        ਨਹੀਂਤਾਂ ਜੇ ((sv->type.t & VT_BTYPE) == VT_SHORT)
            ਮਾਪ = 2;
        ਨਹੀਂਤਾਂ
            ਮਾਪ = 4;

        ਜੇ (modifier == 'b') {
            ਮਾਪ = 1;
        } ਨਹੀਂਤਾਂ ਜੇ (modifier == 'w') {
            ਮਾਪ = 2;
        } ਨਹੀਂਤਾਂ ਜੇ (modifier == 'k') {
            ਮਾਪ = 4;
        }

        ਚੋਣ (ਮਾਪ) {
        ਮੂਲ:
            reg = TOK_ASM_r0 + reg;
            ਰੋਕੋ;
        }
        cstr_printf(ਜੋੜੋ_str, "%s", get_tok_str(reg, ਨਿਰਾ));
    }
}

/* generate prolog and epilog code for asm statement */
ST_FUNC ਖਾਲੀ asm_gen_ਕੋਡ(ASMOperand *operands, ਪੂਰਨ nb_operands,
                          ਪੂਰਨ nb_outputs, ਪੂਰਨ is_output,
                          uint8_t *clobber_regs,
                          ਪੂਰਨ ਬਾਹਰਲਾ_reg)
{
    uint8_t regs_allocated[NB_ASM_REGS];
    ASMOperand *op;
    ਪੂਰਨ i, reg;
    uint32_t saved_regset = 0;

    // TODO: Check non-E ABI.
    // Note: Technically, r13 (sp) is also callee-saved--but that does not matter yet
    ਸਥਿਰ ਅਚਲ uint8_t reg_saved[] = { 4, 5, 6, 7, 8, 9 /* Note: sometimes special reg "sb" */ , 10, 11 };

    /* mark all used registers */
    ਸਮ੍ਰਿਤੀ_ਨਕਲ(regs_allocated, clobber_regs, ਆਕਾਰ(regs_allocated));
    ਲਈ(i = 0; i < nb_operands;i++) {
        op = &operands[i];
        ਜੇ (op->reg >= 0)
            regs_allocated[op->reg] = 1;
    }
    ਲਈ(i = 0; i < ਆਕਾਰ(reg_saved)/ਆਕਾਰ(reg_saved[0]); i++) {
        reg = reg_saved[i];
        ਜੇ (regs_allocated[reg])
            saved_regset |= 1 << reg;
    }

    ਜੇ (!is_output) { // prolog
        /* generate reg save code */
        ਜੇ (saved_regset)
            gen_le32(0xe92d0000 | saved_regset); // push {...}

        /* generate load code */
        ਲਈ(i = 0; i < nb_operands; i++) {
            op = &operands[i];
            ਜੇ (op->reg >= 0) {
                ਜੇ ((op->vt->r & VT_VALMASK) == VT_LLOCAL &&
                    op->is_ਸਮ੍ਰਿਤੀ) {
                    /* memory reference case (for both input and
                       output cases) */
                    SValue sv;
                    sv = *op->vt;
                    sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL | VT_LVAL;
                    sv.type.t = VT_PTR;
                    ਲੱਦੋ(op->reg, &sv);
                } ਨਹੀਂਤਾਂ ਜੇ (i >= nb_outputs || op->is_rw) { // not write-only
                    /* load value in register */
                    ਲੱਦੋ(op->reg, op->vt);
                    ਜੇ (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }
    } ਨਹੀਂਤਾਂ { // epilog
        /* generate save code */
        ਲਈ(i = 0 ; i < nb_outputs; i++) {
            op = &operands[i];
            ਜੇ (op->reg >= 0) {
                ਜੇ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    ਜੇ (!op->is_ਸਮ੍ਰਿਤੀ) {
                        SValue sv;
                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | VT_LOCAL;
                        sv.type.t = VT_PTR;
                        ਲੱਦੋ(ਬਾਹਰਲਾ_reg, &sv);

                        sv = *op->vt;
                        sv.r = (sv.r & ~VT_VALMASK) | ਬਾਹਰਲਾ_reg;
                        store(op->reg, &sv);
                    }
                } ਨਹੀਂਤਾਂ {
                    store(op->reg, op->vt);
                    ਜੇ (op->is_llong)
                        tcc_error("long long not implemented");
                }
            }
        }

        /* generate reg restore code */
        ਜੇ (saved_regset)
            gen_le32(0xe8bd0000 | saved_regset); // pop {...}
    }
}

/* return the constraint priority (we allocate first the lowest
   numbered constraints) */
ਸਥਿਰ ਸਤਰਅੰਦਰ ਪੂਰਨ constraint_ਤਰਜੀਹ(ਅਚਲ ਅੱਖਰ *str)
{
    ਪੂਰਨ ਤਰਜੀਹ, c, pr;

    /* we take the lowest priority */
    ਤਰਜੀਹ = 0;
    ਲਈ(;;) {
        c = *str;
        ਜੇ (c == '\0')
            ਰੋਕੋ;
        str++;
        ਚੋਣ(c) {
        ਹਾਲਤ 'l': // in ARM mode, that's  an alias for 'r' [ARM].
        ਹਾਲਤ 'r': // register [general]
        ਹਾਲਤ 'p': // valid memory address for load,store [general]
            pr = 3;
            ਰੋਕੋ;
        ਹਾਲਤ 'M': // integer constant for shifts [ARM]
        ਹਾਲਤ 'I': // integer valid for data processing instruction immediate
        ਹਾਲਤ 'J': // integer in range -4095...4095

        ਹਾਲਤ 'i': // immediate integer operand, including symbolic constants [general]
        ਹਾਲਤ 'm': // memory operand [general]
        ਹਾਲਤ 'g': // general-purpose-register, memory, immediate integer [general]
            pr = 4;
            ਰੋਕੋ;
        ਮੂਲ:
            tcc_error("unknown constraint '%c'", c);
        }
        ਜੇ (pr > ਤਰਜੀਹ)
            ਤਰਜੀਹ = pr;
    }
    ਵਾਪਸ ਤਰਜੀਹ;
}

ਸਥਿਰ ਅਚਲ ਅੱਖਰ *skip_constraint_modifiers(ਅਚਲ ਅੱਖਰ *p)
{
    /* Constraint modifier:
        =   Operand is written to by this instruction
        +   Operand is both read and written to by this instruction
        %   Instruction is commutative for this operand and the following operand.

       Per-alternative constraint modifier:
        &   Operand is clobbered before the instruction is done using the input operands
    */
    ਜਦੋਂ (*p == '=' || *p == '&' || *p == '+' || *p == '%')
        p++;
    ਵਾਪਸ p;
}

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_ਬਾਹਰਲਾ_ਨਕਾਬ 0x01
#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ REG_ਵਿੱਚ_ਨਕਾਬ  0x02

#ਪਰਿਭਾਸ਼ਿਤ_ਕਰੋ is_reg_allocated(reg) (regs_allocated[reg] & reg_ਨਕਾਬ)

ST_FUNC ਖਾਲੀ asm_compute_constraints(ASMOperand *operands,
                                    ਪੂਰਨ nb_operands, ਪੂਰਨ nb_outputs,
                                    ਅਚਲ uint8_t *clobber_regs,
                                    ਪੂਰਨ *pout_reg)
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
    ਪੂਰਨ sorted_op[MAX_ASM_OPERANDS];
    ਪੂਰਨ i, j, k, p1, p2, tmp, reg, c, reg_ਨਕਾਬ;
    ਅਚਲ ਅੱਖਰ *str;
    uint8_t regs_allocated[NB_ASM_REGS];

    /* init fields */
    ਲਈ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        op->ਨਿਵੇਸ਼_ਸੂਚਕਾਂਕ = -1;
        op->ref_ਸੂਚਕਾਂਕ = -1;
        op->reg = -1;
        op->is_ਸਮ੍ਰਿਤੀ = 0;
        op->is_rw = 0;
    }
    /* compute constraint priority and evaluate references to output
       constraints if input constraints */
    ਲਈ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        str = op->constraint;
        str = skip_constraint_modifiers(str);
        ਜੇ (isnum(*str) || *str == '[') {
            /* this is a reference to another constraint */
            k = ਲੱਭੋ_constraint(operands, nb_operands, str, ਨਿਰਾ);
            ਜੇ ((ਬਿਨਾਨਿਸ਼ਾਨੀ) k >= i || i < nb_outputs)
                tcc_error("invalid reference in constraint %d ('%s')",
                          i, str);
            op->ref_ਸੂਚਕਾਂਕ = k;
            ਜੇ (operands[k].ਨਿਵੇਸ਼_ਸੂਚਕਾਂਕ >= 0)
                tcc_error("cannot reference twice the same operand");
            operands[k].ਨਿਵੇਸ਼_ਸੂਚਕਾਂਕ = i;
            op->ਤਰਜੀਹ = 5;
        } ਨਹੀਂਤਾਂ ਜੇ ((op->vt->r & VT_VALMASK) == VT_LOCAL
                   && op->vt->sym
                   && (reg = op->vt->sym->r & VT_VALMASK) < VT_CONST) {
            op->ਤਰਜੀਹ = 1;
            op->reg = reg;
        } ਨਹੀਂਤਾਂ {
            op->ਤਰਜੀਹ = constraint_ਤਰਜੀਹ(str);
        }
    }

    /* sort operands according to their priority */
    ਲਈ (i = 0; i < nb_operands; i++)
        sorted_op[i] = i;
    ਲਈ (i = 0; i < nb_operands - 1; i++) {
        ਲਈ (j = i + 1; j < nb_operands; j++) {
            p1 = operands[sorted_op[i]].ਤਰਜੀਹ;
            p2 = operands[sorted_op[j]].ਤਰਜੀਹ;
            ਜੇ (p2 < p1) {
                tmp = sorted_op[i];
                sorted_op[i] = sorted_op[j];
                sorted_op[j] = tmp;
            }
        }
    }

    ਲਈ (i = 0; i < NB_ASM_REGS; i++) {
        ਜੇ (clobber_regs[i])
            regs_allocated[i] = REG_ਵਿੱਚ_ਨਕਾਬ | REG_ਬਾਹਰਲਾ_ਨਕਾਬ;
        ਨਹੀਂਤਾਂ
            regs_allocated[i] = 0;
    }
    /* sp cannot be used */
    regs_allocated[13] = REG_ਵਿੱਚ_ਨਕਾਬ | REG_ਬਾਹਰਲਾ_ਨਕਾਬ;
    /* fp cannot be used yet */
    regs_allocated[11] = REG_ਵਿੱਚ_ਨਕਾਬ | REG_ਬਾਹਰਲਾ_ਨਕਾਬ;

    /* allocate registers and generate corresponding asm moves */
    ਲਈ (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        str = op->constraint;
        /* no need to allocate references */
        ਜੇ (op->ref_ਸੂਚਕਾਂਕ >= 0)
            ਜਾਰੀ;
        /* select if register is used for output, input or both */
        ਜੇ (op->ਨਿਵੇਸ਼_ਸੂਚਕਾਂਕ >= 0) {
            reg_ਨਕਾਬ = REG_ਵਿੱਚ_ਨਕਾਬ | REG_ਬਾਹਰਲਾ_ਨਕਾਬ;
        } ਨਹੀਂਤਾਂ ਜੇ (j < nb_outputs) {
            reg_ਨਕਾਬ = REG_ਬਾਹਰਲਾ_ਨਕਾਬ;
        } ਨਹੀਂਤਾਂ {
            reg_ਨਕਾਬ = REG_ਵਿੱਚ_ਨਕਾਬ;
        }
        ਜੇ (op->reg >= 0) {
            ਜੇ (is_reg_allocated(op->reg))
                tcc_error
                    ("asm regvar requests register that's taken already");
            reg = op->reg;
        }
      try_ਅਗਲਾ:
        c = *str++;
        ਚੋਣ (c) {
        ਹਾਲਤ '=': // Operand is written-to
            ਜਾਓ try_ਅਗਲਾ;
        ਹਾਲਤ '+': // Operand is both READ and written-to
            op->is_rw = 1;
            /* FALL THRU */
        ਹਾਲਤ '&': // Operand is clobbered before the instruction is done using the input operands
            ਜੇ (j >= nb_outputs)
                tcc_error("'%c' modifier can only be applied to outputs",
                          c);
            reg_ਨਕਾਬ = REG_ਵਿੱਚ_ਨਕਾਬ | REG_ਬਾਹਰਲਾ_ਨਕਾਬ;
            ਜਾਓ try_ਅਗਲਾ;
        ਹਾਲਤ 'l': // In non-thumb mode, alias for 'r'--otherwise r0-r7 [ARM]
        ਹਾਲਤ 'r': // general-purpose register
        ਹਾਲਤ 'p': // loadable/storable address
            /* any general register */
            ਜੇ ((reg = op->reg) >= 0)
                ਜਾਓ reg_ਮਿਲਿਆ;
            ਨਹੀਂਤਾਂ ਲਈ (reg = 0; reg <= 8; reg++) {
                ਜੇ (!is_reg_allocated(reg))
                    ਜਾਓ reg_ਮਿਲਿਆ;
            }
            ਜਾਓ try_ਅਗਲਾ;
          reg_ਮਿਲਿਆ:
            /* now we can reload in the register */
            op->is_llong = 0;
            op->reg = reg;
            regs_allocated[reg] |= reg_ਨਕਾਬ;
            ਰੋਕੋ;
        ਹਾਲਤ 'I': // integer that is valid as an data processing instruction immediate (0...255, rotated by a multiple of two)
        ਹਾਲਤ 'J': // integer in the range -4095 to 4095 [ARM]
        ਹਾਲਤ 'K': // integer that satisfies constraint I when inverted (one's complement)
        ਹਾਲਤ 'L': // integer that satisfies constraint I when inverted (two's complement)
        ਹਾਲਤ 'i': // immediate integer operand, including symbolic constants
            ਜੇ (!((op->vt->r & (VT_VALMASK | VT_LVAL)) == VT_CONST))
                ਜਾਓ try_ਅਗਲਾ;
            ਰੋਕੋ;
        ਹਾਲਤ 'M': // integer in the range 0 to 32
            ਜੇ (!
                ((op->vt->r & (VT_VALMASK | VT_LVAL | VT_SYM)) ==
                 VT_CONST))
                ਜਾਓ try_ਅਗਲਾ;
            ਰੋਕੋ;
        ਹਾਲਤ 'm': // memory operand
        ਹਾਲਤ 'g':
            /* nothing special to do because the operand is already in
               memory, except if the pointer itself is stored in a
               memory variable (VT_LLOCAL case) */
            /* XXX: fix constant case */
            /* if it is a reference to a memory zone, it must lie
               in a register, so we reserve the register in the
               input registers and a load will be generated
               later */
            ਜੇ (j < nb_outputs || c == 'm') {
                ਜੇ ((op->vt->r & VT_VALMASK) == VT_LLOCAL) {
                    /* any general register */
                    ਲਈ (reg = 0; reg <= 8; reg++) {
                        ਜੇ (!(regs_allocated[reg] & REG_ਵਿੱਚ_ਨਕਾਬ))
                            ਜਾਓ reg_found1;
                    }
                    ਜਾਓ try_ਅਗਲਾ;
                  reg_found1:
                    /* now we can reload in the register */
                    regs_allocated[reg] |= REG_ਵਿੱਚ_ਨਕਾਬ;
                    op->reg = reg;
                    op->is_ਸਮ੍ਰਿਤੀ = 1;
                }
            }
            ਰੋਕੋ;
        ਮੂਲ:
            tcc_error("asm constraint %d ('%s') could not be satisfied",
                      j, op->constraint);
            ਰੋਕੋ;
        }
        /* if a reference is present for that operand, we assign it too */
        ਜੇ (op->ਨਿਵੇਸ਼_ਸੂਚਕਾਂਕ >= 0) {
            operands[op->ਨਿਵੇਸ਼_ਸੂਚਕਾਂਕ].reg = op->reg;
            operands[op->ਨਿਵੇਸ਼_ਸੂਚਕਾਂਕ].is_llong = op->is_llong;
        }
    }

    /* compute out_reg. It is used to store outputs registers to memory
       locations references by pointers (VT_LLOCAL case) */
    *pout_reg = -1;
    ਲਈ (i = 0; i < nb_operands; i++) {
        op = &operands[i];
        ਜੇ (op->reg >= 0 &&
            (op->vt->r & VT_VALMASK) == VT_LLOCAL && !op->is_ਸਮ੍ਰਿਤੀ) {
            ਲਈ (reg = 0; reg <= 8; reg++) {
                ਜੇ (!(regs_allocated[reg] & REG_ਬਾਹਰਲਾ_ਨਕਾਬ))
                    ਜਾਓ reg_found2;
            }
            tcc_error("could not find free output register for reloading");
          reg_found2:
            *pout_reg = reg;
            ਰੋਕੋ;
        }
    }

    /* print sorted constraints */
#ਜੇ_ਪਰਿਭਾਸ਼ਿਤ ASM_DEBUG
    ਲਈ (i = 0; i < nb_operands; i++) {
        j = sorted_op[i];
        op = &operands[j];
        ਲਿਖੋ("%%%d [%s]: \"%s\" r=0x%04x reg=%d\n",
               j,
               op->id ? get_tok_str(op->id, ਨਿਰਾ) : "",
               op->constraint, op->vt->r, op->reg);
    }
    ਜੇ (*pout_reg >= 0)
        ਲਿਖੋ("out_reg=%d\n", *pout_reg);
#ਜੇ_ਅੰਤ
}

ST_FUNC ਖਾਲੀ asm_clobber(uint8_t *clobber_regs, ਅਚਲ ਅੱਖਰ *str)
{
    ਪੂਰਨ reg;
    TokenSym *ts;

    ਜੇ (!strcmp(str, "memory") ||
        !strcmp(str, "cc") ||
        !strcmp(str, "flags"))
        ਵਾਪਸ;
    ts = tok_alloc(str, ਲੜੀ_ਲੰਬਾਈ(str));
    reg = asm_parse_regvar(ts->tok);
    ਜੇ (reg == -1) {
        tcc_error("invalid clobber register '%s'", str);
    }
    clobber_regs[reg] = 1;
}

/* If T refers to a register then return the register number and type.
   Otherwise return -1.  */
ST_FUNC ਪੂਰਨ asm_parse_regvar (ਪੂਰਨ t)
{
    /* coprocessors (p0-p15) and coprocessor registers (c0-c15) are handled elsewere */
    /* single fp (s0-s31) and double fp registers (d0-d15) are handled elsewere */

    ਜੇ (t < TOK_ASM_r0 || t > TOK_ASM_pc) /* filter unrelated registers */
        ਵਾਪਸ -1;

    ਜੇ (t <= TOK_ASM_r15)       /* default register names r0-r15 */
        ਵਾਪਸ t - TOK_ASM_r0;

    ਜੇ (t <= TOK_ASM_v8)        /* synonym register names a1-a4,v1-v8 (alias: r0-r11) */
        ਵਾਪਸ t - TOK_ASM_a1;

    /* special register names sb/sl/fp/ip/sp/lr/pc (alias: r9-r15) */
    ਵਾਪਸ t - TOK_ASM_sb + (TOK_ASM_r9 - TOK_ASM_r0);
}

/*************************************************************/
#ਜੇ_ਅੰਤ /* ndef TARGET_DEFS_ONLY */

/* -*- mode: c++ -*-
 * Kaleidoscope-CharShift -- Independently assign shifted and unshifted symbols
 * Name keyed macros for the CharShift plugin
 * Copyright (C) 2022 Lilith Daemon
 *
 * This program is free software: you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#include "kaleidoscope/plugin/CharShift.h"

// get number of arguments with __NCS_NARG__
#define __NCS_NARG__(...)  __NCS_NARG_I_(__VA_ARGS__,__NCS_RSEQ_N())
#define __NCS_NARG_I_(...) __NCS_ARG_N(__VA_ARGS__)
#define __NCS_ARG_N( \
      _1, _2, _3, _4, _5, _6, _7, _8, _9,_10, \
     _11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
     _21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
     _31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
     _41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
     _51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
     _61,_62,_63,_64,N,...) N
#define __NCS_RSEQ_N() \
     64,63,62,61,60,                \
     59,58,57,56,55,54,53,52,51,50, \
     49,48,47,46,45,44,43,42,41,40, \
     39,38,37,36,35,34,33,32,31,30, \
     29,28,27,26,25,24,23,22,21,20, \
     19,18,17,16,15,14,13,12,11,10, \
     9,8,7,6,5,4,3,2,1,0

// general definition for any function name
#define _NCS_VFUNC_(name, n) name##n
#define _NCS_VFUNC(name, n) _NCS_VFUNC_(name, n)
#define NCS_VFUNC(func, p1, ...) _NCS_VFUNC(func, __NCS_NARG__(__VA_ARGS__)) (p1, __VA_ARGS__)

#define NCS_FOR_EACH(f, ...) NCS_VFUNC(NCS_FOR_EACH, f, __VA_ARGS__)

#define NCS_KEYS___YOU_ARE_MISSING_A_COMMA()

#define NCS_KEYS_INVALID_FORMAT_FUNCTION_WRAPPER(f,p) f p

#define NCS_KEYS___INVALID_FORMAT_CHECK(f, t) NCS_KEYS_INVALID_FORMAT_FUNCTION_WRAPPER(f, NCS_KEYS___INVALID_FORMAT_EXTRA_COMMA t ())
// #define NCS_KEYS___INVALID_FORMAT_CHECK(f, t) f NCS_KEYS___INVALID_TUPLE_FORMAT___NEEDS_3_VALUES___NOT_ENOUGH t ()
#define NCS_KEYS___INVALID_FORMAT_MISSING_COMMA(t, ...) NCS_KEYS___INVALID_TUPLE_FORMAT___NEEDS_3_VALUES___TOO_MANY (t) NCS_KEYS___YOU_ARE_MISSING_A_COMMA __VA_ARGS__
#define NCS_KEYS___INVALID_TUPLE_FORMAT___NEEDS_3_VALUES___NOT_ENOUGH(n,u,s, ...) (n, u, s) NCS_KEYS___INVALID_FORMAT_MISSING_COMMA (__VA_ARGS__)
#define NCS_KEYS___INVALID_TUPLE_FORMAT___NEEDS_3_VALUES___TOO_MANY()

#define NCS_KEYS___INVALID_FORMAT_EXTRA_COMMA(t1, t2, ...) \
  NCS_KEYS___INVALID_TUPLE_FORMAT___NEEDS_3_VALUES___NOT_ENOUGH(t1, t2, ##__VA_ARGS__)

#define  NCS_FOR_EACH1(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t)
#define  NCS_FOR_EACH2(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t),  NCS_FOR_EACH1(f, __VA_ARGS__)
#define  NCS_FOR_EACH3(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t),  NCS_FOR_EACH2(f, __VA_ARGS__)
#define  NCS_FOR_EACH4(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t),  NCS_FOR_EACH3(f, __VA_ARGS__)
#define  NCS_FOR_EACH5(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t),  NCS_FOR_EACH4(f, __VA_ARGS__)
#define  NCS_FOR_EACH6(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t),  NCS_FOR_EACH5(f, __VA_ARGS__)
#define  NCS_FOR_EACH7(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t),  NCS_FOR_EACH6(f, __VA_ARGS__)
#define  NCS_FOR_EACH8(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t),  NCS_FOR_EACH7(f, __VA_ARGS__)
#define  NCS_FOR_EACH9(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t),  NCS_FOR_EACH8(f, __VA_ARGS__)
#define NCS_FOR_EACH10(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t),  NCS_FOR_EACH9(f, __VA_ARGS__)
#define NCS_FOR_EACH11(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH10(f, __VA_ARGS__)
#define NCS_FOR_EACH12(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH11(f, __VA_ARGS__)
#define NCS_FOR_EACH13(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH12(f, __VA_ARGS__)
#define NCS_FOR_EACH14(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH13(f, __VA_ARGS__)
#define NCS_FOR_EACH15(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH14(f, __VA_ARGS__)
#define NCS_FOR_EACH16(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH15(f, __VA_ARGS__)
#define NCS_FOR_EACH17(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH16(f, __VA_ARGS__)
#define NCS_FOR_EACH18(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH17(f, __VA_ARGS__)
#define NCS_FOR_EACH19(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH18(f, __VA_ARGS__)
#define NCS_FOR_EACH20(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH19(f, __VA_ARGS__)
#define NCS_FOR_EACH21(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH20(f, __VA_ARGS__)
#define NCS_FOR_EACH22(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH21(f, __VA_ARGS__)
#define NCS_FOR_EACH23(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH22(f, __VA_ARGS__)
#define NCS_FOR_EACH24(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH23(f, __VA_ARGS__)
#define NCS_FOR_EACH25(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH24(f, __VA_ARGS__)
#define NCS_FOR_EACH26(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH25(f, __VA_ARGS__)
#define NCS_FOR_EACH27(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH26(f, __VA_ARGS__)
#define NCS_FOR_EACH28(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH27(f, __VA_ARGS__)
#define NCS_FOR_EACH29(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH28(f, __VA_ARGS__)
#define NCS_FOR_EACH30(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH29(f, __VA_ARGS__)
#define NCS_FOR_EACH31(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH30(f, __VA_ARGS__)
#define NCS_FOR_EACH32(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH31(f, __VA_ARGS__)
#define NCS_FOR_EACH33(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH32(f, __VA_ARGS__)
#define NCS_FOR_EACH34(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH33(f, __VA_ARGS__)
#define NCS_FOR_EACH35(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH34(f, __VA_ARGS__)
#define NCS_FOR_EACH36(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH35(f, __VA_ARGS__)
#define NCS_FOR_EACH37(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH36(f, __VA_ARGS__)
#define NCS_FOR_EACH38(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH37(f, __VA_ARGS__)
#define NCS_FOR_EACH39(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH38(f, __VA_ARGS__)
#define NCS_FOR_EACH40(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH39(f, __VA_ARGS__)
#define NCS_FOR_EACH41(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH40(f, __VA_ARGS__)
#define NCS_FOR_EACH42(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH41(f, __VA_ARGS__)
#define NCS_FOR_EACH43(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH42(f, __VA_ARGS__)
#define NCS_FOR_EACH44(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH43(f, __VA_ARGS__)
#define NCS_FOR_EACH45(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH44(f, __VA_ARGS__)
#define NCS_FOR_EACH46(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH45(f, __VA_ARGS__)
#define NCS_FOR_EACH47(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH46(f, __VA_ARGS__)
#define NCS_FOR_EACH48(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH47(f, __VA_ARGS__)
#define NCS_FOR_EACH49(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH48(f, __VA_ARGS__)
#define NCS_FOR_EACH50(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH49(f, __VA_ARGS__)
#define NCS_FOR_EACH51(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH50(f, __VA_ARGS__)
#define NCS_FOR_EACH52(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH51(f, __VA_ARGS__)
#define NCS_FOR_EACH53(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH52(f, __VA_ARGS__)
#define NCS_FOR_EACH54(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH53(f, __VA_ARGS__)
#define NCS_FOR_EACH55(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH54(f, __VA_ARGS__)
#define NCS_FOR_EACH56(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH55(f, __VA_ARGS__)
#define NCS_FOR_EACH57(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH56(f, __VA_ARGS__)
#define NCS_FOR_EACH58(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH57(f, __VA_ARGS__)
#define NCS_FOR_EACH59(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH58(f, __VA_ARGS__)
#define NCS_FOR_EACH60(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH59(f, __VA_ARGS__)
#define NCS_FOR_EACH61(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH60(f, __VA_ARGS__)
#define NCS_FOR_EACH62(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH61(f, __VA_ARGS__)
#define NCS_FOR_EACH63(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH62(f, __VA_ARGS__)
#define NCS_FOR_EACH64(f, t, ...) NCS_KEYS___INVALID_FORMAT_CHECK(f, t), NCS_FOR_EACH63(f, __VA_ARGS__)

#define NCS_KEYS___GET_TUPLE_NAME(n,u,s) n

#define NCS_KEYS___GET_KEYPAIR(n,u,s) NCS_KEYS___GENERATE_KEY_PAIR(u,s)

constexpr kaleidoscope::plugins::CharShift::KeyPair NCS_KEYS___GENERATE_KEY_PAIR(const kaleidoscope::Key unshift, const kaleidoscope::Key shift) {
  return kaleidoscope::plugins::CharShift::KeyPair(unshift, shift);
}

#define NCS_KEYS(...)                                                                       \
namespace NCS_KEYS{                                                                         \
void NCS_KEYS() {                                                                           \
  static kaleidoscope::plugins::CharShift::KeyPair const kp_table[] PROGMEM = {             \
    NCS_FOR_EACH(NCS_KEYS___GET_KEYPAIR, __VA_ARGS__)                                       \
  };                                                                                        \
  CharShift.setProgmemKeyPairs(kp_table);                                                   \
}                                                                                           \
enum class KEY_ID : uint8_t {                                                               \
  NCS_FOR_EACH(NCS_KEYS___GET_TUPLE_NAME, __VA_ARGS__)                                      \
};                                                                                          \
}

#define NCS(name)                                                                           \
  NCS_RESOLVE_KEY_CODE(NCS_KEYS::KEY_ID::name)

constexpr kaleidoscope::Key NCS_RESOLVE_KEY_CODE(NCS_KEYS::KEY_ID key_id) {
  return kaleidoscope::Key(kaleidoscope::ranges::CS_FIRST + (uint8_t)key_id);
}

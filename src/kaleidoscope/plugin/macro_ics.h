/* -*- mode: c++ -*-
 * Kaleidoscope-CharShift -- Independently assign shifted and unshifted symbols
 * Index keyed macros for the CharShift plugin
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

constexpr kaleidoscope::plugins::CharShift::KeyPair ICS_KEYS___GENERATE_KEY_PAIR(const kaleidoscope::Key unshift, const kaleidoscope::Key shift) {
  return kaleidoscope::plugins::CharShift::KeyPair(unshift, shift);
}

#define ICS_KEY_PAIR(unshift, shift)\
  ICS_KEYS___GENERATE_KEY_PAIR(unshift, shift)

#define ICS_KEYS(...)                                                                       \
void ICS_KEYS::ICS_KEYS() {                                                                 \
  static kaleidoscope::plugins::CharShift::KeyPair const kp_table[] PROGMEM = {             \
    __VA_ARGS__                                                                             \
  };                                                                                        \
  CharShift.setProgmemKeyPairs(kp_table);                                                   \
}

#define ICS(index) ICS_RESOLVE_KEY_CODE(index)

constexpr kaleidoscope::Key ICS_RESOLVE_KEY_CODE(uint8_t index) {
  return kaleidoscope::Key(kaleidoscope::ranges::CS_FIRST + index);
}

/* Kaleidoscope - Firmware for computer input devices
 * Copyright (C) 2022  kaleidoscope Daemon
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

#include <Kaleidoscope-Ranges.h>  // for CS_FIRST
#include <stdint.h>               // for uint8_t

#include "Arduino.h"                            // for PROGMEM
#include "kaleidoscope/KeyEvent.h"              // for KeyEvent
#include "kaleidoscope/event_handler_result.h"  // for EventHandlerResult
#include "kaleidoscope/key_defs.h"              // for Key
#include "kaleidoscope/plugin.h"                // for Plugin
#include "kaleidoscope/macro_map.h"

namespace lilith_gen_named_char_shift{
enum class KEY_ID : uint8_t;
void setup();
}

namespace kaleidoscope {
namespace plugins {

class NamedCharShift : public Plugin {

 public:
  EventHandlerResult onSetup();
  EventHandlerResult onNameQuery();
  EventHandlerResult onKeyEvent(KeyEvent &event);
  EventHandlerResult beforeReportingState(const KeyEvent &event);

  // ---------------------------------------------------------------------------
  /// A structure that stores CharShift key pair values
  ///
  /// This structure stores two separate `Key` values: `lower` (to be used when
  /// a key is pressed without `shift` held), and `upper` (to be used when
  /// `shift` is held).
  struct KeyPair {
    Key lower;
    Key upper;

    /// Constructor for use in PROGMEM
    ///
    /// This constructor is used when defining an array of `KeyPair` objects in
    /// PROGMEM (though it can also be used elsewhere).
    constexpr KeyPair(Key lower, Key upper)
      : lower(lower), upper(upper) {}

    /// Constructor for reading from PROGMEM
    ///
    /// This constructor is used by the helper function that copies values from
    /// PROGMEM so that they can be used normally.
    KeyPair() = default;
  };

  /// Configure the KeyPairs array in PROGMEM
  ///
  /// This function configures the PROGMEM array of `KeyPair` objects,
  /// automatically setting the internal count variable from the size of the
  /// `keypairs` array given, which must be a fixed-sized array, not a pointer.
  /// Generally, it will be called via the `KEYPAIRS()` preprocessor macro, not
  /// directly by user code.
  template<uint8_t _num_keypairs>
  void setProgmemKeyPairs(KeyPair const (&keypairs)[_num_keypairs]) {
    progmem_keypairs_ = keypairs;
    num_keypairs_     = _num_keypairs;
  }

 private:
  // A pointer to an array of `KeyPair` objects in PROGMEM
  KeyPair const *progmem_keypairs_ = nullptr;
  // The size of the PROGMEM array of `KeyPair` objects
  uint8_t num_keypairs_ = 0;

  // If a `shift` key needs to be suppressed in `beforeReportingState()`
  bool reverse_shift_state_ = false;

  /// Test for keys that should be handled by CharShift
  bool isCharShiftKey(Key key);

  /// Look up the `KeyPair` specified by the given keymap entry
  KeyPair decodeCharShiftKey(Key key);

  /// Get the total number of KeyPairs defined
  ///
  /// This function can be overridden in order to store the `KeyPair` array in
  /// EEPROM instead of PROGMEM.
  uint8_t numKeyPairs();

  /// Get the `KeyPair` at the specified index from the defined `KeyPair` array
  ///
  /// This function can be overridden in order to store the `KeyPair` array in
  /// EEPROM instead of PROGMEM.
  KeyPair readKeyPair(uint8_t n);

  // Default for `keypairsCount()`: size of the PROGMEM array
  uint8_t numProgmemKeyPairs();
  // Default for `readKeypair(i)`: fetch the value from PROGMEM
  KeyPair readKeyPairFromProgmem(uint8_t n);
};


} // namespace kaleidoscope
} // namespace plugins

extern kaleidoscope::plugins::NamedCharShift NamedCharShift;

#define MAP_TUPLES0(f, x, peek, ...) f x MAP_NEXT(peek, MAP_TUPLES1)(f, peek, __VA_ARGS__)
#define MAP_TUPLES1(f, x, peek, ...) f x MAP_NEXT(peek, MAP_TUPLES0)(f, peek, __VA_ARGS__)
#define MAP_TUPLES(f, ...) EVAL(MAP_TUPLES1(f, __VA_ARGS__, ()()(), ()()(), ()()(), 0))

#define NCS_ENUM_ENTRY(name,unshift,shift)                                                  \
  name,

#define NCS_KEY_CODE_ENTRY(name,unshift,shift)                                              \
  kaleidoscope::plugins::NamedCharShift::KeyPair(unshift, shift),

#define NCS_KEYS(...)                                                                       \
namespace lilith_gen_named_char_shift{                                                      \
enum class KEY_ID : uint8_t {                                                               \
  MAP_TUPLES(NCS_ENUM_ENTRY, __VA_ARGS__)                                                   \
};                                                                                          \
void setup() {                                                                              \
  static kaleidoscope::plugins::NamedCharShift::KeyPair const kp_table[] PROGMEM = {        \
    MAP_TUPLES(NCS_KEY_CODE_ENTRY, __VA_ARGS__)                                             \
  };                                                                                        \
  NamedCharShift.setProgmemKeyPairs(kp_table);                                              \
}                                                                                           \
} /* namespace lilith_gen_named_char_shift */

#define NCS(name)                                                                           \
  NCS_RESOLVE_KEY_CODE((uint8_t)lilith_gen_named_char_shift::KEY_ID::name)

/// Define an `KeyPair` entry in a keymap
///
/// This defines a `Key` object that will be handled by the CharShift plugin.
/// The argument `n` is the index number of the `KeyPair` in the array (starting
/// at zero).
constexpr kaleidoscope::Key NCS_RESOLVE_KEY_CODE(uint8_t n) {
  return kaleidoscope::Key(kaleidoscope::ranges::CS_FIRST + n);
}

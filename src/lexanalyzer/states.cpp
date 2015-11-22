#include "states.h"
#include <algorithm>

/*std::map<uint8_t, std::map<Symbol, uint8_t> MiniGPortugol::States::states = {
    { 0,    { NUMBER, 1                  },
            { APOSTROPHE, 4              },
            { D_SLASH, 7                 },
            { LETTER, 9                  },
            { UNDERSCORE, 9              },
            { EQUAL, 10                  },
            { LESS_THAN, 11              },
            { GREATER_THAN, 14           },
            { MATH_OP, 16                },
            { COLON, 17                  } },
    { 1,    { NUMBER, 1                  },
            { DOT, 2                     } },
    { 4,    { CHARACTER, 5               } },
    { 7,    { ANYTHING_EXCPT_B_LINE, 7   },
            { BREAK_LINE, 8              } },
    { 9,    { LETTER, 9                  },
            { NUMBER, 9                  },
            { UNDERSCORE, 9              } },
    { 11,   { GREATER_THAN, 12           },
            { EQUAL, 13                  } },
    { 14,   { EQUAL, 15                  } },
    { 17,   { EQUAL, 18                  } },
    { 2,    { NUMBER, 3                  } },
    { 5,    { APOSTROPHE, 6              } },
    { 3,    { NUMBER, 3                  } }
  };
*/

MiniGPortugol::States::States() {
  createMap();
  std::sort(recognize_states.begin(), recognize_states.end(),
   [](const uint8_t &a, const uint8_t &b) -> bool { return a < b; });
}

MiniGPortugol::States::~States() {

}

void MiniGPortugol::States::createMap() {
  states[0] = { { OPEN_PARENT, 0             },
                { NUMBER, 1                  },
                { APOSTROPHE, 4              },
                { D_SLASH, 7                 },
                { LETTER, 9                  },
                { UNDERSCORE, 9              },
                { EQUAL, 10                  },
                { COMMA, 10                  },
                { LESS_THAN, 11              },
                { GREATER_THAN, 14           },
                { MATH_OP, 16                },
                { COLON, 17                  },
                { CLOSE_PARENT, 19           } };
 states[1] = {  { NUMBER, 1                  },
                { DOT, 2                     } };
 states[4] = {  { CHARACTER, 5               } };
 states[7] = {  { ANYTHING_EXCPT_B_LINE, 7   },
                { BREAK_LINE, 8              } };
 states[9] = {  { LETTER, 9                  },
                { NUMBER, 9                  },
                { UNDERSCORE, 9              } };
 states[11] = { { GREATER_THAN, 12           },
                { EQUAL, 13                  } };
 states[14] = { { EQUAL, 15                  } };
 states[17] = { { EQUAL, 18                  } };
 states[2]  = { { NUMBER, 3                  } };
 states[5]  = { { APOSTROPHE, 6              } };
 states[3]  = { { NUMBER, 3                  } };
}

/*
 * Return types
 * -1 : Actual state not exist
 * -2 : Not recognized
 */
uint8_t MiniGPortugol::States::nextState(const uint8_t actual_state, Symbol symbol) {
  if (states.find(actual_state) != states.end()) {
    auto &inner = states[actual_state];
    if (inner.find(symbol) != inner.end()) {
      return inner[symbol];
    } else {
      return -2;
    }
  }
  return -1;
}

bool MiniGPortugol::States::isRecognizeState(const uint8_t state) {
  return std::binary_search(recognize_states.begin(), recognize_states.end(),
   state);
}

#ifndef __STATES_H__
#define __STATES_H__

#include <map>
#include <vector>
#include <cstdint>

typedef enum { NUMBER = 0, DOT, APOSTROPHE, D_SLASH,
  ANYTHING_EXCPT_B_LINE, BREAK_LINE,  LETTER, UNDERSCORE, EQUAL, LESS_THAN,
  GREATER_THAN, MATH_OP, COLON, COMMA, OPEN_PARENT, CLOSE_PARENT,
  SEMICOLON, UNIDENTIFIED} Symbol;

namespace MiniGPortugol {
  class States {
  private:
    std::map<uint8_t, std::map<Symbol, uint8_t>> states;
    std::vector<uint8_t> recognize_states = { 1, 3, 6, 8, 9, 10, 11, 12, 13,
      14, 15, 16, 17, 18, 19, 20 };
    void createMap();
  public:
    States();
    ~States();
    uint8_t nextState(const uint8_t, const Symbol);
    bool isRecognizeState(const uint8_t);
  };
}


#endif // __STATES_H__

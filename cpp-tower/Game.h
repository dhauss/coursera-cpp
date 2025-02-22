/**
 * C++ class for a game of the Tower of Hanoi puzzle.
 *
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#pragma once

#include "Stack.h"
#include <vector>

class Game
{
public:
  Game();
  void solve();
  void _legalmove(unsigned i1, unsigned i2);

  // An overloaded operator<<, allowing us to print the stack via `cout<<`:
  friend std::ostream &operator<<(std::ostream &os, const Game &game);

private:
  std::vector<Stack> stacks_;
};

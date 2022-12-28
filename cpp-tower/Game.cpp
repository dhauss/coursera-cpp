/**
 * C++ class for a game of the Tower of Hanoi puzzle.
 *
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include "Game.h"
#include "Stack.h"
#include "uiuc/Cube.h"
#include "uiuc/HSLAPixel.h"

#include <iostream>
using std::cout;
using std::endl;

// Solves the Tower of Hanoi puzzle.
// (Feel free to call "helper functions" to help you solve the puzzle.)
void Game::_legalmove(unsigned i1, unsigned i2)
{
  if (stacks_[i1].size() == 0 && stacks_[i2].size() > 0)
  {
    Cube c = stacks_[i2].removeTop();
    stacks_[i1].push_back(c);
  }
  else if (stacks_[i1].size() > 0 && stacks_[i2].size() == 0)
  {
    Cube c = stacks_[i1].removeTop();
    stacks_[i2].push_back(c);
  }
  else if (stacks_[i1].size() > 0 && stacks_[i2].size() > 0)
  {
    if (stacks_[i1].peekTop().getLength() > stacks_[i2].peekTop().getLength())
    {
      Cube c = stacks_[i2].removeTop();
      stacks_[i1].push_back(c);
    }
    else
    {
      Cube c = stacks_[i1].removeTop();
      stacks_[i2].push_back(c);
    }
  }
  std::cout << *this << std::endl;
}

void Game::solve()
{
  while (stacks_[2].size() < 4)
  {
    _legalmove(0, 1);
    _legalmove(0, 2);
    _legalmove(1, 2);
  }
}

// Default constructor to create the initial state:
Game::Game()
{
  // Create the three empty stacks:
  for (int i = 0; i < 3; i++)
  {
    Stack stackOfCubes;
    stacks_.push_back(stackOfCubes);
  }

  // Create the four cubes, placing each on the [0]th stack:
  Cube blue(4, uiuc::HSLAPixel::BLUE);
  stacks_[0].push_back(blue);

  Cube orange(3, uiuc::HSLAPixel::ORANGE);
  stacks_[0].push_back(orange);

  Cube purple(2, uiuc::HSLAPixel::PURPLE);
  stacks_[0].push_back(purple);

  Cube yellow(1, uiuc::HSLAPixel::YELLOW);
  stacks_[0].push_back(yellow);
}

std::ostream &operator<<(std::ostream &os, const Game &game)
{
  for (unsigned i = 0; i < game.stacks_.size(); i++)
  {
    os << "Stack[" << i << "]: " << game.stacks_[i];
  }
  return os;
}

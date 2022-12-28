/**
 * Simple C++ making use of std::cout and a `Cube` class.
 *
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include <iostream>
#include "Cube.h"

using std::cout;
using std::endl;

int main()
{
  uiuc::Cube c;
  c.setLength(2.4);
  cout << "Volume: " << c.getVolume() << endl;

  double surfaceArea = c.getSurfaceArea();
  cout << "Surface Area: " << surfaceArea << endl;

  return 0;
}

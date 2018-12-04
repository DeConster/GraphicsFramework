#include <iostream>
#include "GraphicsRenderer.h"

int main()
{
  GraphicsRenderer mRenderer;

  try
  {
    mRenderer.run();
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
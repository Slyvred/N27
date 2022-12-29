#include <iostream>
#include <string>
#include "socket.hpp"
#include "../classes/json.hpp"

int main() 
{
  auto server = Server();
  server.listen(8080);
  server.run();

  return EXIT_SUCCESS;
}

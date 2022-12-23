#include <iostream>
#include <string>
#include "socket.hpp"
#include "../classes/json.hpp"

int main() {

  // Server server("1234");
  // server.Accept();
  // server.Run();
  auto server = Server();
  server.listen(8080);
  server.run();


  return 0;
}

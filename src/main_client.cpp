#include "../include/client_application.hpp"

int main()
{
    app::ClientApplication::GetInstance("127.0.0.1", 8080)->Run();
    return 0;
}
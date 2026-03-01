#include "../include/server_application.hpp"

int main()
{
    app::ServerApplication::GetInstance(8080)->Run();
}
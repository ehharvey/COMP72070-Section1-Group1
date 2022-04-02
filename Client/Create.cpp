#include "../Communication/Create.h"
#include "Create.h"

std::unique_ptr<Client::Client> Create::Client()
{
    return std::make_unique<Client::Client>(Client::Client());
}
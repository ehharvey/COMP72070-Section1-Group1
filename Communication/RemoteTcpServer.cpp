#pragma once
#include "RemoteTcpServer.h"

Communicators::rPtr Communicators::RemoteTcpServer::getSendFunction()
{
	return rPtr();
}
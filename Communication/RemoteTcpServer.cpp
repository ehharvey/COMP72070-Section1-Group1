#pragma once
#include "RemoteTcpServer.h"

Communicators::rPtr Communicators::RemoteTcpServer::getSendFunction() const
{
	return rPtr();
}
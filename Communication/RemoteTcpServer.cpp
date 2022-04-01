#pragma once
#include "RemoteTcpServer.h"

Communicators::RemoteTcpServer::RemoteTcpServer(Data::IPV4Address address)
: address(address)
{
	
}

Communicators::rPtr Communicators::RemoteTcpServer::getSendFunction() const
{
	return rPtr();
}
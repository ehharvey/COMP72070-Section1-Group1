#pragma once
#include <memory>
#include "IPV4Address.h"
#include "IRemoteResponder.h"
#include "ISender.h"

namespace Communicators
{
    class TcpClient : public ISender
	{
		Data::IPV4Address address;
		std::unique_ptr<IRemoteResponder> remote;

	public:
		TcpClient(Data::IPV4Address address, std::unique_ptr<IRemoteResponder> remote) :
			address(address),
			remote(std::move(remote))
		{ }

		const std::vector<uint8_t> Send(const std::vector<uint8_t> message);
	};
} // namespace Communicators

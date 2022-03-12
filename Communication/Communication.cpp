#include "Communication.h"
#include <exception>

Communication::Data::Data(uint8_t * payload, size_t size) {
	this->payload = (uint8_t*)malloc(size);

	if (this->payload == NULL) {
		throw std::bad_alloc();
	}
	else {
		memcpy(this->payload, payload, size);
		this->size = size;
	}
}

const uint8_t* Communication::Data::getPayload()
{
	return this->payload;
}

size_t Communication::Data::getSize()
{
	return this->size;
}

Communication::Data::~Data() {
	if (this->payload != NULL) {
		free(this->payload);
	}
}

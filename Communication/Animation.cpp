#pragma once
#include "Animation.h"

Data::Animation::Animation()
{
	this->item = 5;
}

Data::Animation::Animation(Data::IContainer Serialization)
{
	Serialization.pop_back();
}

Data::IContainer Data::Animation::Serialize() const
{
	return Data::IContainer({ this->item });
}

std::unique_ptr<Data::Animation> 
Data::Animation::New()
{
	return std::make_unique<Animation>(Animation());
}

std::unique_ptr<Data::Animation> Data::Animation::Deserialize(Data::IContainer Serialization)
{
	return std::make_unique<Animation>(Animation());
}

#include "ErrorSerialization.h"


Data::ErrorSerialization::ErrorSerialization()
{

}

std::unique_ptr<Data::ErrorSerialization>
Data::ErrorSerialization::New(Data::IContainer Serialization)
{
    return std::make_unique<ErrorSerialization>(ErrorSerialization());
}

Data::IContainer
Data::ErrorSerialization::Serialize() const
{
    return Data::IContainer({1});
}
#include "TypeConstructor.h"
#include <chrono>
#include <thread>
#include <mutex>

Data::TypeConstructor::TypeConstructor(std::vector<ISerializableConstructor> constructors)
:   constructors(constructors)
{ }

std::shared_ptr<Data::TypeConstructor>  // Return type
Data::TypeConstructor::New              // Function name
(std::vector<ISerializableConstructor> constructors) // Parameters
{
    static std::mutex new_mutex;

    // Attempt to initialize and/or return __singleton
    for(auto attempt_count = 0; attempt_count < 5; attempt_count++)
    {
        if (new_mutex.try_lock())
        {
            if (__singleton)
            {
                // This locking isn't strictly if __singleton is initialized
                // but it shouldn't cause issue under expected usage
                // There would be an error when there are lots of threads
                new_mutex.unlock();
                return __singleton;
            }
            else
            {
                __singleton = std::make_shared<TypeConstructor>(TypeConstructor(constructors));
                new_mutex.unlock();
                return __singleton;
            }
        }

        std::this_thread::sleep_for(std::chrono::seconds(1)); // If blocked, wait for 1 second
    }

    return nullptr; // Unable to acquire lock
}

Data::ISerializableConstructor
Data::TypeConstructor::getConstructor
(uint8_t type_identifier)
{
    return this->constructors[type_identifier];
}

uint8_t
Data::TypeConstructor::getTypeIdentifier
(const std::type_info& type_info)
{
    return type_identifier_map[(std::type_index(type_info))];
}

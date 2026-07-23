#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& copy)
{
    (void)copy;
}

Serializer& Serializer::operator=(const Serializer& rhs)
{
    if(this != &rhs)
        (void)rhs;
    return *this;
}

Serializer::~Serializer() { }

/* 

A pointer can be represented as another type
it changes only the type, not the underlying memory address
ptr ----> integer

inteter ----> ptr

*/
uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data*>(raw);
}
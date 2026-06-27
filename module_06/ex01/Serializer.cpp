#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t num = reinterpret_cast<uintptr_t>(ptr);
	return num;
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* ptr2 = reinterpret_cast<Data*>(raw);
	return ptr2;
}
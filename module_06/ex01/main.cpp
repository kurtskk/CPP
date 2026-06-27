#include "Serializer.hpp"

int main(void)
{
	Data d;
	d.name = "Robert";
	d.lastname = "Silva";
	d.age = 20;

	Data* adressmemory = &d;
	uintptr_t num = Serializer::serialize(adressmemory);
	Data* ptr = Serializer::deserialize(num);
	if (adressmemory == ptr)
	{
		std::cout << "equal pointers" << std::endl;
		std::cout << ptr->name << std::endl;
		std::cout << ptr->lastname << std::endl;
		std::cout << ptr->age << std::endl;
	}
}
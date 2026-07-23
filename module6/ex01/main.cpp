#include "Serializer.hpp"

int main()
{
    Data student;
    
    student.id = 42;
    student.name = "Enes";

    Data* original = &student;

    uintptr_t raw = Serializer::serialize(original);

    Data* restored = Serializer::deserialize(raw);

    std::cout << "Original pointer: " << original << std::endl;
    std::cout << "Serialized value: " << raw << std::endl;
    std::cout << "Restored pointer: " << restored << std::endl;


    std::cout << "-----------------------------" << std::endl;

    std::cout << "ID: " << restored->id << std::endl;
    std::cout << "Name: " << restored->name << std::endl;

    if(original == restored)
        std::cout << "Pointers are identical." << std::endl;
    else
        std::cout << "Pointers are different." << std::endl;
        
    /*
    we proved that serializing and deseralizing a pointer
    using @reinterpret_cast does not change the pointer
    It stills refers to the same object in memeory.
    */
    return 0;
}
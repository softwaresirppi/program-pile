#include "../potions/hashable.hpp"

#include <string>

std::string Hashable::getRawClassData() {
    int objectSize = sizeof * this; // in bytes
    std::string rawClassData;
    rawClassData.reserve(objectSize);
    for (size_t i = 0; i < objectSize; i++) {
        rawClassData[i] = (((char *)this)[i]);
    }
    return rawClassData;
}
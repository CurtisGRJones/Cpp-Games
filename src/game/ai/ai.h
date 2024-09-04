#pragma once 

#include <memory>

class Ai
{
private:
public:
    Ai();
    ~Ai();

    int getMove(std::unique_ptr<uint8_t[]> boardState);
};
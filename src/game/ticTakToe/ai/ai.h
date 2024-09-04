#pragma once 

#include <memory>
#include <functional>

class Ai
{
private:
    std::function<uint8_t(std::array<uint8_t, 9> *boardState)> m_testWin;
    std::function<uint8_t(std::array<uint8_t, 9> *boardState)> m_testFull;

public:
    Ai(
        std::function<uint8_t(std::array<uint8_t, 9> *boardState)> testWin,
        std::function<uint8_t(std::array<uint8_t, 9> *boardState)> testFull
    );
    ~Ai();

    uint8_t getMove(std::array<uint8_t, 9> *boardState, bool aiTurn);

    float getMiniMaxScore(std::array<uint8_t, 9> *boardState, uint8_t aiId, bool isTurn);
};
#ifndef AI_H
#define AI_H

#include "ai.h"

#include <algorithm>
#include <vector>
#include <random>

Ai::Ai(
    std::function<uint8_t(std::array<uint8_t, 9> *boardState)> testWin,
    std::function<uint8_t(std::array<uint8_t, 9> *boardState)> testFull)
    : m_testWin(testWin), m_testFull(testFull)
{   
}

Ai::~Ai()
{
}

uint8_t Ai::getMove(std::array<uint8_t, 9> *boardState, bool aiTurn)
{
    int aiId = int(aiTurn) + 1;

    std::vector<uint8_t> bestMoves;
    bestMoves.reserve(9);
    float bestScore = -std::numeric_limits<float>::infinity();
    float score = -std::numeric_limits<float>::infinity();
    std::array<uint8_t, 9> newBoardState = {0};

    for (uint8_t i = 0; i < 9; i++)
    {
        if (boardState->at(i) == 0)
        {
            std::copy(boardState->begin(), boardState->end(), newBoardState.begin());
            newBoardState[i]= aiId;
            score = this->getMiniMaxScore(&newBoardState, aiId, false);
            if (score > bestScore) {
                bestMoves.clear();
                bestMoves.push_back(i);
                bestScore = score;
            } else if (score == bestScore) {
                bestMoves.push_back(i);
            }
        }
    }

    score = this->getMiniMaxScore(boardState, aiId, true);

    return bestMoves[std::rand() % bestMoves.size()];
}

float Ai::getMiniMaxScore(std::array<uint8_t, 9> *boardState, uint8_t aiId, bool isTurn)
{

    uint8_t winner = m_testWin(boardState);

    if (winner != 0)
    {

        return winner == aiId ? 2.0f : -2.0f;
    }
    
    if (m_testFull(boardState))
    {
        return 0.0f;
    }

    float bestScore = isTurn ? -std::numeric_limits<float>::infinity() : std::numeric_limits<float>::infinity();

    // TODO mutate board state instead of copying every time
    std::array<uint8_t, 9> newBoardState = {0};
    for (uint8_t i = 0; i < 9; i++)
    {
        if (boardState->at(i) == 0)
        {
            std::copy(boardState->begin(), boardState->end(), newBoardState.begin());
            newBoardState[i] = isTurn ?
                aiId == 1 ? 1 : 2 :
                aiId == 2 ? 1 : 2;
            float score = getMiniMaxScore( &newBoardState, aiId, !isTurn );

            bestScore = isTurn ?
                score > bestScore ? score : bestScore :
                score < bestScore ? score : bestScore;
        }
    }

    return bestScore / 2.0f;
}
#endif

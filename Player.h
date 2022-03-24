//
// Created by Jun Kim on 10/4/21.
//

#ifndef CS2_OCT042021_PROJECT3_PLAYER_H
#define CS2_OCT042021_PROJECT3_PLAYER_H

class Arena;

#include <string>
using namespace std;

class Player
{
public:
    // Constructor
    Player(Arena *ap, int r, int c);

    // Accessors
    int  row() const;
    int  col() const;
    int  age() const;
    bool isDead() const;

    // Mutators
    string takeComputerChosenTurn();
    void   stand();
    void   move(int dir);
    bool   shoot(int dir);
    void   setDead();

private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    int    m_age;
    bool   m_dead;
};

#endif //CS2_OCT042021_PROJECT3_PLAYER_H

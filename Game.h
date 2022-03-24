//
// Created by Jun Kim on 10/4/21.
//

#ifndef CS2_OCT042021_PROJECT3_GAME_H
#define CS2_OCT042021_PROJECT3_GAME_H

class Arena;

class Game
{
public:
    // Constructor/destructor
    Game(int rows, int cols, int nRobots);
    ~Game();

    // Mutators
    void play();

private:
    Arena* m_arena;
};

#endif //CS2_OCT042021_PROJECT3_GAME_H

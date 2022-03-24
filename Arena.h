//
// Created by Jun Kim on 10/4/21.
//

#ifndef CS2_OCT042021_PROJECT3_ARENA_H
#define CS2_OCT042021_PROJECT3_ARENA_H

class Player;
class Robot;

#include <string>
#include "globals.h"
//#include "History.h"
using namespace std;

class Arena
{
public:
    // Constructor/destructor
    Arena(int nRows, int nCols);
    ~Arena();

    // Accessors
    int     rows() const;
    int     cols() const;
    Player* player() const;
    int     robotCount() const;
    int     nRobotsAt(int r, int c) const;
    void    display(string msg) const;

    // Mutators
    bool   addRobot(int r, int c);
    bool   addPlayer(int r, int c);
    void   damageRobotAt(int r, int c);
    bool   moveRobots();

    //history
//    History& history();

private:

    int     m_rows;
    int     m_cols;
    Player* m_player;
    Robot*  m_robots[MAXROBOTS];
    int     m_nRobots;
//    History h_history;
};

#endif //CS2_OCT042021_PROJECT3_ARENA_H

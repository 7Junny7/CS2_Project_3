//
// Created by Jun Kim on 10/4/21.
//
///////////////////////////////////////////////////////////////////////////
//  Robot implementation
///////////////////////////////////////////////////////////////////////////
#include "Robot.h"
#include "globals.h"
#include "Arena.h"
#include <iostream>

using namespace std;

Robot::Robot(Arena* ap, int r, int c)
{
    if (ap == nullptr)
    {
        cout << "***** A robot must be in some Arena!" << endl;
        exit(1);
    }
    if (r < 1  ||  r > ap->rows()  ||  c < 1  ||  c > ap->cols())
    {
        cout << "***** Robot created with invalid coordinates (" << r << ","
             << c << ")!" << endl;
        exit(1);
    }
    m_arena = ap;
    m_row = r;
    m_col = c;
}

int Robot::row() const
{
    return m_row;
}

int Robot::col() const
{
    // TODO: TRIVIAL:  Return what column the robot is at.
    // Delete the following line and replace it with the correct code.
    return m_col;  // This implementation compiles, but is incorrect.
}

void Robot::move()
{
    // Attempt to move in a random direction; if we can't move, don't move
    switch (rand() % 4)
    {
        case UP:
            // TODO:  Move the robot up one row if possible.
            if (m_row > 1){
                m_row--;
            }else{
                m_row = 1;
            }
            break;
        case DOWN:
            if (m_row < m_arena->rows()){
                m_row++;
            }else{
                m_row = m_arena->rows();
            }
            break;
        case LEFT:
            if (m_col > 1){
                m_col--;
            }else{
                m_col = 1;
            }
            break;
        case RIGHT:
            // TODO:  Implement the other movements.
            if (m_col < m_arena->cols()){
                m_col++;
            }else{
                m_col = m_arena->cols();
            }
            break;
    }
}

bool Robot::takeDamageAndLive()
{
    // TODO:  If the robot has been hit once before, return false (since a
    // second hit kills a robot).  Otherwise, return true (since the robot
    // survived the damage).
    if (m_damaged){
        return false;
    }else{
        m_damaged = true;
        return true;
    }
}

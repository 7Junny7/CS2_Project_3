//
// Created by Jun Kim on 10/4/21.
//
///////////////////////////////////////////////////////////////////////////
//  Player implementations
///////////////////////////////////////////////////////////////////////////

#include "Player.h"
#include "Arena.h"
#include <iostream>
using namespace std;

Player::Player(Arena* ap, int r, int c)
{
    if (ap == nullptr)
    {
        cout << "***** The player must be in some Arena!" << endl;
        exit(1);
    }
    if (r < 1  ||  r > ap->rows()  ||  c < 1  ||  c > ap->cols())
    {
        cout << "**** Player created with invalid coordinates (" << r
             << "," << c << ")!" << endl;
        exit(1);
    }
    m_arena = ap;
    m_row = r;
    m_col = c;
    m_age = 0;
    m_dead = false;
}

int Player::row() const
{
    // TODO: TRIVIAL:  Return what row the player is at.
    // Delete the following line and replace it with the correct code.
    return m_row;  // This implementation compiles, but is incorrect.
}

int Player::col() const
{
    // TODO: TRIVIAL:  Return what column the player is at.
    // Delete the following line and replace it with the correct code.
    return m_col;  // This implementation compiles, but is incorrect.
}

int Player::age() const
{
    // TODO:  TRIVIAL:  Return the player's age.
    // Delete the following line and replace it with the correct code.
    return m_age;  // This implementation compiles, but is incorrect.
}

string Player::takeComputerChosenTurn()
{
    // TODO:  Replace this implementation:
    // Your replacement implementation should do something intelligent
    // and return a string that describes what happened.  When you've
    // decided what action to take, take it by calling move, shoot, or stand.
    // This function must return one of the following four strings:
    //     "Moved."
    //     "Shot and hit!"
    //     "Shot and missed!"
    //     "Stood."
    for (int i=1; i<=MAXSHOTLEN; i++){
        if (i == 1){
            //Checking Upside
            if (m_arena->nRobotsAt(m_row - i, m_col) > 0 &&
            m_arena->nRobotsAt(m_row + i,m_col) == 0 && m_row + i <= m_arena->rows()){
                move(DOWN);
                return "Moved DOWN.";
            }else if (m_arena->nRobotsAt(m_row - i, m_col) > 0 &&
                    (m_arena->nRobotsAt(m_row + i,m_col) > 0 || m_row + i > m_arena->rows())){
                if (m_arena->nRobotsAt(m_row,m_col - i) == 0 && m_col - i >= 1){
                    move(LEFT);
                    return "Moved LEFT.";
                }else if (m_arena->nRobotsAt(m_row, m_col + i) == 0 && m_col + i <= m_arena->cols()){
                    move(RIGHT);
                    return "Moved RIGHT.";
                }else{
                    continue;
                }
            }
            //Checking Downside
            else if (m_arena->nRobotsAt(m_row + i, m_col) > 0 &&
            m_arena->nRobotsAt(m_row - i, m_col) == 0 && m_row - i >= 1){
                move(UP);
                return "Moved UP.";
            }else if (m_arena->nRobotsAt(m_row + i, m_col) > 0 &&
                    (m_arena->nRobotsAt(m_row - i, m_col) > 0 || m_row - i < 1)){
                if (m_arena->nRobotsAt(m_row,m_col - i) == 0 && m_col - i >= 1){
                    move(LEFT);
                    return "Moved LEFT.";
                }else if (m_arena->nRobotsAt(m_row, m_col + i) == 0 && m_col + i <= m_arena->cols()){
                    move(RIGHT);
                    return "Moved RIGHT.";
                }else{
                    continue;
                }
            }
            //Checking Leftside
            else if (m_arena->nRobotsAt(m_row, m_col - i) > 0 &&
            m_arena->nRobotsAt(m_row, m_col + i) == 0 && m_col + i <= m_arena->cols()){
                move(RIGHT);
                return "Moved RIGHT.";
            }else if (m_arena->nRobotsAt(m_row, m_col - i) > 0 &&
                    (m_arena->nRobotsAt(m_row, m_col + i) > 0 || m_col + i > m_arena->cols())){
                if (m_arena->nRobotsAt(m_row - i, m_col) == 0 && m_row - i >= 1){
                    move(UP);
                    return "Moved UP.";
                }else if (m_arena->nRobotsAt(m_row + i, m_col) == 0 && m_row + i <= m_arena->cols()){
                    move(DOWN);
                    return "Moved DOWN.";
                }else{
                    continue;
                }
            }
            //Checking Rightside
            else if (m_arena->nRobotsAt(m_row, m_col + i) > 0 &&
            m_arena->nRobotsAt(m_row, m_col - i) == 0 && m_col - i >= 1){
                move(LEFT);
                return "Moved LEFT.";
            }else if (m_arena->nRobotsAt(m_row, m_col + i) > 0 &&
                    (m_arena->nRobotsAt(m_row, m_col - i) > 0 || m_col - i < 1)){
                if (m_arena->nRobotsAt(m_row - i, m_col) == 0 && m_row - i >= 1){
                    move(UP);
                    return "Moved UP.";
                }else if (m_arena->nRobotsAt(m_row + i, m_col) == 0 && m_row + i <= m_arena->cols()){
                    move(DOWN);
                    return "Moved DOWN.";
                }else{
                    continue;
                }
            }
        }
        if (m_arena->nRobotsAt(m_row - i, m_col) > 0){
            if (shoot(UP)){
                return "Shot UP and hit!";
            }else{
                return "Shot UP and missed!";
            }
        }else if (m_arena->nRobotsAt(m_row + i, m_col) > 0){
            if (shoot(DOWN)){
                return "Shot DOWN and hit!";
            }else{
                return "Shot DOWN and missed!";
            }
        }else if (m_arena->nRobotsAt(m_row, m_col - i) > 0){
            if (shoot(LEFT)){
                return "Shot LEFT and hit!";
            }else{
                return "Shot LEFT and missed!";
            }
        }else if (m_arena->nRobotsAt(m_row, m_col + i) > 0){
            if (shoot(RIGHT)){
                return "Shot RIGHT and hit!";
            }else{
                return "Shot RIGHT and missed!";
            }
        }
    }
    stand();
    return "Stood.";
    // Here's one possible strategy:
    //   If moving in some direction would put me in less immediate danger
    //     than standing, then move in that direction.
    //   else shoot in the direction of the nearest robot I can hit.

    // A more aggressive strategy is possible, where you hunt down robots.
}

void Player::stand()
{
    m_age++;

    //for history
//    bool stand = m_arena->history().record(row(),col());
//    if (stand)
//        cout<<"true"<<endl;
//    else
//        cout<<"false"<<endl;
}

void Player::move(int dir)
{
    m_age++;

    //for history
//    bool move = m_arena->history().record(row(),col());
//    if (move)
//        cout<<"true"<<endl;
//    else
//        cout<<"false"<<endl;

    switch (dir)
    {
        case UP:
            if (m_row > 1){
                m_row--;
            }else{
                m_row = 1;
            }
            // TODO:  Move the player up one row if possible.
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
            if (m_col < m_arena->cols()){
                m_col++;
            }else{
                m_col = m_arena->cols();
            }
            cout<<m_col<<endl;
            // TODO:  Implement the other movements.
            break;
    }
}

bool Player::shoot(int dir)
{
    m_age++;
    switch (dir){
        case UP:
            for(int i=1; i<=MAXSHOTLEN; i++){
                if(m_arena->nRobotsAt(m_row - i,m_col) > 0) {
                    if (rand() % 3 == 0) {  // miss with 1/3 probability
                        return false;
                    }else{
                        m_arena->damageRobotAt(m_row - i,m_col);
                        return true;
                    }
                }
            }
            return false;
            break;
        case DOWN:
            for(int i=1; i<=MAXSHOTLEN; i++){
                if(m_arena->nRobotsAt(m_row + i, m_col) > 0){
                    if (rand() % 3 == 0){
                        return false;
                    }else{
                        m_arena->damageRobotAt(m_row + i, m_col);
                        return true;
                    }
                }
            }
            return false;
            break;
        case LEFT:
            for(int i=1; i<=MAXSHOTLEN; i++){
                if(m_arena->nRobotsAt(m_row, m_col - i) > 0){
                    if (rand() % 3 == 0){
                        return false;
                    }else{
                        m_arena->damageRobotAt(m_row, m_col - i);
                        return true;
                    }
                }
            }
            return false;
            break;
        case RIGHT:
            for(int i=1; i<=MAXSHOTLEN; i++){
                if(m_arena->nRobotsAt(m_row,m_col + i) > 0){
                    if(rand() % 3 == 0){
                        return false;
                    }else{
                        m_arena->damageRobotAt(m_row, m_col + i);
                        return true;
                    }
                }
            }
            return false;
            break;
    }

    // TODO:  Damage the nearest robot in direction dir, returning
    // true if a robot is hit and damaged, false if not hit.
//    return false;  // This implementation compiles, but is incorrect.
}

bool Player::isDead() const
{
    // TODO:  TRIVIAL:  Return whether the player is dead.
    if (m_dead)
        return true;
    else
        return false;  // This implementation compiles, but is incorrect.
}

void Player::setDead()
{
    m_dead = true;
}

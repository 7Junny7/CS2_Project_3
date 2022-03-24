//
// Created by Jun Kim on 10/4/21.
//
///////////////////////////////////////////////////////////////////////////
//  Arena implementations
///////////////////////////////////////////////////////////////////////////

#include "Arena.h"
#include "Player.h"
#include "globals.h"
#include "Robot.h"
//#include "History.h"
//class History;
#include <iostream>
using namespace std;

Arena::Arena(int nRows, int nCols) //: h_history(nRows, nCols)
{
    if (nRows <= 0  ||  nCols <= 0  ||  nRows > MAXROWS  ||  nCols > MAXCOLS)
    {
        cout << "***** Arena created with invalid size " << nRows << " by "
             << nCols << "!" << endl;
        exit(1);
    }
    m_rows = nRows;
    m_cols = nCols;
    m_player = nullptr;
    m_nRobots = 0;

}

Arena::~Arena()
{
    delete m_player;
    for (int i=0; i<this->robotCount(); i++){
        delete m_robots[i];
    }
    // TODO:  Delete the player and all remaining dynamically allocated robots.
}

int Arena::rows() const
{
    // TODO:  TRIVIAL:  Return the number of rows in the arena.
    // Delete the following line and replace it with the correct code.
    return m_rows;  // This implementation compiles, but is incorrect.
}

int Arena::cols() const
{
    // TODO:  TRIVIAL:  Return the number of columns in the arena.
    // Delete the following line and replace it with the correct code.
    return m_cols;  // This implementation compiles, but is incorrect.
}

Player* Arena::player() const
{
    return m_player;
}

int Arena::robotCount() const
{
    return m_nRobots;
}

int Arena::nRobotsAt(int r, int c) const
{
    int count = 0;
    for (int i=0; i<m_nRobots; i++){
        if (m_robots[i]->row() == r && m_robots[i]->col() == c){
            count++;
        }
    }

    // TODO:  Return the number of robots at row r, column c.
    return count;  // This implementation compiles, but is incorrect.
}

void Arena::display(string msg) const
{
    // Position (row,col) in the arena coordinate system is represented in
    // the array element grid[row-1][col-1]
    char grid[MAXROWS][MAXCOLS];
    int r, c;

    // Fill the grid with dots
    for (r = 0; r < rows(); r++)
        for (c = 0; c < cols(); c++)
            grid[r][c] = '.';


    // Indicate each robot's position
    // TODO:  If one robot is at some grid point, set the char to 'R'.
    //        If it's 2 though 8, set it to '2' through '8'.
    //        For 9 or more, set it to '9'.
    if (m_nRobots != 0){
        for(int i=0; i<m_nRobots; i++){
            char& gridChar = grid[m_robots[i]->row()-1][m_robots[i]->col()-1];
            if (gridChar == '.'){
                if (nRobotsAt(m_robots[i]->row(),m_robots[i]->col()) == 1){
                    gridChar = 'R';
                }else if (nRobotsAt(m_robots[i]->row(),m_robots[i]->col()) >= 2 && nRobotsAt(m_robots[i]->row(),m_robots[i]->col()) <= 8){
                    gridChar = static_cast<char>(48+nRobotsAt(m_robots[i]->row(),m_robots[i]->col()));
                }else if (nRobotsAt(m_robots[i]->row(),m_robots[i]->col()) > 9){
                    gridChar = '9';
                }
            }
        }
    }

    // Indicate player's position
    if (m_player != nullptr)
    {
        // Set the char to '@', unless there's also a robot there,
        // in which case set it to '*'.
        char& gridChar = grid[m_player->row()-1][m_player->col()-1];
        if (gridChar == '.')
            gridChar = '@';
        else
            gridChar = '*';
    }

    // Draw the grid
    clearScreen();
    for (r = 0; r < rows(); r++)
    {
        for (c = 0; c < cols(); c++)
            cout << grid[r][c];
        cout << endl;
    }
    cout << endl;

    // Write message, robot, and player info
    cout << endl;
    if (msg != "")
        cout << msg << endl;
    cout << "There are " << robotCount() << " robots remaining." << endl;
    if (m_player == nullptr)
        cout << "There is no player." << endl;
    else
    {
        if (m_player->age() > 0)
            cout << "The player has lasted " << m_player->age() << " steps." << endl;
        if (m_player->isDead())
            cout << "The player is dead." << endl;
    }
}

bool Arena::addRobot(int r, int c)
{
    // If MAXROBOTS have already been added, return false.  Otherwise,
    // dynamically allocate a new robot at coordinates (r,c).  Save the
    // pointer to the newly allocated robot and return true.
    // TODO:  Implement this.
    if (this->robotCount() == MAXROBOTS){
        return false;  // This implementation compiles, but is incorrect.
    }else{
        m_robots[m_nRobots] = new Robot(this,r,c);
        m_nRobots++;
        return true;
    }

}

bool Arena::addPlayer(int r, int c)
{
    // Don't add a player if one already exists
    if (m_player != nullptr)
        return false;

    // Dynamically allocate a new Player and add it to the arena
    m_player = new Player(this, r, c);
    return true;
}

void Arena::damageRobotAt(int r, int c)
{
    // TODO:  Damage one robot at row r, column c if at least one is there.
    // If the robot does not survive the damage, destroy it.
    for(int i=0; i<m_nRobots; i++){
        if (m_robots[i]->row() == r && m_robots[i]->col() == c){
            bool check_robot = m_robots[i]->takeDamageAndLive();
            if (check_robot == false){
                for (int j=i; j<m_nRobots; j++){
                    *(m_robots + j) = *(m_robots + j + 1);
                }
                delete *(m_robots+m_nRobots);
                m_nRobots--;
            }
            break;
        }
    }
}

bool Arena::moveRobots()
{
    for (int k = 0; k < m_nRobots; k++)
    {
        // TODO:  Have the k-th robot in the arena make one move.
        //        If that move results in that robot being in the same
        //        position as the player, the player dies.
        m_robots[k]->move();
        if(m_robots[k]->col() == m_player->col() && m_robots[k]->row() == m_player->row()){
            m_player->setDead();
        }
    }

    // return true if the player is still alive, false otherwise
    if (m_player->isDead()) {
        return false;
    }
    else {
        return true;
    }
}

//for history
//History& Arena::history(){
//
//    return h_history;
//}


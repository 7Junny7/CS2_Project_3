//
// Created by Jun Kim on 10/4/21.
//

#ifndef CS2_OCT042021_PROJECT3_ROBOT_H
#define CS2_OCT042021_PROJECT3_ROBOT_H

class Arena;  // This is needed to let the compiler know that Arena is a
// type name, since it's mentioned in the Robot declaration.

class Robot
{
public:
    // Constructor
    Robot(Arena* ap, int r, int c);

    // Accessors
    int  row() const;
    int  col() const;

    // Mutators
    void move();
    bool takeDamageAndLive();

private:
    Arena* m_arena;
    int    m_row;
    int    m_col;
    // TODO: You'll probably find that a robot object needs an additional
    // data member to support your implementation of the behavior affected
    // by being hit and taking damage.
    bool m_damaged = false;
};

#endif //CS2_OCT042021_PROJECT3_ROBOT_H

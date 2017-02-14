//
//  mainstack.cpp
//  Maze
//
//  Created by Junnan Liu on 2/6/17.
//  Copyright © 2017 Junnan Liu. All rights reserved.
//



#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Coord
{
public:
    Coord(int rr, int cc) : m_r(rr), m_c(cc) {}
    int r() const { return m_r; }   //
    int c() const { return m_c; }
private:
    int m_r;
    int m_c;
};

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec);
// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise

// Each 'X' represents a wall, and each '.' represents a walkway.
// sr starts from 0.
// maze[sr][sc] and maze[er][ec] are '.' (i.e., not walls)

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
    stack <Coord> coordStack;
    
    coordStack.push(Coord(sr,sc)); // Push the starting coordinate (sr,sc) onto the coordinate stack
    maze[sr][sc] = '@'; // use "@" to indicate that the algorithm has encountered
    
    while(!coordStack.empty())
    {
        int row = coordStack.top().r(); // obtain the top value of row
        int col = coordStack.top().c(); // col
        coordStack.pop(); // pop the top value
        if(row == er && col == ec)
            return true;   // check if comes to the end
        
        if (maze[row-1][col] == '.' ) // north
        {
            coordStack.push(Coord(row-1, col));
            maze[row-1][col] = '@' ;
        }
        
        if (maze[row][col+1] == '.' ) // east
        {
            coordStack.push(Coord(row, col+1));
            maze[row][col+1] = '@' ;
        }
        
        if (maze[row+1][col] == '.' ) // south
        {
            coordStack.push(Coord(row+1, col));
            maze[row+1][col] = '@' ;
        }
        
        if (maze[row][col-1] == '.' ) // west
        {
            coordStack.push(Coord(row, col-1));
            maze[row][col-1] = '@' ;
        }
    }
    return false;   // fall to come to the end
}

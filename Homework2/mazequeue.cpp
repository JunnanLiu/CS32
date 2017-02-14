//
//  mainstack.cpp
//  Maze
//
//  Created by Junnan Liu on 2/6/17.
//  Copyright © 2017 Junnan Liu. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>

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
    queue <Coord> coordQueue;
    
    coordQueue.push(Coord(sr,sc)); // Push the starting coordinate (sr,sc) onto the coordinate stack
    maze[sr][sc] = '@'; // use "@" to indicate that the algorithm has encountered
    
    while(!coordQueue.empty())
    {
        int row = coordQueue.front().r(); // obtain the front value of row
        int col = coordQueue.front().c(); // col
        cout<<"("<<row<<","<<col<<")"<<endl;
        coordQueue.pop(); // pop the front value
        if(row == er && col == ec)
            return true;   // check if comes to the end
        
        if (maze[row-1][col] == '.' ) // north
        {
            coordQueue.push(Coord(row-1, col));
            maze[row-1][col] = '@' ;
        }
        
        if (maze[row][col+1] == '.' ) // east
        {
            coordQueue.push(Coord(row, col+1));
            maze[row][col+1] = '@' ;
        }
        
        if (maze[row+1][col] == '.' ) // south
        {
            coordQueue.push(Coord(row+1, col));
            maze[row+1][col] = '@' ;
        }
        
        if (maze[row][col-1] == '.' ) // west
        {
            coordQueue.push(Coord(row, col-1));
            maze[row][col-1] = '@' ;
        }
    }
    return false;   // fall to come to the end
}

int main()
{
    string maze[10] = {
        "XXXXXXXXXX",
        "X........X",
        "XX.X.XXXXX",
        "X..X.X...X",
        "X..X...X.X",
        "XXXX.XXX.X",
        "X.X....XXX",
        "X..XX.XX.X",
        "X...X....X",
        "XXXXXXXXXX"
    };
    
    if (pathExists(maze, 10,10, 6,4, 1,1))
        cout << "Solvable!" << endl;
    else
        cout << "Out of luck!" << endl;
}

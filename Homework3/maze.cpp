//
//  maze.cpp
//  Homework3
//
//
//
//  Created by Junnan Liu on 2/12/17.
//  Copyright © 2017 Junnan Liu. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>

using namespace std;

// Return true if there is a path from (sr,sc) to (er,ec)
// through the maze; return false otherwise

// Each 'X' represents a wall, and each '.' represents a walkway.
// sr starts from 0.
// maze[sr][sc] and maze[er][ec] are '.' (i.e., not walls)

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec)
{
    if (sr == er && sc == ec)   // stop point
        return true;
    maze[sr][sc] = '@';   // visited
    
    if (maze[sr-1][sc] == '.' ) // north
    {
        if(pathExists(maze, nRows, nCols, sr - 1, sc, er, ec))
            return true;
    }
    
    if (maze[sr][sc+1] == '.' ) // east
    {
        if(pathExists(maze, nRows, nCols, sr, sc + 1, er, ec))
            return true;
    }
    
    if (maze[sr+1][sc] == '.' ) // south
    {
        if(pathExists(maze, nRows, nCols, sr + 1, sc, er, ec))
            return true;
    }
    
    if (maze[sr][sc-1] == '.' ) // west
    {
        if(pathExists(maze, nRows, nCols, sr, sc - 1, er, ec))
            return true;
    }
    return false;   // fall to come to the end
}

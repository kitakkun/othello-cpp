#include "board.h"
#include <iostream>

// public methods ====================================

Board::Board()
{
    initMap();
    turn = BLACK; // 黒から
}

bool Board::putDisk(Disk disk)
{
    bool reversed = reverseDisks(disk);
    if (reversed)
    {
        putDisk(disk.x, disk.y, disk.color);
        return true;
    }
    else
    {
        return false;
    }
}

void Board::putDisk(int x, int y, int color)
{
    map.at(y).at(x) = color;
}

void Board::changeTurn()
{
    if (turn == BLACK)
        turn = WHITE;
    else if (turn == WHITE)
        turn = BLACK;
}

int Board::getCell(int x, int y)
{
    return map.at(y).at(x);
}

int Board::getTurn()
{
    return turn;
}

// private methods ====================================

void Board::initMap()
{
    // EMPTY埋め
    for (array<int, CELL> &line : map)
    {
        line.fill(EMPTY);
    }
    // 初期配置
    putDisk(CELL / 2 - 1, CELL / 2 - 1, BLACK);
    putDisk(CELL / 2, CELL / 2, BLACK);
    putDisk(CELL / 2 - 1, CELL / 2, WHITE);
    putDisk(CELL / 2, CELL / 2 - 1, WHITE);
}

bool Board::reverseDisks(Disk disk)
{
    bool reversed = false;
    reversed =
        reverseDisks(disk, UP) ||
        reverseDisks(disk, DOWN) ||
        reverseDisks(disk, LEFT) ||
        reverseDisks(disk, RIGHT) ||
        reverseDisks(disk, UP_LEFT) ||
        reverseDisks(disk, UP_RIGHT) ||
        reverseDisks(disk, DOWN_LEFT) ||
        reverseDisks(disk, DOWN_RIGHT);
    return reversed;
}

bool Board::reverseDisks(Disk disk, int dir)
{
    vector<int> v;
    vector<int *> vp;
    v = getVector(disk.x, disk.y, dir);
    if (canReverse(v, disk))
    {
        vp = getVectorPtr(disk.x, disk.y, dir);
        for (int i = 0; *vp.at(i) != disk.color; i++)
        {
            *vp.at(i) = disk.color;
        }
        return true;
    }
    else
    {
        return false;
    }
}

bool Board::canReverse(vector<int> v, Disk disk)
{
    bool findDiffColor = false;
    for (int i = 0; i < v.size(); i++)
    {
        int cell = v.at(i);
        if (cell == EMPTY)
            return false;
        if (!findDiffColor && cell != disk.color)
        {
            findDiffColor = true;
        }
        if (findDiffColor && cell == disk.color)
        {
            return true;
        }
    }
    return false;
}

int *Board::getCellPtr(int x, int y)
{
    return &map.at(y).at(x);
}

vector<int *> Board::getVectorPtr(int x, int y, int dir)
{
    vector<int *> result;
    int i, j;
    if (dir == UP)
    {
        j = x;
        for (i = y - 1; i >= 0; i--)
        {
            result.push_back(getCellPtr(j, i));
        }
    }
    else if (dir == DOWN)
    {
        j = x;
        for (i = y + 1; i < CELL; i++)
        {
            result.push_back(getCellPtr(j, i));
        }
    }
    else if (dir == LEFT)
    {
        i = y;
        for (j = x - 1; j >= 0; j--)
        {
            result.push_back(getCellPtr(j, i));
        }
    }
    else if (dir == RIGHT)
    {
        i = y;
        for (j = x + 1; j < CELL; j++)
        {
            result.push_back(getCellPtr(j, i));
        }
    }
    else if (dir == UP_LEFT)
    {
        for (i = y - 1, j = x - 1; i >= 0 && j >= 0; i--, j--)
        {
            result.push_back(getCellPtr(j, i));
        }
    }
    else if (dir == UP_RIGHT)
    {
        for (i = y - 1, j = x + 1; i >= 0 && j < CELL; i--, j++)
        {
            result.push_back(getCellPtr(j, i));
        }
    }
    else if (dir == DOWN_LEFT)
    {
        for (i = y + 1, j = x - 1; i < CELL && j >= 0; i++, j--)
        {
            result.push_back(getCellPtr(j, i));
        }
    }
    else if (dir == DOWN_RIGHT)
    {
        for (i = y + 1, j = x + 1; i < CELL && j < CELL; i++, j++)
        {
            result.push_back(getCellPtr(j, i));
        }
    }
    return result;
}

vector<int> Board::getVector(int x, int y, int dir)
{
    vector<int> result;
    int i, j;
    if (dir == UP)
    {
        j = x;
        for (i = y - 1; i >= 0; i--)
        {
            result.push_back(getCell(j, i));
        }
    }
    else if (dir == DOWN)
    {
        j = x;
        for (i = y + 1; i < CELL; i++)
        {
            result.push_back(getCell(j, i));
        }
    }
    else if (dir == LEFT)
    {
        i = y;
        for (j = x - 1; j >= 0; j--)
        {
            result.push_back(getCell(j, i));
        }
    }
    else if (dir == RIGHT)
    {
        i = y;
        for (j = x + 1; j < CELL; j++)
        {
            result.push_back(getCell(j, i));
        }
    }
    else if (dir == UP_LEFT)
    {
        for (i = y - 1, j = x - 1; i >= 0 && j >= 0; i--, j--)
        {
            result.push_back(getCell(j, i));
        }
    }
    else if (dir == UP_RIGHT)
    {
        for (i = y - 1, j = x + 1; i >= 0 && j < CELL; i--, j++)
        {
            result.push_back(getCell(j, i));
        }
    }
    else if (dir == DOWN_LEFT)
    {
        for (i = y + 1, j = x - 1; i < CELL && j >= 0; i++, j--)
        {
            result.push_back(getCell(j, i));
        }
    }
    else if (dir == DOWN_RIGHT)
    {
        for (i = y + 1, j = x + 1; i < CELL && j < CELL; i++, j++)
        {
            result.push_back(getCell(j, i));
        }
    }
    return result;
}
#include "interface.h"

void draw(Board board)
{
    int i, j;
    cout << "  0 1 2 3 4 5 6 7" << endl;
    for (i = 0; i < CELL; i++)
    {
        cout << i << " ";
        for (j = 0; j < CELL; j++)
        {
            cout << board.getCell(j, i) << " ";
        }
        cout << endl;
    }
}

void getUserInput(int *x, int *y)
{
    cout << "x = ";
    cin >> *x;
    cout << "y = ";
    cin >> *y;
}
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

int getUserInput(int *x, int *y)
{
    cout << "x = ";
    cin >> *x;
    cout << "y = ";
    cin >> *y;
    if (*x < 0 || *x > CELL || *y < 0 || *y > CELL)
    {
        return 1;
    }
    return 0;
}
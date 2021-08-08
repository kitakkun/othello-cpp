#include "board.h"
#include "interface.h"

int main()
{
    Board board = Board();
    int black, white;

    while (!board.isFilled())
    {
        Disk disk;
        cout << "Turn: " << board.getTurn() << endl;
        draw(board);
        if (getUserInput(&disk.x, &disk.y))
        {
            cout << "invalid input." << endl;
            continue;
        }
        disk.color = board.getTurn();
        if (board.putDisk(disk))
        {
            board.changeTurn();
        }
        else
        {
            cout << "you can't put the disk here." << endl;
        }
    }

    black = board.count(BLACK);
    white = board.count(WHITE);

    cout << "BLACK(" << BLACK << "): " << black << endl;
    cout << "WHITE(" << WHITE << "): " << white << endl;

    if (black > white)
        cout << "WIN: BLACK" << endl;
    else if (black < white)
        cout << "WIN: WHITE" << endl;
    else
        cout << "DRAW" << endl;

    return 0;
}
#include "board.h"
#include "interface.h"

int main()
{
    Board board = Board();
    while (1)
    {
        Disk disk;
        cout << "Turn: " << board.getTurn() << endl;
        draw(board);
        getUserInput(&disk.x, &disk.y);
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
    return 0;
}
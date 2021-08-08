#pragma once
#include <array>
#include <vector>
#define CELL 8
#define EMPTY 0
#define BLACK 1
#define WHITE 2
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define UP_LEFT 4
#define UP_RIGHT 5
#define DOWN_LEFT 6
#define DOWN_RIGHT 7

using namespace std;

typedef struct
{
    int x;
    int y;
    int color;
} Disk;

class Board
{
public:
    Board();
    bool putDisk(Disk);          // ディスクを配置（構造体使用）
    void putDisk(int, int, int); // ディスクを配置（int, int, int）
    void changeTurn();           // ターンの変更
    int getTurn();               // 現在のターンを取得
    int getCell(int, int);       // (x, y)座標のセル情報の取得
    bool isFilled();             // 配置できるエリアが存在しない
    int count(int);              // 指定された色の石をカウントする

private:
    void initMap();                            // 盤面情報の初期化
    bool reverseDisks(Disk);                   // ひっくり返す処理
    bool reverseDisks(Disk, int);              // ひっくり返す処理
    vector<int *> getVectorPtr(int, int, int); // 始点から第3引数の方向へベクトルを返す
    vector<int> getVector(int, int, int);      // 始点から第3引数の方向へベクトルを返す
    int *getCellPtr(int, int);
    bool canReverse(vector<int>, Disk);
    array<array<int, CELL>, CELL> map;
    int turn;
};

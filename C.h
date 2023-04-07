#ifndef c_h
#define c_h

class T_Box
{
    static int Score ;
    static int Rank ;
    private :
             int x ,y ; // 座標
             int type ; // 型別
             int fg ; // 某個圖形的第 fg 個變化的圖形
    public :
             T_Box(int sx = 31 ,int sy = 3 ,int st = 0 ,int f = 0);
             static void staticNum(int num);
             void setValue(int sx = 31 ,int sy = 3 ,int st = 0 ,int f = 0) ;
             void Move(int stepA ,int stepB);
             bool Stop();
             void printBox();
             void eraseBox();
             void Mark();
             void Pause();
             void nextBox(T_Box temp);
             void Transform();
             bool Judge();
};
class Coord
{
    public :
            int x;
            int y;
            int Col;
}G[10][10][10];



#endif
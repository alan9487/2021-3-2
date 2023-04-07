#include<iostream>
#include<iomanip>
#include"C.h"
using namespace std;

void Tetris()
{
   srand(time(0)); // 取系統時間
   setBox();    // 設定各種圖形
   T_Box  cd ,tempA ,tempB;   // 每個下降的方塊的初始值
   tempB.setValue(); // 設定方塊初始值
   tempB.nextBox(tempA);
   for(int i = 0;   ; ++i)
   {
       if(!(i%2))   tempA.setValue();
       else         tempB.setValue();
       if(i%2)      tempB.nextBox(tempA) ,cd = tempA;
       else         tempA.nextBox(tempB) ,cd = tempB;
       while(1) {
          cd.printBox(); // 輸出圖形
          if(cd.Stop())
          {
              color(6);
              getCoord(20 ,10);
              cout<<"   T_T    遊戲結束    T_T";
              Exit();
          }
          Sleep(350);
          cd.eraseBox(); //擦除圖形
          cd.Move(0 ,1);
          if(kbhit()) // 判斷是否有按鍵按下，如果有則可能是旋轉或者加速按鍵
          {
            char ch = getch();
            switch(ch)
            {
                case 'a' :   cd.Move(-2 ,0) ; break;    //  向左移動一格
                case 'd' :   cd.Move(2 ,0) ;  break;    //  向右移動一格
                case 'w' :   cd.Transform() ; break;                   //  變換方格
                case 's' :   cd.Move(0 ,2) ; break;  //  急降方格
                case 'T' :   cd.Pause() ; break;
                case 'Q' :   Exit();  break;
                default :    break; // 如果都不是則不執行
             }
          }
          if(cd.Stop())  break;
       }
       cd.printBox();
       cd.Mark();
       Check(); // 檢查是否可以消除
    }
}
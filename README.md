# 2023-5-5
### Tetris

1. 資工3B 
1. 16 
1. 組長：辜震睿  組員：胡凱棠、陳柏諺
1. generateRandomShape()函數根據需要自訂每個形狀的表示方式，並返回一個隨機的形狀。   clearBoard()函數用於清空遊戲板。  drawBoard()函數在控制台上繪製遊戲板。  moveDown()函數負責將當前方塊向下移動一格，如果無法移動，則固定方塊在板上並進行相應處理。 moveLeft()和moveRight()函數用於將方塊向左或向右移動。 rotate()函數用於旋轉方塊。
  isValidMove()函數檢查方塊是否可以在給定的位置移動，並確保不會超出邊界或與其他固定方塊重疊。  placeShape()函數將方塊固定在板上。 clearLines()函數檢查並清除完整的行。  rotateShape()函數用於簡單的旋轉方塊，不考慮碰撞偵測。 getShapeBlock()函數根據形狀和座標返回相應的方塊。  run()函數是遊戲的主循環，它持續繪製遊戲板，處理使用者的按鍵輸入，並使方塊下降。
1. 《俄羅斯方塊》是由七種四格骨牌構成，全部都由四個方塊組成。開始時，一個隨機的方塊會從區域上方開始緩慢繼續落下。落下期間，玩家可以以90度為單位旋轉方塊，以格子為單位左右移動方塊，或讓方塊加速落下。當方塊下落到區域最下方或著落到其他方塊上無法再向下移動時，就會固定在該處，然後一個新的隨機的方塊會出現在區域上方開始落下。當區域中某一橫列的格子全部由方塊填滿時，則該列會被消除並成為玩家的得分。同時消除的行數越多，得分指數級上升。玩家在遊戲中的目的就是盡量得分。當固定的方塊堆到區域最頂端而無法消除層數時，遊戲就會結束。
1. 遊戲開始時，你會看到一個空的遊戲板。 
方塊從遊戲板的頂部開始下降，你的目標是在遊戲板上放置方塊，以創建完整的水平行，當一行被填滿時，它將被清除，並獲得分數。 使用鍵盤上的按鍵進行操作：
  'a'：向左移動方塊。
  'd'：向右移動方塊。
  's'：加快方塊下降速度。
  'w'：旋轉方塊。
  'q'：退出遊戲。
  方塊下降的速度會隨著時間的推移逐漸增加，讓遊戲變得更具挑戰性。

  如果無法將方塊放置在遊戲板上，即方塊無法再下降，遊戲結束，並顯示"Game Over!"。

  你可以通過放置方塊和清除行來獲得分數，嘗試在遊戲中獲得最高分。

1. 準備C++開發環境。 下載一個名為 "Tetris.cpp" 的檔案。  編譯程式。 開始遊戲。 結束遊戲。

1. ![image](https://github.com/alan9487/2021-3-2/assets/79899890/bcd4f85d-2f1d-4bd7-93ce-6921841bdfdd)  ![image](https://github.com/alan9487/2021-3-2/assets/79899890/a2a3526a-6827-419c-b316-5a5937080ac3) ![image](https://github.com/alan9487/2021-3-2/assets/79899890/32125ad7-1401-4ad4-baf9-d6432a3f2eaf) ![image](https://github.com/alan9487/2021-3-2/assets/79899890/27890799-97e4-44b6-8312-208e7d25a4b3) ![image](https://github.com/alan9487/2021-3-2/assets/79899890/d100d715-7011-48eb-a0b1-a0e10ef8b0b1)

1. 程式碼、ppt、uml皆為共同製作

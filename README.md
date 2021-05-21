# C_Consol_Game_2048
# 遊戲畫面
	![header image](./result.png)
# 開始遊戲
	步驟0、計數i=0。
	步驟1、亂數產生(x,y)座標，x範圍為0~3，y範圍為0~3。
	步驟2、處理目前方陣(x,y)數據，先檢查是否為0？
			是：將方陣(x,y)數值變為2，i+1。
			否：回到步驟1。
	步驟4、檢查i是否為2？
			是：完成開始遊戲。
			否：回到步驟1。

# 移動_上(下、左、右方法同「上」，僅方向不同)
	步驟0、(x,y)由(0,0)開始，計數i=0。
	步驟1、檢查y是否等於4？
			是：i+1，(x,y)=(0,0)，執行步驟2。
			否：執行步驟3。
	步驟2、檢查i是否等於4？
			是：執行步驟6。
否：執行步驟3。	
	步驟3、由上至下檢查方陣，若方格為0則下方方格向上移動，直到超出方陣。
	步驟4、	由上至下檢查方陣，若方陣(x,y)等於方陣(x+1,y)，則方陣(x,y)*2，方陣(x+1,y)設為0，直到超出方陣。
	步驟5、y+1，並回到步驟1。
	步驟6、判斷是否有作移動？
是：執行添加。
否：完成移動。

# 添加
	步驟0、亂數產生(x,y)座標，x範圍為0~3，y範圍為0~3。
	步驟1、處理目前方陣(x,y)數據，先檢查是否為0？
			是：將方陣(x,y)數值變為2或4。
			否：回到步驟0。

# 分數
	步驟0、判斷是否有2相同數合成？
			是：分數加上合成後結果。
			否：分數維持。

# 遊戲結束
	步驟0、判斷方陣內是否全不為0
			是：執行步驟1。
			否：遊戲結束。
	步驟1、判斷方陣內是否還能移動
			是：繼續遊戲。
			否：遊戲結束。

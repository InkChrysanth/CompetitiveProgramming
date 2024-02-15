/*
for i=1...n//n个物品
   for j=0...v //体积v
       if 第i件物品只有1个（01背包）
	       f[i][j]=max{f[i-1][j],f[i-1][j-v[i]]+w[i]} 
	    else if 第i件物品有无穷个（完全背包）
		    f[i][j]=max{f[i-1][j],f[i][j-v[i]]+w[i]}
	    else  (多重背包）
		  f[i][j]=max{f[i-1][j],f[i][j-k*v[i]]+k*w[i]}		 k为第i个物品的个数 
*/

/*
时间复杂度：O(n^3)空间复杂度：O(n^2) 
*/
for(int i=1;i<=n;i++) f[i][i]=0;
for(len=2;len<=n;len++) { //区间长度,阶段 
		for(int i=1;i<=n-len+1;i++)// 枚举区间起点 
		{
			int j=i+len-1;//区间终点（区间大小决定j的边界，已经合并几堆了剩下的从哪一堆开始） 			
			f[i][j]=INT_MAX;
			for(int k=i;k<=j-1;k++)
				f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]); //可能的决策，枚举中间点 
			f[i][j]+=s[j] -s[i-1] ; //需要预处理前缀和s 			
		}
	}
cout<<f[1][n]<<endl;

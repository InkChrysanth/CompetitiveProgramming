trajan(u) //
{
	DFN[u]=Low[u]=++Index//为节点u设定次序编号和Low初值
	Stack.push(u) //将结点U压入栈中 
	for each(u,v) in E //枚举每一条边 
	    if(visnotvisted) //如果结点V未被访问过 
	       tarjan(v) //继续向下找 
	       Low[u]=min(Low[u],Low[v])
	    else if(vinS)  //如果结点V还在栈内 
	       Low[u]=min(Low[u],DFN[v])
	if(DFN[u]==Low[u])  //如果结点u是强联通分量的根 
	repeat{
		v=S.pop //将v退栈，为该强联通分量中一个顶点 
		printv
		until(u==v)
	}    	    
}

void tarjan(int x){
	dfn[x]=low[x]=++tot;//入栈 dfn[]递归访问的顺序,low[]表示最少的访问时间（可以修正） 
	sta[++num]=x;insta[x]=true;
	for(int i=head[x];i;i=edge[i].next){
		if(!dfn[edge[i].to]){ //未被访问过 
			tarjan(dege[i].to);
			low[x]=min(low[x],low[edge[i].to]);
		}
		else if(insta[edge[i].to]) //还在栈内 
		    low[x]=min(low[x],dfn[edge[i].to]);
	}
	if(low[x]==dfn[x]){
		sa=0;//统计强联通分量中点的个数 
		do{	
		       sa++;
			    insta[sta[num--]]=false;
		   }while(x!=sta[num+1]) ; //弹栈
		
		if(sa==2){
			puts("2");exit(0);//到2就没必要继续了 
		}
		if(sa>1) ans=min(ans,sa);//取最小值 
	}
}

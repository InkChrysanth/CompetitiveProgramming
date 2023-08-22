//堆排序是不稳定排序 
//priority_queue<int>que//定义大根堆
//priority_queue<int ,vector<int> ,greater<int> >que 小根堆 
void put(int x){ //小根堆的数据插入 
	int p;
	len++;
	heap[len]=x;
	p=len;
	while(p!=1 && heap[p/2])>heap[p])
	{
		swap(heap[p],heap[p/2]);
		p/=2;
	}
}

int get(){ //取根结点
    int x=heap[1] ,p,q;//把根结点的值赋给变量x保存; 
    heap[1]=heap[len];len--;p=1; //把最后一个结点赋给根结点，数组长度减1 
    while(p*2<=len){ // 当p还有孩子的时候 
    	if(p*2+1>len ||heap[p*2]<heap[p*2+1]) //当P没有右孩子或者左孩子的值小于右孩子
		     q=p*2;//选左孩子 
		else
		     q=p*2+1; //选右孩子 
	    if(heap[q]<heap[p])	{ //父结点比子结点大，交换值 
	    	swap(heap[p],heap[q]);
	    	p=q; //把q传给p 
		}
		else 
		      return x; //已经满足小根堆定义退出函数	    
	}
    return x; //返回根结点	
}



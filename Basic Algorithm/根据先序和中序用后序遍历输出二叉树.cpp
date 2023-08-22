void p(int l1,int r1,int l2,int r2)
{
	int m=s2.find(s1[l1]);
	if(m>l2) p(l1+1,l1+m-l2,l2,m-1);
	if(m<r2) p(l1+m-l2+1,r1,m+1,r2);
	cout<<s1[l1];
} 

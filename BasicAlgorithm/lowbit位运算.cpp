/*
lowbit运算用来求出整数n二进制位上的最低位的1及后面的0 
lowbit(11100010000)=10000;


*/
int lowbit(n)
{
	// return (~n+1)&n;
	return (-n)&n;
}

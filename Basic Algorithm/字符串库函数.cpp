/*
字符串库函数 
*/
//从str逐个抽取出被" ,.-"这几个字符分隔的字串 
p=strtok(str," ,.-"); //请注意，" ,.-" 中的第一个字符是空格 
while(p!=NULL){      // 只要p不为NULL,就说明找到了一个子串 
	cout<<p<<endl;
	p=strtok(NULL ," ,.-"); //后续调用，第一个参数必须是NULL 
}

#include <iostream>
using namespace std;
int main()
{
	int ans=0;
	for(int i=1;i<=100000000;i++)
	{
		int cnt=0;//记录位数
		for(int j=i;j;j/=10)cnt++;
		if(cnt%2!=0)continue;//位数为奇数，则继续遍历
		int now=0,sum=0;//now记录遍历这个偶位数的第几位，sum记录位数 和
		for(int j=i;j;j/=10)
		{
			now++;
			if(now<=cnt/2)sum+=j%10;//位数小于一半   sum加上每一位的值
			else
			sum-=j%10;//判断方法 先把后半部分加起来，再减去前半部分 则结果为0
		}
		if(!sum)ans++;
	}
	
	cout<<ans;
	return 0;
}

//OJ-1028
//http://acm.hdu.edu.cn/showproblem.php?pid=1028
//Unibrighter
//2017-6-17 23:45:54
//思路很简单,每一个分解式看做n=i+remainingValue的拆分
//只要保证remainingValue拆解出来的每一个元素不要大于i就可以
//但是...
//用递归的解法会导致超时,虽然结果正确(N=120时需要大概7~8s...
//不过这样可以用打表的办法求解.

#include <stdio.h>

//using recursive strategy
int magic_func(int n,int componentUpperLimit)
{
	// which one is smaller, n or the components upper limit?
	int limit=componentUpperLimit<n?componentUpperLimit:n;
	
	if (0==limit||1==limit)
	{
		return 1;
	}
	
	//else
	int sum=0;

	for(int i=limit;i>0;i--)
	{
		int remainingValue=n-i;
		sum+=magic_func(remainingValue,i);
	}
	return sum;

}


int main()
{
#ifndef ONLINE_JUDGE
	//redirect the standard input to the file
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int n=-1;
	while(1==scanf("%d",&n))
	{	
		int result=magic_func(n,n);
		printf("%d\n",result);
	}

#ifndef  ONLINE_JUDGE
	//shut down the input
	fclose(stdin);
#endif
	return 0;
}
//***OJ-1029
//http://acm.hdu.edu.cn/showproblem.php?pid=1029
//Unibrighter
//2017-6-20 22:05:26

//此题很容易想到用空间换时间的策略来进行求解,对数组进行遍历即可
//在读入所有的数据之后,选择出value最大(其值按照要求应该是(N+1)/2)的index即可

#include <stdio.h>
#include <stdlib.h>
#define MAX_INDEX 999999

//int container[MAX_INDEX];

int main()
{
#ifndef ONLINE_JUDGE
	//redirect the standard input to the file
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	//main code goes here:
	int n=-1;//the odd number
	while(1==scanf("%d",&n))
	{
		int *container=malloc(MAX_INDEX*sizeof(int));
		int index=-1;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&index);
			container[index]++;
		}
		
		int maxCount=0;
		int maxIndex=-1;
		for(int i=0;i<MAX_INDEX;i++)
		{
			if(0==container[i])
				continue;
			if(maxCount<container[i])
			{
				maxCount=container[i];
				maxIndex=i;
			}
		}
		//printf("maxCount: %d\n",maxCount);
		printf("%d\n",maxIndex);
		free(container);
	}
	
	
   	//===Done
   	
#ifndef  ONLINE_JUDGE
	//shut down the input
	fclose(stdin);
#endif
   return 0;
}
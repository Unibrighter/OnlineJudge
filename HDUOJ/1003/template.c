//***OJ-1000
//http://acm.hdu.edu.cn/showproblem.php?pid=1000
//Unibrighter
//2017-6-16 23:55

#include <stdio.h>

int main()
{
#ifndef ONLINE_JUDGE
	//redirect the standard input to the file
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	//main code goes here:
	//===Start
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n", a + b);
   	//===Done
   	
#ifndef  ONLINE_JUDGE
	//shut down the input
	fclose(stdin);
#endif
   return 0;
}
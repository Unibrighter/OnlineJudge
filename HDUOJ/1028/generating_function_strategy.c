//OJ-1028
//http://acm.hdu.edu.cn/showproblem.php?pid=1028
//Unibrighter
//2017-6-17 23:45:54
//参考了各种方法后,应该考虑采用母函数,一次性计算到N的upperLimit
//然后每次读取,都从结果数组中取对应值即可

#include <stdio.h>

int c1[121];
//The result generating function factor
//here the index for the arrray means n in "x^n"
//the value means the factor an
//we can get a generating function using this array
//G(x)=a0 + a1*x^1 + a2*x^2 + a3*x^3 + a4*x^4 + a5*x^5 + a6*x^6 + a7*x^7 + ... 	- ①

int c2[121];
//临时数组,存储每一次多项式(一个多项式就是下面一个括号里的元素)相乘后的结果.
const int MAX_N=121;

//G(x)=	(1+x+X^2+x^3...)*
//		(1+x^2+x^4+X^6...)*
//		(1+x^3+x^6+x^9...)*														- ②
//		...

//using recursive strategy
int init()
{
	for(int i=0; i<MAX_N; i++)
	{
		c1[i]=1;//每一个i都用纯1来进行组合,可视作每一个数字都有至少一种"只包含1"的组合方案
		//或理解为第一个多项式,所有的系数暂时都是1(a1=a2=a3=...=1)
		c2[i]=0;//每一次做乘法的结果,也即每一次上一次的结果和新括号里面的内容相乘,作为临时变量
	}

	for(int i=2; i<MAX_N; i++)
	{

		for(int k=0; k<MAX_N; k++)
		{
			//对①的an遍历,k代表①中的an*x^n中的幂级数n
			for(int j=0; j+k<MAX_N; j+=i)
			{
				//对②的遍历,此时②中a1=a2=a3=...=1,j代表x^n中的幂级数n
				//两个幂级数的和,就是x^(k+j),其系数需要累加①中的an
				//比如i=3时,已经第三轮了,c2[7]=c2[1+6]=c2[4+3]
				//那么c2需要找c1[1]和c1[4]做累加
				c2[j+k]+=c1[k];
			}
		}
		//c2乘积的结果是新一轮的c1
		for(int k=0; k<MAX_N; k++)
		{
			c1[k]=c2[k];
			c2[k]=0;
		}
	}
}


int main()
{
#ifndef ONLINE_JUDGE
	//redirect the standard input to the file
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int n=-1;
	init();
	while(1==scanf("%d",&n))
	{
		int result=c1[n];
		printf("%d\n",result);
	}

#ifndef  ONLINE_JUDGE
	//shut down the input
	fclose(stdin);
#endif
	return 0;
}
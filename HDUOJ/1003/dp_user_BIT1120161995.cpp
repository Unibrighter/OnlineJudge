//http://acm.hdu.edu.cn/discuss/problem/post/reply.php?postid=31260&messageid=1&deep=0
//dp���̣�dp[i]=max(dp[i-1],dp[i-1]+v[i]) ; ��ʵ �ؼ��ڼ�����ʼλ�úͽ���λ��
#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std ;

struct node
{
	int start ;//��ʼλ�� 
	int end ;//����λ�� 
	int sum ;//�ӿ�ʼλ�õ�����λ�õļӺ� 
}a[100005] ;//Ӧ����dp��ʾ ̫��  ������ 
int v[100005] ;//��¼��������� 

int main()
{
	int t , n ;
	int i , j ;
	scanf("%d",&t) ;
	for(int k=1 ; k<=t ; k++)
	{
		printf("Case %d:\n",k) ;
		for(i=0 ; i<=100005 ; i++)
		   a[i].sum=0 ;
		scanf("%d",&n) ;
		int num=0 ;
		for(i=1 ; i<=n ; i++)
		  {
		   scanf("%d",&v[i]) ;
		   if(v[i]<0)num++ ;
		  }
		a[0].start=1 ;
		for(i=1 ; i<=n ; i++)
		 {
		 	if(a[i-1].sum+v[i]<v[i])
		 	  {
		 	  	a[i].sum=v[i] ;
		 	  	a[i].start=i ;
		 	  	a[i].end=i ;
			   }
			if(a[i-1].sum+v[i]>=v[i])
			  {
			  	a[i].sum=a[i-1].sum+v[i] ;
			  	a[i].end=i ;
			  	a[i].start=a[i-1].start ;
 			  }
		 }
	   if(n==1) printf("%d 1 1\n",v[1]) ;
	   else
	    {
	    	int ans=a[1].sum ;
	    	j=1 ;
	    	for(i=1 ; i<=n ; i++)
	    	 if(ans<a[i].sum)
			    {
			      ans=a[i].sum ;
				  j=i ;
				}
			printf("%d %d %d\n",a[j].sum,a[j].start,a[j].end) ;
		}
	  if(k<t)
	  printf("\n") ;
  	}
    return 0 ;
}
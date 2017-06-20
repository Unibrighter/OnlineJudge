- 此题还有更简便的解法
```
#include<cstdio>
#include<algorithm>
using namespace std;
int a[999999];
int main()
{
    int n,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
           scanf("%d",&a[i]);
        sort(a,a+n);
        j=(n+1)/2;
        printf("%d\n",a[j]);
    }
    return 0;
}
```

- 上述代码的思路是,读入n个数字后,进行排序
- 无论那个超过半数的value在排序结果中的任何地方,他们肯定是成"块"状出现在一起的.
- 既然是"块"作为group了,那么这个"块"由于占了size为n(元素个数为n)的数组一半还要多,所以无论排在哪里,sorted_array[midIndex]肯定在这个"块"内部
- 取出上述的sorted_array[midIndex]即可(其中midIndex=(n+1)/2)
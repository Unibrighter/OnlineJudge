- ���⻹�и����Ľⷨ
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

- ���������˼·��,����n�����ֺ�,��������
- �����Ǹ�����������value���������е��κεط�,���ǿ϶��ǳ�"��"״������һ���.
- ��Ȼ��"��"��Ϊgroup��,��ô���"��"����ռ��sizeΪn(Ԫ�ظ���Ϊn)������һ�뻹Ҫ��,����������������,sorted_array[midIndex]�϶������"��"�ڲ�
- ȡ��������sorted_array[midIndex]����(����midIndex=(n+1)/2)
- 动态规划
- 观察规律
- 总结规律
- 表达规律

- 也即整理dp方程：dp[i]=max(dp[i-1],dp[i-1]+v[i]) ; 其实 关键在记忆起始位置和结束位置
- check:
- http://acm.hdu.edu.cn/discuss/problem/post/reply.php?postid=31260&messageid=1&deep=0

- 另一个分治的思路
- 递归左边最大的,递归右边最大的.两者孰大?记作temp
- 然后按照中部的延展计算,记作lpos=>Lmaxn 和rpos=>Rmaxn
- 比较temp和上述延展计算的结果,返回整理结果.

- http://acm.hdu.edu.cn/discuss/problem/post/reply.php?postid=31858&messageid=1&deep=0
				

---


 如果是
1
4 -1 -4 -6 -9
答案应该是
Case 1:
-1 1 1

- 可否将输入理解为一个采样曲线?
- 只有两个归并后,得到一个正值,才能有资格参与进一步的归并

- 参考了网上各种思路, "最大子连续段的前面所有数的和以及后面所有数的和必小于0；"
- http://www.voidcn.com/blog/whu_zxl/article/p-3124108.html
- http://blog.csdn.net/zsdostar/article/details/51286482

```
关于本题有两个问题：

- 目前的轮子通过大于小于0来判定是否更新状态，那么如果整个数组全都是负数，或者正数数量等于1，那么结果是错的
- HDU1003的测试数据也没有考虑问题1，导致考虑不全的代码也能通过

下次复习这道题的时候解决这个问题，更新考虑更全面的代码。
```

- 开始的时候,自己单纯的用网络上的思路提交,没有注意maxSoFar的初始化问题(开始的版本初始化为0),也没有注意case 2(见注释中)sum!=0才能够进行赋值
- 这样的情况下,如果开始的input是负数,那么结果一直是maxSoFar=0

- 考虑了测试input最后4个case,修改之后AC.
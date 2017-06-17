//***OJ-1000
//http://acm.hdu.edu.cn/showproblem.php?pid=1000
//Unibrighter
//2017-6-16 23:55

#include<iostream>
#include<cstdio>
using namespace std;

int main(){
#ifndef ONLINE_JUDGE
	//redirect the standard input to the file
	freopen("input.txt","r",stdin);
	freopen("output.txt", "wt", stdout);
#endif

	//main code goes here:
	//===Start
	int a, b;
	cin >> a >> b;
	cout << a + b << endl;
	//===Done

#ifndef  ONLINE_JUDGE
	//shut down the input
	fclose(stdin);
#endif
	return 0;
}
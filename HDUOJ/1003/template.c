#include <stdio.h>

int main()
{
#ifndef ONLINE_JUDGE
	//redirect the standard input to the file
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	//the boundary for the sample input in description is -1000=<n<=1000
	const int MIN_INT=-9999;

	int lineCount=-1;
	int numberCountPerLine=-1;
	int subArrayStartIndex=0;
	int subArrayEndIndex=0;
	int candiateComponentIndex=0;

	int sum=0;//the candidate sum
	//when the iteration is over
	//it will holds the final result

	int maxSoFar=-9999;
	int sampleValue=0;

	//get the line count
	scanf("%d",&lineCount);
	for(int caseIndex=0; caseIndex<lineCount; caseIndex++)
	{
		scanf("%d",&numberCountPerLine);
		//initialize the values for a new round
		candiateComponentIndex=0;
		subArrayStartIndex=candiateComponentIndex;
		subArrayEndIndex=0;
		sum=0;
		maxSoFar=MIN_INT;

		for(int i=0; i<numberCountPerLine; i++)
		{
			scanf("%d",&sampleValue);
			sum+=sampleValue;

			//check if we should continue seeing the sub-array[candiateComponentIndex:j] read so far
			//as part of the candidate

			//case 1: the sum is still increasing
			if(sum>maxSoFar)
			{
				if(0!=sum)
				{
					maxSoFar=sum;
				}

				subArrayStartIndex=candiateComponentIndex;
				subArrayEndIndex=i;
			}

			//case 2: the sum becomes the burden
			//adding this sub-array[candiateComponentIndex:j] is no good to produce a better result
			//so we continue looking for the new possible candidate
			if(sum<0)
			{
				candiateComponentIndex=i+1;
				sum=0;
				//sum=MIN_INT;
			}

			//actually there is the third case, and that is
			//case 3:
			//the sum is decreasing, but still it might worth something as a prefix
			//when added to the following sub-arraies to get an overall better result
			//if (sum>0) {continue;}
		}
		printf("Case %d:\n",caseIndex+1);
		printf("%d %d %d\n",maxSoFar,subArrayStartIndex+1,subArrayEndIndex+1);
		if(lineCount!=caseIndex+1)
		{
			//format sucks
			printf("\n");
		}
	}

#ifndef  ONLINE_JUDGE
	//shut down the input
	fclose(stdin);
#endif
	return 0;
}





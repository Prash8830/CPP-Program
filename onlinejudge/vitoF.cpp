/* 12417328	10041	Vito's Family	Accepted	C++	0.095	2013-09-29 07:44:49 */
#include<stdio.h>
#define SWAP(x,y) { int temp=x;	x=y;	y=temp;	}
#define ABS(x) ( (x) >= 0 ? (x) : -(x) )
int main(){
	int t;
	scanf("%d",&t);
	for(int T=1;T<=t;T++){
		int n;
		int S[501];
		scanf("%d",&n);

		for(int i=1;i<=n;i++)
			scanf("%d",&S[i]);
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if( S[i]>S[j] )
					SWAP(S[i],S[j]);
		int M=(n+1)/2;
		int sum=0;
		for(int i=1;i<=n;i++)
			sum+=ABS(S[M]-S[i]);
		printf("%d\n",sum);
	}
	return 0;
}
//  Input:
// 2
// 2 2 4
// 3 2 4 6
//  Output:
// 2
// 4
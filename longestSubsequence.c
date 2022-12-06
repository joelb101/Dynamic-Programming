/*
--------------------------------------------------------------------------------------------------------------------
Longest Common Subsequence of Three Sequences Problem
--------------------------------------------------------------------------------------------------------------------
Compute the maximum length of a common subsequence of three sequences.
--------------------------------------------------------------------------------------------------------------------
Input: Three sequences.
--------------------------------------------------------------------------------------------------------------------
Output: The maximum length of a common subsequence.
--------------------------------------------------------------------------------------------------------------------
Input format. First line: n. Second line: a1, a2, . . . , an. Third line: m. Fourth
line: b1, b2, . . . , bm. Fifth line: l. Sixth line: c1, c2, . . . , cl .
--------------------------------------------------------------------------------------------------------------------
Output format. p.
--------------------------------------------------------------------------------------------------------------------
Constraints. 1 ≤ n, m, l ≤ 100; −109 ≤ ai , bi , ci ≤ 109.
--------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<stdlib.h>

int max(int a,int b){
	return (a>b)?a:b;
}

int longest_subsequence(int p[],int q[],int m,int n){
	int memtable[m+1][n+1];
		
	for(int i=0;i<=n;i++)
		memtable[0][i]=0;
	for(int i=0;i<=m;i++)
		memtable[i][0]=0;
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			memtable[i][j]=max(memtable[i-1][j],memtable[i][j-1]);
			if(p[i-1] == q[j-1])
				memtable[i][j]=memtable[i-1][j-1]+1;
		}
	}
	return memtable[m][n];
}

int main(void){
	int n,m;

	scanf("%d",&m);
	int p[m];

	for(int i=0;i<m;i++)
		scanf("%d",&p[i]);

	scanf("%d",&n);
	int q[n];

	for(int i=0;i<n;i++)
		scanf("%d",&q[i]);
		
	printf("%d\n",longest_subsequence(p,q,m,n));
	
	return 0;
}

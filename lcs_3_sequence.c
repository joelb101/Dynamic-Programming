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

int max(int a,int b,int c){
	return (a>b)?((a>c)?a:c):((b>c)?b:c);
}

int longest_subsequence(int p[],int q[],int r[],int m,int n,int l){
	int memtable[m+1][n+1][l+1];

	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=l;k++){
				memtable[i][j][k]=0;
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=l;k++){
				memtable[i][j][k]=max(memtable[i-1][j][k],memtable[i][j-1][k],memtable[i][j][k-1]);
				if(p[i-1] == q[j-1] && q[j-1] == r[k-1])
					memtable[i][j][k]=memtable[i-1][j-1][k-1]+1;
				}
		}
	}

	return memtable[m][n][l];
}

int main(void){
	int n,m,l;

	scanf("%d",&m);
	int p[m];

	for(int i=0;i<m;i++)
		scanf("%d",&p[i]);

	scanf("%d",&n);
	int q[n];

	for(int i=0;i<n;i++)
		scanf("%d",&q[i]);
		
	scanf("%d",&l);
	int r[l];

	for(int i=0;i<l;i++)
		scanf("%d",&r[i]);
		
	printf("%d\n",longest_subsequence(p,q,r,m,n,l));
	
	return 0;
}

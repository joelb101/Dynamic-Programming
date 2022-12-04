/*
--------------------------------------------------------------------------------------------------------------------
Edit Distance Problem
--------------------------------------------------------------------------------------------------------------------
Compute the edit distance between two strings.
--------------------------------------------------------------------------------------------------------------------
Input: Two strings.
--------------------------------------------------------------------------------------------------------------------
Output: The minimum number of single-symbol insertions, deletions, and substitutions to trans-
form one string into the other one.
--------------------------------------------------------------------------------------------------------------------
Input format. Two strings consisting of lower case Latin letters, each
on a separate line.
--------------------------------------------------------------------------------------------------------------------
Output format. The edit distance between them.
--------------------------------------------------------------------------------------------------------------------
Constraints. The length of both strings is at least 1 and at most 100.
--------------------------------------------------------------------------------------------------------------------
Sample 1.
--------------------------------------------------------------------------------------------------------------------
Input:
short
ports
--------------------------------------------------------------------------------------------------------------------
Output:
3
--------------------------------------------------------------------------------------------------------------------
The second string can be obtained from the first one by deleting s,
substituting h for p, and inserting s. This can be compactly visualized
by the following alignment.
s h o r t −
− p o r t s
--------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<string.h>

#define SIZE 100

int min(int p,int q,int r){
	return (p>q)?((q>r)?r:q):((p>r)?r:p);
}

int edit_distance(char *str1, char*str2){
	int n=strlen(str1);
	int m=strlen(str2);
	int memtable[m+1][n+1];

	for(int i=0;i<=n;i++)
		memtable[0][i]=i;
	for(int i=0;i<=m;i++)
		memtable[i][0]=i;
		
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(str1[j-1] != str2[i-1])
				memtable[i][j]=min(memtable[i][j-1],memtable[i-1][j-1],memtable[i-1][j]) +1;
			else
				memtable[i][j]=memtable[i-1][j-1];
		}
	}

	return memtable[m][n];
}
	
	
int main(void){
	char str1[SIZE+1],str2[SIZE+1];

	scanf("%s",str1);
	scanf("%s",str2);
	
	printf("%d\n",edit_distance(str1,str2));
	
	return 0;
}

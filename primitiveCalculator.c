/*
-------------------------------------------------------------------------------------------------------------------
Primitive Calculator Problem
-------------------------------------------------------------------------------------------------------------------
Find the minimum number of operations needed to get a positive integer n from 1 by using only
three operations: add 1, multiply by 2, and multiply by 3.
-------------------------------------------------------------------------------------------------------------------
Input: An integer n.
-------------------------------------------------------------------------------------------------------------------
Output: The minimum number of operations “+1”, “×2”, and “×3”
needed to get n from 1.
1
+1
×2
×3
-------------------------------------------------------------------------------------------------------------------
Input format. An integer n.
-------------------------------------------------------------------------------------------------------------------
Output format. In the first line, output the minimum number k of opera-
tions needed to get n from 1. In the second line, output a sequence of
intermediate numbers. That is, the second line should contain positive 
integers a0, a1, . . . , ak such that a0 = 1, ak = n and for all 1 ≤ i ≤ k,
ai is equal to either ai−1 + 1, 2ai−1, or 3ai−1. If there are many such
sequences, output any one of them.
-------------------------------------------------------------------------------------------------------------------
Constraints. 1 ≤ n ≤ 106.
-------------------------------------------------------------------------------------------------------------------
Sample 1.
Input:
1
Output:
0
1
-------------------------------------------------------------------------------------------------------------------
Sample 2.
Input:
96234
Output:
14
1 3 9 10 11 22 66 198 594 1782 5346 16038 16039 32078 96234
Another valid output in this case is “1 3 9 10 11 33 99 297 891 2673
8019 16038 16039 48117 96234”.
-------------------------------------------------------------------------------------------------------------------
*/

#include<stdio.h>

int min(int p,int q){
	return p>q?q:p;
}

void path(int DP_table[],int val,int k){
	if(val==1){
		printf("%d ",val);
		return;
	}
	if(val%3==0 && (DP_table[val/3]==(k-1) || k==1)){
		path(DP_table,val/3,--k);
		printf("%d ",val);
	}
	else if(val%2==0 && (DP_table[val/2]==(k-1) || k==1)){
		path(DP_table,val/2,--k);
		printf("%d ",val);
	}
	else{
		path(DP_table,val-1,--k);
		printf("%d ",val);
	}
}

int primitive_calc(int DP_table[],int val){
	
	for(int i=1;i<=val;i++){
		for(int j=1;j<=3;j++){
			switch(j){
				case 1:
						 if((i+1)>val)
						    continue;
						 if( DP_table[i+1] == 0)
						    DP_table[i+1]=DP_table[i]+1;
						 else
						    DP_table[i+1]=min(DP_table[i]+1,DP_table[i+1]);
						 break;
				case 2:
						 if((i*2)>val)
						    continue;
						 if( DP_table[i*2] == 0)
						    DP_table[i*2]=DP_table[i]+1;
						 else
						    DP_table[i*2]=min(DP_table[i]+1,DP_table[i*2]);
						 break;
				case 3:
						 if((i*3)>val)
						    continue;
						 if( DP_table[i*3] == 0)
						    DP_table[i*3]=DP_table[i]+1;
						 else
						    DP_table[i*3]=min(DP_table[i]+1,DP_table[i*3]);
						 break;
			}
		}
	}
	
	return DP_table[val];
}

int main(void){
	int val,k;
	scanf("%d",&val);
	
	int DP_table[val+1];
	
	for(int i=0;i<=val;i++)
		DP_table[i]=0;
	
	printf("%d\n",(k=primitive_calc(DP_table,val)));
	path(DP_table,val,k);
	printf("\n");
	
	return 0;
}

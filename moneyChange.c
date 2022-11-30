/*
--------------------------------------------------------------------------------------------------------------------
Money Change Again Problem
--------------------------------------------------------------------------------------------------------------------
Compute the minimum number of coins needed
to change the given value into coins with denominations 1, 3, and 4.
--------------------------------------------------------------------------------------------------------------------
Input: An integer money.
--------------------------------------------------------------------------------------------------------------------
Output: The minimum number
of coins with denominations 1, 3 and 4 that changes money.
--------------------------------------------------------------------------------------------------------------------
Input format. Integer money.
--------------------------------------------------------------------------------------------------------------------
Output format. The minimum number of coins with denominations 1, 3,
and 4 that changes money.
--------------------------------------------------------------------------------------------------------------------
Constraints. 1 ≤ money ≤ 103.
--------------------------------------------------------------------------------------------------------------------
*/

#include <stdio.h>

int min(int p, int q){
	return p>q?q:p;
}

int moneyChange(int money){
	int DP_table[money+1];
	int coins[]={1,3,4};
	
	for(int i=0;i<money;i++)
		DP_table[i]=0;
	for(int i=0;i<=money;i++){
		for(int j=0;j<3 && (i+coins[j])<=money;j++){
			if( DP_table[i+coins[j]] == 0)
				DP_table[i+coins[j]]=DP_table[i]+1;
			else
				DP_table[i+coins[j]]=min(DP_table[i+coins[j]] , DP_table[i] +1);
		}
	}
	
	return DP_table[money];
}

int main(void){
	int money;
	scanf("%d",&money);
	
	printf("%d\n",moneyChange(money));
	
	return 0;
}

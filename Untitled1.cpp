#include <stdio.h>

#define TOTAL_ELEMENT 10

struct DominanceStorage
{
	unsigned int rank;
	unsigned int count;
};
ss
struct DominanceStorage dominanceInfo[10];

int main()
{
    printf("Finding dominance rank & count\n");
    int objA[] = {8,4,6,7,3,4,8,2,6,3};
    int objB[] = {4,3,2,4,3,2,2,9,9,6};
    
    int i,j;
    for(i=0;i<TOTAL_ELEMENT;i++){
  		//check if this is the first time -> init the value
  		if(dominanceInfo[i].rank < 1){
  			//init
  			dominanceInfo[i].rank = 1;
  			dominanceInfo[i].count = 0;
		  }
		for(j=0;j<TOTAL_ELEMENT;j++){
			if(j>=i){
				// haven't been there yet     
				continue;
			}
			
			// Comparison phase (a current vs a prev && b current vs b prev)
			int totalWin = 0; // 0 by default (if total win == 1 means non-dominated , if total win >1 means win , else if total win === 0 means lose)
			int totalLose = 0;
			if(objA[i] > objA[j]){
				// If a current wins a prev
				totalWin++;
			}else if(objA[i] < objA[j]){
				totalLose++;
			}else{
				//draw
			}
			
			if(objB[i] < objB[j]){
				// If b current wins b prev
				totalWin++;
			}else if(objB[i] > objB[j]){
				totalLose++;
			}else{
				//draw
			}
			
			if((totalWin == 1 && totalLose == 1) || (totalWin == 0 && totalLose == 0)){
				//non dominated
				// do nothings
			}
			else if(totalWin >= 1){
				//wins
				
				// add count to winner
				dominanceInfo[i].count++;
				
				// add rank to the one that lose
				dominanceInfo[j].rank++;
			}
			else{
				// loses
				
				//add rank to loser
				dominanceInfo[i].rank++;
				
				//add count to the one wins
				dominanceInfo[j].count++;
			}
			
			//-----------------
		}
	}
	for(int x=0;x<TOTAL_ELEMENT;x++){
		printf("NO(%d) Rank:(%d), Count:(%d)\n", x+1, dominanceInfo[x].rank,dominanceInfo[x].count);
	}
    return 0;
}


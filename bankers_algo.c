#include<stdio.h>

void main() {
	int pro, rec, process[100], max[100][100], alloc[100][100], avail[100], need[100][100], finish[100], count = 0, f = 0, work[100], safe_seq[100], val = 0;
	printf("Enter the no.of processes : ");
	scanf("%d", &pro);
	printf("Enter the processes : ");
	for(int i=0; i<pro; i++) {
		scanf("%d", &process[i]);
	}
	printf("Enter the no.of resources : ");
	scanf("%d", &rec);
	printf("Enter the maximum resources : ");
	for(int i=0; i<pro; i++) {
		for(int j=0; j<rec; j++) {
			scanf("%d", &max[i][j]);
		}
	}
	printf("Enter the allocated resources : ");
	for(int i=0; i<pro; i++) {
		for(int j=0; j<rec; j++) {
			scanf("%d", &alloc[i][j]);
		}
	}
	printf("Enter the available resources : ");
	for(int i=0; i<rec; i++) {
		scanf("%d", &avail[i]);
	}
	for(int i=0; i<pro; i++) {
		finish[i] = 0;
	
		for(int j=0; j<rec; j++) {
			need[i][j] = max[i][j] - alloc[i][j];
		
		}
	}
	for(int j=0; j<pro; j++) {
		work[j] = avail[j];
	}
	for(int c=0; c<pro; c++) {
		for(int i=0; i<pro; i++) {
			if(finish[i] == 0) {
				count = 0;
				for(int j=0; j<rec; j++) {
					if(need[i][j] <= work[j]) {
						count = count + 1;
					}
				}
			
			if(count == rec) {
				finish[i] = 1;
				safe_seq[val] = i;
				val = val+1;
				for(int b=0; b<rec; b++) {
					work[b] = work[b] + alloc[i][b];
				}
			}
			f=0;
			for(int d=0; d<pro; d++) {
				if(finish[d] == 1) {
						f++;
						
				}
			}
			if(f==pro) {
				break;
			}
		}
		}
	}
	if(f!=pro) {
		printf("It is in deadlock state");
	}
	else {
		printf("It is in safe state");
		for (int i = 0; i < pro; i++) {
        		printf(" %d, ", safe_seq[i]);
		}
	}
}

				
					
				
				
		




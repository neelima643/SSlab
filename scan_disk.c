#include<stdio.h>
void main() {
	int n, head_arr[100], head, max, res_arr[100];
	printf("Enter the maximum no.of tracks : ");
	scanf("%d", &max);
	printf("Enter the no.of requests : ");
	scanf("%d", &n);
	printf("Enter the requests : ");
	for(int i=0; i<n; i++) {
		scanf("%d", &head_arr[i]);
	}
	printf("Enter the initial position of head : ");
	scanf("%d", &head);
	for(int i=0; i<n; i++) {
		for(int j = i+1; j<n; j++) {
			if(head_arr[i]>head_arr[j]) {
				int temp = head_arr[i];
				head_arr[i] = head_arr[j];
				head_arr[j] = temp;
			}
		}
	}
	printf("\nOrder of requests : ");
	for(int i=0; i<n; i++) {
		printf("%d, ", head_arr[i]);
	}
	n = n+1;
	head_arr[n-1] = max-1;
	int j=1;
	res_arr[0] = head;
	
	for(int i=0; i<n; i++) { 
		if(head_arr[i] > head) {
			res_arr[j] = head_arr[i];
			j++;
			
		}
	}
	
	int k = 0;
	
	for(int i=0;i<n; i++) { 
		if(head_arr[i] < head) {
			res_arr[n-k] = head_arr[i];
			k++;
		}
	}
	printf("\nOrder of execution : ");
	for(int i=0; i<n+1; i++) {
		printf("%d, ", res_arr[i]);
	}

	int track = (max-1-head) + (max-1-head_arr[0]);
	printf("\nNo.of track movements is : %d", track);

}
		

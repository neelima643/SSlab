#include<stdio.h>

void main() {
	
	int n, head_arr[100], head, track = 0;
	printf("Enter the no.of request : ");
	scanf("%d", &n);
	printf("Enter the requests : ");
	for(int i=0; i<n; i++) {
		scanf("%d", &head_arr[i]);
	}
	printf("Enter the initial position of head : ");
	scanf("%d", &head);
	printf("\nOrder of request is : ");
	for(int i = 0; i < n; i++) {
		printf("%d, ", head_arr[i]);
	}
	for(int i = 0 ; i < n; i++) {
		if(head_arr[i] >= head) {      // comparing head and request
			track = track + (head_arr[i] - head);	//each track movement  = request - head
			head = head_arr[i]; // update the value of head to next request
			
		}
		else {
			track = track + (head - head_arr[i]);
			head = head_arr[i];
		}

		
	}
	printf("\nOrder of executon is : ");
	for (int i = 0; i<n; i++) {
		printf("%d, ", head_arr[i]);
	}
	printf("\nTotal no.of track movements : %d", track);
}
			
	

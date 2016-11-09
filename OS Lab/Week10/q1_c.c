#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>

#define COUNT_SIZE 1000

void print_frames(int size, int * frames) {
	int i;

	for(i = 0; i < size; i++) {
		if(frames[i] != -1) {
			printf("%d", frames[i]);
		}
	}
	printf("\n");

}


int main() {

	int seq_length, number_frames;
		
	printf("Enter the length of reference string:\n>");
	scanf("%d", &seq_length);

	int sequence[seq_length];

	printf("Enter the number of frames:\n");
	scanf("%d", &number_frames);

	int frames[number_frames];

	int i, j;

	printf("Enter the referene string:\n");

	for(i = 0; i < seq_length; i++) {
		scanf("%d", &sequence[i]);
	}

	memset(frames, -1, sizeof(frames));

	

	int count[COUNT_SIZE];

	for(i = 0; i < COUNT_SIZE; i++) count[i] = 0;

	printf("Result:\n");

	int flag, min;

	for(i = 0; i < seq_length; i++) {

		if(i < 3) {
			frames[i] = sequence[i];
			count[frames[i]] += 1;
			continue;
		}
		
		flag = 1;
	
		for(j = 0; j < number_frames; j++) {
			if(frames[j] == sequence[i]) {
				flag = -1;
				break;
			}
		}
		
		if(flag == 1) {
			min = 0;
		
			for(j = min + 1; j < number_frames; j++) {
				if(count[frames[min]] > count[frames[j]]) {
					min = j;
				}
			}
	
			frames[min] = sequence[i];
			count[frames[min]] += 1;
		}
		else {
			count[frames[j]] += 1;
		}
		
		printf("Sequence: %d\n", sequence[i]);
		print_frames(number_frames, frames);
	}

	return 0;
}
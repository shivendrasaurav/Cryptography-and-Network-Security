#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
	int bsize, oprate, psize=5, i, j, flag=0;
	scanf("%d%d", &bsize, &oprate);
	int packets[psize], time[psize];
	srand(bsize);
	for(i=0; i<psize; i++){
		packets[i] = (rand()%10)*5;
		time[i]=rand()%10;
	}
	for(i=0; i<psize; i++){
		if(packets[i]>bsize){
			printf("\n\n==========================================================================");
			printf("\nPacket Size: %d\t Bucket Size: %d\t Rejected\n", packets[i], bsize);
		}
		else{
			printf("\n\n==========================================================================");
			printf("\nPacket Size: %d\t Bucket Size: %d\t Accepted\n", packets[i], bsize);
			for(j=time[i]; j>-1; j--){
				if(packets[i]>0 && j==0){
					printf("\nBytes left: %d\t Bytes Transmitted: %d\t Time Remaining: %d\t", packets[i], oprate, j);
					flag=1;
					break;
				}
				else if(packets[i]<=0){
					printf("\nBytes left: %d\t Bytes Transmitted: %d\t Time Remaining: %d\t", packets[i], oprate, j);
					packets[i]=0;
					flag=0;
					break;
				}
				else{
					printf("\nBytes left: %d\t Bytes Transmitted: %d\t Time Remaining: %d\t", packets[i], oprate, j);
					packets[i]-=oprate;
					flag=0;
				}
			}
			if(flag==0)
				printf("\nTransmission Over Succesfully");
			else
			printf("\nTimeout Error, Couldn't Transfer");
		}
	}
}

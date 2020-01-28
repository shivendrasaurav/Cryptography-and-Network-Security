#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char message[100], key[100]="1101", inp[100], CRC[100];

void xorfun(){																								//For XOR Operation
	int k;
	for (k = 1; k < strlen(key); k++)
		CRC[k] = ((CRC[k] == key[k]) ? '0' : '1');
}

void crc(){																								//For Calculating Remainder
	strcpy(CRC, "");
	int i, j, k;
	for (j = 0; j < strlen(key); j++)
		CRC[j] = message[j];

	do
	{
		if (CRC[0] == '1')
			xorfun();

		for (k = 0; k < (strlen(key) - 1); k++)
			CRC[k] = CRC[k + 1];

		CRC[k] = message[j++];
		printf("\nThe intermediate result is: %s", CRC);

	} while (j <= strlen(message) + strlen(key) - 1);
	
}

void append(){																								//For Generating Codeword
	int i, j=0;
	strcpy(inp, message);
	for(i=strlen(message); i<strlen(message) + strlen(key) - 1; i++){
		inp[i]=CRC[j];
		j++;
	}
}

void crcverify()																								//For Verification of CRC
{
  if(strcmp(message, inp)==0)
    printf("\nVerifiation Succesful");
  else
    printf("\nVerification Failed");
}

int main(){
	int i;
	printf("\nEnter Message To Send: ");
	scanf("%s", message);
	printf("\n%s", message);
	strcpy(inp, message);
	for(i=strlen(message); i<strlen(message) + strlen(key) -1 ; i++)
		inp[i]='0';
	printf("\n%s", inp);
	crc();	
	printf("\nThe CRC is : %s", CRC);
	append();
	printf("\n\nFinal Sent Message is : %s", inp);
	printf("\n\n\n\nEnter Received Message: ");
	scanf("%s", message);
	crc();
	crcverify();
}

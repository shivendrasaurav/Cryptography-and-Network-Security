#include<stdio.h>
#include<math.h>
#include<string.h>

int gcd(int m, int n){
	if(n==0)
		return m;
 	if(m<n)
	 	return gcd(n,m);
 	return gcd(n,m%n);
}

int main(){
	char msg[100], decmsg[100];
	double enc[100], dec[100], numsg[100];
	
	printf("Enter A Message: ");
	scanf("%s", msg);
	double p=11, q=3, n, e, z, d;
	n=p*q;
	z=(p-1)*(q-1);
	e=2;
	while(gcd(e, z)!=1){
		e++;
		if(e==z){
			printf("\nCouldn't Select an Integer E\n\nExiting Program\n");
		}
	}
	d =	fmod(pow(e, n-1), z);
	
	while((e*d)-1!=z){
		d++;
	}
	printf("%lf\n%lf\n%lf\n%lf\n%lf\n%lf\n", p, q, n, e, z, d);
	printf("\nPublic Key : (%lf, %lf)", n, e);
	printf("\nPrivate Key : (%lf, %lf)", n, d);
	
	int len=strlen(msg), i, j;
	
	for(i=0; i<len; i++){
		numsg[i] = msg[i] - 96;
		enc[i] = pow(numsg[i], e);
		enc[i] = fmod(enc[i], n);
	}

	printf("\n\nOriginal Message: %s", msg);

	printf("\n\nEncrypted Message: ");
	for(i=0; i<len; i++)
		printf("%lf, ", enc[i]);

	for(i=0; i<len; i++){
		dec[i] = pow(enc[i], d);
		dec[i] = fmod(dec[i], n);
		decmsg[i] = (dec[i] + 96);
	}
	
	printf("\n\nDecrypted Message: ");
	for(i=0; i<len; i++)
		printf("%lf, ", dec[i]);
		
	printf("\n\nDecrypted Message String: %s", decmsg);
}

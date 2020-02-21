#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;

struct library{
	int nb, su, sp;
	int bk[10];
};

int main(){
	int nob = 6, nol = 2, nod = 7, score = 0;
	int bookscore[nob] = {1, 2, 3, 6, 5, 4};
	library l[nol];
	l[0].nb = 5;
	l[0].su = 2;
	l[0].sp = 2;
	
	l[1].nb = 4;
	l[1].su = 3;
	l[1].sp = 1;
	
	float a=5, b=2;
	cout<<ceil(a/b);
}

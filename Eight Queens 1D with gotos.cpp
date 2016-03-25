#include<iostream>
#include <stdlib.h> 
using namespace std;

int main(){

	int q[8], c = 0, number = 1;
	q[0] = 0; //Sets a Queen into q subzero
	nc: c++;
	if(c==8) goto print;
	q[c]=-1;
	nr: q[c]++;

	if(q[c]==8) goto backtrack;

	for(int i = 0; i<c; i++)
 	   // if(q[i]==q[c]) goto nr;
	    if(q[i]==q[c] || c-i == abs(q[c]-q[i])) goto nr;
        
	goto nc;
	backtrack: c--;
	if(c==-1) return 0; // All 92 Solutions found
	goto nr;


	 print: cout<<"Solution number "<<number<<" is: \n";
 for (int i = 0; i < 8; i++){
	             cout <<q[i];
}
cout<<endl;
number++;
goto backtrack;
}

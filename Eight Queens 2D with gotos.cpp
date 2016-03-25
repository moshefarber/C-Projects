#include<iostream>
using namespace std;

int main(){
int b[8][8]={0}, r, c=0;
 int counter = 0; 
	b[0][0]=1;
	nc: c++; //Now pointing to col 1. nc for next column.

        if(c==8) goto print;
        
	r=-1; //Will guarantee that you see the top, not miss 0.
	nr: r++; //Next row, now pointing to col 1 row 0.

        if(r==8) goto backtrack;

	for(int i = 0; i<c; i++)
            if(b[r][i] == 1) goto nr;

	for(int i = 1; (r-i)>=0 && (c-i)>=0; i++) // up diagonal test
            if(b[r-i][c-i]==1) goto nr;
                                                  //cols have to move left
	for(int i = 1; (r+i)<8 && (c-i)>=0; i++)  // down diagonal test
            if(b[r+i][c-i]==1) goto nr;

 	b[r][c]=1; //Places down Queen
	goto nc;
	
	backtrack: c--; //goes back a column
	if(c==-1) return 0; //-1 means no more solutions
	r=0;
	while(b[r][c]==0) r++; //checking if no Queen

	b[r][c]=0;
	goto nr;

print:   
cout<<"Solution "<<++counter<<":"<<endl<<endl;
	 for(int x = 0; x < 8; x++){   
            for( int j = 0; j< 8; j++){
                          cout<<b[x][j];
}
cout<<endl;
	
}
cout<<endl;
goto backtrack;

}





#include<iostream>
#include<cstdlib>
#include<cmath>
using namespace std;

bool ok(int q[], int c){
   for(int i = 0; i<c; i++)
      if(q[c]==q[i] || (c-i)==abs(q[c]-q[i])){
        return false;
      }
   return true;
}

void backtrack(int &c){
     c--;
	if(c==-1){
           exit(1);           
        }
}

void print(int q[]){
     static int count = 0;
     cout<< "Solution number: "<<++count<<endl<<endl;
     
     for(int i = 0; i<8; i++)
         cout<<q[i];
      cout<< endl << endl;
}

int main(){
   int q[8]; //setup for 8 Queens
   q[0]=0; //Place down Queen in upper left corner
   int c = 1;

bool from_backtrack = false;

	while(true){
	     while(c<8){
        	  if(!from_backtrack)
			 q[c]=-1; //start at top
	
     	from_backtrack=false; //reset for the next time through
	
		while(q[c]<8){   //Place Queen in this column, or backtrack as reqd
          	q[c]++;
            
		//if row = 8, there is no valid spot in this column
		//so backtrack and continue the loop in prev column
	
		while(q[c]==8){
		backtrack(c);
		q[c]++;
       		}

		//if this position is ok, place the Queen
		//and move onto the next column,
		//otherwise keep looking in this column
		if(ok(q,c)){
	           break;
         	}
	       
	       }//end while 

 	 c++; //placed ok, move to next column
	}//end while true
                             
      //one complete solution found, print it
 	print(q);
	backtrack(c);
      //board completed, print it
      //find next place for Queen, going far back. backtrack
	from_backtrack = true;

}

}

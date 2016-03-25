#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

bool ok(int *q, int c){ //"q" is for the cross, "c" is for current box

     static int adj[8][5] = {
			    {-1},
			    {0,-1},
                            {0,-1},
                            {0,1,2,-1},
                            {0,1,3,-1},
                            {1,4,-1},
                            {2,3,4,-1},
                            {3,4,5,6,-1}}; //this sets up an adjacency table, -1 is stopper value
                                          
      for(int i = 0; i<c; i++)//these loops check for conflicts
	  if(q[i]== q[c]) return false;

      for(int i = 0; adj[c][i]!=-1; i++){
	  //1 is used to see if two numbers are next to each other
	  //for example, 4 and 5, gives you either 1, or -1, hence abs value
	  if(1 == abs(q[c] - q[adj[c][i]])) return false;
      }     
	     return true;
}



void print(int* q) {
	static int slns = 0;
	
	cout << "Solution #" << ++slns << "\n  "
		 << q[0] << ' ' << q[1] << '\n'
		 << q[2] << ' ' << q[3] << ' ' << q[4] << ' ' << q[5] << "\n  "
		 << q[6] << ' ' << q[7] << endl;
}


void move(int* q, int c){
	 if(c==8){ solution was found
	   print(q);
	   return;
	 }
         for(int j = 0; j<8; j++){
	    q[c]=j;
	    if(ok(q,c))
	    move(q,c+1); //then go to the next box of cross
        }
}


int main(){
	int q[8];
	move(q,0); //0 gets passed to c as the first value
}


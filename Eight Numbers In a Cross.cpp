#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

bool ok(int q[], int c){ //"q" is for the cross, "c" is for current box

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
	  //1 is used to see if two numbers are next to eachother
	  //for example, 4 and 5, gives you either 1, or -1, hence abs value
	  if(1 == abs(q[c] - q[adj[c][i]])) return false;
      }     
	     return true;
}
void backtrack(int &c){ //use same backtrack from 8 Queens
	c--;
	if(c==-1) exit(1);

}

void print(int q[]) {
	static int slns = 0;
	
	cout << "Solution #" << ++slns << "\n  "
		 << q[0] << ' ' << q[1] << '\n'
		 << q[2] << ' ' << q[3] << ' ' << q[4] << ' ' << q[5] << "\n  "
		 << q[6] << ' ' << q[7] << endl;
}

int main(){
	int q[8];
	int c = 0;
        bool from_backtrack = false;
	
	while(true){
	    while(c<8){
		if(!from_backtrack){
		   q[c] = -1;
                }
	      from_backtrack = false;

	     while(q[c]<8){
	        q[c]++;
	        if(q[c] == 8){
	          backtrack(c);
	          continue;
	        }
	       
	     
	          if(ok(q,c))
	          break;   
	   }
	  c++;
        }
	print(q);
	backtrack(c);
	from_backtrack = true;
  
    }
}


	
	
	


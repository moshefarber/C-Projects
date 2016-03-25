#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

bool ok(int q[], int col){
	int nm = col;   //nm stands for  "new man"
	int nw = q[nm]; //nw stands for "new woman"
	//setting up preference table
	int mp[3][3] = { {0,2,1}, {0,2,1}, {1,2,0} };
	int wp[3][3] = { {2,1,0}, {0,1,2}, {2,0,1} };


	for( int i = 0; i < col; i++){
	    int cm = i; //current man
	    int cw = q[cm]; //current woman
	 if( q[col] == q[i])
	   return false; //checks if new woman was assigned to a man

	 if(mp[cm][nw] < mp[cm][cw] && wp[nw][cm] < wp[nw][nm])
           return false; 
    
         if(wp[cw][nm] < wp[cw][cm] && mp[nm][cw] < mp[nm][nw])
           return false;  
		 
       }//for


   return true;
}//ok

 

void backtrack( int &col){
	col--;
	if( col == -1){
	   exit(1);
        }
}


void print(int q[]){
	static short slns = 0;

	cout<< "Match # " << slns++ << ":\n"
		<< "Man\tWoman" << endl;
	for ( int i = 0; i < 3; i++){
		cout << i << '\t' << q[i] << endl;
	}
	cout << endl;
}//print


int main(){
	int q[3]; 
	q[0] = 0; 
	int col = 1;

    bool from_backtrack = false;
 
	while(true){
	  while(col < 3){
	     if(!from_backtrack)
            q[col] = -1;
                  
         from_backtrack = false;
	     	   	    
             while(q[col] < 3){
                 q[col]++;
	     if(q[col] == 3){
                backtrack(col);
	        continue;
             }//if 
             
	       if(ok(q,col))
	          break;
          
	        }//while(q[col]

          col++;

           }//while(col < 3)

	print(q);
	backtrack(col);
	from_backtrack = true;

     }//while true
}//main



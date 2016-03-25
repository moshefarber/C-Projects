#include <iostream> 
#include <cstdlib>
#include <cmath>

using namespace std; 

bool ok(int q[], int col){ 
   for(int i = 0; i < col; ++i) 
      if(q[col]==q[i] || (col-i)==abs(q[col]-q[i])) return false; 
     
    return true; 
}

void backtrack(int &c){
     c--;                           
}

int num_solutions(int n) {
	int *q = new int[n]; //allocate memory
	q[0] = 0;
	int c = 1;
	int count = 0;
	bool from_backtrack = false;
	while(true){
	   while(c < n){
	      if(!from_backtrack)
	        q[c] = -1; //start back at top
	     
	     from_backtrack = false; //reset for next time through
	
	     while(q[c] < n){ //place Queen, or backtrack
	        q[c]++;
    	     //if row = n, there is no valid spot in column
	     //so backtrack and continue in previous column
	
	     while(q[c]==n){
	     backtrack(c);
	     if(c==-1) return count;
	     q[c]++;
	     }//end while(q[c]==n)

	     if(ok(q,c))
	        break;
             
	    }//end while(q[c]<n)
           c++;	

         }//end while(c<n)

	count++;
	backtrack(c);
	if(c==-1) return count;
	from_backtrack = true;

        }//end while(true)

	delete []q;//dealocate memory

}//num_solutions

/*!!!DO NOT CHANGE ANYTHING IN MAIN()!!!*/
int main(){ 
	int n;
	cout << "How many queens? ";
	cin >> n;
	
	for (int i = 1; i <= n; ++i) {
		cout << "There is/are " << num_solutions(i) << " solution(s) to the " << i << " Queen(s) problem." << endl; 
	}
	
	return 0;
}

#include<iostream>
using namespace std;

const int rows = 5;//setting up a 2d array of 5*6
const int cols = 6;
int trace[rows][cols];
int cost(int i, int j){ // i is the row, j is the column
   int weight[rows][cols] = {
	{3,4,1,2,8,6},
	{6,1,8,2,7,4},
	{5,9,3,9,9,5},
	{8,4,1,3,2,6},
	{3,7,2,8,6,4}};

   if(j==0){ //base case for recursion - on first column
    return weight[i][0];
   }

   static int memo[rows][cols] = { //memoization for first calculation calls
        {3,0,0,0,0,0},
        {6,0,0,0,0,0},
        {5,0,0,0,0,0},
        {8,0,0,0,0,0},
        {3,0,0,0,0,0}
    };
	if(memo[i][j] > 0){
	cout<<memo[0][0];
           return memo[i][j];
	}

   //recursive calls for feeder boxes 
   int left = weight[i][j] + cost(i, j-1);
   int up = weight[i][j] + cost((i-1 + rows) % rows, j-1); //mod for wraparound
   int down = weight[i][j] + cost((i+1) % rows, j-1); //wrap allows the box to go out one side, in the other
    //now find the value of the shortest path through cell (i,j)
   int min = left;
      
   if(up < min)
	min = up;

   if(down < min)
	min = down;
   
  //now we insert the values into the trace table and use tie breaking
   if (left == min) 
	trace[i][j] = i;
   
   else if(up == min)
	trace[i][j] = (i-1+rows) % rows;

   else if(down == min)
	trace[i][j] =(i+1) % rows;

   return min;
}

int main(){
   int ex[rows];
   int min_row = 0;
   //get the shortest path out of each cell on the right
   for( int i = 0; i<rows; i++){
	ex[i] = cost(i,cols-1);
   }

   //now find the smallest of them
   int min = ex[0];

   for(int i = 0; i<rows; i++){
      if(ex[i] < min){
	min = ex[i];
	min_row = i;
      }
   }
   cout<<"The shortest path is of length: "<<min<<endl;

   int path[cols]; //array to store the path taken
  
   for(int i = cols-1; i>=0; i--){ //working backwards        
       path[i] = min_row;
      min_row = trace[min_row][i]; //get the value of tile from previous column of trace table     
   }
   
   //printing the path from left to right
   cout<<endl<<"The path taken is: ";
   for(int i = 0; i<=cols-1; i++){
	 cout<<path[i]<<" ";
   }

   cout<<endl<<endl<<"Printing the actual trace table:"<<endl;
   for(int i = 0; i <5; i++){
       for(int j = 0; j < 6; j++){
          cout<<trace[i][j];
       }
       cout<<endl;
   }

return 0;
}//main

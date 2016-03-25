#include<iostream>
using namespace std;

const int rows = 5;
const int cols = 6;
int trace[rows][cols];

int cost[rows][cols] = {
	{3,0,0,0,0,0},
	{6,0,0,0,0,0},
	{5,0,0,0,0,0},
	{8,0,0,0,0,0},
	{3,0,0,0,0,0}};

   int weight[rows][cols] = {
	{3,4,1,2,8,6},
	{6,1,8,2,7,4},
	{5,9,3,9,9,5},
	{8,4,1,3,2,6},
	{3,7,2,8,6,4}};

int main(){
   int left, up, down; //tiles from feeder tiles
    
   //a double for loop, starts at first row of the second column, and moves down along tiles
   for(int j = 1; j <= cols-1; j++){
       for(int i = 0; i <= rows-1; i++){
   
   //defining the directions of filling the cost table	
           left = cost[i][j-1];
           up   = cost[(i-1 + rows) % rows][j-1]; //mod for wraparound
           down = cost[(i+1) % rows][j-1]; 

   //now determine what tile was the minimum cost
           int  min = left;
      
           if(up < min)
	     min = up;

           if(down < min)
	     min = down;

   //now fill the trace table

           if(left == min)
              trace[i][j] = i;

      else if(up == min)
              trace[i][j] = (i-1+rows) % rows;

      else if(down == min)
              trace[i][j] = (i+1) % rows;
 

   //now that we have determined the cheapest tile, update the cost table
            cost[i][j] = weight[i][j] + min;
  
      }

   }//end double for loop


   //printing the completed cost table 
   cout<<"The cost table is: "<<endl;
   for( int i = 0; i < 5; i++){
       for(int j = 0; j < 6; j++){

           cout<<cost[i][j]<<", ";
       }
      cout<<endl;
   } 


   int ex[rows];
   int min_row = 0;
   //get the shortest path out of each cell on the right
   for( int i = 0; i<rows; i++){
	ex[i] = cost[i][cols-1];
   }

   //now find the smallest of them
   int min = ex[0];

   for(int i = 0; i<rows; i++){
      if(ex[i] < min){
	min = ex[i];
	min_row = i;
      }
   }
   cout<<endl<<"The shortest path is of length: "<<min<<endl;

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

#include<iostream>
#include<cmath>
using namespace std;

bool ok(int board[][8]){
    for(int c = 7; c>=0; c--){ //first checks column 7, row 0
                               //in reality, column 8, row 1
        int r = 0;
        while(board[r][c]!=1)  //search to find where 1 is sitting
             r++;
        for(int i = 1; i<=c; i++){
            if(board[r][c-i]==1) //column test
              return false;     //board conflict
            
	    if((r-i)>=0 && board[r-i][c-i]==1)  //up diagonal test
              return false;    //board conflict
            
            if((r+i)<=7 && board[r+i][c-i]==1) //down diagonal test  
              return false;    //board conflict
        }
     }
return true; //its only true if 8 Queens are placed correctly   
}

void print(int board[][8]){
           for(int i = 0; i<8; i++){
               for(int j = 0; j<8; j++){
                   cout<< board[i][j];
               }
           cout<< endl;
           }
}
int main(){
int board[8][8]={0};
int count = 1;

	for(int i0 = 0; i0<8; i0++)
            for(int i1 = 0; i1<8; i1++)
                for(int i2 = 0; i2<8; i2++)
                    for(int i3 = 0; i3<8; i3++)
		        for(int i4 = 0; i4<8; i4++)
	                    for(int i5 = 0; i5<8; i5++)
				for(int i6 = 0; i6<8; i6++)
	   			    for(int i7 = 0; i7<8;i7++){
 
//index i7 will loop as the inner loop, constantly moving down, then resetting
//each time i7 goes to the top, the next column moves down one move                              
                                      board[i0][0]=1;
				      board[i1][1]=1;
				      board[i2][2]=1;
				      board[i3][3]=1;
				      board[i4][4]=1;
				      board[i5][5]=1;
                                      board[i6][6]=1;
				      board[i7][7]=1;
                            
                                    if(ok(board)){
                                    cout<<"Solution number: "<< count <<endl;
				    print(board);
	                            count++;
                                    }
                                    //reset config
                                     board[i0][0]=0;
			      	     board[i1][1]=0;
				     board[i2][2]=0;
				     board[i3][3]=0;
				     board[i4][4]=0;
			             board[i5][5]=0;
				     board[i6][6]=0;
				     board[i7][7]=0;       
 
                                  }

return 0;
}

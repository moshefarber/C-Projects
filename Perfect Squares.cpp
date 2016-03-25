#include<iostream>
#include<climits>
#include<cmath>

using namespace std;

int main(){
   int  i, j;

        for(int x = 1; x < sqrt(INT_MAX); x++){
             i = x*x;
               j = i%10;
                 if(j % 2 == 1){
                    i = i/10;
                       j = i%10;
                    if(j % 2 == 1){
                       cout<<x*x;
                    }
                 }

      }
        cout<< "I can't find it!\n";


return 0;
}


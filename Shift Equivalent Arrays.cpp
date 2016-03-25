#include <iostream>

using namespace std;
bool match(int a[], int b[], int n);
bool equivalent(int a[], int b[], int n);
int offset;
int main() {
	cout << boolalpha; //to make cout print true/false instead of 1/0

	int a1[5] = {1, 2, 3, 4, 5};
	int a2[5] = {4, 5, 1, 2, 3};
	cout << "a1[] == a2[]? " << equivalent(a1, a2, 5) << endl;
	cout << "a2[] == a1[]? " << equivalent(a2, a1, 5) << endl;
	
	int a3[] = {4, 6, 3, -4, 5, 2, 5, 8};
	int a4[] = {2, 5, 8, 4, 6, 3, -4, 5};
	cout << "a3[] == a4[]? " << equivalent(a3, a4, 8) << endl;
	cout << "a4[] == a3[]? " << equivalent(a4, a3, 8) << endl;
	
	int a5[] = {5, 4, 2, 1};
	int a6[] = {1, 2, 4, 5};
	cout << "a5[] == a6[]? " << equivalent(a5, a6, 4) << endl;
	cout << "a6[] == a5[]? " << equivalent(a6, a5, 4) << endl;
	
	int a7[] = {4, 5, 4, 3, 2, 7};
	int a8[] = {5, 4, 3, 2, 7, 4};
	cout << "a7[] == a8[]? " << equivalent(a7, a8, 6) << endl;
	cout << "a8[] == a7[]? " << equivalent(a8, a7, 6) << endl;
	
	int a9[] = {1,2,1,2,1};
	int a10[] = {1,1,2,1,2};
	cout << "a9[] == a10[]? " << equivalent(a9, a10, 5) << endl;
	cout << "a10[] == a9[]? " << equivalent(a10, a9, 5) << endl;
	
	int a11[] = {1,1,1,0};
	int a12[] = {0,1,1,1};
	cout << "a11[] == a12[]? " << equivalent(a11, a12, 4) << endl;
	cout << "a12[] == a11[]? " << equivalent(a12, a11, 4) << endl;
	
	return 0;
}

bool equivalent(int a[], int b[], int n) {
       for(int i = 0; i < n; i++){
           if(a[0]==b[i]){
              offset = i;
                if(match(a,b,n))
                   return true;
           }            
       }
return false;
}

bool match(int a[], int b[], int n){
	 for(int c=0;c<n;c++){ 
             if(a[c]!= b[(offset+c)%n]){                                                       return  false;
             }   
         }   
 return true;
}

#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int> t[3]; //vector creating 3 towers 
	int n; //number of rings
	int candidate, to, from; //where the rings are moving to
	int move = 0; //move counter

	cout << "How many rings do you want for the Towers of Hanoi?"<<endl;
	cin >> n;
	
	//now we have to initialize the three towers
	for(int i = n+1; i >= 1; i--)
	    t[0].push_back(i);
	
	t[1].push_back(n+1);
	t[2].push_back(n+1);

	//then go through the process if n was odd
    if(n%2 ==1){
     from = 0;
     to = 1;
     candidate = 1;
	
	while(t[1].size() < n+1){ //there are rings to transfer to tower B
	   cout<< "Move number " <<++move << ": Transfer ring " << candidate <<
	      " from tower " << char(from+65) << " to tower " << char(to+65)
                   <<endl;
	//char 65 is part of ASCII so it gets A,B, or C
	//now move the rings around
	t[to].push_back(t[from].back()); //push top ring from "from" to "to"
	t[from].pop_back(); //removes ring from "from" tower, decreases by 1

	if(t[(to + 1) % 3].back() < t[(to + 2) % 3].back())
	   from = (to + 1) % 3;
	
	else 
    	   from = (to + 2) % 3;

	//move onto the next tower
	if(t[(from + 1) % 3].back() > t[(from)].back())
	   to = (from + 1) % 3;
	else
	   to = (from + 2) % 3;

	//now get next candidate
	candidate = t[from].back();
	} //end while
    } //end if n was odd

	//go through similar process if n was even
    if(n%2 == 0){
     int candidate = 1;
     int from = 0;
     int to = 2;
         
	 while(t[1].size() < n+1){ //there are rings to transfer to tower B
           cout<< "Move number " <<++move << ": Transfer ring " << candidate <<
              " from tower " << char(from+65) << " to tower " << char(to+65)
                   <<endl;

	t[to].push_back(t[from].back());
	t[from].pop_back();

	if(t[(to + 2) % 3].back() < t[(to + 1) % 3].back())
	   from = (to + 2) % 3;
	else 
	   from = (to + 1) % 3;

	if(t[(from + 2) % 3].back() > t[(from)].back())
	   to = (from + 2) % 3;
	else
	   to = (from + 1) % 3;
	

  	candidate = t[from].back();

	} //end while
    } //end if n was even
return 0;
}

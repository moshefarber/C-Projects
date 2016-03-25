//Rat Class (for rational numbers)
//adding, subtracting, ect...

#include<iostream>
using namespace std;

class Rat{
private:
   int n; //numerator
   int d; //denominator

public:
   //make public constructors
   Rat(){ //a default constructor (no argument)
      n = 0;
      d = 1;
   }

   Rat(int i, int j){ // 2 param constructor
      n = i;
      d = j;
   }

   Rat(int i){ //single param conversion constructor ie 3 turns into 3/1
      n = i;
      d = 1;
   }

   //accessor functions or known as member functions
   int getN(){
     return n;
   }
   int getD(){
     return d;
   }

   void setN(int i){
     n = i;
   }
   void setD(int i){
     d = i;;
   }

   //arrithmetic operators (overloaded)

   Rat operator+(Rat r){
    Rat t; //temp variable
    t.n = n*r.d + d*r.n;  //numerator
    t.d = d*r.d;  //denom
    lowestTerms(t);
   return t; //add two rats, get back one sum
   }

   Rat operator-(Rat r){
    Rat t;
    t.n = n*r.d - d*r.n;
    t.d = d*r.d;
   
    lowestTerms(t);
   return t;
   }

   Rat operator*(Rat r){
    Rat t;
    t.n = n*r.n;
    t.d = d*r.d;

    lowestTerms(t);
   return t;
   }

   Rat operator/(Rat r){
    Rat t;
    t.n = n*r.d;
    t.d = d*r.n;

    lowestTerms(t);
   return t;
   } 


   int gcd(int x, int y) {
        if(y==0)
	 return x;
        
         return gcd(y, x%y);
   }
    
   void lowestTerms(Rat &t) {
       int x = t.gcd(t.getN(), t.getD());
        
        t.n/=x;
        t.d/=x;
        
       if (t.n > t.d){
         cout <<t.n/t.d <<" and ";
         t.n=t.n%t.d;
       }
       
    }
   //two overloaded input/output operators
   friend ostream& operator<<(ostream& os, Rat r);
   friend istream& operator>>(istream& is, Rat& r);

}; //end Rat

  //know that the  operator<<() is  not a member function, but since it was
  //declared a friend of Rat, it has access to the private parts of the Rat
  //this is called "operator left shift"
   ostream& operator<<(ostream& os, Rat r){

      if(r.n < r.d){ // if it is not an improper fraction
        os<<r.n<<"/"<<r.d<<endl;
      }
      else{ //if its improper, we need to conver to mixed number
       
      int left = r.n / r.d;
      int right = r.n % r.d;
      
      os<<left<<" and "<<right<<" / "<<r.d<<endl;
      }
	return os;
   }

  //also know that the operator>>() is not a member function, but since
  //it was declared a friend of Rat, it has access to the private parts
  //of the rat
  //This is called "operator right shift"

   istream& operator>>(istream& is, Rat& r){
	is>>r.n>>r.d;
	return is;
   }

int main() {
	Rat r1(5, 2), r2(3, 2);
	
	cout << "r1: " << r1 << endl;
	cout << "r2: " << r2 << endl;
	cout << "r1 + r2: " << r1 + r2 << endl;
	cout << "r1 - r2: " << r1 - r2 << endl;
	cout << "r1 * r2: " << r1 * r2 << endl;
	cout << "r1 / r2: " << r1 / r2 << endl;
	cout << endl;
	
	r1 = r2;
	r2 = r1 * r2;
	
	cout << "r1: " << r1 << endl;
	cout << "r2: " << r2 << endl;
	cout << "r1 + r2: " << r1 + r2 << endl;
	cout << "r1 - r2: " << r1 - r2 << endl;
	cout << "r1 * r2: " << r1 * r2 << endl;
	cout << "r1 / r2: " << r1 / r2 << endl;
	cout << endl;
	
	r1 = r2 + r1 * r2 / r1;
	r2 = r2 + r1 * r2 / r1;
	
	cout << "r1: " << r1 << endl;
	cout << "r2: " << r2 << endl;
	cout << "r1 + r2: " << r1 + r2 << endl;
	cout << "r1 - r2: " << r1 - r2 << endl;
	cout << "r1 * r2: " << r1 * r2 << endl;
	cout << "r1 / r2: " << r1 / r2 << endl;
	
	return 0;
}

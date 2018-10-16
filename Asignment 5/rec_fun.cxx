//SHAMIM BABUL


#include "rec_fun.h"


void binary_print(ostream& outs, unsigned int n){
  if(n==0) outs<<"0"; //base case, stopping case
  if(n==1) outs<<"1"; //base case, stopping case
  if(n>1){            // recursive case
    binary_print(outs,n/2);
    outs<<n%2;

  }
}
// Precondition: m <= n
  // Postcondition: The function has printed a pattern of 2*(n-m+1) lines
  // to the output stream outs. The first line contains m asterisks, the next
  // line contains m+1 asterisks, and so on up to a line with n asterisks.
  // Then the pattern is repeated backwards, going n back down to m.
  /* Example output:
     triangle(cout, 3, 5) will print this to cout:
     ***
     ****
     *****
     *****
     ****
     ***
  */
void triangle(ostream& outs, unsigned int m, unsigned int n){
  assert(m<=n);
  for(unsigned int i=0;i!=m;i++) outs<<"*"; // It will always print m * in the
    outs<<"\n";                             //to have the 2*(n-m+1) lines
  if(m==n){                                 // the base and the stopping case
    for(unsigned int i=0;i!=m;i++) outs<<"*";
    outs<<"\n";
  }
  else{                                     // recursive case
    triangle(outs,m+1,n);         // will add until it reaches n,(stopping case)
    for(unsigned int i=0;i!=m;i++) outs<<"*"; // this will be printed once stopping
      outs<<"\n";                             // case has reached.
  }
}
 // Precondition: If x is zero, then n must be positive.
// Postcondition: The value returned is x raised to the power n.
double pow(double x, int n){
  if(x==0) {
    assert(n>0);
    return 0;
  }
  else if(n<0) return 1/pow(x,-n);
  else if(n==0) return 1;         // base case
  else if(n%2==0) {    // in order to decrase  the Big O, n must be divisble by 2
     double half=pow(x,n/2); // in order to decease the Big O, we divide it by 2
     return half*half;      //since  x^2n = x^n  x^n, we can just multiply the halves
   }
  else {          // if it is not divisble by 2, we then subtract 1 to make it even.
    return x*pow(x,n-1);
  }
}
// precondition: m <=n;
//postcondition: print out the above pattern by calling number from m to n
void indented_sentences(size_t m, size_t n){
  assert(m<=n);
  for(size_t i=0;i!=m;i++) cout<<" "; // this will make the space equal to m;
  cout<<"This was written by calling number "<<m<<"\n"; //after intended it will print
  if(m==n){                 // the base and the stopping case
      for(size_t i=0;i!=m;i++) cout<<" ";
      cout<<"This was ALSO  written by calling number "<<m<<"\n";
    }
  else{                   // recursive case
    indented_sentences(m+1,n);
    for(size_t i=0;i!=m;i++) cout<<" ";
      cout<<"This was ALSO written by calling number "<<m<<"\n";
  }
}

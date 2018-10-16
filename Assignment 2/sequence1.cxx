//Shamim Babul 
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string.h>
#include "sequence1.h"
#include <cassert>
using namespace std;
namespace main_savitch_3 {
  sequence::sequence(){
    used=0;
    current_i=0;

  }
  void sequence::start (){
    current_i=0;
  }

  void sequence::advance(){
    assert(is_item());
    current_i+=1;
      }

  void sequence::insert(const value_type& entry){
    assert(size()<CAPACITY);
    if(!is_item()) current_i=0;
    for(size_type i=used;i!=current_i;i--){
      data[i]=data[i-1];
    }
    data[current_i]=entry;
    used+=1;
  }

  void sequence::attach(const value_type& entry){
    assert(size()<CAPACITY);
    if(!is_item()) current_i=used-1;
    else{
    for(size_type i=used;i!=current_i+1;i--){
      data[i]=data[i-1];
    }
  }
    current_i+=1;
    data[current_i]=entry;
    used+=1;

  }


   void sequence::remove_current( ){
     assert(is_item());
     for(size_type i=current_i+1;i!=used;i++){
       data[i-1]=data[i];
     }
     used-=1;
   }


// CONSTANT MEMBER FUNCTIONS for the sequence class
  sequence::size_type sequence::size( ) const{
    sequence::size_type ret=used;
    return ret;
  }

  bool sequence::is_item( ) const{
    return(current_i<used);
  }

  sequence::value_type sequence::current( ) const{
    assert (is_item());

    sequence::size_type ret=current_i;
    return data[ret];
    }
}

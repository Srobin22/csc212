//Shamim Babul
// Invariant of the Sequence 2.
//  1. The total number of items stored on sequence class is stored in private
//    member variable used.
//  2.  The items are stored on a partially filled dynamic array called data
//    (a private member variable), which is a pointer to a value_type items.
//  CONSTRUCTOR will generate a new allocation of a value_type array, and a
//  larger array can be allocated as needed by the programs.
//  3. When the size of the dynamic array reaches the capacity, activating the
//    insert or attach will resize the capacity of the array to 10% more.
//  4. The current capacity of the array is stored in a size_type Private MEMBER
//     varaiable called capacity.
//  5. If there is a current item then it can be accesed by data[current_i] other-
//    wise current_i=used;
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string.h>
#include "sequence2.h"
#include <cassert>
using namespace std;
namespace main_savitch_4 {
  sequence::sequence(size_type initial_capacity){
    capacity=initial_capacity;
    data= new value_type[initial_capacity];
    used=0;
    current_i=used;
  }
  sequence::sequence(const sequence& source){
    if(this!= &source){
      capacity=source.capacity;
      used=source.used;
      data=new value_type [capacity];
      for(size_type i=0;i!=used;i++) data[i]=source.data[i];
      current_i=source.current_i;
    }
  }

  void sequence::resize(size_type new_capacity){
    value_type *ret_data;
    if(new_capacity==capacity) return;
    if(new_capacity<used) new_capacity=used;
    ret_data= new value_type [new_capacity];
    for(size_type i=0;i!=used;i++) ret_data[i]=data[i];
    delete [] data;
    data=ret_data;
    capacity=new_capacity;

  }

  sequence::~sequence( ){
    delete [] data;
  }

  void sequence::start( ){
    if(size()>0) current_i=0;
  }
  void sequence::advance( ){
    assert(is_item());
    current_i+=1;
  }
  void sequence::insert(const value_type& entry){
    if(used==capacity) resize(((capacity + 1)*1.1));
    if(!is_item()) current_i=0;
    for(size_type i=used;i!=current_i;i--){
      data[i]=data[i-1];
    }
    data[current_i]=entry;
    used+=1;
  }
  void sequence::attach(const value_type& entry){
    if(used==capacity) resize((capacity + 1)*1.1);
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
    for(size_type i=(current_i+1);i!=used;i++)data[i-1]=data[i];
    used-=1;
  }

  sequence::size_type sequence::size( ) const{
    return used;
  }
  bool sequence::is_item( ) const{
    return(current_i<used);
  }
  sequence::value_type sequence::current( ) const{
    assert(is_item());
    return data[current_i];
  }
  void sequence::operator=(const sequence& source){
    if(this != &source){
    capacity=source.capacity;
    used=source.used;
    delete [] data;
    data=new value_type [capacity];
    for(size_type i=0;i!=used;i++) data[i]=source.data[i];
    current_i=source.current_i;
  }
  }
  void sequence::operator +=(const sequence& x) {
    size_type total=used+x.used;
    if(capacity<total) resize(total);
    for(size_type i=0;i!=x.used;i++) data[used+i]=x.data[i];
    used+=x.used;
    }
    sequence::value_type sequence::operator[](size_type index) const{
      assert(index<used);
      return data[index];
    }
  sequence operator +(const sequence& x, const sequence& y){
    sequence ret;
    ret=x;
    ret+=y;
    return ret;

  }

}

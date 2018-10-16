//CLASS IMPLEMENTED: sequence (see sequence3.h for documentation)
//INVARIANT for the sequence class
//  1.  Total number of items are store in a private memeber called total_node.
//
//  2.  For an empty sequence, we do not care what is stored, and all pointers
//       are set to NULL and total_node is set to equal 0.
//
//  3.  For a non-empty sequences, the first and the last item is stored in
//      head_ptr and tail_ptr in private member.
//
//  4.  If a current item exit then it is stored in a private member Variable
//      call cursor, otherwise the cursor will be NULL.
//
//  5.  If a previous item exist then it will be stored in a private member
//      variable call precursor, otherwise precursor will be NULL.

#include "sequence3.h"
#include <cassert>    // Provides assert
#include <cstdlib>    // Provides NULL and size_t
using namespace std;

namespace main_savitch_5
{
  //CONSTRUCTORS and DESTRUCTOR

  // RUNTIME ANALYSIS O(1)-CONSTANT
  sequence::sequence(){
    head_ptr=NULL;
    tail_ptr=NULL;
    cursor=NULL;
    precursor=NULL;
    total_node=0;

  }

  // RUNTIME ANALYSIS O(n)-LINEAR
  sequence::sequence(const sequence& source){
    if(source.total_node==0){
      head_ptr=tail_ptr=cursor=precursor=NULL;
      total_node=0;
    }
    else if((source.total_node==1)||(source.head_ptr==source.cursor)){
      list_copy(source.head_ptr,head_ptr,tail_ptr);
      if(source.cursor!=NULL) cursor=head_ptr;
      else cursor=NULL;
      precursor=NULL;
    }


    else {
      if(source.cursor==NULL){
        list_piece(source.head_ptr,NULL,head_ptr,precursor);
        cursor=NULL;
      }
      else {
        list_piece(source.head_ptr,source.cursor,head_ptr,precursor);
        list_piece(source.cursor,NULL,cursor,tail_ptr);
        precursor->set_link(cursor);
      }
    }
    total_node=source.total_node;

  }
  // RUNTIME ANALYSIS O(n)-LINEAR
  sequence::~sequence(){
   list_clear(head_ptr);
   head_ptr=NULL;
   tail_ptr=NULL;
   precursor=NULL;
   total_node=0;
  }
  // MODIFICATION MEMBER FUNCTIONS

  // RUNTIME ANALYSIS O(1)-CONSTANT
  void sequence::start( ){
    if(total_node>0) cursor=head_ptr;
    else cursor=NULL;
    precursor=NULL;
  }

  // RUNTIME ANALYSIS O(1)-CONSTANT
  void sequence::advance( ){
    assert(is_item());
    precursor=cursor;
    cursor=cursor->link();
    }

  // RUNTIME ANALYSIS O(1)-CONSTANT
  void sequence::insert(const sequence::value_type& entry){
    if((cursor==NULL)||precursor==NULL){
      list_head_insert(head_ptr, entry);
      cursor=head_ptr;
      if(total_node==0) tail_ptr=head_ptr;
      precursor=NULL;
    }
    else{
      list_insert(precursor,entry);
      cursor=precursor->link();

    }
    total_node++;
  }
  // RUNTIME ANALYSIS O(1)-CONSTANT
  void sequence::attach(const sequence::value_type& entry){
    if(cursor==NULL){
      if(total_node==0) {
        list_head_insert(head_ptr,entry);
        tail_ptr=head_ptr;
        cursor=tail_ptr;
        precursor=NULL;
      }
      else{
      list_insert(tail_ptr,entry);
      precursor=tail_ptr;
      tail_ptr=tail_ptr->link();
      cursor=tail_ptr;
      }
    }
    else{
      list_insert(cursor,entry);
      precursor=cursor;
      if(cursor==tail_ptr) tail_ptr=cursor->link();
      cursor=cursor->link();
    }
    total_node+=1;
  }
  // RUNTIME ANALYSIS O(1)-CONSTANT
  void sequence::remove_current( ){
    assert(is_item());
    if(cursor==head_ptr){
      list_head_remove(head_ptr);
      if(total_node==1) cursor=NULL;
      else cursor=head_ptr;
      precursor=NULL;
    }
    else{
      list_remove(precursor);
      cursor=precursor->link();
    }
    total_node-=1;
  }


  //CONSTANT MEMBER FUNCTIONS
  // RUNTIME ANALYSIS O(1)-CONSTANT
  sequence::size_type sequence::size() const{
    return total_node;
  }
  // RUNTIME ANALYSIS O(1)-CONSTANT
  bool sequence::is_item()const{
    return(cursor!=NULL);

  }
  // RUNTIME ANALYSIS O(1)-CONSTANT
  sequence::value_type sequence::current()const{
  assert(is_item());
  return cursor->data();
  }

  //operator

  // RUNTIME ANALYSIS O(1)-CONSTANT
  void sequence::operator =(const sequence& source){
    if(this!=&source) {
    list_clear(head_ptr);

     if(source.total_node==0){
      head_ptr=tail_ptr=cursor=precursor=NULL;
      total_node=0;
    }
    else if((source.total_node==1)||(source.head_ptr==source.cursor)){
      list_copy(source.head_ptr,head_ptr,tail_ptr);
      if(source.cursor!=NULL) cursor=head_ptr;
      else cursor=NULL;
      precursor=NULL;
    }


    else {
      if(source.cursor==NULL){
        list_piece(source.head_ptr,NULL,head_ptr,precursor);
        cursor=NULL;
      }
      else {
        list_piece(source.head_ptr,source.cursor,head_ptr,precursor);
        list_piece(source.cursor,NULL,cursor,tail_ptr);
        precursor->set_link(cursor);
      }
    }
    total_node=source.total_node;
  }

  }


}

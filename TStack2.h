//: C16:TStack2.h
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Templatized Stack with nested iterator
#ifndef TSTACK2_H
#define TSTACK2_H
#include "../require.h"





template <class T>
class Stack {

private:

  struct Link {
    T* data;
    Link* next;
    Link(T* dat, Link* nxt):data(dat), next(nxt) {}
  };

  struct Link * head;
  bool own;

public:

  Stack(bool own = true);
  void push(T* dat);
  T* peek(void) const ;
  T* pop(void);
  ~Stack(void);


  class iterator; 
  friend class iterator;// An elaborated-type-specifier
  class iterator {

  private:

    // Stack<T>::Link* p;
    Stack::Link* p;

  public:

    // iterator( Stack <T> const & tl) : p(tl.head) {
    //   ;
    // }
    // iterator( Stack const & tl) : p(tl.head) {
    //   ;
    // }
    // iterator( Stack <T> const & tl);
    iterator( Stack const & tl);
    
    iterator(void) : p(0) {// The end sentinel iterator:
      ; 
    }

    iterator( iterator const & tl) : p(tl.p) {
      ;
    }


    T* current(void) const {
      if(!p) return 0;
      return p->data;
    }

    T* operator*(void) const { 
      return current(); 
    }

    T* operator->(void) const { 
      require(p != 0, "PStack::iterator::operator->returns 0");
      return current(); 
    }
    

    bool operator++(void) {// operator++ returns boolean indicating end:
      if(p->next){
        p = p->next;
      }
      else {
        p = 0; // Indicates end of list
      }
      return bool(p);
    }
    
    bool operator++(int) { 
      return operator++(); 
    }
    
    bool operator==(const iterator&) const {
      return p == 0;
    }
    
    bool operator!=(const iterator&) const {
      return p != 0;
    }

    operator bool(void) const { 
      return bool(p); 
    }

  };


  iterator begin() const ;// return iterator(*this); 
  iterator end() const ; //return iterator();

};


template<class T>  // template types
// inline // if need
//                  // return type
Stack<T>::iterator::iterator // name
( Stack const & tl) : p(tl.head) {}


template<class T>// template types
//               // return type
Stack<T>::Stack 
(bool own) : head(0), own(own) {

}

template<class T>// template types
void             // return type 
Stack<T>::push   // name
(T* dat) {
  head = new Link(dat, head);
} 

template<class T>
T* 
Stack<T>::peek
(void) const { 
  return head ? head->data : 0;
}

template <class T> 
T* 
Stack<T>::pop 
(void) {
  if(head == 0) return 0;
  T* result = head->data;
  Link* oldHead = head;
  head = head->next;
  delete oldHead;
  return result;
}

template <class T> 
//
Stack <T>::~Stack 
(void) {
  if (own){
    while(head) {
      delete pop();
    }
  }
  else {
    while (head){
      pop();
    }
  }
}

template <class T> 
typename Stack <T>::iterator // class Stack <T>::iterator // doesn't work in MSVC
Stack <T>::begin  // name
(void) const { 
  return iterator(*this); 
}

template<class T> 
typename Stack <T>::iterator
Stack <T>::end  // name
(void) const { 
  return iterator(); 
}

#endif // TSTACK2_H ///:~

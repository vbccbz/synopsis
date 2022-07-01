//: C16:TPStash2.h
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Templatized PStash with nested iterator
#ifndef TPSTASH2_H
#define TPSTASH2_H
#include "../require.h"
// #include <cstdlib>
// #include <stdlib.h>
#include <string.h>
// #include <iostream>

template <class T, int incr = 20>
class PStash {
private: 
  T* *storage;
  
  int quantity;
  int next;
  bool own;

public:

  PStash(bool own = true) : quantity(0), storage(0), next(0), own(own) {}
  ~PStash();
  int add(T* element);

private:

  void inflate(int increase = incr);

public:

  T* operator[](int index) const;
  T* remove(int index);
  int count(void) const { 
    return next; 
  }
  // Nested iterator class:

  // class iterator; // Declaration required
  // friend class iterator; // Make it a friend //An elaborated-type-specifier
  class iterator { // Now define it
  
  private:

    // PStash <T> & ps;
    PStash & ps;
    int index;

  public:

    iterator(PStash& pStash) : ps(pStash), index(0) {}

    iterator(PStash& pStash, bool) : ps(pStash), index(ps.next) {}//the end sentinel

    iterator(const iterator& rv) : ps(rv.ps), index(rv.index) {}

    iterator & operator=(const iterator& rv) {
      ps = rv.ps;
      index = rv.index;
      return *this;
    }


    T* current() const {
      return ps.storage[index];
    }

    T* operator*() const { //Indirection (dereference) operator in the interesting role
      return current(); 
    }

    T* operator->() const { // Element selection through pointer (structure dereference) operator in the interesting role
      require(ps.storage[index] != 0, "PStash::iterator::operator->returns 0");
      return current(); 
    }


    // Remove the current element:
    T* remove(){
      return ps.remove(index);
    }


    iterator & operator++() {
      require(        ++index        <= ps.next,
        "PStash::iterator::operator++ "
        "moves index out of bounds");
      // ++index;
      return *this;
    }

    iterator & operator++(int) {
      return operator++();
    }

    // Create a new iterator that's moved forward
    iterator   operator+(int amount) const {
      iterator ret(*this);
      ret += amount; // op+= does bounds check
      return ret;
    }

    // Jump interator forward or backward:
    iterator & operator+=(int amount) {
      require(index + amount < ps.next && 
        index + amount >= 0, 
        "PStash::iterator::operator+= "
        "attempt to index out of bounds");    
      index += amount;
      return *this;
    }

    iterator & operator--() {
      require(--index >= 0,
        "PStash::iterator::operator-- "
        "moves index out of bounds");
      return *this;
    }

    iterator & operator--(int) { 
      return operator--();
    }

    iterator & operator-=(int amount) {
      require(index - amount < ps.next && 
        index - amount >= 0, 
        "PStash::iterator::operator-= "
        "attempt to index out of bounds");
      index -= amount;
      return *this;
    }
    

    // Comparison tests for end:
    bool operator==(const iterator& rv) const {
      return index == rv.index;
    }
    bool operator!=(const iterator& rv) const {
      return index != rv.index;
    }
  };
 ///////////////////////////////////////iterator 


  iterator begin (void) { 
    return iterator(*this); 
  }
  iterator end (void) { 
    return iterator(*this, true);
  }
};


template<class T, int incr>
// inline
int PStash<T, incr>::add(T* element) {
  
  // std::cout << *element << std::endl;
  
  if(next >= quantity)
    inflate();
  storage[next++] = element;
  return(next - 1); // Index number
}

template<class T, int incr>
// inline
void PStash<T, incr>::inflate(int increase) {
  const int tsz = sizeof(T*);
  T** st = new T*[quantity + increase];
  memset(st, 0, (quantity + increase) * tsz);
  memcpy(st, storage, quantity * tsz);
  quantity += increase;
  delete []storage; // Old storage
  storage = st; // Point to new memory
}

template<class T, int incr> 
// inline
T* 
PStash<T, incr>::
operator[]
(int index) const {
  require(index >= 0,
    "PStash::operator[] index negative");
  if(index >= next)
    return 0; // To indicate the end
  require(storage[index] != 0, 
    "PStash::operator[] returned null pointer");
  return storage[index];
}

template<class T, int incr>
// inline
T* 
PStash<T, incr>::remove
(int index) {
  // operator[] performs validity checks:
  T* v = operator[](index);
  // "Remove" the pointer:
  storage[index] = 0;
  return v;
}

// Destruction of contained objects:
template<class T, int incr>
// inline
//
PStash<T, incr>::~PStash
(void) {
  if (own){
    for(int i = 0; i < next; i++) {
      delete storage[i]; // Null pointers OK
      storage[i] = 0; // Just to be safe
    }  
  }
  
  delete []storage;
}

#endif // TPSTASH2_H ///:~




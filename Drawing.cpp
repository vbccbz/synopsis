//: C16:Drawing.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
#include <vector> // Uses Standard vector too!
#include "TPStash2.h"
#include "TStack2.h"
#include "Shape.h"
using namespace std;




template<class Iter>
void 
drawContainerOfPointers 
(Iter start, Iter end) { // only for iterators that returns a pointers
 std::cout << "\n---------drawAllPointers start...---------\n" << std::endl;
 while(start != end) {
   (*start)->draw();
   // start->draw();// WORKS ONLY WITH PSTASH AND STACK
   start++;
 }
 std::cout << "\n---------end.---------\n" << std::endl;
}



template <class T>
void 
 drawContainerOfPointersWithIters
(T & s) {
  for (typename T::iterator start = s.begin(); start != s.end(); start++) { 
    (*start)->draw();
    // start->draw();// WORKS ONLY WITH PSTASH AND STACK
  }
    
  cout << endl;
}

template<class Iter>
void 
drawContainerOfObjects
(Iter start, Iter end) {
 std::cout << "\n---------drawAllObjects start...---------\n" << std::endl;
 while(start != end) {
   //*start; // Compiler warning (level 1) C4834 // discarding return value of function with 'nodiscard' attribute
   std::cout << *start << std::endl;
   start++;
 }
 std::cout << "\n---------end.---------\n" << std::endl;
}

template <class T>
void 
drawContainerOfObjectsWithIters
(T & s) {
  for (typename T::iterator start = s.begin(); start != s.end(); start++) { 
    std::cout << *start << std::endl;
  }
    
  cout << endl;
}

void all (void){
  std::cout << "\n--------- start...---------\n" << std::endl;

  Shape* sparray[] = { 
   new Circle, 
   new Square, 
   new Line  
  };

  Stack <Shape> st (true);
  st.push(new Circle);
  st.push(new Square);
  st.push(new Line);

  PStash <Shape> pss (true);
  pss.add(new Circle);
  pss.add(new Square);
  pss.add(new Line);

  std::vector <int> vi;
  vi.push_back(1);
  vi.push_back(2);
  vi.push_back(3);

  ////////////////////////array////////////////////////////////////////

  // Shape* * start;
  // Shape* * end;
  // start = sparray;
  // end = sparray + sizeof (sparray) / sizeof (*sparray);
  // while ( start != end){
  //  (*start)->draw();
  //  start++;
  // }
  drawContainerOfPointers (sparray, sparray + sizeof(sparray)/sizeof(*sparray));

  //////////////////////////stack////////////////////////////////////

  Stack <Shape>::iterator it;
  cout << it << endl;//bool
  it = st.begin();
  cout << it << endl;//bool

  Stack <Shape>::iterator * it2p = 0;
  it2p = new Stack <Shape>::iterator(it);

        it               ;       *it2p               ;
      *(it)              ;     *(*it2p)              ;
  (* (*(it)) ) .  draw() ; (* (*(*it2p)) ) .  draw() ;
     (*(it))   -> draw() ;    (*(*it2p))   -> draw() ;
       (it)    -> draw() ;      (*it2p)    -> draw() ;
  //! it2p   -> draw(); //! (*it2p) . draw();
   
  delete it2p;

  // for ( Stack<Shape>::iterator it = st.begin(); it != st.end(); it++ ){
  //  (*it)->draw();   
  // }
  drawContainerOfPointers (st.begin(), st.end());
  drawContainerOfPointersWithIters (st);
  
  std :: cout << " LOL " << std::endl;
  
  Stack<Shape>::iterator lol = st.begin();
  // (*lol)-> draw();
   lol -> draw();
  std :: cout << " LOL " << std::endl;
  ////////////////////stash/////////////////////////////////////////////

  // for ( PStash <Shape>::iterator it = pss.begin(); it != pss.end(); it++ ){
  //  (*it)->draw();   
  // }
  drawContainerOfPointers (pss.begin(), pss.end() );
  drawContainerOfPointersWithIters (pss);

 //////////////////std::vector///////////////////////////////////////////
  
  // for (std::vector<int>::iterator i = vi.begin(); i != vi.end(); ++i ) { 
  //   std::cout << *i << ' ';
  // }
  drawContainerOfObjects ( vi.begin() , vi.end() );
  drawContainerOfObjectsWithIters (vi);

  //////////////////////////////////////////////////////////////////////
  
  for ( Shape* * start = sparray; start != sparray + sizeof (sparray) / sizeof (*sparray); ++start ){
    delete *start;   
  }

  std::cout << "\n--------- end all...---------\n" << std::endl;
}




class Plan : public Stack<Shape> {
public:
  ~Plan() { 
   cout << "~Plan" << endl; 
  }
};

class Drawing : public PStash<Shape> {
public:
 ~Drawing() { 
   cout << "~Drawing" << endl; 
 }
};

class Schematic : public std::vector <Shape*> { // inheritance
//  5.7, 5.11 composition
public:
 ~Schematic() { 
   cout << "~Schematic" << endl; 
   // while ( ! std::vector <Shape*>::empty() ){
   while ( ! empty() ){
     delete back();
     pop_back();
   }
   // clear(); // ?????????? it seems unnecessary due to inheritance
 }
};

void pds (void){
 std::cout << "\n---------pds start...---------\n" << std::endl;

 Plan p;
 Drawing d;
 Schematic s;

 p.push(new Line);
 p.push(new Square);
 p.push(new Circle);

 d.add(new Circle);
 d.add(new Square);
 d.add(new Line);

 s.push_back(new Square);
 s.push_back(new Circle);
 s.push_back(new Line);

 drawContainerOfPointers (p.begin(), p.end());
 drawContainerOfPointers (d.begin(), d.end());
 drawContainerOfPointers (s.begin(), s.end());

 std::cout << "\n---------end pds...---------\n" << std::endl;
}




int main() {
  all();
  pds();

  return 0;  
} 


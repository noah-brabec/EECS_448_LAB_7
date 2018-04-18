#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <vector>
#include "LinkedListOfInts.h"
#include "Node.h"
//#include "catch.h"

class Test
{
private:

  int total = 0;

public:

  Test();

  ~Test();


  //Will run all of the tests and return total grade
  int grade();

  /** @pre None.
	*   @post None.
	*   @return true if the list is empty, false otherwise.
	*/

  void testIsEmpty();



  /** @pre None.
	*   @post None.
	*   @return the number of elements in the list.
	*/
  void testSize();


  /** @pre the value is a valid T.
	*   @post none.
	*   @return true if the value is in the list, false otherwise.
	*/
  void testSearch();


  /** @pre None
	*   @post None
	*   @return A standard vector with the contents of the list
	*   NOTE: This method is guaranteed to work. It's only one guaranteed though
	*/

  /** @pre the value is a valid T.
	*   @post One new element added to the end of the list.
	*   @return none.
	*/
  void testAddBack();

  /** @pre the value is a valid T.
	*   @post One new element added to the front of the list.
	*   @return none.
	*/
  void testAddFront();

  /** @pre None
	*   @post One element is removed from the back of the list.
	*   @return true if the back element was removed, false if the list is empty.
	*/
  void testRemoveBack();

  /** @pre None
	*   @post One element is removed from the front of the list.
	*   @return true if the front element was removed, false if the list is empty.
	*/
  void testRemoveFront();

};

#endif

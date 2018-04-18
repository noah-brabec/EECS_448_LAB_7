#include "Test.h"

Test::Test()
{

}

Test::~Test()
{

}


//Will run all of the tests and return total grade
//the total grade should be something
int Test::grade()
{
    testIsEmpty();
    testSize();
    testSearch();
    testAddBack();
    testAddFront();
    testRemoveBack();
    testRemoveFront();

    return(total);
}

/** @pre None.
*   @post None.
*   @return true if the list is empty, false otherwise.
*/
void Test::testIsEmpty()
{
  LinkedListOfInts* listOfInts = new LinkedListOfInts();

  if(listOfInts->isEmpty())
  {
    std::cout << "Test 1: isEmpty() returns true on an empty list: PASSED\n";
    total++;
  }
  else
  {
    std::cout << "Test 1: isEmpty() returns true on an empty list: FAILED\n";
  }
  //adds the value 3
  listOfInts->addFront(3);

  if(!listOfInts->isEmpty())
  {
    std::cout << "\nTest 2: isEmpty() returns false on a populated list: PASSED\n";
    total++;
  }
  else
  {
    std::cout << "\nTest 2: isEmpty() returns false on a populated list: FAILED\n";
  }
}


/** @pre None.
*   @post None.
*   @return the number of elements in the list.
*   Test function is going to add some values and then see if it returns 0 on an
*   empty list and 3 on a list with 3 elements.
*/
void Test::testSize()
{
  LinkedListOfInts* listOfInts = new LinkedListOfInts();

  if(listOfInts->size() == 0)
  {
    std::cout << "\nTest 3: size() returns 0 on an empty list: PASSED\n";
    total++;
  }
  else
  {
    std::cout << "\nTest 3: size() returns 0 on an empty list: FAILED\n";
  }

  listOfInts->addFront(3);
  listOfInts->addFront(4);
  listOfInts->addFront(5);

  if(listOfInts->size() == 3)
  {
    std::cout << "\nTest 4: size() returns 3 with a list of 3 elements: PASSED\n";
    total++;
  }
  else
  {
    std::cout << "\nTest 4: size() returns 3 with a list of 3 elements: FAILED\n";
  }
}


/** @pre the value is a valid T.
*   @post none.
*   @return true if the value is in the list, false otherwise.
*   Test function is going to add a value and then search for it to see if search works.
*/
void Test::testSearch()
{
  LinkedListOfInts* listOfInts = new LinkedListOfInts();

  if(!listOfInts->search(0))
  {
    std::cout << "\nTest 5: search() returns false when that value does not exist in the list: PASSED\n";
    total++;
  }
  else
  {
    std::cout << "\nTest 5: search() returns false when that value does not exist in the list: FAILED\n";
  }

  listOfInts->addFront(3);

  if(listOfInts->search(3))
  {
    std::cout << "\nTest 6: search() returns true when the value exists in the list: PASSED\n";
    total++;
  }
  else
  {
    std::cout << "\nTest 6: search() returns true when the value exists in the list: FAILED\n";
  }
}


/** @pre None
*   @post None
*   @return A standard vector with the contents of the list
*   NOTE: This method is guaranteed to work. It's only one guaranteed though
*/

/** @pre the value is a valid T.
*   @post One new element added to the end of the list.
*   @return none.
*   The test function is going to add some elements using addBack(), and then turn that list into a vector.
*   Then we are going to check each element in the vector to make sure the values are in the proper space
*   and hold the right value.
*/
void Test::testAddBack()
{
  LinkedListOfInts* listOfInts = new LinkedListOfInts();


  listOfInts->addBack(1);
  listOfInts->addBack(2);
  listOfInts->addBack(3);

  auto testVector = listOfInts->toVector();

  int* vectorList = testVector.data();

  std::cout << "\nTest 7:" << '\n';

  if(vectorList[0] == 1)
  {
    std::cout << "\tList contains 1 in element 0: PASSED" << '\n';
  }
  else
  {
    std::cout << "\tList contains 1 in element 0: FAILED" << '\n';
  }

  if(vectorList[1] == 2)
  {
    std::cout << "\tList contains 2 in element 1: PASSED" << '\n';
  }
  else
  {
    std::cout << "\tList contains 2 in element 1: FAILED" << '\n';
  }

  if(vectorList[2] == 3)
  {
    std::cout << "\tList contains 3 in element 2: PASSED" << '\n';
    std::cout << "\taddBack() succesfully adds elements and puts them in the list in order: PASSED" << '\n';
    total++;
  }
  else
  {
    std::cout << "\tList contains 3 in element 2: FAILED" << '\n';
    std::cout << "\taddBack() succesfully adds elements and puts them in the list in order: FAILED" << '\n';
  }
}

/** @pre the value is a valid T.
*   @post One new element added to the front of the list.
*   @return none.
*/
void Test::testAddFront()
{
  LinkedListOfInts* listOfInts = new LinkedListOfInts();


  listOfInts->addFront(1);
  listOfInts->addFront(2);
  listOfInts->addFront(3);

  auto testVector = listOfInts->toVector();

  int* vectorList = testVector.data();

  std::cout << "\nTest 8:" << '\n';

  if(vectorList[2] == 1)
  {
    std::cout << "\tList contains 1 in element 2: PASSED" << '\n';
  }
  else
  {
    std::cout << "\tList contains 1 in element 2: FAILED" << '\n';
  }

  if(vectorList[1] == 2)
  {
    std::cout << "\tList contains 2 in element 1: PASSED" << '\n';
  }
  else
  {
    std::cout << "\tList contains 2 in element 1: FAILED" << '\n';
  }

  if(vectorList[0] == 3)
  {
    std::cout << "\tList contains 3 in element 0: PASSED" << '\n';
    std::cout << "\taddFront() succesfully adds elements and puts them in the list in order: PASSED" << '\n';
    total++;
  }
  else
  {
    std::cout << "\tList contains 3 in element 0: FAILED" << '\n';
    std::cout << "\taddFront() succesfully adds elements and puts them in the list in order: FAILED" << '\n';
  }
}

/** @pre None
*   @post One element is removed from the back of the list.
*   @return true if the back element was removed, false if the list is empty.
*   Test case will check if it returns false on an empty list, then add some values, see if it removes the back one.
*/
void Test::testRemoveBack()
{
  LinkedListOfInts* listOfInts = new LinkedListOfInts();

  if(!listOfInts->removeBack())
  {
    std::cout << "\nTest 9: removeBack() returns false on an empty list: PASSED\n";
    total++;
  }
  else
  {
    std::cout << "\nTest 9: removeBack() returns false on an empty list: FAILED\n";
  }

  listOfInts->addFront(1);
  listOfInts->addFront(2);
  listOfInts->addFront(3);

  //list should now contain (in order): 3,2,1

  auto testVector = listOfInts->toVector();

  int* vectorList = testVector.data();

  listOfInts->removeBack();

  //list should now contain (in order): 3,2

  if(listOfInts->search(1))
  {
    std::cout << "\n Test 10: removeBack() deleted the last element: FAILED" << '\n';
  }
  else
  {
    std::cout << "\n Test 10: removeBack() deleted the last element: PASSED" << '\n';
    total++;
  }

  if(listOfInts->size() == 2)
  {
    std::cout << "\n Test 11: removeBack() deleted some element in the list: PASSED" << '\n';
    total++;
  }
  else
  {
    std::cout << "\n Test 11: removeBack() deleted some element in the list: FAILED" << '\n';
  }

}

/** @pre None
*   @post One element is removed from the front of the list.
*   @return true if the front element was removed, false if the list is empty.
*/
void Test::testRemoveFront()
{
  LinkedListOfInts* listOfInts = new LinkedListOfInts();

  if(!listOfInts->removeFront())
  {
    std::cout << "\nTest 12: removeFront() returns false on an empty list: PASSED\n";
    total++;
  }
  else
  {
    std::cout << "\nTest 12: removeFront() returns false on an empty list: FAILED\n";
  }

  listOfInts->addFront(1);
  listOfInts->addFront(2);
  listOfInts->addFront(3);

  //list should now contain (in order): 3,2,1

  auto testVector = listOfInts->toVector();

  int* vectorList = testVector.data();

  listOfInts->removeFront();

  //list should now contain(in order): 2,1

  if(listOfInts->search(3))
  {
    std::cout << "\n Test 13: removeFront() deleted the first element: FAILED" << '\n';
  }
  else
  {
    std::cout << "\n Test 13: removeFront() deleted the first element: PASSED" << '\n';
    total++;
  }

  if(listOfInts->size() == 2)
  {
    std::cout << "\n Test 14: removeFront() deleted some element in the list: PASSED" << '\n';
    total++;
  }
  else
  {
    std::cout << "\n Test 14: removeFront() deleted some element in the list: FAILED" << '\n';
  }
}

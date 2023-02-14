#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "linked_list.hpp"

template class LinkedList<int>;

TEST_CASE("Items added successfully", "[LinkedList]"){
  LinkedList<int> list;
  list.insert(0,1);
  list.insert(1,2);

  REQUIRE(list.getLength() == 2);
  REQUIRE(list.getEntry(0) == 1);

  list.setEntry(0, 3);
  REQUIRE(list.getEntry(0) == 3);
  REQUIRE(list.getEntry(1) == 2);
}

TEST_CASE("Item removed successfully", "[LinkedList]"){
  LinkedList<int> list;
  list.insert(0,4);
  list.insert(1,3);
  list.insert(2,2);
  list.insert(3,1);

  list.remove(1);
  REQUIRE(list.getEntry(0) == 4);
  REQUIRE(list.getEntry(1) == 2);
  REQUIRE(list.getEntry(2) == 1);
  REQUIRE(list.getLength() == 3);
}

TEST_CASE("Copy Constructor", "[LinkedList]"){
  LinkedList<int> list;
  list.insert(0,7);
  list.insert(1,2);
  list.insert(2,3);

  LinkedList<int> list2(list);

  REQUIRE(list2.getLength() == 3);
  REQUIRE(list2.getEntry(0) == 7);
  REQUIRE(list2.getEntry(1) == 2);
  REQUIRE(list2.getEntry(2) == 3);

}

TEST_CASE("Overloaded Assignment Operator", "[LinkedList]"){
  LinkedList<int> list;
  list.insert(0,7);
  list.insert(1,2);
  list.insert(2,3);

  LinkedList<int> list2;
  list2 = list;

  REQUIRE(list2.getLength() == 3);
  REQUIRE(list2.getEntry(0) == 7);
  REQUIRE(list2.getEntry(1) == 2);
  REQUIRE(list2.getEntry(2) == 3);
}

TEST_CASE("Detect empty list", "[LinkedList]"){
  LinkedList<int> list;

  REQUIRE(list.getLength() == 0);
  REQUIRE(list.isEmpty());

}


TEST_CASE("List is cleared", "[LinkedList]"){
  LinkedList<int> list;
  list.insert(0,1);
  list.insert(1,2);

  list.clear();

  REQUIRE(list.isEmpty());
}

TEST_CASE("An entry can be set", "[LinkedList]"){
  LinkedList<int> list;
  list.insert(0,8);
  list.insert(1,2);

  list.setEntry(1,9);

  REQUIRE(list.getEntry(0) == 8);
  REQUIRE(list.getEntry(1) == 9);
}

TEST_CASE("Insert is false outside of bounds", "[LinkedList]"){
  LinkedList<int> list;

  REQUIRE_FALSE(list.insert(1,6));
}

TEST_CASE("Remove is false outside of bounds", "[LinkedList]"){
  LinkedList<int> list;

  REQUIRE_FALSE(list.remove(0));
}

#include <assert.h>
#include <stdbool.h>

void testAdd()
{
    List* list = newList();
    insert(list, 324, 0);
    insert(list, 32423, 1);
    assert(add(list, 5555) == true);

    int res = -1;
    find(list, 0, &res);
    assert(res == 324);

    find(list, 1, &res);
    assert(res == 5555);

    find(list, 2, &res);
    assert(res == 32423);

    deleteList(list);
}

void testRm()
{
    List* list = newList();
    insert(list, 324, 0);
    insert(list, 5555, 1);
    insert(list, 32423, 2);

    assert(rm(list, 5555) == true);

    int res = -1;
    find(list, 0, &res);
    assert(res == 324);

    find(list, 1, &res);
    assert(res == 32423);

    deleteList(list);
}

void testAddInEmpty()
{
    List* list = newList();
    assert(add(list, 444) == true);

    int res = -1;
    find(list, 0, &res);
    assert(res == 444);

    deleteList(list);
}

void testRmInEmpty()
{
    List* list = newList();
    assert(rm(list, 3243241) == true);

    deleteList(list);
}

void testAddDuplicate()
{
    List* list = newList();
    insert(list, 324, 0);
    insert(list, 32423, 1);
    assert(add(list, 5555) == true);
    assert(add(list, 5555) == true);

    int res = -1;
    find(list, 0, &res);
    assert(res == 324);

    find(list, 1, &res);
    assert(res == 5555);

    find(list, 2, &res);
    assert(res == 5555);

    find(list, 3, &res);
    assert(res == 32423);

    deleteList(list);
}

void runTests()
{
    testAdd();
    testRm();
    testAddInEmpty();
    testRmInEmpty();
    testAddDuplicate();
}
#include <iostream>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

/*
STL = Standard Template Library

The STL provides ready-to-use:

1. Containers   -> store and organize data
2. Iterators    -> access/traverse container elements
3. Algorithms   -> perform operations such as sorting/searching

Common containers covered here:
vector, list, stack, queue, deque, set, map

Important:
- Most STL containers are templates, so their element type is
  specified inside <>.

Examples:
    vector<int>
    list<string>
    map<string, int>
*/


int main()
{
    // 1. VECTOR

    /*
    Vector:
    - A dynamic array.
    - Stores elements contiguously in memory.
    - Provides fast random access using an index.
    - Automatically grows when more capacity is needed.
    - Adding/removing at the end is efficient (amortized O(1)).
    - Inserting/removing at the beginning or middle is O(n).

    Syntax:
        vector<type> vectorName;
    */


    // Empty vector
    vector<string> cars;

    // Initialize a vector with values
    vector<string> cars1 = {"Volvo", "BMW", "Ford", "Mazda"};

    // The element type is fixed after declaration.
    // cars1 can store only strings.


    // Accessing elements

    // Access using index (0-based indexing)
    cout << cars1[0] << '\n';

    // Access first and last elements
    cout << cars1.front() << '\n';
    cout << cars1.back() << '\n';

    // at() performs bounds checking and throws an exception
    // if the index is out of range.
    cout << cars1.at(2) << '\n';


    // Modifying elements
    cars1[0] = "Opel";
    cars1.at(0) = "Volvo";


    // Adding and removing elements

    // Add elements to the end
    cars1.push_back("Tesla");
    cars1.push_back("VW");

    // Remove the last element
    // This removes "VW".
    cars1.pop_back();


    // size(), capacity(), empty()

    // size() = number of elements currently stored
    cout << "Size: " << cars1.size() << '\n';

    // capacity() = number of elements the vector can currently
    // hold before it needs to allocate more memory.
    cout << "Capacity: " << cars1.capacity() << '\n';

    // empty() returns true if the vector has no elements
    cout << "Empty: " << cars1.empty() << '\n';


    // reserve() requests capacity in advance.
    // It does NOT change the number of elements.
    cars1.reserve(20);

    cout << "Size after reserve: " << cars1.size() << '\n';
    cout << "Capacity after reserve: " << cars1.capacity() << '\n';


    // Loop using an index

    for (size_t i = 0; i < cars1.size(); ++i)
    {
        cout << cars1[i] << '\n';
    }

    /*
    size_t:
    - An unsigned integer type.
    - Commonly used for sizes, number of elements, and indexes.
    - cars1.size() returns a value of type size_t.
    - int also works in many cases, but size_t is the natural
      type for container sizes and avoids signed/unsigned
      comparison issues.
    */


    // ------------------------------------------------------------
    // Range-based for loop
    // ------------------------------------------------------------

    for (const string& car : cars1)
    {
        cout << car << '\n';
    }

    /*
    Why const string& instead of string?

    Using:
        for (string car : cars1)

    creates a COPY of each string from the vector.

    Using:
        for (string& car : cars1)

    makes car a REFERENCE to the original string, avoiding
    the copy. It also allows us to modify the original element.

    Using:
        for (const string& car : cars1)

    makes car a reference to the original string without
    allowing us to modify it through car.

    Therefore:
        string            -> copy
        string&           -> reference, can modify original
        const string&     -> reference, cannot modify original

    Example:

        for (string& car : cars1)
        {
            car = "Toyota";
        }

    This would modify the original vector.

    But:

        for (const string& car : cars1)
        {
            // car = "Toyota";  // ERROR
        }

    because const prevents modification.

    IMPORTANT:
    The & symbol has different meanings depending on context.

        string& car
            -> & declares car as a reference.

        &x
            -> & is the address-of operator and gives the
               address of x.
    */


    /*
    Useful vector functions:
        push_back()
        pop_back()
        front()
        back()
        at()
        size()
        capacity()
        reserve()
        empty()
        clear()
        begin()
        end()

    NOTE:
    vector is usually the default container to consider when
    you need a dynamic array.
    */


    // ============================================================
    // 2. LIST
    // ============================================================

    /*
    List:
    - Usually implemented as a doubly linked list.
    - Elements are not stored contiguously.
    - Does NOT provide random access by index.
    - Fast insertion/deletion when you already have an iterator
      pointing to the position.
    - Supports insertion/removal at both ends.

    Syntax:
        list<type> listName;
    */


    list<string> cars2 = {"Volvo", "BMW", "Ford", "Mazda"};


    // ------------------------------------------------------------
    // Access first and last elements
    // ------------------------------------------------------------

    cout << cars2.front() << '\n';
    cout << cars2.back() << '\n';


    // ------------------------------------------------------------
    // Modify first and last elements
    // ------------------------------------------------------------

    cars2.front() = "Opel";
    cars2.back() = "Toyota";


    // ------------------------------------------------------------
    // Add elements
    // ------------------------------------------------------------

    cars2.push_front("Tesla");
    cars2.push_back("VW");


    // ------------------------------------------------------------
    // Remove elements
    // ------------------------------------------------------------

    cars2.pop_front();
    cars2.pop_back();


    // ------------------------------------------------------------
    // Size and empty check
    // ------------------------------------------------------------

    cout << cars2.size() << '\n';
    cout << cars2.empty() << '\n';


    // A list cannot be accessed using cars2[i].
    // Use a range-based loop or iterators instead.

    for (const string& car : cars2)
    {
        cout << car << '\n';
    }


    /*
    Useful list functions:
        push_front()
        push_back()
        pop_front()
        pop_back()
        front()
        back()
        size()
        empty()
        insert()
        erase()
        sort()
        reverse()

    IMPORTANT:
    Unlike vector, std::list has its own sort() member function.

    std::sort() requires random-access iterators and therefore
    cannot be used directly with std::list.
    */


    // Example of list::sort()
    list<int> numsList = {5, 2, 8, 1, 4};

    numsList.sort();

    /*
    After sort():
        1 2 4 5 8
    */


    // ============================================================
    // 3. STACK
    // ============================================================

    /*
    Stack:
    - Follows LIFO: Last In, First Out.
    - Elements can be inserted and removed only from the top.
    - No index-based access.
    - Internally uses another container by default (usually deque).

    Syntax:
        stack<type> stackName;
    */


    stack<string> cars3;


    // Add elements
    cars3.push("Tesla");
    cars3.push("BMW");


    // Access only the top element
    cout << cars3.top() << '\n';


    // The top element can be modified
    cars3.top() = "Audi";


    // Remove the top element
    cars3.pop();


    // Size and empty check
    cout << cars3.size() << '\n';
    cout << cars3.empty() << '\n';


    /*
    IMPORTANT:

    pop() removes an element but does NOT return it.

    If you need the value:

        string x = cars3.top();
        cars3.pop();
    */


    // ============================================================
    // 4. QUEUE
    // ============================================================

    /*
    Queue:
    - Follows FIFO: First In, First Out.
    - Elements are inserted at the back.
    - Elements are removed from the front.
    - No index-based access.

    Syntax:
        queue<type> queueName;
    */


    queue<string> fruits;


    // Add elements to the back
    fruits.push("Apple");
    fruits.push("Mango");
    fruits.push("Watermelon");


    // Access front and back
    cout << fruits.front() << '\n'; // Apple
    cout << fruits.back() << '\n';  // Watermelon


    // front() and back() can be modified
    fruits.front() = "Banana";
    fruits.back() = "Cherry";


    // Remove the front element
    fruits.pop();


    cout << fruits.size() << '\n';
    cout << fruits.empty() << '\n';


    /*
    IMPORTANT:

    Like stack::pop(), queue::pop() does not return the removed value.

    Use front() first if you need the value:

        string x = fruits.front();
        fruits.pop();
    */


    // ============================================================
    // 5. DEQUE
    // ============================================================

    /*
    Deque = Double-Ended Queue

    - Allows insertion/removal at both front and back.
    - Supports random access using [] and at().
    - Similar to vector for random access, but supports efficient
      insertion/removal at both ends.

    Syntax:
        deque<type> dequeName;
    */


    deque<string> games =
    {
        "GTA", "AC", "WD", "GoW", "KCD"
    };


    // Access by index
    cout << games[2] << '\n';


    // Access first and last elements
    cout << games.front() << '\n';
    cout << games.back() << '\n';


    // at() provides bounds checking
    cout << games.at(2) << '\n';


    // Change an element
    games.at(2) = "RoN";


    // Add at both ends
    games.push_front("FC");
    games.push_back("2K");


    // Remove from both ends
    games.pop_back();
    games.pop_front();


    cout << games.size() << '\n';
    cout << games.empty() << '\n';


    // Index-based loop
    for (size_t i = 0; i < games.size(); ++i)
    {
        cout << games.at(i) << '\n';
    }


    // Range-based loop
    for (const string& game : games)
    {
        cout << game << '\n';
    }


    // ============================================================
    // 6. SET
    // ============================================================

    /*
    Set:
    - Stores UNIQUE elements.
    - Duplicate values are ignored.
    - Elements are automatically sorted.
    - Default order is ascending.
    - No index-based access.
    - Elements cannot be modified directly because changing a
      value could break the set's ordering and uniqueness rules.

    Syntax:
        set<type> setName;
    */


    set<string> brands =
    {
        "Nike", "Adidas", "Puma", "Bata"
    };


    // Elements are stored in sorted order:
    // Adidas, Bata, Nike, Puma


    // A set of integers is also sorted automatically
    set<int> numbers = {1, 7, 3, 2, 5, 9};


    // Descending order
    set<int, greater<int>> numbersDesc =
    {
        1, 7, 3, 2, 5, 9
    };


    // Add an element
    brands.insert("UnderArmour");


    // Duplicate insertion has no effect
    brands.insert("Nike");


    // Remove an element
    brands.erase("UnderArmour");


    // Remove all elements
    // brands.clear();


    cout << brands.size() << '\n';
    cout << brands.empty() << '\n';


    for (const string& brand : brands)
    {
        cout << brand << '\n';
    }


    /*
    Useful set functions:
        insert()
        erase()
        find()
        count()
        size()
        empty()
        clear()

    count(value):
        For std::set, returns either 0 or 1 because every value
        can appear at most once.

    find(value):
        Returns an iterator to the element if found, otherwise
        returns end().

    IMPORTANT:
    Elements cannot be modified through a set iterator because
    changing a value could violate the set's ordering and
    uniqueness rules.

    If you need to change a value:
        1. Erase the old value.
        2. Insert the new value.
    */


    // ============================================================
    // 7. MAP
    // ============================================================

    /*
    Map:
    - Stores data as KEY-VALUE pairs.
    - Every key is unique.
    - Keys are automatically sorted in ascending order by default.
    - Access is by key, not by numeric index.

    Syntax:
        map<keyType, valueType> mapName;
    */


    map<string, int> people =
    {
        {"John", 32},
        {"Adele", 45},
        {"Bo", 29}
    };


    // Access by key
    cout << "John is: " << people["John"] << '\n';
    cout << "Adele is: " << people.at("Adele") << '\n';


    /*
    Difference between [] and at():

    people["Aman"]

        If "Aman" does not exist, [] creates the key with a
        default-initialized value.

        For map<string, int>:
            people["Aman"]
        creates:
            "Aman" -> 0


    people.at("Aman")

        Does NOT create the key.

        Throws an exception if the key does not exist.

    Therefore, use at() when you do not want accidental insertion.
    */


    // Change a value
    people.at("John") = 50;


    // Add elements
    people["Aman"] = 22;
    people.insert({"Jenny", 24});


    /*
    Keys must be unique.

    Inserting another "Jenny" using insert() does not replace
    the existing value.

    However:
        people["Jenny"] = 30;

    would update Jenny's existing value.
    */


    // Remove an element
    people.erase("John");


    // Remove all elements
    // people.clear();


    cout << people.size() << '\n';
    cout << people.empty() << '\n';


    // Check whether a key exists
    cout << people.count("Aman") << '\n';


    // Loop through a map
    for (const auto& person : people)
    {
        cout << person.first << " is: " << person.second << '\n';
    }


    /*
    In a map:

        person.first  -> key
        person.second -> value

    const auto&:
        - auto automatically determines the type.
        - & avoids copying each key-value pair.
        - const prevents modification through person.
    */


    // Map in descending order of keys
    map<string, int, greater<string>> peopleDesc =
    {
        {"John", 32},
        {"Adele", 34},
        {"Aman", 22}
    };


    // ============================================================
    // 8. ITERATORS
    // ============================================================

    /*
    Iterator:
    - An object used to traverse/access elements in a container.
    - It behaves similarly to a pointer.
    - Iterators are important because many STL algorithms operate
      on iterator ranges.

    General range:
        [begin(), end())

    begin() -> points to the first element.
    end()   -> points one position AFTER the last element.

    end() does NOT point to an actual element.
    */


    vector<string> names =
    {
        "Aman", "Baman", "Raman", "Daman"
    };


    // Explicit iterator type
    vector<string>::iterator it1;


    for (it1 = names.begin(); it1 != names.end(); ++it1)
    {
        cout << *it1 << '\n';
    }


    /*
    *it1 is the dereference operator.

    It accesses the element to which the iterator points.

    Example:

        it1
        ↓
        position of "Aman"

        *it1
        ↓
        "Aman"
    */


    // Modify an element using an iterator
    it1 = names.begin();
    *it1 = "Asman";


    // auto can determine the iterator type automatically
    auto it2 = names.begin();
    cout << "First element through auto iterator: " << *it2 << '\n';


    for (auto it = names.begin(); it != names.end(); ++it)
    {
        cout << *it << '\n';
    }


    // Range-based for loop
    for (const string& name : names)
    {
        cout << name << '\n';
    }


    /*
    When to use what?

    Range-based for:
        Best for simple traversal when you only need the values.

    Iterators:
        Useful when:
        - You need to modify elements.
        - You need to work with STL algorithms.
        - You need to erase/insert at a specific position.
        - You need reverse traversal.
        - You need more control over traversal.
    */


    // Reverse iteration
    for (auto it = names.rbegin(); it != names.rend(); ++it)
    {
        cout << *it << '\n';
    }


    /*
    Containers such as vector, list, deque, set, and map support
    iterators.

    stack and queue are container adaptors and do not expose
    iterators directly.
    */


    // ============================================================
    // 9. STL ALGORITHMS
    // ============================================================

    /*
    Algorithms are reusable functions provided mainly by <algorithm>.

    They commonly work with iterator ranges:

        [begin, end)

    This means the first iterator is included, but the second
    iterator is excluded.
    */


    // ------------------------------------------------------------
    // Sorting
    // ------------------------------------------------------------

    vector<int> nums =
    {
        1, 6, 46, 234, 32543, 32, 62
    };


    // Ascending order
    sort(nums.begin(), nums.end());


    // Descending order
    sort(nums.rbegin(), nums.rend());


    /*
    sort() requires random-access iterators.

    Therefore it works with:
        vector
        deque

    But it does NOT work directly with:
        list
        set
        map

    std::list has its own sort() member function:

        list<int> numsList = {5, 2, 8, 1};
        numsList.sort();
    */


    // ------------------------------------------------------------
    // Searching with find()
    // ------------------------------------------------------------

    auto found = find(nums.begin(), nums.end(), 46);


    /*
    find() performs a linear search.

    Time complexity:
        O(n)

    If found:
        found != nums.end()

    If not found:
        found == nums.end()
    */


    if (found != nums.end())
    {
        cout << "46 found\n";
    }
    else
    {
        cout << "46 not found\n";
    }


    // ------------------------------------------------------------
    // lower_bound()
    // ------------------------------------------------------------

    /*
    lower_bound(first, last, value)

    Returns an iterator pointing to the first element that is
    GREATER THAN OR EQUAL TO value.

    Example:

        nums = {1, 3, 5, 7, 9}

        lower_bound(..., 5) -> 5
        lower_bound(..., 6) -> 7

    IMPORTANT:
    The range must be sorted in ascending order for the normal
    overload to work correctly.
    */


    sort(nums.begin(), nums.end());

    auto lower = lower_bound(nums.begin(), nums.end(), 5);

    if (lower != nums.end())
    {
        cout << "First element >= 5: " << *lower << '\n';
    }


    // ------------------------------------------------------------
    // upper_bound()
    // ------------------------------------------------------------

    /*
    upper_bound(first, last, value)

    Returns an iterator pointing to the first element that is
    GREATER than value.

    Example:

        nums = {1, 3, 5, 7, 9}

        upper_bound(..., 5) -> 7
        upper_bound(..., 6) -> 7

    IMPORTANT:
    The range must be sorted in ascending order for the normal
    overload to work correctly.
    */


    auto upper = upper_bound(nums.begin(), nums.end(), 5);

    if (upper != nums.end())
    {
        cout << "First element > 5: " << *upper << '\n';
    }


    /*
    Easy way to remember:

        lower_bound -> first element >= value
        upper_bound -> first element > value
    */


    // ------------------------------------------------------------
    // binary_search()
    // ------------------------------------------------------------

    /*
    binary_search(first, last, value)

    Returns:
        true  -> value exists
        false -> value does not exist

    The range must be sorted.

    Time complexity:
        O(log n)
    */


    if (binary_search(nums.begin(), nums.end(), 46))
    {
        cout << "46 exists\n";
    }
    else
    {
        cout << "46 does not exist\n";
    }


    // ------------------------------------------------------------
    // min_element() and max_element()
    // ------------------------------------------------------------

    auto minimum = min_element(nums.begin(), nums.end());
    auto maximum = max_element(nums.begin(), nums.end());


    /*
    min_element() and max_element() return iterators.

    Therefore, use * to access the actual values:

        *minimum
        *maximum

    If the range is empty, they return end().
    Therefore, do not dereference the result of an empty range.
    */


    if (minimum != nums.end())
    {
        cout << "Smallest: " << *minimum << '\n';
        cout << "Largest: " << *maximum << '\n';
    }


    // ------------------------------------------------------------
    // copy()
    // ------------------------------------------------------------

    /*
    copy(first, last, destination)

    Copies elements from one range to another.

    The destination must have enough space for all copied elements.
    */


    vector<int> copiedNums(nums.size());

    copy(nums.begin(), nums.end(), copiedNums.begin());


    // ------------------------------------------------------------
    // fill()
    // ------------------------------------------------------------

    // Fill every element with 7
    fill(copiedNums.begin(), copiedNums.end(), 7);


    // ------------------------------------------------------------
    // clear()
    // ------------------------------------------------------------

    copiedNums.clear();


    /*
    clear() removes all elements from the container.

    After clear():

        size() == 0

    Note:
    clear() does not necessarily release all allocated memory or
    capacity for every container.
    */


    // ============================================================
    // 10. TYPICAL USE CASES
    // ============================================================

    /*
    vector:
        General-purpose dynamic array.

    list:
        Frequent insertion/deletion at known positions when
        you already have an iterator to those positions.

    deque:
        Frequent insertion/deletion at both ends with random access.

    stack:
        Undo operations, recursion-like processing, parentheses,
        DFS-style problems.

    queue:
        Scheduling, BFS, task processing.

    set:
        Store unique values and keep them sorted.

    map:
        Store and retrieve values using unique keys.
    */


    // ============================================================
    // 11. IMPORTANT COMPLEXITIES
    // ============================================================

    /*
    Approximate/common complexities:

    VECTOR
    ------------------------------------------------------------
    Access by index       O(1)
    push_back()           O(1) amortized
    pop_back()            O(1)
    Search                O(n)
    Insert/erase middle   O(n)


    LIST
    ------------------------------------------------------------
    Access by position    O(n)
    push_front()          O(1)
    push_back()           O(1)
    pop_front()           O(1)
    pop_back()            O(1)

    Insert/erase with a
    valid iterator        O(1)

    IMPORTANT:
    Finding the position may itself take O(n).
    The O(1) refers to the actual insertion/erasure once the
    correct iterator is already available.


    DEQUE
    ------------------------------------------------------------
    Random access         O(1)
    push_front()          O(1)
    push_back()           O(1)
    pop_front()           O(1)
    pop_back()            O(1)


    STACK
    ------------------------------------------------------------
    push()                O(1)
    pop()                 O(1)
    top()                 O(1)


    QUEUE
    ------------------------------------------------------------
    push()                O(1)
    pop()                 O(1)
    front()               O(1)
    back()                O(1)


    SET
    ------------------------------------------------------------
    insert()              O(log n)
    erase()               O(log n)
    find()                O(log n)
    count()               O(log n)


    MAP
    ------------------------------------------------------------
    insert()              O(log n)
    erase()               O(log n)
    find()                O(log n)
    count()               O(log n)
    [] / at()             O(log n)


    IMPORTANT:

    std::set and std::map are typically implemented using a
    balanced binary search tree, commonly a Red-Black tree.

    This is why their main search/insert/erase operations are
    O(log n).
    */


    return 0;
}

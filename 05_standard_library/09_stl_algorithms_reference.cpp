#include <algorithm>
#include <array>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;


bool compareBySecond(pair<string, int> a, pair<string, int> b)
{
    /*
    Custom comparator for sorting pairs.

    Return true when a should come before b.

    This function sorts by second value in ascending order.
    If second values are equal, it sorts by first value.
    */

    if (a.second == b.second)
    {
        return a.first < b.first;
    }

    return a.second < b.second;
}

struct Student
{
    string name;
    int marks;
};

struct CompareStudent
{
    /*
    Custom comparator for priority_queue.

    IMPORTANT:
    In priority_queue, the comparator can feel opposite at first.

    Returning true means:
        "a has lower priority than b"

    This example gives highest marks the highest priority.
    */

    bool operator()(const Student& a, const Student& b)
    {
        return a.marks < b.marks;
    }
};

int main()
{
    // ============================================================
    // 1. STRING STL OPERATIONS
    // ============================================================

    /*
    string:
    - A sequence container for characters.
    - Very important for DSA string problems.
    - Supports indexing like a vector.
    - Many algorithms can be used on strings because strings have iterators.

    Common operations:
        size()
        empty()
        push_back()
        pop_back()
        front()
        back()
        substr()
        find()
        erase()
        insert()
        reverse()
        sort()

    Complexity:
        s[i]              -> O(1)
        push_back()       -> amortized O(1)
        pop_back()        -> O(1)
        substr(pos, len)  -> O(len)
        find(pattern)     -> usually O(n * m) in simple cases
        erase()           -> O(n), because characters may shift
        insert()          -> O(n), because characters may shift
    */

    string word = "leetcode";

    cout << word[0] << '\n';       // l
    cout << word.front() << '\n';  // l
    cout << word.back() << '\n';   // e

    word.push_back('s');           // "leetcodes"
    word.pop_back();               // "leetcode"

    string part = word.substr(0, 4); // "leet"

    size_t position = word.find("code");

    if (position != string::npos)
    {
        cout << "Found at index: " << position << '\n';
    }

    /*
    string::npos:
    - A special value used by string functions.
    - It means "not found".

    In DSA, always check:
        if (pos != string::npos)
    before using the result of find().
    */

    string letters = "dbca";

    sort(letters.begin(), letters.end());       // "abcd"
    reverse(letters.begin(), letters.end());    // "dcba"

    /*
    Practical DSA use:
    - Sort a string to compare anagrams.
    - Count character frequencies.
    - Use substr() for prefix/suffix/window problems.
    */

    string a = "listen";
    string b = "silent";

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (a == b)
    {
        cout << "Anagrams\n";
    }


    // ============================================================
    // 2. PAIR
    // ============================================================

    /*
    pair:
    - Stores two values together.
    - The two values can have different types.
    - Very common in DSA.

    Syntax:
        pair<type1, type2> name;

    Access:
        name.first
        name.second

    Common uses:
        coordinate -> pair<int, int>
        key/value  -> pair<string, int>
        graph edge -> pair<int, int>
        value + index -> pair<int, int>
    */

    pair<string, int> person = {"Aman", 20};

    cout << person.first << '\n';   // Aman
    cout << person.second << '\n';  // 20

    person.second = 21;

    vector<pair<string, int>> students =
    {
        {"Ravi", 85},
        {"Anu", 92},
        {"Karan", 85}
    };

    /*
    Default pair sorting:
    - Sorts by first value.
    - If first values are equal, sorts by second value.
    */

    vector<pair<int, int>> points =
    {
        {2, 5},
        {1, 9},
        {2, 3},
        {1, 4}
    };

    sort(points.begin(), points.end());

    /*
    After sorting:
        {1, 4}
        {1, 9}
        {2, 3}
        {2, 5}
    */


    // ============================================================
    // 3. TUPLE
    // ============================================================

    /*
    tuple:
    - Like pair, but can store more than two values.
    - Useful when each item needs 3 or more related values.

    Syntax:
        tuple<type1, type2, type3> name;

    Access:
        get<0>(name)
        get<1>(name)
        get<2>(name)

    In DSA, pair is used more often than tuple.
    But tuple is useful for graph edges:
        {weight, node1, node2}
    */

    tuple<int, string, double> data = {1, "Aman", 91.5};

    cout << get<0>(data) << '\n';
    cout << get<1>(data) << '\n';
    cout << get<2>(data) << '\n';

    vector<tuple<int, int, int>> weightedEdges =
    {
        {10, 1, 2},
        {5, 2, 3},
        {7, 1, 3}
    };

    sort(weightedEdges.begin(), weightedEdges.end());

    /*
    Default tuple sorting:
    - Sorts by first value.
    - If equal, then second.
    - If still equal, then third.
    */


    // ============================================================
    // 4. ARRAY
    // ============================================================

    /*
    array:
    - Fixed-size array from STL.
    - Size is known at compile time.
    - Safer and more STL-friendly than normal C-style arrays.

    Syntax:
        array<type, size> name;

    Complexity:
        access by index -> O(1)
        size()          -> O(1)

    Use vector when size can change.
    Use array when size is fixed.
    */

    array<int, 5> fixedNums = {4, 2, 9, 1, 7};

    cout << fixedNums[0] << '\n';
    cout << fixedNums.at(2) << '\n';
    cout << fixedNums.size() << '\n';

    sort(fixedNums.begin(), fixedNums.end());

    for (int num : fixedNums)
    {
        cout << num << ' ';
    }

    cout << '\n';


    // ============================================================
    // 5. MULTISET
    // ============================================================

    /*
    multiset:
    - Like set, but allows duplicate values.
    - Elements are stored in sorted order.
    - No index-based access.

    Syntax:
        multiset<type> name;

    Complexity:
        insert()    -> O(log n)
        erase()     -> O(log n) plus number of erased elements
        find()      -> O(log n)
        count()     -> O(log n + occurrences)

    Common DSA use:
    - Need sorted order with duplicates.
    - Need to repeatedly get smallest/largest value.
    - Sliding window problems with duplicates.
    */

    multiset<int> ms = {5, 1, 3, 3, 2, 5};

    ms.insert(3);

    cout << "Number of 3s: " << ms.count(3) << '\n';

    /*
    Important erase difference:

        ms.erase(3);

    removes ALL occurrences of 3.

    To remove only one occurrence:
        auto it = ms.find(3);
        if (it != ms.end())
        {
            ms.erase(it);
        }
    */

    auto oneThree = ms.find(3);

    if (oneThree != ms.end())
    {
        ms.erase(oneThree); // removes only one 3
    }

    cout << "Smallest: " << *ms.begin() << '\n';
    cout << "Largest: " << *prev(ms.end()) << '\n';


    // ============================================================
    // 6. MULTIMAP
    // ============================================================

    /*
    multimap:
    - Like map, but allows duplicate keys.
    - Stores key-value pairs in sorted key order.

    Syntax:
        multimap<keyType, valueType> name;

    Complexity:
        insert() -> O(log n)
        find()   -> O(log n)
        erase()  -> O(log n)

    Common use:
    - One key can have multiple values.

    In many DSA problems, unordered_map<key, vector<value>>
    is more common than multimap, but you should know multimap exists.
    */

    multimap<string, int> scores;

    scores.insert({"Aman", 90});
    scores.insert({"Aman", 95});
    scores.insert({"Ravi", 80});

    auto range = scores.equal_range("Aman");

    for (auto it = range.first; it != range.second; ++it)
    {
        cout << it->first << " " << it->second << '\n';
    }


    // ============================================================
    // 7. UNORDERED_SET
    // ============================================================

    /*
    unordered_set:
    - Stores unique elements.
    - Does NOT keep elements sorted.
    - Uses hashing internally.

    Syntax:
        unordered_set<type> name;

    Complexity:
        insert() -> O(1) average, O(n) worst case
        find()   -> O(1) average, O(n) worst case
        erase()  -> O(1) average, O(n) worst case

    Common DSA use:
    - Fast membership checking.
    - Detect duplicates.
    - Store visited nodes/states.

    Use set when you need sorted order.
    Use unordered_set when you only need fast lookup.
    */

    unordered_set<int> seen;

    seen.insert(10);
    seen.insert(20);
    seen.insert(10); // duplicate ignored

    if (seen.find(20) != seen.end())
    {
        cout << "20 exists\n";
    }

    vector<int> duplicateCheck = {1, 2, 3, 2, 4};
    unordered_set<int> used;
    bool hasDuplicate = false;

    for (int x : duplicateCheck)
    {
        if (used.count(x))
        {
            hasDuplicate = true;
            break;
        }

        used.insert(x);
    }

    cout << "Has duplicate: " << hasDuplicate << '\n';


    // ============================================================
    // 8. UNORDERED_MAP
    // ============================================================

    /*
    unordered_map:
    - Stores key-value pairs.
    - Keys are unique.
    - Does NOT keep keys sorted.
    - Uses hashing internally.

    Syntax:
        unordered_map<keyType, valueType> name;

    Complexity:
        insert / access / find / erase
            -> O(1) average
            -> O(n) worst case

    Common DSA use:
    - Frequency counting.
    - Two sum.
    - Prefix sum problems.
    - Fast key -> value lookup.

    Use map when you need sorted keys.
    Use unordered_map when you only need fast average lookup.
    */

    unordered_map<string, int> freq;

    vector<string> words =
    {
        "apple", "banana", "apple", "mango", "banana", "apple"
    };

    for (const string& x : words)
    {
        freq[x]++;
    }

    for (const auto& entry : freq)
    {
        cout << entry.first << " -> " << entry.second << '\n';
    }

    /*
    Important:

        freq[x]++

    If x does not exist, unordered_map creates it with value 0,
    then increments it.

    This is why unordered_map is excellent for frequency counting.
    */

    vector<int> numsTwoSum = {2, 7, 11, 15};
    int target = 9;
    unordered_map<int, int> indexOf;

    for (int i = 0; i < (int)numsTwoSum.size(); ++i)
    {
        int needed = target - numsTwoSum[i];

        if (indexOf.find(needed) != indexOf.end())
        {
            cout << "Two sum indexes: "
                 << indexOf[needed] << " " << i << '\n';
            break;
        }

        indexOf[numsTwoSum[i]] = i;
    }


    // ============================================================
    // 9. PRIORITY_QUEUE
    // ============================================================

    /*
    priority_queue:
    - A heap-based container adaptor.
    - Gives quick access to the highest-priority element.
    - By default, it is a max-heap.

    Syntax:
        priority_queue<type> name;

    Complexity:
        top()  -> O(1)
        push() -> O(log n)
        pop()  -> O(log n)

    Common DSA use:
    - K largest / K smallest problems.
    - Dijkstra's algorithm.
    - Scheduling problems.
    - Repeatedly getting min/max efficiently.
    */

    priority_queue<int> maxHeap;

    maxHeap.push(10);
    maxHeap.push(40);
    maxHeap.push(20);

    cout << maxHeap.top() << '\n'; // 40

    maxHeap.pop();

    cout << maxHeap.top() << '\n'; // 20

    /*
    Min-heap:

    priority_queue<int, vector<int>, greater<int>> minHeap;

    Meaning:
        int             -> type of element
        vector<int>     -> internal container
        greater<int>    -> comparison rule
    */

    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(10);
    minHeap.push(40);
    minHeap.push(20);

    cout << minHeap.top() << '\n'; // 10

    priority_queue<pair<int, string>> pqPairs;

    pqPairs.push({90, "Aman"});
    pqPairs.push({95, "Ravi"});
    pqPairs.push({85, "Anu"});

    cout << pqPairs.top().second << '\n'; // Ravi

    priority_queue<Student, vector<Student>, CompareStudent> studentHeap;

    studentHeap.push({"Aman", 88});
    studentHeap.push({"Ravi", 95});
    studentHeap.push({"Anu", 91});

    cout << studentHeap.top().name << '\n'; // Ravi


    // ============================================================
    // 10. EMPLACE
    // ============================================================

    /*
    emplace / emplace_back:
    - Constructs the element directly inside the container.
    - Often avoids creating a temporary object.

    For simple types like int, push_back and emplace_back feel similar.
    For pair, tuple, and custom objects, emplace can be cleaner.

    Common functions:
        vector.emplace_back()
        set.emplace()
        map.emplace()
        priority_queue.emplace()

    Complexity:
    Same big-O complexity as the matching insert/push operation.
    */

    vector<pair<string, int>> players;

    players.push_back({"Aman", 50});
    players.emplace_back("Ravi", 60);

    map<string, int> ages;

    ages.insert({"Aman", 20});
    ages.emplace("Ravi", 21);


    // ============================================================
    // 11. INSERT VARIATIONS
    // ============================================================

    /*
    insert():
    Different containers support different insert styles.

    vector:
        insert at position -> O(n)

    set / map:
        insert while maintaining sorted order -> O(log n)

    unordered_set / unordered_map:
        insert using hashing -> O(1) average
    */

    vector<int> insertNums = {1, 2, 5};

    insertNums.insert(insertNums.begin() + 2, 3); // 1 2 3 5
    insertNums.insert(insertNums.begin() + 3, 4); // 1 2 3 4 5

    vector<int> extra = {6, 7, 8};

    insertNums.insert(insertNums.end(), extra.begin(), extra.end());

    set<int> insertSet;

    insertSet.insert(10);
    insertSet.insert(5);
    insertSet.insert(10); // duplicate ignored

    map<string, int> insertMap;

    insertMap.insert({"Aman", 20});
    insertMap.insert({"Aman", 30}); // does not update existing value
    insertMap["Aman"] = 30;         // updates existing value


    // ============================================================
    // 12. ERASE VARIATIONS
    // ============================================================

    /*
    erase():
    Used to remove elements.

    vector:
        erase(iterator)              -> removes one element
        erase(startIterator, endIt)  -> removes a range
        Complexity: O(n), because elements shift

    set / map:
        erase(value/key)
        erase(iterator)
        Complexity: O(log n)

    unordered containers:
        average O(1), worst O(n)
    */

    vector<int> eraseNums = {1, 2, 3, 4, 5};

    eraseNums.erase(eraseNums.begin() + 1); // removes 2

    eraseNums.erase(eraseNums.begin(), eraseNums.begin() + 2);

    set<int> eraseSet = {1, 2, 3, 4};

    eraseSet.erase(3);

    map<string, int> eraseMap =
    {
        {"Aman", 20},
        {"Ravi", 21}
    };

    eraseMap.erase("Ravi");


    // ============================================================
    // 13. COUNT AND COUNT_IF
    // ============================================================

    /*
    count():
    - Counts how many times a value appears in a range.

    count_if():
    - Counts how many elements satisfy a condition.

    Complexity:
        O(n)

    For set:
        set.count(x) returns only 0 or 1.

    For multiset:
        multiset.count(x) can return more than 1.
    */

    vector<int> countNums = {1, 2, 2, 3, 4, 2};

    int twos = count(countNums.begin(), countNums.end(), 2);

    int evenCount = count_if(countNums.begin(), countNums.end(),
        [](int x)
        {
            return x % 2 == 0;
        });

    cout << twos << '\n';
    cout << evenCount << '\n';


    // ============================================================
    // 14. REVERSE AND ROTATE
    // ============================================================

    /*
    reverse():
    - Reverses elements in a range.
    - Complexity: O(n)

    rotate():
    - Rotates elements so that a chosen middle becomes the first.
    - Complexity: O(n)

    Syntax:
        rotate(begin, middle, end);
    */

    vector<int> revNums = {1, 2, 3, 4, 5};

    reverse(revNums.begin(), revNums.end()); // 5 4 3 2 1

    vector<int> rotNums = {1, 2, 3, 4, 5};

    rotate(rotNums.begin(), rotNums.begin() + 2, rotNums.end());

    /*
    After rotate:
        3 4 5 1 2

    Because the element at rotNums.begin() + 2 becomes first.
    */


    // ============================================================
    // 15. ACCUMULATE AND IOTA
    // ============================================================

    /*
    accumulate():
    - Calculates sum or combines values.
    - Header: <numeric>
    - Complexity: O(n)

    iota():
    - Fills a range with increasing values.
    - Header: <numeric>
    - Complexity: O(n)
    */

    vector<int> sumNums = {1, 2, 3, 4, 5};

    int total = accumulate(sumNums.begin(), sumNums.end(), 0);

    cout << total << '\n'; // 15

    vector<int> ids(5);

    iota(ids.begin(), ids.end(), 1);

    /*
    ids becomes:
        1 2 3 4 5

    DSA use:
    - Creating indexes.
    - Disjoint set union parent array initialization.
    */


    // ============================================================
    // 16. ALL_OF, ANY_OF, NONE_OF
    // ============================================================

    /*
    all_of():
        true if every element satisfies the condition.

    any_of():
        true if at least one element satisfies the condition.

    none_of():
        true if no element satisfies the condition.

    Complexity:
        O(n)

    These are useful for writing clean condition checks.
    */

    vector<int> checkNums = {2, 4, 6, 8};

    bool allEven = all_of(checkNums.begin(), checkNums.end(),
        [](int x)
        {
            return x % 2 == 0;
        });

    bool anyGreaterThanFive = any_of(checkNums.begin(), checkNums.end(),
        [](int x)
        {
            return x > 5;
        });

    bool noneNegative = none_of(checkNums.begin(), checkNums.end(),
        [](int x)
        {
            return x < 0;
        });

    cout << allEven << '\n';
    cout << anyGreaterThanFive << '\n';
    cout << noneNegative << '\n';


    // ============================================================
    // 17. REMOVE AND ERASE-REMOVE IDIOM
    // ============================================================

    /*
    remove():
    - Does NOT actually shrink the vector.
    - It moves the unwanted values to the end area and returns
      an iterator to the new logical end.

    To actually remove elements from a vector, use:

        v.erase(remove(v.begin(), v.end(), value), v.end());

    This is called the erase-remove idiom.

    Complexity:
        remove() -> O(n)
        erase()  -> O(n)
    */

    vector<int> removeNums = {1, 2, 3, 2, 4, 2, 5};

    removeNums.erase(
        remove(removeNums.begin(), removeNums.end(), 2),
        removeNums.end()
    );

    /*
    removeNums becomes:
        1 3 4 5
    */

    vector<int> removeIfNums = {1, 2, 3, 4, 5, 6};

    removeIfNums.erase(
        remove_if(removeIfNums.begin(), removeIfNums.end(),
            [](int x)
            {
                return x % 2 == 0;
            }),
        removeIfNums.end()
    );

    /*
    removeIfNums becomes:
        1 3 5
    */


    // ============================================================
    // 18. UNIQUE
    // ============================================================

    /*
    unique():
    - Removes consecutive duplicates logically.
    - Like remove(), it does not shrink the container by itself.
    - It returns the new logical end.

    Important:
    unique() only removes consecutive duplicates.
    So if you want all duplicates removed, sort first.

    Complexity:
        O(n)
    */

    vector<int> uniqueNums = {1, 1, 2, 2, 2, 3, 1, 1};

    uniqueNums.erase(
        unique(uniqueNums.begin(), uniqueNums.end()),
        uniqueNums.end()
    );

    /*
    Result:
        1 2 3 1

    The final two 1s were consecutive, so they became one 1.
    But the earlier 1 and later 1 are not considered duplicates
    because they were separated by other values.
    */

    vector<int> removeAllDuplicates = {4, 1, 2, 1, 4, 3, 2};

    sort(removeAllDuplicates.begin(), removeAllDuplicates.end());

    removeAllDuplicates.erase(
        unique(removeAllDuplicates.begin(), removeAllDuplicates.end()),
        removeAllDuplicates.end()
    );

    /*
    After sort + unique:
        1 2 3 4
    */


    // ============================================================
    // 19. NEXT, PREV, AND DISTANCE
    // ============================================================

    /*
    next(iterator, steps):
    - Returns an iterator moved forward by steps.

    prev(iterator, steps):
    - Returns an iterator moved backward by steps.

    distance(first, second):
    - Returns how many steps from first to second.

    Complexity:
    - For vector/deque/string iterators: usually O(1)
    - For list/set/map iterators: O(n)

    Useful when working with set/map where you cannot use +1.
    */

    vector<int> ndNums = {10, 20, 30, 40, 50};

    auto secondElement = next(ndNums.begin());
    auto lastElement = prev(ndNums.end());

    cout << *secondElement << '\n'; // 20
    cout << *lastElement << '\n';   // 50

    int index = distance(ndNums.begin(), secondElement);

    cout << index << '\n'; // 1

    set<int> ndSet = {5, 10, 15, 20};

    auto setIt = next(ndSet.begin(), 2);

    cout << *setIt << '\n'; // 15


    // ============================================================
    // 20. CUSTOM COMPARATORS AND LAMBDAS
    // ============================================================

    /*
    Comparator:
    - A rule that tells sorting/containers which element comes first.

    For sort():
        comparator(a, b) returns true if a should come before b.

    Common examples:
        sort ascending
        sort descending
        sort pairs by second value
        sort strings by length
    */

    vector<int> compNums = {5, 1, 4, 2, 3};

    sort(compNums.begin(), compNums.end(), greater<int>());

    /*
    greater<int>() sorts in descending order:
        5 4 3 2 1
    */

    vector<pair<string, int>> marks =
    {
        {"Ravi", 85},
        {"Aman", 92},
        {"Anu", 85}
    };

    sort(marks.begin(), marks.end(), compareBySecond);

    /*
    Lambda function:
    - A small function written directly where it is needed.

    Syntax:
        [](parameters)
        {
            return condition;
        }
    */

    vector<string> names = {"Aman", "Ravi", "Christopher", "Anu"};

    sort(names.begin(), names.end(),
        [](const string& x, const string& y)
        {
            return x.size() < y.size();
        });

    /*
    Sort strings by length.
    If you also want alphabetical order when lengths are equal:
    */

    sort(names.begin(), names.end(),
        [](const string& x, const string& y)
        {
            if (x.size() == y.size())
            {
                return x < y;
            }

            return x.size() < y.size();
        });


    // ============================================================
    // 21. CUSTOM SET AND MAP ORDER
    // ============================================================

    /*
    set and map can also use custom ordering.

    Simple descending set:
        set<int, greater<int>> s;

    For more complex rules, use a comparator struct or lambda.
    */

    set<int, greater<int>> descendingSet = {1, 5, 2, 9};

    for (int x : descendingSet)
    {
        cout << x << ' ';
    }

    cout << '\n';

    auto lengthCompare = [](const string& x, const string& y)
    {
        if (x.size() == y.size())
        {
            return x < y;
        }

        return x.size() < y.size();
    };

    set<string, decltype(lengthCompare)> wordsByLength(lengthCompare);

    wordsByLength.insert("banana");
    wordsByLength.insert("kiwi");
    wordsByLength.insert("apple");
    wordsByLength.insert("fig");

    /*
    IMPORTANT:
    For set/map comparators, two values are considered equal if:
        comp(a, b) == false
        and
        comp(b, a) == false

    So your comparator must create a clear ordering.
    */


    // ============================================================
    // 22. IMPORTANT ITERATOR LIMITATIONS
    // ============================================================

    /*
    Not all iterators support the same operations.

    vector / deque / string:
        it + 1 works
        it - 1 works
        sort(begin, end) works

    list / set / map:
        it + 1 does NOT work
        use next(it) instead

    stack / queue / priority_queue:
        do not expose normal iterators

    Important examples:
        sort(vector.begin(), vector.end()) works.
        sort(list.begin(), list.end()) does NOT work.
        list.sort() works.
        sort(set.begin(), set.end()) is unnecessary and does not work.
    */


    // ============================================================
    // 23. PRACTICAL DSA STL PATTERNS
    // ============================================================

    /*
    Pattern 1:
    Frequency counting

    Tool:
        unordered_map

    Use when:
        You need to count how many times each value appears.
    */

    vector<int> freqNums = {1, 2, 2, 3, 1, 2};
    unordered_map<int, int> numberFreq;

    for (int x : freqNums)
    {
        numberFreq[x]++;
    }

    /*
    Pattern 2:
    Fast duplicate check

    Tool:
        unordered_set
    */

    vector<int> maybeDuplicates = {4, 1, 7, 4};
    unordered_set<int> alreadySeen;
    bool duplicateFound = false;

    for (int x : maybeDuplicates)
    {
        if (alreadySeen.count(x))
        {
            duplicateFound = true;
            break;
        }

        alreadySeen.insert(x);
    }

    cout << "Duplicate found: " << duplicateFound << '\n';

    /*
    Pattern 3:
    Top K largest elements

    Tool:
        min-heap priority_queue

    Idea:
        Keep only K largest values in a min-heap.
        If heap size becomes bigger than K, remove the smallest.
    */

    vector<int> topNums = {7, 10, 4, 3, 20, 15};
    int k = 3;
    priority_queue<int, vector<int>, greater<int>> topK;

    for (int x : topNums)
    {
        topK.push(x);

        if ((int)topK.size() > k)
        {
            topK.pop();
        }
    }

    cout << "3rd largest: " << topK.top() << '\n';

    /*
    Pattern 4:
    Prefix sum with unordered_map

    Problem style:
        Count subarrays with sum equal to target.
    */

    vector<int> prefixNums = {1, 2, 3, -2, 5};
    int requiredSum = 5;
    int prefixSum = 0;
    int subarrayCount = 0;
    unordered_map<int, int> prefixFrequency;

    prefixFrequency[0] = 1;

    for (int x : prefixNums)
    {
        prefixSum += x;

        int need = prefixSum - requiredSum;

        if (prefixFrequency.find(need) != prefixFrequency.end())
        {
            subarrayCount += prefixFrequency[need];
        }

        prefixFrequency[prefixSum]++;
    }

    cout << "Subarrays with sum 5: " << subarrayCount << '\n';

    /*
    Pattern 5:
    Sorted unique values

    Tool:
        set

    Use when:
        You need unique values in sorted order.
    */

    vector<int> rawValues = {4, 2, 2, 1, 4, 3};
    set<int> sortedUnique(rawValues.begin(), rawValues.end());

    /*
    Pattern 6:
    Coordinate / index pairs

    Tool:
        pair<int, int>
    */

    vector<pair<int, int>> directions =
    {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };

    int row = 3;
    int col = 4;

    for (const auto& direction : directions)
    {
        int newRow = row + direction.first;
        int newCol = col + direction.second;

        cout << newRow << " " << newCol << '\n';
    }


    // ============================================================
    // 24. QUICK CONTAINER CHOICE GUIDE
    // ============================================================

    /*
    Need dynamic array?
        vector

    Need fixed-size array?
        array

    Need fast push/pop at both ends?
        deque

    Need LIFO?
        stack

    Need FIFO?
        queue

    Need unique sorted values?
        set

    Need sorted values with duplicates?
        multiset

    Need key -> value in sorted key order?
        map

    Need duplicate keys in sorted key order?
        multimap

    Need fast average membership check?
        unordered_set

    Need fast average key -> value lookup?
        unordered_map

    Need repeated largest/smallest element?
        priority_queue

    Need two values together?
        pair

    Need three or more values together?
        tuple
    */

    return 0;
}

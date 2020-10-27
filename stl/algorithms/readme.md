## Q?

- What operators are overloaded in each of the 5 basic iterator types?
- What is the asymptotic behavior of sorting in STL? What is the basis of this sorting?
- How is the copy () algorithm implemented?
- What is lexicographic order?
- How does copy () & copy_if (), find () & find_if () algorithms differ?
- What do the for_each () & transform () algorithms do?


## Iterators

- An iterator is a generalization for a pointer, a smart pointer relative to containers -
provides a standard interface for accessing elements of (standard) containers, which support iterators, without regard to how it works and developed a container from the inside and what data is stored inside this container.
- The basic types of iterators are input, output, unidirectional, bidirectional, and random access.

```txt
InputIterator: {* = ++ -> == !=}
- read
- increment (1)

OutputIterator: {* = ++}
- write
- increment (1)

ForwardIterator: InputIterator, OutputIterator
- increment (N)

BidirectionalIterator: ForwardIterator
- decrement (N)
{* = ++ -> == != --}

RandomAccessIterator: BidirectionalIterator
- at(index)
{* = ++ -> == != -- + - [] < > <= >= += -=}
```

- std::advance() - shift, std::distance() – distance!.
- (back_\front_\)inserter() – isertion into container.
- next()\prev() - ++\--
- std::move_iterator – moving elements from one container-owner to another.

## Algorithms

```txt
- for_each  [not modifies, calls foo() for each element];
- make_heap [ heap1 union heap2 = notheap12, make_heap(notheap12) = heap3];
- push_heap [ 1 element insertion, like v.push_back(x)];
- pop_heap  [ head goes to the end of container];

- sort          [full memory sort];
- partial_sort  [ sort for first N elements, rest - undefined order];
- nth_element   [ array <<0, ..., nth, ..., last >>; for array part[0,nth): a[i] < a[nth]; for part(nth,last]: a[i] > a[nth];undefined order];
- sort_heap     [fastest sort for heap];
- inplace_merge [ like incremental step in merge_sort (2 arrs are already sorted)];

- partition         [sort by predicate, array <<0, ..., partition_point, ..., last>>; part[0,nth): true; part(nth,last]: false];
- partition_point   [ search for partiion_point];

- rotate                                [ was a[last], now is a[0]];
- shuffle                               [randomize order];
- next_permutation and prev_permutation [ iterate order in alphabetical imaginable set of all possible orders ];
- reverse                               [ yep ];
- sample                                [Selects n elements from the sequence [first; last) (without replacement) such that each possible sample has equal probability of appearance, and writes those selected elements into the output iterator out. Random numbers are generated using the random number generator g.];

- stable_       [stable_sort, stable_partition];
- is_           [is_sorted, is_partitioned, is_heap];
- is_*_until    [_sorted_, _partitioned_, _heap_];

- count         [ numeric specialization];
- accumulate    [ sum with init value if container is empty];
- reduce        [behaves like accumulate except the elements of the range may be grouped and rearranged in arbitrary order];
- transform_reduce [the results of unary_op or of binary_op1 may be grouped and arranged in arbitrary order];
- partial_sum   [ yep ];
- transform_inclusive_scan and _exclusove_scan [transforms each element in the range [first, last) with unary_op, then computes an inclusive prefix sum operation using binary_op over the resulting range];
- inner_product [Computes inner product (i.e. sum of products) or performs ordered map/reduce operation on the range [first1, last1) and the range beginning at first2];
- adjacent_difference [Computes the differences between the second and the first of each adjacent pair of elements of the range [first, last) and writes them to the range beginning at d_first + 1. An unmodified copy of *first is written to *d_first.];

- all_of, any_of, none_of [elements, for empty: true, flase, true];
- equal [range, true for empty];
- is_permutation [range, true];
- lexicographical_compare [true if the first range is lexicographically less than the second];
- mismatch [first difference std::pair or mismatch];

- find                      [ element, not sorted ranges ]
- adjacent_find             [ pair, not sorted ranges ]
- equal_range               [ pair, sorted ranges]
- lower_bound, upper_bound  [it, sorted ranges]
- binary_search             [bool, yep]

- search        [ find the range]
- find_end      [finds the last sequence of elements in a certain range]
- find_first_of [first of range match]

- max_element, min_element, minmax_element  [it,it,pair]

- set_union                 [c++ set means sorted container, A and B, std::max(n,m) occurances of eq elements]
- set_difference            [copies not found in B]
- set_instersection         [found in A and in B]
- set_symetric_difference   [found in A and in B are excluded]
- include                   [bool]
- merge                     [like set_union, but (n+m) occurances of eq elements]

- move          [yep]
- swap_ranges   [same sizes]
- fill          [like C-array init]
- generate      [fill using foo()]
- iota          [fill with increment]
- replace       [yep]

- remove        ["move" owned value to the end of the container, undefined, IRL: elements are shifted => may do erase()]
- unique        ["move" non-unique values to the end of the container, undefined ]

- _copy     ["do_smth_then_copy"; remove_copy, rotate_copy, partial_sort, unique, reverse, replace, partition, partial_sort];
- _if       ["do_smth_if"; ...]
- _copy_if  ["do_smth_then_copy_if"; ...]

- transform     [ arr<<x1,x2,...,xN>>, result: arrR<<f(x1), f(x2), ..., f(xN)>>]
- transform     [ arrX<<x1,x2,...,xN>>,  arrY<<y1,y2,...,yN>>, result: arrR<<f(x1,y1), f(x2,y2), ..., f(xN,yN)>>]

- uninitialized_fill, fill            [calls ctor, copy-assigns]
- uninitialized_copy, copy            [calls copy-ctor, copy-assigns]
- uninitialized_move, move            [calls move-ctor, move-assigns]
- destroy                             [calls destructor]
- uninitialized_defualt_construct     [calls default ctor]
- uninitialized_value_construct       [calls ctor with args]
- _n                                  ["do_smth_for_first_n_elements", ...];

```

## links

https://www.youtube.com/watch?v=2olsGf6JIkU (105 algo in an hour)
https://en.cppreference.com/w/cpp/algorithm
https://www.codeproject.com/Articles/854127/Top-Beautiful-Cplusplus-std-Algorithms-Examples
http://cs.stmarys.ca/~porter/csc/ref/stl/iterators.html
https://github.com/caiorss/C-Cpp-Notes/blob/master/STL%20Iterators%20and%20Algorithms.org
https://en.cppreference.com/w/cpp/iterator

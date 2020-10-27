# explicit placeholder

when are you going to fill it, hm?

std::Deque is a map of chunks.

* many push_back() - vector::reserve().
* many deallocations - deque take more time then vector
* many insert() or pop_front() use deque.
* vector::at() has checks

## links
https://www.codeproject.com/Articles/5425/An-In-Depth-Study-of-the-STL-Deque-Container

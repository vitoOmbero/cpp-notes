TODO-todo, toDO-TOdo, toDO-toDo

## Q?

- difference from thread-based?
- difference std::promise from std::packaged_task?
- std::async, problem, solution, when better then std::thread?
- task-based msg to the thread?
- execution policy?

## some notes

std::async - task is a functional object

(+)
- returned typed value
- get() when ready
- exceptions included
- library thread managing responsability, not yours

threads are better
- access to thread realisation of API
- optimization
- custom (hardware/platform friendly) threading model

When auto fut = std::async(f):
- undefined run time of execution 
- undefined executed thread
- undefined result

https://meetingcpp.com/mcpp/slides/2018/BestPractices.pdf



## links

https://docs.microsoft.com/en-us/cpp/standard-library/future?view=vs-2017
https://www.modernescpp.com/index.php/promise-and-future
http://scrutator.me/post/2012/06/03/parallel-world-p2.aspx
https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#S-concurrency
https://ru.cppreference.com/w/cpp/thread/async
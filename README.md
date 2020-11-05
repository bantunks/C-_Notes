# C-_Notes
C++ Study Notes and Practice Programs

***********************************************************************************************************************************************************************************
From https://stackoverflow.com/questions/4636182/problem-with-stdmapiterator-after-calling-erase --
Erasing an element of a map invalidates iterators pointing to that element (after all that element has been deleted). You shouldn't reuse that iterator.

Since C++11 erase() returns a new iterator pointing to the next element, which can be used to continue iterating:

it = mymap.begin();
while (it != mymap.end()) {
   if (something)
      it = mymap.erase(it);
   else
      it++;
}
Before C++11 you would have to manually advance the iterator to the next element before the deletion takes place, for example like this:

mymap.erase(it++);
This works because the post-increment side-effect of it++ happens before erase() deletes the element. Since this is maybe not immediately obvious, the C++11 variant above should be preferred.

***********************************************************************************************************************************************************************************
From https://stackoverflow.com/questions/15325730/priority-queue-of-custom-class-using-comparator-with-argument-on-constructor-in

How to pass extra arguments to custom comparators for priority_queue in C++ ?

The template parameter is the type of the comparator. You still need to pass an instance of the comparator to the priority_queue constructor, and that is when you can construct the comparator instance with whatever parameters you like.

For instance:

map<int, glm::mat4x4> m;
edgeCompare comp(m);
priority_queue<Edge, vector<Edge>, edgeCompare> pq(comp);
You can also create the edgeCompare object inline but extra parentheses are needed for disambiguation:

priority_queue<Edge, vector<Edge>, edgeCompare> pq((edgeCompare(m)));
   ***********************************************************************************************************************************************************************************

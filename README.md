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

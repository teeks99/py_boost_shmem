# py_boost_shmem
An example of mapping shared memory between boost::interprocess and Python's
mmap. 

I was having a problem connecting shared memory in python (using the mmap
module) to shared memory in C++ created using boost::interprocess. I got
it working and wanted to post the solution somewhere for myself in the 
future as well as anyone else who may have this issue.

This example was written along with a [corresponding stack overflow 
question](https://stackoverflow.com/questions/31028012/access-a-boostinterprocess-shared-memory-block-from-python-with-ctypes)

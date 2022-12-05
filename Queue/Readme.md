# Queue based on a circular buffer
A circular buffer is based on an array of fixed size which is virtually connected end to end,
i.e. when the end of the array is reached, writing is done at the start of the array.
In this case, as the buffer is used for a queue, when the maximum capacity is reached,
an error code should be returned when trying to add more elements to the queue.
Attempting to dequeue an element from an empty queue should also result in an error.

### To compile : Run make and define Queue capacity

    make capacity=?

    or just

    make

    ?: is a user input value (by default queue capacity is 5)

### To clean : Clean object/binary files with

    make clean

### To run tests : After "make"/"make capacity=?" run

    make test

### To generate docs : Run command

    make doc

    Then open index.html by your favorite web browser.


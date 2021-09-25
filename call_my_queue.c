#include <unistd.h>
#include <stdio.h>

int main(void)
{
syscall(547);
syscall(547);
syscall(547);
syscall(547);
syscall(547);
//547 (dequeue) 5 times to flush queue. (To be empty queue)

int r;
syscall(546, 1);
syscall(546, 2);
syscall(546, 3);
syscall(546, 3);
r = syscall(547);
//546 (enqueue) enqueueing 1-2-3-3(intend error)
//547 (dequeue) dequeue once.
//Finally, in Queue must be remain 2-3
}


//Implement Circular Queue by Integer array.

#include <linux/kernel.h>
#define MAX 10

int front=0;
int rear=0;
int queue[MAX]; //declare queue having 9rooms. (circular queue)

asmlinkage void sys_my_enqueue(int val){
    int i;
    for (i=front;i<rear;i++){
            if(queue[i]==val){ //if enqueue value is already in queue
	    printk(KERN_CRIT "Enqueue %d Failed. Same value in queue.\n",val);
	    return;
	}
    }

    if(front==(rear+1)%MAX)printk(KERN_CRIT "Enqueue Failed. Queue is Full.\n");
	//just return if queue is full
    else{
	queue[rear]=val;
	rear=(rear+1)%MAX;
	printk(KERN_CRIT "Enqueue %d Success! \n",val);
	//print queue
	for(i=front;i<rear;i++){
	    printk(KERN_CRIT "%d ",queue[i]);
	}
	printk(KERN_CRIT "\n");
    }
}
asmlinkage int sys_my_dequeue(void){
    int i;
    if (front==rear) {
        printk(KERN_CRIT "Queue is Empty.\n");
        return -1;    //if queue is empty, return -1 (means err)
    }
    else{
	int tmp=queue[front]; //store tmp variable for return dequeue.
	front=(front+1)%MAX;
	printk(KERN_CRIT "Dequeue Success!\n");
	//print queue
	for(i=front;i<rear;i++){
	    printk(KERN_CRIT "%d ",queue[i]);
	}
	printk(KERN_CRIT "\n");

	return tmp;
    }
}

//Printing queue status
asmlinkage void sys_my_printqueue(void){
    int i;
    printk(KERN_CRIT "this is the queue.\n");
	for (i=front;i<rear;i++){
		printk(KERN_CRIT "%d",queue[i]);
	}
	printk(KERN_CRIT "\n");
}

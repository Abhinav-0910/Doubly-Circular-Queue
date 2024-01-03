# Doubly-Circular-Queue
C programming to make a queue data structure. Implement an ADT called Circular Deque using the queue data structure. A deque is known as a double-ended queue. Implement a Circular Deque which performs the required Operations.
• void Push(Queue head,int val): Creates a new node containing the integer val and inserts at the end of the circular Deque.
• int Pop(Queue head): Remove the front element in the Circular Deque and return it. If there is no element in Circular Deque, return -1.
• void Inject(Queue head,int val): Creates a new node containing the integer val and adds it to the front end of the circular Deque.
• int popRear(Queue head): Remove the last element in the Circular Deque and return it.If there is no element in Circular Deque, return -1.
• void Print(Queue head): Prints the Circular Deque from the first element.If deque is empty, Print -1.
• void PrintReverse(Queue head): Prints the Circular Deque in reverse manner. If deque is empty, Print -1.
• int findElem(Queue head, int pos): Find the element in the given position and return it. If there is no element present in the given position, return -1. Consider 
  the Circular Deque as 1-indexed.
• void removeKElems(Queue head,int k): Remove the front k elements in the Circular Deque. If k is greater than the size of deque, remove all the elements.

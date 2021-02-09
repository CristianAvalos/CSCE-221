- Cristian Avalos
- UIN: 627003137
- Section 501
- avalos672918
- avalos672918@tamu.edu

I certify that I have listed all the sources that I used to develop the solutions and code to the
submitted work.
On my honor as an Aggie, I have neither given nor received any unauthorized help
on this academic work.
Cristian Avalos         03/05/2020

- My min function for some reason only works for some test cases. I am not sure if it is a problem with 
string comparions or not but it works for my list1 second test but not my first test. In my code I will 
comment where it doesn't work.

- My code utilizes functions from the templated doubly linked list that I had created from the last
assignment. I did this by using the adapter design pattern. The enqueue function uses the "insert_last"
function from the tdll. The dequeue utilizes the "remove_first" function from the dll. The size function
 simply returns a count that I keep track of every time that the enqueue and dequeue functions are used 
 and lastly the is empty function is also from the dll function "is_empty". All of these funtion have a
 constant run time because they do not need to iterate through the minqueue. However, my min function does not
 have a constant run time because it has to iterate through the minqueue and compare each node with the min
 node and update if it is less. I had also created a printItems function which lists the values in the 
 minqueue. This function was only for testing purposes because it allowed me to see all of the nodes that
 I have in the lists. It was not required but I made it for myself.

- I tested my program by creating a main funtion in which I called the functions that I had created
in order to ensure that they performed as they should. The variables that I used for the minqueue were strings.
I would list out the results and check if I got the same results as I would do by hand. I believe that I had 
tested every function that I created.
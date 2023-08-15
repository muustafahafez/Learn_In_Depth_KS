- FIFO - First In First Out - and LIFO -Last In First Out- are two common types of data strctures.

- In LIFO (stack):
	* The last input data is the first output data , which can be very useful to use as a buffer to store data coming from some sensor.
	* One of its advantages is that we can do processing on the last data we get while the previous one is still stored not overrided like
	  that if we recived it in a global variable.
	* The buffer can be implemented statically using array or dynamically using dynamic memory allocation. 
	* In Embedded world, we alawys prefer to use static allocation.

- In FIFO (queue):
	* The first input data is the first output data , which can be very useful to use as a buffer to store data coming from some peripheral like UART
	* One of its advantages is that we can store the data coming from the UART and sent it byte by byte.
	* The buffer can be implemented statically using array or dynamically using dynamic memory allocation. 
	* In Embedded world, we alawys prefer to use static allocation.

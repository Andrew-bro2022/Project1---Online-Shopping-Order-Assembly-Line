# Project1---Online-Shopping-Order-Assembly-Line
Using C++ to develop a simulation of an assembly line with any number of stations. This application can help customers to autofill the requested orders and products depending on different sceneries. Below is the flow chart. 

![assemblyline](https://user-images.githubusercontent.com/97316979/211911917-ab84ff79-fdd4-4af5-9c13-056dfb72dae5.jpg)

More details about the project:
The assembly line in the solution consists of a set of workstations each of which holds a set of stock items, which are specific to the station. 
A line manager moves customer orders along the line filling the orders at each station, as requested. 
Each customer order consists of a list of items that need to be filled. 
Each station processes a queue of orders by filling the next order in the queue if that order requests the station's item and that item is in stock. 
The line manager keeps moving the customer orders from station to station until all orders have been processed. 
Any station that has used all the items in stock cannot fill any more orders. 
At the end of the line, orders are either completed or incomplete due to a lack of inventory at one or more stations. 
The simulator lists the completed orders and those that are incomplete once the line manager has finished processing all orders.

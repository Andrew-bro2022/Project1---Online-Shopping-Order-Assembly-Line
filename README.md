# Project1---Online-Shopping-Order-Assembly-Line
**Summary**: Using C++ to develop a simulation of an assembly line with any number of stations. This application can help customers to autofill the requested orders and products depending on different sceneries. Below is the flow chart. 

![assemblyline](https://user-images.githubusercontent.com/97316979/211911917-ab84ff79-fdd4-4af5-9c13-056dfb72dae5.jpg)

**More details about the project**:

-The assembly line in the solution consists of a set of workstations each of which holds a set of stock items, which are specific to the station. 

-A line manager moves customer orders along the line filling the orders at each station, as requested. 

-Each customer order consists of a list of items that need to be filled. 

-Each station processes a queue of orders by filling the next order in the queue if that order requests the station's item and that item is in stock. 

-The line manager keeps moving the customer orders from station to station until all orders have been processed. 

-Any station that has used all the items in stock cannot fill any more orders. 

-At the end of the line, orders are either completed or incomplete due to a lack of inventory at one or more stations. 

-The simulator lists the completed orders and those that are incomplete once the line manager has finished processing all orders.



**Technical Highlight Parts**:

1. Part 1:
Part 1 implements and tests the Utilities and Station modules.

The Utilities module supports the parsing of input files, which contain information used to setup and configure the assembly line.
The Station module manages information about a station on the assembly line, which holds a specific item and fills customer orders.

2.  Part 2:
Part 2 implements and tests the CustomerOrder module.

The CustomerOrder module contains all the functionality for processing customer orders as they move from Station to Station along the assembly line. The Station where a given order currently rests fills a request for one item of that station, if there is any such request.
  
3. Part 3:
Part 3 implements and tests the Workstation and LineManager modules.

The LineManager module first configures the assembly line and then moves CustomerOrders along it (from start to finish). The LineManager object configures the Workstation objects identified by the user, and moves orders along the line one step at a time. A Workstation is a Station that the LineManager has activated on the user's request. At each step, every Workstation fills one item in a Customer Order, if possible. The manager moves orders from station to station. Once an order has reached the end of the line, it is either complete or incomplete. An order is incomplete if one or more stations had an insufficient number of items in stock to cover that order's requests.  

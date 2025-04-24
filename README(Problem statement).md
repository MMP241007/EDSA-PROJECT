# EDSA-PROJECT
# PROBLEM STATEMENT

Assignment Question 1: Robotic Assembly Line Simulator 

You are a junior engineer designing a Robotic Assembly Line Simulator for a futuristic car manufacturing plant. The plant uses robots to assemble car parts (e.g., engine, chassis, wheels, doors, battery) in a highly efficient manner. To manage the workflow, you need to implement data structures for the following subsystems:
1.	Part Delivery System (Queue): Car parts arrive via a conveyor belt and are queued for processing.
2.	Robot Arm Task Manager (Stack): The robot arm picks parts from the queue and stacks them temporarily in a Last-In-First-Out (LIFO) order to assemble a car prototype.
3.	Assembly Storage Unit (Array): Completed car prototypes are stored in an array-based garage with a fixed capacity of 8 slots. If the garage is full, the oldest prototype is shipped out.
4.	Repair and Upgrade Tracker (Linked Lists):
○	Defective prototypes are tracked in a singly linked list.
○	Repaired prototypes move to a doubly linked list, allowing engineers to revisit them in both directions.
○	High-priority prototypes (e.g., for VIP clients) are cycled in a circular linked list for urgent upgrades.
Objective: Design and simulate this system using data structures, showcasing how parts flow through the assembly line, get processed, stored, and repaired.
________________________________________
Tasks:
a) Part Delivery and Robot Arm 
●	Simulate the arrival of 6 car parts (e.g., "Engine", "Chassis", "Wheels", "Doors", "Battery", "Hood") into a queue using a conveyor belt.
●	The robot arm picks parts from the queue and stacks them in a LIFO order to assemble a prototype. Write pseudocode or an algorithm to:
○	Enqueue all 6 parts.
○	Dequeue and push them onto a stack one by one.
○	Pop the stack to show the assembly order.
●	Creativity Bonus: Describe (in 2-3 sentences) how the robot arm prioritizes parts based on their stack position (e.g., "Hood" must be last for aesthetic finishing).
b) Assembly Storage Unit 
●	After assembly, store the prototypes in an array-based garage with 8 slots.
●	Simulate adding 10 prototypes (e.g., "Car1", "Car2", ..., "Car10"). If the garage is full, remove the oldest prototype (first-in) to make space for the new one.
●	Write pseudocode or an algorithm to:
○	Insert the first 8 prototypes.
○	Handle the overflow for "Car9" and "Car10".
●	Creativity Bonus: Suggest a mechanical reason (in 2-3 sentences) why the oldest prototype is shipped out (e.g., rust prevention or client delivery schedule).
c) Defective Prototype Tracker 
●	During testing, "Car3" and "Car6" are found defective. Add them to a singly linked list.
●	After repairs, move "Car3" to a doubly linked list for further inspection.
●	Write pseudocode or an algorithm to:
○	Insert "Car3" and "Car6" into the singly linked list.
○	Delete "Car3" from the singly linked list and insert it into the doubly linked list.
○	Traverse the doubly linked list forward and backward to verify "Car3".
●	Creativity Bonus: Propose (in 2-3 sentences) a mechanical defect for "Car3" and how it’s fixed (e.g., loose bolts tightened by a robotic wrench).
d) VIP Priority Upgrades 
●	For VIP clients, "Car1" and "Car5" need urgent upgrades (e.g., turbo engines). Add them to a circular linked list.
●	Write pseudocode or an algorithm to:
○	Insert "Car1" and "Car5" into the circular linked list.
○	Traverse the list twice to simulate two rounds of upgrade checks.
Creativity Bonus: Invent (in 2-3 sentences) a fun upgrade for "Car1" or "Car5" (e.g., "Car5 gets a solar-powered roof for eco-friendly VIPs").

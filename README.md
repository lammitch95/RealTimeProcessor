# RealTimeProcessor

### Description
This is a multithreaded data processing application that simulates the collection and processing of sensor data in real time. 
The application generates sensor objects for various types (Temperature, Pressure, and Voltage), processes the data in parallel using multithreading, 
and then provides statistical analysis for each sensor type, such as average, minimum, and maximum values. Additionally, 
it visualizes the processing times of each object using scatter charts, displaying real-time performance metrics.

### Multithreading Concept and Design
* Utilizes a thread pool to manage threads efficiently, reusing threads to reduce overhead and improve performance.
* Split the data  into chunks based on the number of available CPU cores ensuring even distribution.
* Launch threads each responsible for processing a chunk of data. Use lambda functions to encapsulate the work logic for each thread.
* Use atomic counters to safely update shared variables.
* Periodically update progress and emit signals for UI responsiveness.
* Wait for all threads to finish using join() to ensure the main program flow doesn’t continue prematurely.

### Demo
![DemoGifRealTimeProc](https://github.com/user-attachments/assets/8753ac13-f929-4752-9b39-ed3cc87dc68d) 

#### Single-Threaded vs. Multithreaded Processing
##### The following GIF demonstrates the workflow of the application, including:
1. Single-threaded object generation: The creation of 700k+ sensor objects.
2. Multithreaded data processing: The calculation of statistical data and visualization of processing times.
   
Notice the significant reduction in processing time when switching to multithreading for data processing tasks

### Key Features

* Utilizes Qt's threading capabilities to process large datasets in parallel, reducing processing time.
* Generates synthetic sensor data for different types, such as temperature, pressure, and voltage.
* Displays average, minimum, and maximum values for each sensor type.
* Dynamically updates a scatter chart showing the processing times of sensor data objects, offering a visual representation of performance.
* Supports different types of sensors, and allows for adding more sensor types in the future.

## Technologies

* C++,Qt Creator

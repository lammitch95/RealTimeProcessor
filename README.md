#RealTimeProcessor

###Description
This is a multithreaded data processing application that simulates the collection and processing of sensor data in real time. 
The application generates sensor objects for various types (Temperature, Pressure, and Voltage), processes the data in parallel using multithreading, 
and then provides statistical analysis for each sensor type, such as average, minimum, and maximum values. Additionally, 
it visualizes the processing times of each object using scatter charts, displaying real-time performance metrics.

###Key Features

*Utilizes Qt's threading capabilities to process large datasets in parallel, reducing processing time.
*Generates synthetic sensor data for different types, such as temperature, pressure, and voltage.
*Displays average, minimum, and maximum values for each sensor type.
*Dynamically updates a scatter chart showing the processing times of sensor data objects, offering a visual representation of performance.
*Supports different types of sensors, and allows for adding more sensor types in the future.

##Technologies

*C++,Qt Framework

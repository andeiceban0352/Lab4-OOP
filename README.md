# The Hierarchy of a Taxi Company

#General class of hierarchy: Taxi Company


#Ride Type : here we have ride_price interface
Here we override the function
- Standart (ride_price()) 
- Premium (ride_price())

#In Person class we have  rank interface
Here we overide the function
- Customer
- Operator
- Admin
- Taxi_Driver

#Taxi_Company the main class with one interface

+ Is has three inntermediary children 

- Car

- Person

- Economy Management

Also, entityes person and Economy Management has their children

#Person

1.Customer - place a request for a ride

2.Operator - take the request from the customer and process it

3.Taxi Driver - take the ride

4.Admin - manage the company

#Economy Management

1.Salary - calculate the salaray for each person of the company

2.Payment - represent the method of payment, also the value for the ride

3.Income - calculate the company income

4.Rating - return the ride rating

5.Booking - get all  details of the ride

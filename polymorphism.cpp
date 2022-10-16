#include "iostream"
#include "string"
#include "cstdlib"

using namespace std;

class Taxi_Company
{
public:
    virtual void info() {
        cout << "This is the Taxi Company";
        cout << "It contains all the information about the Company !";
    }

};

class Ride_Type:public Taxi_Company{
public:
    float start_ride;
    float cost_per_km;
    float cost_per_min;
    float price;
    float distance;
    float time;

    virtual float ride_price() = 0;

    virtual void comfort_type(){
        //
    }

    void setTime(float x) {
        time = x;
    }

    void setDistance(float x){
        distance = x;
    }
};

class Standart:public Ride_Type{
public:
    float start_ride = 29;
    float cost_per_km = 5.5;
    float cost_per_min = 0.38;

    float ride_price() override{
        price = start_ride + (cost_per_km * distance) + (cost_per_min * time);
        return price;
    }

    void comfort_type() override{
        cout << "This Ride will be confortable !!" << endl;
    }

};

class Premium:public Ride_Type{
public:
    float start_ride = 70;
    float cost_per_km = 10.5;
    float cost_per_min = 1;
    
    float ride_price() override{
        price = start_ride + (cost_per_km * distance) + (cost_per_min * time);
        return price;
    }

    void comfort_type() override{
        cout << "This Ride will be the most confortable ever you had !!" << endl;
    }
};


class Person:Taxi_Company
{
public:
    string name;
    string forename;
    string phone_number;
    float rank_val;

    virtual float rank(float value) = 0;

};


class Customer:public Person
{
public:

    Customer(string c_name, string c_forename, string c_phone_number)
    {
    	name = c_name;
        forename = c_forename;
        phone_number = c_phone_number;
    }

    void customer_request()
    {
    	cout << "Hello my name is " << forename << ". I would want ...." << endl ;
    }

    float rank(float value) override{
        rank_val = value - 1;
        return rank_val;
    };

    void info() override{
        cout << "Customers are very important in our company because they are the source of income !" << endl;
    }
};

class Operator:public Person
{
public:

    int salary;
    int age;
    string IDNP;

    Operator(string o_name, string o_forename, string o_phone_number, int o_age, string o_IDNP)
    {
    	name = o_name;
        forename = o_forename;
        phone_number = o_phone_number;
        age = o_age;
        IDNP = o_IDNP;
    }

    void get_the_request()
    {
    	cout << "This is " << forename << " i just got a new request " << endl; 
    }

    float rank(float value) override{
        rank_val = value - 2;
        return rank_val;
    };

    void info() override{
        cout << "The operator is the person who receives all the calls and makes reservations for customers !" << endl;
    }
};

class Taxi_Driver:public Person
{
public:
    int salary;
    int age;
    string IDNP;

    Taxi_Driver(string t_name, string t_forename, string t_phone_number, int t_age, string t_IDNP)
    {
    	name = t_name;
        forename = t_forename;
        phone_number = t_phone_number;
        age = t_age;
        IDNP = t_IDNP;
    }

    void drive()
    {
    	cout << "Hello, it's " << forename << " I will get this ride !" << endl; 
    }

    float rank(float value) override{
       rank_val = value - 0;
       return rank_val;
    };

    void info() override{
        cout << "The driver is the person who takes the client from point A to point B safely and comfortably !" << endl;
    }
};

class Admin:public Person
{
public:

    float income_amount = 0;
    int age;
    string IDNP;

    Admin(string c_name, string c_forename, string c_phone_number, int c_age, string c_IDNP)
    {
        name = c_name;
        forename = c_forename;
        phone_number = c_phone_number;
        age = c_age;
        IDNP = c_IDNP;
    }

    void manage_company()
    {
        cout << "My name is " << forename << " and I manage this Taxi Company !" << endl;
    }

    void manage_salary(float customer_amount) {
        income_amount = income_amount + customer_amount;
        cout << "The income for this day is " << income_amount << " lei. ";
    }

    float rank(float value) override{
        rank_val = value - 3;
        return rank_val;
    };

    void info() override{
        cout << "The admin is the company manager who is responsible for everything that happens in the company !" << endl;
    }
};

class Booking:public Taxi_Company
{
public:
    string starting_time;
    string arrival_time;
    string current_destination;
    string destination;
    string ride_type;

    Booking(string b_starting_time, string b_arrival_time, string b_current_destination, string b_destination, string b_ride_type)
    {
    	starting_time = b_starting_time;
        arrival_time = b_arrival_time;
        current_destination = b_current_destination;
        destination = b_destination;
        ride_type = b_ride_type;
    }

    void booking()
    {
    	cout << "The customer wants : " << endl; 
    }

    void info() override{
        cout << "Booking is the process in which the operator takes all the data from the client and makes a reservation !" << endl; 
    }
};


// car will be the parent class for the other cars
class Car:Taxi_Company
{
public:
    string name;
    string model;
    string transmission;
    string fuel_type;
    int power;
    int max_speed;
    string vin;

    Car(string c_name, string c_model, string c_transmission, string c_fuel_type, int c_power, int c_max_speed, string c_vin)
    {
    	name = c_name;
        model = c_model;
        transmission = c_transmission;
        fuel_type = c_fuel_type;
        power = c_power;
        max_speed = c_max_speed;
        vin = c_vin;
    }

    void car_specs()
    {
        if(power > 250){
            cout << "Which is a sport car !" << endl;
        }else{
            cout << "Which is a regular car !" << endl;
        }
    }

    void info() override{
        cout << "Car is the main transport through which our customers are served !" << endl;
    }
};

class Economy_Management:Taxi_Company
{
public:

    float income = 0;
    float amount = 0;
    float price = 0;
    string rating;

    void return_salary() {
        cout << "Good job, keep going !" << endl;
    }

    void return_income(float z) {
        if (z >= 50){
            cout << "A very good profit for today !!!" << endl;         
        }else{
            cout << "Not bad for today" << endl;
        }
        
    }

    void info() override{
        cout << "Economy Management System represents a system that returns salary and income ! " << endl;
    }
};


class Payment:public Economy_Management
{
public:
    string payment_type;

    Payment(string c_payment_type)
    {
    	payment_type = c_payment_type;
    }

    void payment_details()
    {
        cout << "The customer paid with " << payment_type << endl;
        if(payment_type == "card"){
            cout << "Also, ";
            cout << "the payment was completed successfully !" << endl;
        }else{
            cout << "Also, ";
            cout << "the payment was completed successfully !" << endl;
        }
    }

    void info() override{
        cout << "Payment represents a system which checks whether the transaction was by card or cash ! " << endl;
    }
};


class Salary:public Economy_Management
{
public:

    float calculate_salary(float customer_income){
        income = income + customer_income;
        return income;
    }

    void info() override{
        cout << "Salary Class calculate the salary !" << endl;
    }

};

class Income: public Economy_Management
{
public:

    float calculate_income(float current_income){
        income = income + current_income - (current_income*0.5);
        return income;
    }

    void info() override{
        cout << "Income Class calculate the income !" << endl;
    }
};

class Rating: public Taxi_Company
{
public:
    
    void ride_rating(string rating){
    	cout << "The customed said that ride was " << rating << " out of 10" << endl;
    }

    void info() override{
        cout << "Rating Class return the ratirn of ride !" << endl;
    }
};


int main()
{
    float income_monthly = 0;
    float income_daily = 0;
    float tom_income = 0;
    float tom_income_total = 0;
    string ride_type = "standart";


    Customer customer_x("Erikow", "Tom", "065487947");
    Operator operator_x("Rewot", "Emma", "064879245", 31, "0123456789123");
    Booking boking_x("15:30", "15:45", "Riscani", "Centru","standart");
    Car car_x("BMW", "M 3" , "Automate", "benzine", 349, 300, "4Y1SL65848Z411439");
    Taxi_Driver driver_x("Wetsib", "Jim","069748167", 24, "7894561230124");
    Payment payment_x("card");
    Admin admin_x("Bdirs", "Rocko", "0788495134", 39, "4871354871545");
    Salary salary_x;
    Income income_x;
    Rating rating_x;

    Standart Stand;
    Premium Prem;
    
    // Set the time and distance, override both functions 
    Stand.setDistance(6);
    Stand.setTime(15);
    Prem.setDistance(6);
    Prem.setTime(15);   

    customer_x.customer_request();
    operator_x.get_the_request();

    boking_x.booking();
    tom_income = Stand.ride_price();
    income_daily = income_daily + Stand.ride_price();
    tom_income_total = income_x.calculate_income(tom_income);

    cout << " - Go from " << boking_x.current_destination << " at " << boking_x.starting_time << " to " << boking_x.destination << " at " << boking_x.arrival_time << endl ;    
    driver_x.drive();

    cout << " - I will go with our new " << car_x.name << " " << car_x.model << endl ;
    
    car_x.car_specs();
    int rand_rating = (rand() % 10) + 8; 
    string rand = to_string(rand_rating);
    rating_x.ride_rating(rand);

    cout << "Done !, I finished the ride !" << endl;

    if(boking_x.ride_type == "standart"){
        cout << "It is a standart ride and the price will be " << Stand.ride_price() << " lei !" << endl;
        Stand.comfort_type();
    }else {
        cout << "It is a premium ride and the price will be " << Prem.ride_price() << " lei !"<< endl;
        Prem.comfort_type();
    }

    payment_x.payment_details();

    admin_x.manage_company();

    admin_x.manage_salary(income_daily);
    salary_x.return_income(income_daily);

    cout << "The salary for " << customer_x.forename << " at the moment is " << salary_x.calculate_salary(tom_income - (tom_income*0.5)) << " lei. ";

    cout << " \n" <<  endl;

    cout << "Here are the ranking system of each Person from Company : " << endl;
    cout << "The Driver has : " << driver_x.rank(4)<< endl;
    cout << "The Customer has : " << customer_x.rank(4)<< endl;
    cout << "The Operator has : " << operator_x.rank(4)<< endl;
    cout << "The Admin has : " << admin_x.rank(4)<< endl;

    cout << endl;

    customer_x.info();
    operator_x.info();
    boking_x.info();
    car_x.info();
    driver_x.info();
    payment_x.info();
    admin_x.info();
    salary_x.info();
    income_x.info();
    rating_x.info();


    return 0;
}

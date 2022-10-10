#include "iostream"

using namespace std;

// 

class Taxi_Company
{
public:
    void tx_ocmpany() {
        cout << "This is the Taxi Company";
    }

};

class Person:Taxi_Company
{
public:
    string name;
    string forename;
    string phone_number;

};

class Ride_Type{
public:
    float start_ride;
    float cost_per_km;
    float cost_per_min;
    float price;
    float distance;
    float time;

    virtual float ride_price() = 0;

    void setTime(float x){
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

    float ride_price(){
        price = start_ride + (cost_per_km * distance) + (cost_per_min * time);
        return price;
    }
};

class Premium:public Ride_Type{
public:
    float start_ride = 70;
    float cost_per_km = 10.5;
    float cost_per_min = 1;
    
    float ride_price(){
        price = start_ride + (cost_per_km * distance) + (cost_per_min * time);
        return price;
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

    void return_income() {
        cout << "A very good profit for today !!!" << endl;
    }

    void return_rating() {
        cout << "We are proud of you !!!" << endl;
    }
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
    	cout << "Hello my name is " << forename << ". I would want to go from Chisinau to Balti !" << endl ;
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
};

class Booking:public Economy_Management
{
public:
    string starting_time;
    string arrival_time;
    string current_destination;
    string destination;

    Booking(string b_starting_time, string b_arrival_time, string b_current_destination, string b_destination, float b_price)
    {
    	starting_time = b_starting_time;
        arrival_time = b_arrival_time;
        current_destination = b_current_destination;
        destination = b_destination;
        price = b_price;
    }

    void booking()
    {
    	cout << "The customer wants : " << endl; 
    }
};

class Taxi_Driver:Person
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
};


class Payment:public Economy_Management
{
public:
    string payment_type;

    Payment(string c_payment_type, float c_amount)
    {
    	payment_type = c_payment_type;
        amount = c_amount;

    }

    void payment_details()
    {
        cout << " It was " << amount << " lei " << "and customer paid with " << payment_type << endl;
        if(amount == 0 && payment_type == "card"){
            cout << "Also, ";
            cout << "the payment was completed unsuccessfully !" << endl;
            cout << "Need to pay with cash !" << endl;
        }else{
            cout << "Also, ";
            cout << "the payment was completed successfully !" << endl;
        }
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


};

class Salary:public Economy_Management
{
public:

    float calculate_salary(float customer_income){
        income = income + customer_income;
        return income;
    }

};

class Income: public Economy_Management
{
public:

    float calculate_income(float current_income){
        income = income + current_income - (current_income*0.5);
        return income;
    }
};

class Rating: public Economy_Management
{
public:
    
    void ride_rating(string rating){
    	cout << "The customed sad that ride was " << rating << " out of 10" << endl;
    }
};


int main()
{
    float income_monthly = 0;
    float income_daily = 0;
    float tom_income = 0;
    float tom_income_total = 0;


    Customer customer_x("Erikow", "Tom", "065487947");
    Operator operator_x("Rewot", "Emma", "064879245", 31, "0123456789123");
    Booking boking_x("15:34", "14:06", "Chisinau", "Balti", 400);
    Car car_x("BMW", "M 3" , "Automate", "benzine", 349, 300, "4Y1SL65848Z411439");
    Taxi_Driver driver_x("Wetsib", "Jim","069748167", 24, "7894561230124");
    Payment payment_x("card", 179.32);
    Admin admin_x("Bdirs", "Rocko", "0788495134", 39, "4871354871545");
    Salary salary_x;
    Income income_x;
    Rating rating_x;

    Standart Stand;
    Premium Prem;

    Stand.setDistance(6);
    Stand.setTime(15);

    Prem.setDistance(6);
    Prem.setTime(15);   

    customer_x.customer_request();
    operator_x.get_the_request();

    boking_x.booking();
    tom_income = boking_x.price;
    income_daily = income_daily + boking_x.price;
    tom_income_total = income_x.calculate_income(tom_income);

    cout << "Go from " << boking_x.current_destination << " at " << boking_x.starting_time << " to " << boking_x.destination << " at " << boking_x.arrival_time << endl ;

    cout << "For Standart Ride the price will be " << Stand.ride_price() << " lei !" << endl;
    cout << "For Premium Ride the price will be " << Prem.ride_price() << " lei !"<< endl;
    
    driver_x.drive();
    cout << "I will go with my " << car_x.name << " " << car_x.model << endl ;
    
    car_x.car_specs();
    rating_x.ride_rating("9");

    cout << "Done !, I finished the ride !" << endl;

    payment_x.payment_details();

    admin_x.manage_company();

    admin_x.manage_salary(income_daily);
    salary_x.return_income();

    cout << "The salary for " << customer_x.forename << " at the moment is " << salary_x.calculate_salary(tom_income - (tom_income*0.5)) << " lei. ";
    salary_x.return_salary();
    cout << "The income for Tom is " << tom_income_total << " lei" << endl;
    

    return 0;
}

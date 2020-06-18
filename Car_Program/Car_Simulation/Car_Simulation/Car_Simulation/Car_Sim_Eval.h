//=======Start of base class: Vehicle
class Vehicle
{
protected:
	double fuel_consume;
	double distance;
	double roll_resistance;
	double wind_resistance;
	double vehicle_weight;
	double vehicle_height;
	const double c_rollresistance { 0.75 };//roll resistance as constant value
	const double c_windresistance { 0.2 }; //wind resistance as constant value
	const double c_trailerresistance { 0.05 }; //trailer resistance as constant value

public:
	Vehicle();
	Vehicle(double dist, double veh_weight, double veh_height);
	virtual ~Vehicle();
	virtual double fuel_consumption();
	//virtual double fuel_consumption_with_trailer(); 
};
//=======End of base class: Vehicle




//=======Start of derived class: Convertable car
class Convertable_Car: public Vehicle
{	
public:
	Convertable_Car(double dist);
	~Convertable_Car();
	// no point of implementing the below, I can directly access the vehicle method unless there is requirement to change
	//however, I will implement only for car and not for Van for the purpose of Evaluation
	double fuel_consumption();
};
//=======End of derived class: Convertable car


//=======Start of derived class: Van
class Van : public Vehicle
{
public:
	Van(double dist);
	~Van();
	//double fuel_consumption();// no point of implementing as, I can directly access th vehicle method unless there is requirement to change 

};
//=======End of derived class: Van


//=======Start of derived class: Truck
class Truck : public Vehicle
{
	double empty_trailer_weight;  
	double full_trailer_weight;	
	bool isTrailer;

public:
	Truck(double dist, bool istrailer_attached);
	~Truck();
	//double fuel_consumption();
	double fuel_consumption_with_trailer();

};
//=======End of derived class: Truck
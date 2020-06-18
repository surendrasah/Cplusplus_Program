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
	constexpr static  double c_rollresistance { 0.75 }; //roll resistance as constant value
	constexpr static double c_windresistance { 0.2 }; //wind resistance as constant value
	constexpr static double c_trailerresistance { 0.05 };//trailer resistance as constant value

public:
	Vehicle();
	Vehicle(double dist);
	virtual ~Vehicle();
	virtual double fuel_consumption() = 0;
	
};
//=======End of base class: Vehicle




//=======Start of derived class: Convertable car
class Convertable_Car: public Vehicle
{	
public:
	Convertable_Car(double dist);
	~Convertable_Car();
	double fuel_consumption();
};
//=======End of derived class: Convertable car


//=======Start of derived class: Van
class Van : public Vehicle
{
public:
	Van(double dist);
	~Van();
	double fuel_consumption();

};
//=======End of derived class: Van


//=======Start of derived class: Truck
class Truck : public Vehicle
{
	double empty_trailer_weight;  
	double full_trailer_weight;	
	int isTrailer;//to accept if there is trailer associated with or not

public:
	Truck(double dist);
	~Truck();
	double fuel_consumption();
	double fuel_consumption_with_trailer();

};
//=======End of derived class: Truck
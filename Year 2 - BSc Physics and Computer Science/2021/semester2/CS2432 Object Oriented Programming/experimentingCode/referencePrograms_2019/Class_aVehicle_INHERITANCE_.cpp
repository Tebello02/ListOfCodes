/*
	FILE NAME: Class{aVehicle_INHERITANCE}.cpp
	FUNCTION:
			The program shows how abstract classes are used for inheritance. The example used
			is that of vehicles, where a price may be determined by different properties
			depending on whether the vehicle is a truck or a private car.
	
	(C) Mofana Mphaka 2006;
	Edited: February 2021
*/

#include <iostream>

class aPerson
{
	public:
		aPerson() : name("") {}
		
		aPerson(char * the_name) : name(the_name) { }
		
		~aPerson() { };

		char * get_name() 
		{ 
			return name;
		}
		
		void set_name(char * the_name = "")
		{
			name = new char[40];	// Name is 40 characters max
			
			for(int i=0; (the_name[i] != '\0') && (i < 40); i++)
				name[i] = the_name[i];
		}

		void input_name()
		{
			name = new char[40];
			
			std::cout << "Enter the name of the person ";
			std::cin >> name;
		}

	private:
		char * name;
};



class  aVehicle
{
	public:
		aVehicle() : manufacturer(""), cylinders(1) {}

		aVehicle(char * Manufacturer,  int Cylinders) : manufacturer(Manufacturer)
		{ 
			cylinders = ( (Cylinders <= 0)? 1 : Cylinders);
		}
		
		~aVehicle() {}

		virtual double price( ) = 0;

		void input()
		{
			manufacturer = new char[20];
			
			std::cout << "Enter the name of the Manufacturer ";
			std::cin >> manufacturer;
			
			do
			{
				std::cout << "Enter the number of the Engine Cylinders >= 1 ";
				std::cin >> cylinders;
			}
			while(cylinders < 1);
			
			std::cout << "The Owner of the Vehicle\n";
			owner.input_name();
		}
		
		void display()
		{
			std::cout << "Vehicle Manufacturer:  " << manufacturer << "\n";
			std::cout << "Engine Cylinders:  " << cylinders << "\n";
			std::cout << "Owner of the Vehicle:  " << owner.get_name() << "\n";
		}

	protected:
		char *		manufacturer;
		int			cylinders;
		aPerson		owner;
						
};


class aTruck : public aVehicle
{
	public:
		aTruck( ) : aVehicle(), capacity(1) {}

		aTruck (char * Manufacturer, int Cylinders, double Capacity) : aVehicle(Manufacturer, Cylinders) 
		{
			capacity = ( (Capacity <= 0)? 1 : Capacity);
		}

		double price( ) 
		{ 
			return (capacity * cylinders * 10000);
		}
		
		void input()
		{
			std::cout << "\nA TRUCK VEHICLE\n";
			aVehicle :: input();
			
			do
			{
				std::cout << "Enter the Loading Capacity of this Truck (in Tons) > 0 ";
				std::cin >> capacity;
			}
			while (capacity <= 0);
		}
		
		void display()
		{
			std::cout << "\nA TRUCK VEHICLE\n";
			aVehicle :: display();
			std::cout << "Loading Capacity: " << capacity << " tonnes\n";
			std::cout << "Price:  M" << price() << ".00\n";
		}

	private:
		double  capacity;
};



class aPrivate_Car : public aVehicle
{
	public:
		aPrivate_Car( ) : aVehicle(), passengers(1) {}

		aPrivate_Car(char * Manufacturer, int Cylinders, int Passengers) : aVehicle(Manufacturer, Cylinders)
		{ 
			passengers = ( (Passengers <= 0)? 1 : Passengers);
		}

		double price( ) 
		{ 
			return (passengers * cylinders * 1000);
		}
		
		void input()
		{
			std::cout << "\nA PRIVATE CAR\n";
			aVehicle :: input();
			
			do
			{
				std::cout << "Enter the Number of Seats of this Car > 0 ";
				std::cin >> passengers;
			}
			while (passengers <= 0);
		}

		void display()
		{
			std::cout << "\nA PRIVATE CAR\n";
			aVehicle :: display();
			std::cout << "Number of Seats: " << passengers << "\n";
			std::cout << "Price: M" << price() << ".00\n";
		}

	private:
		int passengers;
};

/*
int main()
{
	aTruck Truck;
	aPrivate_Car Car;
	
	Truck.input();
	Car.input();
	
	Truck.display();
	Car.display();
	
	return 1;
}
*/

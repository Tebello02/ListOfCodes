#include <iostream>
/*	FILE NAME: Class{aPrintDevice_INHERITANCE}.cpp
	FUNCTION:
			This is an example of an "Abstract Class", aPrintDevice. We then show how derived 
			classes could be built (from it).
			
			The example is that of a print device -- aPrintDevice. Since there can be many
			print devices, we derive only two psuch rint devices: a printer, aPrinter, and 
			a plotter, aPlotter.
			
	(C) Mofana Mphaka; 2006.
	Edited: February 2021
*/

class aPrintDevice
{
	public:

		aPrintDevice(int Type)
		{
			DeviceType = ((Type >= 0)? Type : 0);
		}

		virtual void print() = 0;
		virtual int getDeviceType() { return DeviceType;}

	protected:
		int DeviceType;
};


class aPrinter : public aPrintDevice
{
	public:
		aPrinter(int device) : aPrintDevice(device) {}

		void print()
		{
			std::cout << "\nI am a Printer\nThe device number is "
					  << getDeviceType() << "\n";
		}
};


class aPlotter : public aPrintDevice
{
	public:
		aPlotter(int device) : aPrintDevice(device) {}

		void print()
		{
			std::cout << "\nI am a Plotter\nThe device number is "
					  << getDeviceType() << "\n";
		}
};

/*
int main()
{
	aPrinter Printer(10);
	aPlotter Plotter(2);

	Printer.print();
	Plotter.print();
	return(1);
}
*/

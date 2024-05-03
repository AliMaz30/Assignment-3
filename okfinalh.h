#pragma once
#include<iostream>
using namespace std;

class ALU {
	int NoofAdders;
	int NoofSubtractors;
	int NoofRegisters;
	int sizeofRegisters;
	//int price;
public:

	ALU(int noofadd = 0, int noofsub = 0, int noofreg = 0, int sizereg = 0) : NoofAdders(noofadd),
		NoofSubtractors(noofsub), NoofRegisters(noofreg), sizeofRegisters(sizereg)
	{};

	//getter and setter of all


	int getadders() {
		return NoofAdders;
	};
	int getsubtractors() {
		return NoofSubtractors;
	};
	int getsregisters() {
		return NoofRegisters;
	};
	int getsizeofregisters() {
		return sizeofRegisters;
	};

	void setadders(int add) {
		NoofAdders = add;
	};
	void setsubtractors(int sub) {
		NoofSubtractors = sub;
	};
	void setnoofregisters(int num) {
		NoofRegisters = num;
	};
	void setsizeofregisters(int size) {
		sizeofRegisters = size;
	};

	/*int getpricealu() {
		return NoofAdders * 2 + NoofSubtractors * 2 + NoofRegisters * 1;
	}*/
};

class ControlUnit {
	float clock;
	//int clockprice;
public:
	ControlUnit(float cloc = 0) : clock(cloc) {}

	int getclock() {
		return clock;
	}
	void setclock(float cl) {
		clock = cl;
	}

	/*int getpriceclock() {
		return clockprice;
	}
	void setclockprice(float cl) {
		clockprice = cl;
	}*/

};

//cpu composed of these
class CPU {
private:
	ALU Alu;
	ControlUnit CU;
	//float CPUprice;

public:
	// Default constructor
	CPU() : Alu(), CU()/*,CPUprice(0)*/ {}

	// Overloaded constructor
	CPU(ALU a, ControlUnit c) : Alu(a), CU(c)/*, CPUprice(price)*/ {}



	// Getter and setter for ALU
	const ALU getALU() const { return Alu; }
	void setALU(ALU a) { Alu = a; }

	// Getter and setter for ControlUnit
	const ControlUnit getCU() const { return CU; }
	void setCU(ControlUnit c) { CU = c; }

	// Getter and setter for CPU price
	/*float getCPUPrice() const { return CPUprice; }
	void setCPUPrice(float price) { CPUprice = price; }*/

};

class MainMemory {
private:
	int capacity;
	string technologyType;
	/*int price;*/

public:

	MainMemory() {
		capacity = 8;
		technologyType = "Semiconductor";
		/*price = 0;*/

	}

	MainMemory(int cap, string& techType, int p = 0) : capacity(cap), technologyType(techType)/*, price(p)*/ {}


	int getCapacity() const { return capacity; }
	void setCapacity(int cap) { capacity = cap; }

	string getTechnologyType() const { return technologyType; }
	void setTechnologyType(string techType) { technologyType = techType; }

	//int getMMprice() const { return price; }
	//void setMMprice(int p) { price = p; }

};

class Port {
private:
	string type;
	int baudRate;

public:

	Port() {
		type = "No Port";
		baudRate = 0;

	}

	Port(string t, int baud) : type(t), baudRate(baud) {}

	string getType() const { return type; }
	void setType(string t) { type = t; }

	int getBaudRate() const { return baudRate; }
	void setBaudRate(int baud) { baudRate = baud; }
};

//mb has mainmemory and ports
class MotherBoard {
protected:
	MainMemory* mm;
	Port ports[4]; // Assuming a maximum of 4 ports

public:

	MotherBoard() {
		mm = nullptr;

		for (int i = 0; i < 4; i++) {
			ports[i] = Port();
		}

	}
	// Constructor initializing attributes with overloaded constructors
	MotherBoard(MainMemory* memory,Port p1 = Port(), Port p2 = Port(), Port p3 = Port(), Port p4 = Port()) : mm(memory) {
		ports[0] = p1;
		ports[1] = p2;
		ports[2] = p3;
		ports[3] = p4;
	}

	// Getters and Setters
	MainMemory* getMainMemory() const { return mm; }
	void setMainMemory(MainMemory memory) { *mm = memory; }

	Port getPort(int index) const { return ports[index]; }
	void setPort(int index,Port port) { ports[index] = port; }
};


class PhysicalMemory {
private:
	int capacity;
	string physical;

public:
	// Constructor initializing attributes with default parameters
	//default construct for mac
	PhysicalMemory(int cap = 8192, string physical = "LDDR4/5") : capacity(cap) {}


	// Getters and Setters
	int getCapacity() const { return capacity; }
	void setCapacity(int cap) { capacity = cap; }

	string gettechtype()const { return physical; }
	void setTechType(string str) { physical = str; }
};


class GraphicsCard {
private:
	string brand;
	int memorySize;
	double price;

public:


	GraphicsCard(string b="Apple", int size = 0, double p = 0) : brand(b), memorySize(size), price(p) {}

	// Getters and Setters
	string getBrand() const { return brand; }
	void setBrand(const  string& b) { brand = b; }

	int getMemorySize() const { return memorySize; }
	void setMemorySize(int size) { memorySize = size; }

	double getPrice() const { return price; }
	void setPrice(double p) { price = p; }
}; // will agregate in intel mb but compose in apple mb


class AppleSilicon {
private:
	CPU cpu;
	GraphicsCard gpu;
	bool isIntegrated;

public:
	AppleSilicon() : isIntegrated(true), cpu(), gpu("Apple",0,0) {}

	// Overloaded constructor
	AppleSilicon(CPU* cpuPtr,GraphicsCard* gp ,bool integrated) : cpu(*cpuPtr), gpu(*gp), isIntegrated(integrated) {}

	// Getter and setter for CPU
	
	CPU getCPU() const { return cpu; }
	void setCPU(CPU* cpuPtr) { cpu = *cpuPtr; }
	
	GraphicsCard getGPU() const { return gpu; }
	void setGraphicsCard(GraphicsCard* gpuPtr) { gpu = *gpuPtr; }

	// Getter and setter for isIntegrated
	bool getIsIntegrated() const { return isIntegrated; }
	void setIsIntegrated(bool integrated) { isIntegrated = integrated; }
};

class Computer {
protected:
	PhysicalMemory* pm;
	MotherBoard* mb;

public:
	Computer(PhysicalMemory* memory = nullptr, MotherBoard* motherboard = nullptr)
		: pm(memory), mb(motherboard) {}

	PhysicalMemory * getPhysicalMemory() const { return pm; }
	void setPhysicalMemory(PhysicalMemory* memory) { pm = memory; }

	MotherBoard* getMotherBoard() const { return mb; }
	void setMotherBoard(MotherBoard* motherboard) { mb = motherboard; }


};

class MacComputer : public Computer {
protected:
	AppleSilicon* as;
public:
	//MacComputer(PhysicalMemory
	MacComputer(PhysicalMemory* memor = nullptr, MotherBoard* motherboard = nullptr, AppleSilicon* chip = nullptr)
		: Computer(memor, motherboard), as(chip) {}
	AppleSilicon* getCPU() const { return as; }
	void setCPU(AppleSilicon* applechip) { as = applechip; }
};

class IntelComputer : public Computer {
	CPU* cpu;
	GraphicsCard* gpu;
public:
	IntelComputer(PhysicalMemory* memory = nullptr, MotherBoard* motherboard = nullptr, CPU *processor = nullptr, GraphicsCard* graphics=nullptr )
		: Computer(memory, motherboard), cpu(processor), gpu(graphics) {}

	CPU* getCPU() const { return cpu; }
	void setCPU(CPU processor) { *cpu = processor; }
	
	GraphicsCard* getGPU() const { return gpu; }
	void setGPU(GraphicsCard processor) { *gpu = processor; }

};


class StorageDevice {
private:
	string type;
	int capacity;
	double price;

public:
	// Constructor initializing attributes with default parameters
	StorageDevice(string t = "HDD", int cap = 500, double p = 0)
		: type(t), capacity(cap), price(p) {}


	// Getters and Setters
	string getType() const { return type; }
	void setType(string t) { type = t; }

	int getCapacity() const { return capacity; }
	void setCapacity(int cap) { capacity = cap; }

	double getPrice() const { return price; }
	void setPrice(double p) { price = p; }
};

class NetworkCard {
private:
	string type;
	int speed;
	double price;

public:
	// Default constructor
	NetworkCard() : type("Ethernet"), speed(0), price(0.0) {}

	// Overloaded constructor
	NetworkCard(string t, int s, double p) : type(t), speed(s), price(p) {}

	// Getter and setter methods
	void setType(string t) {
		type = t;
	}

	string getType() const {
		return type;
	}

	void setSpeed(int s) {
		speed = s;
	}

	int getSpeed() const {
		return speed;
	}

	void setPrice(double p) {
		price = p;
	}

	double getPrice() const {
		return price;
	}
};

class PowerSupply {
private:
	int wattage;
	string efficiencyRating;
	double price;

public:
	// Constructor initializing attributes with default parameters

	/*PowerSupply() {

		wattage = 0;
		efficiencyRating = "\0";
		price= 0;
	}*/
	PowerSupply(int watt = 500, const  string& rating = "80 Plus Bronze", double p = 50.0)
		: wattage(watt), efficiencyRating(rating), price(p) {}

	// Constructor initializing attributes with overloaded constructors


	// Getters and Setters
	int getWattage() const { return wattage; }
	void setWattage(int watt) { wattage = watt; }

	string getEfficiencyRating() const { return efficiencyRating; }
	void setEfficiencyRating(const  string& rating) { efficiencyRating = rating; }

	double getPrice() const { return price; }
	void setPrice(double p) { price = p; }
};


class Battery {
private:
	int capacity;

public:
	// Constructor initializing attributes with default parameters
	Battery(int cap = 5000) : capacity(cap) {}

	// Constructor initializing attributes with overloaded constructors
	/*Battery() : capacity(0) {}*/

	// Getters and Setters
	int getCapacity() const { return capacity; }
	void setCapacity(int cap) { capacity = cap; }
};

class Case {
private:
	string formFactor;
	string color;
	double price;

public:
	// Constructor initializing attributes with default parameters


	Case(string factor = "none", string col = "none", double p = 50.0)
		: formFactor(factor), color(col), price(p) {};

	// Constructor initializing attributes with overloaded constructors


	// Getters and Setters
	string getFormFactor() const { return formFactor; }
	void setFormFactor(string factor) { formFactor = factor; }

	string getColor() const { return color; }
	void setColor(string col) { color = col; }

	double getPrice() const { return price; }
	void setPrice(double p) { price = p; }
};


//these aggregated in computer assembly class
class ComputerAssembly {
private:
	PowerSupply* psu;
	NetworkCard* nc;
	Battery* battery;
	Case* computerCase;
	StorageDevice* storage;
	double totalPrice;

public:


	// Constructor initializing attributes with overloaded constructors
	ComputerAssembly(PowerSupply* p=nullptr, Battery* b = nullptr, Case* c = nullptr, StorageDevice* store=nullptr, NetworkCard *n=nullptr,double total=0)
		: psu(p), battery(b), computerCase(c),storage(store),nc(n), totalPrice(total) {}

	// Getters and Setters
	PowerSupply* getPowerSupply() const { return psu; }
	void setPowerSupply(PowerSupply p) { *psu = p; }

	const Battery* getBattery() const { return battery; }
	void setBattery(Battery b) { *battery = b; }

	Case* getComputerCase() const { return computerCase; }
	void setComputerCase(Case c) { *computerCase = c; }
	
	StorageDevice* getStorageDevice() const { return storage; }
	void setStorage(StorageDevice s) { *storage = s; }
	
	NetworkCard* getNetworkCard() const { return nc; }
	void setNetworkCard(NetworkCard s) { *nc = s; }
	
	void totalprice() {
		totalPrice = psu->getPrice() + computerCase->getPrice()+storage->getPrice()+ nc->getPrice();
	}
	
	double getTotalPrice()  {
		
		totalprice();
		return totalPrice; }
	void setTotalPrice(double total) { totalPrice = total; }

	


};

class PC : public ComputerAssembly {
private:
	IntelComputer* computer;
	double price = 0;

public:
	PC(PowerSupply* p=nullptr, Battery* b = nullptr, Case* c = nullptr, StorageDevice* s = nullptr, NetworkCard* n = nullptr, double total=0, IntelComputer* comp = nullptr, double pri=0)
		: ComputerAssembly(p, b, c,s,n, total), computer(comp), price(pri) {}

	IntelComputer* getComputer() const { return computer; }
	void setComputer(IntelComputer* comp) { computer = comp; }

	double getprice() {
		return price;
	}
};

class Mac : public ComputerAssembly {
private:
	MacComputer* computer;

public:
	Mac(PowerSupply* p = nullptr, Battery* b = nullptr, Case* c= nullptr, StorageDevice* s = nullptr, NetworkCard* n = nullptr,double total=0, MacComputer* comp = nullptr)
		: ComputerAssembly(p, b, c,s,n, total), computer(comp) {}

	MacComputer* getComputer() const { return computer; }
	void setComputer(MacComputer* comp) { computer = comp; }
};

istream& operator>>(istream& inp, GraphicsCard* gpu) {
	int price = 0;
	string choice;
	cout << "Input Graphics Card:\nNVIDIA\nAMD\nINTEL\n";
	inp >> choice;
	while (choice != "NVIDIA" && choice != "AMD" && choice != "INTEL") {
		cout << "Invalid Input. Pick out of the three.\n";
		inp >> choice;
	}

	gpu->setBrand(choice);

	cout << "Input price:\n";
	inp >> price;
	gpu->setPrice(price);

	int size = 0;
	cout << "Input memory size of Graphics Card:\n";
	inp >> size;
	while (size > 32) {
		cout << "Invalid Input, size should be upto 32.\nInput memory size of Graphics Card:\n";
		inp >> size;
	}
	gpu->setMemorySize(size);

	return inp;
};
istream& operator>>(istream& inp, NetworkCard* nc) {

	int choice = 0;
	int speed = 0;
	int price = 0;
	cout << "Input type of Network Card:\n1.Wifi\n2.Ethernet\n";
	inp >> choice;
	while (choice != 1 && choice != 2) {
		cout << "invalid choice pick between 1 and 2.\n";
		inp >> choice;
	}
	if (choice == 1) {

		cout << "Input Speed:\n1.10Mbps for $10\n2.20Mbps for $15\n3.30Mbps for $20\n4.40Mbps for $25\n";
		inp >> speed;

		while (speed < 1 || speed>4) {
			cout << "Invalid choice, pick a number between 1 and 5.\n";
			inp >> speed;

		}

		nc->setSpeed(speed * 10);
		nc->setPrice(10 + ((speed - 1) * 5));
	}
	else {
		cout << "Input Speed:\n1.40Mbps for $10\n2.60Mbps for $15\n3.80Mbps for $20\n4.100mbps for $25\n";
		inp >> speed;

		while (speed < 1 || speed>4) {
			cout << "Invalid choice, pick a number between 1 and 5.\n";
			inp >> speed;

		}
		nc->setSpeed((speed - 1) * 20 + 40);
		nc->setPrice(10 + ((speed - 1) * 5));

	}


	return inp;
};
istream& operator>>(istream& inp, Case* cas) {

	int ch = 0;
	cout << "Input Case:\n1.ATX for $10\n2.Micro-ATX for $5\n ";
	inp >> ch;
	while (ch != 1 && ch != 2) {
		cout << "invalid choice pick between 1 and 2.\n";
		inp >> ch;
	}
	if (ch == 1) {
		cas->setFormFactor("ATX");
		cas->setPrice(10);
	}
	if (ch == 2) {
		cas->setFormFactor("Micro-ATX");
		cas->setPrice(5);
	}


	int ca = 0;
	cout << "Input Colour:\n1.Black\n2.Red\n3.White\n ";
	inp >> ca;
	while (ca != 1 && ca != 2 && ca != 3) {
		cout << "invalid choice pick between 1 and 3.\n";
		inp >> ca;
	}
	if (ca == 1) {
		cas->setColor("Black");
	}
	if (ca == 1) {
		cas->setColor("Red");
	}
	if (ca == 3) {
		cas->setColor("White");
	}


	return inp;
};
istream& operator>>(istream& inp, MainMemory* mem) {
	int ch;
	cout << "Input Technology type:\n1.Silicon\n2.Semi-Conductor \n";
	inp >> ch;
	while (ch != 1 && ch != 2) {
		cout << "invalid choice pick between 1 and 2.\n";
		inp >> ch;
	}
	if (ch == 1) {
		mem->setTechnologyType("Silicon");

	}
	if (ch == 2) {
		mem->setTechnologyType("Semi-Conductor");
	}

	int cap = 0;
	cout << "Set Capacity:\n";
	inp >> cap;
	while (cap < 1 && pow(cap, 2) != 0 && cap>32) {
		cout << "Invalid Input.Input in powers in 2\n";
		inp >> cap;
	}
	mem->setCapacity(cap);
	return inp;
};

istream& operator>>(istream& inp, ALU* alu) {
	int adders, subtractors, registers, sizeofRegisters;
	cout << "Enter the number of adders: ";
	inp >> adders;
	cout << "Enter the number of subtractors: ";
	inp >> subtractors;
	cout << "Enter the number of registers: ";
	inp >> registers;
	cout << "Enter the size of registers: ";
	inp >> sizeofRegisters;

	alu->setadders(adders);
	alu->setsubtractors(subtractors);
	alu->setnoofregisters(registers);
	alu->setsizeofregisters(sizeofRegisters);

	return inp;
}

istream& operator>>(istream& inp, ControlUnit* cu) {
	float clock;
	cout << "Enter the clock speed: ";
	inp >> clock;
	cu->setclock(clock);

	return inp;
}

istream& operator>>(istream& inp, CPU* cpu) {
	ALU *alu=new ALU;
	ControlUnit* cu=new ControlUnit;
	inp >> alu >> cu;
	cpu->setALU(*alu);
	cpu->setCU(*cu);

	return inp;
}



istream& operator>>(istream& inp, Port* port) {

	int cho;
	cout << "Input type of Port:\n1.VGA Port\n2.I/O Port\n3.USB Port\n4.HDMI Port\n5.Ethernet Port\n6.Parallel Port\n";
	inp >> cho;
	while (cho < 1 || cho>6) {
		cout << "Invalid Input. Enter a number between 1 and 6.\n";
		inp >> cho;
	}
	switch (cho) {
	case 1:
	{
		port->setType("VGA");
		port->setBaudRate(9600);
		break;
	}
	case 2:
	{
		port->setType("I/O");
		port->setBaudRate(9600);
		break;
	}
	case 3:
	{
		port->setType("USB");
		port->setBaudRate(9600);
		break;
	}
	case 4:
	{
		port->setType("HDMI");
		port->setBaudRate(10200);
		break;
	}
	case 5:
	{
		port->setType("Ethernet");
		port->setBaudRate(10200);
		break;
	}
	case 6:
	{
		port->setType("Parallel");
		port->setBaudRate(1000);
		break;
	}
	}




	return inp;
};
istream& operator>>(istream& inp, MotherBoard* mb) {
	MainMemory* mem=new MainMemory;
	Port ports[4];
	int num = 0;


	for (int i = 0; i < 4; ++i) {
		cout << "Enter details for port " << i + 1 << ":\n";
		inp >> &ports[i];
	}
	cout << "Input Main Memory\n";
	cin >> mem;
	
	for (int i = 0; i < 4; ++i) {
		mb->setPort(i, ports[i]);
	}

	return inp;
}

istream& operator>>(istream& inp, PhysicalMemory* pm) {
	int capacity;
	string physical;
	cout << "Enter the physical memory type: ";
	inp >> physical;
	cout << "Enter the capacity: ";
	inp >> capacity;
	pm->setTechType(physical);
	pm->setCapacity(capacity);

	return inp;
}

istream& operator>>(istream& inp, StorageDevice* sd) {
	string type;
	int capacity;
	double price;
	int cho = 0;
	cout << "Enter the type: ";
	//string choic = 0;
	//int price = 0;
	cout << "Input type of Storage Device:\n1.HDD\n2.SSD\n";
	inp >> type;
	while (type != "HDD" && type != "SSD") {
		cout << "invalid choice pick between the two specified above.\n";
		inp >> type;
	}
	cout << "Input Capacity:\n1.128GB for $10\n2.256GB for $20\n3.512GB for $30\n4.1TB for $40\n5.2TB for $50\n";
	inp >> cho;
	while (cho < 1 || cho>5) {
		cout << "Invalid Input. Enter a number between 1 and 5.\n";
		inp >> cho;
	}
	switch (cho) {
	case 1:
	{
		sd->setCapacity(128);
		break;
	}
	case 2:
	{
		sd->setCapacity(256);
		break;
	}
	case 3:
	{
		sd->setCapacity(512);
		break;
	}
	case 4:
	{
		sd->setCapacity(1024);
		break;
	}
	case 5:
	{
		sd->setCapacity(2048);
		break;
	}

	}


	if (type == "HDD") {
		sd->setPrice(cho * 10);
	}
	else {
		sd->setPrice(10 + cho * 10);
	}


	sd->setType(type);
	//sd->setCapacity(capacity);

	return inp;
}

istream& operator>>(istream& inp, PowerSupply* psu) {
	int wattage;
	string efficiencyRating;
	double price;
	cout << "Enter the wattage: ";
	inp >> wattage;
	cout << "Enter the efficiency rating: ";
	inp >> efficiencyRating;
	cout << "Enter the price: ";
	inp >> price;
	psu->setWattage(wattage);
	psu->setEfficiencyRating(efficiencyRating);
	psu->setPrice(price);

	return inp;
}

istream& operator>>(istream& inp, Battery* battery) {
	int capacity;
	cout << "Enter the capacity: ";
	inp >> capacity;
	battery->setCapacity(capacity);

	return inp;
}



istream& operator>>(istream& inp, ComputerAssembly* assembly) {
	PowerSupply* psu=new PowerSupply;
	Battery *battery=new Battery;
	Case *computerCase=new Case;
	double totalPrice;
	inp >> psu >> battery >> computerCase;
	totalPrice = psu->getPrice()  + computerCase->getPrice();
	assembly->setPowerSupply(*psu);
	assembly->setBattery(*battery);
	assembly->setComputerCase(*computerCase);
	assembly->setTotalPrice(totalPrice);

	return inp;
}

istream& operator>>(istream& inp, IntelComputer* ic) {
	PhysicalMemory* pm = new PhysicalMemory();
	MotherBoard* mb = new MotherBoard();
	GraphicsCard* g = new GraphicsCard();
	CPU* cpu = new CPU();

	cout << "Enter details for Physical Memory:\n";
	inp >> pm;
	cout << "Enter details for Motherboard:\n";
	inp >> mb;
	cout << "Enter details for CPU:\n";
	inp >> cpu;
	cout << "Enter details for Graphics Card:\n";
	inp >> g;

	ic = new IntelComputer( pm, mb, cpu,g);

	return inp;
}
istream& operator>>(istream& in, AppleSilicon* appleSilicon) {
	CPU *cpu=new CPU;
	GraphicsCard *gpu=new GraphicsCard;
	cout << "Enter (integrated) CPU details:" << endl;
	in >> cpu;
	cout << "Enter (integrated) Graphics card details:" << endl;
	in >> gpu;
	
	appleSilicon->setGraphicsCard(gpu);
	appleSilicon->setCPU(cpu);

	return in;
}
istream& operator>>(istream& inp, MacComputer* mc) {
	PhysicalMemory* pm = new PhysicalMemory();
	MotherBoard* mb = new MotherBoard();
	AppleSilicon* as = new AppleSilicon();

	cout << "Enter details for Physical Memory:\n";
	inp >> pm;
	cout << "Enter details for Motherboard:\n";
	inp >> mb;
	cout << "Enter details for the integrated cpu:\n";
	inp >> as;


	mc = new MacComputer(pm, mb, as);


	return inp;
}






istream& operator>>(istream& inp, PC* pc) {
	PowerSupply* p = new PowerSupply();
	Battery* b = new Battery();
	Case* c = new Case();
	StorageDevice* s = new StorageDevice;
	NetworkCard* n = new NetworkCard;
	IntelComputer* comp = new IntelComputer();

	cout << "Enter details for Power Supply:\n";
	inp >> p;
	cout << "Enter details for Battery:\n";
	inp >> b;
	cout << "Enter details for Case:\n";
	inp >> c;
	cout << "Enter total price for ComputerAssembly:\n";
	double total;
	inp >> total;
	
	cout << "Enter details for Intel Computer:\n";
	inp >> comp;
	cout << "Enter details of Network Card:\n";
	inp >> n;
	cout << "Enter Storage Device:\n";
	cin >> s;
	pc = new PC(p, b, c, s,n,total, comp);
	pc->setTotalPrice( p->getPrice() + c->getPrice() + s->getPrice() + total);

	cout << "Total price of PC: $" << pc->getTotalPrice() << endl;

	return inp;
}

istream& operator>>(istream& inp, Mac* mac) {
	PowerSupply* p = new PowerSupply();
	Battery* b = new Battery();
	Case* c = new Case();
	StorageDevice* s = new StorageDevice();
	NetworkCard* n = new NetworkCard;
	MacComputer* comp = new MacComputer();

	cout << "Enter details for Power Supply:\n";
	inp >> p;
	cout << "Enter details for Battery:\n";
	inp >> b;
	cout << "Enter details for Case:\n";
	inp >> c;
	cout << "Enter total price for ComputerAssembly:\n";
	double total;
	inp >> total;
	cout << "Enter Storage Device:\n";
	cin >> s;
	cout << "Enter details of Network Card:\n";
	inp >> n;
	cout << "Enter details for Mac Computer:\n";
	inp >> comp;

	mac = new Mac(p, b, c,s,n, total, comp);
	mac->setTotalPrice(p->getPrice()+c->getPrice()+total+s->getPrice());
	cout << "Total price of MAC: $" << mac->getTotalPrice()<< endl;

	return inp;
}

///////////////////////////////////////////////



void finalchoice() {
	PC* pc = new PC();
	Mac* mac = new Mac();
	
	int cho = 0;
	cout << "What do you want to build?\n1.PC\n2.MAC\n";
	cin >> cho;
	while (cho != 2 && cho != 1) {
		cout << "Invalid choice.Pick between 1 and 2.\n";
		cin >> cho;
	}
	if (cho == 1) {
		cout << "Build your PC:\n";
		PC* pc = new PC();
		mac = nullptr;
		cin >> pc;
	}
	else if (cho == 2) {
		cout << "Build your MAC:\n";
		Mac* mac = new Mac();
		pc = nullptr;
		cin >> mac;
	}
}
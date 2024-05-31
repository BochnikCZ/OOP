#include "RentalSystem.h"

void Demo_Client()
{
	Client* test_client = new Client(0, "John Doe", 20, true);

	cout << "Active Client objects: " << test_client->GetObjectsCountClient() << endl;
	test_client->Print();
	delete test_client;
	cout << "Active Client objects: " << Client::GetObjectsCountClient() << endl;
}

void Demo_Vehicle()
{
	Vehicle* test_vehicle = new Vehicle(0, "Škoda", "Octavia", 'F', 800);

	cout << "Active Vehicle objects: " << Vehicle::GetObjectsCountVehicles() << endl;
	test_vehicle->Print();
	printf("\n");
	test_vehicle->SetStatus('U');
	test_vehicle->Print();
	printf("\n");
	test_vehicle->SetStatus('F');
	test_vehicle->Print();
	delete test_vehicle;
	cout << "Active Vehicle objects: " << Vehicle::GetObjectsCountVehicles() << endl;
}
void Demo_Car()
{
	Car* test_car = new Car(2, "Volkswagen", "Golf", 'F', 750, 50, "2B3 5678", "hatchback", 2018);

	cout << "Active Vehicle objects: " << Vehicle::GetObjectsCountVehicles() << endl;
	test_car->Print();
	printf("\n");

	cout << "John Doe, 12 years old, tries to rent this car..." << endl;
	test_car->ConditionsCheck(12, false);
	printf("\n");
	cout << "Jane Doe, 19 years old, without a valid driving licence, tries to rent this car..." << endl;
	test_car->ConditionsCheck(19, false);
	printf("\n");
	cout << "James Doe, 18 years old, with a valid driving licence, tries to rent this car..." << endl;
	test_car->ConditionsCheck(18, true);
	printf("\n");

	test_car->SetStatus('U');
	cout << "Updated car status: " << test_car->GetStatus() << endl;
	printf("\n");
	cout << "Joyce Doe, 50 years old, with a valid driving licence, also wants to rent this car, but James did it first..." << endl;
	test_car->ConditionsCheck(50, true);
	printf("\n");

	cout << "How much would it cost, if you rented this car for 9 days?" << endl;
	cout << "(Fuel price per liter: 38.50)" << endl;
	cout << "Total price: " << test_car->CalculateTotalPrice(9, 38.50) << endl;

	delete test_car;

	cout << "Active Vehicle objects: " << Vehicle::GetObjectsCountVehicles() << endl;
}
void Demo_Motorcycle()
{
	Motorcycle* test_motorbike1 = new Motorcycle(5, "Harley-Davidson", "Iron 883", 'F', 600, 12.5, "2H3 5678", 883, "chopper", 1);
	Motorcycle* test_motorbike2 = new Motorcycle(3, "Vespa", "Primavera 50", 'F', 150, 8, "3V4 7890", 50, "scooter", 1);

	cout << "Active Vehicle objects: " << Vehicle::GetObjectsCountVehicles() << endl;
	test_motorbike1->Print();
	printf("\n");
	test_motorbike2->Print();
	printf("\n");


	cout << "John Doe, 12 years old, tries to rent the scooter..." << endl;
	test_motorbike2->ConditionsCheck(12, false);
	printf("\n");

	cout << "Justin Doe, 16 years old, without a valid driving licence, tries to rent the scooter..." << endl;
	test_motorbike2->ConditionsCheck(16, false);
	printf("\n");

	cout << "Jasmine Doe, 17 years old,with a valid driving licence tries to rent the chopper..." << endl;
	test_motorbike1->ConditionsCheck(17, true);
	printf("\n");

	cout << "Jane Doe, 19 years old, without a valid driving licence, tries to rent the scooter..." << endl;
	test_motorbike2->ConditionsCheck(19, false);
	printf("\n");

	cout << "James Doe, 30 years old, with a valid driving licence, tries to rent the scooter..." << endl;
	test_motorbike2->ConditionsCheck(30, true);
	printf("\n");

	test_motorbike2->SetStatus('U');
	cout << "Updated motorbike status: " << test_motorbike2->GetStatus() << endl;
	printf("\n");
	cout << "Joyce Doe, 50 years old, with a valid driving licence, also wants to rent the scooter, but James did it first..." << endl;
	test_motorbike2->ConditionsCheck(50, true);
	printf("\n");
	cout << "...so she rented the chopper!" << endl;
	test_motorbike1->ConditionsCheck(50, true);
	printf("\n");

	test_motorbike1->SetStatus('U');
	cout << "Updated motorbike status: " << test_motorbike1->GetStatus() << endl;
	printf("\n");

	cout << "How much would it cost, if you rented the chopper for 9 days?" << endl;
	cout << "(Fuel price per liter: 38.50)" << endl;
	cout << "Total price: " << test_motorbike1->CalculateTotalPrice(9, 38.50) << endl;

	delete test_motorbike1;

	cout << "Active Vehicle objects: " << Vehicle::GetObjectsCountVehicles() << endl;

	delete test_motorbike2;

	cout << "Active Vehicle objects: " << Vehicle::GetObjectsCountVehicles() << endl;
}
void Demo_Bicycle()
{
	Bicycle* test_bicycle = new Bicycle(10, "Trek", "FX 3 Disc", 'F', 150, "horská", 18, 24);

	cout << "Active Vehicle objects: " << Vehicle::GetObjectsCountVehicles() << endl;
	test_bicycle->Print();
	printf("\n");
	test_bicycle->ConditionsCheck(8, false);
	cout << "Little Johny rented the bike..." << endl;
	test_bicycle->SetStatus('U');
	cout << "Updated bicycle status: " << test_bicycle->GetStatus() << endl;
	printf("\n");
	cout << "...now, little Jamie is sad..." << endl;
	test_bicycle->ConditionsCheck(6, false);

	delete test_bicycle;
	cout << "Active Vehicle objects: " << Vehicle::GetObjectsCountVehicles() << endl;
}

void Demo_RentRequest()
{
	Car* test_car = new Car(2, "Volkswagen", "Golf", 'F', 750, 50, "2B3 5678", "hatchback", 2018);
	Client* test_client = new Client(0, "John Doe", 20, true);

	RentRequest* test_request = new RentRequest(0, 9, test_car, test_client);
	printf("\n");
	cout << "Active RentRequest objects: " << RentRequest::GetObjectsCountRequests() << endl;
	cout << "Fuel price: " << RentRequest::GetFuelPrice() << endl;
	printf("\n");
	test_request->Print();
	printf("\n");
	delete test_request;
	printf("\n");
	cout << "Active Vehicle objects: " << Vehicle::GetObjectsCountVehicles() << endl;
	cout << "Active Client objects: " << Client::GetObjectsCountClient() << endl;
	cout << "Active RentRequest objects: " << RentRequest::GetObjectsCountRequests() << endl;



	delete test_client;
	delete test_car;
}

void Demo()
{
	RentalSystem* Pujcovna = new RentalSystem(10);

	Pujcovna->CreateClient(0, "John Doe", 12, false);
	Pujcovna->CreateClient(1, "Jane Doe", 15, false);
	Pujcovna->CreateClient(2, "Justin Doe", 17, true);
	Pujcovna->CreateClient(3, "Julie Doe", 19, false);

	Pujcovna->RegisterVehicle(2, "Volkswagen", "Golf", 750, 50, "2B3 5678", "hatchback", 2018);
	Pujcovna->RegisterVehicle(5, "BMW", "X5", 1200, 70, "3C4 7890", "SUV", 2020);

	Pujcovna->CreateRequest(0, 9, Pujcovna->RegisterVehicle(0, "Skoda", "Octavia", 800, 55, "1A2 3456", "sedan", 2015), Pujcovna->CreateClient(4, "James Doe", 23, true));
	Pujcovna->CreateRequest(1, 5, Pujcovna->SearchVehicle(5), Pujcovna->SearchClient(4));

	cout << "Number of registered clients: " << Client::GetObjectsCountClient() << endl;
	cout << "Number of registered vehicles: " << Vehicle::GetObjectsCountVehicles() << endl;
	cout << "Number of active requests: " << RentRequest::GetObjectsCountRequests() << endl;

	cout << "Client you searched for: " << Pujcovna->SearchClient(2)->GetName() << endl;
	cout << "Vehicle you searched for: " << Pujcovna->SearchVehicle(2)->GetMake() << " " << Pujcovna->SearchVehicle(2)->GetModel() << endl;
	cout << "Request you searched for: " << Pujcovna->SearchRequest(0)->GetVehicle()->GetMake() << " " << Pujcovna->SearchRequest(0)->GetVehicle()->GetModel() << " for " << Pujcovna->SearchRequest(0)->GetClient()->GetName() << endl;

	Pujcovna->RemoveRequest(0);
	Pujcovna->RemoveClient(2);
	Pujcovna->RemoveVehicle(2);

	cout << "Number of registered clients: " << Client::GetObjectsCountClient() << endl;
	cout << "Client you searched for: " << Pujcovna->SearchClient(3)->GetName() << endl;
	cout << "Number of registered vehicles: " << Vehicle::GetObjectsCountVehicles() << endl;
	cout << "Number of active requests: " << RentRequest::GetObjectsCountRequests() << endl;

	delete Pujcovna;
}


int main()
{
	//Demo_Client();

	//Demo_Vehicle();
	//Demo_Car();
	//Demo_Motorcycle();
	//Demo_Bicycle();

	Demo_RentRequest();

	//Demo();

	return 0;
}
#include<iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//class containing car specs
class carSpecs{
public: 
    int year; 
    string model; 
    double price; 
    int mpg; 
    string color;
};


void getData(ifstream &inData, carSpecs cars[], int Length); 
void printCars(carSpecs cars[], int Length);


int main()
{
    int Length = 0;
    string str;

   

    ifstream inData;
    inData.open("carspecs.txt");

    // reads the number of lines in the file
    while (getline(inData, str)){
        Length++;
    }
    inData.close();
    inData.open("carspecs.txt");

    //dynamic array of classes 
    carSpecs *cars;
    cars = new carSpecs[Length];

    // Arrays of customizations and prices
    string customName[10] = {"Leather-Seats", "Apple-CarPlay", "Android-Auto", "Body-Molding", "3/36-Warranty", "6/72-Warranty", "Heated-Seats", "Wrap", "Upgraded-Navigation", "LED-Lights"};

    double customPrice[10] = {5000, 500, 500, 800, 1000, 1500, 400, 1300, 1600, 200};

    cout << setw(36) << setfill('*') << ' ' << endl;
    cout << "*"
         << " Governors School Car Dealership "
         << "*" << endl;
    cout << setw(36) << setfill('*') << ' ' << setfill(' ') << endl
         << endl;

    cout << "Hello and welcome to the Governors School Car Dealership!! Using this program you will be able to browse our inventory, customize, and purchase your brand new vehicle. Take a look at the vehicles we currently have below and select a model to get started." << endl
         << endl;

    getData(inData, cars, Length);
    printCars(cars, Length);
    inData.close();


    int input;
    int carSelected = -1;
    int customSelected = -1; 
    int numberOfCustoms = 0; 
    int customIndex, deleteIndex; 

    string model = "NO MODEL SELECTED";
    string selectedCustoms[customIndex];
    string customization, deletedCustomization; 
    double price = 0;
    cout << fixed << showpoint;
    cout << setprecision(2);

    do
    {
        cout << endl << endl;
        cout << "Model: " << model << ", Price: $" << price << ", Customs: ";
        for (int i = 0; i < numberOfCustoms; i++)
        {
            cout << selectedCustoms[i] << ", ";
        }
        cout << endl; 


        cout << "1. Select a Model" << endl;
        cout << "2. Display available customizations and prices" << endl;
        cout << "3. Add a customization" << endl;
        cout << "4. Delete a customization" << endl;
        cout << "5. Complete order" << endl;
        cout << "Enter Choice: ";
        cin >> input;

        switch (input)
        {
        case 1: //Prompts User to enter car model
            do
            {
                cout << "Enter the Exact Model: " << endl;
                cin >> model;

                for (int i = 0; i < Length; i++)
                {
                    if (model == cars[i].model)
                    {
                        carSelected = i;
                        price = cars[i].price;
                    }
                }

            } while (carSelected == -1);
            break;

        case 2: // Displays available customizations and prices
            cout << endl << "Available Customs: " << endl;
            cout << left << setw(30) << "Custom" << setw(15) << "Price" << endl; 
            for(int i = 0; i < 10; i++){
                cout << left << setw(30) << customName[i] << "$" << setw(20) <<  customPrice[i] << endl; 
                
            }
            break; 

        case 3: // Allows user to add customization
            if (model == "NO MODEL SELECTED"){
                cout << "Select a model first to add customizations" << endl; 
                }
            if (model != "NO MODEL SELECTED"){
                    do{
                        cout << "Enter the exact customization: ";
                        cin >> customization;
                        numberOfCustoms += 1;
                        for (int i = 0; i < 10; i++)
                        {
                            if (customization == customName[i])
                            {
                                customSelected = i;
                                selectedCustoms[customIndex] = customization;
                                price += customPrice[i];
                            }
                        }
                        customIndex += 1;
                    } while (customSelected == -1); 
                }
                break; 

            

            case 4: // Deletes inputted Customization
                
                cout << "Enter the customization to delete: ";
                    cin >> deletedCustomization; 
                    
                    for( int i = 0; i < numberOfCustoms; i ++){
                      if(selectedCustoms[i] == deletedCustomization){
                          deleteIndex = i; 
                          selectedCustoms[i] = " *REMOVED* "; 
                        }
                    }


                    for (int i = 0; i < 10; i++){
                        if(deletedCustomization == customName[i])
                        price -= customPrice[i]; 
                        }


        }

        

    } while (input != 5);

    //prints Receipt

    cout << endl << endl;
    cout << "**********************" << endl;
    cout << "* Dealership Receipt *" << endl;
    cout << "**********************" << endl;
    cout << endl;
    //prints selected car 
    cout << left << setw(10) << "Year" << setw(20) << "Model" << setw(10) << "Price" << setw(10) << "MPG" << setw(10) << "Color" << endl;
    cout << setw(60) << setfill('-') << "" << setfill(' ') << endl;

    cout << left << setw(10) << cars[carSelected].year << setw(20) << cars[carSelected].model << "$" << setw(10) << cars[carSelected].price << setw(10) << cars[carSelected].mpg << setw(10) << cars[carSelected].color << endl;

    cout << endl; 
    cout << "Customizations: " << endl; 

    //prints selected customizations
    for(int i = 0; i < numberOfCustoms; i++){
        if (selectedCustoms[i] != " *REMOVED* "){
            cout << left << setfill('-') << setw(30)<< selectedCustoms[i]; 
        }
        

        for(int j = 0; j < 10; j ++){
            if(selectedCustoms[i] == customName[j]){
                cout << setfill(' ') << " $" << setw(20) << customPrice[j] << endl;
            }
        }
    }
    cout << endl << endl << "Total Price: $" << price << endl;
    delete[] cars;
}

//reads data from input file
void getData(ifstream &inData, carSpecs cars[], int Length){

    for(int i = 0; i < Length; i++){
        inData >> cars[i].year >> cars[i].price >> cars[i].mpg >> cars[i].model >> cars[i].color; 
    }

}

//prints car inventory from input file
void printCars(carSpecs cars[], int Length){
    cout << left << setw(10) << "Year" << setw(20) << "Model" << setw(10) << "Price" << setw(10) << "MPG" << setw(10) << "Color" << endl;
    cout << setw(60) << setfill('-') << "" << setfill(' ') << endl;
    for(int i = 0; i < Length; i ++){
        cout << left << setw(10) << cars[i].year << setw(20) << cars[i].model << "$" << setw(10) << cars[i].price << setw(10) << cars[i].mpg << setw(10) << cars[i].color << endl;
    }
}



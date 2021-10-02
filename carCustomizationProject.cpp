/*
Name(s):Darrian Belcher
Date: 02/23/21
Program Name: Car Customization Project
Program Description: Freestyle project that allows the user to select a car read from a text file and add/remove listed customizations 
*/

#include<iostream>
#include <fstream>
#include <iomanip>

using namespace std;

//class containing car specs that will be read from text file
class carSpecs{
public: 
    int year; 
    string model; 
    double price; 
    int mpg; 
    string color;
};

/*
Summary: Reads data from carspecs file into array
Reasoning: Needed to obtain and store text file data
Input: N/A
Output: ifstream &inData, carSpecs cars[], int Length
*/
void getData(ifstream &inData, carSpecs cars[], int Length){

    for(int i = 0; i < Length; i++){
        inData >> cars[i].year >> cars[i].price >> cars[i].mpg >> cars[i].model >> cars[i].color; 
    }

}

/*
Summary: Prints car inventory in column format
Reasoning: Needed to display car specs
Input: N/A
Output: carSpecs cars[], int Length
*/
void printCars(carSpecs cars[], int Length){
    cout << left << setw(10) << "Year" << setw(20) << "Model" << setw(10) << "Price" << setw(10) << "MPG" << setw(10) << "Color" << endl;
    cout << setw(60) << setfill('-') << "" << setfill(' ') << endl;
    for(int i = 0; i < Length; i ++){
        cout << left << setw(10) << cars[i].year << setw(20) << cars[i].model << "$" << setw(10) << cars[i].price << setw(10) << cars[i].mpg << setw(10) << cars[i].color << endl;
    }
}


int main()
{
    int fileLength = 0;
    string str;


    ifstream inData;
    inData.open("carspecs.txt");

    // stores the number of lines in the text file
    while (getline(inData, str)){
        fileLength++;
    }

    inData.close();
    inData.open("carspecs.txt");

    //creates dynamic array of classes used to store car specs
    carSpecs *cars;
    cars = new carSpecs[fileLength];

    // Arrays of car customizations and their respective prices
    string customName[10] = {"Leather-Seats", "Apple-CarPlay", "Android-Auto", "Body-Molding", "3/36-Warranty", "6/72-Warranty", "Heated-Seats", "Wrap", "Upgraded-Navigation", "LED-Lights"};

    double customPrice[10] = {5000, 500, 500, 800, 1000, 1500, 400, 1300, 1600, 200};

    // Prints program header and description to terminal 
    cout << setw(36) << setfill('*') << ' ' << endl;
    cout << "*"
         << " Governors School Car Dealership "
         << "*" << endl;
    cout << setw(36) << setfill('*') << ' ' << setfill(' ') << endl
         << endl;

    cout << "Hello and welcome to the Governors School Car Dealership!! Using this program you will be able to browse our inventory, customize, and purchase your brand new vehicle. Take a look at the vehicles we currently have below and select a model to get started." << endl
         << endl;

    getData(inData, cars, fileLength);
    printCars(cars, fileLength);
    inData.close();

    int menuInput;

    //used for input validation and to store selected car and custom
    int carSelected = -1;
    int customSelected = -1; 

    //variables used to store, delete, and add customizations
    int numberOfCustoms = 0; 
    int customIndex, deleteIndex; 
    string customization, deletedCustomization; 
    string selectedCustoms[customIndex]; // stores selected customs



    string model = "NO MODEL SELECTED"; //stores model of car selected



    double totalPrice = 0;

    cout << fixed << showpoint;
    cout << setprecision(2);

    do
    {
        cout << endl << endl;
        //Displays user's selected car model, its price, and the user's selected customizations
        cout << "Model: " << model << ", Price: $" << totalPrice << ", Customs: ";
        for (int i = 0; i < numberOfCustoms; i++)
        {
            cout << selectedCustoms[i] << ", ";
        }
        cout << endl; 

        // Prints user input  options 
        cout << "1. Select a Model" << endl;
        cout << "2. Display available customizations and prices" << endl;
        cout << "3. Add a customization" << endl;
        cout << "4. Delete a customization" << endl;
        cout << "5. Complete order" << endl;
        cout << "Enter Choice: ";
        cin >> menuInput;

        switch (menuInput) // Switch statement analyzing user input 
        {
        case 1: //Prompts User to enter car model
            do // do-while loop that continues until a correct car model is entered
            {
                cout << "Enter the Exact Model: " << endl;
                cin >> model;

                for (int i = 0; i < fileLength; i++)
                {
                    if (model == cars[i].model)
                    {
                        carSelected = i;
                        totalPrice = cars[i].price; // stores the selected car's price
                    }
                }

            } while (carSelected == -1);
            break;

        case 2: // Displays available customizations and prices in column format
            cout << endl << "Available Customs: " << endl;
            cout << left << setw(30) << "Custom" << setw(15) << "Price" << endl; 
            for(int i = 0; i < 10; i++){
                cout << left << setw(30) << customName[i] << "$" << setw(20) <<  customPrice[i] << endl; 
                
            }
            break; 

        case 3: // Allows user to add customizations to selected car model
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
                                totalPrice += customPrice[i]; // adds the selected customization's price to total price
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
                        totalPrice -= customPrice[i]; // subtracts removed customization's price from total price
                        }


        }


    } while (menuInput != 5);

    //prints car dealership receipt

    cout << endl << endl;
    cout << "**********************" << endl;
    cout << "* Dealership Receipt *" << endl;
    cout << "**********************" << endl;
    cout << endl;
    
    //prints selected car and it's specs
    cout << left << setw(10) << "Year" << setw(20) << "Model" << setw(10) << "Price" << setw(10) << "MPG" << setw(10) << "Color" << endl;
    cout << setw(60) << setfill('-') << "" << setfill(' ') << endl;

    cout << left << setw(10) << cars[carSelected].year << setw(20) << cars[carSelected].model << "$" << setw(10) << cars[carSelected].price << setw(10) << cars[carSelected].mpg << setw(10) << cars[carSelected].color << endl;

    cout << endl; 

    //prints selected customizations if they have not been removed

    cout << "Customizations: " << endl; 

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
    cout << endl << endl << "Total Price: $" << totalPrice << endl;
    delete[] cars;
}





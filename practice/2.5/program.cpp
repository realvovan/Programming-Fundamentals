/*
    Done by:
    Student: Hordiienko Volodymyr
    Group: 123:2
    Practice 2.5
*/

#include "iostream"
#include "vector"
#include "chrono"
#include "sstream"
#include "cctype"

using std::string;
using std::vector;
using std::cout;
using std::cin;

string toString(int number) {
    std::ostringstream oss;
    oss << number;
    return oss.str();
}

string toString(float number) {
    std::ostringstream oss;
    oss << number;
    return oss.str();
}

struct Car {
    string Brand;
    string Model;
    int Year;
    float RentalPricePerDay;
    bool IsAvailable = true;

    Car(string brand, string model, int year, float rentalPricePerDay) {
        this->Brand = brand;
        this->Model = model;
        this->Year = year;
        this->RentalPricePerDay = rentalPricePerDay;
    }

    string GetInfo() {
        return "Brand: " + this->Brand
            + ", Model: " + this->Model
            + ", Year: " + toString(this->Year)
            + ", Rental price: $" + toString(this->RentalPricePerDay)
            + "/day";
    }
};


int getCurrentYear() {
    //istg i hate c++ why is this the way to get the current year
    //at least that's what i found on the internet
    std::time_t currentTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    return 1900 + std::localtime(&currentTime)->tm_year;
}

string toLower(string str) {
    string temp = str;
    for(char &c : temp) {
        c = std::tolower(c);
    }
    return temp;
}

void intputCars(vector<Car> &cars) {
    int n;
    cout << "How many cars would you like to add? ";
    cin >> n;
    if(n < 1) {
        cout << "Please enter a number greater than zero\n";
        return;
    }
    static int currentYear = getCurrentYear();
    for(int i = 0; i < n; i++) {
        string brand,model;
        int year;
        float rentPrice;
        cout << "Enter details for car " << i+1 << ":\n";
        cout << "Brand: ";
        cin >> brand;
        cout << "Model: ";
        cin >> model;
        cout << "Year: ";
        cin >> year;
        //idk what the minimum year should be so i'll just leave it as 0
        while(year <= 0 || year > currentYear) {
            cout << "Please enter a valid year: ";
            cin >> year;
        }
        cout << "Rental price per day: ";
        cin >> rentPrice;
        while(rentPrice <= 0) {
            cout << "Please enter a valid price: ";
            cin >> rentPrice;
        }
        cout << "\n";
        cars.push_back(Car(brand,model,year,rentPrice));
    }
}

void displayAvailableCars(const vector<Car> cars) {
    cout << "Available cars:\n";
    bool isEmpty = true;
    for(Car car : cars) {
        if(!car.IsAvailable) continue;
        isEmpty = false;
        cout << car.GetInfo() + "\n";
        
    }
    if(isEmpty) cout << "No cars available to rent\n";
}

void rentCar(vector<Car> &cars, vector<Car*> &rentedCars) {
    vector<int> rentableCarsIndices;
    string brand,model;
    cout << "Please enter the brand name and model of the car you'd like to rent: ";
    cin >> brand >> model;
    for(int i = 0; i < cars.size(); i++) {
        if(toLower(cars[i].Brand) == toLower(brand) && toLower(cars[i].Model) == toLower(model) && cars[i].IsAvailable) {
            rentableCarsIndices.push_back(i);
        }
    }
    if(rentableCarsIndices.size() == 0) {
        cout << brand << " " << model << " is not on the list of available cars!\n";
        return;
    } else if(rentableCarsIndices.size() == 1) {
        cars[rentableCarsIndices[0]].IsAvailable = false;
        rentedCars.push_back(&cars[rentableCarsIndices[0]]);
    } else {
        cout << "There are multiple " << brand << " " << model << "s available. Please choose which one you'd like to rent\n";
        for(int i = 0; i < rentableCarsIndices.size(); i++) {
            cout << (i+1) << ". " << cars[rentableCarsIndices[i]].GetInfo() << "\n";
        }
        int choice;
        cin >> choice;
        while(choice < 1 || choice > rentableCarsIndices.size()) {
            cout << "Please enter a valid choice: ";
            cin >> choice;
        }
        cars[rentableCarsIndices[choice - 1]].IsAvailable = false;
        rentedCars.push_back(&cars[rentableCarsIndices[choice - 1]]);
    }
    cout << "Success! You have rented a " << brand << " " << model << "\n";
}

void returnCar(vector<Car*> &rentedCars) {
    if(rentedCars.size() == 0) {
        cout << "You do not have cars to be returned\n";
        return;
    }
    cout << "Please choose which car you'd like to return:\n";
    for(int i = 0; i < rentedCars.size(); i++) {
        cout << (i+1) << ". " << rentedCars[i]->GetInfo() << "\n";
    }
    int choice;
    cin >> choice;
    while(choice < 1 || choice > rentedCars.size()) {
        cout << "Please enter a valid choice: ";
        cin >> choice;
    }
    rentedCars[choice - 1]->IsAvailable = true;
    cout << "Successfully returned a " << rentedCars[choice - 1]->Brand << " " << rentedCars[choice - 1]->Model << "\n";
    //not sure if this is how you dispose of a pointer properly
    //never used pointers before lol
    rentedCars[choice - 1] = nullptr;
    rentedCars.erase(rentedCars.begin() + choice - 1);
}

void findMostExpensiveCar(vector<Car> cars) {
    vector<Car> expensiveCars;
    float maxPrice = 0; //price cannot be less or equal to zero
    for(Car car : cars) {
        if(!car.IsAvailable) continue;
        if(car.RentalPricePerDay > maxPrice) {
            maxPrice = car.RentalPricePerDay;
            expensiveCars.clear();
            expensiveCars.push_back(car);
        } else if(car.RentalPricePerDay == maxPrice) {
            expensiveCars.push_back(car);
        }
    }
    if(expensiveCars.size() == 0) cout << "There are no cars available!\n";
    else if(expensiveCars.size() == 1) cout << "The most expensive available car is:\n";
    else cout << "The most available expensive cars are:\n";
    for(Car car : expensiveCars) {
        cout << car.GetInfo() << "\n";
    }
}

void clearConsole() {
    #ifdef _WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

int main() {
    //predefined a list of cars for testing
    vector<Car> cars {
        Car("Honda","Civic",2005,6.9),
        Car("Toyta","Corolla",2018,4.20),
        // Car("BMW","X5",1955,65),
        // Car("Mercedes","X5",1955,65),
        // Car("test","X5",1955,65),
        // Car("Honda","Civic",1966,4.20),
        };
    vector<Car*> rentedCars;
    bool isRunning = true;
    while(isRunning) {
        int n;
        cout << "Choose an action:\n"
                "1. Input cars\n"
                "2. Display available cars\n"
                "3. Display rented cars\n"
                "4. Rent a car\n"
                "5. Return a car\n"
                "6. Display the most expensive car\n"
                "7. Remove a car from the list\n"
                "8. Clear console\n"
                "9. Exit\n";
        cin >> n;
        switch(n) {
        case 1:
            intputCars(cars);
            break;
        case 2:
            displayAvailableCars(cars);
            break;
        case 3:
            if(rentedCars.empty()) {
                cout << "You have not rented any cars\n";
            } else {
                cout << "Cars you've rented:\n";
                for(Car* car : rentedCars) {
                    cout << car->GetInfo() << "\n";
                }
            }
            break;
        case 4:
            rentCar(cars,rentedCars);
            break;
        case 5:
            returnCar(rentedCars);
            break;
        case 6:
            findMostExpensiveCar(cars);
            break;
        case 7:
            //todo: add this
            break;
        case 8:
            clearConsole();
            break;
        case 9:
            isRunning = false;
            continue;
        default:
            clearConsole();
            cout << "Please enter a valid option!";
            break;
        }
        system("pause");
    }
}

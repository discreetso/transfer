#include <iostream>
#include <string>

using namespace std;

class CarNode {
    private:
        string carNumber;
        CarNode* next;

    public:
        // constructor
        CarNode(const string& number);

        string getCarNumber();
        CarNode* getNext();
        void setNext(CarNode* nextNode);
};

// constructor
CarNode::CarNode(const string& number) {
    carNumber = number;
    next = nullptr;
}

// getter for car number
string CarNode::getCarNumber() {
    return carNumber;
}

// getter for next node
CarNode* CarNode::getNext() {
    return next;
}

// setter for next node
void CarNode::setNext(CarNode* nextNode) {
    next = nextNode;
}

class ParkingLot {
    private:
        CarNode* top;
        int size;

    public:
        ParkingLot();
        ~ParkingLot();

        bool isEmpty();

        void push(const string& carNumber);
        string pop();

        string peek();
        void display();

        int getSize();
};

ParkingLot::ParkingLot() {
    top = nullptr;
    size = 0;
}

ParkingLot::~ParkingLot() {
    while(!isEmpty()) {
        pop();
    }
}

bool ParkingLot::isEmpty() {
    return top == nullptr;
}

void ParkingLot::push(const string& carNumber) {
    CarNode* newNode = new CarNode(carNumber);
    newNode->setNext(top);
    top = newNode;
    size++;
    cout << "Car with number " << carNumber << " parked succesfully!" << endl;
}

string ParkingLot::pop() {
    if (isEmpty()) {
        return "";
    }

    CarNode* temp = top;
    string carNumber = top->getCarNumber();
    top = top->getNext();
    delete temp;
    size--;

    return carNumber;
}

string ParkingLot::peek() {
    if(isEmpty()) {
        return "";
    }

    return top->getCarNumber();
}

void ParkingLot::display() {
    if(isEmpty()) {
        cout << "Parking lot is empty" << endl;
        return;
    }

    cout << "Currently parked cars: " << endl;
    CarNode* current = top;
    while (current != nullptr) {
        cout << "Car number: " << current->getCarNumber() << endl;
        current = current->getNext();
    }
}

int ParkingLot::getSize() {
    return size;
}

int main() {
    cout << "Student Name: Muhammad Huzaifa" << endl;
    cout << "Student ID: BC220209840" << endl;
    cout << "````````````````````````````````````" << endl;

    ParkingLot parkingLot;

    string vuIdCar = "9840";
    parkingLot.push(vuIdCar);

    cout << "--- Parking more cars ---" << endl;
    parkingLot.push("PAK-301");
    parkingLot.push("PAK-301P");

    cout << "--- Removing the last parked car ---" << endl;
    string removedCar = parkingLot.pop();
    if(!removedCar.empty()) {
        cout << "car with numebr " << removedCar << " removed from parking lot." << endl;
    }

    cout << "--- Dsiplaying all remaining cars  in parking lot ---" << endl;
    parkingLot.display();

    cout << "\nProgram executed successfully";
    cout << "-----------------------------------" << endl;

    return 0;
}
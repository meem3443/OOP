#include<iostream>
using namespace std;

// Model: Car
class Car {
    int carNum;
    string ownerName;

public:
    int getCarNum() {
        return carNum;
    }

    string getOwnerName() {
        return ownerName;
    }

    void setCarNum(int num) {
        carNum = num;
    }

    void setOwnerName(string name) {
        ownerName = name;
    }

    Car() {
        // Constructor implementation
    }

    Car(int num, string ownername) {
        carNum = num;
        ownerName = ownername;  // Corrected typo here
    }
};

// View: CarView
class CarView {
public:
    void printDetailInfo(string ownerName, int carNum) {
        cout << "owner name: " << ownerName << endl;
        cout << "car number: " << carNum << endl;
    }
};

// Controller: CarController
class CarController {
private:
    Car* model;
    CarView* view;

public:
    CarController() {
        model = nullptr;
        view = nullptr;
    }

    CarController(Car* car, CarView* carview) {
        model = car;
        view = carview;
    }

    void setCarDetails(int num, string name) {
        model->setCarNum(num);
        model->setOwnerName(name);
    }

    void updateView() {
        view->printDetailInfo(model->getOwnerName(), model->getCarNum());
    }
};

int main() {
    // Create instances of Model, View, and Controller
    Car carModel;
    CarView carView;
    CarController carController(&carModel, &carView);

    // Set car details using the controller
    carController.setCarDetails(123, "Kim Jin seo");

    // Update and print car details using the controller and view
    carController.updateView();

    return 0;
}

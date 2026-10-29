#include "menu.h"

menu::menu():zoo(Zoo()) {}

menu::~menu() {}


void menu::addAnimal(){

    cout<<"What animal do you want to add?"<<endl;
    cout<<"1. Sponges"<<endl;
    cout<<"2. Corals"<<endl;
    cout<<"3. Lion"<<endl;
    cout<<"4. Shark"<<endl;
    cout<<"5. Wolf"<<endl;
    cout<<"6. Horse"<<endl;
    cout<<"7. Zebra"<<endl;
    cout<<"8. Sheep"<<endl;
    cout<<"9. Cows"<<endl;
    cout<<"10. Buffalo"<<endl;

    int choice;
    cin>>choice;
    switch (choice) {
        case 1:
            zoo.AddAnimal(new Sponges());
            break;
        case 2:
            zoo.AddAnimal(new Corals());
            break;
        case 3:
            zoo.AddAnimal(new Lion());
            break;
        case 4:
            zoo.AddAnimal(new Shark());
            break;
        case 5:
            zoo.AddAnimal(new Wolf());
            break;
        case 6:
            zoo.AddAnimal(new Horse());
            break;
        case 7:
            zoo.AddAnimal(new Zebra());
            break;
        case 8:
            zoo.AddAnimal(new Sheep());
            break;
        case 9:
            zoo.AddAnimal(new Cows());
            break;
        case 10:
            zoo.AddAnimal(new Buffalo());
            break;
        default:
            break;

    }
}


void menu::InsertAnimals(){
    cout<<"Add 5 animals!"<<endl;

    for (int i = 0; i < 5; i++) {
        addAnimal();
    }
}

void menu::Menu() {
    int choice;
    do {
        cout<<"What do you want to do?"<<endl;
        cout<<"1. Add animals"<<endl;
        cout<<"2. Feed animals"<<endl;
        cout<<"3. Show animals"<<endl;
        cout<<"4. Fitness animals"<<endl;
        cout<<"5. Show lions"<<endl;
        cout<<"6. Exit"<<endl;
        cin>>choice;
        switch (choice) {
            case 1:
                addAnimal();
                break;
            case 2:
                zoo.Feed();
                break;
            case 3:
                zoo.Show();
                break;
            case 4:
                zoo.Fitness();
                break;
            case 5:
                zoo.LionShow();
                break;
            case 6:
                break;
            default:
                break;
        }
    } while (choice != 6);
}
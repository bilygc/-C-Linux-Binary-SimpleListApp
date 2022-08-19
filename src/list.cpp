#include "include/list.h"

void List::print_menu (){
    int choice;

    cout << "****************************\n";
    cout << " 1 - Print list. \n";
    cout << " 2 - Add to list. \n";
    cout << " 3 - Delete from list. \n";
    cout << " 4 - Save list. \n";
    cout << " 5 - Quit. \n";
    cout << " Enter your choice and press Return ";

    cin >> choice;

    switch (choice){
        case 1:
            print_list();
        break;
        case 2:
            add_list();
        break;
        case 3:
            delete_item();
        break;
        case 4:
            save_list();
        break;
        case 5:
            return;
        default:
            cout << "Sorry that choice doesnt exist\n";
        break;
    }
}

void List::add_list(){
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "*******************************\n";
    cout << "***********Add Item************\n";
    cout << " Type an item and press Enter : ";

    string item;

    cin >> item;

    list.push_back(item);

    cout << " Item Successfully added!!";
    cin.clear();

    print_menu();


}

void List::delete_item(){
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "*******************************\n";
    cout << "***********Delete Item************\n";
    cout << " Type an index to delete  and press Enter :\n";

    if(list.size()){
        for(int i =0; i < (int)list.size(); i++){
            cout <<"[" << i << "]" << ": " << list[i] << endl;
        }
        int index;
        cin >> index;

        string deletedItem = list[index];

        list.erase(list.begin()+ index);

        cout << "\n\nitem: " << deletedItem << " successfully deleted at index: " << index << endl;

        
    }else{
        cout << "\nTheres no items in the list\n";
    }
        print_menu();
}

void List::print_list(){
    if(list.empty()){
        cout << "\n\n\n\n\ntheres no items in the list\n\n\n";
    }else{
        cout << "\n\n List items\n\n";
        for(int i =0; i < (int)list.size(); i++){
            cout <<"[" << i << "]" << ": " << list[i] << endl;
        }
        cout << "\n\n";
    }

    print_menu();
}

bool List::find_user_list(){
    bool user_found = false;

    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "*******************************\n";
    cout << "***********Find user: " << name << " ************\n";

    for (int user_index = 0; user_index < (int)mainList.size() ; user_index++)
    {
        if (mainList[user_index][0] == name){
            cout << "Found user: " << name << "\n";
            list = mainList[user_index];
            currentUserIndex = user_index;
            user_found = true;
            break;
        }
    }

    if (!user_found){
        cout << "User: " << name << " not found\n";
        list.push_back(name);
        mainList.push_back(list);
        currentUserIndex = (int)mainList.size() - 1;
    }
    return user_found;
    
}

void List::save_list(){

    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout << "*******************************\n";
    cout << "***********Save list***********\n";

    mainList[currentUserIndex] = list;
    print_menu();

}
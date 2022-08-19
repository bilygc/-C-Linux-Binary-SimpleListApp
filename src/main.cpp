#include "include/list.h"
#include "include/database.h"

int main (int args_count, char *args[]){
    Database data;
    List simpleList;

    if(args_count > 1){

        //take the argument
        simpleList.name = string((args[1]));
        //read from de db (file list.sl) and pupulate 2D vector mainList
        simpleList.mainList = data.read();
        //search for the user(argument) in the db, 
        simpleList.find_user_list();
        //print the main menu
        simpleList.print_menu();
        //write out the new  data to the db if the data was saved first in the option 4 of the main menu
        data.write(simpleList.mainList);

    }else{
        cout << "no arguments provided" << endl;
    }



    return 0;
}
#include "include/database.h"


void Database::write(vector<vector<string>> mainList){

    ofstream db;
    db.open("db/list.sl");

    if(db.is_open()){
        for(int index_user = 0; index_user < (int)mainList.size(); index_user++){
            for(int index_data = 0; index_data < (int)mainList[index_user].size(); index_data ++){
                if(index_data == 0){

                    db << "#" << mainList[index_user][index_data] << "\n";
                }else{
                    db << mainList[index_user][index_data] << "\n";                    
                }
            }
            db << "%" << "\n";

        }
    }else{
        cout << "The file is not open";
    }

    db.close();
}

vector<vector<string>> Database::read(){
    ifstream db;
    string line;
    vector<string> users;

    db.open("db/list.sl");

    if(db.is_open()){
        while(getline(db, line, '\n')){
            if(line.front() == '#'){
                line.erase(line.begin());
                users.push_back(line);
                cout << "found a user: " << line << endl;
            }else if (line.front() == '%'){
                cout << "found a percentage: \n";
                mainList.push_back(users);
                users.clear();
            }else{
                cout << "found data: " << line << endl;
                users.push_back(line);

            }

        }
    }else{
        cout << "the db could not be opened";
    }
    return mainList;
}
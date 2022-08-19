#include <iostream>
#include <vector>

using namespace std;

class List {
    private:

    protected:

    public:
    List(){

    }

    ~List(){

    }

    vector<string> list;
    vector<vector<string>> mainList;
    string name;
    int currentUserIndex;

    void print_menu();
    void print_list();
    void add_list();
    void delete_item();
    bool find_user_list();
    void save_list();
};
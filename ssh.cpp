#include <iostream>
#include <fstream> //file reading (not used)
#include <cstdio> // for popen
#include <string> 


using namespace std;

int options_option;
int menu_option;
int help_menu_option;

//int option; changes to self int 
//bool linux;
bool putty;
bool windows;
bool linux;
/*
void clear(){
    linux == true; // for debbuging
    if (linux == false){
    string command = "cls";
    system(command.c_str());
    }
    if (linux == true){
        string command = "clear";
        system(command.c_str());
    }
}
*/
void clear(){
    string clear = "cls";
    system(clear.c_str());
}

void clear_check_system(){  //   MAKE TO POPEN
    string info_windows;
    string info_linux;
    string check_windows = "ipconfig";
    string check_linux = "ip add"; 
    FILE* pipe=_popen(check_windows.c_str(), "r");
    char buffer[256];
    while(fgets(buffer, sizeof buffer, pipe)){
        info_windows = buffer;
        if(info_windows.find("Windows IP Configuration")){ //string.find("") USAGE : use to find text in string
            windows = true;
        }
        /*else 
        {
            windows = false;
            FILE* linux = _popen(check_linux.c_str(), "r");
            char buffer[256];
            while(fgets(buffer, sizeof buffer, linux));
            {
                info_linux = buffer;
                if (info_linux.find("eth0"))
                {
                    linux = true;
                }

                
            }
        }
        */
        
        
        
    }
    _pclose(pipe);
    if (windows = true)
    {
      clear();
    
    }
    else if (windows = false)
    {
      clear();
    }
    /*
    else if (condition)
    {
       cout << "linux";
    }
    */
}

void main_menu(){
    //int menu_option; 
    clear(); //to clear the screen
    cout << "1.Connect \n2.Options \n3.Help\nEnter number: ";
    cin >> menu_option;
}


void options(){
    //int options_option;
    clear(); //to clear the screen
    while (true)
    {
        cout << "Those are different settings\n1.Use putty\n2.Return to menu\n";
        cin >> options_option;
        if (options_option == 1){
            putty = true;

        }
        if (options_option == 2){
            return;  // Just return from the options function, go back to the main menu
        }
        // You can add functionality for "Use putty" 
    }
}

void help_menu(){
    //int help_menu_option;
    clear(); //to clear the screen
    while (true)
    {
        cout << "This is the help menu: \nThose are the terms the connector works with";  //TODO to fix the full help
        cout << "\nPress 1 to return to menu: ";
        cin >> help_menu_option;
        if (help_menu_option == 1){
            return;  // Return to the main menu after selecting '1'
        }
    }
}


void connect(){
    clear(); //to clear the screen
    if (putty == false)
    {
        string address;
        string port;
        string user;
        cout << "vuvedi address , port i user : ";
        cin >> address >> port >> user; 
        string ssh_connect = "ssh " + user + "-l" + address + " -p " + port;
        system(ssh_connect.c_str());
        FILE* pipe = _popen(ssh_connect.c_str(), "r");
        char buffer[265];
        while(fgets(buffer, sizeof(buffer), pipe)) {
            cout << buffer;
        }
        _pclose(pipe);
        
    }
    
}


int main(){
    while (true){
    main_menu();
    if (menu_option == 1){
        connect();
    }

    if (menu_option == 2){
        options();
    }

    if (menu_option == 3){
        help_menu();
    }
    if (menu_option == 4){
        clear_check_system();
    }

    }

    return 0;
}

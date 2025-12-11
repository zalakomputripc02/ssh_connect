#include <iostream>
#include <cstdio> // for popen
#include <string> 


using namespace std;

int options_option;
int menu_option;
int help_menu_option;


bool putty;
bool windows;
bool linux;

//------------CLEARING FUNCTIONS--------------------
void clear_windows(){
    string clear = "cls";
    system(clear.c_str());
}


void clear_linux(){
    string clear = "clear";
    system(clear.c_str());
}


void clear_check_system(){  //   MAKE TO POPEN
    string info_windows;
    string check_windows = "ipconfig";
    FILE* pipe=_popen(check_windows.c_str(), "r");
    char buffer[256];
    while(fgets(buffer, sizeof buffer, pipe)){
        info_windows = buffer;
        if(info_windows.find("Windows IP Configuration")){ //string.find("") USAGE : use to find text in string
            windows = true;
        }
        else 
        {
            linux = true;
        }
    
    }
    _pclose(pipe);

}


void clear_check(){
    if (windows = true)
    {
      clear_windows();
    
    }
    else if (windows = false)
    {
      clear_linux();
    }
}






//------------------MAIN MENU FUNCTIONS--------
void main_menu(){
    clear_check(); //to clear the screen
    cout << "1.Connect \n2.Options \n3.Help\nEnter number: ";
    cin >> menu_option;
}





//-------------------OPTIONS MENU--------------
void options(){
    clear_check(); //to clear the screen
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



//--------------------HELP MENU-----------------

void help_menu(){
    clear_check(); //to clear the screen
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






//-------------------CONNECTIONS------------------
void connect(){
    clear_check(); //to clear the screen
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









//----------------MAIN RUN-------------------

int main(){
    clear_check_system();
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

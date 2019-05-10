#include <iostream>
#include <string>
#include "Scene.h"
#include <sys/types.h>
#include <dirent.h>

using namespace std;

void help(string mode, bool fileSelected);
vector<string> list(string mode);
void _new(string mode, string newFileName);
string select(string currentMode, string newFileName);
void save(string mode);

int main(int argc, char* argv[])
{ 
    string mode = "scene";
    bool fileSelected = false;

    help(mode, fileSelected);    

    string userInput;

    do
    {
        cin >> userInput;

        if(userInput == "-list")
        {
            vector<string> files = list(mode);


            cout<<"files are" <<endl;
            for(string x : files){
                cout<<x <<endl;
            }
        }
        else if(userInput == "-new")
        {
            cout<<"Enter new files name: ";
            cin >> userInput;

            _new(mode, userInput);
        }
        else
        {
            help(mode, fileSelected);
        }       
    }while(userInput != "-exit");

    return 0;
}

void help(string mode, bool fileSelected)
{
    cout<< "Current Mode: " << mode << endl;
    cout<< "---Valid Commands---" << endl;
    cout<< "-list\t\tlists available " << mode << " files" << endl;
    cout<< "-new\t\tcreates a new " << mode << " file" << endl;
    cout<< "-select\t\tattempts to select a " << mode << " with the given filename" << endl;
    cout<< "-delete\t\tdeletes if it exists" << endl;

    if(fileSelected)
    {    
        cout<< "-save\tsaves the currently selected file" << endl;
        // cout<< "-remove\t\t\tremoves" << endl;
        cout<< "-exit\texits currently selected file" << endl;
        
    }
    else
    {
        cout<< "-exit\t\texits program" << endl;
    }
}

vector<string> list(string mode)
{
    vector<string> files = vector<string>();

    DIR* dir = opendir(".");

    struct dirent * dp;

    while ((dp = readdir(dir)) != NULL) {
        //get current file name
        string currentFileName = dp->d_name;

        //get its last letter
        string::reverse_iterator currentFileNameLetterCheck = currentFileName.rbegin();

        //get modes last letter
        string::reverse_iterator currentModeLetterCheck = mode.rbegin();

        while(*currentModeLetterCheck == *currentFileNameLetterCheck && currentModeLetterCheck != mode.rend())
        {
            currentModeLetterCheck++;
            currentFileNameLetterCheck++;
            
        }

        if(currentModeLetterCheck == mode.rend())
        {
            files.push_back(currentFileName);
        }
    }

    closedir(dir);

    return files;
}

void _new(string mode, string newFileName)
{
    vector<string> currentFiles = list(mode);

    vector<string>::iterator it = currentFiles.begin();

    while(it != currentFiles.end() && *it != newFileName + "." + mode)
    {
        it++;
    }

    if(it == currentFiles.end())
    {
        ofstream file;

        file.open (newFileName + "." + mode);

        file.close();

        cout<< newFileName << "." << mode << " created" << endl;
    }
    else
    {
        cout<< "Error file already exists" << endl;
    }
    
}

//returns the new mode
string select(string currentMode, string newFileName)
{
    return "";
}

void save(string mode)
{

}

// void _delete(string mode)
// {

// }
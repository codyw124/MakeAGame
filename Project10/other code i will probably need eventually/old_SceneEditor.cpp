//Cody Ware
//5/19/19

#include <iostream>
#include <string>
#include <dirent.h>
#include "stdio.h"
#include "../headers/Scene.h"

int main(int argc, char *argv[])
{

    string userInput;

    do
    {
        cin >> userInput;

        if (userInput == "-list")
        {
            vector<string> files = _list(mode);

            if (files.size() > 0)
            {
                cout << "files are" << endl;
                for (string x : files)
                {
                    cout << x << endl;
                }
            }
            else
            {
                cout << "No files of type ." << mode << endl;
            }
        }
        else if (userInput == "-new")
        {
            _new(mode);            
        }
        else if(userInput == "-save")
        {
            cout << "Enter new files name: ";
            cin >> userInput;

            save(mode, userInput);
        }
        else if (userInput == "-select")
        {
            cout << "Enter a " << mode << " file to select: ";
            cin >> userInput;

            //make sure user input + mode exists
            if(fileExistsInCurrentDirectory(userInput, mode))
            {
                // loadScene(userInput, mode);
                workingOnFile = true;
            }
            else
            {
                cout << "Error " << userInput << "." << mode << " doesnt exist" << endl;
            }
        }
        else if (userInput == "-delete")
        {
            cout << "Enter name of file to delete: ";
            cin >> userInput;

            _delete(mode, userInput);
        }
        // else if(userInput == "-exit")
        // {
        //     if(mode == "gameobject")
        //     {
        //        mode = "scene";
        //        workingOnFile =  
        //     }
        // }
        else
        {
            help(mode, workingOnFile);
        } 
    } while (userInput != "-exit");

    return 0;
}



void save(string mode, string newFileName)
{
    if (!fileExistsInCurrentDirectory(newFileName, mode))
    {
        ofstream file;

        file.open(newFileName + "." + mode);

        Scene x = Scene();

        file << x.toXML();

        file.close();

        cout << newFileName << "." << mode << " created" << endl;
    }
    else
    {
        cout << "Error file already exists" << endl;
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

void _delete(string mode, string fileToTryAndDelete)
{
    if (remove((fileToTryAndDelete + "." + mode).c_str()) != 0)
    {
        cout << "Delete failed" << endl;
    }
    else
    {
        cout << fileToTryAndDelete << "." << mode <<" has been deleted" << endl;
    }
}

void _new(string mode)
{
    if(mode == "scene")
    {
        
    }
    else if(mode == "gameobject")
    {

    }
    else if(mode == "component")
    {

    }
}
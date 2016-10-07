/* main.cpp for oc compiler*/
#include <iostream>
#include <string>   // for string class
#include <vector>   // for vector class
using namespace std;    // std::string can now be called as string
using std::cout;    // for some reason the above namespace does not work for cout

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for string function ex.strlen()
#include <unistd.h> // for getopt

#include "stringset.h"

void usage(string program);
bool isOcFile(string file);

int main (int argc, char* argv[]){
    
    /*Options*/
    for (;;) {
        int opt = getopt(argc, argv, "@D:lyh");
        if (opt == EOF) break;  //End Of File
        switch (opt) {
            case '@':
            //    cout << "@" << endl;    //test
                break;
            case 'D':
            //    cout << "D" << endl;    //test
                break;
            case 'l':
            //    cout << "l" << endl;    //test
                break;
            case 'y':
            //    cout << "y" << endl;    //test
                break;
            case 'h':
            //    cout << "h" << endl;    //test
                usage(argv[0]);
                break;
        }
        
    }
    
//    //for understanding optind (optINDEX)
//    cout << "optind = " << optind << endl;
//    cout << "argc = " << argc << endl;
//    for (int j=0; j<argc; j++) {
//        cout << j << ": " << argv[j] << endl;
//    }
    
    /*Check input and suffix*/
    if (optind == argc) {
        cerr <<("Please specify a program file.\n");
        return 1;
    } else if (optind + 1 < argc){
        cerr << ("Only one program file is allowed.\n");
        return 1;
    }
    
    string infile = argv[optind];
    if(!isOcFile(infile)){
        cerr << "InputFileError: file '" << infile << "' is not an oc program.\n";
        return 1;
    }
    
}

bool isOcFile(string file){
    int n = file.size();
    bool condition = (file[n-1] == 'c')&&(file[n-2] == 'o')&&(file[n-3] == '.');
    if(condition){
        return true;
    }
    return false;
}

// Display Usage, not require
void usage(string program){
    cout << "usage:" << program << " [-D <define>] [-yl] [-h](usage) <source file>" << endl;
    exit(0);
}


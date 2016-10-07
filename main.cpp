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

/*helper*/  void usage(string program);
/*suffix*/  bool isOcFile(string file);
/*Options*/ int scan_opt(int argc, char* argv[]);
/*check input*/ void check_input(int optIndex, int argc);
/*check suffix*/void check_suffix(int optIndex, char* argv[]);


int main (int argc, char* argv[]){
    int optIndex = scan_opt(argc, argv);
    check_input(optIndex, argc);
    check_suffix(optIndex, argv);

}

/*check suffix*/
void check_suffix(int optIndex, char* argv[]){
    string infile = argv[optIndex];
    if(!isOcFile(infile)){
        cerr << "InputFileError: file '" << infile << "' is not an oc program.\n";
        exit(2);
    }

}

/*check input*/
void check_input(int optIndex, int argc){
    /*Check input and suffix*/
    if (optind == argc) {
        cerr <<("Please specify a program file.\n");
        exit(1);
    } else if (optind + 1 < argc){
        cerr << ("Only one program file is allowed.\n");
        exit(1);
    }
}


/*Options*/
int scan_opt(int argc, char* argv[]){
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
    return optind;
}

/*suffix*/
bool isOcFile(string file){
    size_t found = file.find_last_of(".");
    if (found == string::npos || file.substr(found) != ".oc"){
        return false;
    }
    return true;
}

/*helper*/
// Display Usage, not require
void usage(string program){
    cout << "usage:" << program << " [-D <define>] [-yl] [-h](usage) <source file>" << endl;
    exit(0);
}


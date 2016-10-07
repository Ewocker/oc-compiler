/* main.cpp for oc compiler*/
#include <iostream>
#include <string>   // for string class
#include <vector>   // for vector class
using std::cout;    // for some reason the above namespace does not work for cout

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for string function ex.strlen()
#include <unistd.h> // for getopt

#include "stringset.h"
#include "auxlib.h"

using namespace std;    // std::string can now be called as string


const string cpp_name = "/usr/bin/cpp";
string cpp_command;


/*helper*/  void usage(string program);
/*Options*/ int scan_opt(int argc, char* argv[]);
/*check input*/ void check_input(int argc);
/*check suffix*/void check_suffix(int optIndex, char* argv[]);
/*is.oc*/  bool isOcFile(string file);
/*rewrite ext*/ string change_ext(string inFile);
/*test file accessibility*/ void test_access_file(char* file);


int main (int argc, char* argv[]){
    int optIndex = scan_opt(argc, argv);
    check_input(argc);
    check_suffix(optIndex, argv);
    
    char *inFilename = argv[optIndex];
    string outFilename = change_ext(inFilename);
    
    test_access_file(inFilename);
    
}





const string cpp_name = "/usr/bin/cpp";
string cpp_command;

// Open a pipe from the C preprocessor.
// Exit failure if can't.
// Assigns opened pipe to FILE* yyin.
void cpp_popen (const char* filename) {
    cpp_command = cpp_name + " " + filename;
    yyin = popen (cpp_command.c_str(), "r");
    if (yyin == NULL) {
        syserrprintf (cpp_command.c_str());
        exit (exec::exit_status);
    }else {
        if (yy_flex_debug) {
            fprintf (stderr, "-- popen (%s), fileno(yyin) = %d\n",
                     cpp_command.c_str(), fileno (yyin));
        }
        lexer::newfilename (cpp_command);
    }
}


/* calls the C pre-processor, tokenizes the output,
 * and adds it to the stringset. */
static void cpplines (FILE* pipe, char* filename)
{
    int linenr = 1;
    char inputname[LINESIZE];
    strcpy (inputname, filename);
    for (;;) {
        /* get the line */
        char buffer[LINESIZE];
        char* fgets_rc = fgets (buffer, LINESIZE, pipe);
        if (fgets_rc == NULL) break;
        /* remove the end whitespace */
        chomp (buffer, '\n');
        /* check for pre-processor directives */
        int sscanf_rc = sscanf (buffer, "# %d \"%[^\"]\"",
                                &linenr, filename);
        if (sscanf_rc == 2) {
            continue;
        }
        /* tokenize the line */
        char* savepos = NULL;
        char* bufptr = buffer;
        for (int tokenct = 1;; ++tokenct) {
            char* token = strtok_r (bufptr, " \t\n", &savepos);
            bufptr = NULL;
            if (token == NULL) break;
            /* add to stringset */
            intern_stringset(token);
        }
        ++linenr;
    }
}

/*test file accessibility*/
void test_access_file(char* file){
    FILE* tmp = fopen(file, "r");
    if (!tmp){
        fprintf(stderr, "File not found.\n");
        exit(1);
    }
    fclose(tmp);
}

/*rewrite ext*/
string change_ext(string inFile){
    size_t found = inFile.find_last_of(".");
    return inFile.substr(0,found) + ".str";
}

/*check suffix*/
void check_suffix(int optIndex, char* argv[]){
    string inFile = argv[optIndex];
    if(!isOcFile(inFile)){
        cerr << "InputFileError: file '" << inFile << "' is not an oc program.\n";
        exit(2);
    }
}

/*is .oc*/
bool isOcFile(string file){
    size_t found = file.find_last_of(".");
    if (found == string::npos || file.substr(found) != ".oc"){
        return false;
    }
    return true;
}

/*check input*/
void check_input(int argc){
    /*Check input and suffix*/
    if (optind == argc) {
//        errprintf("Please specify a program file.\n");
        cerr << ("Please specify a program file.\n");
        exit(1);
    } else if (optind + 1 < argc){
//        errprintf("Only one program file is allowed.\n");
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

/*helper*/
// Display Usage, not require
void usage(string program){
    cout << "usage:" << program << " [-D <define>] [-yl] [-h](usage) <source file>" << endl;
    exit(0);
}


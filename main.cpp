/* main.cpp for oc compiler*/
#include <iostream>
#include <string>   // for string class
#include <vector>   // for vector class

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // for string function ex.strlen()
#include <unistd.h> // for getopt

#include "string_set.h"
#include "auxlib.h"
#include "astree.h"
#include "lyutils.h"

using namespace std;    // std::string can now be called as string

#define LINESIZE 1024
const string cpp_name = "/usr/bin/cpp";
string cpp_command;
extern FILE* yyin;     //yyin is the pipe of inFile
extern int yy_flex_debug;
extern int yydebug;
FILE* tokFile;


/*helper*/  void usage(string program);
/*Options*/ int scan_opt(int argc, char* argv[]);
/*check input*/ void check_input(int argc);
/*check suffix*/void check_suffix(int optIndex, char* argv[]);
/*is.oc*/  bool isOcFile(string file);
/*rewrite ext*/ string change_ext(string inFile, string ext);
/*test file accessibility*/ void test_access_file(char* file);
/*dump to file*/void dump_file(string outFilename);
/*generate astree*/void gen_astree (string astFilename);

/*from strtok.cpp*/ void cpp_popen (const char* filename);
/*from strtok.cpp*/ static void cpplines (FILE* pipe, char* filename);
/*from strtok.cpp*/ void cpp_pclose();
/*from strtok.cpp*/ void chomp (char* string, char delim);
/*dump to .tok*/ void scan (string tokFilename);
//----------------------------------------------------

int main (int argc, char* argv[]){
    //init
    set_execname(argv[0]);
    //==================
    yy_flex_debug = 0;
    int optIndex = scan_opt(argc, argv);
    check_input(argc);
    check_suffix(optIndex, argv);

//    output filename
    char *inFilename = argv[optIndex];
    test_access_file(inFilename);
    string strFilename = change_ext(inFilename, ".str");
    string tokFilename = change_ext(inFilename, ".tok");
    string astFilename = change_ext(inFilename, ".ast");
    
    
    cpp_popen(inFilename);

//    asg2
    scan(tokFilename);  

//    asg1
    cpplines(yyin, inFilename);
    dump_file(strFilename);
    
//    asg3
    yyparse();
    gen_astree(astFilename);


    cpp_pclose();
    yylex_destroy();
    
    return EXIT_SUCCESS;
}




//---------------------------------------------


/*generate astree & dump to .ast*/
void gen_astree (string astFilename) {
    FILE* astfile = fopen (astFilename.c_str(), "w");
    // example 8 out
        astree::print (astfile, parser::root);
        // emit_sm_code (parser::root);
        delete parser::root;
    // my out
    if (astfile == NULL) {
        cerr << "Error opening file";
        exit (EXIT_FAILURE);
    }
    // printf('\n From now on is my output');
    // astree::dump(astfile, parser::root);
    fclose (astfile);
}

/*dump to .tok*/
void scan (string tokFilename) {
    tokFile = fopen(tokFilename.c_str(), "w");
    if (tokFile == NULL) {
        cerr << "Error opening file";
        exit (EXIT_FAILURE);
    } else {
        // for (;;) {
            // int token = yylex();
            // 
            // if (yy_flex_debug) fflush (NULL);
            // if (token == YYEOF) break;
            
            // DEBUGF('m', "token=%d", token);
        // }
    }
    fclose(tokFile);
}

/*dump to file*/
void dump_file(string strFilename){
    FILE* strfile = fopen(strFilename.c_str(), "w");
    if (!strfile){
        fprintf(stderr, "Cannot open file.\n");
        exit(1);
    }
    string_set::dump(strfile);
    fclose(strfile);
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
string change_ext(string inFile, string ext){
    size_t found = inFile.find_last_of(".");
    return inFile.substr(0,found) + ext;
}

/*check suffix*/
void check_suffix(int optIndex, char* argv[]){
    string inFile = argv[optIndex];
    if(!isOcFile(inFile)){
        string err = "InputFileError: file ";
        err += inFile;
        err += " is not an oc program.";
        cerr << err << endl;
        exit(1);
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
        cerr << ("Please specify a program file.\n");
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
                yy_flex_debug = 1;
                break;
            case 'y':
                //    cout << "y" << endl;    //test
                yydebug = 1;
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
    string err = "usage: ";
    err += program;
    err += " [-D <define>] [-yl] [-h](usage) <source file>";
    exit(1);
}



/********************************************/
/*            from strtok.cpp               */
/********************************************/



// Open a pipe from the C preprocessor.
// Exit failure if can't.
// Assigns opened pipe to FILE* yyin.
void cpp_popen (const char* filename) {
    cpp_command = cpp_name + " " + filename;
    yyin = popen (cpp_command.c_str(), "r");
    if (yyin == NULL) {
        fprintf(stderr, "Fail to open pipe.");
        exit (1);
    } else {
        if (yy_flex_debug) {
            fprintf(stderr, "-- popen (%s), fileno(yyin) = %d\n",
                    cpp_command.c_str(), fileno(yyin));
        }
        lexer::newfilename (cpp_command.c_str());
    }
}

void cpp_pclose() {
    int pclose_rc = pclose (yyin);
//    eprint_status (cpp_command.c_str(), pclose_rc);
    if (pclose_rc != 0){
        exit(1);
    }
}


/* calls the C pre-processor, tokenizes the output,
 * and adds it to the stringset. */
static void cpplines (FILE* pipe, char* filename){
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
            string_set::intern(strdup(token));
        }
        ++linenr;
    }
}

// Chomp the last character from a buffer if it is delim.
void chomp (char* string, char delim) {
    size_t len = strlen (string);
    if (len == 0) return;
    char* nlpos = string + len - 1;
    if (*nlpos == delim) *nlpos = '\0';
}














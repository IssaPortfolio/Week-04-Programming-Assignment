/*////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/                                                                                                                                                /
/   Create a program that counts the number of vowels in a file.                                                                                 /
/                                                                                                                                                /
/   Requirements:                                                                                                                                /
/                                                                                                                                                /
/       User must specify the name of the file(from the command line) to analyze when the program is run.If not, an error should be generated.   /
/       Use constants where appropriate.                                                                                                         /
/       Use I / O(stream) manipulators to format the output so that it is identical to the example below                                         /
/       Pass the name of the file to read in from the command line.                                                                              /
/                                                                                                                                                /
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// BY ISSA HABEEB */


#include <iostream>     // GIVES "cin" AND "cout"
#include <iomanip>      // GIVES "setfill(char)", "setw(int)" AND "setprecision(int)"
#include <string>       // GIVES DATA TYPE "string"
#include <fstream>      // INPUTS/OUTPUTS TO A FILE
using namespace std;    // SO NO NEED TO DO "std::cout" OR "std::cin"


//  Main function recieving arguments from command prompt. 
int main(int argc, char *argv[])  // argc is number of arguments and argv is the "string" of the arguments or a list of char data type
{

    //  Settings defaults for console outputs
    cout << setfill('*') << fixed;

    //  Introduction
    cout << setw(61) << "\n"
         << setw(48) <<" Welcome to my Letter Count Program " << right << setw(13) << "\n"
         << setw(61) << "\n" << endl;

    //  Checking if file argument is given
    if (argc < 2)
    {
        cout << "File argument not given" << "\n" << endl;
        system("pause");
        return 1;  // Returns a value (1 will be used to indicate no file given) 
    }

    const string INPUTFILENAME = argv[1];  // argv[0] is the exe and argv[1] is the file input (txt file)

    //  Opening file
    cout << setfill('.');
    cout << "Analyzing file " << "'" << INPUTFILENAME << "'..." << "\n" << endl;
    ifstream InputStream;  // Variable InputStream will be used to read input from a file stream
    InputStream.open(INPUTFILENAME);  // Variable InputStream will open file INPUTFILESTREAM

    //  Checking if file is open
    if (!InputStream)
    {
        cout << "File " << "'" << argv[1] << "'" << " not found" << "\n" << endl;
        system("pause");
        return 2;  // Returns a value (2 will be used to indicate file not open error) 
    }

    // Initializing variables with initial value 0
    int a_count = 0, e_count = 0, i_count = 0, o_count = 0, u_count = 0, z_count = 0, y_count = 0; 

    char extractCharacter;  // Initializing char variable

    // Loop that reads from file as long as end of file is not reached 
    while (!InputStream.eof() && InputStream >> extractCharacter) 
    {
        //  Adds 1 to each variable if conditional is true
        if (extractCharacter == 'A' || extractCharacter == 'a')
            a_count += 1;
        else if (extractCharacter == 'E' || extractCharacter == 'e')
            e_count += 1;
        else if (extractCharacter == 'I' || extractCharacter == 'i')
            i_count += 1;
        else if (extractCharacter == 'O' || extractCharacter == 'o')
            o_count += 1;
        else if (extractCharacter == 'U' || extractCharacter == 'u')
            u_count += 1;
        else if (extractCharacter == 'Z' || extractCharacter == 'z')
            z_count += 1;
        else if (extractCharacter == 'Y' || extractCharacter == 'y')
            y_count += 1;
    }

    //  String sentences that do not change
    const string NUM_OF_SENTENCE = "The number of ";
    const string VOWEL_TOTAL_SENTENCE = "The vowel count is: ";

    //  Outputs to console sentences and amount of vowels for each letter. 
    cout << left << setw(61)  << NUM_OF_SENTENCE + "A's" << a_count << endl;
    cout << right << setw(61) << left << NUM_OF_SENTENCE + "E's: " << e_count << endl;
    cout << right << setw(61) << left << NUM_OF_SENTENCE + "I's: " << i_count << endl;
    cout << right << setw(61) << left << NUM_OF_SENTENCE + "O's: " << o_count << endl;
    cout << right << setw(61) << left << NUM_OF_SENTENCE + "U's: " << u_count << endl;
    cout << right << setw(61) << left << NUM_OF_SENTENCE + "Z's: " << z_count << endl;
    cout << right << setw(61) << left << NUM_OF_SENTENCE + "Y's: " << y_count << endl;
    //  Total of all vowels
    const int VOWEL_TOTAL = a_count + e_count + i_count + o_count + u_count + z_count + y_count;
    cout << right << setw(61) << left << VOWEL_TOTAL_SENTENCE << VOWEL_TOTAL << endl;

    //  Closes the input stream file
    InputStream.close();

    //  Pauses command line rather than closing
    system("pause");

    //  Returns int 0 to the function main
    return 0;
}

/*
 
    For line 18, I previously had const char *INPUTFILENAME = " "; and it did work but I was unsure what it did so I changed it to a string
    I think * means a pointer, which I am unfamilar with. 

    I am not sure how I can make that file not found error popup so instead I just made it output it in the console. 

    I am assuming it's something we have not learned yet. I found this online https://stackoverflow.com/questions/34870490/i-want-to-stop-cmd-when-run-c-exe 
    when looking up how to make popups on c++ cmd programs

*/
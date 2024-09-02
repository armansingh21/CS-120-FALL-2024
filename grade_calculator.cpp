// These headers define some of the classes and functions we need
#include <iostream>
#include <string>
#include <sstream>
#include <limits>

// ONLY MAKE CHANGES WHERE THERE IS A TODO

// These using declarations let us refer to things more simply
// e.g. instead of "std::cin" we can just write "cin"
using std::cin, std::cout, std::endl;
using std::string, std::getline;

// These methods are defined below the main function

// print instructions for inputting grades
void print_instructions();

// pretty print a summary of the grades
void print_results(double exam_average,
                   double hw_average,
                   double lw_average,
                   double reading,
                   double engagement,
                   double weighted_total,
                   char final_letter_grade);

// YOU ARE NOT EXPECTED TO UNDERSTAND THIS ONE... YET
// extract the category and score from the line
// and store the values in the provided variables
// if line := "exam 95", then category := "exam" and score := 95
// if the line is invalid, then category := "ignore"
void get_category_and_score(const string& line,
                            string* category,
                            double* score);

int main() {
    print_instructions();

    // ONLY MAKE CHANGES WHERE THERE IS A TODO

    // TODO(student): declare and initialize variables that you want

    double exam = 0.0;
    double fexam = 0.0;
    double hw = 0.0;
    double lw = 0.0;
    double zybook = 0.0;
    double engage = 0.0;

    double numexam = 0.0;
    double numhw = 0.0;
    double numlw = 0.0;
    double numzybook = 0.0;
    double numengage = 0.0;
    


    string line;
    // read one line from standard input (discards the ending newline character)
    getline(cin, line);
    // read lines until an empty line is read
    while (!line.empty()) {
        string category;
        double score;
        get_category_and_score(line, &category, &score);

        // process the grade entry
        if (category == "exam") {
            // TODO(student): process exam score
            exam += score;
            numexam++;
        } else if (category == "final-exam") {
            // TODO(student): process final score
            fexam = score;

        } else if (category == "hw") {
            // TODO(student): process hw score
            hw += score;
            numhw++;
        } else if (category == "lw") {
            // TODO(student): process lw score
            lw += score;
            numlw++;
        } else if (category == "reading") {
            // TODO(student): process reading score
            zybook += score;
            numzybook++;
        } else if (category == "engagement") {
            // TODO(student): process engagement score
            engage += score;
            numengage++;
        }else {
            cout << "ignored invalid input" << endl;
        }

        // get the next line from standard input
        getline(cin, line);
    }

    // TODO(student): compute component averages
    double exam_average = (exam + fexam) / (numexam + 1);
    if(fexam > exam_average){
        exam_average = fexam;
    }
    double hw_average = (numhw > 0) ? hw / numhw : 0;
    double lw_average = (numlw > 0) ? (lw / numlw) * 100 : 0;
    double reading = (numzybook > 0) ? zybook / numzybook : 0;
    double engagement = (numengage > 0) ? engage / numengage : 0;

    if(engagement != 0){
        if (engagement + 15 <= 100) {
            engagement += 15;
        }
        else {
            engagement = 100;
        }
    }

    if(reading != 0){
        if (reading + 15 <= 100) {
            reading += 15;
        }
        else {
            reading = 100;
        }
    }

    // TODO(student): compute weighted total of components
    double weighted_total = (exam_average * 0.4) + (hw_average * 0.4) + (lw_average * 0.1) + (reading * 0.05) + (engagement * 0.05) ;

    // TODO(student): compute final letter grade
    char final_letter_grade = 'X';
    if( weighted_total <= 100 && weighted_total >= 90){
         final_letter_grade = 'A';
    }
    if( weighted_total < 90 && weighted_total >= 80){
         final_letter_grade = 'B';
    }
    if( weighted_total < 80 && weighted_total >= 70){
         final_letter_grade = 'C';
    }
    if( weighted_total < 70 && weighted_total >= 60){
         final_letter_grade = 'D';
    }
    else if(weighted_total < 60){
         final_letter_grade = 'F';
    }


    print_results(
        exam_average, hw_average, lw_average, reading, engagement,
        weighted_total, final_letter_grade);
}

// These methods are already implemented for you
// You should not need to modify them

void print_instructions() {
    cout << "enter grades as <category> <score>" << endl;
    cout << "  <category> := exam | final-exam | hw | lw | reading | engagement" << endl;
    cout << "     <score> := numeric value" << endl;
    cout << "enter an empty line to end input" << endl;
}

void get_category_and_score(
    const string& line,
    string* category,
    double* score) {
    // turn the string into an input stream
    std::istringstream sin(line);

    // read the category (as string) and score (as double) from the stream
    sin >> *category;
    sin >> *score;

    if (sin.fail()) {
        // the stream is in a fail state (something went wrong)
        // clear the flags
        sin.clear();
        // clear the stream buffer (throw away whatever garbage is in there)
        sin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // signal that the line was invalid
        *category = "ignore";
    }
}

void print_results(
    double exam_average,
    double hw_average,
    double lw_average,
    double reading,
    double engagement,
    double weighted_total,
    char final_letter_grade) {
    cout << "summary:" << endl;
    cout << "      exam average: " << exam_average << endl;
    cout << "        hw average: " << hw_average << endl;
    cout << "        lw average: " << lw_average << endl;
    cout << "           reading: " << reading << endl;
    cout << "        engagement: " << engagement << endl;
    cout << "    ---------------" << endl;

    cout << "    weighted total: " << weighted_total << endl;

    cout << "final letter grade: " << final_letter_grade << endl;
}

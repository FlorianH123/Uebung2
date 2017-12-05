#include <iostream>

using namespace std;

int countWords(const char *string) {
    int count = 0;

    do {
        if (*string != ' ' && *string != '\t' && *string != '\n' && *string != '\0') {
            count++;

            while (*string != ' ' && *string != '\t' && *string != '\n' && *string != '\0') {
                string++;
            }
        }
    } while (*string++);

    return count;
}

int strcmp_ign_wsp(const char *s1, const char *s2) {
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 == *s2) {
            s1++;
            s2++;
        } else if (*s1 == ' ' || *s1 == '\n' || *s1 == '\t') {
            s1++;
        } else if (*s2 == ' ' || *s2 == '\n' || *s2 == '\t') {
            s2++;
        } else {
            if (*s1 > *s2) {
                return 1;
            } else if (*s1 < *s2) {
                return -1;
            }
        }
    }

    // Weiterer Vergleich, wenn ein String Pointer auf '\0' zeigt
    if (*s1 == '\0') {
        while (*s2 != '\0') {
            if (*s2 != ' ' && *s2 != '\n' && *s2 != '\t') {
                return -1;
            }

            s2++;
        }
    } else {
        while (*s1 != '\0') {
            if (*s1 != ' ' && *s1 != '\n' && *s1 != '\t') {
                return 1;
            }

            s1++;
        }
    }

    return 0;
}

template <class Iterator>
void insertionSort(Iterator first, Iterator last) {
    int key, j;

    for (; first != last ; first++) {
        printf(first);
    }
}

void printTestsPartA() {
    cout << "<-- Tests fuer Teilaufgabe A -->" << endl;

    // Tests auf Blank
    cout << "Tests auf Blank\n" << endl;

    cout << R"("Hallo" expected 1)";
    cout << " actual " << countWords("Hallo") << "\n" <<endl;

    cout << R"(" Hallo" expected 1)";
    cout << " actual " << countWords(" Hallo") << "\n" << endl;

    cout << R"(" Hallo " expected 1)";
    cout << " actual " << countWords(" Hallo ") << "\n" << endl;

    cout << R"("Hallo Du" expected 2)";
    cout << " actual " << countWords("Hallo Du") << "\n" << endl;

    cout << R"("Hallo  Du" expected 2)";
    cout << " actual " << countWords("Hallo  Du") << "\n" << endl;

    cout << R"("  Hallo  Du  " expected 2)";
    cout << " actual " << countWords("  Hallo  Du  ") << "\n" << endl;

    //Tests auf Tabulator
    cout << R"("\tHallo" expected 1)";
    cout << " actual " << countWords("\tHallo") << "\n" << endl;

    cout << R"("\tHalloDu\t" expected 1)";
    cout << " actual " << countWords("\tHallo\t") << "\n" << endl;

    cout << R"("\tHallo\tDu\t" expected 2)";
    cout << " actual " << countWords("\tHallo\tDu\t") << "\n" << endl;
}

void printTestsPartB() {
    cout << "<-- Tests fuer Teilaufgabe B -->" << endl;

    //--- Tests auf Gleichheit ---
    cout << "Tests auf Gleichheit" << "\n" << endl;

    cout << R"(" aaa ", "aaa" expected 0)";
    cout << " actual " << strcmp_ign_wsp(" aaa ", "aaa") << "\n" << endl;

    cout << R"(" aaa ", " aaa " expected 0)";
    cout << " actual " << strcmp_ign_wsp(" aaa ", " aaa ") << "\n" << endl;

    cout << R"("aaa", "aaa " expected 0)";
    cout << " actual " << strcmp_ign_wsp("aaa", "aaa ") << "\n" << endl;

    cout << R"(" a a a ", "a a a" expected 0)";
    cout << " actual " << strcmp_ign_wsp(" a a a ", "a a a") << "\n" << endl;

    cout << R"("aaa", "aaa" expected 0)";
    cout << " actual " << strcmp_ign_wsp("aaa", "aaa") << "\n" << endl;

    cout << R"("a b c", "abc" expected 0)";
    cout << " actual " << strcmp_ign_wsp("a b c", "abc") << "\n" << endl;

    cout << R"("a\nb\nc", "abc" expected 0)";
    cout << " actual " << strcmp_ign_wsp("a\nb\nc", "abc") << "\n" << endl;

    cout << R"("a\tb\tc", "abc" expected 0)";
    cout << " actual " << strcmp_ign_wsp("a\tb\tc", "abc") << "\n" << endl;

    cout << R"("a\n b\ nc", "abc" expected 0)";
    cout << " actual " << strcmp_ign_wsp("a\n b\n c", "abc") << "\n" << endl;

    cout << R"("a\n\tb\n\tc", "abc" expected 0)";
    cout << " actual " << strcmp_ign_wsp("a\n\tb\n\tc", "abc") << "\n" << endl;

    // Tests auf String1 > String2
    cout << "Test auf String 1 lexikalisch groesser als String 2" << "\n" << endl;

    cout << R"("aba", "aaa" expected 1)";
    cout << " actual " << strcmp_ign_wsp("aba", "aaa") << "\n" << endl;

    cout << R"("   aaab", "aaa" expected 1)";
    cout << " actual " << strcmp_ign_wsp("   aaab", "aaa") << "\n" << endl;

    cout << R"(" a b c ", " a a a " expected 1)";
    cout << " actual " << strcmp_ign_wsp(" a b c ", " a a a ") << "\n" << endl;

    // Tests auf String1 < String2
    cout << "Test auf String 1 lexikalisch groesser als String 2" << "\n" << endl;

    cout << R"("aaa", "aa ab" expected -1)";
    cout << " actual " << strcmp_ign_wsp("aaa", "aa ab") << "\n" << endl;

    cout << R"(" a a a ", " aa ab " expected -1)";
    cout << " actual " << strcmp_ign_wsp(" a a a ", " aa ab ") << "\n" << endl;

    cout << R"("aaa", "ab" expected -1)";
    cout << " actual " << strcmp_ign_wsp("aaa", "ab") << "\n" << endl;

    cout << R"("aa", "ab " expected -1)";
    cout << " actual " << strcmp_ign_wsp("aa", "ab ") << "\n" << endl;

    cout << R"("aaa ", "ab" expected -1)";
    cout << " actual " << strcmp_ign_wsp("aaa ", "ab") << "\n" << endl;
}

int main() {
    // Tests für Aufgabenteil A
    printTestsPartA();

    // Tests für Aufgabenteil B
    printTestsPartB();

    //int array[] = {1,2,3,4,5};
   // insertionSort(*array, *array+5);
    return 0;
}
#include <iostream>
using namespace std;

void printTestsPartA();
void printTestsPartB();
void printTestsPartC();
template <typename T>
void insertionSort(T first, T last);
template <typename T>
void printArray(T, int);

/**
 * Methode um die Anzahl an Woertern in einem char String zu zaehlen
 * @param string char String
 * @return Anzahl an Woertern
 */
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

/**
 * Vergleicht lexikalisch zwei String ohne Lerrzeichen zu beachten
 * @param s1 String1
 * @param s2 String2
 * @return -1 String1 < String2, 0 String1 = String2, 1 String1 > String2
 */
int strcmp_ign_wsp(const char *s1, const char *s2) {
    if (*s1 == '\0' && *s2 != '\0' && *s2 != ' ') {
        return -1;
    } else if (*s1 != '\0' && *s2 == '\0' && *s1 != ' ') {
        return 1;
    } else if (*s1 != '\0' && *s2 != '\0') {
        if (*s1 == ' ' || *s1 == '\t' || *s1 == '\n') {
            return strcmp_ign_wsp(++s1, s2);
        }

        if (*s2 == ' ' || *s2 == '\t' || *s2 == '\n') {
            return strcmp_ign_wsp(s1, ++s2);
        }

        if (*s1 > *s2) {
            return 1;
        }

        if (*s1 < *s2) {
            return -1;
        } else {
            return strcmp_ign_wsp(++s1, ++s2);
        }
    }
    return 0;
}

/**
 * Sortieren von beliebigen gleichen Typen mit insertion sort
 * @tparam T
 * @param first linke Schranke des Arrays
 * @param last  rechte Schranke des Arrays
 */
template<typename T>
void insertionSort(T first, T const last) {
    auto valueToSort = *first;
    T j;
    T firstValue = first;

    if (first == last) {
        return;
    }

    for (firstValue += 1; firstValue <= last; firstValue++) {
        valueToSort = *firstValue;
        j = firstValue;
        while (j > first && *(j - 1) > valueToSort) {
            *j = *(j - 1);
            j--;
        }
        *j = valueToSort;
    }
}

template <typename T>
void printArray(T array, int n) {
    for(int i = 0; i <= n; i++) {
        cout << array[i] << ", ";
    }

    cout << endl;
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

void printTestsPartC() {
    int array1[]= {2,1,6,4,2,-1,0,222};
    char array2[] = {'f', 'a', 'x', 'b', 'g'};

    cout << "<-- Tests fuer Teilaufgabe C -->" << endl;

    cout << "2, 1, 6, 4, 2,-1 , 0, 222" << endl;
    insertionSort(array1, &array1[7]);
    printArray(array1, 7);

    cout << "f, a, x, b, g" << endl;
    insertionSort(array2, &array2[4]);
    printArray(array2, 4);
}


int main() {
    // Tests für Aufgabenteil A
    printTestsPartA();

    // Tests für Aufgabenteil B
    printTestsPartB();

    // Tests für Aufgabenteil C
    printTestsPartC();

    return 0;
}
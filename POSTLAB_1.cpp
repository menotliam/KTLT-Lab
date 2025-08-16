------------------------------------------------------------CLASS_STRING--------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;
string longestSymmetricalSubstring(const string& s) {
    int n = s.length();
    int maxLen = 0;
    int start = 0;

    for (int i = 0; i < n; ++i) {
        // Odd length palindrome
        int l = i, r = i;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                maxLen = r - l + 1;
                start = l;
            }
            l--;
            r++;
        }

        // Even length palindrome
        l = i;
        r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                maxLen = r - l + 1;
                start = l;
            }
            l--;
            r++;
        }
    }

    return s.substr(start, maxLen);
}

int main() {
    string s;
    getline(cin, s);

    string result = longestSymmetricalSubstring(s);
    cout << result << endl;

    return 0;
}

------------------------------------------------------------------------
#include <iostream>
#include <string>

using namespace std;

int longestNonRepeatSubString(string s) {
    int maxLen = 0;
    int start = 0;
    int pos[128]; // ASCII table

    for (int i = 0; i < 128; ++i) {
        pos[i] = -1;
    }

    for (int end = 0; end < s.length(); ++end) {
        char ch = s[end];
        if (pos[ch] >= start) {
            start = pos[ch] + 1;
        }
        pos[ch] = end;
        int len = end - start + 1;
        if (len > maxLen) {
            maxLen = len;
        }
    }

    return maxLen;
}

int main()  {
    string s;
    cin >> s;
    cout << longestNonRepeatSubString(s);
    return 0;
}

-----------------------------------------------MULTI_DIMENSIONAL-------------------------------------------------
// Function to check if a number is prime
bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i*i <= n; ++i)
        if (n % i == 0)
            return false;
    return true;
}

int specialCells(int arr[][1000], int row, int col) {
    vector<int> rowSum(row, 0);
    vector<int> colSum(col, 0);

    // Calculate row sums and column sums
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            rowSum[i] += arr[i][j];
            colSum[j] += arr[i][j];
        }
    }

    // Count HN3 cells
    int count = 0;
    for (int i = 0; i < row; ++i) {
        if (!isPrime(rowSum[i])) continue;  // skip if row sum is not prime
        for (int j = 0; j < col; ++j) {
            if (isPrime(colSum[j])) {
                ++count;
            }
        }
    }

    return count;
}

---------------------------------------------------------------------------
int subMatrix(int arr[][1000], int row, int col) {
    int count = 0;

    for (int i = 0; i < row - 1; ++i) {
        for (int j = 0; j < col - 1; ++j) {
            int sum = arr[i][j] + arr[i][j + 1] +
                      arr[i + 1][j] + arr[i + 1][j + 1];

            if (sum % 2 != 0) {
                ++count;
            }
        }
    }

    return count;
}

------------------------------------------------------FILE_I/O---------------------------------------------------------
void studentGrading(string fileName)   {
    ifstream fin(fileName);

    if (!fin) {
        cout << "Error: Cannot open file " << fileName << endl;
        return;
    }

    int N;
    fin >> N;

    int gradeA = 0, gradeB = 0, gradeC = 0, gradeD = 0;

    for (int i = 0; i < N; ++i) {
        double nmdt, ktlt, dsa, ppl;
        fin >> nmdt >> ktlt >> dsa >> ppl;

        double gpa = (nmdt + ktlt + dsa + ppl) / 4.0;

        bool allSubjectsAbove5 = (nmdt >= 5) && (ktlt >= 5) && (dsa >= 5) && (ppl >= 5);

        if (gpa >= 8 && allSubjectsAbove5) {
            ++gradeA;
        } else if (gpa >= 6.5 && allSubjectsAbove5) {
            ++gradeB;
        } else if (gpa >= 5 && allSubjectsAbove5) {
            ++gradeC;
        } else {
            ++gradeD;
        }
    }

    fin.close();

    cout << "A " << gradeA << endl;
    cout << "B " << gradeB << endl;
    cout << "C " << gradeC << endl;
    cout << "D " << gradeD << endl;
}

-------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

void calMoney(string priceFile, string buyFile) {
    const int MAX_ID = 1000;
    int prices[MAX_ID] = {0};

    // Read price file
    ifstream finPrice(priceFile);
    if (!finPrice) {
        cout << "Cannot open " << priceFile << endl;
        return;
    }

    int n;
    finPrice >> n;
    for (int i = 0; i < n; ++i) {
        int id, price;
        finPrice >> id >> price;
        prices[id] = price;
    }
    finPrice.close();

    // Read buy file
    ifstream finBuy(buyFile);
    if (!finBuy) {
        cout << "Cannot open " << buyFile << endl;
        return;
    }

    int m;
    finBuy >> m;
    string dummy;
    getline(finBuy, dummy); // consume the rest of the line after the number

    for (int i = 0; i < m; ++i) {
        string line;
        getline(finBuy, line);
        if (line.empty()) continue;

        stringstream ss(line);
        string name;
        ss >> name;

        int total = 0;
        int id, quantity;
        while (ss >> id >> quantity) {
            total += prices[id] * quantity;
        }

        cout << name << " " << total << endl;
    }

    finBuy.close();
}

----------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <set>
using namespace std;

void manage(string libraryFile, string bookFile, string authorFile) {
    map<string, set<int>> libraryBooks;
    map<string, set<int>> authorBooks;

    // Read library.txt
    ifstream finLibrary(libraryFile);
    if (!finLibrary) {
        cout << "Cannot open " << libraryFile << endl;
        return;
    }

    int n;
    finLibrary >> n;
    string libName;
    for (int i = 0; i < n; ++i) {
        finLibrary >> libName;
        for (int j = 0; j < 5; ++j) {
            int bookID;
            finLibrary >> bookID;
            libraryBooks[libName].insert(bookID);
        }
    }
    finLibrary.close();

    // book.txt is not needed for this task

    // Read author.txt
    ifstream finAuthor(authorFile);
    if (!finAuthor) {
        cout << "Cannot open " << authorFile << endl;
        return;
    }

    int p;
    finAuthor >> p;
    string line;
    getline(finAuthor, line); // consume remaining newline
    for (int i = 0; i < p; ++i) {
        getline(finAuthor, line);
        stringstream ss(line);
        string authorName;
        ss >> authorName;
        int id;
        while (ss >> id) {
            authorBooks[authorName].insert(id);
        }
    }
    finAuthor.close();

    // Get user input
    string L, A;
    //cout << "Enter library name: ";
    cin >> L;
    //cout << "Enter author name: ";
    cin >> A;

    // Check if any book in common
    if (libraryBooks.count(L) == 0 || authorBooks.count(A) == 0) {
        cout << "False" << endl;
        return;
    }

    for (int book : libraryBooks[L]) {
        if (authorBooks[A].count(book)) {
            cout << "True" << endl;
            return;
        }
    }

    cout << "False" << endl;
}

----------------------------------------------------------------------------------------

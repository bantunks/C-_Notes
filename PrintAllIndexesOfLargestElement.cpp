/* Given an array of integers, print the indices of the largest element of the array in random order */

#include <iostream>
#include <vector>
#include <unistd.h>  // to link usleep()

using namespace std;

int main()
{
        vector<int> v1 = { 3, 4, 5, 8, 9, 2, 8, 8, 9, 9, 9, 3, 2, 4, 4, 9, 9, 4, 8, 8, 7, 2, 7, 9, 9};
        vector<int> outVec;
        unsigned int i = 0;
        int curLargest = v1[0];
        while (i < v1.size()) {
                if (v1[i] == curLargest) {
                        outVec.push_back(i);
                } else if (v1[i] > curLargest) {
                        curLargest = v1[i];
                        outVec.erase(outVec.begin(), outVec.end());
                        outVec.push_back(i);
                }
                ++i;
        }
        i = 0;
        cout << "Printing array of indices of largest element in original order" << endl;
        while (i < outVec.size()) {
                cout << outVec[i] << "\t";
                ++i;
        }
        cout << endl << endl;
        i = 0;
        srand(time(NULL));
        int random = 0;
        cout << "Printing array of indices of largest element in random order" << endl;
        while (1) {
                while (i < (outVec.size()-1)) {
                        random = rand() % (outVec.size()-i-1);
                        cout << outVec[random] << "\t";
                        int temp = outVec[random];
                        outVec[random] = outVec[outVec.size()-i-1];
                        outVec[outVec.size()-i-1] = temp;
                        ++i;
                }
                cout << outVec[0] << endl;
                usleep(2000000); // sleep in microseconds
                i = 0;
        }

        return 0;
}

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int maxTreasureValue(int N, int SGold, int VGold, int SSilver, int VSilver) {

    int maxValue = 0;
    int totalValue;

    //80 1 3 2 1
    // 80 size of treasure box
    // 1 size of gold 3 value of gold
    // 2 size of silver 1 value of silver


    for (int countGold = 0; countGold <= N / SGold; countGold++)
    {
        for (int coundSilver = 0; coundSilver <= N / SSilver; coundSilver++)
        {
            if (countGold * SGold + coundSilver * SSilver <= N) { //if we can fit in box

                totalValue = countGold * VGold + coundSilver * VSilver;
                //cout << totalValue << endl;
                maxValue = max(maxValue, totalValue);
            }
        }
    }

    return maxValue;
}


int main(int argc, char *argv[]) {

    //cout << "Lovci na zaklade!" << endl;

    const char* vhodna_datoteka = argv[1];

     ifstream inputFile(vhodna_datoteka);
    //ifstream inputFile("testni_primer.txt");
    //ifstream inputFile("primer.txt");
    ofstream outputFile("output.txt");

    if (!inputFile) {
        cerr << "Napaka pri odpiranju vhodne datoteke." << endl;
        return 1;
    }

    int N, SGold, VGold, SSilver, VSilver; //N size of box, S size, V value
    int maximumValue; //max value of treasure

    while (inputFile >> N >> SGold >> VGold >> SSilver >> VSilver)
    {
        maximumValue = maxTreasureValue(N, SGold, VGold, SSilver, VSilver);
        outputFile << maximumValue << endl;
        cout << maximumValue << endl;
    }


    inputFile.close(); //Close file

    return 0;
}

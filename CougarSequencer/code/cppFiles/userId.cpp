#pragma once
#include <iostream>
#include <string>

using namespace std;

class project {
    private:
        string name = "song";
};

class grid {
    private:
    string instruName;
    int bpm = 60;
    public:
        const piano = new instrument(60, "Piano")

};

class instrument {
    protected:
        string instruName;
        int row = 0;
        int col = 0;
    public:
        instrument(int b, string i) {
            bpm = b;
            instruName = i;
        }

        void setBpm(int b) {
            bpm = b;
        }

        int getBpm() {
            return bpm;
        }    
};

// class piano: public instrument {
//     private:
//         bool activated = false;
//         instruName = "Piano";

// };

// class drums: public instrument {
//     private:
//         bool activated = false;
//     public:
//         drums() {
//             instruName = "Drums";
//         }
// };

// class bass: public instrument {
//     private:
//         bool activated = false;
//     public:
//         bass() {
//             instruName = "Bass";
//         }
// };
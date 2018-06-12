#include <iostream>
using namespace std;

#include "inh_class.h"

CInhClass::CInhClass() {
        cout << "CInhClass Constructor\n";
}
CInhClass::~CInhClass() {
        cout << "CInhClass Destructor\n";
}

void CInhClass::virtFunc(int *val)
{
        CBaseClass::virtFunc(val);
        *val += 100;
}

int main(int argc, char *argv[])
{
        CInhClass ic;
        int val;

        ic.virtFunc(&val);
        cout << val << "\n";
}

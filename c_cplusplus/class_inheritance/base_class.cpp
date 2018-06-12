#include <iostream>
#include "base_class.h"

using namespace std;

CBaseClass::CBaseClass()
{
        cout << "CBaseClass constructor\n";
}

CBaseClass::~CBaseClass()
{
        cout << "CBaseClass desctructor\n";
}

void CBaseClass::virtFunc(int *val)
{
        *val = 10;
}

#ifdef TEST_BASE_CLASS
int main(int argc, char *argv[])
{
        CBaseClass bc;
        int val;

        bc.virtFunc(&val);
        cout << val << "\n";

        return (0);
}
#endif

#include "base_class.h"

class CInhClass: public CBaseClass
{
public:
        CInhClass();
        virtual ~CInhClass();

        void virtFunc(int *val);
};

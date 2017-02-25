#include "atm.h"



int main()
{
    setlocale(LC_ALL, "rus");
    ATM *atm = new ATM();
    atm -> start();
    return 0;
}

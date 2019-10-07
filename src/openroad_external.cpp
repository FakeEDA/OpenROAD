#include"openroad_external.h"
#include<openroad/version.h>
#include<iostream>

using namespace std;

openroad_external::
openroad_external() 
{
}

openroad_external::
~openroad_external() 
{
}

void openroad_external::
print_version() 
{
    cout << "OpenROAD v" MY_VERSION << endl << endl;
}
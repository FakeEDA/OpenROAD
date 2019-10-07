#include<iostream>
#include<tcl.h>
#include<string.h>



using namespace std;


extern "C" {
extern int OpenROAD_Init(Tcl_Interp *interp);
}

int 
openroadTclAppInit(Tcl_Interp *interp) {
    if( OpenROAD_Init(interp) == TCL_ERROR) {
        return TCL_ERROR; 
    }
  
    string command = "";
    command = "";
    command += "puts \"RePlAce Version: 1.0.0\"";
    Tcl_Eval(interp, command.c_str());  
    return TCL_OK;
}

int main(int argc, char *argv[]) {
    Tcl_Main(1, argv, openroadTclAppInit);
}
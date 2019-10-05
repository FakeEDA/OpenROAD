#include<iostream>
#include<openroad/version.h>

using namespace std;

void print_header(){
    const char* openroadHeader = 
    "/----------------------------------------------------------------------------\\\n"
    "|                                                                            |\n"
    "|  OpenROAD -- RTL-to-GDS Open-Source Flow                                   |\n"
    "|                                                                            |\n"
    "|  Copyright (C) 2018 - 2019  The OpenROAD Project <openroad@eng.ucsd.edu>   |\n"
    "|                                                                            |\n"
    "|  Permission to use, copy, modify, and/or distribute this software for any  |\n"
    "|  purpose with or without fee is hereby granted, provided that the above    |\n"
    "|  copyright notice and this permission notice appear in all copies.         |\n"
    "|                                                                            |\n"
    "|  THE SOFTWARE IS PROVIDED \"AS IS\" AND THE AUTHOR DISCLAIMS ALL WARRANTIES  |\n"
    "|  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF          |\n"
    "|  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR   |\n"
    "|  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES    |\n"
    "|  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN     |\n"
    "|  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF   |\n"
    "|  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.            |\n"
    "|                                                                            |\n"
    "\\----------------------------------------------------------------------------/\n"
    "\n"
    "OpenROAD ";
    cout << openroadHeader << MY_VERSION << endl << endl;
}

int main(int argc, char *argv[]) {
    print_header();
}
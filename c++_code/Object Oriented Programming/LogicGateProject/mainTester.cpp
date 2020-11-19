
//A main funciton for running unit tests on the project
//Uses Catch unit test framework:
//https://github.com/philsquared/Catch/wiki/Reference


//Tell catch we have our own main function and it should NOT make a new one
#define CATCH_CONFIG_RUNNER

#include "catch.hpp"

int main (int argc, char * argv[]) {
    return Catch::Session().run( argc, argv );
}



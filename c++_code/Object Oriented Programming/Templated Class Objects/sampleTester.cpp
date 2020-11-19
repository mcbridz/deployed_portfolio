
//Bring in unit testing code
#include "catch.hpp"

//Include your .h files

TEST_CASE( "SAMPLE/test post-increment" ) {

    int x = 1;
    x++;

    //Make sure that x really equals 2
    REQUIRE( x == 2 );
}
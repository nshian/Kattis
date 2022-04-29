#include "logicfunctions.h"

// Compute xor
void exclusive(bool x, bool y, bool& ans){
    if(x!=y){
        ans = true;
    }
    else{
        ans = false;
    }
}

// Compute implication
void implies(bool x, bool y, bool& ans){
    if(x == false){
        ans = true;
    }
    else{
        if(y == true){
            ans = true;
        }
        else{
            ans = false;
        }
    }
}

// Compute equivalence
void equivalence(bool x, bool y, bool& ans){
    if(x == y){
        ans = true;
    }
    else{
        ans = false;
    }
}
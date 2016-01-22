#include <iostream>
#include "matrix.h"

int main(int argc, const char * argv[]) {
    
    // Test your implementation here.
    // Here is sample code to test your implementation.
    
    Matrix* A = rand(3, 3);
    show(A);
    
    Matrix* B = rand(3, 3);
    show(B);

    Matrix* R = add(A, B);
    show(R);
    
    R = multiply(A, B);
    show(R);
    
    R = multiply(A, 3);
    show(R);

    del(A);
    del(B);
    del(R);
    
    return 0;
}



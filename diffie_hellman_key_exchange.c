#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// func to perform modular exponentiation
// (base^exp) % mod using exponentiation by squaring
int mod_pow(int base, int exp, int mod) {
    int result = 1;
    base = base % mod; //verify that base is within mod range

    while (exp > 0) {
        // if exp is odd, multiply result by base
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1; //divide exp by 2
        base = (base * base) % mod; // square base module mod
    }

    return result;
}

int main() {

    int alice_secret; //a
    int bob_secret; //b
    int public_common_material; //p (large prime number)
    int generator; //g (where 0 < g < p)

    //alice secret a = 13
    alice_secret = 12;
    //bob secret b = 15
    bob_secret = 17;
    //uses 29 as public variable
    public_common_material = 29;
    //uses 3 as generator
    generator = 5;

    printf("alice secret: %d\n", alice_secret);
    printf("bob secret: %d\n", bob_secret);
    printf("public common material: %d\n", public_common_material);
    printf("generator: %d\n", generator);

    // A = (g^a)%p
    int alice_public = mod_pow(generator, alice_secret, public_common_material);

    // B = (g^b)%p
    int bob_public = mod_pow(generator, bob_secret, public_common_material);

    // alice and bob exchange their keys here, bob gets A, alice gets B
    printf("--------\n");
    printf("alice public: %d\n", alice_public);
    printf("bob public: %d\n", bob_public);
    printf("--------\n");

    // alice calcs (B^a)%p
    int alice_shared_secret = mod_pow(bob_public, alice_secret, public_common_material);

    // bob calcs (A^b)%p
    int bob_shared_secret = mod_pow(alice_public, bob_secret, public_common_material);

    // these should be the same
    printf("Alice Shared Secret: %d\n", alice_shared_secret);
    printf("Bob Shared Secret: %d\n", bob_shared_secret);

    return 0;
}
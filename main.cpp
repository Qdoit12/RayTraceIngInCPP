#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG 1
#if DEBUG==1
    #define LOG(x) std::cout << #x << " : " << x << std::endl;
    #define LOGT(x, l) for (int i = 0; i < l; i++) {std::cout << x[i] << std::endl;} 
#else 
    #define LOG(x) ;
    #define LOGT(x) ;
#endif

#define CINT(TABLE, LENGTH) for(int i = 0; i < LENGTH; i++) {std::cin >> TABLE[i]; }
#define CINTS(TABLE, LENGTH, STARTAT) for(int i = STARTAT; i < LENGTH+STARTAT; i++) {std::cin >> TABLE[i]; }

//CODE 

int main() {
    int n;
    std::cin >> n;
}

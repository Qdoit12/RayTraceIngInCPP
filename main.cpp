#include <iostream>

#define DEBUG 1
#if DEBUG==1
    #define LOG(x) std::cout << #x << " : " << x << std::endl;
    #define LOGT(x, l) for (int i = 0; i < l; i++) {std::cout << x[i] << std::endl;} 
#else 
    #define LOG(x) ;
    #define LOGT(x) ;
#endif

#pragma pack(push, 1)
struct BitmapHeader {
    unsigned short file_type;
    unsigned file_size;
    unsigned short reserved1;
    unsigned short reserved2;
    unsigned bitmap_offset;

    unsigned size;
    int width;
    int height;
    unsigned short planes;
    unsigned short bits_per_pixel;
    unsigned compression;
    unsigned size_of_bitmap;
    int horz_res;
    int vert_res;
    unsigned colors_used;
    unsigned colors_important;



};
#pragma pack(pop)

//TODO: Write Image
void write_image() {

}

//TODO(Q DO IT): give picture size via args
int main() {
    return 0; 
}

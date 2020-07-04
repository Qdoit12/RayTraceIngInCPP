#include <cstdio> //NOTE(Qdoit): writing image to disk
#include <cstdlib>
#include <cassert>
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
void write_image(unsigned width, unsigned height, const unsigned* pixels, const char* filename) {
    //NOTE
    BitmapHeader header = {};
    unsigned pixel_size = sizeof(unsigned) * width * height;
    header.file_type = 0x4D42;
    header.file_size = sizeof(header) + pixel_size;
    header.bitmap_offset = sizeof(header);
    header.size = sizeof(header) - 14;
    header.width = width;
    header.height = height;
    header.planes = 1;
    header.bits_per_pixel = 32;
    header.compression = 0;
    header.size_of_bitmap = pixel_size;

    FILE* outfile = fopen(filename, "wb");
    if(outfile) {
        fwrite(&header, sizeof(header), 1, outfile);
        fwrite(pixels, pixel_size, 1, outfile);
        fclose(outfile);
    } else 
    {
        printf("Error while creating file\n");
    }

}




//TODO(Q DO IT): give picture size via args
int main() {
    unsigned width = 1280, height = 720;
    unsigned pixels_size = sizeof(unsigned) * width * height;
    unsigned resolution_size = width*height;
    unsigned* pixels = (unsigned*)malloc(pixels_size);
    
    

    unsigned* curPx = pixels;

    for(unsigned y = 0; y < height; ++y) {
        for(unsigned x = 0; x < width; ++x) {
            *curPx = 0x00FF0000; //AARRGGBB
            
            ++curPx;

        }
    }
    LOG(curPx)
    LOG((pixels+pixels_size))
    LOG(sizeof(pixels))
    assert(curPx == (pixels + resolution_size));

    write_image(width, height, pixels, "test.bmp");
    free(pixels);
    return 0; 
}

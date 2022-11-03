#include <stdio.h>
#include <stdlib.h>

void rgb_to_black_and_white(char* input, char* target) {
	FILE *fp;
        fp = fopen(input,"rb");
        void *header = (void*)malloc(54);
        fseek(fp,0,SEEK_END);
        int size = ftell(fp);
        fseek(fp,0,SEEK_SET);
        fread(header,54,1,fp);
        size -= 54;
        unsigned char* image = (unsigned char*)malloc(size);
        fread(image,size,1,fp);
        fclose(fp);

        // rgb to black and white
        for(int i=0; i<size; i+=3) {
                unsigned char color = (image[i]+image[i+1]+image[i+2])/3;
                image[i] = image[i+1] = image[i+2] = color;
        }

        fp = fopen(target,"wb");
        fwrite(header,54,1,fp);
        fwrite(image,size,1,fp);
        fclose(fp);
        free(image);
        free(header);
}

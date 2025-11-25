#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char **argv)
{

    int w = 1980;
    int h = w * 9 / 16;

    FILE *f = fopen("seno.ppm", "wb");
    fprintf(f, "P6\n%d %d\n255\n", w, h);

    int unit = 10;      // 1 unità = 10 pixel
    int x0 = w / 2;
    int y0 = h / 2;

    unsigned char *img = (unsigned char*) malloc(w * h * 3);
    for(int i=0;i<w*h*3;i++) img[i]=0; // sfondo nero

    // --- Disegna griglia e assi ---
    for(int y=0;y<h;y++)
    {
        for(int x=0;x<w;x++)
        {
            unsigned char *p = &img[(y*w+x)*3];

            // griglia fine
            if (x%unit==0 || y%unit==0)
                *p = *(p+1) = *(p+2) = 15;

            // griglia principale ogni 100px
            if (x%(unit*10)==0 || y%(unit*10)==0)
                *p = *(p+1) = *(p+2) = 40;

            // assi
            if (x==x0 || y==y0)
                *p = *(p+1) = *(p+2) = 200;
        }
    }

    // --- Disegna parabola analogica ---
    float prevY = 0;
    int first = 1;
    for(int x=0;x<w;x++)
    {
        float X = (x - x0)/(float)unit;
        float PYf = y0 - sin(X)*unit;

        if(!first)
        {
            int yStart = (int)prevY;
            int yEnd = (int)PYf;
            if(yStart>yEnd) { int tmp=yStart; yStart=yEnd; yEnd=tmp; }

            for(int y=yStart;y<=yEnd;y++)
            {
                if(y>=0 && y<h)
                {
                    unsigned char *p = &img[(y*w+x)*3];
                    *p = *(p+1) = *(p+2) = 255;
                }
            }
        }
        prevY = PYf;
        first = 0;
    }
    // --- Uso fwrite per velocizzare la scrittura ---
    fwrite(img,1,w*h*3,f);
    fclose(f);
    free(img);
    return 0;
}

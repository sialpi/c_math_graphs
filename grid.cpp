    // --- Disegna griglia e assi ---
void draw_grid(int w, int h, int x0, int y0,unsigned char *img){
    for(int y=0;y<h;y++)
    {
        for(int x=0;x<w;x++)
        {
            unsigned char *p = &img[(y*w+x)*3];

            // griglia fine
            if ((x-x0)%unit==0 || (y-y0)%unit==0)
                *p = *(p+1) = *(p+2) = 15;

            // griglia principale ogni 100px
            if ((x-x0)%(unit*10)==0 || (y-y0)%(unit*10)==0)
                *p = *(p+1) = *(p+2) = 40;

            // assi
            if (x==x0 || y==y0)
                *p = *(p+1) = *(p+2) = 200;
        }
    }
}

#ifndef SCULPTOR_H
#define SCULPTOR_H
#include <string>
#include <vector>

struct Voxel {
  float r,g,b; // Cores
  float a; // Transparencia
  bool show; // Visivel ou nao
};

class Sculptor
{
    protected:
       Voxel ***v; // 3D matrix
       int nx,ny,nz; // Dimensions
       float r,g,b,a; // Current drawing color

     public:
        //pesquisar o que é uma função virtual
        Sculptor(int _nx, int _ny, int _nz); // construtor
        ~Sculptor(); // destrutor
        void setColor(float r, float g, float b, float alpha); //define a cor do desenho
        void putVoxel(int x, int y, int z); //ativa as propriedades de um voxel em uma determinada posicao
        void cutVoxel(int x, int y, int z); // desativa as propriedades de um voxel em uma determinada posicao
        void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
        void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
        void putSphere(int xcenter, int ycenter, int zcenter, int radius);
        void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
        void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
        void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
        void writeOFF(const char *filename); //grava a escultura no formato OFF no arquivo filename

};

#endif // SCULPTOR_H
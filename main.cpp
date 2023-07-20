#include "figurageometrica.h"
#include "putVoxel.h"
#include "cutVoxel.h"
#include "putBox.h"
#include "cutBox.h"
#include "putSphere.h"
#include "cutSphere.h"
#include "putEllipsoid.h"
#include "cutEllipsoid.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

int main(){
    std::vector<FiguraGeometrica*> figs;
    FiguraGeometrica *pfig;
    std::ifstream fin;
    std::string s;
    fin.open("entrada.txt");
  
    float r,g,b,a;
    int nx, ny, nz;
    int xcenter, ycenter, zcenter, raio;
    int x, y, z;
    int x0, y0, z0, x1, y1, z1;
    int rx, ry, rz;
  
    while(fin.good()){
        fin >> s;
        if(fin.good()){
          std::cout << s << "\n";
          if(s.compare("dim") == 0){
            fin >> nx >> ny >> nz;
          }
          else if(s.compare("putvoxel") == 0){
            fin >> x >> y >> z >> r >> g >> b >> a;
            figs.push_back(new PutVoxel(x, y, z, r, g, b, a));
          }
          else if(s.compare("cutvoxel") == 0){
            fin >> x >> y >> z;
            figs.push_back(new CutVoxel(x, y, z));
          }
          else if(s.compare("putbox") == 0){
            fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1 >> r >> g >> b >> a;
            figs.push_back(new PutBox(x0, x1, y0, y1, z0, z1, r, g, b, a));
          }
          else if(s.compare("cutbox") == 0){
            fin >> x0 >> x1 >> y0 >> y1 >> z0 >> z1;
            figs.push_back(new CutBox(x0, x1, y0, y1, z0, z1));
          }
          else if(s.compare("putsphere") == 0){
            fin >> xcenter >> ycenter >> zcenter >> raio >> r >> g >> b >> a;
            figs.push_back(new PutSphere(xcenter, ycenter, zcenter, raio, r, g, b, a));
          }
          else if(s.compare("cutsphere") == 0){
            fin >> xcenter >> ycenter >> zcenter >> raio;
            figs.push_back(new CutSphere(xcenter, ycenter, zcenter, raio));
          }
          else if(s.compare("putellipsoid") == 0){
            fin >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz >> r >> g >> b >> a;
            figs.push_back(new PutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz, r, g, b, a));
          }
          else if(s.compare("cutellipsoid") == 0){
            fin >> xcenter >> ycenter >> zcenter >> rx >> ry >> rz;
            figs.push_back(new CutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz));
          }
        }
  }
    Sculptor *scp ;
    std::cout << nx << std::endl;
    scp = new Sculptor(nx, ny, nz);
    
    for(int i=0; i<figs.size(); i++){
      std::cout<<"draw\n";
      figs[i]->draw(*scp);
    }
    
    scp->writeOFF("saida.off");

    for(int i=0; i<figs.size(); i++){
      delete figs[i];
    }

    delete scp;
  
  return 0;
}



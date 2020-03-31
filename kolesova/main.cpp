#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

const int N=10;

int main(int ac, char *av[]){
    char *file,*file1;
    if (ac > 1) {
        file = av[1];
        file1 =av[2];
    }
    else {
        cout«"Не заданы имена файлов\n";
        return 1;
    }
    ifstream f(file);
    int mass[N], max, min,kmax=0,kmin=0;

    for (int i=0;i<N;i++){
        f»mass[i];
    }

    max=mass[0];
    min=mass[0];
    for(int r=1; r<N; r++) {
        if(max<mass[r]) {
            max=mass[r];
            kmax=r;
        }
        if(min>mass[r]){
            min=mass[r];
            kmin=r;
        }
    }
    f.close();
    ofstream f1(file1);
    mass[kmax]=min;
    mass[kmin]=max;
    for (int i=0;i<N;i++){f1«mass[i]«" ";}
}

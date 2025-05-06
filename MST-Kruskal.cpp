#include <iostream>
using namespace std;

int M [6][6] = {{0,10,0,30,45,0},
{10,0,50,0,40,25},
{0,50,0,0,35,15},
{30,0,0,0,0,20},
{45,40,35,0,0,55},
{0,25,15,20,55,0},
};
int E[2][10] = {{0, 2, 3, 1, 0, 2, 1, 0, 1, 4},{1, 5, 5, 5, 3, 4, 4, 4, 3, 5}};
int T[6][6];
int W[6], vt[6];
int v,v1,v2,k,m,mst;

int main(){
    k=1; mst=0;
    for (int i=0;i<=9;i++){
        if (k <= 5) {
            v1=E[0][i];v2=E[1][i];
            for(int j=0;j<=5;j++){
                W[j]=0;vt[j]=0;
            }
            for(int j=0;j<=5;j++){
                W[j]=T[v1][j];
            }
            int cek =0;
            while (cek<=5){
                for(int j=0;j<=5;j++){
                    if ((W[j]==1) && (vt[j]==0)){
                        vt[j]=1;
                        for(int k=0;k<=5;k++){
                            if(T[j][k]==1){
                                W[k]= 1;
                            }
                        }
                    }
                }
                cek++;
            }
            if(W[v2]==0){
                T[v1][v2]=1;T[v2][v1]=1;
                mst=mst+M[v1][v2];
                cout<<endl<<v1<<"-"<<v2<<" bobot"<<M[v1][v2]<<" total MST = "<<mst;
                M[v1][v2]=0;M[v2][v1]=0;
                k++;
            }
        }
    }
}

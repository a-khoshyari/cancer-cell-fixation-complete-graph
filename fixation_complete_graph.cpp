#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <ctime>
using namespace std;
int main(){
    srand(time(NULL));
    int n=3;
    // Change n (3, 4, 5) and recompile to reproduce the results in the slides.
    float w=0;
    int gama;
    int a[n],i;
    int r;
    int j;
    int sum=0;
    float l=0;
    
    ofstream out("results.tsv");
    out<<"n"<<'\t'<<"gama"<<'\t'<<"fixation.p"<<'\t'<<"fixation.t"<<'\n';
    for(gama=1;gama<=10;gama++){
    for(int z=1;z<=1000;z++){
        for(i=0;i<n;i++){
        a[i]=0;
        }
        a[(rand()%n)]=1;
        j=0;
        for(i=0;i<=1000;i++){
            r=(rand()%10)+1;
            if(r<=gama){
                a[(rand()%n)]=a[(rand()%n)];
                j++;
                sum=0;
                for(int e=0;e<=n-1;e++){
                    
                    sum=sum+a[e];
                }
                if(sum==n){
                    l++;
                    w=w+j;
                    break;
                }
                else{if(sum==0)break;}
                
            
            }
            else{
                j++;
                continue;
            }
        }
        
       // out<<a[0]<<'\t'<<a[1]<<'\t'<<a[2]<<'\t'<<sum<<'\t'<<j<<'\t'<<l<<'\t'<<w<<'\t'<<z<<'\n';
    }
        out<<n<<'\t'<<gama/10.0<<'\t'<<l/1000<<'\t'<<w/l<<'\n';
        w=0;
        l=0;
    }
}

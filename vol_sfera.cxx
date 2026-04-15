#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

int main(){
    //typedef std::chrono::high_resolution_clock myclock;
    //myclock::time_point beginning = myclock::now();
    //myclock::duration d = myclock::now() - beginning;
    //unsigned seed2 = d.count();
    unsigned seed2 = chrono::system_clock::now().time_since_epoch().count();
    int m, N=10000000;
    double vol_t, vol, omega, media=0, somma=0, p, r, temp, sigma, var;
    vector <double> x_rand;
    vector <double> func;
    default_random_engine rd(seed2);
    
    //mt19937 gen(rd());
    uniform_real_distribution <double> dis(-1,1);
    cout<<"inserire numero di dimensioni: "<<endl;
    cin>>m;

    //theoretical volume of the sphere
    vol_t=pow(M_PI,m/2)/tgamma((m/2)+1);
    cout<<"volume teorico: "<<vol_t<<endl;
    //integration domain
    omega=pow(2,m);

    for (int i=0; i<N; i++){
        for (int j=0; j<m; j++){ //this is to generate m values for the components
            r=dis(rd);
            x_rand.push_back(r);
            temp+=pow(r,2);
        }
        if(temp<=1){
            media+=1;
            func.push_back(1);
        }
        else{
            func.push_back(0);
        }
        temp=0;
    }
    media=media/N;
    vol=omega*media;

    cout<<"Il volume calcolato e': "<<vol;

    for(int k=0; k<func.size(); k++){
        somma+=pow(func.at(k)-media,2);
    }
    var=somma/N;
    sigma=sqrt(var/N);
    cout<<" +/- "<<sigma<<endl;




    return 0;
}
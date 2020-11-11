#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
int main(){
    ifstream inFile;
    inFile.open("data.txt");
    vector<string> input;
    string temp;
    string x,y;
    string hr,mm,ss;
    vector<double> time;
    vector<double> dist;
    long double t;
    if(!inFile){
        cout<<"Unable to open the file";
        exit(1);
    }
    while(inFile>>x>>y){
        stringstream str2;
        str2<<x;
        getline(str2,hr,':');
        getline(str2,mm,':');
        getline(str2,ss);
        t=stod(hr)*3600+stod(mm)*60+stod(ss);
        time.push_back(t);
        dist.push_back(stod(y));
        //cout<<dist[dist.size()-1]<<endl;
    }
    inFile.close();
    double slow_time,tot_dist;
    
    double cost=80*(int)(slow_time/90)+410+max(0,80*(1+(int)(tot_dist-1052-1)/237));
    cout<<cost;
    return 0;
}

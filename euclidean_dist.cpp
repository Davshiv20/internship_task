#include<bits/stdc++.h>
using namespace std;

double euclideanDist(pair<double,double>& pointA,pair<double,double>& pointB)
{
    return sqrt(pow(pointA.first-pointB.first,2)+ pow(pointA.second-pointB.second,2));
}
vector<pair<pair<double,double>,pair<double,double>>> findPairsWithinDistance( vector<pair<double, double>>& setA, vector<pair<double, double>>& setB, double e)
{
    vector<pair<pair<double,double>,pair<double,double>>>pairs;
    for(auto& i: setA)
    {
        for(auto &j: setB)
        {
            double dist=euclideanDist(i,j);
            if(dist<e)
            {
                pairs.push_back({i,j});
            }

        }
    }
    return pairs;
}
int main(){
    srand(time(NULL)); //seed for random no generation

    int m=10;
    int n=10;
    vector<pair<double,double>>setA; //vector for setA
    vector<pair<double,double>>setB; //vector for setB
    for(int i=0;i<m;i++)
    {
        setA.push_back({(double)rand()/RAND_MAX*10, (double)rand()/RAND_MAX*10});
    }
    for(int i=0;i<n;i++)
    {
         setB.push_back({(double)rand()/RAND_MAX*10, (double)rand()/RAND_MAX*10});
    }
    for(int i=0;i<5;i++) //testing for randomly generated 5 different epsilon values
    {
        double e=rand() % 10 + 1;
        auto pairsWithinDistance=findPairsWithinDistance(setA,setB,e);
        cout<<"Pairs within distance epsilon "<<e<<" :"<<endl;
        for(auto& j:pairsWithinDistance)
        {
            cout<< "("<<j.first.first<<", "<<j.first.second<<")<-->("<<j.second.first<<", "<<j.second.second<<")"<<endl;
        }
        cout<<endl;
    }
}
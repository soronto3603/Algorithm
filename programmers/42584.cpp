#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> prices={498,501,470,489};
    //[2,1,1,0]
    
    vector<int> result;
    
    for(int i=0;i<prices.size();i++){
        int time=0;
        for(int j=i+1;j<prices.size();j++){
            // cout << "["<<prices[i]<<"]" <<" < ["<<prices[j]<<"]"<< time<< " " << endl;
            time++;
            if(prices[i] > prices[j]){
                break;
            }
            
        }
        result.push_back(time);
    }

    for(int i=0;i<result.size();i++){
        cout << result[i] << endl;
    }
    return 0;
}
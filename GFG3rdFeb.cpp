#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
     pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
        vector<pair<int, int>>arr = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int t1 = 0;
        int x = 0, y = 0;
        while(x >= 0 && x < R && y >=0 && y < C){
            int temp = matrix[x][y];
            if(temp == 1){
                matrix[x][y] = 0;
                t1 = (t1+1)%4;
            }
            x += arr[t1].first;
            y += arr[t1].second;
        }
        return {x-arr[t1].first, y-arr[t1].second};
    }
};

int main()
{
    int tc;
	cin >> tc;
	while(tc--){
		int row, col;
		cin>> row;
        cin>>col;
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
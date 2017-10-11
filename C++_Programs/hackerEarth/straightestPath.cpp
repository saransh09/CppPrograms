#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<char> > grid, int x, int y, int prevDir, int currDir) {
    if(x<0 || x > grid.size() || y < 0 || y > grid[0].size()) return false;
    if(grid[x][y]=='*') return false;
    if(prevDir == -1 * currDir) return false;
    cout<<"prevDir"<<' '<<prevDir<<'\t'<<"currDir"<<' '<<currDir<<endl;
    return true;
}

void minDirChange(vector<vector<char> > grid, int x, int y, int fx, int fy, int dir, int & dirChange,int & prevDir, int currDir){
    if(!isValid(grid,x,y,prevDir,currDir)) return;
    if(prevDir!=currDir){ 
        prevDir = currDir;
        dir++;
    }
    if(x==fx && y==fy){ 
        dirChange = max(dirChange,dir);
        return;
    }
    minDirChange(grid,x+1,y,fx,fy,dir,dirChange,prevDir,1);
    minDirChange(grid,x-1,y,fx,fy,dir,dirChange,prevDir,-1);
    minDirChange(grid,x,y+1,fx,fy,dir,dirChange,prevDir,2);
    minDirChange(grid,x,y-1,fx,fy,dir,dirChange,prevDir,-2);
}

int main(){
    int m,n;
    cin>>m>>n;
    int x,y;
    int fx,fy;
    vector<vector<char> > grid(m,vector<char>(n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            char ch;
            cin>>ch;
            grid[i][j] = ch;
            if(grid[i][j]=='V'){
                x = i;
                y = j;
            }
            if(grid[i][j]=='H'){
                fx = i;
                fy = j;
            }
        }
    }
    int dirChange = INT_MAX;
    int prevDir  = 3;
    minDirChange(grid,x,y,fx,fy,0,dirChange,prevDir,3);
    cout<<dirChange<<endl;
    return 0;
}

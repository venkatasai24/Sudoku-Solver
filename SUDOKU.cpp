#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;
bool findzero(vector<vector<int>>& m,int& r,int& c)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            if(m[i][j]==0)
            {
                r=i;
                c=j;
                return true;
            }
        }
    }
    return false;
}
bool row(vector<vector<int>>& m,int r,int num)
{
    for(int i=0;i<9;i++)
    {
        if(m[r][i]==num) return true;
    }
    return false;
}
bool col(vector<vector<int>>& m,int c,int num)
{
    for(int i=0;i<9;i++)
    {
        if(m[i][c]==num) return true;
    }
    return false;
}
bool box(vector<vector<int>>& m,int r,int c,int num)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(m[r+i][c+j]==num) return true;
        }
    }
    return false;
}
bool valid(vector<vector<int>>& m,int r,int c,int num)
{
    return !row(m,r,num) && !col(m,c,num) && !box(m,r-(r%3),c-(c%3),num) && m[r][c]==0;
}
bool solve(vector<vector<int>>& m)
{
    int row,col;
    if(!findzero(m,row,col)) return true;
    for(int num=1;num<=9;num++)
    {
        if(valid(m,row,col,num))
        {
            m[row][col]=num;
            if(solve(m)) return true;
            m[row][col]=0;
        }
    }
    return false;
}
void printGrid(vector<vector<int>>& grid)
{
    system("Color 02");;
    for (int row = 0; row < 9; row++)
    {
        if(row%3==0) cout<<endl;
        for (int col = 0; col < 9; col++)
        {
            if(col==0) cout<<"| ";
            cout<<grid[row][col]<<" ";
            if(col%3==2) cout<<"| ";
        }
        cout<<endl;
        if(row%3==2)
        {
            for(int i=0;i<9;i++)
            {
                cout<<"__ ";
            }
            cout<<endl;
        }
    }
    cout<<endl;
}
int main()
{
    // vector<vector<int>> grid= { { 6, 0, 3, 0, 0, 0, 0, 7, 0 },
    //                             { 0, 5, 0, 0, 9, 0, 0, 0, 0 },
    //                             { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    //                             { 2, 0, 0, 7, 0, 5, 0, 0, 0 },
    //                             { 0, 8, 0, 0, 0, 0, 9, 0, 4 },
    //                             { 0, 0, 0, 0, 3, 0, 0, 0, 0 },
    //                             { 0, 0, 0, 6, 0, 0, 8, 0, 0 },
    //                             { 0, 0, 7, 0, 0, 0, 0, 5, 0 },
    //                             { 4, 0, 0, 0, 0, 0, 0, 0, 0 } };
    vector<vector<int>> grid(9,vector<int>(9));
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>grid[i][j];
        }
    }
    auto start = high_resolution_clock::now();
    if (solve(grid))
    {
        printGrid(grid);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        cout << "Time taken to solve : "<< duration.count() << " milliseconds" << endl;
    }
    else
    {
        system("color 04");
        cout <<endl<< "No solution exists"<<endl;
    }
    return 0;
}

class Solution {
    int r[9]{}, c[9]{}, b[9]{};

    bool solve(vector<vector<char>>& a) {
        int x=-1,y=-1,mn=10,ms=0;

        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                if(a[i][j]=='.'){
                    int m=(~(r[i]|c[j]|b[i/3*3+j/3]))&511;
                    int n=__builtin_popcount(m);
                    if(n<mn) mn=n,x=i,y=j,ms=m;
                }

        if(x<0) return true;

        int k=x/3*3+y/3;
        while(ms){
            int z=ms&-ms; ms-=z;
            a[x][y]='1'+__builtin_ctz(z);
            r[x]|=z; c[y]|=z; b[k]|=z;

            if(solve(a)) return true;

            r[x]^=z; c[y]^=z; b[k]^=z;
            a[x][y]='.';
        }
        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                if(board[i][j]!='.'){
                    int z=1<<(board[i][j]-'1');
                    r[i]|=z; c[j]|=z; b[i/3*3+j/3]|=z;
                }
        solve(board);
    }
};
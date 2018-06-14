#include <iostream>
using namespace std;

void clearBoard(char board[][100],int m,int n){
	for(int r = 0;r<m;++r){
		for(int c=0;c<n;c++){
			board[r][c] = 'X';
		}
	}
}
void outputMat(char board[][100],int m,int n){
	for(int r=0;r<m;r++){
		for(int c=0;c<n;c++){
			cout<<board[r][c]<<" ";
		}
		cout<<endl;
	}
}
bool canPlace(char board[][100],int N,int r,int c){
	for(int x=0;x<N;x++){
		if(board[x][c] == 'Q')
			return false;
	}
	int rowDir[] = {-1,-1};
	int colDir[] = {-1,+1};
	for(int dir=0;dir<2;dir++){
		for(int dist=0;dist<N;dist++){
			int nextRow = r + dist*rowDir[dir];
			int nextCol = c + dist*colDir[dir];
			if((nextRow<0 || nextRow>=N)or(nextCol<0 || nextCol>=N))
				break;
			//Now check safely
			if(board[nextRow][nextCol] == 'Q')
				return false;
		}
	}
	return true;
}
bool solveNQueen(char board[][100],int N,int r){
	if(r==N)
		return true;
	//Lets try to place the queen in row R
	for(int c=0;c<N;c++){
		bool check = canPlace(board,N,r,c);
		if(check == true){
			board[r][c] = 'Q';
			bool status = solveNQueen(board,N,r+1);
			if(status == true)
				return true;
			else
				board[r][c] = 'X';
		}
	}
	return false;
}
int main(){
	char board[100][100];
	int N; cin>>N;
	clearBoard(board,N,N);
	bool success = solveNQueen(board,N,0);
	if(success)
		outputMat(board,N,N);
	else
		cout<<"Your castle is too small to handle queens!"<<endl;	
}

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;
const int N = 15;  //TWL
const int M = 25; //3RD
int counter=0;
char grid[N][M];

//srand( (unsigned)time( NULL ) );
int n2=rand()%N;
int n=rand()%N;
//This function prints the grid of Gomoku as the game progresses
void print_grid() {

    cout << "\n";
	cout << "__";
    for (int i = 0; i < M; cout << "___", i++);
    cout << "__\n";
    for (int i = 0; i < N; i++) {
            if( i==n ){cout<<"   ";}
        else{cout << "|  ";   }   //left
        for (int j = 0; j < M; j++)
            cout << grid[i][j] << "  ";
            if( i==n2 ){cout<<" \n";}
        else {cout << "|\n";}
        cout << "";
        for (int i = 0; i < M; cout << "", i++);
    }
    cout<<"|"; for (int i = 0; i < M; cout << "___", i++);
    cout << "__|\n";
}

//This function checks if the game has a win state or not
bool check_win(int a, int b ) {
    if(a==n2 && b+1==M){return true;}
    else{return false;}

}


//This function checks if the game has a tie state or not for the given mark
bool check_wall(int i, int a , int b) {
if (i==3){  if(grid[a][b+1]=='|' || grid[a][b+1]=='_' ){return true;}}

else if (i==1){ if(grid[a-1][b]=='|' || grid[a][b+1]=='_' ){return true;}}

else if (i==2){  if(grid[a+1][b]=='|' || grid[a][b+1]=='_' ){return true;}}

else if (i==4){  if(grid[a][b-1]=='|' || grid[a][b+1]=='_' ){return true;}}
  return false;
}



//This function checks if given position is valid or not
bool check_valid_direction(int i) {
    if (i==1 || i==2 || i==3 || i==4 ){
        return true;
        }
    else{return false;}
}

//This function generates pac man
void generate_man(int &a , int &b) {

    a = n;
	b = 0;
    grid[a][b] = 'M';
}

//This function generates a wall
void generate_wall() {
    srand( (unsigned)time( NULL ) );
    int f=N*M*1/6;
    while ( f>0 )
    {
    int a = rand() % N;
	int b = rand() % M;
    while ( grid[a][b] == 'M' || (a==n2 && b==M-1) || (a==n2-1 && b==M-1) || (a==n2+1 && b==M-1) || (a==n && b==1)
                             || (a==n-1 && b==0) || (a==n+1 && b==0)||(a==n-1 && b==1) || (a==n+1 && b==1)) {

        a = rand() % N;
        b = rand() % M;
	}
    grid[a][b] = '|';
    f--;
    }
}

void generate_() {
    srand( (unsigned)time( NULL ) );
    int f=N*M*1/8;
    while ( f>0 )
    {
    int a = rand() % N;
	int b = rand() % M;
    while ( grid[a][b] == 'M' || grid[a][b] == '|' || (a==n-1 && b==0) ||
            (a==n+1 && b==0)||(a==n-1 && b==1) || (a==n+1 && b==1) || (a==n && b==1)
           ||(a==n2 && b==M-1) || (a==n2-1 && b==M-1) || (a==n2+1 && b==M-1))  {
        a = rand() % N;
        b = rand() % M;
	}
    grid[a][b] = '_';
    f--;
    }
}



//Move with the input direction
void move(int i,int &a,int &b) {
    grid[a][b]='.';
    if (i==3){  if(grid[a][b+1]=='+'){counter+=1; grid[a][b+1]='M';   }
                else if(grid[a][b+1]=='.'){ grid[a][b+1]='M';  } b+=1;  } //right

 else if (i==1){ if(grid[a-1][b]=='+'){counter+=1; grid[a-1][b]='M';}
                 else if(grid[a-1][b]=='.'){ grid[a-1][b]='M'; }  a-=1;  }   // up

 else if (i==2){  if(grid[a+1][b]=='+'){counter+=1; grid[a+1][b]='M';}
                    else if(grid[a+1][b]=='.'){ grid[a+1][b]='M'; } a+=1;}  //down

 else if (i==4){  if(grid[a][b-1]=='+'){counter+=1; grid[a][b-1]='M';}
                  else if(grid[a][b-1]=='.'){ grid[a][b-1]='M'; }b-=1;}  }   //left

//This function clears the game structures
void grid_clear() {
     for (int i =0 ; i<N; i++){
            for (int j =0 ; j<M; j++){
                grid[i][j]='.';
            }
        }

}
//This function reads a valid direction
void read_input(int &i,int &a, int &b) {
    cout << "Enter the direction: ";
	cin >> i;
    while (!check_valid_direction(i)) {
        cout << "Enter a valid direction: ";
		cin >> i;
	}
}
//MAIN FUNCTION
void play_game(int &a,int &b) {
    cout << "Pac-Man Game!\n";
    cout << "Welcome...\n";
    cout << "============================\n";
    while (true) {

        //Prints the grid
        print_grid();
        //Read an input from the player
		int i;
		read_input(i,a,b);

        //Check if the state of the grid has a tie state
        /*if (check_lose(i,a,b)) {
            //Prints the grid
            print_grid();
            //Announcement of the final statement
            cout << "GAME OVER!\n";
            break;
        }*/
        if(check_wall(i,a,b)){
            cout<<"WHATCH OUT you hit a wall !! please " ;
            read_input(i,a,b);
        }
        //Move with the input direction
        move(i,a,b);
        //Check if the state of the grid has a win state
        if (check_win(a,b)) {
            //Prints the grid
            print_grid();
            //Announcement of the final statement
            cout << "Congrats, you won!\n";
            break;
        }

    }
}
int main() {
    while (true) {
        int a,b;
        grid_clear();
        //
        generate_man(a,b);

        generate_wall();
        generate_();
    	play_game(a,b);
    	char c;
    	cout << "Play Again [Y/N] ";
    	cin >> c;
    	if (c != 'y' && c != 'Y')
    		break;
    }
}

#include "gol.h"


void start_message(){
	printf("Welcome to the Game of Life!\n");
}

void init_board(Board b){
	int i, y;
	for(i = 0; i < BOARDSIZE; i++){
		for(y = 0; y < BOARDSIZE; y++){
			b[i][y] = DEAD; //Leave no survivors
		}
	}
}

void get_dots(Board b){
	printf("\n\n*************************************************************\n\n\n");
	printf("Enter 0 to manually enter initial points, or 1-4 for examples:\n"
	"1.Glider\n2.Exploder\n3.Spaceship\n4.10 cell row\n"
	);
	char c = 0;
	int x = 0, y = 0;
	int hb = BOARDSIZE/2; //Half board (for the examples)
	while(1){
		c = getchar();
		if(c >= '0' && c <= '4')
			break;
		printf("Please enter a choice between 0-4\n");
	}
	if(c == '0'){
		printf("Enter X and Y values for each initial dot like so: \"10 20\". Press <Enter> after each dot.\nTo finish enter -1 in x or y\n");
		while(1){
			scanf("%d %d", &x, &y);
			if(x == (-1) || y == (-1)){
				break;
			}
			if(inBounds(x,y)){ //if x and y are in the borders
				b[x][y] = ALIVE;
			}
			else{
				printf("Please enter values between 0 and %d\n", BOARDSIZE-1);
			}
		}
	}
		else{
			switch(c){
				case '1':
					b[hb][hb] = b[hb-1][hb] = b[hb-2][hb] = b[hb][hb-1] = b[hb-1][hb-2] = ALIVE;
					break;
				case '2':
					b[hb][hb] = b[hb][hb+2] = b[hb][hb-1] = b[hb-1][hb-1] = b[hb-1][hb] = b[hb+1][hb-1] = b[hb+1][hb] = ALIVE;
					break;
				case '3':
					b[hb][hb] = b[hb][hb+1] = b[hb][hb+2] = b[hb-1][hb] = b[hb-1][hb+3] = b[hb-2][hb] = b[hb-3][hb] = b[hb-4][hb+1] = b[hb-4][hb+3] = ALIVE;
					break;
				case '4':
					b[hb][hb-4] = b[hb][hb-3] = b[hb][hb-2] = b[hb][hb-1] = b[hb][hb] = b[hb][hb+1] = b[hb][hb+2] = b[hb][hb+3] = b[hb][hb+4] = b[hb][hb+5] = ALIVE;
					break;
		}
		
	}
}

void next(Board b){
	int i, j, num_n;
	for(i = 0; i < BOARDSIZE; i++){
		for(j = 0; j < BOARDSIZE; j++){
			num_n = num_neighbours(b,i,j);
			if(num_n == 3 && b[i][j] == DEAD){
				b[i][j] = PENDING_LIFE; //this is necessary so we dont count it as alive when checking neighbours, and only give it life next round
			}
			else if((num_n == 2 || num_n == 3) &&  b[i][j] == ALIVE){
				;	//Stays alive
			}
			else if(b[i][j] == ALIVE){
				b[i][j] = PENDING_DEATH; //doesnt meet the conditions to stay alive
			}
		}
	}
}

int num_neighbours(Board b, int x, int y){
	int cnt = 0, i, j;
	for(i = -1; i <= 1; i++){
		for(j = -1; j <= 1; j++){
			if(inBounds(x+i,y+j)){
				if(b[x+i][y+j] == ALIVE || b[x+i][y+j] == PENDING_DEATH) //if a neighboor is alive, or pending death, in which case he was alive last round
					cnt++;
			}
		}
	}
	if(b[x][y] == ALIVE || b[x][y] == PENDING_DEATH){
		--cnt; //minus one to account for the counting of b[x][y] itself if it's alive, or was last round (Pending death)
	}
	return cnt;
}

void execute_and_birth(Board b){
	int i, j;
	for(i = 0; i < BOARDSIZE; i++){
		for(j = 0; j < BOARDSIZE; j++){
			if(b[i][j] == PENDING_DEATH){
				b[i][j] = DEAD;
			}
			else if(b[i][j] == PENDING_LIFE){
				b[i][j] = ALIVE;
			}
		}
	}
	
}

void print_board(Board b){
	int i, j;
	for(i = 0; i < BOARDSIZE; i++){
		for(j = 0; j < BOARDSIZE; j++){
			putchar(b[i][j]);
		}
	putchar('\n');
	}	
}

void run_game(Board b){
	while(1){
	system("clear"); //Assume this is running on linux because if you're running Windows you don't deserve to be playing this game
	print_board(b);
	sleep(1); //Assume this is running on linux
	next(b);
	execute_and_birth(b);
	}
}






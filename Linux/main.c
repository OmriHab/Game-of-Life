#include "gol.h"

int main(){
	Board b;
	start_message();
	init_board(b);
	get_dots(b);
	run_game(b);
	
	return 0;
}

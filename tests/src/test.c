#include "../../include/boat.h"
#include "../../include/const.h"
#include "../../lib/include/board.h"
#include <CUnit/Basic.h>


/* TEST BOAT */

void test_init_boat(void){
  Boat boat;
  int i;
  initBoat(&boat, 3, "bateau");
  for (i=0;i<3;i++){
    CU_ASSERT(boat.cells[i].val == 1);
  }
  CU_ASSERT(strcmp(boat.name,"bateau") == 0);
}

void test_init_fleet(void){
  int i;
  Boat *fleet;
  char *name[N_BOAT] = {"porte_avion","croiseur","contre_torpilleur","sous_marin","torpilleur"};

  initFleet(&fleet);

  for (i=0;i<N_BOAT;i++){
    CU_ASSERT(strcmp(fleet[i].name,name[i]) == 0);
  }

  CU_ASSERT(fleet[0].cells[4].val == 1);
  CU_ASSERT(fleet[2].cells[2].val == 1);

}


/* TEST BOARD */

void test_init_board(void) {

  Board board;
  int i,j;

  initBoard( &board,10,8 );

  CU_ASSERT( board.row == 10 );
  CU_ASSERT( board.col == 8 );

  for (i = 0; i < board.row; i++){
    for (j = 0; j < board.col; j++) {
      CU_ASSERT( board.tab[i][j] == 0);
    }
  }

}

void test_check_in_tab(void) {

  Board board;
  int i,j;

  initBoard(&board,10,10);

  for ( i = 0; i < 15 ; i++ ) {
    for ( j = 0; j < 15 ; j++ ) {
      if ( i < 10 && j < 10 ) {
        CU_ASSERT( checkInTab( board,i,j ) == 1 );
      }
      else {
        CU_ASSERT( checkInTab( board,i,j ) == 0 );
      }
    }
  }

}

void test_put_value(void) {

  Board board;
  int i,j;

  initBoard(&board,10,10);
  for ( i = 0; i < 15 ; i++ ) {
    for ( j = 0; j < 15 ; j++ ) {
      putValue( &board,i,j,i*j );
      if ( i < 10 && j < 10 ) {
        CU_ASSERT( board.tab[i][j] == i*j);
      }
    }
  }

}

void test_print_board(void) {

  Board board;
  initBoard(&board,5,5);
  printf("\n");
  printBoard(board);
  printf("Putting 3 in [1][2]\n");
  printf("Putting 2 in [3][3]\n");
  putValue(&board,1,2,3);
  putValue(&board,3,3,2);
  printBoard(board);

}

void test_free_board(void) {

  Board board;
  initBoard(&board,10,10);
  freeBoard(board);

}

int main(void){
  CU_initialize_registry();

  /* Boat test suite */
  CU_pSuite boat_test;
  boat_test = CU_add_suite("boat_test", 0, 0);
  CU_add_test(boat_test, "init_boat", test_init_boat);
  CU_add_test(boat_test, "init_fleet",test_init_fleet);
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();

  /*Suite test lib Board*/
  CU_pSuite board_test;
  board_test = CU_add_suite("test_suite", 0, 0);
  CU_add_test(board_test, "init_board", test_init_board);
  CU_add_test(board_test, "check_in_tab", test_check_in_tab);
  CU_add_test(board_test, "put_value", test_put_value);
  CU_add_test(board_test, "print_board", test_print_board);
  CU_add_test(board_test, "free_board", test_free_board);
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();

  CU_cleanup_registry();
  return 0;
}

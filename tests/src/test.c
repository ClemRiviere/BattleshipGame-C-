#include "../../include/boat.h"
#include "../../lib/board.h"
#include <CUnit/Basic.h>

void test_init_boat(void){
  Boat boat;
  int i;
  initBoat(&boat, 3, "bateau");
  for (i=0;i<3;i++){
    CU_ASSERT(boat.cells[i].val == 1);
  }
  CU_ASSERT(strcmp(boat.name,"bateau") == 0);
}

void test_init_board(void) {

  tab ** t;
  initBoard(t,10,10);
  CU_ASSERT( 0 == t[5][2] );
  CU_ASSERT( 0 == t[0][0] );
  CU_ASSERT( 0 == t[9][9] );

}

void test_print_board() {

  tab ** t;
  initBoard(t,10,10);
  CU_ASSERT( printBoard(t,10,10) );

}

void test_put_value() {
  
  tab ** t;
  initBoard(t,10,10);
  CU_ASSERT( putValue(t,4,4,5) );
  CU_ASSERT( putValue(t,10,10,2) );
  CU_ASSERT( 5 == tab[4][4] );

}

void test_check_in_tab() {

  tab ** t;
  initBoard(t,10,10);
  
  CU_ASSERT( checkInTab(t,2,2) );
  CU_ASSERT( checkInTab(t,0,0) );
  CU_ASSERT( checkInTab(t,15,15) );
}

void test_free_board() {

  tab ** t;
  initBoard(t,10,10);
  
  CU_ASSERT(freeBoard(t));
}

int main(void){
  CU_initialize_registry();

  /* Suite test boat */
  CU_pSuite suite_test = CU_add_suite("test_suite", 0, 0);
  CU_add_test(suite_test, "init_boat", test_init_boat);
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();

  /* Suite test lib Board */
  CU_pSuite test_board= CU_add_suite("test_suite", 0, 0);
  CU_add_test(test_board, "init_board", test_init_boat);
  CU_add_test(test_board, "print_board", test_print_boat);
  CU_add_test(test_board, "put_value", test_put_value);
  CU_add_test(test_board, "check_in_tab", test_check_in_tab);
  CU_add_test(test_board, "free_board", test_free_board);
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();

  CU_cleanup_registry();
  return 0;
}

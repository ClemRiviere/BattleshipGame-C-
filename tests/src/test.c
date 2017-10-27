#include "../../include/boat.h"
#include "../../include/const.h"
<<<<<<< HEAD
#include "../../lib/board.h"
=======
#include "../../include/board.h"
>>>>>>> 5465565d4cb7a1578ffe0704900535f3320477d5
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

void test_init_fleet(void){
  int i;
  Boat *fleet;
  char *name[N_BOAT] = {"porte_avion","croiseur","contre_torpilleur","sous_marin","torpilleur"};

  initFleet(fleet);
  for (i=0;i<N_BOAT;i++){
    CU_ASSERT(strcmp(fleet[i].name,name[i]) == 0);
  }

  CU_ASSERT(fleet[0].cells[4].val == 1);
  CU_ASSERT(fleet[2].cells[2].val == 1);
<<<<<<< HEAD
=======
}
>>>>>>> 5465565d4cb7a1578ffe0704900535f3320477d5

void test_init_board(void) {

  int ** t;
  initBoard(t,10,10);
  CU_ASSERT( 0 == t[5][2] );
  CU_ASSERT( 0 == t[0][0] );
  CU_ASSERT( 0 == t[9][9] );

}

void test_print_board(void) {

  int ** t;
  initBoard(t,10,10);
  printBoard(t,10,10);

}

<<<<<<< HEAD
void test_put_value(void) {
  
  int ** t;
  initBoard(t,10,10);
  putValue(t,4,4,5) );
=======
void test_put_value() {

  int ** t;
  initBoard(t,10,10);
  putValue(t,4,4,5);
>>>>>>> 5465565d4cb7a1578ffe0704900535f3320477d5
  putValue(t,10,10,2);
  CU_ASSERT( 5 == t[4][4] );

}

void test_check_in_tab(void) {

  int ** t;
  initBoard(t,10,10);
  
  CU_ASSERT( 1 == checkInTab(t,2,2) );
  CU_ASSERT( 1 == checkInTab(t,0,0) );
  CU_ASSERT( 0 == checkInTab(t,15,15) );

}

void test_free_board(void) {

  int ** t;
  initBoard(t,10,10);
<<<<<<< HEAD
  
=======

>>>>>>> 5465565d4cb7a1578ffe0704900535f3320477d5
  freeBoard(t);
}

int main(void){
  CU_initialize_registry();

  /* Suite test boat */
  CU_pSuite suite_test = CU_add_suite("test_suite", 0, 0);
  CU_add_test(suite_test, "init_boat", test_init_boat);
  /*CU_add_test(suite_test, "init_fleet",test_init_fleet);*/
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();

  /* Suite test lib Board */
  CU_pSuite test_board= CU_add_suite("test_suite", 0, 0);
  CU_add_test(test_board, "init_board", test_init_boat);
  CU_add_test(test_board, "print_board", test_print_board);
  CU_add_test(test_board, "put_value", test_put_value);
  CU_add_test(test_board, "check_in_tab", test_check_in_tab);
  CU_add_test(test_board, "free_board", test_free_board);
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();

  CU_cleanup_registry();
  return 0;
}

#include "../../include/boat.h"
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

int main(void){
  CU_initialize_registry();

  /* Suite test boat */
  CU_pSuite suite_test = CU_add_suite("test_suite", 0, 0);
  CU_add_test(suite_test, "init_boat", test_init_boat);
  CU_basic_set_mode(CU_BRM_VERBOSE);
  CU_basic_run_tests();

  CU_cleanup_registry();
  return 0;
}

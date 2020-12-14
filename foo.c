#include <stdio.h>
#include <stdlib.h>
#define STU_NUM 5
int main(void)
{

  float score[STU_NUM] = {88.0, 78.5, 99, 77, 99};
  char name[5][20] = {
    "you_rong", 
    "dog_brother", 
    "wang_cai", 
    "tie_dan",
    "miss_qi"
  };
  
  int rank[STU_NUM] = {0, 1, 2, 3, 4};

  for (int i = 0; i < STU_NUM -1; i++) {
    for (int j = i + 1; j < STU_NUM; j++) {
      if (score[i] < score[j]) {
	float temp = score[i];
	score[i] = score[j];
	score[j] = temp;

	int tmp = rank[i];
	rank[i] = rank[j];
	rank[j] = tmp;
      }
    }

  }
  

  printf("Rank list:\n");
  for (int i = 0; i < STU_NUM; i++) {
    printf("%20s: %.2f\n", name[rank[i]], score[i]);
  }
  /*

  for (int i = 0; i < 5; i++)
    printf("%f\n", score[i]);
  */

  return 0;
}

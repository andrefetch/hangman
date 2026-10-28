#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {

  char getLetter;

  for (;;) {

    printf("Enter A Letter: ");
    scanf("%s", &getLetter);

    if (!isalpha(( unsigned char) getLetter )){
      printf("%c is not a letter, use an alphabetical letter.\n", getLetter);
    } else {
        printf("Your letter is: %c\n", getLetter);
        break;
    }

  }
  
  return 0;

} 

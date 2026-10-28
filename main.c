#include <stdio.h>
#include <ctype.h>
#include <string.h>

void buildMask(char *maskedString, const char *word);

int main(void) {
  char word[256];
  char mask[sizeof(word)];

  for (;;) {
    printf("Enter a word: ");
    fflush(stdout);

    if (fgets(word, sizeof(word), stdin) == NULL) {
      return ferror(stdin) ? 1 : 0;
    }

    size_t length = strcspn(word, "\n");
    if (word[length] == '\n') {
      word[length] = '\0';
    } else {
      int next = getchar();
      if (next != '\n' && next != EOF) {
        do {
          next = getchar();
        } while (next != '\n' && next != EOF);

        printf("Please enter a word of at most %zu letters.\n", sizeof(word) - 1);
        continue;
      }
    }

    int isWord = word[0] != '\0';
    for (size_t i = 0; word[i] != '\0'; i++) {
      if (!isalpha((unsigned char)word[i])) {
        isWord = 0;
        break;
      }
    }

    if (!isWord) {
      printf("Please enter a word containing only alphabetic letters.\n");
      continue;
    }

    printf("Your word is: %s\n", word);
    buildMask(mask, word);
    printf("%s\n", mask);
    break;
  }

  return 0;
}

void buildMask(char *maskedString, const char *word) {
  size_t length = strlen(word);

  for (size_t i = 0; i < length; i++) {
    maskedString[i] = '_';
  }

  maskedString[length] = '\0';
}

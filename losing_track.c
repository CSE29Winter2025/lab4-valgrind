#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *getQueries(char *url) {
  char *query = malloc(sizeof(char) * (strlen(url) + 1));
  if (!query) return NULL;

  // make our lowercase string
  for (int i = 0; i < strlen(url); i++) {
    query[i] = tolower(url[i]);
  }

  // search for ?
  char *ptr = query;
  while (*ptr != '?' && *ptr != 0) {
    ptr++;
  }

  if (*ptr == '?') {
    // Allocate only for query part
    char *result = malloc(sizeof(char) * (strlen(ptr) + 1));

    // Copy query part only
    strcpy(result, ptr + 1);
    // Free original memory
    free(query);
    return result;
    //return ptr + 1;
  }
  free(query);
  return NULL;
}

int main(int argc, char *argv[]) {
  char s[] = "https://example.com/over/there?name=ferret";

  char *queries = getQueries(s);
  printf("%s\n", queries);
  if (queries) {
      free(queries);
  }
  return 0;
}

#include <stdio.h>
#include <string.h>

typedef struct HashEntry {
  int f;
  int hash;
  char s[20];
} HashEntry;

typedef struct table {
  int size;
  HashEntry entries[101];
} table;

int hashF(char *s) {
   int sum = 0;
   int i = 1;
  while(*s != '\0') {
    sum += (*s) * i;
    ++i;
    ++s;
  }
  return (19 * sum) % 101;
}

int find(table *h, char *string) {
  int hash = hashF(string);
  int j;
  for(j = 0; j < 20; ++j) {
    int Hashloc = (hash + 23 * j + j * j) % 101;
    if(h->entries[Hashloc].f == 0) return 0;
    if(h->entries[Hashloc].f == 1) continue;
    if(h->entries[Hashloc].hash == hash && (strcmp(h->entries[Hashloc].s, string) == 0)) {
      return 1;
    }
  }
  return 0;
}

void insert(table *h, char *string) {
  int hash = hashF(string);
  int j;

  if (find(h, string) == 1) return;

  for(j = 0; j < 20; ++j) {
    int Hashloc = (hash + 23 * j + j * j) % 101;
    if(h->entries[Hashloc].f == 0 || h->entries[Hashloc].f == 1) {
      (h->size)++;
      h->entries[Hashloc].f = 2;
      h->entries[Hashloc].hash = hash;
      strcpy(h->entries[Hashloc].s, string);
      break;
    }
  }
  return;
}

void deleteT(table *h, char *string) {
  int hash = hashF(string);
  int j;
  for(j = 0; j < 20; ++j) {
    int Hashloc = (hash + 23 * j + j * j) % 101;
    if(h->entries[Hashloc].f == 0)
        return;
    if(h->entries[Hashloc].f == 1)
        continue;
    if(h->entries[Hashloc].hash == hash && (strcmp(h->entries[Hashloc].s, string) == 0))
    {
      h->entries[Hashloc].f = 1;
      (h->size)--;
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    table hTable;

    int i, j;
    for(i = 0; i < 101; ++i) {
      hTable.entries[i].f = 0;
    }
    hTable.size = 0;

    int n;
    scanf("%d", &n);

    char string[50];
    for(i = 0; i < n; ++i)
    {
      scanf("%s", string);
      if(string[0] == 'A')
      {

        insert(&hTable, string + 4);
      }
        else
      {

        deleteT(&hTable, string + 4);
      }
    }
    printf("%d\n", hTable.size);

    for(i = 0; i < 101; ++i)
    {
      if(hTable.entries[i].f == 2)
      {
        printf("%d:%s\n", i, hTable.entries[i].s);
      }
    }
  }
  return 0;
}

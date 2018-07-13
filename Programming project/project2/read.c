#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
 
 
int main() {
int i=0;
char* string[100];
char line[100];
 
FILE *file; 
file = fopen("greetings.txt", "r"); 
 
while(fgets(line, sizeof line, file)!=NULL) { 
printf("%s", line);
string[i]=line;
i++;
}
 
for (i=0 ; i<4; i++) {
printf("%s", string[i]);
}
fclose(file);
return 0;
}
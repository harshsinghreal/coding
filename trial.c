#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
// Function to find and underline the words in the list 
void find_and_underline(const char** words, const char** lines, int n) { 
  // Iterate through the lines of text 
  for (int i = 0; i < n; i++) { 
    puts(lines[i]);  // Print the line 
    int underline_len = strlen(lines[i]);  // Initialize the underline string length 
    char* underline = malloc(underline_len + 1);  // Allocate memory for the underline string 
    for (int j = 0; j < underline_len; j++) { 
      underline[j] = ' ';  // Initialize the underline string with spaces 
    } 
    underline[underline_len] = '\0';  // Add the null terminator 
 
    // Iterate through the words in the list 
    for (int j = 0; words[j] != NULL; j++) { 
      // Check if the word appears in the line 
      char* pos = strstr(lines[i], words[j]); 
      if (pos != NULL) { 
        // If the word appears, underline it using "_" characters 
        int word_len = strlen(words[j]); 
        for (int k = 0; k < word_len; k++) { 
          underline[pos - lines[i] + k] =' ';  // Replace the corresponding characters in the underline string with "" 
        } 
      } 
    } 
 
    puts(underline);  // Print the underline 
    free(underline);  // Free the memory allocated for the underline string 
  } 
} 
 
int main() { 
  // Create the list of words to find 
  const char* words[] = { "for","for each", "in", "is", "list of", "unit" }; 
 
  // Read the number of lines from the user 
  int n; 
  printf("Enter the number of lines: "); 
  scanf("%d", &n); 
 
  // Read the lines of text from the user 
  char** lines = malloc(n * sizeof(char*));  // Allocate memory for the lines of text 
  char ch=getchar(); 
  for (int i = 0; i < n; i++) { 
    lines[i] = malloc(101);  // Allocate memory for each line of text 
    fgets( lines[i],101,stdin);  // Read the line of text from the user 
     
  } 
 
  // Find and underline the words in the list 
  find_and_underline(words, lines, n); 
 
  // Free the memory allocated for the lines of text 
  for (int i = 0; i < n; i++) { 
    free(lines[i]); 
  } 
  free(lines); 
 
  return 0; 
}
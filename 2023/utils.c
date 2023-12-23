#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **str_break(char *_input, char *delimiter) {
  long int _input_length = strlen(_input);

  char *input = (char *)malloc(sizeof(char) * (_input_length + 1));

  _input_length = strlen(_input);

  strcpy(input, _input);

  long int input_length = strlen(input);

  strcpy(input, _input);
  char **tokens = NULL;
  int count = 0;

  char *token = strtok(input, delimiter);

  while (token != NULL) {
    tokens = realloc(tokens, sizeof(char *) * (count + 1));
    tokens[count] = token;
    token = strtok(NULL, delimiter);
    count++;
  }

  tokens = realloc(tokens, sizeof(char *) * (count + 1));
  tokens[count] = NULL;
  return tokens;
}

char *read_file(char *path) {
  FILE *filePtr;
  char *buffer;
  char character;
  long file_size;
  int index = 0;

  // Open the file in read mode
  filePtr = fopen(path, "r");

  // Check if the file was opened successfully
  if (filePtr == NULL) {
    perror("Error opening file");
    return NULL; // Return an error code
  }

  // Get the file size
  fseek(filePtr, 0, SEEK_END);
  file_size = ftell(filePtr);
  rewind(filePtr);

  // Dynamically allocate memory to store the file content
  buffer = (char *)malloc(file_size + 1); // +1 for null-terminator

  // Check if memory allocation was successful
  if (buffer == NULL) {
    perror("Memory allocation error");
    fclose(filePtr);
    return NULL; // Return an error code
  }

  // Read the file character by character
  while ((character = fgetc(filePtr)) != EOF) {
    buffer[index++] = character;
  }

  // Null-terminate the buffer
  buffer[index] = '\0';

  // Close the file when you're done
  fclose(filePtr);

  return buffer;
}

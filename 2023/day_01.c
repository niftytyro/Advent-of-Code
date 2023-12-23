#include "./utils.c"
#include <stdio.h>
#include <string.h>

// Problem: Take multi-line input and return the sum of calibration values
//     Take each line and return a calibration value for that line

int find_first_digit(char *str) {
  for (int i = 0; i < strlen(str); i++) {
    char character = str[i];
    if ((character - '0') >= 0 && (character - '0') < 10) {
      return character - '0';
    }
  }
  return 0;
}

int find_last_digit(char *str) {
  for (int i = strlen(str) - 1; i >= 0; i--) {
    char character = str[i];
    if ((character - '0') >= 0 && (character - '0') < 10) {
      return character - '0';
    }
  }

  return 0;
}

int get_calibration_value(char *line) {
  // find first and last digit in string
  int first_digit = find_first_digit(line);
  int last_digit = find_last_digit(line);
  return first_digit * 10 + last_digit;
}

int main() {

  char *file_path = "day_01.txt";

  /* char *input = "1abc2\npqr3stu8vwx\na1b2c3d4e5f\ntreb7uchet"; */
  char *input = read_file(file_path);

  char **lines = str_break(input, "\n");

  int sum_calibration_values = 0;

  int count = 0;

  char *line = lines[count];
  while (line != NULL) {
    sum_calibration_values += get_calibration_value(line);
    count++;
    line = lines[count];
  };

  printf("Sum: %d\n", sum_calibration_values);
}

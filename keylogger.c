#include <stdio.h>
// #include <conio.h>

int main() {
  // Open the file for writing
  FILE *file = fopen("key_log.txt", "w");

  // Check if file opened successfully
  if (!file) {
    printf("Error opening file!\n");
    return 1;
  }

  // Capture key presses until Esc key is pressed
  while (1) {
    // Get the pressed key
    int key;
    scanf("%d", &key);

    // Check if Esc key is pressed
    if (key == 27) {
      break;
    }

    // Check if printable character
    if (isprint(key)) {
      // Write the character to the file
      fputc(key, file);
    } else {
      // Handle non-printable characters (e.g., arrow keys)
      // You can add your own logic here
    }
  }

  // Close the file
  fclose(file);

  printf("Key logging stopped!\n");
  return 0;
}

#include <stdio.h>

int main() 
{
    printf("| %-10s | %-15s | %-8s |\n", "Name", "Occupation", "Age");
    printf("|------------|-----------------|--------|\n");
    printf("| %-10s | %-15s | %-8d |\n", "John", "Engineer", 28);
    printf("| %-10s | %-15s | %-8d |\n", "Alice", "Teacher", 32);
    printf("| %-10s | %-15s | %-8d |\n", "Bob", "Doctor", 45);

    return 0;
}


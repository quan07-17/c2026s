int isPalindrome(char *str)
{
    int left = 0;
    int right = 0;

    // Find the length of the string
    while (str[right] != '\0') {
        right++;
    }
    right--; // Move back to the last character

    // Check for palindrome
    while (left < right) {
        if (str[left] != str[right]) {
            return 0; // Not a palindrome
        }
        left++;
        right--;
    }
    return 1; // Is a palindrome
}
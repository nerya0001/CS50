from cs50 import get_int
from math import floor

first_digit = 0
second_digit = 0
digits = 0
sum1 = 0
sum2 = 0
number = get_int("Number: ")

while number > 0:
    second_digit = first_digit
    first_digit = number % 10

    if digits % 2 == 0:
        sum2 += first_digit
    else:
        multiple = 2 * first_digit
        sum1 += (multiple // 10) + (multiple % 10)

    number //= 10
    digits += 1

validity = (sum2 + sum1) % 10 == 0
first_two = (first_digit * 10) + second_digit

if first_digit == 4 and digits >= 13 and digits <= 16 and validity:
    print("VISA")
elif first_two >= 51 and first_two <= 55 and digits == 16 and validity:
    print("MASTERCARD")
elif (first_two == 34 or first_two == 37) and digits == 15 and validity:
    print("AMEX")
else:
    print("INVALID")
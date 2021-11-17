from cs50 import get_float

while True:
    amount = get_float("Change owed: ")
    if amount > 0.00:
        break

change = round(amount * 100)
count = 0

while change >= 25:
    count += 1
    change -= 25

while change >= 10:
    count += 1
    change -= 10

while change >= 5:
    count += 1
    change -= 5

while change >= 1:
    count += 1
    change -= 1

print (count)
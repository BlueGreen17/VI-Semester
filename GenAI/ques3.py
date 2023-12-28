def even_digits(number):
    
    number_string = str(number)
    even_count = 0
    
    for digit in number_string:
        # Check if the digit is even
        if int(digit) % 2 == 0:
            even_count += 1
    
    return even_count

user_number = int(input("Enter a five-digit number: "))


if 10000 <= user_number <= 99999:
    result = even_digits(user_number)
    print(f"The number of even digits in {user_number} is: {result}")
else:
    print("Please enter a valid five-digit number.")



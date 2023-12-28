def count_notes(withdrawal_amount):
  
    notes_count = {
        500: 0,
        100: 0,
        20: 0,
        1: 0
    }

    
    for note_value in sorted(notes_count.keys(), reverse=True):
        if withdrawal_amount >= note_value:
            notes_count[note_value] = withdrawal_amount // note_value
            withdrawal_amount %= note_value

    return notes_count


withdrawal_amount = int(input("Enter the withdrawal amount in rupees: "))


if withdrawal_amount > 0:
    result = count_notes(withdrawal_amount)

    print(f"Minimum number of notes needed:")
    for note_value, count in result.items():
        print(f"{note_value} rupees notes: {count} notes")
else:
    print("Please enter a valid withdrawal amount.")

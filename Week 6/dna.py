from csv import reader, DictReader
from sys import argv


def main():

    # TODO: Check for command-line usage
    if len(argv) != 3:
        print("Please use the format name.csv name.txt")
        exit(1)
    # TODO: Read database file into a variable
    STRs = []
    profiles = []
    with open(argv[1], "r") as cfile:
        reader = DictReader(cfile)
        STRs = reader.fieldnames[1:]
        for row in reader:
            profiles.append(row)
    seq_str_count = dict.fromkeys(STRs, 0)
    with open(argv[2], "r") as file:
        sequence = file.readline()
    # TODO: Find longest match of each STR in DNA sequence
        for STR in STRs:
            seq_str_count[STR] = longest_match(sequence, STR)
    for profile in profiles:
        match_count = 0
        for STR in STRs:
            if int(profile[STR]) != seq_str_count[STR]:
                continue
            match_count += 1
        if match_count == len(STRs):
            print(profile['name'])
            exit(0)
    print("No match")
    exit(1)


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()

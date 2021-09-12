from mastermind import*
#import pygame
if __name__ == '__main__':
    size = 4
    count = 0
    valid_chars = 'grbyop'
    listofguesses = []
    listofclues = []
    code = create_code(valid_chars, size)
    wordcode = ''
    for i in code:
        wordcode = wordcode + i
    guess = ''
    while guess != wordcode and count < 10:
        guess = input("Please enter your guess of length 4, using the" +
                      " letters 'grbyop' : ")
        count = count + 1
        guess_list = []
        for i in guess:
            guess_list.append(i)
        check = valid(guess_list, valid_chars, size)
        while check == False:
            guess = input("Please enter your guess again of length 4," +
                          " using the letters 'grbyop' : ")
            guess_list = []
            for i in guess:
                guess_list.append(i)
            check = valid(guess_list, valid_chars, size)
        b_clue = find_fully_correct(code, guess_list)
        w_clue = find_colour_correct(code, guess_list)
        clue_list = b_clue
        clue_list.extend(w_clue)
        listofguesses.append(guess_list)
        listofclues.append(clue_list)
        print_game(listofguesses, listofclues)
    if guess == wordcode:
        if count == 1:
            print('\nCongratulations! it took you only', count, 'guess to ' +
                  ' find the code. You have Psychic powers')
        else:
            print('\nCongratulations! it took you', count, 'guesses to find' +
                  ' the code')
    else:
        print("\nSorry! You Lose! The correct code was", wordcode)
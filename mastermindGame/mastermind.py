import random


def create_code(c_letters, length):
    '''
    (str, int)---> list
        Given a str and a size (an int) return a list of length size of single
        character strs comprised of the characters in the given str.
    '''
    newlist = []
    for i in range(0, length):
        letter = random.choice(c_letters)
        newlist.append(letter)
    return newlist


def valid(code_list, valid_chars, length):
    '''
    (list, str, int) ---> bool
        Given a list of single character strs, a str and a int that
        is the length of the guess, return True if every character,
        is in the given str and the guess is the correct length.
    '''
    wordcode = ''
    for i in code_list:
        wordcode = wordcode + i
    if len(wordcode) > length:
        return False
    else:
        for i in code_list:
            if valid_chars.find(i) == -1:
                return False
        return True


def remove_fully_correct(code_list, guess_list):
    '''
    (list, list) ---> list
        Given two lists of single character strs return a new list that is the
        result of removing from the first list all chars that are the same and
        in the same position in the second list. Both lists have
        the same length.
    '''
    newlist = []
    index = 0
    while index < len(code_list) and index < len(guess_list):
        if code_list[index] == guess_list[index]:
            newlist.append(code_list[index])
        index = index + 1
    return newlist


def find_fully_correct(code_list, guess_list):
    '''
    (list, list) ---> list
        Given the answer code (a list) and the guess (a list) return a list
        containing a 'b' for each correctly positioned colour in the guess.
    '''
    newlist = []
    c_list = remove_fully_correct(code_list, guess_list)
    c_word = ''
    for i in code_list:
        c_word = c_word + i
    newlist = []
    for item in c_list:
        count = c_word.count(item)
        if count >= 1:
            newlist.append('b')
    return newlist


def find_colour_correct(clist, glist1):
    '''
    (list, list) ---> list
        Given two lists of single character strs return a list of 'w's
        where the number of 'w's is equal to the number of str in the
        second list that have the same value as str in the first list
        but different position. Only one 'w' is returned for each str in
        the first list.
    '''
    glist = []
    for s in glist1:
        glist.append(s)
    index = 0
    while index < len(clist) and index < len(glist):
        if clist[index] == glist[index]:
            clist = clist[:index] + clist[index+1:]
            glist = glist[:index] + glist[index+1:]
            index = -1
        index = index + 1
    g_word = ''
    for item in glist:
        g_word = g_word + item
    newlist = []
    for i in clist:
        count = g_word.count(i)
        if count >= 1:
            newlist.append('w')
            glist.remove(i)
            g_word = ''
            for let in glist:
                g_word = g_word + let
    return newlist

def print_game(glist1, clist2):
    '''
    (list, list) ---> None
        Given two lists of lists of single character strs print to the display
        the headers Guess and Clue separated by a tab. Next, print
        corresponding sublists of the given lists. Each character in the
        sublists should be printed, separated by spaces. Each pair of sublists
        should be separated by a tab and on a separate line
    '''
    print ('Guesses \tClues')
    index = 0
    while index <= len(clist2) and index < len(glist1):
        gstring = ''
        for i in glist1[index]:
            gstring = gstring + i + ' '
        cstring = ''
        for item in clist2[index]:
            cstring = cstring + item + ' '
        print (gstring,'\t', cstring)
        index = index + 1
import random
def game(player_name, ccount, pcount):
    print("Pick a hand: (0: Rock, 1: Paper, 2: Scissors)")
    player_hand = int(input("Please enter a number (0-2): "))
    if validate(player_hand):
        computer_hand = random.randint(0, 2)
        if len(player_name) > 0:
            print_hand(player_hand, player_name)
        else:
            player_name="Guest"
            print_hand(player_hand, player_name)
        print_hand(computer_hand, "Computer")
        result = judge(player_hand, computer_hand)
        if result=="Win":
            pcount+=1
        elif result=="Lose":
            ccount+=1
        print("Result: " + result)
        resp(player_name, ccount, pcount)
    else:
        print("Please enter a valid number")

def resp(player_name, ccount, pcount):
    response = input("Want to play again? (Y/N): ")
    if response == "Y":
        game(player_name, ccount, pcount)
    elif response == "N":
        if ccount > pcount:
            print("Computer wins by " + str(ccount) + " - " + str(pcount))
        elif pcount > ccount:
            print(player_name + " wins by " + str(pcount) + " - " + str(ccount))
        else:
            print("Match draw by " + str(ccount) + " - " + str(pcount))
        print("Thanks for playing")
    else:
        print("Please enter a valid response")
        resp(player_name, ccount, pcount)

def validate(hand):
    if hand<0 or hand>2:
        return False
    return True

def print_hand(hand, name):
    hands=['Rock', 'Paper', 'Scissors']
    print(name+' picked: '+hands[hand])

def judge(player, computer):
    if player == computer:
        return 'Draw'
    elif player==0 and computer==1:
        return 'Lose'
    elif player==1 and computer==2:
        return 'Lose'
    elif player==2 and computer==0:
        return 'Lose'
    else:
        return 'Win'
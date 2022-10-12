#ROCK-PAPER-SCISSORS..GAME TIME!!

import random

def play():
    user=input("Enter (r) for rock, (p) for paper and (s) for scissor ")
    computer=random.choice(['r','p','s'])

    if user==computer:
        return("Thats a TIE !")

    if win(user,computer):
        return 'Heyy...YOU WON..!..CONGRATS!'

    return 'Sorry...you lost!'  #If both the above conditions fail..its evident that user must have lost;hence directly give return stat.
    
def win(user,computer):
    # s>p , p>r , r>s ==> Inequations for winning
    if  (user=='s' and computer=='p') or (user=='r' and computer=='s') or (user=='p' and computer=='r'):
        return True
l=[]   
for i in range(3):   
    answer=play()
    print(answer)
    l.append(answer[0])

if max(set(l), key=l.count)=='T':
        print()
        print("The best of three resulted in a TIE!")
        print()
elif max(set(l), key=l.count)=='H':
        print()
        print("YOU WON THE BEST OF THREE..!!")
        print()

elif max(set(l), key=l.count)=='S':
        print()
        print("YOU LOST THE BEST OF THREE..")
        print()

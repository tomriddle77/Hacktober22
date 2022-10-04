import random as r 
choices =  ['Rock', 'Paper', 'Scissors']
computer = r.choice(choices)

player = False
computer_score = 0
player_score = 0
while True:
  player = input('Rock, Paper or Scissors?').capitalize() # this function converts first letter of string to uppercase and rest to lower case
  if player == computer:
    print('Tie')
  elif player == 'Rock':
    if computer == 'Paper':
      print('You lose!',computer, 'covers',player) 
      computer_score += 1
    else:
      print('You win!',player,'smashes',computer)
      player_score += 1   

  elif player == 'Paper':
    if computer == 'Scissors':
      print('You lose!',computer,'cuts',player)
      computer_score += 1
    else:
      print('You Win!',player,'covers',computer)
      player_score += 1
    
  elif player == 'Scissors':
    if computer == 'Rock':
      print('You Lose',computer,'smashes',player)
      computer_score += 1
    else:
      print('You Win',player,'cut',computer)
      player_score += 1 

  elif player == 'End':
    print("Final Score: ")
    print(f"Computer Score:{computer_score}")   
    print(f"Player Score:{player_score}")     
    break

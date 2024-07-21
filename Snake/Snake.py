# Side Porject: Snake
# Thomas Liu

# import modules
import pygame
import random
import time
from pygame import mixer

# initialize the pygame
pygame.init()

# initialize music in pygame
pygame.mixer.init()

# FPS of the game
FPS = 30
FramePerSec = pygame.time.Clock()

# colors
black = pygame.Color(0, 0, 0)
white = pygame.Color(255, 255, 255)
blue = pygame.Color(0, 0, 255)
red = pygame.Color(255, 0, 0)
green = pygame.Color(0, 255, 0)

# setup the screen size of the game
scr_width = 800
scr_height = 600
screen = pygame.display.set_mode((scr_width, scr_height))
pygame.display.set_caption("Thomas Liu's Snake Game") 

# snake size
snake_size = 10

# initial score
score = 0

# draw the snake
def draw_snake(snake_position):
    for x in snake_position:
        # draw the snake
        pygame.draw.rect(screen, blue, [x[0], x[1], snake_size, snake_size])

# show user the final score
def final_score(msg, score):
    # font used to display the final score
    font_final_score = pygame.font.SysFont('Verdana', 60)
    message = font_final_score.render(msg + str(score), True, black)
    message_rect = message.get_rect(center = (scr_width/2, scr_height/2))
    screen.fill(white)
    screen.blit(message, message_rect)   

# main function, where the game is ran
def game():
    # coordinate of the snake
    # initial coordinate
    snake_x = 390
    snake_y = 290
    # change in coordinate
    x_change = 0
    y_change = 0

    # store the coordinates of the entire snake
    snake_pos = []
    # snake length
    snake_len = 1

    # apple
    apple = pygame.image.load("D:\\University of Waterloo\\Side Project\\Snake\\apple.png").convert()
    apple = pygame.transform.scale(apple, (snake_size, snake_size))
    
    # coordinate of the apple
    apple_x = round(random.randrange(70, scr_width - snake_size - 70) / 10.0) * 10.0
    apple_y = round(random.randrange(70, scr_height - snake_size - 70) / 10.0) * 10.0

    # main loop to run the function
    end_game = False
    while not end_game:
        for event in pygame.event.get():
            # end game when QUIT
            if event.type == pygame.QUIT:
                end_game = True

            # when key is pressed
            if event.type == pygame.KEYDOWN:
                # move snake up when up key is pressed
                if event.key == pygame.K_UP:
                    x_change = 0
                    y_change = -snake_size
                # move snake down when down key is pressed
                elif event.key == pygame.K_DOWN:
                    x_change = 0
                    y_change = snake_size
                # move snake right when right key is pressed
                elif event.key == pygame.K_RIGHT:
                    x_change = snake_size
                    y_change = 0
                # move snake left when left key is pressed
                elif event.key == pygame.K_LEFT:
                    x_change = -snake_size
                    y_change = 0
            
        # when the snake hit the board
        if snake_x >= (scr_width - snake_size) or snake_x < 0 or snake_y >= (scr_height - snake_size) or snake_y < 0:
            col_sound = pygame.mixer.Sound("D:\\University of Waterloo\\Side Project\\Snake\\collision.mp3")
            pygame.mixer.Sound.play(col_sound)
            end_game = True
        
        # update the coordinate of the snake
        snake_x += x_change
        snake_y += y_change

        # fill the background with green
        screen.fill(green)

        # draw the apple
        screen.blit(apple, (apple_x, apple_y))

        # store the current 
        snake_head = []
        snake_head.append(snake_x)
        snake_head.append(snake_y)
        snake_pos.append(snake_head)

        # remove the coordinate of snake head
        if len(snake_pos) > snake_len:
            del snake_pos[0]

        # if snake collides into the body
        for x in snake_pos[:-1]:
            if x == snake_head:
                col_sound = pygame.mixer.Sound("D:\\University of Waterloo\\Side Project\\Snake\\collision.mp3")
                pygame.mixer.Sound.play(col_sound)
                end_game = True
        
        # draw snake
        draw_snake(snake_pos)

        pygame.display.update()

        # detect whether snake eats the apple
        if snake_x == apple_x and snake_y == apple_y:
            # generate new apple coordinate
            apple_x = round(random.randrange(70, scr_width - snake_size - 70) / 20.0) * 20.0
            apple_y = round(random.randrange(70, scr_height - snake_size - 70) / 20.0) * 20.0
            # make sound
            eat_sound = pygame.mixer.Sound("D:\\University of Waterloo\\Side Project\\Snake\\ding_sound.mp3")
            pygame.mixer.Sound.play(eat_sound)
            # snake length plus 1
            snake_len += 1
            # score plus 1
            global score
            score += 1

        
        FramePerSec.tick(10)

# run the game function
game()

# show user the final score
final_score("Your final score is ", score)
pygame.display.update()
time.sleep(2)

# end the entire game
pygame.quit()
quit()
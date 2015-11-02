import pygame
import math
import random
from pygame.locals import *
key = [False,False,False,False]
ppos = [100,100]
acc=[0,0]
arrows = []
badtimer = 100
badtimer1 = 0
bc=[[930,100]]
power = 194

pygame.init()
pygame.mixer.init()
width,height = 920,550
screen = pygame.display.set_mode((width,height))

player = pygame.image.load('resources\images\dude.png')
bg = pygame.image.load('resources\images\grass.jpg')
cas = pygame.image.load('resources\images\castle.png')
arrow = pygame.image.load("resources\images\dude1.png")
bcimg1 = pygame.image.load("resources\images\dc.png")
healthbar = pygame.image.load("resources/images/healthbar.png")
health = pygame.image.load("resources/images/health.png")
gameover = pygame.image.load("resources/images/gameover.png")
youwin = pygame.image.load("resources/images/youwin.png")
bcimg = bcimg1
hit = pygame.mixer.Sound('resources/audio/explode.wav')
enemy = pygame.mixer.Sound('resources\audio\enemy.wav')
shoot = pygame.mixer.Sound('resources\audio\shoot.wav')
hit.set_volume(0.5)
enemy.set_volume(0.5)
shoot.set_volume(0.5)
pygame.mixer.music.load('resources/audio/moonlight.wav')
pygame.mixer.music.play(-1,0.0)
pygame.mixer.music.set_volume(0.25)


X = width/bg.get_width() + 1
Y = height/bg.get_height() + 1

running = 1
exitcode =0
while 1:
 badtimer -= 1
 screen.fill(0)
 for x in range(X):
  for y in range(Y):
   screen.blit(bg,(x*100,y*100))
 screen.blit(cas,(0,50))
 screen.blit(cas,(0,170))
 screen.blit(cas,(0,290))
 screen.blit(cas,(0,410))
 
 position = pygame.mouse.get_pos()
 angle = math.atan2(position[1]-(ppos[1]+32),position[0]-(ppos[0]+26))
 playerrot = pygame.transform.rotate(player, 360-angle*57.29)
 playerpos1 = (ppos[0]-playerrot.get_rect().width/2, ppos[1]-playerrot.get_rect().height/2)
 screen.blit(playerrot, playerpos1)
 
 #arrow
 for bullet in arrows:
        index=0
        velx=math.cos(bullet[0])*30
        vely=math.sin(bullet[0])*30
        bullet[1]+=velx
        bullet[2]+=vely
        if bullet[1]<-64 or bullet[1]>970 or bullet[2]<-64 or bullet[2]>640:
            arrows.pop(index)
        index+=1
        for projectile in arrows:
            arrow1 = pygame.transform.rotate(arrow, 360-projectile[0]*57.29)
            screen.blit(arrow1, (projectile[1], projectile[2]))
 
 
 if badtimer == 0:
  bc.append([930,random.randint(50,500)])
  badtimer = 100 - (badtimer1*2)
  if badtimer1 >35:
   badtimer = 35
  else:
   badtimer1 += 5
 index = 0
 for b in bc :
   if b[0] < -64 :
    bc.pop(index)
   b[0] -= 7
   brect = pygame.Rect(bcimg.get_rect())
   brect.top = b[1]
   brect.left = b[0]
   if brect.left < 64 :
        power -= 10
	bc.pop(index)
	hit.play()
   index1 = 0
   for bullet in arrows :
   	bullrect = pygame.Rect(arrow.get_rect())
	bullrect.left=bullet[1]
	bullrect.top = bullet[2]
	if brect.colliderect(bullrect) :
	 acc[0] += 1
	 bc.pop(index)
	 enemy.play()
	 arrows.pop(index1)
	index1 += 1
	 
   index += 1
 for b in bc :
   screen.blit(bcimg1,b)
   
 font = pygame.font.Font(None, 24)
 survivedtext = font.render(str((90000-pygame.time.get_ticks())/60000)+":"+str((90000-pygame.time.get_ticks())/1000%60).zfill(2), True, (0,0,0))
 textRect = survivedtext.get_rect()
 textRect.topright=[635,5]
 screen.blit(survivedtext, textRect)
 screen.blit(healthbar, (5,5))
 for health1 in range(power):
    screen.blit(health, (health1+8,8))
	
 if pygame.time.get_ticks() >= 90000:
        running=0
	exitcode=1
	#screen.blit(gameover, (0,0))
 if power <= 0:
  running=0
  exitcode=0
  #screen.blit(youwin, (200,100))
 if acc[1]!=0:
        accuracy=acc[0]*1.0/acc[1]*100
 else:
        accuracy=0
 if running == 0:
  if exitcode==0:
    pygame.font.init()
    font = pygame.font.Font(None, 24)
    text = font.render("Accuracy: "+str(accuracy)+"%", True, (255,0,0))
    textRect = text.get_rect()
    textRect.centerx = screen.get_rect().centerx
    textRect.centery = screen.get_rect().centery+24
    screen.blit(gameover, (140,30))
    screen.blit(text, textRect)
  elif exitcode == 1:
    pygame.font.init()
    font = pygame.font.Font(None, 24)
    text = font.render("Accuracy: "+str(accuracy)+"%", True, (0,255,0))
    textRect = text.get_rect()
    textRect.centerx = screen.get_rect().centerx
    textRect.centery = screen.get_rect().centery+24
    screen.blit(youwin, (140,30))
    screen.blit(text, textRect)
  while 1:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            exit(0)
    pygame.display.flip()
  
   
 pygame.display.flip()
 
 
 for event in pygame.event.get():
  if event.type == pygame.QUIT:
   pygame.quit()
   exit(0)
  
    
 
  if event.type == pygame.KEYDOWN:
   if event.key == K_w or event.key == K_8 :
    key[0] = True
   elif event.key == K_a or event.key == K_4:
    key[1] = True
   elif event.key == K_s or event.key == K_2:
    key[2] = True
   elif event.key == K_d or event.key == K_6:
    key[3] = True
	
  if event.type == pygame.KEYUP:
   if event.key == K_w or event.key == K_8 :
    key[0] = False
   elif event.key == K_a or event.key == K_4:
    key[1] = False
   elif event.key == K_s or event.key == K_2:
    key[2] = False
   elif event.key == K_d or event.key == K_6:
    key[3] = False
  if event.type==pygame.MOUSEBUTTONDOWN:
    position=pygame.mouse.get_pos()
    acc[1]+=1
    shoot.play()
    arrows.append([math.atan2(position[1]-(playerpos1[1]+32),position[0]-(playerpos1[0]+26)),playerpos1[0]+32,playerpos1[1]+32])
 if key[0] :
  ppos[1] -= 5
 elif key[2] :
  ppos[1] += 5
 if key[1]:
  ppos[0]-= 5
 elif key[3]:
  ppos[0] += 5
 
 

  
  
	
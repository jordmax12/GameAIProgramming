import pygame, random, sys
from pygame.locals import *
def collide(x1, x2, y1, y2, w1, w2, h1, h2):
    if x1+w1>x2 and x1<x2+w2 and y1+h1>y2 and y1<y2+h2:return True
    else:return False
def die(screen, score):
    f=pygame.font.SysFont('Arial', 30);
    t=f.render('Your score was: '+str(score), True, (0, 0, 0));
    screen.blit(t, (10, 270));
    pygame.time.wait(2000);
    sys.exit(0)
xs = [290 , 280];
ys = [10, 10];
dirs = 0;
score = 0;
applepos = (290, 250);
floorpos = (0, 590);
pygame.init();
s=pygame.display.set_mode((600, 600));
pygame.display.set_caption('Tetris Attempt');
appleimage = pygame.Surface((10, 10));
appleimage.fill((0, 255, 0));
img = pygame.Surface((10, 70));
img.fill((255, 0, 0));
shape2 = pygame.Surface((600, 10));
shape2.fill((255, 5, 255));

f = pygame.font.SysFont('Arial', 20);
clock = pygame.time.Clock()

while True:
    clock.tick(10)
    for e in pygame.event.get():
        if e.type == QUIT:
            sys.exit(0)
        elif e.type == KEYDOWN:
            if e.key == K_SPACE:img = pygame.Surface((70, 10));
            elif e.key == K_DOWN and dirs != 2:dirs = 0
    i = len(xs)-1
    while i >= 2:
        if collide(xs[0], xs[i], ys[0], ys[i], 20, 20, 20, 20):die(s, score)
        i-= 1
    if collide(xs[0], floorpos[0], ys[0], floorpos[1], 50, 300, 50, 200):
                    score = 500;
                    xs.append(700);
                    ys.append(700);
                    newShape = pygame.Surface((30, 45));
                    newShape.fill((150, 54, 98))
                    s.blit(newShape, (xs[1], ys[1]))
                    pygame.display.update()
    
    if xs[0] < 0 or xs[0] > 580 or ys[0] < 0 or ys[0] > 580:
            die(s, score)
            i = len(xs)-1
    while i >= 1:
        xs[i] = xs[i-1];ys[i] = ys[i-1];i -= 10
    if dirs==0:
            ys[0] += 20
            
    ty = ys[0]
    angle = 90
    if ty >= 100:
                score+=10
    s.fill((255, 255, 255))
    s.blit(img, (xs[0], ys[0]))
##    s.blit(appleimage, applepos);
    s.blit(shape2, floorpos);
    t=f.render(str(score), True, (0, 0, 0));
    s.blit(t, (10, 10));
    pygame.display.update()
pygame.quit()
                    
                    
            



#ifndef GAME_H
# define GAME_H

# include <wiringPi.h>
# include <stdlib.h>
# include <time.h>

# define BUTTON1 0
# define LED1 1

# define BUTTON2 7
# define LED2 4

# define WIN 32

void init(void);
int update(void);
void draw(void);
void win(void);
void loose(void);
int go(void);

#endif /* !GAME_H */

#include <game.h>

static int tab[WIN]; 
static int count = 0;

int go(void)
{
    if (digitalRead(BUTTON1) == LOW &&
	digitalRead(BUTTON2) == LOW) {
	
	for (int i = 0; i < WIN; i++)
	    tab[i] = 0;
	count = 0;

        return 1;
    }
    return 0;
}

void win(void)
{
    for (int i = 0; i < 5; i++) {
	digitalWrite(LED2, HIGH);
	delay(500);
	digitalWrite(LED2, LOW);
	delay(500);
    }
}

void loose(void)
{
    for (int i = 0; i < 5; i++) {
	digitalWrite(LED1, HIGH);
	delay(500);
	digitalWrite(LED1, LOW);
	delay(500);
    }
}

void init(void)
{
    wiringPiSetup();

    pinMode(LED1, OUTPUT);
    pinMode(BUTTON1, INPUT);
    
    pinMode(LED2, OUTPUT);
    pinMode(BUTTON2, INPUT);

    srand(time(NULL));
}

int update(void)
{
    int c = 0;
    while (c < count) {
	int val = 0;
	while (!val) {
	    if (digitalRead(BUTTON1) == LOW) {
		delay(250);
		val = 1;
		break;
	    }
	    if (digitalRead(BUTTON2) == LOW) {
		delay(250);
		val = 2;
		break;
	    }
	}
	if ((val == 1) && tab[c] == LED2)
	    return 1;
	if ((val == 2) && tab[c] == LED1)
	    return 1;
	c++;
    }

    int r = rand() % 2;
    tab[count++] = r == 0 ? LED1 : LED2;

    if (count == WIN)
	return 2;

    return 0;
}

void draw(void)
{
    for (int i = 0; tab[i] && i < WIN; i++) {
	digitalWrite(tab[i], HIGH);
        delay(500);
	digitalWrite(tab[i], LOW);
        delay(500);
    }
}
